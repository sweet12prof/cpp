#include <bClass.hpp>

A::A( A& bClassArg)
:intPtr{std::make_unique<A>(&(*(bClassArg.intPtr)))}{}
