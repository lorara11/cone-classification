vector-operations-test: ../src/vector-operations.o
	gcc -Wall -std=c99 -pedantic ../src/vector-operations.o -o vector-operations-test vector-operations-test.c -lm

../headers/vector-operations.o: ../src/vector-operations.c
	gcc -Wall -std=c99 -pedantic -c -o ../src/vector-operations.o ../src/vector-operations.c -lm

clean: 
	rm ../src/*.o vector-operations-test
