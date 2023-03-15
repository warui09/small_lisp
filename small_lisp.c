#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char** argv)
{
    /* Print version and Exit information*/
    puts("small_lisp version 1.0\n");
    puts("Press Ctrl+c to exit\n");

    while (1)
    {
        char *input = readline ("> ");       

        /* Output prompt and get input from user*/
        //char* el_gets(*e, *count);

        /* add input to history */
        //add_history(input);

        /* Output test string */
        printf("Hey, it's working. This is your input: %s", input);

        /* free the memory */
        free(input);
    }

    return 0;
    
}
