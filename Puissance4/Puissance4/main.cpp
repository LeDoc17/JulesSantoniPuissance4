#include <iostream>
#include "BullAndCow.h"
#include "Puissance4.h"

using namespace std;
string choixjeu;

void PrintHomeScreen();

int main()
{
	PrintHomeScreen();
	return 0;
}


void PrintHomeScreen()
{
	bool Quit = false;
	while (Quit == false)
	{
		system("cls");
		std::cout << R"(
                               _       _                                 
         _     _              (_)     (_)                                
   ___ _| |_ _| |_   _ __ ___  _ _ __  _  __ _  __ _ _ __ ___   ___  ___ 
  / __|_   _|_   _| | '_ ` _ \| | '_ \| |/ _` |/ _` | '_ ` _ \ / _ \/ __|
 | (__  |_|   |_|   | | | | | | | | | | | (_| | (_| | | | | | |  __/\__ \
  \___|             |_| |_| |_|_|_| |_|_|\__, |\__,_|_| |_| |_|\___||___/
                                          __/ |                          
                                         |___/                           
		)" << '\n';
		cout << "A quoi voulez vous jouer ?" << '\n';
		cout << "Bull&Cow(1) ou Puissance4(2)" << '\n';
		cout << "Pour quitter (Q)" << '\n';
		cin >> choixjeu;
		if (choixjeu == "1")
		{
			BCMainMenu();
		}
		else if (choixjeu == "2")
		{
			PfourMainMenu();
		}
		else if (choixjeu == "q" || choixjeu == "Q")
		{
			Quit = true;
		}
		else
		{
			cout << "Choix invalide" << '\n';
		}
	}
	system("cls");
	std::cout << R"(

           __  ___               _             __     
          /  |/  /__  __________(_)  ____ _   / /___ _
         / /|_/ / _ \/ ___/ ___/ /  / __ `/  / / __ `/
        / /  / /  __/ /  / /__/ /  / /_/ /  / / /_/ / 
       /_/  /_/\___/_/   \___/_/   \__,_/_ /_/\__,_/  
      ____  _________  _____/ /_  ____ _(_)___  ___   
     / __ \/ ___/ __ \/ ___/ __ \/ __ `/ / __ \/ _ \  
    / /_/ / /  / /_/ / /__/ / / / /_/ / / / / /  __/  
   / .___/_/   \____/\___/_/ /_/\__,_/_/_/ /_/\___/   
  /_/                                                 

	)" << '\n';
}