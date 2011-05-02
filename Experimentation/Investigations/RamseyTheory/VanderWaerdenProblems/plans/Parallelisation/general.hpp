// Oliver Kullmann, 22.4.2011 (Guangzhou)
/* Copyright 2011 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/VanderWaerdenProblems/plans/Parallelisation/general.hpp
  \brief Using parallel SAT solving for van-der-Waerden problems

  Collaboration of OK, YP.


  \todo Cryptominisat
  <ul>
   <li> Running on a machine (YP, Dawning 5000A/compute-0-80) with 8 quadcore
   cpu's as follows:
   \verbatim
$ more /proc/cpuinfo
model name	: Quad-Core AMD Opteron(tm) Processor 8350
cpu MHz		: 2008.985
cache size	: 512 KB
cpu cores	: 4
bogomips	: 4019.73
   \endverbatim
   we get
   \verbatim
$ time ./cryptominisat --threads=4 VanDerWaerden_2-3-12_135.cnf
c conflicts                : 2703221
real	25m4.821s
user	82m21.972s
sys	0m9.289s
   \endverbatim
   (user-time is sum over all threads) while with 32 threads after 10h of
   total running time still no result was obtained (this might be due to
   scheduling problems). </li>
   <li> One needs to re-run these experiments when nothing else runs on thes
   machine. </li>
  </ul>
  
  
  \todo Simple parallelisation via OKsolver-2002
  <ul>
   <li> See Solvers/OKsolver/SAT2002/plans/SimpleParallelisation.hpp. </li>
   <li> This tool is ready now, via the helper script
   SAT2002/SplittingViaOKsolver (available through a public link). </li>
  </ul>
  
  
  \todo Parallel Satz
  <ul>
   <li> See "Satz" in Buildsystem/ExternalSources/SpecialBuilds/plans/SAT.hpp.
   </li>
  </ul>
  
  
  \todo Using Open MPI
  <ul>
   <li> It seems that to run even the "simple parallelisation" provided e.g.
   by the OKsolver-2002 (see above) on a "supercomputer" (like "Dawning
   5000A"; see above) one needs to utilise the Open-Mpi-interface. </li>
   <li> See http://www.open-mpi.org. </li>
  </ul>
  
  
  \todo Verify vdw_2(4,9) = 309 (conjectured)
  <ul>
   <li> See 
   Investigations/RamseyTheory/VanderWaerdenProblems/plans/4-k/09.hpp. </li>
   <li> Via
   \verbatim
OKplatform> SplittingViaOKsolver -D12 VanDerWaerden_2-4-9_309.cnf
OKplatform> more SplitViaOKsolver_D12VanDerWaerden_249_309cnf_2011-04-23-114006/Statistics
> E=read.table("Data")
> summary(E)
       n
 Min.   :12.00
 1st Qu.:12.00
 Median :14.00
 Mean   :13.92
 3rd Qu.:15.00
 Max.   :28.00
> table(E)
E
  12   13   14   15   16   17   18   19   20   21   22   23   25   28
1157  779  957  420  413  167  109   39   28   12    8    4    1    2
OKplatform> more SplitViaOKsolver_D12VanDerWaerden_249_309cnf_2011-04-23-114006/Result
s UNKNOWN
c sat_status                            2
c initial_maximal_clause_length         9
c initial_number_of_variables           309
c initial_number_of_clauses             21573
c initial_number_of_literal_occurrences 115362
c number_of_initial_unit-eliminations   0
c reddiff_maximal_clause_length         0
c reddiff_number_of_variables           0
c reddiff_number_of_clauses             0
c reddiff_number_of_literal_occurrences 0
c number_of_2-clauses_after_reduction   0
c running_time(sec)                     486.1
c number_of_nodes                       8191
c number_of_single_nodes                0
c number_of_quasi_single_nodes          0
c number_of_2-reductions                1
c number_of_pure_literals               0
c number_of_autarkies                   0
c number_of_missed_single_nodes         0
c max_tree_depth                        12
c number_of_table_enlargements          0
c number_of_1-autarkies                 0
c number_of_new_2-clauses               0
c maximal_number_of_added_2-clauses     0
c file_name                             VanDerWaerden_2-4-9_309.cnf
c splitting_directory                   SplitViaOKsolver_D12VanDerWaerden_249_309
cnf_2011-04-23-114006/Instances
c splitting_cases                       4096

OKplatform> SplittingViaOKsolver -D16 VanDerWaerden_2-4-9_309.cnf
OKplatform> more SplitViaOKsolver_D16VanDerWaerden_249_309cnf_2011-04-23-115118/Statistics
> E=read.table("Data")
> summary(E)
       n
 Min.   :16.00
 1st Qu.:18.00
 Median :20.00
 Mean   :20.87
 3rd Qu.:23.00
 Max.   :52.00
> table(E)
E
  16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31
3595 5286 9092 8508 8788 7294 5932 4546 3366 2610 1870 1369  959  679  540  325
  32   33   34   35   36   37   38   39   40   41   42   43   44   45   46   52
 241  176  121   76   56   27   13   18   12    8   12    5    4    6    1    1
OKplatform> more SplitViaOKsolver_D16VanDerWaerden_249_309cnf_2011-04-23-115118/Result
s UNKNOWN
c sat_status                            2
c initial_maximal_clause_length         9
c initial_number_of_variables           309
c initial_number_of_clauses             21573
c initial_number_of_literal_occurrences 115362
c number_of_initial_unit-eliminations   0
c reddiff_maximal_clause_length         0
c reddiff_number_of_variables           0
c reddiff_number_of_clauses             0
c reddiff_number_of_literal_occurrences 0
c number_of_2-clauses_after_reduction   0
c running_time(sec)                     4656.9
c number_of_nodes                       131071
c number_of_single_nodes                0
c number_of_quasi_single_nodes          0
c number_of_2-reductions                401
c number_of_pure_literals               0
c number_of_autarkies                   0
c number_of_missed_single_nodes         0
c max_tree_depth                        16
c number_of_table_enlargements          0
c number_of_1-autarkies                 0
c number_of_new_2-clauses               0
c maximal_number_of_added_2-clauses     0
c file_name                             VanDerWaerden_2-4-9_309.cnf
c splitting_directory                   SplitViaOKsolver_D16VanDerWaerden_249_309
cnf_2011-04-23-115118/Instances
c splitting_cases                       65536

OKplatform> SplittingViaOKsolver -D20 VanDerWaerden_2-4-9_309.cnf
Kplatform> more SplitViaOKsolver_D20VanDerWaerden_249_309cnf_2011-04-23-154844/Statistics
> E=read.table("Data")
> summary(E)
       n
 Min.   : 20.00
 1st Qu.: 26.00
 Median : 29.00
 Mean   : 29.68
 3rd Qu.: 33.00
 Max.   :152.00
> table(E)
E
   20    21    22    23    24    25    26    27    28    29    30    31    32
 5450 14228 32543 49590 69076 81356 88914 88741 86047 79358 71111 62380 53753
   33    34    35    36    37    38    39    40    41    42    43    44    45
45800 39111 32446 27142 22184 18379 15028 12098  9927  8171  6647  5320  4327
   46    47    48    49    50    51    52    53    54    55    56    57    58
 3394  2862  2267  1765  1478  1103   944   766   578   500   403   291   299
   59    60    61    62    63    64    65    66    67    68    69    70    71
  254   173   165   141   119    89    81    56    44    44    37    37    20
   72    73    74    75    76    77    78    79    80    81    82    84    85
   17    15    14    11     9     9     7     2     2     2     1     4     1
   87    88    89    91    94   118   125   127   131   132   139   140   143
    1     1     1     2     1     1     1     1     1     1     1     2     1
  144   145   146   148   149   150   152
    4     1     1     2     1     1     1
Kplatform> more SplitViaOKsolver_D20VanDerWaerden_249_309cnf_2011-04-23-154844/Result
s UNKNOWN
c sat_status                            2
c initial_maximal_clause_length         9
c initial_number_of_variables           309
c initial_number_of_clauses             21573
c initial_number_of_literal_occurrences 115362
c number_of_initial_unit-eliminations   0
c reddiff_maximal_clause_length         0
c reddiff_number_of_variables           0
c reddiff_number_of_clauses             0
c reddiff_number_of_literal_occurrences 0
c number_of_2-clauses_after_reduction   0
c running_time(sec)                     38099.4
c number_of_nodes                       2096621
c number_of_single_nodes                0
c number_of_quasi_single_nodes          0
c number_of_2-reductions                57332
c number_of_pure_literals               0
c number_of_autarkies                   0
c number_of_missed_single_nodes         0
c max_tree_depth                        20
c number_of_table_enlargements          0
c number_of_1-autarkies                 0
c number_of_new_2-clauses               0
c maximal_number_of_added_2-clauses     0
c file_name                             VanDerWaerden_2-4-9_309.cnf
c splitting_directory                   SplitViaOKsolver_D20VanDerWaerden_249_309
cnf_2011-04-23-154844/Instances
c splitting_cases                       1047157
   \endverbatim
   we split it into 2^12=4096 resp. 2^16=65536 resp. 1047157 subproblems.
   </li>
   <li> So with D=20 we have less then 2^20=1048576 possible sub-problems.
   </li>
   <li> For these subproblems one needs to find out the best solver, and
   what the average running time might be. </li>
   <li> One should try to fit the curve for node/conflict-numbers in dependency
   on the size of the partial assignment ("n" above). </li>
   <li> And one needs to repeat this for different values of D, searching for
   the optimum. </li>
   <li> One should ease the access to subproblems with a given number of
   eliminated variables.
    <ol>
     <li> Perhaps sorting the table in R, and then outputting it in some
     appropriate form. </li>
     <li> This should be linked to experimentation. </li>
     <li> The problems with, say, more than 100 variables eliminated should be
     very easy. </li>
    </ol>
   </li>
   <li> One should investigate whether at least for splitting-depth 20 there
   could be single nodes. </li>
  </ul>
  
  
  \todo Verify vdw_2(5,7) = 260 (conjectured)
  <ul>
   <li> See 
   Investigations/RamseyTheory/VanderWaerdenProblems/plans/5-k/07.hpp. </li>
   <li>
   \verbatim
OKplatform> SplittingViaOKsolver -D12 VanDerWaerden_2-5-7_260.cnf
OKplatform> more SplitViaOKsolver_D12VanDerWaerden_257_260cnf_2011-04-25-142303/Statistics
> E=read.table("Data")
> summary(E)
       n
 Min.   :12.00
 1st Qu.:12.00
 Median :13.00
 Mean   :13.38
 3rd Qu.:14.00
 Max.   :22.00
> table(E)
E
  12   13   14   15   16   17   18   19   20   21   22
1428 1118  740  452  203   84   54    8    6    2    1
OKplatform> more SplitViaOKsolver_D12VanDerWaerden_257_260cnf_2011-04-25-142303/Result
s UNKNOWN
c sat_status                            2
c initial_maximal_clause_length         7
c initial_number_of_variables           260
c initial_number_of_clauses             13824
c initial_number_of_literal_occurrences 80128
c number_of_initial_unit-eliminations   0
c reddiff_maximal_clause_length         0
c reddiff_number_of_variables           0
c reddiff_number_of_clauses             0
c reddiff_number_of_literal_occurrences 0
c number_of_2-clauses_after_reduction   0
c running_time(sec)                     71.0
c number_of_nodes                       8191
c number_of_single_nodes                0
c number_of_quasi_single_nodes          0
c number_of_2-reductions                1
c number_of_pure_literals               0
c number_of_autarkies                   0
c number_of_missed_single_nodes         0
c max_tree_depth                        12
c number_of_table_enlargements          0
c number_of_1-autarkies                 0
c number_of_new_2-clauses               0
c maximal_number_of_added_2-clauses     0
c file_name                             VanDerWaerden_2-5-7_260.cnf
c splitting_directory                   SplitViaOKsolver_D12VanDerWaerden_257_260
cnf_2011-04-25-142303/Instances
c splitting_cases                       4096

OKplatform> SplittingViaOKsolver -D16 VanDerWaerden_2-5-7_260.cnf
OKplatform> more SplitViaOKsolver_D16VanDerWaerden_257_260cnf_2011-04-25-143203/Statistics
> E=read.table("Data")
> summary(E)
       n
 Min.   :16.00
 1st Qu.:17.00
 Median :18.00
 Mean   :18.68
 3rd Qu.:20.00
 Max.   :34.00
> table(E)
E
   16    17    18    19    20    21    22    23    24    25    26    27    28
 9177 12561 13302 10882  7966  4878  3145  1769   931   486   223   121    53
   29    30    32    33    34
   25    13     2     1     1
OKplatform> more SplitViaOKsolver_D16VanDerWaerden_257_260cnf_2011-04-25-143203/Result
s UNKNOWN
c sat_status                            2
c initial_maximal_clause_length         7
c initial_number_of_variables           260
c initial_number_of_clauses             13824
c initial_number_of_literal_occurrences 80128
c number_of_initial_unit-eliminations   0
c reddiff_maximal_clause_length         0
c reddiff_number_of_variables           0
c reddiff_number_of_clauses             0
c reddiff_number_of_literal_occurrences 0
c number_of_2-clauses_after_reduction   0
c running_time(sec)                     3805.9
c number_of_nodes                       131071
c number_of_single_nodes                0
c number_of_quasi_single_nodes          0
c number_of_2-reductions                134
c number_of_pure_literals               0
c number_of_autarkies                   0
c number_of_missed_single_nodes         0
c max_tree_depth                        16
c number_of_table_enlargements          0
c number_of_1-autarkies                 0
c number_of_new_2-clauses               0
c maximal_number_of_added_2-clauses     0
c file_name                             VanDerWaerden_2-5-7_260.cnf
c splitting_directory                   SplitViaOKsolver_D16VanDerWaerden_257_260
cnf_2011-04-25-143203/Instances
c splitting_cases                       65536

OKplatform> SplittingViaOKsolver -D20 VanDerWaerden_2-5-7_260.cnf
OKplatform> more SplitViaOKsolver_D20VanDerWaerden_257_260cnf_2011-04-25-170946/Statistics
> E=read.table("Data")
> summary(E)
       n
 Min.   :20.00
 1st Qu.:22.00
 Median :24.00
 Mean   :24.65
 3rd Qu.:26.00
 Max.   :70.00
> table(E)
E
    20     21     22     23     24     25     26     27     28     29     30
 40841  88833 133680 153876 151467 131506 104803  79336  56249  38242  25576
    31     32     33     34     35     36     37     38     39     40     41
 16393  10392   6558   4070   2492   1564    947    638    394    266    162
    42     43     44     45     46     47     48     49     50     51     53
   101     63     45     31     10     12      5      3      2      1      5
    54     55     56     59     61     62     66     67     70
     1      1      1      3      2      1      1      1      1
OKplatform> more SplitViaOKsolver_D20VanDerWaerden_257_260cnf_2011-04-25-170946/Result
s UNKNOWN
c sat_status                            2
c initial_maximal_clause_length         7
c initial_number_of_variables           260
c initial_number_of_clauses             13824
c initial_number_of_literal_occurrences 80128
c number_of_initial_unit-eliminations   0
c reddiff_maximal_clause_length         0
c reddiff_number_of_variables           0
c reddiff_number_of_clauses             0
c reddiff_number_of_literal_occurrences 0
c number_of_2-clauses_after_reduction   0
c running_time(sec)                     42958.5
c number_of_nodes                       2097151
c number_of_single_nodes                0
c number_of_quasi_single_nodes          0
c number_of_2-reductions                5912
c number_of_pure_literals               0
c number_of_autarkies                   0
c number_of_missed_single_nodes         0
c max_tree_depth                        20
c number_of_table_enlargements          0
c number_of_1-autarkies                 0
c number_of_new_2-clauses               0
c maximal_number_of_added_2-clauses     0
c file_name                             VanDerWaerden_2-5-7_260.cnf
c splitting_directory                   SplitViaOKsolver_D20VanDerWaerden_257_260
cnf_2011-04-25-170946/Instances
c splitting_cases                       1048575
   \endverbatim
  </ul>
  
*/