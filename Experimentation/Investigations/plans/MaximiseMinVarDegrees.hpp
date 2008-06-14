// Oliver Kullmann, 2.6.2008 (Swansea)
/* Copyright 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/plans/MaximiseMinVarDegrees.hpp
  \brief Plans on investigations into the maximum of the min-var-degree of parameterised classes of unsatisfiable clause-sets


  \todo Minimally unsatisfiable clause-sets
  <ul>
   <li> See under "Maximal min-var-degrees" in
   ComputerAlgebra/Satisfiability/Lisp/MinimalUnsatisfiability/Basics.mac
   </li>
  </ul>


  \todo Unsatisfiable non-singular hitting clause-sets
  <ul>
   <li> See under "Maximal min-var-degrees" in
   ComputerAlgebra/Satisfiability/Lisp/MinimalUnsatisfiability/Basics.mac
   </li>
   <li> And see todo "Maximal min-var-degrees" in
   ComputerAlgebra/Satisfiability/Lisp/MinimalUnsatisfiability/plans/general.hpp
   </li>
   <li> The function "sharp_uhit_catalogue_maxminvardeg" investigates
   the catalogue for the sharp cases w.r.t. the general upper bound. </li>
   <li> n-oriented investigations:
    <ol>
     <li> One tool is e.g. "all_unsinghitting(5, 'all_n5)" and
     "all_unsinghitting_mvd(5, 'all_n5)" for searching through all
     cases for n=5. </li>
     <li> And then applying e.g.
     "d_all_n5 : analyse_isorepo_defset_mvd(all_n5)"
     to get the sharp cases obtained. </li>
     <li> While by "d_all_n5 : analyse_isorepo_defset_imprmvd(all_n5)"
     we get the cases which improve upon the catalogue; this belongs
     more to the "deficiency-oriented investigations" below. </li>
     <li> However in this way it seems very unlikely to get sharp
     examples for deficiencies much smaller than the gap-deficiencies. </li>
     <li> While determining the possible distribution of clause-lengths
     due to the condition sum_C 2^(-|C|) = 1 by all_cld_uhit_maxminvd
     and then either determining that there are no examples for the given
     n, or constructing them by hand seems to be more successful. </li>
     <li> See "all_cld_uhit_minvd" in
     ComputerAlgebra/Satisfiability/Lisp/ConflictCombinatorics/plans/HittingClauseSets.hpp
     for further strengthenings of this approach (especially regarding
     the use of (generalised) SAT solving). </li>
     <li> We know that the bound max_min_var_degree_def is sharp
     for given n and deficiencies k = 2^n-n - i for 0 <= i <= n. </li>
     <li> For n <= 3 this cannot be applied fully, and there we also
     have full information. </li>
     <li> For n=4 we obtain k = 12, 11,10,9,8.
      <ul>
       <li> And actually cases for k=7 are known where the bound is sharp.
       </li>
       <li> While this cannot be the case for k = 6. </li>
       <li> And also not for k = 5. </li>
       <li> But we have again sharpness for k=3,4. </li>
      </ul>
      This information is complete. </li>
     </li>
     <li> n = 5:
      <ol>
       <li> The general cases for sharpness are k = 27, 26,25,24,23,22. </li>
       <li> Also for k = 18,19,20,21 we have sharp cases. </li>
       <li> One could conjecture that there is no sharp case for k <= 17,
       however k=4 below is a counter-example. </li>
       <li> For k = 17 we have all_cld_uhit_maxminvd(k,5) =
       {{[2,1],[3,1],[5,20]}}, thus there exists a variable not
       occurring in the first two clauses, and thus occurring only
       22 - 2 = 20 < 21 times, so here there is no sharp case. </li>
       <li> For k = 13,14,15,16 due to all_cld_uhit_maxminvd(k,5) = {}
       we know there are no sharp cases. </li>
       <li> For k = 12 we have all_cld_uhit_maxminvd(k,5) =
       {{[1,1],[5,16]}}, and so there is no non-singular sharp case. </li>
       <li> k = 11 ? </li>
       <li> k = 10 ? </li>
       <li> k = 9 ? </li>
       <li> k = 8 ? </li>
       <li> k = 7 ? </li>
       <li> For k = 6 we have the only the non-singular case
       {{[2,3],[5,8]}}, and so there is a variable not occurring in the
       first three clauses, thus occurring 11 - 3 = 8 < 9 time, so
       here is no sharp case. </li>
       <li> For k = 5 the only non-singular case is {[2,3],[4,1],[5,6]}},
       so again in variable is not occurring in the first three clauses,
       thus occurring 10 - 3 = 7 < 8 times, so no sharp case here. </li>
       <li> For k = 4 we have a sharp case. </li>
       <li> For k = 3 the non-singular cases are
        <ul>
         <li> {[2,1],[3,5],[4,2]} ? </li>
         <li> {[2,2],[3,2],[4,4]} ? </li>
         <li> {[2,2],[3,3],[4,1],[5,2]} ? </li>
         <li> {[2,3],[3,1],[5,4]} ? </li>
         <li> {[2,3],[4,3],[5,2]} ? </li>
        </ul>
       </li>
      </ol>
     </li>
     <li> For n=6 we only have incomplete information.
      <ol>
       <li> The general cases for sharpness are k = 58, 56,55,54,53,52,51.
       </li>
       <li> And then we have sporadic cases for k = 43. </li>
       <li> We should also get all min-var-degree-maximal cases
       into the catalogue, but likely only optionally. </li>
       <li> For 14 <= k <=  19 we have all_cld_uhit_maxminvd_nu(13,6)={},
       and so we do not have sharp cases here. </li>
       <li> k = 13: all_cld_uhit_maxminvd_nu(13,6)={{[2,3],[6,16]}},
       where the first 3 binary clauses must leave out one variable,
       which then occurs 19 - 3 = 16 < 17 times, so no sharp case here. </li>
       <li> k = 6: all_cld_uhit_maxminvd_nu(6,6) has the following cases:
        <ul>
         <li> {[2,2],[3,3],[5,1],[6,6]}: Impossible, since a hitting cls
         consisting of two binary and two ternary clauses can contain at
         most 5 variables. </li>
         <li> {[2,3],[3,1],[6,8]}: Impossible, since the first three clauses
         can involve only 3 variables, so the first four clauses can only
         involve 5 variables, thus one variable has occurrence
         12 - 4 = 8 < 9. </li>
         <li> {[2,3],[4,1],[5,4],[6,4]}: Impossible, since the first three
         clauses only involve 3 variables, so the fourth clause
         only can contain one of them, so this literal must provide the
         clash with the first three clauses, which is not possible. </li>
         <li> {[2,3],[4,2],[5,1],[6,6]}: Impossible, since the fourth clause
         can only introduce 2 new variables, leaving one variable not
         occurring four times. </li>
        </ul>
        So no sharp case here.
       </li>
      </ol>
     </li>
     <li> For n=7 we only have incomplete information.
      <ol>
       <li> The general cases for sharpness are
       k = 121, 120,119,118,117,116,115,114. </li>
       <li> k = 17 : all_cld_uhit_maxminvd_nu(17,7) =
       {{[2,3],[4,1],[5,1],[6,1],[7,18]}}: The first  three clauses can
       only use 3 variables, so the first four clauses leave out one
       variable, which then occurs 24 - 4 = 20 < 21 times. So no sharp case
       here. </li>
       <li> For k = 15,16 we have all_cld_uhit_maxminvd_nu(k,7)={},
       and so we do not have sharp cases here.
       <li> k = 14 : all_cld_uhit_maxminvd_nu(14,7)={{[2,3],[4,2],[7,16]}}.
       The first  three clauses can only use 3 variables, so the first four
       clauses leave out one variable, which then occurs 21 - 4 = 17 < 18
       times. So no sharp case here. </li>
       <li> k = 13: all_cld_uhit_maxminvd_nu(13,7)={{[2,3],[3,1],[7,16]}}.
       Now a hitting cls F with c(F) = 3 which is 2-uniform has
       n(F) <= 3, and thus the first 4 clauses must leave out one variable,
       which then occurs 20 - 4 = 16 < 17 times. So no sharp case here. </li>
       <li> k = 6: The cases of all_cld_uhit_maxminvd_nu(6,7) are as follows.
        <ul>
         <li> Every variable can loose at most 4 occurrences. </li>
         <li> {[2,2],[3,3],[4,1],[6,1],[7,6]}: Impossible. </li>
         <li> {[2,2],[3,3],[5,2],[6,2],[7,4]}: Impossible for the same
         reason. </li>
         <li> {[2,3],[3,1],[4,1],[7,8]}: Impossible, like the following
         case. </li>
         <li> {[2,3],[3,1],[5,1],[6,4],[7,4]}: Impossible, since the first
         four clauses can only contain 4 variables (see below), so the
         fifth clause must contain all other 3 variables, and two of
         literals are furthermore fixed for the clash with the first three
         clauses, which, since this is the same for the fourth clause, doesn't
         leave a conflict with the fourth clause. So 13 - 5 = 8 < 9. </li>
         <li> {[2,3],[3,1],[5,2],[6,1],[7,6]}: Impossible as the previous
         case. </li>
         <li> {[2,3],[3,1],[6,7],[7,2]} </li>
         <li> {[2,3],[4,1],[5,5],[7,4]} </li>
         <li> {[2,3],[4,2],[5,1],[6,5],[7,2]} </li>
         <li> {[2,3],[4,2],[5,2],[6,2],[7,4]} </li>
         <li> {[2,3],[4,3],[6,1],[7,6]} </li>
        </ul>
        A general principle:
        <ul>
         <li> If hitting F consists of 3 binary variables,
         then the only cases are
          <ol>
           <li> A : {{a,b},{-a,b},{-b,a}} </li>
           <li> B : {{a,b},{-a,c},{-a,-c}} </li>
           <li> C : {{a,b},{-a,c},{-b,-c}} </li>
          </ol>
          and every other clause must contain two of these variables
          to produce a clash (in case of case C it must contain all
          three, while in case A it must contain {-a,-b}, and in
          case B it must contain {a,-b}). </li>
         <li> This follows from the fact that the sub-clause-set
         consisting of these four clauses is hitting, and we can
         remove all pure literals, so only the three variables
         involved are of relevance. </li>
         <li> Every hitting cls has sum_C 2^(-|C|) <= 1, thus
         the last clause must then be binary. </li>
         <li> And this last clause is then also unique (since only
         one satisfying assignment is left). </li>
        </ul>
       </li>
      </ol>
     </li>
     <li> For n=8 we only have incomplete information.
      <ol>
       <li> The general cases for sharpness are
       k = 248, 247,246,245,244,243,242,241,240. </li>
       <li> k = 13: all_cld_uhit_maxminvd_nu(13,8) has the following cases:
        <ul>
         <li> {[2,2],[3,3],[4,1],[7,1],[8,14]} </li>
         <li> [2,3],[3,1],[4,1],[8,16]} </li>
         <li> {[2,3],[3,1],[5,1],[6,2],[7,2],[8,12]} </li>
         <li> {[2,3],[3,1],[5,2],[7,1],[8,14]} </li>
         <li> {[2,3],[4,3],[7,1],[8,14]}} </li>
        </ul>
        The first cases look impossible, perhaps the last one might be
        possible.
       </li>
      </ol>
     </li>
    </ol>
   </li>
   <li> Deficiency-oriented investigations:
    <ol>
     <li> max_min_var_deg_uhit_def(k) yields the maximal min-var-deg
     realised in the uhit_def-catalogue for deficiency k. </li>
     <li> We have sharpness w.r.t. the bound for k in
     {2, 3,4,5, 7, 8,9,10,11,12, 18,19,20,21, 22,23,24,25,26,27,
     43, 51,52,53,54,55,56,58},
     </li>
     <li> So one could conjecture that always directly after the "gap"
     we have an interval where the bound is not sharp. </li>
     <li> We have the current maxima for the non-sharp cases (compared
     to the upper bound):
      <ul>
       <li> k = 6 : 8 = 9-1
        <ol>
         <li> The above show that for a sharp case we have n >= 7. </li>
         <li> A general fact, which might be useful:
          <ol
           <li> A variable realising the
           min-var-degree occorrs w.l.o.g. (exactly) 5 times positively and
           4 times negatively, since in case of 6+3=9 setting v -> 1 yields an
           MU of deficiency 1, yielding a variable occurring 2 + 6 = 8 < 9
           times. </li>
           <li> So setting v -> 0 yields F0 in MU(3), and v -> 1 yields F1 in
           MU(2) (assuming, as usual F saturated). </li>
           <li> Since there is a variable in MU(3) of degree 5, we can have
           at most 5 full clauses containing literal v. </li>
          </ol>
         </li>
        </ol>
       </li>
       <li> k = 13 : 16 = 17-1
        <ol>
         <li> The above show that for a sharp case we have n >= 8. </li>
        </ol>
       </li>
       <li> k = 14 : 17 = 18-1
        <ol>
         <li> The above show that for a sharp case we have n >= 8. </li>
        </ol>
       </li>
       <li> k = 15 : 18 = 19-1
        <ol>
         <li> The above show that for a sharp case we have n >= 8. </li>
        </ol>
       </li>
       <li> k = 16 : 19 = 20-1
        <ol>
         <li> The above show that for a sharp case we have n >= 8. </li>
        </ol>
       </li>
       <li> k = 17 : 20 = 21-1
        <ol>
         <li> The above show that for a sharp case we have n >= 8. </li>
        </ol>
       </li>
      </ul>
     </li>
    </ol>
   </li>
  </ul>

*/
