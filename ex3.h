#ifndef EX3_H_INCLUDED
#define EX3_H_INCLUDED
#define N 3
#define M 4

typedef struct Element Element;
struct Element
{
   int colonne;
   int valeur;
   Element* suivant;
};
typedef Element* liste_ligne;
typedef liste_ligne  matrice_creuse[N];

void constructMat(matrice_creuse m, int t[N][M]);
void displayLigne(liste_ligne lst);
void displayTab(int tab[N][M]);
void displayMat(matrice_creuse m);
int getValue(matrice_creuse m, int i, int j);
void putValue(matrice_creuse m, int i, int j, int val);
void addMat(matrice_creuse m1, matrice_creuse m2, matrice_creuse m3);

#endif // EX3_H_INCLUDED
