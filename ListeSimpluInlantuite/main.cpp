#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#include "List.h"
#include "ListaEchipe.h"
#include "ListaJucatori.h"

void init(Team **first);

int main() {

	Team *prima = NULL;
	init(&prima);

	adaugaEchipa(prima, "prima echipa", 0);
	adaugaEchipa(prima, "a doua echipa", 1);
	adaugaEchipa(prima, "a treia echipa", 0);
	adaugaEchipa(prima, "a patra echipa", 1);

	printf("length: %d\n", getLengthOfList(prima));

	Team *oEchipa = cautaEchipa(prima, "a doua echipa");
	int exista = oEchipa != NULL;
	printf("rez: %d \n" , exista);

	stergeEchipa(prima, "prima echipa");

	if (exista) {
		adaugaJucatorLaEchipa(oEchipa, "un jucator", 1);
		afiseazaJucatori(oEchipa->firstPlayer);
		adaugaJucatorLaEchipa(oEchipa, "alt jucator", 0);
		afiseazaJucatori(oEchipa->firstPlayer);
		adaugaJucatorLaEchipa(oEchipa, "al treilea jucator", 1);
		afiseazaJucatori(oEchipa->firstPlayer);
		printf("length: %d\n", getLengthOfList(oEchipa->firstPlayer));
	}

	
	afiseazaEchipe(prima);
	stergeJucatorDinListaDeEchipe(prima, "alt jucator");
	afiseazaEchipe(prima);

	Team *inTeam;
	Player *gasit = cautaJucatorInListaDeEchipe(prima, "un jucator", &inTeam);

	if (gasit != NULL) {
		printf("\ngasit '%s' in echipa '%s'\n", gasit->name, inTeam->name);
	}
	else {
		printf("nu am gasit jucatorul cautat");
	}

	init(&prima);

	printf("\n\ndone!\n");
	getch();
	return 0;
}

void init(Team **first) {
	if (*first != NULL) {
		stergeListaDeEchipe(*first);
	}
	*first = (Team *)malloc(sizeof(Team));
	(*first)->name = NULL;
	(*first)->next = NULL;
	(*first)->firstPlayer = NULL;
}