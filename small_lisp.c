#include <stdio.h>

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char** argv)
{
    /* Print version and Exit information*/
    puts("small_lisp version 1.0\n");
    puts("Press Ctrl+c to exit\n");

    while (1)
    {
        /* Output prompt */
        fputs("small_lisp> ", stdout);

        /* Read input from user, max size 2048 */
        fgets(input, 2048, stdin);

        /* Output test string */
        printf("Hey, it's working. This is your input: %s", input);
    }

    return 0;
    
}
