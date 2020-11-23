#include "doctest/doctest.h"

#define RETURN_42
#include "src/foo.h"

DOCTEST_SYMBOL_EXPORT void return42_cpp_force_link() {}
