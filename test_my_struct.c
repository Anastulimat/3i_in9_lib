#include "my_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){//int argc, char *argv[]
	p_s_my_struct p_my_struct_a = NULL;
	s_my_struct my_struct_b = {NULL, 0.0};
	
	char str_a[100];
	char str_b[100];
	
	p_s_test_bench ptestbench = alloc_s_test_bench(); 
	start_test_bench(ptestbench);
	
	srand(time(NULL)); //initialisation de la graine du générateur de nombres aléatoires
	
	my_struct_tostring(ptestbench, p_my_struct_a, str_a, sizeof(str_a));
	printf("\n%s\n", str_a);
	
	p_my_struct_a = my_struct_alloc(ptestbench);
	
	my_struct_tostring(ptestbench, p_my_struct_a, str_a, sizeof(str_a));
	printf("%s\n", str_a);
	
	my_struct_init_rand(ptestbench, p_my_struct_a);
	
	my_struct_tostring(ptestbench, p_my_struct_a, str_a, sizeof(str_a));
	printf("%s\n", str_a);
	
	my_struct_init_rand(ptestbench, &my_struct_b);
	my_struct_tostring(ptestbench, &my_struct_b, str_b, sizeof(str_b));
	printf("%s\n", str_b);
	
	printf("my_struct_cmp_nom(%s, %s) = %d\n", str_a, str_b, my_struct_cmp_nom(ptestbench, p_my_struct_a, &my_struct_b));
	printf("my_struct_cmp_prix(%s, %s) = %d\n", str_a, str_b, my_struct_cmp_prix(ptestbench, p_my_struct_a, &my_struct_b));
	
	my_struct_free(ptestbench, p_my_struct_a);
	
	stop_test_bench(ptestbench);
	print_test_bench(ptestbench);
	free_s_test_bench(ptestbench);
	
	return 0;
}
