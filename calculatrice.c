#include <stdlib.h>
#include <string.h>
#include "pile.h"
#include "calculatrice.h"
static int est_ouvrant(char c){ return c=='('||c=='['||c=='{'; }
static int vont_ensemble(char o,char f){
  if(o=='('&&f==')') return 1; if(o=='['&&f==']') return 1; if(o=='{'&&f=='}') return 1; return 0;
}
int parentheses_bien_formees(const char *expr){
  Pile p; int i,ouvert; pile_init(&p);
  for(i=0;expr[i]!='\0';i++){ char c=expr[i];
    if(est_ouvrant(c)){ if(pile_empiler(&p,c)!=0){ pile_detruire(&p); return 0; } }
    else if(c==')'||c==']'||c=='}'){
      if(pile_depiler(&p,&ouvert)!=0){ pile_detruire(&p); return 0; }
      if(!vont_ensemble((char)ouvert,c)){ pile_detruire(&p); return 0; }
    }
  }
  i=pile_est_vide(&p); pile_detruire(&p); return i;
}
int evaluer_postfixe(const char *expr,int *resultat){
  Pile p; char copie[256]; char *jeton; int ok=0; pile_init(&p);
  strncpy(copie,expr,sizeof(copie)-1); copie[sizeof(copie)-1]='\0';
  jeton=strtok(copie," \t\n");
  while(jeton!=NULL){
    if((jeton[0]>='0'&&jeton[0]<='9')||(jeton[0]=='-'&&jeton[1]>='0'&&jeton[1]<='9')){
      if(pile_empiler(&p,atoi(jeton))!=0) goto fin;
    } else if(strlen(jeton)==1&&(jeton[0]=='+'||jeton[0]=='-'||jeton[0]=='*'||jeton[0]=='/')){
      int b,a,res;
      if(pile_depiler(&p,&b)!=0||pile_depiler(&p,&a)!=0) goto fin;
      if(jeton[0]=='+') res=a+b; else if(jeton[0]=='-') res=a-b; else if(jeton[0]=='*') res=a*b;
      else { if(b==0) goto fin; res=a/b; }
      if(pile_empiler(&p,res)!=0) goto fin;
    } else goto fin;
    jeton=strtok(NULL," \t\n");
  }
  if(pile_depiler(&p,resultat)!=0) goto fin;
  if(!pile_est_vide(&p)) goto fin;
  ok=1;
fin: pile_detruire(&p); return ok?0:-1;
}
