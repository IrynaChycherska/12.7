#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <math.h>
using namespace std;
void CreateTXT(char* fname)
{
	ofstream fout(fname);
	char ch;
	string s;
	do
	{
		cin.get();
		cin.sync();
		cout << "enter line: "; getline(cin, s);
		fout << s << endl;
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}
int ProcessTXT1(char* fname)
{
	ifstream fin(fname);
	string s;
	int k = 0;
	while (getline(fin, s))
	{
		for (unsigned i = 0; i < s.length(); i++)
			if (s[i] == ' ')
				k++;
	}
	return k;
}
void SortTXT(char* fname, char* gname)
{
	ofstream g(gname);
	string s, mins, z = "";
	int k;
	do
	{
		k = 0;
		ifstream f(fname);
		while (getline(f, s))
		{
			if (s <= z)
				continue;
			mins = s;
			k++;
			break;
		}
		while (getline(f, s))
		{
			if (s <= z)
				continue;
			if (s < mins)
			{
				mins = s;
				k++;
			}
		}

		z = mins;
		if (k > 0)
			g << z << endl;
		f.close();
	} while (k > 0);
}

void main()
{
	int x, y, w, chromatic;
	int summond[6];
	int m[15] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5 };
	int n[15] = { 2, 3, 4, 5, 6, 3, 4, 5, 6, 4, 5, 6, 5, 6, 6 };
	int contiguity[6][6];
	int incidence[6][11];
	int Rmn[15];
	cout << "Input values:\n";
	for (int i = 0; i <= 14; i++)
	{
		cin >> Rmn[i];
	}
	int k = 0, j = 0, z = -1;
	for (int i = 0; i <= 5; i++)
	{
		z += 1;
		for (j = z; j <= 5; j++)
		{
			if (i == j)
			{
				contiguity[i][j] = 0;
			}
			else
			{
				contiguity[i][j] = Rmn[k];
				contiguity[j][i] = Rmn[k++];
			}
		}
	}
	cout << "\nMatrix of contiguity:\n\n";
	for (int i = 0; i <= 5; i++)
		for (int k = 0, j = 0; j <= 5; j++)
		{
			cout << contiguity[i][j] << " ";
			if (j == 5) cout << "\n";
		}
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 10; j++)
			incidence[i][j] = 0;
	for (int i = 0, k = 0; i <= 14; i++)
	{
		x = Rmn[i];
		y = m[i] - 1;
		w = n[i] - 1;
		while (x > 0)
		{
			incidence[y][k] = 1;
			incidence[w][k] = 1;
			k++;
			x--;
		}
	}
	_getch();
	char fname[100];
	cout << "enter file name 1: "; cin >> fname;
	CreateTXT(fname);
	PrintTXT(fname);
	cout << "k( ) = " << ProcessTXT1(fname) << endl;

	char gname[100];
	cout << "enter file name 2: "; cin >> gname;
	SortTXT(fname, gname);
	PrintTXT(gname);

}