SHELL = /bin/sh
.SUFFIXES :

####################################################

ifndef OKplatform
  ifdef OKPLATFORM
    OKplatform := $(OKPLATFORM)
  else
    $(error Either OKplatform (a make-variable) or OKPLATFORM (an environment-variable) must be defined when calling this makefile!)
  endif
endif

ifndef OKSystem
  ifdef OKSYSTEM
    OKSystem := $(OKSYSTEM)
  else
    OKSystem := $(OKplatform)/OKsystem
  endif
endif

ifndef OKBuildsystem
  ifdef OKBUILDSYSTEM
    OKBuildsystem := $(OKBUILDSYSTEM)
  else
    OKBuildsystem := $(OKSystem)/Transitional/Buildsystem
  endif
endif

prefix := $(shell pwd)

# #################################
# Functions
# #################################

define postcondition 
if [ $$? != 0 ]; then exit 1; fi;
endef

define unarchive
if [ -f $(1).tar.gz ]; then tar --extract --directory=$(2) --file=$(1).tar.gz --ungzip; elif [ -f $(1).tar.bz2 ]; then tar --extract --directory=$(2) --file=$(1).tar.bz2 --bzip2; else exit 1; fi;
endef

# #################################
# Main targets
# #################################

.PHONY : all clean cleanall

all : gcc boost postgresql valgrind mhash doxygen


# #################################
# Includes
# #################################

include $(OKBuildsystem)/external_sources_versions.mak
include $(OKBuildsystem)/ExternalSources/mhash.mak
include $(OKBuildsystem)/ExternalSources/gcc.mak
include $(OKBuildsystem)/ExternalSources/doxygen.mak
include $(OKBuildsystem)/ExternalSources/boost.mak
include $(OKBuildsystem)/ExternalSources/postgresql.mak
include $(OKBuildsystem)/ExternalSources/valgrind.mak
include $(OKBuildsystem)/ExternalSources/ubcsat.mak

# #################################
# Cleaning
# #################################

clean : cleangcc cleanmhash cleanboost

cleanall : clean cleanallgcc cleanallmhash cleanallboost cleanalldoxygen cleanallpostgresql cleanallvalgrind
