#include <string.h>
#include <stdio.h>

#include "List.h"
#include "ListaEchipe.h"
#include "ListaJucatori.h"

Team* buildTeamWithName(char *name);

auto freeTeamMethod = [](ListNode *node) {
	Team *crt = (Team *)node;
	free(crt->name);
	stergeListaDeJucatori(crt->firstPlayer);
	free(node);
};
auto teamHasNameMethod = [&](ListNode *node, char *name) {
	Team *crt = (Team *)node;
	if (crt->name == NULL) return false;
	return strcmp(crt->name, name) == 0;
};

void adaugaEchipa(Team *first, Team *toAdd, int laSfarsit) {
	addNodeToList(first, toAdd, laSfarsit);
}

void adaugaEchipa(Team *first, char *name, int laSfarsit) {
	Team *toAdd = buildTeamWithName(name);
	adaugaEchipa(first, toAdd, laSfarsit);
}

Team* buildTeamWithName(char *name) {
	Team *toRet = (Team*)malloc(sizeof(Team));
	toRet->next = NULL;
	toRet->firstPlayer = (Player *)malloc(sizeof(Player));
	toRet->firstPlayer->next = NULL;
	toRet->firstPlayer->name = NULL;
	toRet->name = (char*)malloc(strlen(name) + 1);
	strcpy(toRet->name, name);
	return toRet;
}

void afiseazaEchipe(Team *first) {
	auto afiseazaOEchipa = [](ListNode *node) {
		Team *echipa = (Team *)node;
		if (echipa->name != NULL) {
			printf("    %s\n", echipa->name);
			afiseazaJucatori(echipa->firstPlayer);
		}
		return 0;
	};
	printf("  Echipe:\n");
	iterListUntil(first, afiseazaOEchipa);
	printf("  ------\n");
}

Team *cautaEchipa(Team *first, char *name) {
	auto findMethod = [&](ListNode *node) {
		return teamHasNameMethod(node, name);
	};
	return (Team *)listNodeRespects(first, findMethod);
}

void stergeEchipa(Team *first, char *name) {
	auto findMethod = [&](ListNode *node) {
		return teamHasNameMethod(node, name);
	};
	removeNodeFromList(first, findMethod, freeTeamMethod);
}	

void stergeListaDeEchipe(Team *first) {
	auto iterMethod = [](ListNode *node) {
		freeTeamMethod((Team *)node);
		return 0;
	};
	iterListUntil(first, iterMethod);
}