// Matthew Gwynne, 5.10.2010 (Swansea)
/* Copyright 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Satisfiability/FiniteFunctions/QuineMcCluskeySubsumptionHypergraph.cpp
  \brief Application for computing all minimal resolvents from a given full clause-set

  One parameter is needed, the file containing the clause-set in DIMACS format.
  The result is printed to standard output (a hypergraph in DIMACS format).

  \todo Fully specify the hypergraph that is given.

  \todo Provide maxima specification.
  
*/

#include <fstream>
#include <iostream>
#include <string>

#include <OKlib/Satisfiability/Interfaces/InputOutput/Dimacs.hpp>
#include <OKlib/Satisfiability/Interfaces/InputOutput/ClauseSetAdaptors.hpp>
#include <OKlib/Satisfiability/FiniteFunctions/QuineMcCluskey.hpp>
#include <OKlib/Structures/Sets/SetAlgorithms/SubsumptionHypergraph.hpp>

namespace {

  enum {
    error_parameters = 1,
    error_openfile = 2,
    error_readfile = 3
  };

  const std::string version = "0.1.10";

}

// Move this elsewhere      
#ifdef NUMBER_VARIABLES
        const int num_vars = NUMBER_VARIABLES;
#else
        const int num_vars = 4;
#endif

int main(const int argc, const char* const argv[]) {
  typedef OKlib::InputOutput::RawDimacsCLSAdaptor<> CLSAdaptor;
  typedef OKlib::InputOutput::StandardDIMACSInput<CLSAdaptor> CLSInput;
  typedef OKlib::Satisfiability::FiniteFunctions::QuineMcCluskey<num_vars>::clause_set_type clause_set_type;
  typedef std::list<std::list<boost::range_difference<CLSAdaptor::clause_set_type>::type> > subsumption_hg_type;


  if (argc != 2) {
    std::cerr << "ERROR[QuineMcCluskey]: Exactly one input is required, the "
      "name of the file\n with the clause-set in DIMACS-format.\n"
      "However, the actual number of input parameters was " << argc-1 << ".\n";
    return error_parameters;
  }

  const std::string filename = argv[1];
  std::ifstream inputfile(filename.c_str());
  if (not inputfile) {
    std::cerr << "ERROR[QuineMcCluskey]: Failure opening file " << filename << ".\n";
    return error_openfile;
  }

  CLSAdaptor cls_F;
  const CLSInput input_F(inputfile, cls_F); inputfile.close();

  
  // Compute the prime clauses
  using namespace OKlib::Satisfiability::FiniteFunctions;
  const clause_set_type prime_imp_F = quine_mccluskey<num_vars>(cls_F.clause_set);
  
  // Compute the subsumption hypergraph
  const subsumption_hg_type subsumption_hg = 
    OKlib::SetAlgorithms::subsumption_hypergraph(
                                                 prime_imp_F,
                                                 cls_F.clause_set);

  
  const std::string comment("Subsumption hypergraph for the minimisation problem for " + filename);

  // Output
  OKlib::InputOutput::List2DIMACSOutput(subsumption_hg,std::cout,comment.c_str());

}
