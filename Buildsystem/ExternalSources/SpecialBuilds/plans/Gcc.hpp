// Oliver Kullmann, 27.6.2007 (Swansea)
/* Copyright 2007, 2008, 2010 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Buildsystem/ExternalSources/SpecialBuilds/plans/Gcc.hpp
  \brief Plans regarding installation of gcc


  \todo GCC 4.1.2 will not build on systems without GMP with MPFR support
  <ul>
   <li> GCC 4.1.2 fails to build on some machines (notably the Swansea 
   University Computer Science Linux lab machines), with the following error:
   \verbatim
checking whether the C compiler (gcc  ) is a cross-compiler... no
checking whether we are using GNU C... yes
checking whether gcc accepts -g... yes
checking for gnatbind... gnatbind
checking whether compiler driver understands Ada... no
checking how to compare bootstrapped objects... cmp --ignore-initial=16 $$f1 $$f2
checking for correct version of gmp.h... yes
checking for MPFR... no
configure: error: GMP with MPFR support is required to build fortran
make: *** [gcc] Error 1
make: Leaving directory `/tmp/OKlib/OKplatform/ExternalSources'
   \endverbatim
   </li>
   <li> Ideally we could just build GMP and MPFR as part of the OKlibrary
   build process, however, these libraries would then build using a newer
   version of GCC and we run the risk of there being incompatibilities
   with the version we are building when we start to compile anything in
   the library which might somehow link to standard libraries. </li>
   <li> The GCC website (http://gcc.gnu.org/install/prerequisites.html) 
   suggests it should be possible to simply drop GMP and MPFR source
   directories in the GCC source directory and build as normal :
   \verbatim
GNU Multiple Precision Library (GMP) version 4.3.2 (or later)
    Necessary to build GCC. If you do not have it installed in your library search path, you will have to configure with the --with-gmp configure option. See also --with-gmp-lib and --with-gmp-include. Alternatively, if a GMP source distribution is found in a subdirectory of your GCC sources named gmp, it will be built together with GCC.
MPFR Library version 2.4.2 (or later)
    Necessary to build GCC. It can be downloaded from http://www.mpfr.org/. The --with-mpfr configure option should be used if your MPFR Library is not installed in your default library search path. See also --with-mpfr-lib and --with-mpfr-include. Alternatively, if a MPFR source distribution is found in a subdirectory of your GCC sources named mpfr, it will be built together with GCC. 
   \endverbatim
   </li>
   <li> However, building GCC with GMP and MPFR source directories "in-tree"
   (as such a method is called) with GCC 4.1.2 doesn't work yielding the same 
   error. </li>
   <li> Either additional configure options are needed, or GCC 4.1.2 doesn't
   support this. Perhaps such functionality has only been introduced in later
   GCC versions?
   </li>
  </ul>


  \todo Providing gcc 4.1.2
  <ul>
   <li> Motivated by "GRASP cannot be compiled with gcc version 4.3" (see
   Buildsystem/ExternalSources/SpecialBuilds/plans/SAT.hpp), we should provide
   a permanent installation of version 4.1.2. </li>
   <li> Perhaps we should provide in general build-variables supporting
   usage of gcc (i.e., calling the compiler, and providing the instructions
   for fixing the shared libraries in the binaries. </li>
   <li> Gcc 4.1.2 will not link on some 64 bit systems
    <ul>
     <li> Gcc 4.1.2 assumes that 32 bit libraries are stored
     in /usr/lib /lib etc rather than /usr/lib32 /lib32 etc. </li>
     <li> This is the case for most linux systems following the
     LSB (Linux Standard Base) conventions however debian-based
     distributions use the later convention. This results
     in the linker not finding the libraries during the building
     of gcc. </li>
     <li> This has been fixed in later versions of gcc, and there
     is a patch available (MG: The patch works for me). </li>
     <li> See http://www.trevorpounds.com/blog/?tag=ubuntu for
     details and a link to the patch. </li>
     <li> Of course, the question is whether this patch is really a general
     improvement, and whether it creates problems with other systems? </li>
     <li> Those who are interested in this patch need to test it on other
     systems. </li>
     <li> And precise information on how to perform the improvements are
     needed (note that we are using already an altered gcc!). </li>
    </ul>
   </li>
  </ul>


  \todo Install GCC 4.2.4
  <ul>
   <li> First only as an alternative (since yet code doesn't compile with
   versions 4.2 or later). </li>
   <li> It seems best to proceed in stages, first installing 4.2.4 and
   updating our code, then installing 4.3.5, and then 4.4.4. </li>
  </ul>


  \todo Install GCC 4.3.5


  \todo Install GCC 4.4.4
  <ul>
   <li> Building 4.4.4:
    <ol>
     <li> Now Gmp and Mpfr is needed. </li>
     <li> For Gmp just use the configure-option
     "--with-gmp=$(gmp_installation_dir_okl)". </li>
     <li> However, then we have the problem of a circular dependency, since
     these libraries are built using Gcc! </li>
     <li> The main question is about the link-library-compatabilities. </li>
    </ol>
   </li>
  </ul>


  \todo Install GCC 4.5.1
  

  \todo Installation in general
  <ul>
   <li> Documentation:
    <ol>
     <li> Linking to the gcc-documentation (main info-page) should be checked
     for completeness. </li>
     <li> We could offer also to show the man-page (just open it into a
     browser); however then it should be said that likely the
     html-documentation is more complete. </li>
     <li> We should also move the info-pages to the doc-directory. How to view
     them? The least is just to open them into a browser. </li>
    </ol>
   </li>
   <li> DONE (not used anymore)
   If variable "gcc_version_okl" is set, then it should have one of the
   allowed values (while otherwise we get an error). </li>
   <li> We must understand, how gcc interacts with 32- and 64-bit
   environments, and how to take control of this. </li>
   <li> There should be make-variables, which allow control over
   some settings for the build of gcc. </li>
   <li> texti2pdf is a script, which can be put into ~/bin for example,
   and is needed for building the gcc-documentation --- how to provide it?
   Such small utilities could be put under version control (OKlibrary) ? </li>
   <li> Installation of R requires a Fortran compiler. Therefore the 
    system-installation of Gcc should allow for enabling of Fortran
    language support. </li>
   <li> DONE (yes, GMP and MPFR are installed locally)
   Enabling Fortran language support in Gcc requires that the MPFR
    and GMP libraries are installed. Should we install these also locally?
    <ol>
     <li> GMP is also of interest to us regarding big-number-types, so we need
     full control about it, and perhaps a local installation is warranted
     (ignoring the system installation). UPDATE NEEDED </li>
    </ol>
   </li>
   <li> DONE (placed in Buildsystem/Configuration)
   Shouldn't file external_sources_versions.mak be placed in subdirectory
   Buildsystem/ExternalSources ? </li>
   <li> DONE (it seems reasonable
   to remove the build-directory from the prerequisite-list and to build it
   "manually")
   If the filestamp does already exist, then we want nothing to happen ---
   however yet the build-directory will be rebuilt if not existent, since
   it is a prerequisite of the rule for the "tag-paths". So it seems
   necessary to remove the build-directory from the prerequisite-list,
   however then it seems impossible to create the build-directory, if actually
   gcc *is* to be build, via the target-mechanism. </li>
   <li> DONE (now just "oklib gcc", and potentially setting 
  gcc_recommended_version_number_okl)
   Instead of, %e.g., "make gcc-4.1.2", wouldn't it be more consistent with
   building Boost to also have "make gcc gcc-version=4.1.2" ? </li>
  </ul>


  \todo DONE
  Update our gcc-installation-system to the new standard
  <ul>
   <li> OK: was this done? has this to do with "stubs-32.h not found"?
   As only extension, we install the patch for 4.1.2 as provided
   by MG. </li>
   <li> Regarding this "stubs-32.h"-nonsense (the internet is full
   of noise regarding that, but nobody has a clue): perhaps glibc
   has to be installed (the development library) --- more precisely,
   for a 64-bit machine also the glibc-32-bit version! </li>
   <li> DONE
   Likely it's best for now only to support local installation. </li>
   <li> DONE
   As it is standard now, existing documentation is always overwritten.
   </li>
   <li> DONE
   A problem is how to handle these two lists for the two installation
   modes.
    <ol>
     <li> We need to extend the usual "iseq"-macro. </li>
     <li> Use
     \verbatim
ifneq ($(findstring $(gcc_recommended_version_number_okl), $(gcc_old_installation_okl)),)
     \endverbatim
     to test whether the version to be installed is an old installation. </li>
    </ol>
   </li>
   <li> DONE
   Another problem is the target "gcc_all":
    <ol>
     <li> In this way all support versions of gcc are installed. </li>
     <li> In the new model, where always (only) the "recommended version" is
     installed, this needs several calls of make (from oklib). </li>
     <li> So well, seems alright to me. </li>
    </ol>
   </li>
   <li> DONE
   The current installation creates timestamps: Shall we take over
   this, or shall we first drop it?
    <ol>
     <li> Doesn't seem to be a big problem to keep it. </li>
     <li> On the other hand, is it really useful? </li>
     <li> It might create trouble, and for all recent installations
     it was not done (forgotten; but likely also not needed?). </li>
     <li> So we drop it (at least for now). </li>
    </ol>
   </li>
   <li> DONE
   We should introduce make-variables for the configuration options. </li>
  </ul>

*/
