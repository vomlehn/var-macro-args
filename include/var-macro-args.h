#include <stdio.h>

#ifndef _VAR_MACRO_ARGS_H_
#define _VAR_MACRO_ARGS_H_
/*
 * These macros are the user APIs for processing argument lists with
 * macros. Unlike using stdarg.h, these can be used to produce various
 * constructs such as, totaling the values from a list of arguments,
 * building code to initiailze buffers with a variable number of fields,
 * etc.
 *
 * ARG_COUNT        This is given a list of items and it produces a value
 *                  which is the number of items in the list
 *
 * PROCESS_ARGS     Given a list of arguments, it will process them with a
 *                  macro and separate each item with a comma. The macro
 *                  is something the user will write and takes a single
 *                  argument. The argument is one of the list of arguments.
 *                  Given the macro defined as:
 *
 *                      #define MY_MACRO(arg)   arg
 *
 *                  the output will be the argument list, separated by
 *                  commas.
 *
 *                  Not only is it nice to have a short name for a very
 *                  common case, but it's not possible to use
 *                  PROCESS_SEP_ARGS with a comma as the specified
 *                  separator. This is because the preprocessor uses
 *                  commas to separate arguments, meaning a comma cannot
 *                  be an argument. 
 *
 * PROCESS_SEP_ARGS Similar to PROCESS_ARGS except that the separator
 *                  between the arguments specified as an argument to the
 *                  macro. The macro defined by the user and passed to this
 *                  macro takes two arguments. The separator is the first
 *                  argument and probably won't be used, the argument is
 *                  the second agument. The follow macro takes the argument
 *                  and turns it into an express with a value one greater
 *                  than that of the argument:
 *
 *                      #define ELEM(sep, arg) ((arg) + 2)
 *                      
 *                  Computing a sum of input value, plus one, can be done
 *                  in the following way:
 *
 *                      int sum;
 *                      sum = PROCESS_SEP_ARGS(ELEM, +, 1, 2, 3);
 *
 *                  The value of sum will be 1 + 3 + 4 = 8.
 *
 *                  With both PROCESS_ARGS and PROCESS_SEP_ARGS, it is
 *                  useful to define a second macro in addition to the one
 *                  passed to these macros, such as:
 *
 *                      #define SUM_LIST(...) \
 *                          PROCESS_SEP_ARGS(ELEM,+, __VA_ARGS__)
 * 
 *                  and use it as:
 *
 *                      sum = SUM_LIST(1, 2, 3);
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
#define __PROC_ARGS_IMPL(macro, count, ...) \
    __PROC_ARG##count(macro, __VA_ARGS__)
#define __PROC_COUNTED_ARGS(macro, count, ...) \
    __PROC_ARGS_IMPL(macro, count, __VA_ARGS__)
#define PROCESS_ARGS(macro, ...) \
    __PROC_COUNTED_ARGS(macro, ARG_COUNT(__VA_ARGS__), __VA_ARGS__)

#define __PROC_ARG0(macro, ...)
#define __PROC_ARG1(macro, arg, ...) macro(arg)
#define __PROC_ARG2(macro, arg, ...) macro(arg) , \
    __PROC_ARG1(macro, __VA_ARGS__)
#define __PROC_ARG3(macro, arg, ...) macro(arg) , \
    __PROC_ARG2(macro, __VA_ARGS__)
#define __PROC_ARG4(macro, arg, ...) macro(arg) , \
    __PROC_ARG3(macro, __VA_ARGS__)
#define __PROC_ARG5(macro, arg, ...) macro(arg) , \
    __PROC_ARG4(macro, __VA_ARGS__)
#define __PROC_ARG6(macro, arg, ...) macro(arg) , \
    __PROC_ARG5(macro, __VA_ARGS__)
#define __PROC_ARG7(macro, arg, ...) macro(arg) , \
    __PROC_ARG6(macro, __VA_ARGS__)
#define __PROC_ARG8(macro, arg, ...) macro(arg) , \
    __PROC_ARG7(macro, __VA_ARGS__)
#define __PROC_ARG9(macro, arg, ...) macro(arg) , \
    __PROC_ARG8(macro, __VA_ARGS__)
#define __PROC_ARG10(macro, arg, ...) macro(arg) , \
    __PROC_ARG9(macro, __VA_ARGS__)

/*
 * This handles all separators except for commas. Commas are a special
 * case because they separate macro arguments, and so can't be used as
 * arguments.
 */
#define __PROC_SEP_ARGS_IMPL(macro, sep, count, ...) \
    __PROC_SEP_ARG##count(macro, sep, __VA_ARGS__)
#define __PROC_SEP_COUNTED_ARGS(macro, sep, count, ...) \
    __PROC_SEP_ARGS_IMPL(macro, sep, count, __VA_ARGS__)
#define PROCESS_SEP_ARGS(macro, sep, ...) \
    __PROC_SEP_COUNTED_ARGS(macro, sep, ARG_COUNT(__VA_ARGS__), __VA_ARGS__)

#define __PROC_SEP_ARG0(macro, ...)
#define __PROC_SEP_ARG1(macro, sep, arg, ...) macro(sep, arg)
#define __PROC_SEP_ARG2(macro, sep, arg, ...) macro(sep, arg) sep \
                                    __PROC_SEP_ARG1(macro, sep, __VA_ARGS__)
#define __PROC_SEP_ARG3(macro, sep, arg, ...) macro(sep, arg) sep \
                                    __PROC_SEP_ARG2(macro, sep, __VA_ARGS__)
#define __PROC_SEP_ARG4(macro, sep, arg, ...) macro(sep, arg) sep \
                                    __PROC_SEP_ARG3(macro, sep, __VA_ARGS__)
#define __PROC_SEP_ARG5(macro, sep, arg, ...) macro(sep, arg) sep \
                                    __PROC_SEP_ARG4(macro, sep, __VA_ARGS__)
#define __PROC_SEP_ARG6(macro, sep, arg, ...) macro(sep, arg) sep \
                                    __PROC_SEP_ARG5(macro, sep, __VA_ARGS__)
#define __PROC_SEP_ARG7(macro, sep, arg, ...) macro(sep, arg) sep \
                                    __PROC_SEP_ARG6(macro, sep, __VA_ARGS__)
#define __PROC_SEP_ARG8(macro, sep, arg, ...) macro(sep, arg) sep \
                                    __PROC_SEP_ARG7(macro, sep, __VA_ARGS__)
#define __PROC_SEP_ARG9(macro, sep, arg, ...) macro(sep, arg) sep \
                                    __PROC_SEP_ARG8(macro, sep, __VA_ARGS__)
#define __PROC_SEP_ARG10(macro, sep, arg, ...) macro(sep, arg) sep \
                                    __PROC_SEP_ARG9(macro, sep, __VA_ARGS__)
#endif /* _VAR_MACRO_ARGS_H_ */
