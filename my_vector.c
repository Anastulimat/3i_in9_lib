#include "my_vector.h"

/**
 *
 * func : alloc_my_vector(p_s_test_bench ptestbench)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *
 * desc : Alloue et retourne la structure de type p_s_my_vector.
 *        Par défaut, le tableau dynamique est vide et le pointeur de p_objet est initialisé à NULL.
 * 
 * return : ptr_my_vector : p_s_my_vector (Pointeur sur la structure allouée)
 *        
**/    
p_s_my_vector alloc_my_vector(p_s_test_bench ptestbench)
{
    p_s_my_vector ptr_my_vector = (p_s_my_vector) my_malloc(ptestbench, sizeof(s_my_vector));
    
    ptr_my_vector->nbr_elements = 0;
    ptr_my_vector->capacity = 16;
    ptr_my_vector->objects_tab = NULL;

    //Affectaion de 1) malloc  -  2) nbr_elements  - 3) capacity  - 4) ptr_object
    increm_instruction_counter(ptestbench, 4);
    return ptr_my_vector;
}



/**
 *
 * func : free_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *
 * desc : Libérer la structure
 * 
 * return : void
 *        
**/    
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
 * func : set_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *        i : size_t - (index du tableau)
 *        pobjet : p_object - (pointuer sur un objet)
 *
 * desc : Affecter la donnée pobjet à l’index i du tableau objects_tab
 * 
 * return : void
 *        
**/    
void set_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet)
{
    if(pmyvector == NULL)
        return;

    if(i > pmyvector->nbr_elements)
        return;

    pmyvector->objects_tab[i] = pobjet;

    //Affectaion de 1) 1ère condition  -  2) 2ème condition  -  3) affectation
    increm_instruction_counter(ptestbench, 3);
}



/**
 *
 * func : get_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *        i : size_t - (index du tableau)
 *
 * desc : Retourne l'éléménet à l’index i du tableau objects_tab
 * 
 * return : p_object - (pointuer sur un objet)
 *        
**/    
p_object get_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i)
{   
    if(pmyvector == NULL)
        return NULL;

    if(i > pmyvector->nbr_elements)
        return NULL;

    //Affectaion de 1) 1ère condition  -  2) 2ème condition
    increm_instruction_counter(ptestbench, 2);

    return pmyvector->objects_tab[i];
}



