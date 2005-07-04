// Oliver Kullmann, 25.5.2005 (Swansea)

/*!
  \file LibraryBasics_Tests.hpp
  \brief Tools for testing concept definitions (and related constructions).
*/

#ifndef LIBRARYBASICSTESTS_rttjkN00

#define LIBRARYBASICSTESTS_rttjkN00

#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>
// This file is guaranteed to include the last two files, so that OKLIB_BASIC_CONCEPT_TEST always works.

#include "ConceptsMetafunctions.hpp"

namespace OKlib {

  namespace Concepts {

    /*!
      \namespace OKlib::Concepts::ConceptTests
      \brief Contains macros for testing concept definitions (and related constructions).
    */

    namespace ConceptTests {

      /*!
        \define OKLIB_BASIC_CONCEPT_TEST_TAG(concept)
        \brief Tests, whether with concept a concept tag is associated.
      */

#define OKLIB_BASIC_CONCEPT_TEST_TAG(concept) BOOST_STATIC_ASSERT(IsConceptTag< concept ## _tag >::value);

      /*!
        \define OKLIB_BASIC_CONCEPT_TEST_ARCHETYPE(concept)
        \brief Tests, whether with concept an archetype is associated which fulfills the concept.
      */

#define OKLIB_BASIC_CONCEPT_TEST_ARCHETYPE(concept) template class concept< concept ## _Archetype >;

    }

  }

}

#endif
