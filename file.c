#include <stdlib.h>
#include "file.h"
void file_init(File *f){ f->tete=NULL; f->queue=NULL; f->taille=0; }
int file_enfiler(File *f,int v){
  FNoeud *n=malloc(sizeof *n); if(!n) return -1;
  n->v=v; n->suiv=NULL;
  if(f->queue) f->queue->suiv=n; else f->tete=n;
  f->queue=n; f->taille++; return 0;
}
int file_defiler(File *f,int *out){
  FNoeud *n; if(!f->tete) return -1;
  n=f->tete; *out=n->v; f->tete=n->suiv;
  if(!f->tete) f->queue=NULL;
  free(n); f->taille--; return 0;
}
int file_est_vide(File *f){ return f->tete==NULL; }
void file_detruire(File *f){ int x; while(file_defiler(f,&x)==0); }
