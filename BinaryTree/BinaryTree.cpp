// BinaryTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyBinaryTree.h"


int _tmain(int argc, _TCHAR* argv[])
{
	MyBinaryTree<int>* myTree = new MyBinaryTree<int>(8);


	myTree->insert (3);
	myTree->insert (6);
	myTree->insert (1);	
	myTree->insert(4);
//	myTree->insert(7);
//	myTree->insert(10);
//	myTree->insert(14);
//	myTree->insert(13);

	//delete myTree;
	myTree->remove(6);

	return 0;
}

