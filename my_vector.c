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
    for(int index = 0; i < pmyvector->nbr_elements; index++)
    {
        if(index == i)
        {
            pmyvector->objects_tab = pobjet;
        }
    }
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






