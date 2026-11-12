#include <assert.h>
#include <stdio.h>
#include "pile.h"
#include "file.h"
#include "calculatrice.h"
static void test_pile(void){ Pile p; int x; pile_init(&p);
  assert(pile_est_vide(&p)); assert(pile_depiler(&p,&x)==-1);
  pile_empiler(&p,10); pile_empiler(&p,20); pile_empiler(&p,30);
  assert(pile_depiler(&p,&x)==0&&x==30); assert(pile_depiler(&p,&x)==0&&x==20); assert(pile_depiler(&p,&x)==0&&x==10);
  pile_detruire(&p); printf("test_pile : OK\n"); }
static void test_file(void){ File f; int x; file_init(&f);
  assert(file_est_vide(&f)); assert(file_defiler(&f,&x)==-1);
  file_enfiler(&f,1); file_enfiler(&f,2); file_enfiler(&f,3);
  assert(file_defiler(&f,&x)==0&&x==1); assert(file_defiler(&f,&x)==0&&x==2);
  file_enfiler(&f,4); assert(file_defiler(&f,&x)==0&&x==3); assert(file_defiler(&f,&x)==0&&x==4);
  file_detruire(&f); printf("test_file : OK\n"); }
static void test_postfixe(void){ int r;
  assert(evaluer_postfixe("3 4 + 5 *",&r)==0&&r==35);
  assert(evaluer_postfixe("6 2 / 3 - 4 *",&r)==0&&r==0);
  assert(evaluer_postfixe("2 3 +",&r)==0&&r==5);
  assert(evaluer_postfixe("5 1 2 + 4 * + 3 -",&r)==0&&r==14);
  assert(evaluer_postfixe("4 0 /",&r)==-1); assert(evaluer_postfixe("3 +",&r)==-1);
  assert(evaluer_postfixe("3 4 5 +",&r)==-1); assert(evaluer_postfixe("3 4 ?",&r)==-1);
  assert(evaluer_postfixe("",&r)==-1); printf("test_postfixe : OK\n"); }
static void test_parentheses(void){
  assert(parentheses_bien_formees("()")==1); assert(parentheses_bien_formees("([])")==1);
  assert(parentheses_bien_formees("{[()]}")==1); assert(parentheses_bien_formees("(a + b) * [c - {d}]")==1);
  assert(parentheses_bien_formees("")==1); assert(parentheses_bien_formees("(")==0);
  assert(parentheses_bien_formees(")")==0); assert(parentheses_bien_formees("([)]")==0);
  assert(parentheses_bien_formees("((())")==0); assert(parentheses_bien_formees("{[}]")==0);
  printf("test_parentheses : OK\n"); }
int main(void){ test_pile(); test_file(); test_postfixe(); test_parentheses(); printf("Tous les tests TP3 sont passes.\n"); return 0; }
