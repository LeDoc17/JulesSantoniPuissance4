#include <iostream>
#include "BullAndCow.h"
#include "Puissance4.h"

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
	else if (choixjeu == "4")
	{
		PfourMainMenu();
	}
	cout << "j'espere que tu t'es amuse" << '\n';
	return 0;
}