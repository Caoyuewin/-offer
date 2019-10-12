#pragma once
#include <iostream>

struct ListNode {
	ListNode(int value)
		:_value(value)
		,_pNext(nullptr)
	{}
	int _value;
	ListNode* _pNext;
};

ListNode* CreateList(int length) {
	ListNode* pHead = new ListNode(0);
	ListNode* node = pHead;
	while (length) {
		int value;
		std::cin >> value;
		ListNode* newnode = new ListNode(value);
		node->_pNext = newnode;
		node = node->_pNext;
		--length;
	}
	ListNode* pRet = pHead->_pNext;
	delete pHead;
	pHead = nullptr;
	return pRet;
}