#pragma once
#include <iostream>

template <class T> class MyBinaryTree
{
private:

	struct MyNode {
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
			//data = 0;
		};
	};

	MyNode* head;
	void prInsert (MyNode* node, T keyValue);
	void prRemove (MyNode* node, T keyValue); 
	bool prFind(MyNode* node, T const keyValue, bool& res);
	void infixTraverse (std::ostream& out, MyNode* node);

	MyNode* prGetParent(MyNode* node, T keyValue)
	{
		if ((max(node->data,keyValue)>0)&&(max(node->left->data,keyValue)!=0)) prGetParent(node->left, keyValue);
		else if ((max(node->data,keyValue)<0)&&(max(node->right->data,keyValue)!=0)) prGetParent(node->right, keyValue);
		else if (max(node->left->data,keyValue)==0) return node;
		else if (max(node->right->data,keyValue)==0) return node;
	}

//	MyNode* prGetParent(MyNode* node, const char* keyValue)
//	{
//		if ((max(node->data,keyValue)==1)&&(node->left->data != keyValue)) prGetParent(node->left, keyValue);
//		else if ((max(node->data,keyValue)==-1)&&(node->right->data != keyValue)) prGetParent(node->right, keyValue);
//		else if (node->left->data == keyValue) return node;
//		else if (node->right->data == keyValue) return node;
//	}

	MyNode* prFindLeft(MyNode* node)
	{
		if (node->left) prFindLeft(node->left);
		else return node;

		//return node; ////////////////////////////////////////////////////////////////////
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

	~MyBinaryTree()	{clear(); }
	
	void insert (T const keyValue); 
	void remove (T const keyValue);
	bool find (T const keyValue);
	MyNode& get_head(MyBinaryTree<T>& tree)
	{
		return tree.head;
	}

//	void assotiation (MyBinaryTree tree1, MyBinaryTree tree2);
//	void balancing (MyBinaryTree tree);

	MyNode* getParent(MyNode* node)
	{
		if (max(head->data,node->data)!=0) 
			prGetParent(head, node->data);
		else return nullptr;
		//return node; ////////////////////////////////////////////////////////////////////
	};

	void clear();
	void deleteTree(MyNode* node);

	friend std::ostream& operator << (std::ostream& out, MyBinaryTree<T>& tree)
	{
		if (tree.head != nullptr) 
			tree.infixTraverse(out, tree.head);
		return out;
	};

	int max (T const a, T const b);

};

template <class T> void MyBinaryTree<T>::clear()
{
	//deleteNode(head);
	deleteTree(head);
	head->data = NULL;
	head ->left = nullptr;
	head->right=nullptr;
	delete head;
	head = NULL;
}

template <class T> void MyBinaryTree<T>::deleteTree(MyNode* node)
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
	if(max(node->data,keyValue)==1)
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
	else if (max(node->data,keyValue)==-1)
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
	if (max(node->data,keyValue) == 1) 
	{
		prRemove(node->left, keyValue);
	}
	else if(max(node->data,keyValue) == -1)
	{
		prRemove(node->right, keyValue);
	}
	else if(max(node->data,keyValue) == 0)
	{
		if ((!node->left)&&(!node->right))
		{
			if (node == head)
				node ->deleteNode();
			else
			{
				MyNode* n = getParent(node);
				if (n->left == node) n->left = nullptr;
				else if (n->right == node) n->right = nullptr;
				node -> deleteNode();
			}
		}
		else if ((node->left)&&(!node->right))
		{
			if (node == head)
				head = node -> left;
			else
			{
				MyNode* n = getParent(node);
				if (max(n->left->data,node->data)==0) n->left = node->left;
				else if (n->right == node) n->right = node->left;
			}
			node -> deleteNode();	

		}
		else if ((!node->left)&&(node->right))
		{
			if (node == head)
				head = node -> right;
			else
			{
				MyNode* n = getParent(node);
				if (n->left == node) n->left = node->right;
				else if (n->right == node) n->right = node->right;
			}
			node -> deleteNode();			
		}
		else if ((node->left)&&(node->right))
		{
			if (!node->right->left)
			{
				node->data=node->right->data;
				MyNode* nn = node -> right;	
				node->right = node->right->right;
				delete nn;
			}
			else
			{
				MyNode* n = prFindLeft(node->right);
				T data = n -> data;
				
				this -> remove(n->data);
				node->data = data;
				//n->deleteNode();
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

template <class T> bool MyBinaryTree<T>::prFind(MyNode* node, T const keyValue, bool& res)
{
	if (max(node->data,keyValue) == 0) res=true;

	else if (max(keyValue, node->data)== -1) 
	{
		if (node->left) prFind(node->left, keyValue, res);
		else res=false;
	}
	else if (max(keyValue, node->data) == 1)
	{
		if (node->right) prFind(node->right, keyValue, res);
		else res=false;
	}
	return res;
}

template <class T> bool MyBinaryTree<T>::find(T const keyValue)
{
	bool res = NULL;
	if (!head) std::cout << "Tree is empty";
	else
	{
		return prFind(head, keyValue, res);
	}
	return false;
}

template <> void MyBinaryTree<std::string>::infixTraverse(std::ostream& out, MyNode* node)
{
	if (node)
	{
		if (node->left) infixTraverse(out, node->left);

		if (node->right) infixTraverse(out, node->right);

		out << node->data.c_str()<<" ";
	}
}

template <class T> void MyBinaryTree<T>::infixTraverse(std::ostream& out, MyNode* node)
{
	if (node)
	{
		if (node->left) infixTraverse(out, node->left);

		if (node->right) infixTraverse(out, node->right);

		out << node->data<<" ";
	}
}


template <> int MyBinaryTree<const char*>::max (const char* a, const char* b)
{		
	if (strcmp(a,b)>0) 
		return 1;
	else if (strcmp(a,b)<0)
		return -1;
	else return 0;
}

template <> int MyBinaryTree<std::string>::max(std::string a, std::string b)
{		
	if (strcmp(a.c_str(),b.c_str())>0) 
		return 1;
	else if (strcmp(a.c_str(),b.c_str())<0)
		return -1;
	else return 0;
}

template<class T> int MyBinaryTree<T>::max (T a, T b)
{		
	if (a>b) 
		return 1;
	else if (a<b)
		return -1;
	else return 0;
}