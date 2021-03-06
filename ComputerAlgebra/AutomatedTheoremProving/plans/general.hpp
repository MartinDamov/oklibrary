// Oliver Kullmann, 8.4.2008 (Swansea)
/* Copyright 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/AutomatedTheoremProving/plans/general.hpp
  \brief Plans for automated theorem proving using computer algebra systems

  A long-term goal is to provide a experimental systems where SAT and ATP
  coexist, so that approaches for integrating SAT into ATP can be studied.


  \todo Clause-based approach
  <ul>
   <li> First we need a representation of terms. </li>
   <li> Then we need to implement unification algorithms. </li>
   <li> Then the various inference rules need to be implemented:
    <ol>
     <li> resolution rules </li>
     <li> equality rules. </li>
    </ol>
   </li>
   <li> Finally, the strategies guiding the inference process are
   implemented. </li>
  </ul>


  \todo Connections
  <ul>
   <li> Currently (8.4.2008) the only examples come from formalising
   set theory: See AutomatedTheoremProving/SetTheory/NeumannBernaysGoedel/plans/general.hpp. </li>
  </ul>


  \todo First-order theory of the reals
  <ul>
   <li> Are there implementations of the decision procedure for this theory
   in computer-algebra systems? </li>
   <li> See "First-order theory of the reals" in
   Buildsystem/ExternalSources/SpecialBuilds/plans/ATP.hpp. </li>
   <li> Perhaps this topic should go to ComputerAlgebra/FirstOrderStructures
   ? </li>
   <li> But ATP seems alright, since here theorems are proved automatically
   (though not with general logical methods, but with specialised algorithms
   --- but that should also belong to here). </li>
   <li> In [A decision procedure for probability calculus with applications;
   Fitelson, 2008. The review of symbolic logic] an interesting application
   is discussed (only with a mathematica-program, but perhaps it's not too
   hard to learn from that). </li>
  </ul>
  
*/

