#ifndef FILE_H
#define FILE_H
#include <stddef.h>
typedef struct FNoeud { int v; struct FNoeud *suiv; } FNoeud;
typedef struct { FNoeud *tete; FNoeud *queue; size_t taille; } File;
void file_init(File *f);
int file_enfiler(File *f,int v);
int file_defiler(File *f,int *out);
int file_est_vide(File *f);
void file_detruire(File *f);
#endif
