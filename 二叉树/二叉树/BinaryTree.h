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


//����ǰ����������д���������
template<typename T>
BinaryTree<T>* CreateTreeRecursion(T* startPreOrder, T* endPreOrder, T* startInOrder, T* endInOrder) {
	//�������ڵ�
	T rootvalue = startPreOrder[0];
	BinaryTree<T>* root = new BinaryTree<T>(rootvalue);

	//�ж��ǲ���ֻ��һ���ڵ�
	if (startPreOrder == endPreOrder) {
		//�ж�ǰ�����к����������Ƿ�ƥ��
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return root;
		else
			throw std::exception("invalid input");
	}

	//�Ҹ��ڵ������������е�λ��
	T* rootInOrder = startInOrder;
	while (startInOrder < endInOrder && *rootInOrder != rootvalue)
		++rootInOrder;
	//���û���ҵ���Ӧֵ��˵���������
	if (rootInOrder == endInOrder && *rootInOrder != rootvalue)
		throw std::exception("invalid input");

	//�ҵ���λ�����ҷֱ�Ϊ���ڵ����������
	//�������Ľڵ����
	int leftlength = rootInOrder - startInOrder;
	//ǰ���������������Ľ���λ��
	T* leftPreOrderEnd = startPreOrder + leftlength;

	//���������ȴ���0
	if (leftlength > 0) {
		root->pleft = CreateTreeRecursion<T>(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	}
	//���������ȴ���0
	if (leftlength < endPreOrder - startPreOrder) {
		root->pright = CreateTreeRecursion<T>(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}
	//���������ڵ������Ϊ0�����ظ��ڵ�
	return root;
}

template<typename T>
BinaryTree<T>* CreateTree(T* PreOrder, T* InOrder, int length) {
	if (PreOrder == nullptr || InOrder == nullptr || length <= 0)
		return nullptr;
	return CreateTreeRecursion(PreOrder, PreOrder + length - 1, InOrder, InOrder + length - 1);
}