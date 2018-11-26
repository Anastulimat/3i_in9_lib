#include "my_vector.h"


/**
 * 
 * 
 * alloue et retourne votre structure. 
 * Par d ́efaut, le tableau dynamique est vide alors le pointeur de p_objet est initialisé à NULL
 * 
 * *********************************************/
p_s_my_vector alloc_my_vector(p_s_test_bench ptestbench)
{
    p_s_my_vector ptr_my_vector = NULL;

    ptr_my_vector = (p_s_my_vector) my_malloc(ptestbench, sizeof(s_my_vector));
    
    ptr_my_vector->nbr_elements = 0;
    ptr_my_vector->objects_tab = NULL;

    //Affectaion de 1)malloc  -  2)nbr_elements  -  3)ptr_object
    increm_instruction_counter(ptestbench, 3);
    return ptr_my_vector;
}



/**
 * 
 * 
 * Libérer la structure
 * 
 * *********************************************/
void free_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
{   
    if(pmyvector)
    {
        my_free(ptestbench, pmyvector->objects_tab);  
        my_free(ptestbench, pmyvector);
    }    
}



/**
 * 
 * 
 * Affecter la donnée pobjet à l’index i du tableau objects_tab
 * 
 * *********************************************/
void set_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet)
{
    if(pmyvector == NULL)
        return;

    if((i > pmyvector->nbr_elements) || (i < 0))
        return;
    
    pmyvector->objects_tab[i] = pobjet;
}


/**
 * 
 * 
 * Retourne l'éléménet à l’index i du tableau objects_tab
 * 
 * *********************************************/
p_object get_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i)
{
    p_object pobject = NULL;
    for(int index = 0; i < pmyvector->nbr_elements; index++)
    {
        if(index == i)
        {
            pobject = pmyvector->objects_tab;
        }
    }
    return pobject;
}


/**
 * 
 * 
 * Insert une nouvelle donnée à l’index i de votre tableau dynamique
 * 
 * *********************************************/
void insert_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet)
{
    if(pmyvector == NULL)
        return;

    if(i > pmyvector->nbr_elements)
        return;
    
    if(pmyvector->objects_tab == NULL) // OU pmyvector->nbr_elements == 0
    {
        pmyvector->objects_tab = (p_object*) my_malloc(ptestbench, sizeof(p_object));
        pmyvector->objects_tab[0] = pobjet;
        pmyvector->nbr_elements = 1;
    }
    else 
    {
        p_object* datas_tmp = (p_object*) my_malloc(ptestbench, sizeof(p_object) * (pmyvector->nbr_elements+1));
        for(long k = 0; k < i; k++)
        {
            datas_tmp[k] = pmyvector->objects_tab[k];
        }

        datas_tmp[i] = pobjet;

        for(long k = i+1; k < pmyvector->nbr_elements; k++)
        {
            datas_tmp[k] = pmyvector->objects_tab[k];
        }

        my_free(ptestbench, pmyvector->objects_tab);
        pmyvector->objects_tab = datas_tmp;
        pmyvector->nbr_elements++;
    }
}
