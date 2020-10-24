#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"
using namespace std;

int numWords = 0;
void SolveBoard(string board[4][4], int count, Dictionary& dict, Dictionary& wordsFound, bool printBoard);

int main()
{
	string board[4][4];
	
	int count = 1;
	Dictionary dict("dictionary.txt");
	cout << dict.wordCount() << " words loaded." << endl << endl;
	
	string word;
	Dictionary wordsFound;
	wordsFound.outfile;
	cout << "Enter Board\n";
	cout << "-----------\n";
	cout << "Row 0: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> word;
		board[0][i] = word;
	}
	cout << "Row 1: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> word;
		board[1][i] = word;
	}
	cout << "Row 2: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> word;
		board[2][i] = word;
	}
	cout << "Row 3: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> word;
		board[3][i] = word;
	}
	cout << "\n" << "Show Board (y/n)?: ";
	cin >> word;
	if (word == "y")
	{ 
		SolveBoard(board, count, dict, wordsFound, true);
	}
	else
	{
		SolveBoard(board, count, dict, wordsFound, false);
	}
	wordsFound.outfile.close();
	return 0;
}
// Pre: Given a board, a step board, a tracker for row and col and step, a Dictionary tree, a tree to store the word that is found in the board, a bool to check which kind of output to print
// Post: Given a output for the solution of the board.
void SearchForWord(string board[4][4], int stepboard[4][4], int r, int c, int count, Dictionary& dict, Dictionary& wordsFound, string word, bool printboard)
{
	if (stepboard[r][c] != 0)
	{
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (stepboard[i][j] == count)
				return;
		}
	}
	if (dict.isPrefix(word))
	{
		stepboard[r][c] = count;
		if (dict.isWord(word))
		{
			if (!wordsFound.isWord(word))
			{
				wordsFound.addWord(word);
				if (printboard)
				{
					cout << "Word: " << word << endl;
					cout << "Number of words: " << wordsFound.wordCount() << endl;
					wordsFound.outfile << "Word: " << word << endl;
					wordsFound.outfile << "Number of words: " << wordsFound.wordCount() << endl;
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (stepboard[i][j] != 0)
							{
								cout << "'" << board[i][j] << "'";
								wordsFound.outfile << "'" << board[i][j] << "'";
							}
							else
							{
								cout << " " << board[i][j] << " ";
								wordsFound.outfile << " " << board[i][j] << " ";
							}
						}
						cout << "       ";
						wordsFound.outfile << "       ";
						for (int j = 0; j < 4; j++)
						{
							cout << " " << stepboard[i][j] << " ";
							wordsFound.outfile << " " << stepboard[i][j] << " ";
						}
						cout << "\n";
						wordsFound.outfile << "\n";
					}
					cout << "\n";
					wordsFound.outfile << "\n";
				}
				else
				{
					cout << wordsFound.wordCount();
					wordsFound.outfile << wordsFound.wordCount();
					if (wordsFound.wordCount() <= 9)
					{
						cout << "     " << word << endl;
						wordsFound.outfile << "     " << word << endl;
					}
					else if (wordsFound.wordCount() <= 99)
					{
						cout << "    " << word << endl;
						wordsFound.outfile << "    " << word << endl;
					}
					else if (wordsFound.wordCount() > 99)
					{
						cout << "   " << word << endl;
						wordsFound.outfile << "   " << word << endl;
					}
				}
				
			}
		}
		if (r - 1 >= 0)
		{
			SearchForWord(board, stepboard, r - 1, c, count + 1, dict, wordsFound, word + board[r - 1][c], printboard);
			if (c - 1 >= 0)
			{
				SearchForWord(board, stepboard, r - 1, c - 1, count + 1, dict, wordsFound, word + board[r - 1][c - 1], printboard);
			}
			if (c + 1 <= 3)
			{
				SearchForWord(board, stepboard, r - 1, c + 1, count + 1, dict, wordsFound, word + board[r - 1][c + 1], printboard);
			}
		}
		if (r + 1 <= 3)
		{
			SearchForWord(board, stepboard, r + 1, c, count + 1, dict, wordsFound, word + board[r + 1][c], printboard);
			if (c - 1 >= 0)
			{
				SearchForWord(board, stepboard, r + 1, c - 1, count + 1, dict, wordsFound, word + board[r + 1][c - 1], printboard);
			}
			if (c + 1 <= 3)
			{
				SearchForWord(board, stepboard, r + 1, c + 1, count + 1, dict, wordsFound, word + board[r + 1][c + 1], printboard);
			}
		}
		if (c - 1 >= 0)
		{
			SearchForWord(board, stepboard, r, c - 1, count + 1, dict, wordsFound, word + board[r][c - 1], printboard);
		}
		if (c + 1 <= 3)
		{
			SearchForWord(board, stepboard, r, c + 1, count + 1, dict, wordsFound, word + board[r][c + 1], printboard);
		}
		stepboard[r][c] = 0;
	}
	else
		return;
}

// Pre: Given a board, a track of steps, a Dictionary tree, a tree to store the word is found in the board, a bool to check what kind of output to print)
// Post: Call SearchForWord() recursively
void SolveBoard(string board[4][4], int count, Dictionary& dict, Dictionary& wordsFound, bool printBoard)
{
	int stepboard[4][4];
	for (int r = 0; r < 4; r++) 
	{
		for (int c = 0; c < 4; c++) 
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					stepboard[i][j] = 0;
				}
			}
			string searchword = board[r][c];
			SearchForWord(board, stepboard, r, c, count, dict, wordsFound, searchword, printBoard);
		}
	}
}
