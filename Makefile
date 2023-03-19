parsing: parsing.c -lreadline mpc.c -lm
	gcc -std=c99 -Wall parsing.c mpc.c -lreadline -lm -o parsing
