/**
 * \file foo.cpp
 * \brief Implementation de foo.hpp
 */
#include "foo.hpp"

Foo::Foo()
    : bar(5)
{
    std::cout << "bar: " << bar << std::endl;
}
