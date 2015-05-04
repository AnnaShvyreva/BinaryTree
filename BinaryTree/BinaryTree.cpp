// BinaryTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyBinaryTree.h"

void test1 ()
{
	MyBinaryTree<int>* myTree = new MyBinaryTree<int>(8);

	std::cout << "test1"  << std::endl;
	std::cout << *myTree  << std::endl;

	myTree->insert (3);
	myTree->insert (6);
	myTree->insert (1);	
	myTree->insert(4);
	myTree->insert(7);
	myTree->insert(10);
	myTree->insert(14);
	myTree->insert(13);

	bool b6 = myTree->find(6);
	std::cout << "6 " << b6 << std::endl;
	bool b4 = myTree->find(4);
	std::cout << "4 " << b4 << std::endl;

	std::cout << *myTree  << std::endl;

	myTree->remove(6);

	std::cout << *myTree  << std::endl;

	bool b6_1 = myTree->find(6);

	std::cout<< "6 "<< b6_1<<std::endl;

	delete myTree;
	myTree = NULL;
}

void test2()
{
	std::cout << "test2"  << std::endl;

	MyBinaryTree<int>* myTree = new MyBinaryTree<int>(5);

	std::cout << *myTree  << std::endl;

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

	std::cout << *myTree  << std::endl;

	myTree->remove(6);

	std::cout << *myTree  << std::endl;

	bool b6 = myTree->find(6);
	bool b4=myTree->find(4);
	bool b8=myTree->find(8);
	bool b1=myTree->find(1);
	bool b3=myTree->find(3);
	bool b14=myTree->find(14);
	bool b45=myTree->find(45);

	delete myTree;
	myTree = NULL;
}

void test3()
{
	std::cout << "test3"  << std::endl;

	MyBinaryTree<const char*>* myTree = new MyBinaryTree<const char*>("s");

	std::cout << *myTree  << std::endl;

	const char* aa = "b";
	myTree->insert(aa);
	myTree->insert("x");
	myTree->insert("b");
	myTree->insert("m");
	myTree->insert("a");

	std::cout << *myTree  << std::endl;

	myTree->remove("b");

	std::cout << *myTree  << std::endl;

	bool b45=myTree->find("a");
	bool b14=myTree->find("14");

	delete myTree;
	myTree = NULL;
}

void test4()
{
	std::cout << "test4"  << std::endl;

	MyBinaryTree<std::string>* myTree = new MyBinaryTree<std::string>("s");

	std::cout << *myTree << std::endl;

	myTree->insert("x");
	myTree->insert("b");
	myTree->insert("m");
	myTree->insert("a");

	std::cout << *myTree  << std::endl;

	myTree->remove("b");

	bool bb = myTree->find("b");
	bool ba = myTree->find("a");

	std::cout << *myTree  << std::endl;

	delete myTree;
	myTree = NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}


