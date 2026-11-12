#include <stdlib.h>
#include "pile.h"
void pile_init(Pile *p){ p->sommet=NULL; p->taille=0; }
int pile_empiler(Pile *p,int v){
  PNoeud *n=malloc(sizeof *n); if(!n) return -1;
  n->v=v; n->suiv=p->sommet; p->sommet=n; p->taille++; return 0;
}
int pile_depiler(Pile *p,int *out){
  PNoeud *n; if(!p->sommet) return -1;
  n=p->sommet; *out=n->v; p->sommet=n->suiv; free(n); p->taille--; return 0;
}
int pile_sommet(Pile *p,int *out){ if(!p->sommet) return -1; *out=p->sommet->v; return 0; }
int pile_est_vide(Pile *p){ return p->sommet==NULL; }
void pile_detruire(Pile *p){ int x; while(pile_depiler(p,&x)==0); }
