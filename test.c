/*
 * Example of using var-macro-args.h
 */

#include <stdarg.h>
#include <stdlib.h>

#include <var-macro-args.h>

#define PROCESS_ARG(arg)            sizeof(arg), &arg
#define SEP                         ,
#define PROCESS_SEP_ARG(sep, arg)   arg

static void print_args(int n, ...) {
    va_list ap;
    const char *sep1;
    int i;

    printf("arguments (%d): ", n);
    va_start(ap, n);
    sep1 = "";

    for (i = 0; i < n; i++) {
        size_t size;
        const unsigned char *p;
        const char *sep2;
        size_t j;

        size = va_arg(ap, typeof(size));
        p = (const unsigned char *)va_arg(ap, void *);

        printf("%s[", sep1);
        sep2 = "";

        for (j = 0; j < size; j++) {
            printf("%s%02x", sep2, p[j]);
            sep2 = ", ";
        }

        printf("]");
        sep1 = ", ";
    }

    va_end(ap);
    printf("\n");
}


 int main() {
    int value1 = 10;
    struct {
        int a;
        float b;
    } value2 = {.a = 20, .b = 1.0 };
    struct { char a[1]; } v1 = {.a = {10}};
    struct { char a[2]; } v2 = {.a = {10, 20}};
    struct { char a[3]; } v3 = {.a = {10, 20, 30}};
    struct { char a[4]; } v4 = {.a = {10, 20, 30, 40}};
    struct { char a[5]; } v5 = {.a = {10, 20, 30, 40, 50}};
    struct { char a[6]; } v6 = {.a = {10, 20, 30, 40, 50, 60}};
    struct { char a[7]; } v7 = {.a = {10, 20, 30, 40, 50, 60, 70}};
    struct { char a[8]; } v8 = {.a = {10, 20, 30, 40, 50, 60, 70, 80}};
    struct { char a[9]; } v9 = {.a = {10, 20, 30, 40, 50, 60, 70, 80, 90}};
    struct { char a[10]; } v10 = {.a = {10, 20, 30, 40, 50, 60, 70, 80, 90,
         100}};
    int sum1, sum2;
   
    printf("Counting zero argument: %d\n", ARG_COUNT());
    printf("Counting one argument: %d\n", ARG_COUNT(one));
    printf("Counting two arguments: %d\n", ARG_COUNT(one, two));
    printf("Counting nine arguments: %d\n", ARG_COUNT(one, two, three,
        four, five, six, seven, eight, nine));
    printf("Counting ten arguments: %d\n", ARG_COUNT(one, two, three,
        four, five, six, seven, eight, nine, ten));

    print_args(0);
#define PRINT_ARGS(...) print_args(ARG_COUNT(__VA_ARGS__), \
    PROCESS_ARGS(__VA_ARGS__))
    PRINT_ARGS(value1, value2);
    PRINT_ARGS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);

#define SUM_ARGS(...) PROCESS_SEP_ARGS(+, __VA_ARGS__)
    sum1 = SUM_ARGS(1, 2);
    printf("sum1 is %d, should be 3\n", sum1);
    sum2 = SUM_ARGS(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("sum2 is %d, should be 45\n", sum2);

    return EXIT_SUCCESS;
}
