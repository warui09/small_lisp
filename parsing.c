#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"
#include <readline/history.h>
#include <readline/readline.h>

int main(int argc, char** argv)
{
    /* create parsers */
    mpc_parser_t *Number = mpc_new("number");
    mpc_parser_t *Operator = mpc_new("operator");
    mpc_parser_t *Expr = mpc_new("expr");
    mpc_parser_t *Small_lisp = mpc_new("small_lisp");

    /* define the parsers with the following language */
    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                   \
        number : /-?[0-9]+/;                            \
        operator : '+' | '-' | '*' | '/' ;              \
        expr : <number> | '(' <expr> <operator> <expr> ')' ;  \
        small_lisp: /^/ <expr> <operator> <expr> /$/ ;   \
        ",
        Number, Operator, Expr, Small_lisp);
    /* Print version and Exit information*/
    /* will add later pre-processor instructions to allow for compilation on Windows */
    puts("small_lisp version 1.0");
    puts("Press Ctrl+c to exit");

    while (1)
    {
        char *input = readline("small_lisp> ");

        /* add non empty line to history */
        if (*input)
        {
            add_history(input);
        }

        /* Load AST from output */
        mpc_result_t r;

        /* Parse the user input */
        if (mpc_parse("<stdin>", input, Small_lisp, &r))
        {
            /* On success print the AST */
            mpc_ast_t *a = r.output;
            mpc_ast_print(a);
            mpc_ast_delete(a);
        }
        else
        {
            /* Print the error */
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        /* free the memory */
        free(input);
    }

    /* undefine and delete parsers*/
    mpc_cleanup(4, Number, Operator, Expr, Small_lisp);

    return 0;
}


