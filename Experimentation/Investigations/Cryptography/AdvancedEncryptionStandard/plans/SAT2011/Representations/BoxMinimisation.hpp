// Matthew Gwynne, 30.12.2010 (Swansea)
/* Copyright 2010, 2011 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/Cryptography/AdvancedEncryptionStandard/plans/SAT2011/Representations/BoxMinimisation.hpp
  \brief On investigating the generation of minimum size CNFs for the AES boxes


  \todo Overview
  <ul>
   <li> We investigate the generation of minimum size CNF representations
   for the AES boxes, including:
   <ul>
    <li> Sbox (see 
    ComputerAlgebra/Cryptology/Lisp/Cryptanalysis/Rijndael/SboxAnalysis.mac).
    </li>
    <li> Field Multiplications (see
    ComputerAlgebra/Cryptology/Lisp/Cryptanalysis/Rijndael/FieldOperationsAnalysis.mac). 
    </li>
    <li> Small scale variations of the Sbox and field multiplications. </li>
    <li> Affine multiplications (see 
    "Affine bijections over ZZ_2" in 
    Experimentation/Investigations/BooleanFunctions/plans/Permutations.hpp). 
    </li>
   </ul>
   </li>
   <li> In some cases, it may seem infeasible to generate the *minimum* size
   representation and so we generate only "small" representations (i.e.
   as small as we can get). </li>
   <li> When generating minimum or small representations, we have the 
   following tools, discussed in todos of the same name:
   <ul>
    <li> Espresso. </li>
    <li> Iterative SAT solving. </li>
    <li> Minimising using Hypergraph Transversal tools. </li>
    <li> Translating to a weighted MaxSAT problem. </li>
    <li> Minimisation at the maxima level. </li>
    <li> Minimisation using the R QCA package. </li>
   </ul>
  </ul>


  \todo Move individual investigations to sub-modules
  <ul>
   <li> Sub-modules need to be created for each of the investigations topics
   associated with this file. </li>
   <li> A good set of sub-modules seems to be based on the methods involved,
   and so we should have the following sub-modules:
   <ul>
    <li> Espresso </li>
    <li> IterativeSAT (Iterative SAT solving). </li>
    <li> HypergraphTransversal (Minimising using Hypergraph Transversal tools)
    </li>
    <li> WeightedMaxSAT (Translating to a weighted MaxSAT problem). </li>
    <li> MaximaMinimumCNF (Minimisation at the maxima level). </li>
    <li> RQCA (Minimisation using the R QCA package). </li>
   </ul>
   </li>
   <li> Each of these modules would then have a file per box using names
   related to the small scale notation, so such as:
   <ul>
    <li> ss_sbox_4.hpp (4-bit Sbox). </li>
    <li> ss_sbox_8.hpp (8-bit Sbox). </li>
    <li> ss_mul_4_2.hpp (4-bit multiplication by 2). </li>
    <li> ss_mul_8_3.hpp (4-bit multiplication by 3). </li>
    <li> etc. </li>
   </ul>
   </li>
  </ul>


  \todo Espresso
  <ul>
   <li> Espresso is a popular logic minimisation tool with a variety
   of methods for generating small and minimum sized logical representations.
   </li>
   <li> To use Espresso we must give a "pla" file as input. Therefore we must
   translate a full CNF (as generated by functions in 
   ComputerAlgebra/Cryptology/Lisp/Cryptanalysis/Rijndael/SboxAnalysis.mac etc)
   into a PLA file:
   \verbatim
fcl2tt(FF) := 
 append(
   map(lambda([C],
     endcons(0,
       map(lambda([L], if elementp(L, C) then 0 else 1), FF[1]))), FF[2]),
   listify(map(lambda([C],
     endcons(1,
       map(lambda([L], if elementp(L, C) then 0 else 1), FF[1]))), 
       setdifference(all_tass(FF[1]),setify(FF[2])))))$
output_tt2pla(TT, n) := 
  with_stdout(n, 
    if length(TT) = 0 then block(print(".i 0"), print(".0 1")) 
    else block(
      print(".i ", length(TT[1])-1),
      print(".o 1"),
      for tt_line in TT do
        print(apply(sconcat,rest(tt_line,-1))," ",1-last(tt_line))))$
   \endverbatim
   Note here that the truth table produced is then negated for representation
   in the PLA file, as we want espresso to minimise the CNF and by default
   it will find a minimum/minimal representation of the DNF.
   </li>
   <li> So for example, to generate the small scale 4-bit sbox as a PLA file,
   we then do:
   \verbatim
maxima> SboxCNF: fcs2fcl(ss_sbox_fullcnf_fcs(2,4,ss_polynomial_2_4))$
maxima> output_tt2pla(fcl2tt( SboxCNF ),"Sbox.pla")$
   \endverbatim
   </li>
   <li> To then minimise the boxes, we can then use either the "exact" or 
   "signature" methods of the espresso utility:
   \verbatim
shell> espresso2.3 -Dexact Sbox.pla
.i 8
.o 1
.p 22
1---01-- 1
-0--00-- 1
0---1-0- 1
--11---1 1
-1--1--1 1
--1--0-1 1
1-----10 1
--0---00 1
-111-1-- 1
-10-01-- 1
10-1-0-- 1
--001-1- 1
-0-1-11- 1
--101-0- 1
---0110- 1
0-0-0--1 1
-1-0--01 1
0-10---0 1
-1-10--0 1
-0-1--10 1
-101-01- 1
00---111 1
.e
   \endverbatim
   Note that "espresso2.3 -Dsignature Sbox.pla" should yield the same
   result, but may have different complexity depending on the input.
   </li>
   <li> We need a conversion function from the PLA format back to a CNF
   file. </li>
   <li> The above code on PLA generation should be moved into the appropriate
   Maxima file. </li>
  </ul>


  \todo Iterative SAT solving
  <ul>
   <li> Optimising the size of CNF representations for a given clause-set
   using standard SAT solvers can be approached by generating the 
   subsumption hypergraph for the original (full) CNF and it's prime 
   implicates and then adding additional cardinality clauses to the 
   subsumption hypergraph restricting the number of variables set to true
   and hence the number of clauses in our representation. </li>
   <li> By continuing to reduce the cardinality of the result until
   the subsumption hypergraph clause-set is unsatisfiable (i.e., there
   is no CNF representation with a number of clauses less than the 
   cardinality), we can iteratively search for the solution. </li>
   <li> So, for example, we generate the subsumption hypergraph
   for the 4-bit small scale Sbox like so:
   \verbatim
maxima> output_ss_sbox_fullcnf_stdname(2);
   \endverbatim
   and then 
   \verbatim
shell> ${OKPLATFORM}/OKsystem/OKlib/Experimentation/Investigations/Cryptography/AdvancedEncryptionStandard/minimise_cnf_oksolver ss_byte2_4_field_mul_full_2.cnf
c Starting level  14
c Starting level  13
c Starting level  12
c Starting level  11
c Starting level  10
c Starting level  9
c Starting level  8
c Found (a) minimum size representation for " ss_byte2_4_field_mul_full_2.cnf " of size 9
c Subsumption hypergraph for the minimisation problem for ss_byte2_4_field_mul_full_2.cnf
p cnf 8 9
-5 2 0
-2 5 0
-6 3 0
-3 6 0
-7 1 4 0
-4 1 7 0
-8 -7 -4 0
-8 4 7 0
-1 8 0
   \endverbatim
   </li>
   <li> Note the above uses the OKsolver to check for satisfiability of each
   clause-set. Further scripts should be written to check using other solvers.
   See "Solvers to be used for experimentation" in 
   Investigations/Cryptography/AdvancedEncryptionStandard/plans/SAT2011/Experimentation.hpp . </li>
  </ul>


  \todo Minimising using Hypergraph Transversal tools
  <ul>
   <li> Given a full CNF as generated by one of the box CNF generation 
   functions (see 
   ComputerAlgebra/Cryptology/Lisp/Cryptanalysis/Rijndael/FieldOperationsAnalysis.mac
   etc), for example:
   \verbatim
maxima> output_rijnmult_fullcnf_stdname(2);
   \endverbatim
   we can generate the subsumption hypergraph for this clause-set and it's
   prime implicates, and then use tools within the OKlibrary to compute
   all minimum transversals of the generated hypergraph, and hence all
   minimum CNF representations.
   </li>
   <li> This can be done like so:
   \verbatim
shell> QuineMcCluskeySubsumptionHypergraph-n16-O3-DNDEBUG ss_byte2_4_field_mul_full_2.cnf ss_byte2_4_field_mul_pi_2.cnf > ss_byte2_4_field_mul_shg_2.cnf
shell> BoundedTransversals_bv < ss_byte2_4_field_mul_shg_2.cnf > ss_byte2_4_field_mul_transversals_2.cnf
   \endverbatim
   </li>
   <li> We can generate all minimum CNF representations using a provided 
   script:
   \verbatim
shell> ${OKPLATFORM}/OKsystem/OKlib/Experimentation/Investigations/Cryptography/AdvancedEncryptionStandard/all_minimum_cnf ss_byte2_4_field_mul_full_2.cnf
shell> echo ss_byte2_4_field_mul_full_2.cnf.trans_* | wc -w
2
   \endverbatim
   </li>
  </ul>

  
  \todo Translating to a weighted MaxSAT problem
  <ul>
   <li> Given a full CNF as generated by one of the box CNF generation 
   functions (see 
   ComputerAlgebra/Cryptology/Lisp/Cryptanalysis/Rijndael/FieldOperationsAnalysis.mac
   etc), for example:
   \verbatim
maxima> output_rijnmult_fullcnf_stdname(2);
   \endverbatim
   we can generate the subsumption hypergraph for this clause-set and it's
   prime implicates, and then convert this to a weighted MaxSAT problem, which
   encodes that we wish to find an assignment setting the minimum number of 
   variables to true:
   \verbatim
shell> QuineMcCluskeySubsumptionHypergraph-n16-O3-DNDEBUG AES_byte_field_mul_full_2.cnf AES_byte_field_mul_2_pi.cnf > AES_byte_field_mul_2_shg.cnf
shell> cat AES_byte_field_mul_2_shg.cnf | awk --file ${OKPLATFORM}/OKSystem/OKlib/Experimentation/Investigations/Cryptography/AdvancedEncryptionStandard/shg2partial_maxsat.awk > AES_byte_field_mul_2_shg.wcnf
   \endverbatim
   </li>
   <li> We can then use both complete and incomplete weighted partial
   MaxSAT solvers to find minimum and small (minimal) solutions. </li>
   <li> We can use new-ubcsat-okl to find small solutions like so:
   \verbatim
shell> ubcsat-okl  -alg gsat -w -runs 100 -cutoff 1000000 -i AES_byte_field_mul_2_shg.wcnf
   \endverbatim
   and then assuming we find a good solution, we can then extract the solution
   as a CNF file of the small size clause-set:
   \verbatim
shell> new-ubcsat-okl  -alg gsat -w -runs 100 -cutoff 1000000 -wtarget 20 -solve 1 -seed 1402276559 -i AES_byte_field_mul_2_shg.wcnf -r model AES_byte_field_mul_2_m20.result; 
shell> cat AES_byte_field_mul_2_pi.cnf | FilterDimacs AES_byte_field_mul_2_m20.result
   \endverbatim
   </li>
   <li> See "Add new-ubcsat-okl as an option for run_ubcsat" in
   ExperimentSystem/ControllingLocalSearch/plans/DataCollection.hpp
   for discussion on extending run_ubcsat to allow us to find good algorithms 
   for such minimisation problems. </li>
   <li> Add discussion of complete MaxSAT solvers. </li>
  </ul>


  \todo Minimisation at the maxima level.
  <ul>
   <li> Given a full CNF as generated by one of the box CNF generation 
   functions (see 
   ComputerAlgebra/Cryptology/Lisp/Cryptanalysis/Rijndael/FieldOperationsAnalysis.mac
   etc), we can generate all minimum CNF representations like so:
   \verbatim
ss_mul3_min_cnfs : all_minequiv_bvs_cs(ssmult_fullcnf_fcs(3,2,4,ss_polynomial_2_4)[2])$
   \endverbatim
   </li>
  </ul>


  \todo Minimisation using the R QCA package
  <ul>
   <li> The R QCA package is written to deal with problems arising from
   sociology, derives small CNF/DNF representations for (partial) truth
   tables (see "Packages" in 
   BuildSystem/ExternalSources/SpecialBuilds/plans/R.hpp). </li>
   <li> To use the R QCA package we must a truth table as a data file
   readable by the R systems readtable function. Therefore we must
   translate a full CNF (as generated by functions in 
   ComputerAlgebra/Cryptology/Lisp/Cryptanalysis/Rijndael/SboxAnalysis.mac etc)
   into a table format:
   \verbatim
fcl2tt(FF) := 
 append(
   map(lambda([C],
     endcons(0,
       map(lambda([L], if elementp(L, C) then 0 else 1), FF[1]))), FF[2]),
   listify(map(lambda([C],
     endcons(1,
       map(lambda([L], if elementp(L, C) then 0 else 1), FF[1]))), 
       setdifference(all_tass(FF[1]),setify(FF[2])))))$
output_tt2table(TT, n) := 
  with_stdout(n, 
    if length(TT) = 0 then (print("O"), print(1))
    else block(
      apply(print, endcons("O",create_list(i,i,1,length(TT[1])-1))),
      for tt_line in TT do
        apply(print,tt_line)))$
   \endverbatim
   </li>
   <li> So for example, to generate the small scale 4-bit sbox as a R data 
   file, we then do:
   \verbatim
maxima> SboxCNF: fcs2fcl(ss_sbox_fullcnf_fcs(2,4,ss_polynomial_2_4))$
maxima> output_tt2table(fcl2tt(SboxCNF),"Sbox.dat")$
   \endverbatim
   </li>
   <li> We can then use the R QCA package to try to generate a small 
   representation:
   \verbatim
R> oklib_load_all()
R> library(QCA)
R> sbox_tt = read.table("Sbox.tt",header=TRUE)
R> eqmcc(sbox_tt, outcome="O", expl.0=TRUE)
   \endverbatim
   </li>
   <li> This method is unlikely to yield much however, as even for this
   smaller problem (the example 4-bit Sbox), we get:
   \verbatim
Error: Impossible to solve the PI chart (too many possible combinations).
   \endverbatim
   </li>
  </ul>

  
  \todo DONE Update method todos
  <ul>
   <li> The todos "Iterative SAT solving" and
   "Translating to a weighted MaxSAT problem" need to be filled out. 
   </li>
   <li> Minimising using Hypergraph Transversal tools : DONE. </li>
   <li> Iterative SAT solving : DONE. </li>
   <li> Minimisation at the maxima level : DONE. </li>
   <li> Minimisation using the R QCA package : DONE. </li>
   <li> Translating to a weighted MaxSAT problem : DONE. </li>
   <li> Espresso : DONE. </li>
  </ul>
*/
