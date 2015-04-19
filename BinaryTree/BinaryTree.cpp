// BinaryTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyBinaryTree.h"


int _tmain(int argc, _TCHAR* argv[])
{

/* тест 1 

    MyBinaryTree<int>* myTree = new MyBinaryTree<int>(8);
	myTree->insert (3);
	myTree->insert (6);
	myTree->insert (1);	
	myTree->insert(4);
	myTree->insert(7);
	myTree->insert(10);
	myTree->insert(14);
	myTree->insert(13);

	bool b6 = myTree->find(6);
	bool b4=myTree->find(4);

	myTree->remove(6);

	bool b6_1 = myTree->find(6);
*/

/*тест 2 
	MyBinaryTree<int>* myTree = new MyBinaryTree<int>(5);

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

	myTree->remove(6);

	bool b6 = myTree->find(6);
	bool b4=myTree->find(4);
	bool b8=myTree->find(8);
	bool b1=myTree->find(1);
	bool b3=myTree->find(3);
	bool b14=myTree->find(14);
	bool b45=myTree->find(45);
*/

/*тест 3

	MyBinaryTree<const char*>* myTree = new MyBinaryTree<const char*>("s");

	const char* aa = "b";
	myTree->insert(aa);
	myTree->insert("x");
	myTree->insert("b");
	myTree->insert("m");
	myTree->insert("a");

	myTree->remove("b");

	bool b45=myTree->find("a");
	bool b14=myTree->find("14");
*/

/*тест 4 */

	MyBinaryTree<std::string>* myTree = new MyBinaryTree<std::string>("s");

	myTree->insert("x");
	myTree->insert("b");
	myTree->insert("m");
	myTree->insert("a");

	myTree->remove("b");

	bool bb = myTree->find("b");
	bool ba = myTree->find("a");
//*/

	std::cout << *myTree ;

//	delete myTree;
//	myTree = NULL;

	return 0;
}

