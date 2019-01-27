#include "my_struct.h"
#include "my_rand_util.h"
#include <stdlib.h>
#include <stdio.h>

size_t my_strcpy(p_s_test_bench ptestbench, char * dest,const char * src){
	size_t i;
	increm_instruction_counter(ptestbench, 1);
	if(dest == NULL || src == NULL)
		return 0;
	increm_instruction_counter(ptestbench, 1);
	for(i = 0; src[i] != '\0' ; i++){
		increm_instruction_counter(ptestbench, 3);
		dest[i] = src[i];
	}
	increm_instruction_counter(ptestbench, 1);
	dest[i] = src[i];
	return i;
}

size_t my_strlen(p_s_test_bench ptestbench, const char * ptr){
	size_t i;
	increm_instruction_counter(ptestbench, 1);
	if(ptr == NULL)
		return 0;
	increm_instruction_counter(ptestbench, 1);
	for(i = 0; ptr[i] != '\0' ; i++){
		increm_instruction_counter(ptestbench, 2);
	}
	return i;
}

int my_strcmp(p_s_test_bench ptestbench, const char *s1, const char *s2){
	while (*s1 != '\0' && (*s1++ == *s2++)){
		increm_instruction_counter(ptestbench, 4);
	}
	increm_instruction_counter(ptestbench, 4);
	s1--;
	s2--;
	if(*((unsigned char *)s1) < *((unsigned char *)s2))
		return -1;
	else 
		return *(unsigned char *)s1 != *(unsigned char *)s2;
}

void my_struct_copy(p_s_test_bench ptestbench, p_s_my_struct dest, p_s_my_struct src){
	increm_instruction_counter(ptestbench, 1);
	if(dest == NULL || src == NULL)
		return;
	increm_instruction_counter(ptestbench, 2);
	dest->prix = src->prix;
	if(dest->nom != NULL){
		increm_instruction_counter(ptestbench, 1);
		my_free(ptestbench, dest->nom);
		dest->nom = NULL;
	}
	increm_instruction_counter(ptestbench, 1);
	if(src->nom != NULL){
		increm_instruction_counter(ptestbench, 1);
		dest->nom = my_malloc(ptestbench, my_strlen(ptestbench, src->nom)+1);
		my_strcpy(ptestbench, dest->nom, src->nom);
	}
}

p_s_my_struct my_struct_alloc(p_s_test_bench ptestbench){
	p_s_my_struct ptr = my_malloc(ptestbench, sizeof(s_my_struct));
	increm_instruction_counter(ptestbench, 2);
	ptr->nom = NULL;
	ptr->prix = 0.0;
	return ptr;
}

void my_struct_free(p_s_test_bench ptestbench, p_s_my_struct ptr){
	increm_instruction_counter(ptestbench, 1);
	if(ptr != NULL){
		increm_instruction_counter(ptestbench, 1);
		if(ptr->nom != NULL)
			my_free(ptestbench, ptr->nom);
		my_free(ptestbench, ptr);
	}
}

void my_struct_tostring(p_s_test_bench ptestbench, p_s_my_struct ptr, char* str, size_t size_max){
	increm_instruction_counter(ptestbench, 1);
	if(ptr == NULL)
		snprintf(str, size_max, "NULL");
	else{
		increm_instruction_counter(ptestbench, 2);
		if(ptr->nom == NULL)
			snprintf(str, size_max, "Nom : NULL");
		else
			snprintf(str, size_max, "Nom : %10s(%.2f euros)", ptr->nom, ptr->prix);
	}
}

int my_struct_cmp_nom(p_s_test_bench ptestbench, p_s_my_struct pA, p_s_my_struct pB){
	increm_instruction_counter(ptestbench, 1);
	if(pA == NULL && pB == NULL) 
		return 0;
	increm_instruction_counter(ptestbench, 1);
	if(pA == NULL) 
		return -1;
	increm_instruction_counter(ptestbench, 1);
	if(pB == NULL)
		return 1;
	increm_instruction_counter(ptestbench, 1);
	if(pA->nom == NULL && pB->nom == NULL)
		return 0;
	increm_instruction_counter(ptestbench, 1);
	if(pA->nom == NULL)
		return -1;
	increm_instruction_counter(ptestbench, 1);
	if(pB->nom == NULL)
		return 1;
	increm_instruction_counter(ptestbench, 1);
	return my_strcmp(ptestbench, pA->nom, pB->nom);
}

int my_struct_cmp_prix(p_s_test_bench ptestbench, p_s_my_struct pA, p_s_my_struct pB){
	increm_instruction_counter(ptestbench, 1);
	if(pA == NULL || pB == NULL)
		return 0;
	increm_instruction_counter(ptestbench, 1);
	if(pA->prix < pB->prix)
		return -1;
	else {
		increm_instruction_counter(ptestbench, 1);
		if(pA->prix > pB->prix)
			return 1;
		else
			return 0;
	}
}

void my_struct_set_nom(p_s_test_bench ptestbench, p_s_my_struct ptr, const char * nom){
	increm_instruction_counter(ptestbench, 1);
	if(ptr == NULL || nom == NULL)
		return;
	increm_instruction_counter(ptestbench, 1);
	if(ptr->nom != NULL)
		my_free(ptestbench, ptr->nom);
	ptr->nom = my_malloc(ptestbench, my_strlen(ptestbench, nom)+1);
	increm_instruction_counter(ptestbench, 1);
	if(ptr->nom == NULL)
		return;
	increm_instruction_counter(ptestbench, 1);
	my_strcpy(ptestbench, ptr->nom, nom);
}

void my_struct_set_prix(p_s_test_bench ptestbench, p_s_my_struct ptr, float prix){
	increm_instruction_counter(ptestbench, 1);
	if(ptr == NULL)
		return;
	increm_instruction_counter(ptestbench, 1);
	ptr->prix = prix;
}

void my_struct_get_nom(p_s_test_bench ptestbench, p_s_my_struct ptr, char * nom){
	increm_instruction_counter(ptestbench, 1);
	if(ptr == NULL || ptr->nom == NULL || nom == NULL)
		return;
	increm_instruction_counter(ptestbench, 1);
	my_strcpy(ptestbench, nom, ptr->nom);
}

float my_struct_get_prix(p_s_test_bench ptestbench, p_s_my_struct ptr){
	increm_instruction_counter(ptestbench, 1);
	if(ptr == NULL)
		return 0.0;
	return ptr->prix;
}

void my_struct_init_rand(p_s_test_bench ptestbench, p_s_my_struct ptr){
	char str_temp[15];
	increm_instruction_counter(ptestbench, 1);
	if(ptr == NULL)
		return;
	my_struct_set_nom(ptestbench, ptr, rand_string(str_temp, rand_int(4, 10)));
	my_struct_set_prix(ptestbench, ptr, rand_float(1.0, 10.0));
}
