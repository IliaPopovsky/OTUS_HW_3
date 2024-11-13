#makefile для hash_functions.c
hash_functions: hash_functions.c
	gcc  -Wall -Wextra -Wpedantic -o hash_functions hash_functions.c -no-pie

