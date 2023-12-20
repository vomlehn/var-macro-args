#include <stdio.h>

#ifndef _VAR_MACRO_ARGS_H_
#define _VAR_MACRO_ARGS_H_
/*
 * These macros are the user APIs. You must define the macro PROCESS_ARG to
 * perform some function on each argument
 *
 *      #define PROCESS_ARG(arg)   printf("%d\n", arg);
 *
 * From zero to ten arguments are supported; the error message you get if
 * you supply more may vary.
 *
 * You can count the number of arguments with:
 *
 *      int n;
 *      n = ARG_COUNT(a, b, c);
 *      printf("%d arguments\n", n);
 *
 * which will print "3".
 */

    
#define __GET_10TH_ARG(dummy, \
    _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) _10
#define ARG_COUNT(...) __GET_10TH_ARG(dummy, ##__VA_ARGS__, \
    10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

/*
 * The default separator is a comma, which can't be specified as a separator
 * because commas are used to separate macro arguments, which prevents using
 * them as arguments.
 */
#define __PROC_ARGS_IMPL(count, ...) __PROC_ARG##count(__VA_ARGS__)
#define __PROC_COUNTED_ARGS(count, ...) \
    __PROC_ARGS_IMPL(count, __VA_ARGS__)
#define PROCESS_ARGS(...) \
    __PROC_COUNTED_ARGS(ARG_COUNT(__VA_ARGS__), __VA_ARGS__)

#define __PROC_ARG0()
#define __PROC_ARG1(arg, ...) PROCESS_ARG(arg)
#define __PROC_ARG2(arg, ...) PROCESS_ARG(arg) , __PROC_ARG1(__VA_ARGS__)
#define __PROC_ARG3(arg, ...) PROCESS_ARG(arg) , __PROC_ARG2(__VA_ARGS__)
#define __PROC_ARG4(arg, ...) PROCESS_ARG(arg) , __PROC_ARG3(__VA_ARGS__)
#define __PROC_ARG5(arg, ...) PROCESS_ARG(arg) , __PROC_ARG4(__VA_ARGS__)
#define __PROC_ARG6(arg, ...) PROCESS_ARG(arg) , __PROC_ARG5(__VA_ARGS__)
#define __PROC_ARG7(arg, ...) PROCESS_ARG(arg) , __PROC_ARG6(__VA_ARGS__)
#define __PROC_ARG8(arg, ...) PROCESS_ARG(arg) , __PROC_ARG7(__VA_ARGS__)
#define __PROC_ARG9(arg, ...) PROCESS_ARG(arg) , __PROC_ARG8(__VA_ARGS__)
#define __PROC_ARG10(arg, ...) PROCESS_ARG(arg) , __PROC_ARG9(__VA_ARGS__)

/*
 * This handles all separators except for commas. Commas are a special
 * case because they separate macro arguments, and so can't be used as
 * arguments.
 */
#define __PROC_SEP_ARGS_IMPL(sep, count, ...) \
    __PROC_SEP_ARG##count(sep, __VA_ARGS__)
#define __PROC_SEP_COUNTED_ARGS(sep, count, ...) \
    __PROC_SEP_ARGS_IMPL(sep, count, __VA_ARGS__)
#define PROCESS_SEP_ARGS(sep, ...) \
    __PROC_SEP_COUNTED_ARGS(sep, ARG_COUNT(__VA_ARGS__), __VA_ARGS__)

#define __PROC_SEP_ARG0()
#define __PROC_SEP_ARG1(sep, arg, ...) PROCESS_SEP_ARG(sep, arg)
#define __PROC_SEP_ARG2(sep, arg, ...) PROCESS_SEP_ARG(sep, arg) sep \
                                        __PROC_SEP_ARG1(sep, __VA_ARGS__)
#define __PROC_SEP_ARG3(sep, arg, ...) PROCESS_SEP_ARG(sep, arg) sep \
                                        __PROC_SEP_ARG2(sep, __VA_ARGS__)
#define __PROC_SEP_ARG4(sep, arg, ...) PROCESS_SEP_ARG(sep, arg) sep \
                                        __PROC_SEP_ARG3(sep, __VA_ARGS__)
#define __PROC_SEP_ARG5(sep, arg, ...) PROCESS_SEP_ARG(sep, arg) sep \
                                        __PROC_SEP_ARG3(sep, __VA_ARGS__)
#define __PROC_SEP_ARG6(sep, arg, ...) PROCESS_SEP_ARG(sep, arg) sep \
                                        __PROC_SEP_ARG5(sep, __VA_ARGS__)
#define __PROC_SEP_ARG7(sep, arg, ...) PROCESS_SEP_ARG(sep, arg) sep \
                                        __PROC_SEP_ARG6(sep, __VA_ARGS__)
#define __PROC_SEP_ARG8(sep, arg, ...) PROCESS_SEP_ARG(sep, arg) sep \
                                        __PROC_SEP_ARG7(sep, __VA_ARGS__)
#define __PROC_SEP_ARG9(sep, arg, ...) PROCESS_SEP_ARG(sep, arg) sep \
                                        __PROC_SEP_ARG8(sep, __VA_ARGS__)
#define __PROC_SEP_ARG10(sep, arg, ...) PROCESS_SEP_ARG(sep, arg) sep \
                                        __PROC_SEP_ARG9(sep, __VA_ARGS__)
#endif /* _VAR_MACRO_ARGS_H_ */
