#pragma once

#include <string>
#include "Bridges.h"
#include "BSTElement.h"
#include "tree.h"

class BSTWrapper {
public:
	BSTWrapper() 
	{
		nodeVector = new vector<BSTElement<char, string>*>();
	}

	// Rule of three
    BSTWrapper(const BSTWrapper &rhs) = delete;
    BSTWrapper operator=(const BSTWrapper &rhs) = delete;
    ~BSTWrapper() {
		for (int i = nodeVector->size() - 1; i >= 0; i--)
		{
			delete (*nodeVector)[i];
		}

		delete nodeVector;
    }

	void insert(const char c, BSTElement<char, string> *node)
	{
		if (!root)
		{
			root = new_node(c);
		}
		else if (c == node->getKey()) 	
		{

		}
		else if (c < node->getKey())
		{
			if (node->getLeft()) 
			{
				insert(c, node->getLeft());
			}
			else 
			{
				node->setLeft(new_node(c));
			}
		}
		else if (c > node->getKey())
		{
			if (node->getRight()) 
			{
				insert(c, node->getRight());
			}
			else 
			{
				node->setRight(new_node(c));
			}
		}
	}

private:
	BSTElement<char, string> *root = nullptr;
	vector<BSTElement<char, string>*>* nodeVector;

	BSTElement<char, string>* new_node(char c)
	{
		BSTElement<char, string>* newNode = new BSTElement<char, string>(c);
		
		string label = "Room: ";
		label.push_back(c);
		newNode->setLabel(label);
		
		nodeVector->push_back(newNode);
		
		return newNode;
	}
};
