#ifndef __MY__VECTOR__
#define __MY__VECTOR__

#include "test_bench.h"


//Un pointeur de sur un objet
typedef void* p_object;

//Structure my_vector
struct struct_my_vector {
    size_t nbr_elements;
    p_object objects_tab;
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



#endif
