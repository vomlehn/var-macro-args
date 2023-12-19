/*
 * Example of using var-macro-args.h
 */

#include <var-macro-args.h>

int main() {
    int value1 = 10;
    int value2 = 20;
   
    printf("Counting zero argument: %d\n", COUNT_ARGS());
    printf("Counting one argument: %d\n", COUNT_ARGS(one));
    printf("Counting two arguments: %d\n", COUNT_ARGS(one, two));
    printf("Counting nine arguments: %d\n", COUNT_ARGS(one, two, three, four,
        five, six, seven, eight, nine));
    printf("Counting ten arguments: %d\n", COUNT_ARGS(one, two, three, four,
        five, six, seven, eight, nine, ten));

    // Use the PROCESS_ARGS macro with the number of arguments you want to process
//    PROCESS_ARGS(COUNT_ARGS(value1, value2), value1, value2);

    return 0;
}

