#include <iostream>
#include <cstring>
#include <list>
#include <random>
#include <time.h>
#include "BullAndCow.h"
using namespace std;


string Word = "";
string NumPlayer;
int NumLetters = 5;
bool WordFound = false;
const char* WordBank[]
= {
"RAILS", "PATIO", "ALBUM", "SCORE", "LARME", "HALTE", "CAVES", "ALPIN", "PROUT", "RONDE",
"JUIVE", "CHANT", "ADORE", "DOTER", "CUBES", "ACTIF", "BRUIT", "PLUME", "GRAND", "MORTE",
"FOYER", "BLANC", "PEINT", "GLACE", "JOURS", "VASTE", "PRUNE", "MONDE", "PALES", "COEUR",
"TIGRE", "LIVRE", "FORCE", "DRAPS", "AGILE", "CRANE", "BLOCS", "FONTE", "CARTE", "GRAVE",
"PIEDS", "VITRE", "BRUNE", "CLAIR", "DOUZE", "FORGE", "PLANS", "TONDU", "VALET", "GRAIN" };
const char* Validator[]
= { "[_]", "[_]", "[_]", "[_]", "[_]" };

void BCMainMenu()
{
	srand(time(NULL));
	bool WordCreated = false;
	system("cls");
	bool Choose = false;
	std::cout << R"(
-----------------------Bienvenue dans-------------------------
__________      .__  .__     ____   _________                
\______   \__ __|  | |  |   /  _ \  \_   ___ \  ______  _  __
 |    |  _/  |  \  | |  |   >  _ </\/    \  \/ /  _ \ \/ \/ /
 |    |   \  |  /  |_|  |__/  <_\ \/\     \___(  <_> )     / 
 |______  /____/|____/____/\_____\ \ \______  /\____/ \/\_/  
        \/                        \/        \/               
  Un wordle jouable seul ou a deux avec 50 mots disponibles
	)" << '\n';
	while (Choose == false)
	{
		cout << "---------------------- 1 ou 2 joueurs ? ----------------------" << '\n';
		cout << "---------------------- Pour quitter (Q) ----------------------" << '\n';
		cin >> NumPlayer;
		if (NumPlayer == "2")
		{
			TwoPlayersGame();
			Choose = true;
		}
		else if (NumPlayer == "1")
		{
			OnePlayerGame();
			Choose = true;
		}
		else if (NumPlayer == "Q")
		{
			Quit();
			Choose = true;
		}
		else if (NumPlayer == "q")
		{
			Quit();
			Choose = true;
		}
		else
		{
			cout << "---------------------- Entree invalide  ----------------------" << '\n';
		}
	}
	return;
}

void OnePlayerGame()
{
	system("cls");
	WordFound = false;
	int Rand = rand() % ((sizeof(WordBank) / sizeof(WordBank[0])) + 1);
	Word = WordBank[Rand];
	cout << "------------ Essayez de deviner le mot de " << NumLetters << " lettres ------------" << '\n';
	cout << "le mot est " << Word << "!" << '\n';
	while (WordFound == false)
	{
		PlayerTry();
	}
	PrintWin();
	return;
}

void TwoPlayersGame()
{
	WordFound = false;
	system("cls");
	bool WordCreated = false;
	cout << "--------------------------- Master ---------------------------" << '\n';
	while (WordCreated == false)
	{
		cout << "| - - - - - - - Choisissez un mot de " << NumLetters << " lettres - - - - - - - |" << '\n';
		cin >> Word;
		transform(Word.begin(), Word.end(), Word.begin(), ::toupper);
		if (Word.length() == NumLetters)
		{
			const char* str = Word.c_str();
			WordCreated = true;
		}
		else
		{
			cout << "| - - - - - - - Votre mot ne fait pas " << NumLetters << " lettres - - - - - - - |" << '\n';
		}
	}
	system("cls");
	cout << "-------------------------- Chercheur --------------------------" << '\n';
	while (WordFound == false)
	{
		PlayerTry();
	}
	PrintWin();
	return;
}

bool PlayerTry()
{
	cout << "| - - - - - - - - Trouvez le mot de " << NumLetters << " lettres - - - - - - - - |" << '\n';
	string Guess;
	cin >> Guess;
	transform(Guess.begin(), Guess.end(), Guess.begin(), ::toupper);
	if (Guess.length() == NumLetters)
	{
		const char* str = Guess.c_str();
		for (int i = 0; i < NumLetters; i++)
			if (Guess[i] == Word[i])
			{
				Validator[i] = "[_]";
			}
			else
			{
				Validator[i] = "[|]";
			}
		for (int i = 0; i < NumLetters; i++)
			cout << Validator[i];
		cout << '\n';
		PrintLegend();
		if (Guess == Word)
		{
			WordFound = true;
		}
	}
	else
	{
		cout << "| - - - - - - - Votre mot ne fait pas " << NumLetters << " lettres - - - - - - - |" << '\n';
	}
	return WordFound;
}

void PrintLegend()
{
	cout << "           legende" << '\n';
	cout << "[_] Bonne lettre, bonne place." << '\n';
	cout << "[/] Bonne lettre, mauvaise place." << '\n';
	cout << "[|] Mauvaise lettre, mauvaise place." << '\n';
}

void PrintWin()
{
	bool BoucleRejouer = false;
	string Rejouer;
	cout << "------------------------------------------------------------------------" << '\n';
	std::cout << R"(
 ______                                                      
|   __ \.----.---.-.--.--.-----.    .--.--.-----.--.--.-----.
|   __ <|   _|  _  |  |  |  _  |    |  |  |  _  |  |  |__ --|
|______/|__| |___._|\___/|_____|     \___/|_____|_____|_____|
                                                             
                                                             
.---.-.--.--.-----.-----.    .-----.---.-.-----.-----.-----. 
|  _  |  |  |  -__|-- __|    |  _  |  _  |  _  |     |  -__| 
|___._|\___/|_____|_____|    |___  |___._|___  |__|__|_____| 
                             |_____|     |_____|                               

)" << '\n';
	while (BoucleRejouer == false)
	{
		cout << "------------------ Rejouer, Menu ou Quitter ? (R/M/Q) ------------------" << '\n';
		cin >> Rejouer;
		if (Rejouer == "R" || Rejouer == "r")
		{
			if (NumPlayer == "2")
			{
				TwoPlayersGame();
				BoucleRejouer = true;
			}
			else if (NumPlayer == "1")
			{
				OnePlayerGame();
				BoucleRejouer = true;
			}
		}
		else if (Rejouer == "M" || Rejouer == "m")
		{
			BCMainMenu();
			BoucleRejouer = true;
		}
		else if (Rejouer == "Q" || Rejouer == "q")
		{
			Quit();
			BoucleRejouer = true;
		}
		else
		{
			cout << "--------------------------- Entree invalide  ---------------------------" << '\n';
		}
	}
	return;

}

void Quit()
{
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
	return;
}
