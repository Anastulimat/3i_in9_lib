#include "my_vector.h"


/**
 * 
 * 
 * Alloue et retourne la structure. 
 * Par défaut, le tableau dynamique est vide et le pointeur de p_objet est initialisé à NULL
 * 
 * *********************************************/
p_s_my_vector alloc_my_vector(p_s_test_bench ptestbench)
{
    p_s_my_vector ptr_my_vector = (p_s_my_vector) my_malloc(ptestbench, sizeof(s_my_vector));
    
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

    if(i > pmyvector->nbr_elements)
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
    if(pmyvector == NULL)
        return NULL;

    if(i > pmyvector->nbr_elements)
        return NULL;

    return pmyvector->objects_tab[i];
}


/**
 * 
 * 
 * Insert une nouvelle donnée à l’index i du tableau dynamique
 * 
 * *********************************************/
void insert_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet)
{
    printf("Pass insert_my_vector i = %ld\n", i);
    if(pmyvector == NULL)
        return;

    if(i > pmyvector->nbr_elements)
        return;
    
    if(pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
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

/**
 * 
 * 
 * Supprime la donnée à l’index i du tableau dynamique
 * 
 * *********************************************/
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
       }
       for(long k = i + 1; k < pmyvector->nbr_elements; k++)
       {
           data_tmp[k-1] = pmyvector->objects_tab[k];
       }
       my_free(ptestbench, pmyvector->objects_tab);
       pmyvector->objects_tab = data_tmp;
       pmyvector->nbr_elements--;
   }
}

/**
 * 
 * 
 * Insert une nouvelle donnée à la fin du tableau dynamique
 * 
 * *********************************************/
void push_back_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, p_object pobjet)
{
    printf("Pass push_back_my_vector\n");
    insert_my_vector(ptestbench, pmyvector, pmyvector->nbr_elements-1, pobjet);
}


/**
 * 
 * 
 * Supprime la dernière donnée de votre tableau dynamique
 * 
 * *********************************************/
p_object pop_back_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
{
    if(pmyvector == NULL)
        return NULL;

    if(pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
        return NULL;
    
    p_object pobject = NULL;
    pobject = pmyvector->objects_tab[pmyvector->nbr_elements-1];

    erase_my_vector(ptestbench, pmyvector, pmyvector->nbr_elements-1);

    return pobject;
}


/**
 * 
 * 
 * Supprime toutes les données de votre tableau dynamique.
 * 
 * *********************************************/
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
    }
    my_free(ptestbench, pmyvector->objects_tab);
    pmyvector->nbr_elements = 0;
}


/**
 * 
 * 
 * Retourne un entier non-nul si le tableau dynamique est vide et zéros sinon.
 * 
 * *********************************************/
int empty_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
{
    if(pmyvector == NULL || pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
        return 1;

    return 0;
}


/**
 * 
 * 
 * Retourne le nombre d’élément stocker dans le tableau dynamique
 * 
 * *********************************************/
size_t size_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector)
{
    if(pmyvector == NULL || pmyvector->objects_tab == NULL || pmyvector->nbr_elements == 0)
        return 0;

    return pmyvector->nbr_elements;
}