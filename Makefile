all: tests
tests: tests.o graph.o
	gcc graph.o tests.o -o tests -fprofile-arcs -ftest-coverage
tests.o: tests.c
	gcc -c tests.c -fprofile-arcs -ftest-coverage
graph.o: graph.c
	gcc -c graph.c -fprofile-arcs -ftest-coverage

clean: 
	rm -rf *.o *.gcno *.gcda *.gcov tests