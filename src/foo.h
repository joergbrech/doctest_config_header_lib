#pragma once
#include "doctest/doctest.h"
#include <type_traits>

#ifdef RETURN_42
#define TEST_LABEL "[return42] "
#else
#define TEST_LABEL "[default] "
#endif

double bar() {
#ifdef RETURN_42
    return 42;
#else
    return 11;
#endif
}

#if defined(DOCTEST_LIBRARY_INCLUDED) && defined(RETURN_42)
TEST_CASE(TEST_LABEL "bartest"){
    INFO("Running " TEST_LABEL "bartest"); MESSAGE("");
    CHECK_EQ(42, bar());
}
#endif

#if defined(DOCTEST_LIBRARY_INCLUDED) && !defined(RETURN_42)
TEST_CASE(TEST_LABEL "bartest"){
    INFO("Running " TEST_LABEL "bartest"); MESSAGE("");
    CHECK_EQ(11, bar());
}
#endif

#ifdef DOCTEST_LIBRARY_INCLUDED
TEST_CASE(TEST_LABEL "commontest"){
    INFO("Running " TEST_LABEL "commontest");MESSAGE("");
    auto x = bar();
    CHECK(std::is_same<decltype(x), double>::value);
}
#endif
