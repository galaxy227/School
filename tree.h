#pragma once

#include "/public/read.h"
#include "Bridges.h"
#include "BSTElement.h"

using namespace std;
using namespace bridges;

template <class T>
class Set {

private:
	struct Node {
		T data{};
		Node *left = nullptr, *right = nullptr;
		~Node() {
			delete left;
			delete right;
		}

		// Insert
		void insert(const T &t) {
			if (t == data) return;
			if (t < data) {
				if (left) left->insert(t);
				else left = new Node{t};
			}
			else {
				if (right) right->insert(t);
				else right = new Node{t};
			}
		}
	
		// Contains
		bool contains(const T &t) const {
			if (t == data) return true;
			if (t < data)
			{
				if (left) return left->contains(t);
				return false;
			}
			else {
				if (right) return right->contains(t);
				return false;
			}
		}

		// Search
		void search(const T &key) const {
			if (key == data) cout << "Found " << key << ". Retrace your steps to the entrance." << endl;
			else if (key < data)
			{
				cout << "Take the left door at the " << key << "." << endl; 
				return left->search(key);
			}
			else if (key > data)
			{
				cout << "Take the right door at the " << key << "." << endl; 
				return right->search(key);
			}
		}

		// Print
		void print() const {
			if (left) left->print();
			cout << data << endl;
			if (right) right->print();
		}
	} 

	*root = 0;
	size_t SIZE = 0;
	
	void copy_dungeon_to_bridges(vector<char> &v, Node* node)
	{
			if (!node) return;

			v.push_back(node->data);

			copy_dungeon_to_bridges(v, node->left);
			copy_dungeon_to_bridges(v, node->right);
	}

	public:
		Set() { }	

		// Rule of three
		Set(const Set &s2) = delete;
		Set operator=(const Set &s2) = delete;
		~Set() {
			delete root;
		}

		//Insert
		void insert(const T &t) {
			if (!SIZE or !root) {
				root = new Node{t};
				SIZE++;
			}

			root->insert(t);
		}
		
		//Erase
		void erase(const T &t) {}

		//Contains
		bool contains(const T &t) {
			if (!root) return false;

			return root->contains(t);
		}
	
		// Size
		size_t size() const { return SIZE; }
	
		// Print
		void print() const {
			if (root)
				root->print();
		}

		// Print directions
		void print_directions(const char &key)
		{
			if (root) root->search(key);
		}


	void get_bridges(vector<char> &v)
	{
		copy_dungeon_to_bridges(v, root);
	}
};
