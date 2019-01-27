all : test_test_bench test_my_vector test_my_struct


test_test_bench : test_test_bench.o test_bench.o
	gcc test_bench.o test_test_bench.o -o test_test_bench

test_my_vector : test_my_vector.o my_vector.o test_bench.o
	gcc my_vector.o test_bench.o test_my_vector.o -o test_my_vector

test_my_struct : test_bench.o ptr_func_set.o my_rand_util.o my_struct.o test_my_struct.o
	gcc test_bench.o ptr_func_set.o my_rand_util.o my_struct.o test_my_struct.o -o test_my_struct

test_bench.o : test_bench.c
	gcc test_bench.c -g -c -o test_bench.o

test_test_bench.o : test_test_bench.c 
	gcc test_test_bench.c -g -c -o test_test_bench.o

my_vector.o : my_vector.c
	gcc my_vector.c -g -c -o my_vector.o

test_my_vector.o : test_my_vector.c
	gcc test_my_vector.c -g -c -o test_my_vector.o

ptr_func_set.o : ptr_func_set.c
	gcc ptr_func_set.c -g -c -o ptr_func_set.o

my_rand_util.o : my_rand_util.c
	gcc my_rand_util.c -g -c -o my_rand_util.o

my_struct.o : my_struct.c
	gcc my_struct.c -g -c -o my_struct.o

test_my_struct.o : test_my_struct.c
	gcc test_my_struct.c -g -c -o test_my_struct.o

clean :
	rm -f *.o test_test_bench test_my_vector test_my_struct