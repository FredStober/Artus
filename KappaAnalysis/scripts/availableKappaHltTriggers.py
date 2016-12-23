#!/usr/bin/env python
# -*- coding: utf-8 -*-

import logging
import Artus.Utility.logger as logger
log = logging.getLogger(__name__)

import argparse
import os

import ROOT
ROOT.gROOT.SetBatch(True)
ROOT.PyConfig.IgnoreCommandLineOptions = True
ROOT.gErrorIgnoreLevel = ROOT.kError


def main():
	
	parser = argparse.ArgumentParser(description="Print out the available tau discriminators in a kappa skim.", parents=[logger.loggingParser])
	parser.add_argument("file", help="Kappa skim output file containing the Tau Meta data")
	args = parser.parse_args()
	logger.initLogger(args)
	
	lumis = ROOT.TChain("Lumis")
	lumis.Add(args.file)
	lumis.GetEntry(0)
	
	hltNames = lumis.lumiInfo.hltNames
	for hltName in hltNames:
		log.info(hltName)


if __name__ == "__main__":
	main()

