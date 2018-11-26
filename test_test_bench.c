#define SIZE 100000000

#include <stdio.h>
#include <stdlib.h>

#include "test_bench.h"

int main(int argc, char const *argv[])
{
    
    p_s_test_bench ptr_test_bench = NULL;
    ptr_test_bench = alloc_s_test_bench();
    start_test_bench(ptr_test_bench);
    
    int* ptr_int = NULL;
    ptr_int = (int*) my_malloc(ptr_test_bench, SIZE * sizeof(int));

    
    
    //Incrémenter de 2 ==> 1) Affictaion ptr_int = my_malloc. 2) Initialisation de boucle for i = 0.
    increm_instruction_counter(ptr_test_bench, 2);
    
    for(int i = 0; i < SIZE; i++)
    {
        ptr_int[i] = i;
        //Incrémenter de 3 Dans le boucle on a ==> 1) Incrémentaion de 1 i++. 2) Test de condition. 3) Affictaion dans la boucle.
        increm_instruction_counter(ptr_test_bench, 3); 
    }
    stop_test_bench(ptr_test_bench);
    
    my_free(ptr_test_bench, ptr_int);
    print_test_bench(ptr_test_bench);

    free_s_test_bench(ptr_test_bench);

    return 0;
}
