// Oliver Kullmann, 11.5.2013 (Swansea)
/* Copyright 2013 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/BooleanFunctions/plans/Hardness/LinearEquations.hpp
  \brief Investigations regarding hardness of representations of systems of linear equations


  \todo gen_2xor_fcl
  <ul>
   <li> Creation:
   \verbatim
output_gen_2xor_stdname(n);
   \endverbatim
   </li>
   <li> The hardness of output_gen_2xor_stdname(n) is precisely n. </li>
   <li> OKsolver_2002-O3-DNDEBUG behaves completely predictable:
    <ol>
     <li> max_tree_depth = n-2 </li>
     <li> number_of_nodes = 2^(n-1) - 1 </li>
     <li> number_of_quasi_single_nodes = 2^(n-3) </li>
     <li> number_of_2-reductions = 2^(n-2) </li>
    </ol>
   </li>
   <li> satz215 behaves completely predictable:
    <ol>
     <li> NB_BACK = 2^(n-3) </li>
     <li> NB_BRANCHE = 2^(n-2) - 1 </li>
    </ol>
    satz215 seems slower than the OKsolver.
   </li>
   <li> march_pl solves these instances quickly via equivalence-reasoning.
   </li>
   <li> minisat also solves all instances via (quick) preprocessing. Would be
   interesting to find it what happens here. </li>
   <li> Also minisat-no-pre solves large instances very quickly (for example
   n=10000 in 15 sec; now of course based on splitting). </li>
   <li> Picosat913 has problems already with n=1000 (aborted after 180 sec,
   apparently without progress). </li>
   <li> Precosat-570 solves instances quickly by preprocessing. </li>
   <li> lingelingala-b02aa1a-121013 solves instances even more quickly than
   minisat-no-pre. </li>
   <li> Also glucose-2.0 seems faster then minisat-no-pre. </li>
   <li> cryptominisat-296 uses apparently a mixture of splitting and
   xor-reasoning (very quick). </li>
   <li> The w-hardness of these instances seems to be 3:
   \verbatim
min_kresolution_closure_cs(fcl2cs(gen_2xor_fcl(3)),2);
[{{-5,-4},{-5,-3},{-5,-2,-1},{-5,-2,1},{-5,-1,2},{-5,1,2},{-4,-2,-1},
 {-4,-2,1},{-4,-1,2},{-4,1,2},{-4,3},{-3,-2,-1},{-3,-2,1},{-3,-1,2},
 {-3,1,2},{-3,4},{-2,-1,3},{-2,-1,4},{-2,-1,5},{-2,1,3},{-2,1,4},
 {-2,1,5},{-1,2,3},{-1,2,4},{-1,2,5},{1,2,3},{1,2,4},{1,2,5},{3,5},{4,5}},
[12,22,30,30]]
for k : 0 thru 5 do print(k, min_kresolution_closure_cs(fcl2cs(gen_2xor_fcl(k)),3));
0 [{{}},[1]]
1 [{{}},[2,1]]
2 [{{}},[4,4,1]]
3 [{{}},[12,30,36,10,1]]
4 [{{}},[20,58,216,122,12,1]]
5 [{{}},[28,90,388,1274,380,54,1]]
   \endverbatim
   </li>
   <li> The symmetric width of these instances seems to be 3:
   \verbatim
for k : 0 thru 10 do print(k, min_bresolution_closure_cs(fcl2cs(gen_2xor_fcl(k)),3));
0 [{{}},[1]]
1 [{{}},[2,1]]
2 [{{}},[4,4,1]]
3 [{{}},[12,30,36,10,1]]
4 [{{}},[20,58,240,142,16,1]]
5 [{{}},[28,90,508,1882,592,34,1]]
6 [{{}},[36,54,64,66,86,88,86,26,1]]
7 [{{}},[44,62,72,74,94,96,94,122,112,52,1]]
8 [{{}},[52,70,80,82,102,104,102,122,124,122,70,1]]
9 [{{}},[60,78,88,90,110,112,110,130,132,130,158,148,88,1]]
10 [{{}},[68,86,96,98,118,120,118,138,140,138,158,160,158,106,1]]
   \endverbatim
   </li>
  </ul>


*/


