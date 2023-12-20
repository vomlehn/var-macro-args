/*
 * Example of using var-macro-args.h
 */

#include <stdarg.h>
#include <var-macro-args.h>

#define PRINT_ITEM(arg)  arg
#define PRINT_LIST(...) print_args(ARG_COUNT(__VA_ARGS__), \
    PROCESS_ARGS(PRINT_ITEM, ##__VA_ARGS__))

/*
 * Print a list of integer arguments where the number of integers is
 * passed as the first argument.
 */
static void print_args(int n, ...) {
    va_list ap;
    int i;

    printf("Printing %d arguments:\n", n);

    va_start(ap, n);
    for (i = 0; i < n; i++) {
        int x;

        x = va_arg(ap, int);
        printf("Argument #%d: %d\n", i, x);
    }
    va_end(ap);
}

int main() {

    
    int value1 = 10;
    int value2 = 20;
   
    printf("Counting zero argument: %d\n", ARG_COUNT());
    printf("Counting one argument: %d\n", ARG_COUNT(one));
    printf("Counting two arguments: %d\n", ARG_COUNT(one, two));
    printf("Counting ten arguments: %d\n", ARG_COUNT(one, two, three, four,
        five, six, seven, eight, nine));

    PRINT_LIST(42);
    PRINT_LIST(10, 20, 30, 40, 50, 60, 70, 80, 90, 100);

    return 0;
}

