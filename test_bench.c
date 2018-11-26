#include "test_bench.h"
    
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


void free_s_test_bench(p_s_test_bench p)
{
    free(p);
}


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


void stop_test_bench(p_s_test_bench p) 
{
    if(p)
    {
        p->finish = clock();
    }
}


void increm_instruction_counter(p_s_test_bench p, int n)
{
    if(p) 
    {
        p->compteurInstruction += n;
    }
}

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


void my_free(p_s_test_bench p, void* ptr) 
{
    free(ptr);
    p->compteurFree++;
}


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
