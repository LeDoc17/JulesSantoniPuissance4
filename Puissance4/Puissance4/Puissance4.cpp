#include "Puissance4.h"
#include <iostream>
#include <cstring>
#include <list>
#include <random>
#include <time.h>
using namespace std;

bool winner = false;
string P1Name;
string P2Name;
string choixRejouer;
bool ReplayValid = false;
char P1Tile;
char P2Tile;

char arr[6][7] = { 
	{'.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.'} };
int c1 = 6;
int c2 = 6;
int c3 = 6;
int c4 = 6;
int c5 = 6;
int c6 = 6;
int c7 = 6;

void PfourMainMenu()
{
	resetBoard();
	int round = 0;
	winner = false;
	system("cls");
	cout << "Bienvenue Dans le" << '\n';
	std::cout << R"(
 ____  _  _  __  ____  ____   __   __ _   ___  ____     ___ 
(  _ \/ )( \(  )/ ___)/ ___) / _\ (  ( \ / __)(  __)   / _ \
 ) __/) \/ ( )( \___ \\___ \/    \/    /( (__  ) _)   (__  (
(__)  \____/(__)(____/(____/\_/\_/\_)__) \___)(____)    (__/

	)" << '\n';
	cout << "Joueur 1 quel est votre nom ?" << '\n';
	cin >> P1Name;
	cout << "Joueur 2 quel est votre nom ?" << '\n';
	cin >> P2Name;
	transform(P1Name.begin(), P1Name.end(), P1Name.begin(), ::toupper);
	transform(P2Name.begin(), P2Name.end(), P2Name.begin(), ::toupper);
	P1Tile = P1Name[0];
	P2Tile = P2Name[0];
	system("cls");
	for (int i = 0;i < 6;i++)
	{
		for (int j = 0;j < 7;j++)
		{
			cout << arr[i][j] << '|';
		}
		cout << endl;
	}
	for (int f = 1; f < 8;f++)
	{
		cout << f << '|';
	}
	cout << endl;
	while (winner == false && round < 21)
	{
		P1Turn();
		round++;
	}
	if (round >= 21)
	{
		cout << "Egalite !" << '\n';
		PrintReplay();
	}
}

void P1Turn()
{
	bool win = false;
	int p1 = 0;
	int col = 0;
	int row = 0;
	while (p1 < 1)
	{
		cout << P1Name << '\n' << "Choisissez une colonne: ";
		col = 0;
		cin >> col;
		while (cin.fail()) {
			cout << "Choix invalide, choisissez un chiffre entier de 1 a 7: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> col;
		}
		row = insert(col);
		while (row == -1)
		{
			cout << "Place invalide, choisissez une autre colonne: ";
			cin >> col;
			row = insert(col);
		}
		printBoard(row, col, P1Tile);

		p1++;
	}
	if (win_p1_row(row) == true)
	{
		PrintWin(P1Name);
		win = true;
		winner = true;
	}
	if (win_p1_col(col) == true)
	{
		PrintWin(P1Name);
		win = true;
		winner = true;
	}
	if (win_p1_dai1(row, col) == true)
	{
		PrintWin(P1Name);
		win = true;
		winner = true;
	}
	if (win_p1_dai2(row, col) == true)
	{
		PrintWin(P1Name);
		win = true;
		winner = true;
	}
	if (win == false)
	{
		P2Turn();
	}
}

void P2Turn()
{
	int p2 = 0;
	int col = 0;
	int row = 0;
	while (p2 < 1)
	{
		cout << P2Name << '\n' << "Choisissez une colonne: ";
		col = 0;
		cin >> col;
		while (cin.fail()) {
			cout << "Choix invalide, choisissez un chiffre entier de 1 a 7: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> col;
		}
		row = insert(col);
		while (row == -1)
		{
			cout << "Place invalide, choisissez une autre colonne: ";
			cin >> col;
			row = insert(col);
		}
		printBoard(row, col, P2Tile);
		p2++;
	}
	if (win_p2_row(row) == true)
	{
		PrintWin(P2Name);
		winner = true;
	}
	if (win_p2_col(col) == true)
	{
		PrintWin(P2Name);
		winner = true;
	}
	if (win_p2_dai1(row, col) == true)
	{
		PrintWin(P2Name);
		winner = true;
	}
	if (win_p2_dai2(row, col) == true)
	{
		PrintWin(P2Name);
		winner = true;
	}
}

void resetBoard()
{
	for (int i = 0;i < 6;i++)
	{
		for (int j = 0;j < 7;j++)
		{
			arr[i][j] = '.';
		}
	}
	c1 = 6;
	c2 = 6;
	c3 = 6;
	c4 = 6;
	c5 = 6;
	c6 = 6;
	c7 = 6;
}

void printBoard(int a, int b, char x)
{
	arr[a][b - 1] = x;
	for (int i = 0;i < 6;i++)
	{
		for (int j = 0;j < 7;j++)
		{
			cout << arr[i][j] << '|';
		}
		cout << '\n';
	}
	for (int f = 1; f < 8;f++)
	{
		cout << f << '|';
	}
	cout << '\n';
}

//inserting the char in the board
int insert(int x)
{

	if (x == 1) {
		if (c1 > 0) {
			c1--;
			return c1;
		}
		else
			return -1;
	}
	else if (x == 2) {
		if (c2 > 0) {
			c2--;
			return c2;
		}
		else
			return -1;
	}
	else if (x == 3) {
		if (c3 > 0) {
			c3--;
			return c3;
		}
		else
			return -1;
	}
	else if (x == 4) {
		if (c4 > 0)
		{
			c4--;
			return c4;
		}
		else
			return -1;
	}
	else if (x == 5) {
		if (c5 > 0) {
			c5--;
			return c5;
		}
		else
			return -1;
	}
	else if (x == 6) {
		if (c6 > 0) {
			c6--;
			return c6;
		}
		else
			return -1;
	}
	else if (x == 7) {
		if (c7 > 0) {
			c7--;
			return c7;
		}
		else
			return -1;
	}
	else
		return -1;

}


//checking all the P1 winning possibilities 
bool win_p1_row(int a)
{
	int count = 0;
	for (int j = 0; j < 7;j++) {
		if (arr[a][j] == P1Tile)
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}

bool win_p1_dai1(int a, int b)
{
	int count = 0;
	b--;
	if (a >= b)
	{
		a -= b;
		b = 0;
		while (a < 6)
		{
			if (arr[a][b] == P1Tile)
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	else
	{
		b -= a;
		a = 0;
		while (b < 7)
		{
			if (arr[a][b] == P1Tile)
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	return false;

}

bool win_p1_dai2(int a, int b)
{
	int count = 0;
	b--;
	int c = a + b;
	if (c < 7 && c>2)
	{
		b = c;
		a = 0;
		while (a < 6)
		{
			if (arr[a][b] == P1Tile)
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	else if (c > 6 && c < 9)
	{
		b = 6;
		a = c - 6;
		while (a < 6)
		{
			if (arr[a][b] == P1Tile)
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	return false;

}

bool win_p1_col(int a)
{
	int count = 0;
	a--;
	for (int j = 0; j < 6;j++)
	{
		if (arr[j][a] == P1Tile)
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}


//checking all the P2 winning possibilities
bool win_p2_row(int a)//1st case to win p2
{
	int count = 0;

	for (int j = 0; j < 7;j++)
	{
		if (arr[a][j] == P2Tile)
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}

bool win_p2_col(int a)//2nd case to win p2
{
	int count = 0;
	a--;
	for (int j = 0; j < 6;j++)
	{
		if (arr[j][a] == P2Tile)
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}

bool win_p2_dai1(int a, int b)//3rd case to win p2
{
	int count = 0;
	b--;
	if (a >= b)
	{
		a -= b;
		b = 0;
		while (a < 6)
		{
			if (arr[a][b] == P2Tile)
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	else
	{
		b -= a;
		a = 0;
		while (b < 7)
		{
			if (arr[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	return false;

}

bool win_p2_dai2(int a, int b)//4th case to win p2
{
	int count = 0;
	b--;
	int c = a + b;
	if (c < 7 && c>2)
	{
		b = c;
		a = 0;
		while (a < 6)
		{
			if (arr[a][b] == P2Tile)
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	else if (c > 6 && c < 9)
	{
		b = 6;
		a = c - 6;
		while (a < 6)
		{
			if (arr[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	return false;

}


void PrintWin(string x)
{
	std::cout << R"(
  _                          
 | |__  _ __ __ ___   _____  
 | '_ \| '__/ _` \ \ / / _ \ 
 | |_) | | | (_| |\ V / (_) |
 |_.__/|_|  \__,_| \_/ \___/ 
                             
	)" << '\n';
	cout << x << " a gagne !" << '\n';
	PrintReplay();
}

void PrintReplay()
{
	std::cout << R"(



	)" << '\n';
	while (ReplayValid == false)
	{
		cout << "Que voulez vous faire ?" << '\n';
		cout << "Rejouer (R) ou Quitter(Q)" << '\n';
		cin >> choixRejouer;
		if (choixRejouer == "R" || choixRejouer == "r")
		{
			PfourMainMenu();
			ReplayValid = true;
		}
		else if (choixRejouer == "Q" || choixRejouer == "q")
		{
			ReplayValid = true;
		}
		else
		{
			cout << "Entree invalide" << '\n';
		}
	}
}
