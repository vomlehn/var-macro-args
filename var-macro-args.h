#include <stdio.h>

#define GET_10TH_ARG(dummy, \
    _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) _10
#define COUNT_ARGS(...) GET_10TH_ARG(dummy, ##__VA_ARGS__, \
    10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define PROCESS_ARGS_IMPL(count, ...) PROCESS_ARGS_##count(__VA_ARGS__)
#define PROCESS_ARGS(count, ...) PROCESS_ARGS_IMPL(count, __VA_ARGS__)

#define PROCESS_ARGS_0()
#define PROCESS_ARGS_1(arg1) printf("Processing arg1: %d\n", arg1);
#define PROCESS_ARGS_2(arg1, arg2) printf("Processing arg1: %d\n", arg1); printf("Processing arg2: %d\n", arg2);
// Add more macros for higher counts if needed
