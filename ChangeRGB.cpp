#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Create Function Prototype
void CI(string, string);
void ZO(string, string);
void AR(string, string);

int main()
{
	// Create variables
	int choice;

	// Asking user for three spaces and choices
	cout << "Do you want 1) Color invent, 2) Zero out gb values or 3) Add random noise to the image? (Enter 1, 2 or3) ";
	cin >> choice;

	// If statement for what user choose
	if (choice == 1)
	{
		// Run Color Invent function
		CI("rainbow_cake.ppm", "new_cake.ppm");
	}
	if (choice == 2)
	{
		// Run Zero Out RB Values function
		ZO("rainbow_cake.ppm", "new_cake.ppm");
	}
	if (choice == 3)
	{
		// Run Add Random Noise function
		AR("rainbow_cake.ppm", "new_cake.ppm");
	}
}

void CI(string infi, string outfi)
{
	ifstream infile;
	ofstream outfile;
	string str;
	int num;

	// Open the file
	infile.open(infi);
	outfile.open(outfi);

	// Print first four line in output file
	for (int count = 0; count < 4; count++)
	{
		getline(infile, str);
		outfile << str << endl;
	}
	
	// Deal with rest of the num
	while (infile >> str)
	{
		num = stoi(str);
		// Invert the numbers
		num = 255 - num;
		outfile << num << " ";
	}

	// Close the file
	outfile.close();
	infile.close();
}

void ZO(string infi, string outfi)
{
	ifstream infile;
	ofstream outfile;
	string str;
	int num;
	int nocount = 0;

	// Open the file
	infile.open(infi);
	outfile.open(outfi);

	// Print first four line in output file
	for (int count = 0; count < 4; count++)
	{
		getline(infile, str);
		outfile << str << endl;
	}
	
	// Deal with rest of the num
	while (infile >> str)
	{
		// Only change G and B value to  0
		nocount++;
		if (nocount == 1)
		{
			outfile << str << " ";
		}
		if (nocount == 2)
		{
			outfile << 0 << " ";
		}
		if (nocount == 3)
		{
			outfile << 0 << " ";
			nocount = 0;
		}
	}

	// Close the file
	outfile.close();
	infile.close();
}

void AR(string infi, string outfi)
{
	ifstream infile;
	ofstream outfile;
	string str;
	int num;

	// Open the file
	infile.open(infi);
	outfile.open(outfi);

	// Print first four line in output file
	for (int count = 0; count < 4; count++)
	{
		getline(infile, str);
		outfile << str << endl;
	}
	
	// Deal with rest of the num
	while (infile >> str)
	{
		// Randomly 1/3 chances to change the value
		int tf = rand() % 3;
		if (tf == 0)
		{
			num = rand();
			outfile << num << " ";
		}
		else
		{
			outfile << str << " ";
		}
	}
	
	// Close the file
	outfile.close();
	infile.close();
}
