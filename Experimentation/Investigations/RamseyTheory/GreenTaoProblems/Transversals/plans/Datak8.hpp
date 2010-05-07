// Oliver Kullmann, 23.4.2010 (Swansea)
/* Copyright 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/GreenTaoProblems/Transversals/plans/Datak8.hpp
  \brief Investigating the transversal hypergraph of Green-Tao hypergraphs for k = 8 (length of arithmetic progressions)


  \todo Elementary statistics
  <ul>
   <li> Investigating tr_arithprog_hg(8,n). </li>
   <li> The numbers of minimum hyperedges:
   \verbatim
L8 : [];
minimum_transversals_decomp_gen(inf,lambda([n],arithprog_primes_hg(8,n)),'L8)$

T : transform_steps_l(map(lambda([d],d[4][1]),reverse(L8)));
 [262,348,664,788,1322,1427,1446,1472,1554,1800,1880,1934,1978,2116,2260,2405,2436,2567,2572,
        2650,2815,2869,3139,3214,3240,3246,3252,3323,3396,3457,3482,3488,3492,3543,3698,3771,3772,
        3899,3993,4180,4218,4305,4310,4317,4384,4404,4432,4502,4503,4516,4817,4991,5011,5023,5156,
        5260,5439,5442,5507,5578,5646,5664,5674,5682,5791,5832,5856,5985,6052,6089,6140,6142,6245,
        6259,6326,6341,6456,6483,6492,6604,6624,6702,6748,6805,6809,6867,7038,7042,7046,7201,7329,
        7358,7523,7676,7692,7792,7825,7920,7944,8010,8023,8048,8075,8275,8276,8307,8415,8432,8465,
        8471,8657,8712,8715,8752,8779,8807,8895,8958,8976,9031,9086,9095,9214,9245,9268,9279,9287,
        9329,9352,9356,9388,9426,9453,9459,9491,9721,9766,9856,9870,9872,9875,9888,9896,9917,10001,
        10003,10118,10137,10200,10243,10264,10560,10627,10801,10807,10858,10867,10886,10937,10971,
        10990,11093,11103,11109,11153,11160,11173,11184,11222,11309,11358,11488,11495,11509,11577,
        11637,11646,11678,11704,11724,11741,11925,12020,12178,12240,12252,12260,12285,12301,12332,
        12426,12436,12701,12736,12798,12805,12813,12889,12938,12944,13051,13109,13171,13192,13199,
        13221,13241,13340,13445,13451,13461,13478,13521,13524,13588,13591,13632,13660,13666,13759,
        13841,13842,13872,13946,14041,14054,14065,14109,14171,14253,14255,14272,14389,14440,14547,
        14553,14565,14598,14608,14685,14836,15003,15065,15138,15196,15224,15255,15338,15356,15405,
        15406,15424,15458,15514,15543,15545,15592,15624,15661,15683,15749,15763,15767]

length(T);
 263
   \endverbatim
   </li>
  </ul>


  \todo Only computing the transversal numbers
  <ul>
   <li> Just computing the transversal numbers, using minisat2 and the
   direct translation:
   \verbatim
> GTTransversalsInc 8 1 0 GT_8 GT_8_SAT

L : transform_steps_l(map(third,rest(read_nested_list("GT_8"))));
 [262,348,664,788,1322,1427,1446,1472,1554,1800,1880,1934,1978,2116,2260,2405]
length(L);
 16

> tail -1 GT_8
8 2436 16

> tail  GT_8_SAT
|   3366628 |    4736    21772    76494 |    75537    35253     71 |  6.735 % |
|   5050043 |    4736    21772    76494 |    83091    76486    147 |  6.735 % |
|   7575160 |    4736    21772    76494 |    91400    41104     93 |  6.735 % |
|  11362836 |    4640    21356    75402 |   100540    91925    226 |  7.561 % |
|  17044348 |    4640    21356    75402 |   110594    89911    136 |  7.561 % |
|  25566617 |    4640    21356    75402 |   121654    97296    138 |  7.561 % |
|  38350020 |    4640    21356    75402 |   133819    24400     88 |  7.561 % |
|  57525125 |    4640    21356    75402 |   147201   132652    143 |  7.561 % |
|  86287784 |    4640    21356    75402 |   161921    56646     90 |  7.561 % |
| 129431775 |    4640    21356    75402 |   178113    36818     65 |  7.561 % |
   \endverbatim
   </li>
  </ul>

*/
