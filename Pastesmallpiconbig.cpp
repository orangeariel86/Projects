// HW5.cpp#include <iostream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
// Create Arstr to store arrays' data
struct Arstr
{
	int columns;
	int rows;
	int** redar;
	int** greenar;
	int** bluear;
};
// Create functions
Arstr makeDataStructures(string);
void Paste(Arstr, Arstr, int);
void newppm(string, string, Arstr);
// Create globle variables for functions' parameters
Arstr arrs;
Arstr largeimage;
Arstr smallimage;

int main()
{
	// Put large and small images' data in two structures
	largeimage = makeDataStructures("rainbow_keyboard.ppm");
	smallimage = makeDataStructures("flower.ppm");
	cout << "How many pixels?";
	int pixels;
	cin >> pixels;
	Paste(largeimage, smallimage, pixels);
	newppm("rainbow_keyboard.ppm", "new.ppm", largeimage);
	return 0;
}

Arstr makeDataStructures(string infi)
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

	// Struct Everything Here
	arrs.columns = num1;
	arrs.rows = num2;
	arrs.redar = new int* [num2 - 1];
	for (int i = 0; i < num2; i++)
	{
		arrs.redar[i] = new int[num1 - 1];
	}
	arrs.greenar = new int* [num2 - 1];
	for (int i = 0; i < num2; i++)
	{
		arrs.greenar[i] = new int[num1 - 1];
	}
	arrs.bluear = new int* [num2 - 1];
	for (int i = 0; i < num2; i++)
	{
		arrs.bluear[i] = new int[num1 - 1];
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
				arrs.redar[ri][rj] = num;
				rj = 0;
				ri++;
				if (ri == num2)
				{
					ri = 0;
				}
			}
			else if (rj < num1 - 1)
			{
				arrs.redar[ri][rj] = num;
				rj++;
			}
		}
		else if (count == 2)
		{
			num = stoi(str);
			if (gj == num1 - 1)
			{
				arrs.greenar[gi][gj] = num;
				gj = 0;
				gi++;
				if (gi == num2)
				{
					gi = 0;
				}
			}
			else if (gj < num1 - 1)
			{
				arrs.greenar[gi][gj] = num;
				gj++;
			}
		}
		else if (count == 3)
		{
			num = stoi(str);
			if (gj == num1 - 1)
			{
				arrs.bluear[bi][bj] = num;
				bi++;
				bj = 0;
				if (bi == num2)
				{
					bi = 0;
				}
			}
			else if (bj < num1 - 1)
			{
				arrs.bluear[bi][bj] = num;
				bj++;
			}
			count = 0;
		}
	}

	infile.close();
	// Return to the varriable which call this function
	return arrs;
}
// Function for pasting small image on large image
void Paste(Arstr largeimage, Arstr smallimage, int x)
{
	int i, j;
	for (i = 0; i < smallimage.rows; i++)
	{
		for (j = 0; j < smallimage.columns; j++)
		{
			largeimage.redar[i + x][j + x] = smallimage.redar[i][j];
			largeimage.greenar[i + x][j + x] = smallimage.greenar[i][j];
			largeimage.bluear[i + x][j + x] = smallimage.bluear[i][j];
		}
	}
}
// Function for write a new .ppm 
void newppm(string infi, string outfi, Arstr largeimage)
{
	ifstream infile;
	ofstream outfile;
	string str;
	infile.open(infi);
	outfile.open(outfi);
	for (int i = 0; i < 4; i++)
	{
		getline(infile, str);
		outfile << str << endl;
	}
	for (int j = 0; j < largeimage.rows; j++)
	{
		for (int k = 0; k < largeimage.columns; k++)
		{
			outfile << largeimage.redar[j][k] << " ";
			outfile << largeimage.greenar[j][k] << " ";
			outfile << largeimage.bluear[j][k] << " ";
		}
	}
	outfile.close();
	infile.close();
}