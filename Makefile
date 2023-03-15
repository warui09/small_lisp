small_lisp.o: small_lisp.c -lreadline
	gcc -c small_lisp.c

small_lisp: small_lisp.o
	gcc small_lisp.o -o small_lisp