// Oliver Kullmann, 10.4.2009 (Swansea)
/* Copyright 2009 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/RamseyTheory/VanderWaerdenProblems/plans/VanderWaerden_2-4-k.hpp
  \brief On investigations into vdW-numbers vdw_2(4,k)
  
  
  \todo Literature overview
  <ul>
   <li> Apparently nothing is known about vdw_2(4,k) ? Could there also be
   a conjecture that it's polynomially bounded? </li>
   <li> The known values:
   \verbatim
create_list(vanderwaerden4k(k),k,1,9);
 [4,7,18,35,55,73,109,146,unknown]
   \endverbatim
   </li>
  </ul>


  \todo Performance of OKsolver-2002
  <ul>
   <li> </li>
  </ul>


  \todo Performance of march_pl


  \todo Performance of minisat2


  \todo Local search for the satisfiable instances
  <ul>
   <li> </li>
  </ul>


  \todo vanderwaerden_2(4,9)
  <ul>
   <li> [Ahmed 2009] states vanderwaerden4k(9) > 254. </li>
  </ul>

*/