/**
 *
 * func : insert_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *        i : size_t - (index du tableau pour l'insersion)
 *        pobjet : p_object - (pointuer sur un objet)
 *
 * desc : Insert une nouvelle donnée à l’index i du tableau dynamique
 * 
 * return : void
 *        
**/    
void insert_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet)
{
    if(pmyvector == NULL)
        return;

    if(i > pmyvector->nbr_elements)
        return;
    
    if(pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
    {
        pmyvector->objects_tab = (p_object*) my_malloc(ptestbench, sizeof(p_object) * pmyvector->capacity);
        pmyvector->objects_tab[0] = pobjet;
        pmyvector->nbr_elements = 1;
        increm_instruction_counter(ptestbench, 3);
    }
    else 
    {
        p_object* datas_tmp = (p_object*) my_malloc(ptestbench, sizeof(p_object) * (pmyvector->nbr_elements+1));
        for(long k = 0; k < i; k++)
        {
            datas_tmp[k] = pmyvector->objects_tab[k];
            increm_instruction_counter(ptestbench, 3);
        }

        datas_tmp[i] = pobjet;

        for(long k = i+1; k < pmyvector->nbr_elements; k++)
        {
            datas_tmp[k] = pmyvector->objects_tab[k];
            increm_instruction_counter(ptestbench, 3);
        }

        my_free(ptestbench, pmyvector->objects_tab);
        pmyvector->objects_tab = datas_tmp;
        pmyvector->nbr_elements++;
        increm_instruction_counter(ptestbench, 8);
    }
    increm_instruction_counter(ptestbench, 4);
}



/**
 *
 * func : insert_my_vector_dynamically(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *        i : size_t - (index du tableau pour l'insersion)
 *        pobjet : p_object - (pointuer sur un objet à ajouter)
 *
 * desc : Insert une nouvelle donnée à l’index i du tableau dynamique,
 *        cette méthode ajoute une valeur d'une manière dynamique en calculant la capacité du tableau.
 * 
 * return : void
 *        
**/
void insert_my_vector_dynamically(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet)
{
    if(!pmyvector)
        return;

    if(i > pmyvector->nbr_elements)
        return;

    if((pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0) && pmyvector->capacity >= 16) 
    {
        pmyvector->objects_tab = (p_object*) my_malloc(ptestbench, sizeof(p_object) * pmyvector->capacity);
        pmyvector->objects_tab[0] = pobjet;
        pmyvector->nbr_elements = 1;
        increm_instruction_counter(ptestbench, 3);
    }
    else
    {
        pmyvector->objects_tab[i] = pobjet;
        pmyvector->nbr_elements++;

        if(pmyvector->nbr_elements >= pmyvector->capacity)
        {
            pmyvector->capacity *= 2;
            pmyvector->objects_tab = my_realloc(ptestbench, pmyvector->objects_tab, sizeof(p_object) * pmyvector->capacity);
            increm_instruction_counter(ptestbench, 2);
        }
        increm_instruction_counter(ptestbench, 3);
    }
    increm_instruction_counter(ptestbench, 5);
}



/**
 *
 * func : erase_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *        i : size_t - (index du tableau pour l'insersion)
 *
 * desc : Supprime la donnée à l’index i du tableau dynamique
 * 
 * return : void
 *        
**/    
void erase_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i)
{
    if(pmyvector == NULL)
        return;

    if(i > pmyvector->nbr_elements)
        return;

    if(pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
        return;
 
    else
    {
       p_object* data_tmp = (p_object*) my_malloc(ptestbench, sizeof(p_object) * (pmyvector->nbr_elements-1));
       for(long k = 0; k < i; k++)
       {
           data_tmp[k] = pmyvector->objects_tab[k];
           increm_instruction_counter(ptestbench, 3);
       }
       for(long k = i + 1; k < pmyvector->nbr_elements; k++)
       {
           data_tmp[k-1] = pmyvector->objects_tab[k];
           increm_instruction_counter(ptestbench, 3);
       }
       my_free(ptestbench, pmyvector->objects_tab);
       pmyvector->objects_tab = data_tmp;
       pmyvector->nbr_elements--;
       increm_instruction_counter(ptestbench, 7);
    }
    increm_instruction_counter(ptestbench, 4);
}



/**
 *
 * func : void erase_my_vector_dynamically(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i) 
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *        i : size_t - (index du tableau pour l'insersion)
 *
 * desc : Supprime la donnée à l’index i du tableau dynamique,
 *        cette méthode supprime une valeur d'une manière dynamique en calculant la capacité du tableau.
 * 
 * return : void
 *        
**/
void erase_my_vector_dynamically(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i) 
{
    if(pmyvector == NULL)
        return;

    if(i > pmyvector->nbr_elements)
        return;

    if(pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
        return;

    for(long k = 0; k < i; k++)
    {
        pmyvector->objects_tab[k+i] = pmyvector->objects_tab[k+i+1];
        increm_instruction_counter(ptestbench, 3);
    }

    pmyvector->nbr_elements--;

    if(pmyvector->nbr_elements <= (pmyvector->capacity/4))
    {
        pmyvector->capacity /= 2;
        pmyvector->objects_tab = my_realloc(ptestbench, pmyvector->objects_tab, sizeof(p_object) * pmyvector->capacity);
        increm_instruction_counter(ptestbench, 2);
    }
    increm_instruction_counter(ptestbench, 8);
}



/**
 *
 * func : push_back_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, p_object pobjet)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *        pobjet : p_object - (pointuer sur un objet à ajouter)
 *
 * desc : Insert une nouvelle donnée à la fin du tableau dynamique.
 * 
 * return : void
 *        
**/    
void push_back_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, p_object pobjet)
{
    //Méthode pout le tableau dynamique V2.0
    insert_my_vector_dynamically(ptestbench, pmyvector, pmyvector->nbr_elements, pobjet);

    //Méthode pour le tableau dynamique V1.0 (Plusieurs malloc)
    //insert_my_vector(ptestbench, pmyvector, pmyvector->nbr_elements, pobjet);
}



/**
 *
 * func : pop_back_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *
 *
 * desc : Supprime la dernière donnée de votre tableau dynamique et la retournée.
 * 
 * return : pobjet : p_object - retourner le dernier élément du tableau
 *        
**/    
p_object pop_back_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
{
    if(pmyvector == NULL)
        return NULL;

    if(pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
        return NULL;
    
    p_object pobject = NULL;
    pobject = pmyvector->objects_tab[pmyvector->nbr_elements-1];

    increm_instruction_counter(ptestbench, 5);
    erase_my_vector_dynamically(ptestbench, pmyvector, pmyvector->nbr_elements-1);

    return pobject;
}



/**
 *
 * func : clear_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *
 * desc : Supprime toutes les données du tableau dynamique.
 * 
 * return : void
 *        
**/    
void clear_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
{
    if(pmyvector == NULL)
        return;

    if(pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
        return;

    for(long i = 0; i < pmyvector->nbr_elements; i++)
    {
        pmyvector->objects_tab[i] = NULL;
        my_free(ptestbench, pmyvector->objects_tab[i]);
        increm_instruction_counter(ptestbench, 3);
    }
    my_free(ptestbench, pmyvector->objects_tab);
    pmyvector->nbr_elements = 0;
    increm_instruction_counter(ptestbench, 6);
}



/**
 *
 * func : empty_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *
 * desc : Retourne un entier non-nul si le tableau dynamique est vide et zéros sinon.
 * 
 * return : int
 *        
**/    
int empty_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
{
    if(pmyvector == NULL || pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
        return 1;

    increm_instruction_counter(ptestbench, 3);

    return 0;
}


/**
 *
 * func : size_t size_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
 *
 * args : ptestbench : p_s_test_bench - (Pointeur sur test_bench)
 *        pmyvector : p_s_my_vector - (Pointeur sur un vector)
 *
 * desc : Retourne le nombre d’élément stocker dans le tableau dynamique
 * 
 * return : size_t - Le nombre d'éléments dans le tableau
 *        
**/    
size_t size_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
{
    if(pmyvector == NULL || pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
        return 0;

    increm_instruction_counter(ptestbench, 3);

    return pmyvector->nbr_elements;
}