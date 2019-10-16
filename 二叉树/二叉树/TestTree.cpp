#include "BinaryTree.h"
//前序遍历
template<typename T>
void PreOrderPrintTree(BinaryTree<T>* root) {
	if (root == nullptr)
		return;
	std::cout << root->_value << "->";
	PreOrderPrintTree(root->pleft);
	PreOrderPrintTree(root->pright);
}

//中序遍历
template<typename T>
void InOrderPrintTree(BinaryTree<T>* root) {
	if (root == nullptr)
		return;
	InOrderPrintTree(root->pleft);
	std::cout << root->_value << "->";
	InOrderPrintTree(root->pright);
}

//后序遍历
template<typename T>
void PostOrderPrintTree(BinaryTree<T>* root) {
	if (root == nullptr)
		return;
	PostOrderPrintTree(root->pleft);
	PostOrderPrintTree(root->pright);
	std::cout << root->_value << "->";
}



int main() {
	int PreOrder[] = { 1,2,4,7,3,5,6,8 };
	int InOrder[] = { 4,7,2,1,5,3,8,6 };
	/*char PreOrder[] = {'a'};
	char InOrder[] = {'a'};*/
	BinaryTree<int>* tree = CreateTree(PreOrder, InOrder, sizeof(PreOrder) / sizeof(PreOrder[0]));
	PreOrderPrintTree(tree);
	std::cout << std::endl;
	InOrderPrintTree(tree);
	std::cout << std::endl;
	PostOrderPrintTree(tree);
	std::cout << std::endl;
	return 0;
}