#pragma once

#include "List.h"


typedef struct Player : ListNode {
	char *name;
	int inaltime;
}Player;

void adaugaJucatorLaEchipa(Team *echipa, Player *jucator, int laSfarsit = 0);
void adaugaJucatorLaEchipa(Team *echipa, char *nume, int laSfarsit = 0);

void afiseazaJucatori(Player *first);
void afiseazaJucatori(Team *echipa);

void stergeJucator(Player *first, char *name);
void stergeJucator(Team *echipa, char *name);
void stergeJucatorDinListaDeEchipe(Team *first, char *name);
void stergeListaDeJucatori(Player *first);

Player *cautaJucator(Player *first, char *name);
Player *cautaJucator(Team *echipa, char *name);

Player *cautaJucatorInListaDeEchipe(Team *first, char *name, Team **memberOf);