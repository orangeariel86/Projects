#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int maxsize = 26;
struct Node 
{
	Node* arr[maxsize];
	bool flag = false;
};

class Dictionary
{
public:
	ofstream outfile;
	//Constructor
	Dictionary();
	//Pre: Need a dictionary file that can be found
	//Post: Create a tree within the dictionary file. Will give a warn when it can't find a file
	Dictionary(string file);
	//Pre: Given a word
	//Post:Add the word to the tree
	void addWord(string word);
	//Pre: Given a word
	//Post: Check if the word is in the tree
	bool isWord(string word);
	//Pre: Given a word
	//Post:Check if there's simialar word in the tree
	bool isPrefix(string word);
	//Pre: numWords in the private is counting correctly
	//Post: return how many words are there
	int wordCount();

private:
	Node* root;
	int numWords;
};

Dictionary::Dictionary()
{
	root = nullptr;
	numWords = 0;
	outfile.open("output.txt");
}

Dictionary::Dictionary(string file)
{
	root = nullptr;
	numWords = 0;
	string dicword;
	ifstream infile;
	infile.open(file);
	if (!infile)
	{
		cout << "Can't open the file!!";
		return;
	}
	Node* tempNode = new Node;
	for (int i = 0; i < 26; i++)
	{
		tempNode->arr[i] = nullptr;
	}
	root = tempNode;
	while (getline(infile, dicword))
	{
		addWord(dicword);
	}
	infile.close();
}

void Dictionary::addWord(string word)
{
	if (root == nullptr)
	{
		Node* tempNode = new Node;
		for (int i = 0; i < 26; i++)
		{
			tempNode->arr[i] = nullptr;
		}
		root = tempNode;
	}
	Node* currNode = root;
	int wordsize = word.length();
	int index;
	for (int i = 0; i  < wordsize; i++)
	{
		index = word[i] - 'a';
		if (currNode->arr[index] == nullptr)
		{
			currNode->arr[index] = new Node();
			if (currNode->flag != true)
			{
				currNode->flag = false;
			}
		}
		currNode = currNode->arr[index];
	}
	numWords++;
	currNode->flag = true;
}

bool Dictionary::isWord(string word)
{
	if (root == nullptr)
	{
		Node* tempNode = new Node;
		for (int i = 0; i < 26; i++)
		{
			tempNode->arr[i] = nullptr;
		}
		root = tempNode;
	}
	Node* currNode = root;
	int wordsize = word.length();
	for (int i = 0; i < wordsize; i++)
	{
		if (currNode->arr[word[i] - 'a'] == nullptr)
		{
			return false;
		}
		currNode = currNode->arr[word[i] - 'a'];
	}
	return currNode->flag;
}

bool Dictionary::isPrefix(string word) 
{
	Node* currNode = root;
	int wordsize = word.length();
	for (int i = 0; i < wordsize; i++)
	{
		if (currNode->arr[word[i] - 'a'] == nullptr)
		{
			return false;
		}
		currNode = currNode->arr[word[i] - 'a'];
	}
	return true;
}

int Dictionary::wordCount()
{
	return numWords;
}