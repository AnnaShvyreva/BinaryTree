#pragma once
#include <iostream>

template <class T> class MyBinaryTree
{
private:

	struct MyNode {
		//MyDate date;
		T data;
		MyNode* left;
		MyNode* right;
		//MyNode* parent;

		MyNode(T newData, MyNode* newLeft, MyNode* newRight) : 
			data(newData), left(newLeft), right(newRight) {}

		MyNode(T newData) : data(newData), left(nullptr), right(nullptr){}

		void deleteNode()
		{
			if (left) 
			{
				left = nullptr;
			}
			if (right)
			{
				right = nullptr;
			}
			data = NULL;
			delete this;
		};
	};

	MyNode* head;
	void prInsert (MyNode* node, T keyValue); 
	void prRemove (MyNode* node, T keyValue); 
	T& prFind(MyNode* node, T const keyValue);

	MyNode* prGetParent(MyNode* node, T keyValue)
	{
		if ((node->data>keyValue)&&(node->left->data != keyValue)) prGetParent(node->left, keyValue);
		else if ((node->data<keyValue)&&(node->right->data != keyValue)) prGetParent(node->right, keyValue);
		else if (node->left->data == keyValue) return node;
		else if (node->right->data == keyValue) return node;
	}

	MyNode* prFindLeft(MyNode* node)
	{
		if (node->left) prFindLeft(node->left);
		else return node;
	}

public:

	MyBinaryTree() 
	{
		head = nullptr;
	}

	MyBinaryTree(T keyValue)
	{
		head = new MyNode(keyValue);
	}

	~MyBinaryTree() { clear(); }
	
	void insert (T const keyValue); 
	void remove (T const keyValue);
	T& find (T const keyValue);
	void infixTraverse (MyBinaryTree tree);
	void assotiation (MyBinaryTree tree1, MyBinaryTree tree2);
	void balancing (MyBinaryTree tree);

	MyNode* getParent(MyNode* node)
	{
		if (head->data == node->data) return nullptr;
		else prGetParent(head, node->data);
	};

	void clear();
	void deleteTree(MyNode node);

};

template <class T> void MyBinaryTree<T>::clear()
{
	//deleteNode(head);
	deleteTree(head);
	delete head;
}

template <class T>
void MyBinaryTree<T>::deleteTree(MyNode node)
{
	if (node -> left) 
			{
				deleteTree(node->left);
				delete node->left;
			}
			if (node->right)
			{
				deleteTree(node->right);
				delete node->right;
			}
}

template <class T> void MyBinaryTree<T>::prInsert (MyNode* node, T keyValue)
{
	if((node->data)>keyValue)
	{
		if (!node->left)
		{
			node->left = new MyNode(keyValue);
		}
		else
		{
			prInsert(node->left, keyValue);
		}
	}
	else if ((node->data)<keyValue)
	{
		if (!node->right)
		{
			node->right = new MyNode(keyValue);	
		}
		else
		{
			prInsert(node->right, keyValue);
		}
	}
}

template <class T> void MyBinaryTree<T>::insert (T const keyValue)
{
	if (!head)
	{
		head = new MyNode(keyValue);
	}
	else
	{
		prInsert(head, keyValue);
	}
	
}

template <class T> void MyBinaryTree<T>::prRemove(MyNode* node, T keyValue)
{
	if (keyValue < node->data) 
	{
		prRemove(node->left, keyValue);
	}
	else if(keyValue > node->data)
	{
		prRemove(node->right, keyValue);
	}
	else if(keyValue == node->data)
	{
		if ((!node->left)&&(!node->right))
		{
			MyNode* n = getParent(node);
			if (n->left == node) n->left = nullptr;
			else if (n->right == node) n->right = nullptr;
			node -> deleteNode();
		}
		else if ((node->left)&&(!node->right))
		{
			MyNode* n = getParent(node);
			if (n->left->data == node->data) n->left = node->left;
			else if (n->right == node) n->right = node->left;

			node -> deleteNode();			
		}
		else if ((!node->left)&&(node->right))
		{
			MyNode* n = getParent(node);
			if (n->left == node) n->left = node->right;
			else if (n->right == node) n->right = node->right;

			node -> deleteNode();			
		}
		else if ((node->left)&&(node->right))
		{
			if (!node->right->left)
			{
				node->right->left = node->left;

				MyNode* n = getParent(node);
				if (n->left == node) n->left = node->right;
				else if (n->right == node) n->right = node->right;

				node -> deleteNode();	
			}
			else
			{
				MyNode* n = prFindLeft(node->right);
				node->data = n -> data;
				n->deleteNode();
			}
		}

	}
}

template <class T> void MyBinaryTree<T>::remove (T const keyValue)
{
	if (head)
	{
		prRemove(head, keyValue);
	}
}

template <class T> T& MyBinaryTree<T>::prFind(MyNode* node, T const keyValue)
{
	if (node->data == keyValue) return node;
	else if (keyValue < node->data) prFind(node->left, keyValue);
	else if (keyValue > node->data) prFind(node->right, keyValue);
}

template <class T> T& MyBinaryTree<T>::find(T const keyValue)
{
	if (!head) std::cout << "Tree is empty";
	else
	{
		prFind(head, keyValue);
	}
}

template <class T> void MyBinaryTree<T>::infixTraverse(MyBinaryTree tree)
{
	if (head)
	{
		if (head->left) infixTraverse(head->left);
		else std::cout << head->data<<" ";

		if (head->right) infixTraverse(head->right);
		else std::cout << head->data<<" ";
	}
}