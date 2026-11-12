# TD 3 - Piles et files - IDANI Lindsey Kadidjatou Alicia, L2 IIRT, ESGIS
## Q1. Verifier qu une expression est bien parenthesee
Principe : on parcourt de gauche a droite avec une pile vide.
- ouvrant ( [ { -> on empile
- fermant ) ] } -> on depile et on verifie que ca correspond. Si pile vide ou pas pareil, c est faux.
- autres caracteres on les ignore.
A la fin pile doit etre vide. Sinon un ouvrant n a jamais ete ferme.
Exemple : ([)] est faux. On empile (, puis [, puis on voit ) : on depile [, et [ ne va pas avec ), donc mal imbrique.
Complexite : O(n) en temps, O(n) en memoire pire cas.
Code dans calculatrice.c, fonction parentheses_bien_formees.
## Q2. Une file avec deux piles
On prend deux piles : entree et sortie.
- Enfiler x : on empile x dans entree. O(1).
- Defiler : si sortie est vide, on depile tout entree et on empile dans sortie. Ca retourne l ordre. Ensuite on depile le sommet de sortie.
Exemple : on enfile 1,2,3 puis on defile : entree = [1,2,3] (3 au sommet), sortie = []
defiler : on vide entree dans sortie -> sortie = [3,2,1] (1 au sommet)
on depile sortie -> on sort 1, c est bien le premier arrive.
Complexite : enfiler O(1). Defiler O(1) la plupart du temps, O(n) quand transfert. En moyenne O(1).
Je n ai pas code cette variante dans le TP3 car le TP demande la file par liste chainee (tete + queue), plus simple et toujours O(1).
## Q3. Evaluer a la main : 6 2 / 3 - 4 *
6 -> pile [6]
2 -> pile [6,2]
/ -> 6/2=3 -> pile [3]
3 -> pile [3,3]
- -> 3-3=0 -> pile [0]
4 -> pile [0,4]
* -> 0*4=0 -> pile [0]
Resultat : 0. C est aussi ce que donne mon programme.
