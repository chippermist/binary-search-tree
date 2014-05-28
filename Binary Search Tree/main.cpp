//main.cpp - main for Binary Search Tree
//Written by Chinmay Garg

#include <iostream>
#include <string>
#include "TreeNode.h"

using namespace std;

void main()
{
	string inputSentence;
	string deleteWord;

	cout << "Enter input sentence: ";
	TreeNode<string>* treeRoot = NULL;
	//peek() function takes in the strings until there are strings to take in
	//stops when the next stting is null
	//does not count spaces
	while(cin.peek() != '\n')
	{
		cin >> inputSentence;
		Insert(treeRoot, inputSentence);
	}
	//prints the Tree
	Transversal(treeRoot);

	cout << "Enter a word to delete: ";
	cin >> deleteWord;
	//deletes the word specified and then prints the Tree
	Delete(treeRoot, deleteWord);
	Transversal(treeRoot);

	system("pause");
}