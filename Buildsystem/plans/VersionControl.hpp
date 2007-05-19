// Oliver Kullmann, 10.4.2007 (Swansea)

/*!
  \file Buildsystem/plans/VersionControl.hpp
  \brief Plans for the versioning control system

  \todo Building and using Git
  <ul>
   <li> Created now also for Transitional a shared Git-repository. </li>
   <li> DONE In order that commits have the full name ("Oliver Kullmann" instead of "csoliver") and e-mail-address
   ("O.Kullmann@Swansea.ac.uk" instead of "csoliver@cs-wsok.swan.ac.uk"), easiest is to tell Git for all
   repositories of the user (that is, in  ~/.gitconfig instead of .git/config) about it via
   \verbatim
> git config --global user.name "Oliver Kullmann"
> git config --global user.email O.Kullmann@Swansea.ac.uk
   \endverbatim
   </li>
   <li> DONE The creation of the initial Annotations-respository was done via
   \verbatim
su csoksc
cd /work/Repositories/Git/Annotations
git cvsimport -d /work/Repositories/OKdevelopment/  -v -A /work/Repositories/Git/e-mail_addresses Annotations
   \endverbatim
   Then the shared repository has been set up via (as explained in "git for CVS users")
   \verbatim
su csoksc
cd /work/Repositories/Git/bare
mkdir Annotations
cd Annotations
git --bare init --shared
bit --bare fetch /work/Repositories/Git/Annotations master:master
   \endverbatim
   Now every user has to create his master clone himself, via for example
   \verbatim
csoliver@cs-wsok:~/LaptopArchiv/OKsystem> git clone cs-oksvr:/work/Repositories/Git/bare/Annotations
   \endverbatim
   that is, go to the directory where you want to place the master-close, and issue the git-clone-command.
   Updating the master-clone happens simply via "git pull", submitting changes via "git push".
   However, <strong>before submission</strong> everything in the master-clone needs to be completely up-to-date and tested!!
   </li>
   <li>  DONE Creating a local copy of the master-clone simply via
   \verbatim
git clone PATH-TO-EXISTING-CLONE
   \endverbatim
   which will create the clone in the current directory. Then the following actions are possible:
   <ol>
    <li> Updating the subclone via "git pull" in the sub-clone. </li>
    <li> Updating the masterclone either via "git pull PATH-TO-SUB-CLONE" in the masterclone,
    or via "git push" in the sub-clone, followed by "git checkout -f" in the master-clone. </li>
   </ol>
   </li>
   <li> Is there html-documentation? DONE (documentation-links seem to be fine (and all what is available)) </li>
   <li> DONE Problems with cvsimport:
   \verbatim
csoksc@cs-oksvr:/work/Repositories/Git/Annotations> git cvsimport -d /work/Repositories/OKdevelopment/ \
-C /work/Repositories/Git/Annotations -a -v -A ../e-mail_addresses Annotations
   \endverbatim
   resulted in
   \verbatim
Done.
DONE; creating master branch
D       200511_UniformHittingClauseSets.tex
D       200512_Alldifferent.tex
D       200512_OKlibrary.tex
D       200512_OKlibrary_Annotations
D       BuchOKsystems.tex
D       FullDocumentation.tex
D       History_OKsystem
D       Latex_bib/C++_Books.bib
D       Latex_bib/Constraints.bib
D       Latex_bib/EigArt.bib
D       Latex_bib/MiscSAT.bib
D       Latex_macros/Basis.tex
D       Latex_macros/Definitionen.tex
D       Latex_macros/FolienDefN.tex
D       Latex_macros/OKplatform_Texpackages.tex
D       Release-1_0
D       definitions.mak
   \endverbatim
   What's the point in deleting all the files you just wanted to import?? Okay,
   \verbatim
git checkout -f
   \endverbatim
   is needed after the import (the "D" just means the files are not there, i.e.,
   supposedly have been deleted).
   </li>
   <li> On csltok asciidoc is not available --- what about cs-wsok? DONE (supplied a build-makefile) </li>
   <li> Perhaps we should just use the default Git-installation into
   the users bin-directory (otherwise it seems hard to use because of
   the many different commands). It should also be possible to do the
   system-wide installion (in /usr/local). DONE (for now just the system-wide installation) </li>
  </ul>

  \todo New version control system
  <ul>
   <li> How to send notification-e-mails with Git: In the shared repository the file
   "hooks/post-receive" has to be made executable, and then filled with action; temporary
   solution (for Annotations):
   \verbatim
mutt -s "OKlibrary::Annotations Git Push -- $USER" O.Kullmann@Swansea.ac.uk m.j.henderson@swansea.ac.uk csmatthewl@swan.ac.uk
   \endverbatim
   Apparently to the script "post-receive" per branch a line with reference-data is passed on stdin,
   while stdin is passed onto mutt which then sends these lines in the body. A more sophisticated
   solution is given in in the Git-repository under "contrib/hooks/post-receive-email" (see also
   the text in "hooks/post-receive"), which we should examine (it seems we should also set up
   an OKlibrary-e-mail-list ?!).
   </li>
   <li> Git can handle symbolic links, so all symbolic links should go
   into the respository? On the other hand, this seems to imply one universal
   convention like "/h/21/GemeinsameBasis", which perhaps one better should avoid?!?
   </li>
   <li> What about version numbers in Git? What is the
   version-numbering-systems there, and what kind of statistics
   are supported? </li>
   <li> How to handle change dates and revision numbers in files with Git?
   </li>
   <li> The central repository:
   For a new version control system we have to find out how to establish the role of the repository at
   cs-oksvr as *central*, and how to manage access control (as fine-grained as possible; if possible not
   relying on ssh). </li>
   <li> Models of behaviour for distributed version control:
   Find out how to do the following:
    <ul>
     <li> We have the central repository R and a local repository L. L is changed (with commits, logs
     and everything) to L', while meanwhile R has been changed to R'. Now it should not be possible to
     submit L' to R', since L' is not up-to-date; so first all changes in R' have to be committed to
     L', yielding L'' (without changing R'), and then L'' is submitted to R', yielding R''. </li>
     <li> For the (off-line) laptop csltok: Can we just copy the local repository to disc, then copy this
     to cs-wsok, synchronise it with the local repository on cs-wsok, run the tests, and then submit the
     local repository on cs-wsok to the central repository? Should be no problem. DONE (yes, that's possible)</li>
    </ul>
   </li>
   <li> Branching:
    <ul>
     <li> Yet we never branched; in [{CVU}, vo. 10, no. 2, page 34] it
     is recommended (for Bazaar), that every work on a file (or
     perhaps better on a module?) starts by creating a branch,
     and that (only) after a review the branches are merged into
     the main branch. </li>
     <li> This sounds reasonable; perhaps
     a problem would be, that the review manager (OK) would
     not always be available (and it would also cost him additional
     work). </li>
    </ul>
   </li>
   <li> External sources:
    <ul>
     <li> Optimally, the OKlibrary-package is exactly a clone of the repository (and then one needs to
     run "make" in the top-level directory).
      <ul>
       <li> For this also ExternalSources needs to be in the version control. </li>
       <li> And there needs to be a way to specify "sub-repositories" to separate the public parts
       of the library from the non-public parts. </li>
      </ul>
     </li>
     <li> If we cannot do this, then at least ExternalSources needs to be under version control on its own. </li>
    </ul>
   <li> The different parts in OKplatform:
    <ul>
     <li> As already mentioned in the point "External sources", optimally there is just one repository
     for the whole library (containing the current three repositories Annotations, OKlibrary, Transitional,
     and the new (sub-)repositories ExternalSources and Overview). Then we need the possibility to restrict
     access to parts of the repository (so that annotations and Transitional are not public). </li>
     <li> A problem is, that Annotations currently has public as well as non-public parts; likely this needs to be
     separated. </li>
    </ul>
   </li>
   <li> A distributed version control system as integral part of the library:
    <ul>
     <li> The version control system is built by the library (ExternalSources). </li>
     <li> One has to reflect on how an (external) user of the library might want to
     extend the library (under the version control!). </li>
     <li> Hopefully the distributed version control constitutes also the main part of the
     update-solution for an external user (who extended the library)! </li>
    </ul>
   </li>
   <li> Files to ignore can be entered to .git/info/exclude. DONE </li>
   </li>
   <li> We have a little problems with submissions to the repository, which often span
   many files, so the whole submission process takes a while, and it's not clear from
   outside when it's finished (and the library is again in a well-defined state). DONE (With Git first all submissions are done to a local clone, and only
   once this is all settled, the final push to central respository happens.)
   </li>
   <li> The main conceptual disadvantage (shared with CVS) of Subversion is that
    no local repositories are possible; alternatives: DONE (the three
    existing repositories will be copied over to Git).
    <ol>
     <li> Git (http://git.or.cz/) looks rather good --- one should try it out! </li>
     <li> Bazaar (http://bazaar-vcs.org) was recommended in [{CVU}, vo. 10, no. 2, page 34].
     <li> svk (http://svk.elixus.org), apparently a further development of Subversion.
     Looks somewhat immature. </li>
     <li> What about Arch? </li>
     <li> BitKeeper (http://www.bitkeeper.com) seems to be only proprietary. </li>
    </ol>
   </li>
  </ul>

*/

