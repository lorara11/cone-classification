classify_cone: vector-operations.o classification-functions.o main.c
	gcc -Wall -std=c99 -pedantic main.c vector-operations.o classification-functions.o -o classify_cone -lm

classification-functions.o: vector-operations.o classification-functions.c
	gcc -Wall -std=c99 -pedantic classification-functions.c vector-operations.o -c -lm

vector-operations.o: vector-operations.c
	gcc -Wall -std=c99 -pedantic vector-operations.c -c -lm

clean:
	rm *.o classify_cone