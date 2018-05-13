all : forkit.c tryit.c
	gcc -o forkit -Wall -pedantic -g forkit.c
	gcc -o tryit -Wall -pedantic -g tryit.c
