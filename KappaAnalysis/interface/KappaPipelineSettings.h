
#pragma once

#include "Artus/Core/interface/GlobalInclude.h"
#include "Artus/Configuration/interface/SettingsBase.h"
#include "Artus/Configuration/interface/SettingMacros.h"
#include "Artus/Configuration/interface/PropertyTreeSupport.h"

class KappaPipelineSettings: public SettingsBase {
public:

};

class KappaGlobalSettings: public GlobalSettingsBase {

public:
	IMPL_SETTING_DEFAULT(bool, Verbose, false);
	
	IMPL_SETTING_DEFAULT(std::string, Electrons, "");
	IMPL_SETTING_DEFAULT(std::string, Muons, "");
	IMPL_SETTING_DEFAULT(std::string, Taus, "");
	
	IMPL_SETTING_DEFAULT(std::string, Jets, "");
	IMPL_SETTING_DEFAULT(std::string, JetArea, "");
	
	IMPL_SETTING_DEFAULT(std::string, Met, "");
	
	IMPL_SETTING_DEFAULT(std::string, BeamSpot, "");
	IMPL_SETTING_DEFAULT(std::string, VertexSummary, "");
	
	IMPL_SETTING_DEFAULT(std::string, GenParticles, "");
	
	IMPL_SETTING_DEFAULT(std::string, LumiMetadata, ""); // TODO: Default value, move to Artus/Provider
	IMPL_SETTING_DEFAULT(std::string, GenLumiMetadata, ""); // TODO: Default value, move to Artus/Provider
	IMPL_SETTING_DEFAULT(std::string, EventMetadata, ""); // TODO: Default value, move to Artus/Provider
	IMPL_SETTING_DEFAULT(std::string, GenEventMetadata, ""); // TODO: Default value, move to Artus/Provider
	IMPL_SETTING_DEFAULT(std::string, FilterMetadata, ""); // TODO: Default value, move to Artus/Provider
	IMPL_SETTING_DEFAULT(std::string, FilterSummary, ""); // TODO: Default value, move to Artus/Provider
	
	VarCache<std::vector<std::string>> jsonFiles;
	stringvector GetJsonFiles() const
	{
		RETURN_CACHED(jsonFiles, PropertyTreeSupport::GetAsStringList(GetPropTree(), "JsonFiles"))
	}
	IMPL_SETTING_DEFAULT(int, PassRunLow, 1);
	IMPL_SETTING_DEFAULT(int, PassRunHigh, 0);
	
	VarCache<std::vector<std::string>> hltPaths;
	stringvector GetHltPaths() const
	{
		RETURN_CACHED(jsonFiles, PropertyTreeSupport::GetAsStringList(GetPropTree(), "HltPaths"))
	}
};
