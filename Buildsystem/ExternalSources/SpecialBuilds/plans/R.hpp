// Oliver Kullmann, 27.6.2007 (Swansea)
/* Copyright 2007, 2008, 2009, 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Buildsystem/ExternalSources/SpecialBuilds/plans/R.hpp
  \brief Plans regarding installation of R


  \todo Installing 2.12.1


  \todo Local installation of gfortran
  <ul>
   <li> Often gfortran is not installed. </li>
   <li> While it shouldn't be a problem to install gfortran locally.
    <ol>
     <li> DONE Just add "fortran" to gcc_enable_languages_okl. </li>
    </ol>
   </li>
   <li> And also employing it for building R shouldn't be a problem. </li>
  </ul>


  \bug Can't output graphics
  <ul>
   <li> For example
   \verbatim
> hist(c(1,2,3,2,1))
Fehler in title(main = main, sub = sub, xlab = xlab, ylab = ylab, ...) :
  X11 Schrift -adobe-helvetica-%s-%s-*-*-%d-*-*-*-*-*-*-*, Typ 2 in Größe 14 konnte nicht geladen werden
   \endverbatim
   on csltok. </li>
   <li> Perhaps this is language-related, or related to the rather old version
   (9.2) of Suse-Linux running on csltok (it works on cs-wsok). </li>
  </ul>


  \todo Packages
  <ul>
   <li> We should supply additional packages. </li>
   <li> DONE (target R_packages)
   And also install them automatically (with documentation). </li>
   <li> Apparently with "library(Rcmdr)" we can open a (useful) graphical user
   interface, and apparently for this package "Rcmdr" is needed.
    <ol>
     <li> On cs-wsok we get the error
     \verbatim
> library(Rcmdr)
Loading required package: tcltk
Error in firstlib(which.lib.loc, package) :
  Tcl/Tk support is not available on this system
Error: package 'tcltk' could not be loaded
     \endverbatim
     though apparently everything is installed? </li>
     <li> On csltok we get messages on startup of Rcmdr that further
     packages (rgl, relimp, multcomp, lmtest, effects, car, aplpack, abind)
     should be installed; we should do this. </li>
    </ol>
   </li>
   <li> Of potential interest:
    <ol>
     <li> "gsl" http://cran.r-project.org/web/packages/gsl/index.html
      <ol>
       <li> With this we would get the exponential integral (and thus also
       the logarithmic integral). </li>
       <li> Needs the Gnu Gsl-library installed. </li>
       <li> Likely we should do this locally. </li>
       <li> But then, how to tell the R-installation about this local
       library? </li>
       <li> Using "oklib --R CMD INSTALL --help" reveals no options for
       libraries needed by the packages? </li>
       <li> Perhaps the usual configure-options are to be used, together
       with "--configure-args=ARGS" and "--configure-vars=VARS" (but unclear
       what these CMD-options mean)? </li>
      </ol>
     </li>
     <li> "SparseM" </li>
     <li> DONE "QCA" (Quine-McCluskey;
     http://cran.r-project.org/web/packages/QCA/index.html) </li>
     <li> DONE "lpsolve"
     http://cran.r-project.org/web/packages/lpSolve/index.html </li>
     <li> DONE
     "QCA3" (qualitative comparative analysis;
     http://cran.r-project.org/web/packages/QCA3/index.html) </li>
     <li> "boolean" </li>
     <li> "combinat" </li>
     <li> diagram http://r-forge.r-project.org/R/?group_id=342 </li>
     <li> "dyn" </li>
     <li> "gafit" </li>
     <li> "glpk" </li>
     <li> "graph" http://www.bioconductor.org/packages/2.5/bioc/html/graph.html
     </li>
     <li> "igraph" http://igraph.sourceforge.net/ </li>
     <li> "linprog" </li>
     <li> "pspline" </li>
     <li> "quadprog" </li>
     <li> "randaes" </li>
     <li> "Rgraphviz"
     http://www.bioconductor.org/packages/2.5/bioc/html/Rgraphviz.html </li>
     <li> "sudoku" </li>
    </ol>
   </li>
   <li> There should be also packages for machine learning. </li>
  </ul>


  \todo Improving the docus-page
  <ul>
   <li> Prerequisites:
    <ol>
     <li> What precisely is needed from the gcc-suite? </li>
     <li> What is mpfr? We should also add installation-help
     (there is already some installation-make-code). </li>
    </ol>
   </li>
  </ul>


  \todo Building dvi,pdf,info-documentation
  <ul>
   <li> On csltok "make dvi" fails --- is this due to old
   tex-tools? </li>
   <li> Likely "make pdf" sits on top of dvi. </li>
   <li> What can we do with the info-documentation? </li>
   <li> How do we get documentation on the packages? </li>
  </ul>

*/

