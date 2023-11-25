#include "debugger_symbol_problem.hpp"

void A::func() {
    aa.insert({"1", "1"});
    aa.insert({"2", "2"});
    aa.size();  // make a symbol for debugger to call
}