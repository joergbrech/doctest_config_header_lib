#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "doctest/doctest.h"

#include "src/foo.h"

DOCTEST_SYMBOL_EXPORT void default_cpp_force_link() {}
