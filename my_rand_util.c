#include "my_rand_util.h"

#include <stdlib.h>

char *rand_string(char *chaine, int taille){
    for (int i = 0 ; i < taille ; i++) {
        chaine[i] = 'A' + rand_int(0, 26);
    }
    chaine[taille] = '\0';
    return chaine;
}

int rand_int(int a, int b){
	return a+rand()%(b-a);
}

float rand_float(float a, float b){
	return ((float)rand()/(float)(RAND_MAX)) * (b-a) + a;
}
