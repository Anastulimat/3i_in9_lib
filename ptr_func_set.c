#include "ptr_func_set.h"
#include <stdlib.h>

p_s_ptr_func_set ptr_func_set_alloc(p_func_alloc 	alloc,
									p_func_free 	free,
									p_func_copy 	copy,
									p_func_cmp 		cmp,
									p_func_tostring tostring){
										
	p_s_ptr_func_set p_fptr_set = malloc(sizeof(s_ptr_func_set));
	if(p_fptr_set != NULL){
		p_fptr_set->copy 		= copy;
		p_fptr_set->alloc 		= alloc;
		p_fptr_set->free 		= free;
		p_fptr_set->tostring 	= tostring;
		p_fptr_set->cmp 		= cmp;
	}
	
	return p_fptr_set;
}
								
void ptr_func_set_free(p_s_ptr_func_set ptr){
	if(ptr != NULL){
		free(ptr);
	}
}

