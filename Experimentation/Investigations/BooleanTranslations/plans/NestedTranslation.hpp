// Oliver Kullmann, 9.1.2010 (Swansea)
/* Copyright 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/BooleanTranslations/plans/NestedTranslation.hpp
  \brief On investigations regarding the nested translations

  The standard nested translation is computed by nbfclud2fcl_standnest(FF)
  at Maxima-level.


  \todo Strong form
  <ul>
   <li> The task is to add binary clauses, in order to strengthen inference.
   </li>
   <li> For k+1 values in the domain, a maximal set of binary clauses (to be
   added to the "remainder") is computed by:
   \verbatim
add_bincl_nec(smusat_horn_stdfcs(k)[2],{},dll_simplest_trivial2);
   \endverbatim
   </li>
   <li> There are various maximal sets of addable binary clauses, but their
   numbers seems to be (constantly) k*(k-1)/2:
   \verbatim
for k : 0 thru 8 do print(k,length(add_bincl_nec(smusat_horn_stdfcs(k)[2],{},dll_simplest_trivial2)));
0 0
1 0
2 1
3 3
4 6
5 10
6 15
7 21
8 28
   \endverbatim
   </li>
   <li> One needs to understand how these solutions arise, and how to choose
   one of them. </li>
   <li> The simplest case is k=2, where we have two possibilities: {{1,2}} and
   {{-2,1}} (where smusat_horn_stdfcs(2) = [{1,2},{{-2,-1},{-1,2},{1}}]). </li>
   <li> k=3
    <ol>
     <li> smusat_horn_stdfcs(3) = [{1,2,3},{{-3,-2,-1},{-2,-1,3},{-1,2},{1}}]
     </li>
     <li> {{1,2},{1,3},{2,3}} is a possible extension. </li>
    </ol>
   </li>
   <li> So it seems one maximal solution for smusat_horn_stdfcs(k) is
   powerset(set(k),2) (which has size k*(k-1)/2); the following tests
   all yield "true":
   \verbatim
for k : 0 thru 5 do block(
 [V : create_list(i,i,1,5),
  D : create_list(i,i,1,k+1), Vt, TR_strong],
  Vt : standnest_TV(D),
  TR_strong : buildq([Vt],lambda([v], listify(powerset(setify(Vt(v)),2)))),
  print(k, gennest_nbfcl2fcl_p(V,lambda([v],D),dll_simplest_trivial2, standnest_T(D),TR_strong,standnest_TV(D))))$
   \endverbatim
   </li>
   <li> And the proof that after addition of all positive binary clauses all
   of the clauses of smusat_horn_stdfcs(k) are still necessary is simple:
   Consider the k+1 total assignment which set at most one variable to false
   (and all other to true): these assignments falsify exactly the k+1 clauses
   from smusat_horn_stdfcs(k) respectively, and satisfy all other clauses.
   </li>
  </ul>


  \todo The order of Horn clauses
  <ul>
   <li> Yet we considered only "standard" weak and strong nested translations,
   where the goal is to minimise the number of literal occurrences, and
   thus the shorter clauses are used for the smaller arithmetic progressions
   (since the number of arithmetic progressions decreases with increasing
   progression size). </li>
   <li> However this creates long clauses. One would use the opposite order
   if the goal is to avoid having long clauses (this would have a tendency to
   make the translated clauses equal in size). </li>
  </ul>


  \todo The reduced forms
  <ul>
   <li> The weak reduced translation is obtained from the strong nested
   translation by performing subsumption-resolution with the additional
   2-clauses (and the resolvents), and then discarding these 2-clauses, while
   for the strong reduced translation they are kept. </li>
   <li> For the fully symmetry problem greentao_3(3,3,3) (see
   Investigations/RamseyTheory/GreenTaoProblems/plans/GreenTao_3-3.hpp)
   the OKsolver actually nodes considerably more time for the strong reduced
   form than for the logarithmic translation, while from the latter by
   two subsumption-resolution-steps per variable we get the strong reduced
   form. This should be just idiosyncratic for the OKsolver_2002's heuristic,
   but in general there is the problem, to which value to associate the long
   clause of the reduced translation. Compare "The order of Horn clauses"
   above. </li>
  </ul>

*/

