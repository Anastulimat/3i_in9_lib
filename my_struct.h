#ifndef __MY_STRUCT__
#define __MY_STRUCT__

#include "test_bench.h"
#include <stddef.h>

struct struct_my_struct{
	char * 	nom;
	float 	prix;
};

typedef struct struct_my_struct s_my_struct;
typedef s_my_struct * 			p_s_my_struct;

p_s_my_struct 	my_struct_alloc		(p_s_test_bench ptestbench);
void 			my_struct_free		(p_s_test_bench ptestbench, p_s_my_struct ptr);
void 			my_struct_copy		(p_s_test_bench ptestbench, p_s_my_struct dest, p_s_my_struct src);
int 			my_struct_cmp_nom	(p_s_test_bench ptestbench, p_s_my_struct pA, p_s_my_struct pB);
int 			my_struct_cmp_prix	(p_s_test_bench ptestbench, p_s_my_struct pA, p_s_my_struct pB);
void 			my_struct_tostring	(p_s_test_bench ptestbench, p_s_my_struct ptr, char* str, size_t size_max);

void 			my_struct_set_nom	(p_s_test_bench ptestbench, p_s_my_struct ptr, const char * nom);
void 			my_struct_set_prix	(p_s_test_bench ptestbench, p_s_my_struct ptr, float prix);
void 			my_struct_get_nom	(p_s_test_bench ptestbench, p_s_my_struct ptr, char * nom);
float 			my_struct_get_prix	(p_s_test_bench ptestbench, p_s_my_struct ptr);

void 			my_struct_init_rand	(p_s_test_bench ptestbench, p_s_my_struct ptr);

#endif //__MY_STRUCT__
