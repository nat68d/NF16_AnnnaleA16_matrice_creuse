#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

void constructMat(matrice_creuse m, int t[N][M])
{
   for (int i = 0; i < N; i++)
   {
      m[i] = NULL ;
      for(int j = M-1; j >= 0; j--)
      {
         if (t[i][j] != 0)
         {
            liste_ligne ligne = malloc(sizeof(Element)) ;
            if ( ! ligne ) return ;

            ligne->colonne = j;
            ligne->valeur  = t[i][j];
            ligne->suivant = m[i];
            m[i] = ligne ;
         }
     }
   }
}

void displayLigne(liste_ligne lst)
{
   for (liste_ligne liste = lst; liste != NULL; liste = liste->suivant)
      printf("C%d V=%d - ", liste->colonne, liste->valeur) ;
}

void displayMat(matrice_creuse m)
{
   printf("--- MATRICE : %d Lignes & %d Colonnes\n", N, M) ;
   for (int i = 0; i < N; i++)
   {
      printf("ligne = %d\n  ", i) ;
      displayLigne(m[i]) ;
      printf("\n") ;
   }
   printf("-------------------\n") ;
}

void displayTab(int tab[N][M])
{
   printf("--- TABLEAU : %d Lignes & %d Colonnes\n", N, M) ;
   for (int i = 0; i < N; i++)
   {
      printf("ligne = %d\n  ", i) ;
      for (int j = 0; j < M; j++)
         printf("C%d V=%d - ", j, tab[i][j]) ;
      printf("\n") ;
   }
   printf("-------------------\n") ;
}

int getValue(matrice_creuse m, int i, int j)
{
   if (i >= N)               // ATTENTION : toujours vérifier les indices de tableau
      return 0 ;
   liste_ligne lst = m[i] ; // ATTENTION : il faut impérativement utiliser une variabl etemporaire pour boucler
   while (lst && j != lst->colonne) // sinon tu réaffacetes m[i] à chaque tour de boucle (à la fin m[i] vaut NULL) !!!
      lst = lst->suivant;
   if (lst)                // ATTENTION : dans la matrice, toutes les colonnes ne sont pas présentes
      return lst->valeur;
   else                    // ATTENTION : gère le cas ou la valeur est 0 ET le cas où j > M
      return 0 ;
}

void putValue(matrice_creuse m, int i, int j, int val)
{
   if ( (i >= N) || (j >= M) )              // ATTENTION : toujours vérifier les indices de tableau
      return ;

   liste_ligne lst = m[i] ; // ATTENTION : il faut impérativement utiliser une variable temporaire pour boucler
   // On cherche si la colonne j existe déjà
   while (( lst ) && (lst->colonne != j))
      lst = lst->suivant ;

   if ( lst )
   {  // donc colonne j trouvée : valeur mise à jour
      if (val == 0)
      {
         // ATTENTION : si val == 0, il faut supprimer l'elt !!!
         lst->valeur = val ; // à supprimer cat il faut supprimer l'elt
      }
      else
         lst->valeur = val ;
   }
   else if (val != 0)
   {
      lst = m[i] ;
      liste_ligne precedent = lst ;
      while(lst && lst->colonne < j)
      {
         precedent = lst ;
         lst = lst->suivant ;
      }

      liste_ligne newEl = malloc(sizeof(Element));
      newEl->colonne = j;
      newEl->valeur  = val;

      if (lst == m[i]) // Marche si insertion en tête ou bien si m[i] est NULL (liste vide)
      {
         m[i] = newEl ;
         newEl->suivant = lst ;
      }
      else
      {
         precedent->suivant = newEl ;
         newEl->suivant = lst ;
      }
   }
}

void addMat(matrice_creuse m1, matrice_creuse m2, matrice_creuse m3)
{
   for (int i = 0; i < N; i++)
   {
      m3[i] = NULL ; // A ne pas oublier, sinon ça plante !!!
      for (int j = 0; j < M; j++)
         putValue(m3, i, j, getValue(m1, i, j) + getValue(m2, i, j)) ;
   }
}
