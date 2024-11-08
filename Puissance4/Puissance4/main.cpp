#include <iostream>
#include "BullAndCow.h"
using namespace std;
string choixjeu;

int main()
{
	cout << "choisissez un jeu" << '\n';
	cin >> choixjeu;
	if (choixjeu == "b")
	{
		BCMainMenu();
	}
	system("cls");
	cout << "j'espere que tu t'es amuse" << '\n';
	return 0;
}