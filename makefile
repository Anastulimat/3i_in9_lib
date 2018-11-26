all : test_test_bench

test_test_bench : test_test_bench.o test_bench.o
	gcc test_bench.o test_test_bench.o -o test_test_bench

test_bench.o : test_bench.c test_bench.h
	gcc test_bench.c -g -c -o test_bench.o

test_test_bench.o : test_test_bench.c 
	gcc test_test_bench.c -g -c -o test_test_bench.o

my_vector.o : my_vector.c
	gcc my_vector.c -g -c -o my_vector.o

clean :
	rm -f *.o test_test_bench