#include "test_bench.h"
 
/**
 *
 * func : alloc_s_test_bench()
 *
 * args : 
 *
 * desc : Allouer et retourner une pointeur sur la structure allouée.
 * 
 * return : ptr_test_bench (Pointeur sur la structure allouée)
 *        
**/    
p_s_test_bench alloc_s_test_bench() 
{
    p_s_test_bench ptr_test_bench = NULL;
    ptr_test_bench = (p_s_test_bench) malloc(sizeof(s_test_bench));
    if(!ptr_test_bench) 
    {
        printf("ptr_test_bench --> malloc error !");
        exit(0);
    }
    return ptr_test_bench;
}


/**
 *
 * func : free_s_test_bench(p_s_test_bench p)
 *
 * args : p : p_s_test_bench - (Pointeur sur la structure)
 *
 * desc : Libérer la structrue pointée par p.
 * 
 * return : void
 *        
**/    
void free_s_test_bench(p_s_test_bench p)
{
    if(p)
        free(p);
}


/**
 *
 * func : start_test_bench(p_s_test_bench p)
 *
 * args : p : p_s_test_bench - (Pointeur sur la structure)
 *
 * desc : Initialiser à zéro tous les compteurs de la structure,
 *        et initialise la variable de debut pour la mesure de temps d'exécution.
 * 
 * return : void
 *        
**/    
void start_test_bench(p_s_test_bench p) 
{
    if(p)
    {
        p->start = clock();
        p->compteurInstruction = 0;
        p->compteurAllocation = 0;
        p->compteurFree = 0;
        p->compteurTotalAllocationSize = 0;
    }
}


/**
 *
 * func : stop_test_bench(p_s_test_bench p)
 *
 * args : p : p_s_test_bench - (Pointeur sur la structure)
 *
 * desc : Initialise le variable de debut pour la mesure de temps d'exécution.
 * 
 * return : void
 *        
**/    
void stop_test_bench(p_s_test_bench p) 
{
    if(p)
    {
        p->finish = clock();
    }
}


/**
 *
 * func : increm_instruction_counter(p_s_test_bench p, int n)
 *
 * args : p : p_s_test_bench - (Pointeur sur la structure)
 *        n : int - (nombre d'instuction)
 *
 * desc : Incrémenter le compteur d'instuction de n instuctions.
 * 
 * return : void
 *        
**/    
void increm_instruction_counter(p_s_test_bench p, int n)
{
    if(p) 
    {
        p->compteurInstruction += n;
    }
}


/**
 *
 * func : my_malloc(p_s_test_bench p, size_t size)
 *
 * args : p : p_s_test_bench - (Pointeur sur la structure)
 *        size : size_t - (nombre d'instuction)
 *
 * desc : Allouer une zone de méemoire de taille size, 
 *        Incrémenter le compteur d’allocation de 1,
 *        Incrémenter le compteur de mémoire allouée de size et retourner la mémoire allouée.
 * 
 * return : ptr : void* (la mémoire allouée)
 *        
**/    
void* my_malloc(p_s_test_bench p, size_t size)
{
    //p_s_test_bench ptr_test_bench = (p_s_test_bench) malloc(sizeof(size));

    void* ptr = malloc(size);

    if(!ptr) 
    {
        printf("ptr ---> malloc error !");
        exit(0);
    }
    p->compteurAllocation++;
    p->compteurTotalAllocationSize += size;
    return ptr;
}


/**
 *
 * func : my_free(p_s_test_bench p, void* ptr)
 *
 * args : p : p_s_test_bench - (Pointeur sur la structure)
 *        ptr : void* - (Pointeur sur la zone mémoire)
 *
 * desc : libérer la zone mémoire pointée par ptr,
 *        Incrémenter le compteur de libération de 1.
 * 
 * return : void
 *        
**/    
void my_free(p_s_test_bench p, void* ptr) 
{
    free(ptr);
    p->compteurFree++;
}


/**
 *
 * func : print_test_bench(p_s_test_bench p)
 *
 * args : p : p_s_test_bench - (Pointeur sur la structure)
 *
 * desc : Afficher un rapport de toutes les mesures
 * 
 * return : void
 *        
**/    
void print_test_bench(p_s_test_bench p) 
{
    printf("\n********************************\n");
    printf("##Rapport de toute les mesures##\n");
    printf("********************************\n\n");
    printf("==> start(clock_t) = %ld\n", p->start);
    printf("==> finish(clock_t) = %ld\n", p->finish);
    printf("==> Total finish - start (clock_t) = %f sec\n",  (double)(p->finish - p->start) / CLOCKS_PER_SEC);
    printf("==> compteurInstruction(size_t) = %ld\n", p->compteurInstruction);
    printf("==> compteurAllocation(size_t) = %ld\n", p->compteurAllocation);
    printf("==> compteurFree(size_t) = %ld\n", p->compteurFree);
    printf("==> compteurTotalAllocationSize(size_t) = %ld\n\n", p->compteurTotalAllocationSize);
    printf("=========================================================================\n\n");
}
