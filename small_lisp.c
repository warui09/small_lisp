#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char** argv)
{
    /* Print version and Exit information*/
    /* will add later pre-processor instructions to allow for compilation on Windows */
    puts("small_lisp version 1.0");
    puts("Press Ctrl+c to exit");

    while (1)
    {
        char *input = readline ("small_lisp> ");

        /* add non empty line to history */
        if (*input)
        {
            add_history(input);
        }

        /* Output test string */
        printf("Hey, it's working. This is your input: %s\n", input);

        /* free the memory */
        free(input);
    }

    return 0;
    
}
