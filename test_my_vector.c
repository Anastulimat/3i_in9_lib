#include <stdio.h>
#include <stdlib.h>

#include "test_bench.h"
#include "my_vector.h"

int main(int argc, char const *argv[])
{
    p_s_test_bench ptestbench = alloc_s_test_bench();
    start_test_bench(ptestbench);

    int* tab = my_malloc(ptestbench, sizeof(int) * 1000);
    p_s_my_vector pmyvector = alloc_my_vector(ptestbench);


    for(size_t i = 0; i < 1000; i++)
        push_back_my_vector(ptestbench, pmyvector, &(tab[i]));
    
    /*
    for(size_t i = 0; i < 1000; i++)
    {
        printf("tab[%ld] = %d\n", i, tab[i]);
    }
    exit(0);
    */

    for(size_t i = 0; i < 1000; i++)
        *(int*)get_my_vector(ptestbench, pmyvector, i) = i;

    while(!empty_my_vector(ptestbench, pmyvector))
        pop_back_my_vector(ptestbench, pmyvector);

    free_my_vector(ptestbench, pmyvector);
    my_free(ptestbench, tab);
    stop_test_bench(ptestbench);
    print_test_bench(ptestbench);
    free_s_test_bench(ptestbench);
    
    return 0;
}
