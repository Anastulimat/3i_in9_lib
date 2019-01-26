#ifndef __TEST_BENCH__
#define __TEST_BENCH__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct struct_test_bench
{
    //Stocker le temps de d´ebut et de fin de la mesure du temps d’exécution 
    clock_t start;      
    clock_t finish;

    //Compter le nombre d'instruction
    size_t  compteurInstruction;

    //Compter le nombre d'allocation (malloc)
    size_t  compteurAllocation;

    //Compter le nombre de libération (free)
    size_t  compteurFree;

    //Compter la quantité cumulée total alloué
    size_t  compteurTotalAllocationSize;
};

//Redéfinir struct struct_test_bench ===> s_test_bench
typedef struct struct_test_bench s_test_bench;

//Définir le type p_s_test_bench qui est un pointeur de s_test_bench (s_test_bench* ===> p_s_test_bench)
typedef s_test_bench* p_s_test_bench;


/*******************************************
 *              METHODES
 * ****************************************/
p_s_test_bench  alloc_s_test_bench();
void            free_s_test_bench(p_s_test_bench p);
void            start_test_bench(p_s_test_bench p);
void            stop_test_bench(p_s_test_bench p);
void            increm_instruction_counter(p_s_test_bench p, int n);
void*           my_malloc(p_s_test_bench p, size_t size);
void*           my_realloc(p_s_test_bench p, void* ptr_vector, size_t size);
void            my_free(p_s_test_bench p, void* ptr);
void            print_test_bench(p_s_test_bench p);

#endif
