#include <stdio.h>
#include <stdlib.h>
#include <functional>

#include "List.h"


void addNodeToListAtEnd(ListNode *first,ListNode *toAdd) {
	auto getLastElementOfList = [&](ListNode *node) {
		return node->next == NULL;
	};
	ListNode *lastElement = listNodeRespects(first, getLastElementOfList);
	lastElement->next = toAdd;
	toAdd->next = NULL;
}
void addNodeToListAtStart(ListNode *first, ListNode *toAdd) {
	toAdd->next = first->next;
	first->next = toAdd;
}
void addNodeToList(ListNode *first, ListNode *toAdd, int toEnd) {
	if (toEnd) {
		addNodeToListAtEnd(first, toAdd);
	}
	else {
		addNodeToListAtStart(first, toAdd);
	}
}

int iterListUntil(ListNode *first, std::function<int(ListNode *)> iterMethod) {
	return listNodeRespects(first, iterMethod) != NULL;
}

int getLengthOfList(ListNode *first) {
	int counter = 0;
	auto incrementCounterMethod = [&](ListNode *node) {
		if (node->next != NULL) {
			counter++;
		}
		return 0;
	};
	listNodeRespects(first, incrementCounterMethod);
	return counter;
}

ListNode *listNodeRespects( ListNode *first, 
							std::function<int(ListNode *)> method) {
	ListNode *tmp = first;
	while (tmp != NULL) {
		ListNode *next = tmp->next;
		if (method(tmp)) {
			return tmp;
		}
		tmp = next;
	}
	return (ListNode *)NULL;
}

void removeNodeFromList(ListNode *first, 
	std::function<int (ListNode *)> findMethod,
	std::function<void(ListNode *)> freeMethod) {

	auto beforeNodeMethod = [&](ListNode *node) {
		return node != NULL && node->next != NULL 
					&& findMethod(node->next);
	};

	ListNode *beforeNode = listNodeRespects(first, beforeNodeMethod);
	if (beforeNode == NULL || beforeNode->next == NULL) {
		printf("nodul nu exista\n");
	}
	else {
		ListNode *toDeleteNode = beforeNode->next;
		beforeNode->next = toDeleteNode->next;
		freeMethod(toDeleteNode);
	}
}