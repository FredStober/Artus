
#pragma once

#include "Artus/KappaAnalysis/interface/KappaProducerBase.h"


/**
Central producers for searching the resonance boson,
whose final state particles are to be analysed on reco. level.
*/

class GenBosonFromGenParticlesProducer: public ProducerBase<KappaTypes>
{
public:

	std::string GetProducerId() const override;

	void Init(KappaSettings const& settings) override;

	void Produce(KappaEvent const& event, KappaProduct& product,
	             KappaSettings const& settings) const override;
};


class GenBosonProductionProducer: public GenBosonFromGenParticlesProducer
{
public:

	std::string GetProducerId() const override;

	void Init(KappaSettings const& settings) override;

	void Produce(KappaEvent const& event, KappaProduct& product,
	             KappaSettings const& settings) const override;

private:

	std::vector<KGenParticle*> FindMothersWithDifferentPdgId(KGenParticles* genParticles, unsigned int currentIndex, int currentPdgId) const;
};


class GenBosonDiLeptonDecayModeProducer: public GenBosonFromGenParticlesProducer
{
public:

	std::string GetProducerId() const override;

	void Init(KappaSettings const& settings) override;

	void Produce(KappaEvent const& event, KappaProduct& product,
	             KappaSettings const& settings) const override;
};

