#ifndef __MY_RAND_UTIL_H__
#define __MY_RAND_UTIL_H__

/* generation de chaine aleatoire de 'taille' majuscules */
char *rand_string(char *chaine, int taille);

/* generation d'un entier aleatoire entre a (inclus) et b(exclu) */
int rand_int(int a, int b);

/* generation d'un reel aleatoire entre a (inclus) et b(inclus) */
float rand_float(float a, float b);

#endif //__MY_RAND_UTIL_H__
