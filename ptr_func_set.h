
#ifndef __PTR_FUNC_SET__
#define __PTR_FUNC_SET__

#include "test_bench.h"
#include <stddef.h>

/*Definition du type p_objet*/
typedef void * p_objet;

/*Definition du type de pointeur de fonction pour les fonctions d'allocation*/
typedef p_objet (*p_func_alloc)	(p_s_test_bench ptestbench);

/*Definition du type de pointeur de fonction pour les fonctions de libération*/
typedef void 	(*p_func_free)	(p_s_test_bench ptestbench, p_objet ptr);

/*Definition du type de pointeur de fonction pour les fonctions de copie*/
typedef void 	(*p_func_copy)	(p_s_test_bench ptestbench, p_objet dest, p_objet src);

/* Definition du type de pointeur de fonction pour les fonctions de comparaison
 * 0 si le critère de a est égal au critère de b
 * < 0 si le critère de a est inférieur au critère de b
 * > 0 si le critère de a est supérieur au critère de b
 * */
typedef int (*p_func_cmp)(p_s_test_bench ptestbench, p_objet pA, p_objet pB);

/*Definition du type de pointeur de fonction pour les fonctions de copie*/
typedef void 	(*p_func_tostring)(p_s_test_bench ptestbench, p_objet ptr, char* str, size_t size_max);

/*Definition d'une structure pour stocker l'ensemble des pointeurs de fonctions*/
struct struct_ptr_func_set{
	p_func_alloc 	alloc;
	p_func_free 	free;
	p_func_copy 	copy;
	p_func_cmp 		cmp;
	p_func_tostring	tostring;
};

typedef struct struct_ptr_func_set s_ptr_func_set;
typedef s_ptr_func_set* p_s_ptr_func_set;


/*Fonction d'allocation d'une structure s_ptr_func_set
 * Exemple :
 * p_s_ptr_func_set psptrfuncset = 
 * 			ptr_func_set_alloc(	(p_func_alloc)		my_struct_alloc,
 * 								(p_func_free)		my_struct_free,
 * 								(p_func_copy)		my_struct_copy,
 * 								(p_func_cmp)		my_struct_cmp_nom,
 * 								(p_func_tostring)	my_struct_tostring);
 * */
p_s_ptr_func_set ptr_func_set_alloc(p_func_alloc 	alloc,
									p_func_free 	free,
									p_func_copy 	copy,
									p_func_cmp 		cmp,
									p_func_tostring tostring);

/*Fonction de libération d'une structure s_ptr_func_set*/							
void ptr_func_set_free(p_s_ptr_func_set ptr);

#endif //__PTR_FUNC_SET__
 
