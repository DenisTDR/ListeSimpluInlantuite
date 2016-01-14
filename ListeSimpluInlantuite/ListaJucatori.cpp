#include <string.h>
#include <stdio.h>

#include "List.h"
#include "ListaEchipe.h"
#include "ListaJucatori.h"

Player* buildPlayerWithName(char *name);

auto freePlayerMethod = [](ListNode *node) {
	Player *crt = (Player *)node;
	free(crt->name);
	free(node);
};

void adaugaJucatorLaEchipa(Team *echipa, Player *jucator, int laSfarsit) {
	if (echipa->firstPlayer == NULL) {
		echipa->firstPlayer = (Player*)malloc(sizeof(Player));
	}
	addNodeToList(echipa->firstPlayer, jucator, laSfarsit);
}

void adaugaJucatorLaEchipa(Team *echipa, char *name, int laSfarsit) {
	Player *toAdd = buildPlayerWithName(name);
	adaugaJucatorLaEchipa(echipa, toAdd, laSfarsit);
}

void afiseazaJucatori(Player *first) {
	auto afiseazaOEchipa = [](ListNode *node) {
		if (((Team *)node)->name != NULL) {
			printf("\t%s\n", ((Team *)node)->name);
		}
		return 0;
	};
	printf("     Jucatori:\n");
	iterListUntil(first, afiseazaOEchipa);
	printf("     ------\n");
}

void afiseazaJucatori(Team *echipa) {
	afiseazaJucatori(echipa->firstPlayer);
}

void stergeJucator(Player *first, char *name) {
	auto findMethod = [&](ListNode *node) {
		Player *crt = (Player *)node;
		if (crt->name == NULL) return false;
		return strcmp(crt->name, name) == 0;
	};

	removeNodeFromList(first, findMethod, freePlayerMethod);
}

void stergeJucator(Team *echipa, char *name) {
	stergeJucator(echipa->firstPlayer, name);
}

Player *cautaJucator(Player *first, char *name) {
	auto findMethod = [&](ListNode *node) {
		Player *crt = (Player *)node;
		if (crt->name == NULL) return false;
		return strcmp(crt->name, name) == 0;
	};
	Player *found = (Player *)listNodeRespects(first, findMethod);
	return found;
}

Player *cautaJucator(Team *echipa, char *name) {
	return cautaJucator(echipa->firstPlayer, name);
}

Player *cautaJucatorInListaDeEchipe(Team *first, char *name, Team **memberOf) {
	Player *foundPlayer = NULL;
	auto findPlayerMethod = [&](ListNode *node) {
		Player *crt = (Player *)node;
		if (crt == NULL || crt->name == NULL) {
			return false;
		}
		int result = strcmp(crt->name, name);
		if (result == 0) {
			foundPlayer = crt;
		}
		return result == 0;
	};

	auto findTeamMethod = [&](ListNode *node) {
		Team *team = (Team *)node;
		if (team == NULL || team->firstPlayer == NULL) {
			return false;
		}
		return listNodeRespects(team->firstPlayer, findPlayerMethod) != NULL;
	};

	*memberOf = (Team *)listNodeRespects(first, findTeamMethod);

	return foundPlayer;
}

void stergeJucatorDinListaDeEchipe(Team *first, char *name) {
	Player *beforePlayer = NULL;
	auto findBeforePlayerMethod = [&](ListNode *node) {
		
		Player *crt = (Player *)node;
		if (crt == NULL || crt->next == NULL) {
			return false;
		}

		Player *next = (Player *)crt->next;
		if (next == NULL || next->next == NULL) {
			return false;
		}

		int result = strcmp(next->name, name);
		if (result == 0) {
			beforePlayer = crt;
		}
		return result == 0;
	};

	auto findTeamMethod = [&](ListNode *node) {
		Team *team = (Team *)node;
		if (team == NULL || team->firstPlayer == NULL) {
			return false;
		}
		return listNodeRespects(team->firstPlayer, findBeforePlayerMethod) != NULL;
	};
	listNodeRespects(first, findTeamMethod);
	if (beforePlayer != NULL) {
		ListNode *toDelete = beforePlayer->next;
		beforePlayer->next = toDelete->next;
		freePlayerMethod(toDelete);
	}
}

Player* buildPlayerWithName(char *name) {
	Player *toRet = (Player*)malloc(sizeof(Player));
	toRet->next = NULL;
	toRet->name = (char*)malloc(strlen(name) + 1);
	strcpy(toRet->name, name);
	return toRet;
}


void stergeListaDeJucatori(Player *first) {
	auto iterMethod = [](ListNode *node) {
		freePlayerMethod(node);
		return 0;
	};
	iterListUntil(first, iterMethod);
}