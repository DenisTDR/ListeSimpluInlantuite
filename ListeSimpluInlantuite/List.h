
#include <functional>

#pragma once

typedef struct ListNode {
	ListNode() : next(NULL) {}
	ListNode *next;
}ListNode;

void addNodeToList(ListNode *first, ListNode *toAdd, int toEnd = 0);

int iterListUntil(ListNode *first, std::function<int(ListNode *)> iterMethod);

int getLengthOfList(ListNode *first);

int listContainsNode(ListNode *nodeToFind, ListNode *first, 
	int(*areListNodesEqual)(ListNode *, ListNode *));

void removeNodeFromList(ListNode *first,
	std::function<int(ListNode *)> findMethod,
	std::function<void(ListNode *)> freeMethod);

ListNode *listNodeRespects(ListNode *first, std::function<int(ListNode *)> method);