
#pragma once

#include <sstream>
#include <boost/test/included/unit_test.hpp>

#include "Artus/Configuration/interface/ArtusConfig.h"

#include "TestTypes.h"
#include "TestPipelineRunner.h"
#include "TestEventProvider.h"

BOOST_AUTO_TEST_CASE( test_parse_config )
{
	std::stringstream configStream;

	configStream
	<<	"{"
	<<	    "\"Processors\": ["
	<<	    "    \"filter:testglobalfilter\", \"producer:test_global_producer\""
	<<	    "],"
	<<	    "\"InputFiles\": ["
	<<	    "    \"sample_ntuple.root\""
	<<	    "],"
	<<	    "\"OutputPath\": \"sample_output.root\","
	<<	    "\"Pipelines\": {"
	<<	    "    \"lowPt\": {"
	<<	    "        \"Consumers\": [ \"test_consumer\""
	<<	    "        ],"
	<<	    "       \"Processors\": [\"producer:test_local_producer\", \"filter:testfilter\", \"filter:testfilter2\" "
	<<	    "        ]"
	<<	    "    },"
	<<	    "    \"highPt\": {"
	<<	    "        \"Consumers\": [ \"test_consumer\""
	<<	    "        ],"
	<<	    "       \"Processors\": [ \"producer:test_local_producer\", \"filter:testfilter2\""
	<<	    "        ]"
	<<	    "    }"
	<<	    "}"
	<<	"}";

	ArtusConfig cfg ( configStream );

	TestEventProvider evtProvider;

	// the pipeline initializer will setup the pipeline, with
	// all the attached Producer, Filer and Consumer
	TestPipelineInitializer pInit;
	TestFactory factory;
	TestPipelineRunner runner(false);

	// load the pipeline with their configuration from the config file
	cfg.LoadConfiguration( pInit, runner, factory, nullptr);

	auto & pList = runner.GetNodes();

	BOOST_CHECK_EQUAL( pList.size(), size_t(2) );
	BOOST_CHECK( pList.begin()->GetProcessNodeType() == ProcessNodeType::Filter );

	auto & pLine = runner.GetPipelines();

	BOOST_CHECK_EQUAL( pLine.size() , size_t(2) );

	auto pLineOne = pLine.begin();

	BOOST_CHECK_EQUAL( pLineOne->GetNodes().size() , size_t(3) );

	auto & nodesOne = pLineOne->GetNodes();

	BOOST_CHECK( nodesOne.begin()->GetProcessNodeType() == ProcessNodeType::Producer );
}

