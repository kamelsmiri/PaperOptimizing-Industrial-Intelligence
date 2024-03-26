#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct maillon {
	float valeur;
	struct maillon* suivant;
} *liste;

void insere_tete(liste* P,float val){
	liste P1 = (liste)malloc(sizeof(struct maillon));
	P1->valeur = val;
	P1->suivant = *P;
	*P = P1;
}

void afficher(liste P){
	if(P){
		printf("%g ",P->valeur);
		afficher(P->suivant);
	}
}

void afficher_inv(liste P){
	if(P){
		afficher_inv(P->suivant);
		printf("%g ",P->valeur);
	}
}

void main(){
	liste P = NULL;
	insere_tete(&P,1.3);
	insere_tete(&P,5.5);
	insere_tete(&P,7.2);
	printf("Liste P:\n");
	afficher(P);
	printf("Liste P inv:\n");
	afficher_inv(P);
}
