#include <iostream>
#include "List.h"
#include "从尾到头打印单链表.h"

int main() {
	ListNode* list = CreateList(5);
	PrintListReversingly(list);
	return 0;
}