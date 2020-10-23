
#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
void makeDataStructures(string);
int columns;
int rows;
int** redar;
int** greenar;
int** bluear;

int main()
{
	makeDataStructures("sample.ppm");
	int i, j, k = 0, m = 0, n = 0;
	double val;
	double** greyval = new double*[rows - 1];
	for (int i = 0; i < rows; i++)
	{
		greyval[i] = new double[columns - 1];
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			greyval[i][j] = (redar[i][j] + greenar[i][j] + bluear[i][j]) / 3.0;
		}
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			val = greyval[i][j];
			if (j == columns - 1)
			{
				cout << "\n";
				n = 0;
			}
			if (val >= 0 && val <= 17)
			{
				cout << "$";
			}
			else if (val >= 18 && val <= 34)
			{
				cout << "&";
			}
			else if (val >= 35 && val <= 51)
			{
				cout << "o";
			}
			else if (val >= 52 && val <= 68)
			{
				cout << "d";
			}
			else if (val >= 69 && val <= 85)
			{
				cout << "Z";
			}
			else if (val >= 86 && val <= 102)
			{
				cout << "C";
			}
			else if (val >= 103 && val <= 119)
			{
				cout << "z";
			}
			else if (val >= 120 && val <= 136)
			{
				cout << "x";
			}
			else if (val >= 137 && val <= 153)
			{
				cout << "/";
			}
			else if (val >= 154 && val <= 170)
			{
				cout << "1";
			}
			else if (val >= 171 && val <= 187)
			{
				cout << "?";
			}
			else if (val >= 188 && val <= 204)
			{
				cout << "<";
			}
			else if (val >= 205 && val <= 221)
			{
				cout << "|";
			}
			else if (val >= 222 && val <= 238)
			{
				cout << "^";
			}
			else if (val >= 239 && val <= 255)
			{
				cout << ".";
			}
			n++;
		}
	}
	return 0;
}

void makeDataStructures(string infi)
{
	ifstream infile;
	string str;
	int num, num1, num2, x;
	int count = 0, size;
	infile.open(infi);
	// Reading first fourth line and read the size of columns and rows
	for (x = 0; x < 4; x++)
	{
		getline(infile, str);
		if (x == 1)
		{
			infile >> str;
			num1 = stoi(str);
			infile >> str;
			num2 = stoi(str);
		}
	}
	columns = num1;
	rows = num2;
	redar = new int*[num2 - 1];
	for (int i = 0; i < num2; i++)
	{
		redar[i] = new int[num1 - 1];
	}
	greenar = new int*[num2 - 1];
	for (int i = 0; i < num2; i++)
	{
		greenar[i] = new int[num1 - 1];
	}
	bluear = new int*[num2 - 1];
	for (int i = 0; i < num2; i++)
	{
		bluear[i] = new int[num1 - 1];
	}
	// Run the rest of the file to three rgb arrays
	int ri = 0, rj = 0, gi = 0, gj = 0, bi = 0, bj = 0;
	while (infile >> str)
	{
		count++;
		if (count == 1)
		{
			num = stoi(str);
			if (rj == num1 - 1)
			{
				redar[ri][rj] = num;
				rj = 0;
				ri++;
				if (ri == num2)
				{
					ri = 0;
				}
			}
			else if (rj < num1 - 1)
			{
				redar[ri][rj] = num;
				rj++;
			}
		}
		else if (count == 2)
		{
			num = stoi(str);
			if (gj == num1 - 1)
			{
				greenar[gi][gj] = num;
				gj = 0;
				gi++;
				if (gi == num2)
				{
					gi = 0;
				}
			}
			else if (gj < num1 - 1)
			{
				greenar[gi][gj] = num;
				gj++;
			}
		}
		else if (count == 3)
		{
			num = stoi(str);
			if (gj == num1 - 1)
			{
				bluear[bi][bj] = num;
				bi++;
				bj = 0;
				if (bi == num2)
				{
					bi = 0;
				}
			}
			else if (bj < num1 - 1)
			{
				bluear[bi][bj] = num;
				bj++;
			}
			count = 0;
		}
	}
	infile.close();
}
