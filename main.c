#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

int main()
{
   matrice_creuse mat ;
   int tab[N][M] ;
   // Init matrice (0 mis si i = j
   for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
      {
         tab[i][j] = i + j + 1 ;
         if (i == j)
            tab[i][j] = 0 ;
      }

   displayTab(tab) ;
   constructMat(mat, tab) ;
   displayMat(mat) ;
   int val = getValue(mat, 2, 1) ;
   printf("ligne 2 col 1 = %d\n", val) ;
   val = getValue(mat, 2, 2) ;
   printf("ligne 2 col 2 = %d\n", val) ;
   val = getValue(mat, 2, 9) ;
   printf("ligne 2 col 9 = %d\n", val) ;
   val = getValue(mat, 9, 2) ;
   printf("ligne 9 col 2 = %d\n", val) ;
   displayMat(mat) ;
   putValue(mat, 2, 3, 9) ;
   displayMat(mat) ;
   putValue(mat, 1, 2, 8) ;
   displayMat(mat) ;
   putValue(mat, 1, 1, 7) ;
   displayMat(mat) ;
   putValue(mat, 0, 0, 6) ;
   displayMat(mat) ;

   // Addition de matrices
   printf("\n\nADDITION\n\n") ;
   matrice_creuse m1, m2, m3 ;
   constructMat(m1, tab) ;
   displayMat(m1) ;
   constructMat(m2, tab) ;
   displayMat(m2) ;
   addMat(m1, m2, m3) ;
   displayMat(m3) ;

   /*
   liste_ligne liste = NULL ;
   for (int i = 0; i < N; i++)
   {
      liste_ligne ligne = malloc(sizeof(liste_ligne)) ;
      ligne->colonne = i;
      ligne->valeur  = 2 * i;
      ligne->suivant = liste;
      liste = ligne ;
   }

   //printf(" ==> Pt liste = %p\n", &liste) ;
   //displayLigne(liste) ;
*/

   return 0;
}
