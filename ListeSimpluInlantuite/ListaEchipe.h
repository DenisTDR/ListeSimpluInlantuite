#pragma once

#include "List.h"


typedef struct Team : ListNode {
	char *name;
	struct Player *firstPlayer;
}Team;

void adaugaEchipa(Team *first, Team *toAdd, int laSfarsit = 0);
void adaugaEchipa(Team *first, char *name, int laSfarsit = 0);

void afiseazaEchipe(Team *first);

void stergeEchipa(Team *first, char *name);
void stergeListaDeEchipe(Team *first);

Team *cautaEchipa(Team *first, char *name);