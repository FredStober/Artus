
#include "Artus/KappaAnalysis/interface/Producers/LuminosityWeightProducer.h"


std::string LuminosityWeightProducer::GetProducerId() const {
	return "LuminosityWeightProducer";
}

void LuminosityWeightProducer::Produce(KappaEvent const& event,
		KappaProduct& product,
		KappaSettings const& settings) const
{
	product.m_weights["luminosityWeight"] = (1.0 / static_cast<double>(settings.GetIntLuminosity()));
}

