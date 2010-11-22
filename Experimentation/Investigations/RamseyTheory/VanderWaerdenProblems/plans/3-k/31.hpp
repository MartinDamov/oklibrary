/* Copyright 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/VanderWaerdenProblems/plans/3-k/31.hpp
  \brief On investigations into vdw_2(3,31)


  \todo vanderwaerden_2(3,31) > 918
  <ul>
   <li> n=900
    <ol>
     <li> rots, cutoff=10^7:
     \verbatim
 1  2  3  4  5  6
 4 16 46 84 40  1
191
     \endverbatim
     So higher cutoffs are needed.
     </li>
     <li> rots, cutoff=10^7:
     \verbatim
 1  2  3  4  5
 5 16 31 39  1
92
     \endverbatim
     Again, higher cutoffs are needed.
     </li>
    </ol>
   </li>
   <li> n=906: a solution was found, adapted from the solution for k=30,
   n=901, with certificate
   \verbatim
25,48,53,56,80,85,102,103,130,139,
152,167,173,177,196,199,208,210,213,214,
228,245,270,271,284,288,302,310,315,319,
337,356,361,374,384,413,419,426,432,435,
448,450,472,485,493,495,506,529,530,532,
546,561,566,578,584,604,611,615,617,635,
640,643,648,658,670,677,694,707,717,726,
747,752,759,763,765,769,781,806,826,828,
829,833,863,876
   \endverbatim
   </li>
   <li> n=914: a solution was found, adapted from the solution for n=907,
   with certificate
   \verbatim
25,26,41,59,78,88,111,132,137,143,
148,170,173,199,217,222,226,236,243,256,
280,284,285,293,294,318,328,331,337,359,
367,370,392,396,421,429,442,444,458,465,
469,470,476,479,502,503,506,515,522,532,
555,559,569,576,589,613,617,618,626,651,
661,670,691,698,700,701,729,738,744,762,
772,791,802,814,835,848,849,855,886
   \endverbatim
   </li>
   <li> n=916: a solution was found, adapted from the solution for n=915,
   with certificate
   \verbatim
30,61,71,76,99,102,113,121,145,152,
173,178,182,195,210,224,226,227,232,261,
263,283,284,289,301,320,324,330,337,338,
345,363,394,398,412,417,431,435,454,456,
474,483,485,493,506,509,528,552,557,559,
560,565,580,594,596,617,622,634,653,657,
663,670,671,691,700,731,733,745,750,752,
764,779,789,807,811,816,838,842,863,885,
900
   \endverbatim
   </li>
   <li> n=917:
    <ol>
     <li> rots, cutoff=2*10^7:
     \verbatim
 1  2  3   4  5  6 
 4 18 50 124 82  2 
280
  1   2   3   4   5   6 
 21  55 148 391 246  10 
871 
     \endverbatim
     </li>
    </ol>
   </li>
   <li> n=918: rots found a solution, adapted from n=917, cutoff=5*10^7,
   with certificate:
   \verbatim
10,40,59,67,84,98,104,115,120,121,
133,148,177,185,191,194,209,214,231,252,
254,283,288,289,305,306,318,325,337,343,
363,370,376,392,394,402,407,411,417,429,
448,476,481,487,510,513,518,522,524,542,
547,564,585,587,616,617,621,638,639,653,
658,688,696,703,709,733,735,740,746,762,
787,809,816,820,844,846,855,860,873,898,
910
   \endverbatim
   </li>
  </ul>


  \todo Palindromic version
  <ul>
   <li> Best ubcsat-algorithm:
   \verbatim
> PdVanderWaerdenCNF-O3-DNDEBUG 3 31 919 > VanDerWaerden_pd_2-3-31_919.cnf

> E=run_ubcsat("VanDerWaerden_pd_2-3-31_919.cnf",runs=100,cutoff=1000000)

> plot(E$alg,E$min)
> table(E$min[E$alg=="gsat_tabu"])
 1  2  3
20 70 10
> table(E$FlipsPerSecond[E$alg=="gsat_tabu"])
67526
  100
> table(E$min[E$alg=="samd"])
 1  2  3
12 65 23
> table(E$FlipsPerSecond[E$alg=="samd"])
60536
  100
   \endverbatim
   shows clearly that gsat-tabu is best, followed by samd (which is also
   slower). (Currently eval_ubcsat_dataframe(E) is not usable due to a bug in
   run_ubcsat.) </li>
  </ul>

*/