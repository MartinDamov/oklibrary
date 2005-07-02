// Oliver Kullmann, 8.5.2005 (Swansea)

#ifndef TESTEXCEPTIONS_QwAq190

#define TESTEXCEPTIONS_QwAq190

#include <stdexcept>
#include <vector>
#include <string>
#include <ostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <set>
#include <ostream>
#include <list>
#include <deque>
#include <map>

#include <boost/range/functions.hpp>

namespace OKlib {

  namespace TestSystem {

    typedef unsigned int LineNumber;

    class ErrorDescription {
      const char* file;
      const char* line;
      const char* type_test_class;
    public :
      ErrorDescription() : file(0), line(0), type_test_class(0) {}
      ErrorDescription(const char* const file, const char* const line, const char* const type_test_class) : file(file), line(line), type_test_class(type_test_class) {}
      friend std::ostream& operator <<(std::ostream& out, const ErrorDescription& D) {
        return out << D.file << ": " << D.line << "\n" << D.type_test_class << "\n";
        // ToDo: Adding messages (using module Messages)
      }
    };

    typedef std::vector<ErrorDescription> ErrorContainer;
    // Assumes, that the destructor of std::vector does not throw exceptions.
    // ----------------------------------------------------------------------------------------------

    class TestException : public std::runtime_error {
      
      ErrorContainer errors;

    public :

      explicit TestException(const std::string& special_circumstances) :  std::runtime_error(special_circumstances) {}
      ~TestException() throw() {}

      TestException& add(const ErrorDescription e) {
        errors.push_back(e);
        return *this;
      }

      friend std::ostream& operator <<(std::ostream& out, const TestException& E) {
        out << __DATE__ ", " __TIME__ "\n";
        out << E.what() << "\n";
        std::copy(E.errors.begin(), E.errors.end(), std::ostream_iterator<ErrorDescription>(out, "\n"));
        return out;
      }
    };

# define OKLIB_LINENUMBER(L) # L
# define OKLIB_INTERMEDIATE_TEST(X) OKLIB_LINENUMBER(X)
#define OKLIB_TESTDESCRIPTION (::OKlib::TestSystem::ErrorDescription(__FILE__, OKLIB_INTERMEDIATE_TEST(__LINE__), typeid(test_type).name()))

#define OKLIB_THROW(string) throw ::OKlib::TestSystem::TestException(string).add(OKLIB_TESTDESCRIPTION);

#define OKLIB_TEST_EQUAL(v1, v2) \
    if ( not(v1 == v2)) { \
      std::stringstream out; \
      out << "Value is " << v1 << ", and not " << v2; \
      OKLIB_THROW(out.str()); \
    }

#define OKLIB_TEST_NOTEQUAL(v1, v2) \
    if ( v1 == v2) { \
      OKLIB_THROW("Equal values"); \
    }

#define OKLIB_TEST_EQUAL_RANGES(c1, c2) { \
      using boost::begin; \
      using boost::end; \
      using boost::size; \
      if (size(c1) != size(c2)) { \
        std::stringstream out; \
        out << "Size is " << size(c1) << ", and not " << size(c2); \
        OKLIB_THROW(out.str()); \
      } \
      else if (not std::equal(begin(c1), end(c1), begin(c2))) \
        OKLIB_THROW("Containers have different content"); \
    }

#define OKLIB_TESTTRIVIAL_RETHROW(Testobject) \
    try { \
      (Testobject).perform_test(); \
    } \
    catch(::OKlib::TestSystem::TestException& e) { \
      e.add(OKLIB_TESTDESCRIPTION); \
      throw e; \
    }

    template <typename T>
    struct OutputWrapper {
      const T& t;
      OutputWrapper(const T& t) : t(t) {}
    };
    template <typename T>
    inline OutputWrapper<T> output_wrapper(const T& t) {
      return OutputWrapper<T>(t);
    }
    template <typename T>
    std::ostream& operator <<(std::ostream& out, const OutputWrapper<T>& w) {
      std::copy(w.t.begin(), w.t.end(), std::ostream_iterator<typename T::value_type>(out, ","));
      return out;
    }
    template <typename T>
    struct OutputWrapper2 {
      const T& t;
      OutputWrapper2(const T& t) : t(t) {}
    };
    template <typename T>
    inline OutputWrapper2<T> output_wrapper2(const T& t) {
      return OutputWrapper2<T>(t);
    }
    template <typename T>
    std::ostream& operator <<(std::ostream& out, const OutputWrapper2<T>& w) {
      std::copy(w.t.begin(), w.t.end(), std::ostream_iterator<OutputWrapper<typename T::value_type> >(out, "\n"));
      return out;
    }

    // ToDo: Should this go to a general output facilities module?

#define OKLIB_TEST_EQUAL_W(v1, v2) \
    if ( not(v1 == v2)) { \
      std::stringstream out; \
      out << "Value is " << ::OKlib::TestSystem::output_wrapper(v1); \
      out << ", and not " << ::OKlib::TestSystem::output_wrapper(v2); \
      OKLIB_THROW(out.str()); \
    }
#define OKLIB_TEST_EQUAL_W2(v1, v2) \
    if ( not(v1 == v2)) { \
      std::stringstream out; \
      out << "Value is " << ::OKlib::TestSystem::output_wrapper2(v1); \
      out << ", and not " << ::OKlib::TestSystem::output_wrapper2(v2); \
      OKLIB_THROW(out.str()); \
    }

  }

}

#endif
