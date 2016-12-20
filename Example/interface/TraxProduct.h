/* Copyright (c) 2013 - All Rights Reserved
 *   Thomas Hauth  <Thomas.Hauth@cern.ch>
 *   Joram Berger  <Joram.Berger@cern.ch>
 *   Dominik Haitz <Dominik.Haitz@kit.edu>
 */
#pragma once

#include "Artus/KappaAnalysis/interface/KappaProduct.h"

struct TraxProduct: KappaProduct
{
	float m_floatPtSim_corrected;
};
