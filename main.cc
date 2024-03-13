#include <string>
#include "Bridges.h"
#include "BSTElement.h"
#include "bst_wrapper.h"
#include "tree.h"

using namespace std;
using namespace bridges;

void SetBridges(Set<char>* &dungeon) 
{
	Bridges bridges(1, "galaxy227", "818750556369");

	bridges.setTitle("Dungeon");
	bridges.setDescription("This is the created dungeon");	

	vector<char> v;
	dungeon->get_bridges(v);

	BSTElement<char, string> *root = new BSTElement<char, string>(v.at(0));
	BSTWrapper* wrapper = new BSTWrapper();
	
	for (char c : v)
	{
		wrapper->insert(c, root);
	}

	bridges.setDataStructure(root);

	bridges.visualize();

	delete wrapper;
	delete root;
}

bool is_solvable(Set<char>* dungeon, string password)
{
	for (char c : password)
	{
		if (!dungeon->contains(c)) return false;
	}

	return true;
}

int main(int argc, char **argv) {
	Set<char>* dungeon = new Set<char>();

	// Get dungeon
	cout << "Enter the dungeon layout: " << endl;

	string input;

	while (dungeon->size() < 1)
	{
		cin >> input;

		for (char letter : input)
		{
			if (!isalpha(letter)) break;
			
			dungeon->insert(toupper(letter));
		}

		if (dungeon->size() < 1) cout << "Invalid input! Please enter string of alphabetical characters followed by a number." << endl;
	}

	// Get password
	cout << "Enter character for password: " << endl;

	char c;
	vector<char>* passwordVector = new vector<char>();
	Set<char>* passwordSet = new Set<char>();

	while (cin >> c)
	{
		if (c == EOF) break;
		if (!isalpha(c)) break;

		if (!passwordSet->contains(toupper(c))) passwordVector->push_back(toupper(c));
		passwordSet->insert(toupper(c));
	}

	string password;

	for (char ch : *passwordVector)
	{
		password.push_back(ch);
	}

	// Check solvable
	if (is_solvable(dungeon, password))
	{
		for (char c : password)
		{
			if (isalpha(c)) dungeon->print_directions(c);	
		}

		cout << "Exit the dungeon!" << endl;
	}
	else 
	{
		cout << "NOT SOLVABLE" << endl;
	}

	// Visualize dungeon with Bridges API
	SetBridges(dungeon);

	// Clean memory
	delete dungeon;
	delete passwordVector;
	delete passwordSet;

	return 0;
}
