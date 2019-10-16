#include <iostream>

template <typename T>
struct BinaryTree
{
	BinaryTree(T value)
		: _value(value)
		, pleft(nullptr)
		, pright(nullptr)
	{}
	T _value;
	BinaryTree<T>* pleft;
	BinaryTree<T>* pright;
};


//根据前序和中序序列创建二叉树
template<typename T>
BinaryTree<T>* CreateTreeRecursion(T* startPreOrder, T* endPreOrder, T* startInOrder, T* endInOrder) {
	//创建根节点
	T rootvalue = startPreOrder[0];
	BinaryTree<T>* root = new BinaryTree<T>(rootvalue);

	//判断是不是只有一个节点
	if (startPreOrder == endPreOrder) {
		//判断前序序列和中序序列是否匹配
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return root;
		else
			throw std::exception("invalid input");
	}

	//找根节点在中序序列中的位置
	T* rootInOrder = startInOrder;
	while (startInOrder < endInOrder && *rootInOrder != rootvalue)
		++rootInOrder;
	//如果没有找到对应值，说明输入错误
	if (rootInOrder == endInOrder && *rootInOrder != rootvalue)
		throw std::exception("invalid input");

	//找到的位置左右分别为根节点的左右子树
	//左子树的节点个数
	int leftlength = rootInOrder - startInOrder;
	//前序序列中左子树的结束位置
	T* leftPreOrderEnd = startPreOrder + leftlength;

	//左子树长度大于0
	if (leftlength > 0) {
		root->pleft = CreateTreeRecursion<T>(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	}
	//右子树长度大于0
	if (leftlength < endPreOrder - startPreOrder) {
		root->pright = CreateTreeRecursion<T>(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}
	//左右子树节点个数都为0，返回根节点
	return root;
}

template<typename T>
BinaryTree<T>* CreateTree(T* PreOrder, T* InOrder, int length) {
	if (PreOrder == nullptr || InOrder == nullptr || length <= 0)
		return nullptr;
	return CreateTreeRecursion(PreOrder, PreOrder + length - 1, InOrder, InOrder + length - 1);
}