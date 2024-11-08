#pragma once

#include <iostream>
#include <cstring>
#include <list>
#include <random>
#include <time.h>
using namespace std;

void PfourMainMenu();
void printBoard(int a, int b, char x);
int insert(int x);
void P1Turn();
void P2Turn();
void PrintWin(string x);
void resetBoard();
void PrintReplay();

//win verificators
bool win_p1_row(int a);
bool win_p1_dai1(int a, int b);
bool win_p1_dai2(int a, int b);
bool win_p1_col(int a);
bool win_p2_row(int a);
bool win_p2_dai1(int a, int b);
bool win_p2_dai2(int a, int b);
bool win_p2_col(int a);