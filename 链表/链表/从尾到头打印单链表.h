#include <iostream>
#include <stack>
#include "List.h"

void PrintListReversingly(ListNode* pHead) {
	std::stack<ListNode*> nodestack;

	ListNode* tmp = pHead;
	while (tmp != nullptr) {
		nodestack.push(tmp);
		tmp = tmp->_pNext;
	}

	while (!nodestack.empty()) {
		std::cout << nodestack.top()->_value;
		nodestack.pop();
	}
	std::cout << std::endl;
}