// BinaryTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyBinaryTree.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//MyBinaryTree<int>* myTree = new MyBinaryTree<int>(8);
	MyBinaryTree<int>* myTree = new MyBinaryTree<int>(5);


//	myTree->insert (3);
//	myTree->insert (6);
//	myTree->insert (1);	
//	myTree->insert(4);
//	myTree->insert(7);
//	myTree->insert(10);
//	myTree->insert(14);
//	myTree->insert(13);

	myTree->insert (1);
	myTree->insert (0);
	myTree->insert (3);
	myTree->insert (2);
	myTree->insert (4);
	myTree->insert (10);
	myTree->insert (100);
	myTree->insert (8);
	myTree->insert (9);
	myTree->insert (6);
	myTree->insert (7);

	myTree->remove(5);


	//delete myTree;
//	myTree->remove(6);

	bool b6 = myTree->find(6);
	bool b4=myTree->find(4);
//	bool b8=myTree->find(8);
//	bool b1=myTree->find(1);
//	bool b3=myTree->find(3);
//	bool b14=myTree->find(14);
//	bool b45=myTree->find(45);

//	delete myTree;
//	myTree = NULL;

	std::cout << *myTree ;

	return 0;
}

