#ifndef __MY__VECTOR__
#define __MY__VECTOR__

#include "test_bench.h"
#include "ptr_func_set.h"


//Un pointeur de sur un objet (abstrait)
typedef void* p_object;

//Structure my_vector 
//    1) Nomber d'éléments <<référencés>> dans la structure
//	  3) Nombre d'éléments <<référeçable>> dans la structure (taille réelle du tableau)	
//	  4) Pointeur sur la structure s_ptr_func_set
//    2) Tableau d'objets de type void* (p_objet)
struct struct_my_vector {
    size_t nbr_elements;
    size_t capacity;
    p_s_ptr_func_set ptr_func_set;
    p_object* objects_tab;
};

//Redéfinir to s_my_vector
typedef struct struct_my_vector s_my_vector;

//Un pointeur sur la structure
typedef s_my_vector* p_s_my_vector;


/**********************************************
 * METHODES
 * **********************************************/
p_s_my_vector       alloc_my_vector(p_s_test_bench ptestbench);
void                free_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector);
void                set_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet);
p_object            get_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i);
void                insert_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i, p_object pobjet);
void                erase_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, size_t i);
void                push_back_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector, p_object pobjet);
p_object            pop_back_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector);
void                clear_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector);
int                 empty_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector);
size_t              size_my_vector(p_s_test_bench ptestbench, p_s_my_vector pmyvector);


#endif
