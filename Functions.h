#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
int AI[2]{ 0,0 };
enum colors { blue = 1, green = 2, red = 4, yellow = 6, white = 7  };
void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}
const int height = 11;
const int width = 11;
int game[height][width]{};
int computer[11][11]{};
int PlayerShipCount = 20;
int ComputerShipCount = 20;




void ShowRules() {
	HANDLE Hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD fsize = { 8,8 };
	CONSOLE_FONT_INFOEX Font = { sizeof( Font ) };
	GetCurrentConsoleFontEx(Hout, 0, &Font);

	//My Code to check the problem...............................
	cout << Font.dwFontSize.X << ' ' << Font.dwFontSize.Y; 
	//...........................................................

	Font.dwFontSize = fsize;
	Font.dwFontSize.X = 100;
	Font.dwFontSize.Y = 100;
	SetCurrentConsoleFontEx(Hout, 0, &Font);
	//std::cout << "!Test Text!";
	//getch();

	mysetcolor(blue, 0);
	cout << "\t\t\t\t\tRULES OF THE GAME" << endl;
	cout << "\n";

	mysetcolor(red, 0);
	cout << "\t" << char(237);
	mysetcolor(blue, 0);
	cout << " <- is place of burst ship";
	cout << endl;

	mysetcolor(yellow, 0);
	cout << "\t" << char(235);
	mysetcolor(blue, 0);
	cout << " <- is place of miss ship";
	cout << endl;

	mysetcolor(blue, 0);
	cout << "\t" << char(176);
	mysetcolor(blue, 0);
	cout << " <- is place of the sea";
	cout << endl;

	mysetcolor(green, 0);
	cout << "\t" << char(237);
	mysetcolor(blue, 0);
	cout << " <- is place of unburst ship in Player Area";
	cout << "\n\n";

	char* RULE = new char[] {"1. This is a two player game.\n2. Player 1 is you and Player 2 is computer.\n3. Player 1 will be prompted if user wants to manually input coordinates\n   for the game board or have the computer randomly generate a game board.\n4. There are five types of ships to be placed by longest length to the\n   shortest;[c] Carrier has 4 cells, [b] Battleship\n   has 3 cells, [r] Cruiser has 2 cells, [d] destroyer has 1 cells\n5. The game begins as each player tries to guess the location of the ships\n   of the opposing player's game board.\n6. First Player to guess the location of all ships wins.\n "};
	int l = strlen(RULE);
	for (size_t i = 0; i < l; i++)
	{
		Sleep(2);
		cout << RULE[i];
	}
	mysetcolor(white, 0);
	system("pause");
	system("cls");
}


void ShowGame() {
	int col = 0;
	int row = 65;
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			if (x == 0 && y == 0) {
				cout << "  ";
			}
			else if (y == 0) {
				cout << col++ << " ";
			}
			else if (x == 0) {
				cout << char(row) << " ";
				row++;
			}
			else if (game[y][x] == 0 || game[y][x] == 2) {
				mysetcolor(blue, 0);
				cout << char(176) << " ";
				mysetcolor(white, 0);
			}
			else if (game[y][x] == 1) {
				mysetcolor(green, 0);
				cout << char(237) << " ";
				mysetcolor(white, 0);
			}
			else if (game[y][x] == 3) {
				mysetcolor(yellow, 0);
				cout << char(235) << " ";
				mysetcolor(white, 0);
			}
			else if (game[y][x] == 4) {
				mysetcolor(red, 0);
				cout << char(237) << " ";
				mysetcolor(white, 0);
			}

			/*else if (game[y][x] == 2) {
				mysetcolor(red, 0);
				cout << 'x' << " ";
				mysetcolor(white, 0);
			}*/
		
		}cout << endl;
	}
}

bool Check(const int& x,const char& y,const char& d) {
	if (x >= 0 && x <= 10 && y >= 'A' && y <= 'J'+1) {
		if (d == 'r' || d == 'l' || d == 'u' || d == 'd') {
			return true;
		}
		else {
			cout << "Enter correct destination " << endl;
			return false;
		}
	}
	else {
		cout << "Enter right cordinates " << endl;
		return false;
	}
}

bool Check(const int& x, const char& y) {
	if (x >= 0 && x <= 10 && y >= 'A' && y <= 'J' + 1) {
		return true;
	}
	else {
		cout << "Enter right cordinates " << endl;
		Sleep(1000);
		return false;
	}
}

bool isEmpty(const int& x, const char& y1,const int& c, const char& d) {
	//d -destination
	int y = (int)y1 - 65;
	if (d == 'r') {
		if (x + c <= height) {
			for (size_t i = 0; i < c; i++)
			{
				if (game[y][x + i] == 1 || game[y - 1][x + i] == 1 || game[y + 1][x + i] == 1) {
					return false;
				}
			}
			if (game[y][x - 1] == 1 || game[y - 1][x - 1] == 1 || game[y + 1][x - 1] == 1 ||
				game[y][x + c] == 1 || game[y - 1][x + c] == 1 || game[y + 1][x + c] == 1) {
				return false;
			}
		}
		else return false;
	}
	/*------------------------------------------*/
	else if (d == 'l') {
		if (x - c >= 1) {

			for (size_t i = 0; i < c; i++)
			{
				if (game[y][x - i] == 1 || game[y - 1][x - i] == 1 || game[y + 1][x - i] == 1) {
					return false;
				}
			}
			if (game[y][x + 1] == 1 || game[y - 1][x + 1] == 1 || game[y + 1][x + 1] == 1 ||
				game[y][x - c] == 1 || game[y - 1][x - c] == 1 || game[y + 1][x - c] == 1) {
				return false;
			}
		}
		else return false;
	}
	/*------------------------------------------*/
	else if (d == 'u') {
		if (y - c >= 1) {

			for (size_t i = 0; i < c; i++)
			{
				if (game[y - i][x] == 1 || game[y - i][x - 1] == 1 || game[y - i][x + 1] == 1) {
					return false;
				}
			}
			if (game[y + 1][x] == 1 || game[y + 1][x - 1] == 1 || game[y + 1][x + 1] == 1 ||
				game[y - c][x] == 1 || game[y - c][x - 1] == 1 || game[y - c][x + 1] == 1) {
				return false;
			}
		}
		else return false;
	}
	/*------------------------------------------*/
	else if (d == 'd') {
		if (y + c <= width) {

			for (size_t i = 0; i < c; i++)
			{
				if (game[y + i][x] == 1 || game[y + i][x - 1] == 1 || game[y + i][x + 1] == 1) {
					return false;
				}
			}
			if (game[y - 1][x] == 1 || game[y - 1][x - 1] == 1 || game[y - 1][x + 1] == 1 ||
				game[y + c][x] == 1 || game[y + c][x - 1] == 1 || game[y + c][x + 1] == 1) {
				return false;
			}
		}
		else return false;
	}
	
	return true;
}

void SetShip(const int& x, const char& y1, const int& c, const char& d) {
	int y = (int)y1 - 65;
	if (d == 'r') {
		for (size_t i = 0; i < c; i++)
		{
			game[y + 1][x + i] = 2;
			game[y - 1][x + i] = 2;
			game[y][x + i] = 1;
		}
		game[y][x - 1] = 2;
		game[y - 1][x - 1] = 2;
		game[y + 1][x - 1] = 2;
		game[y][x + c] = 2;
		game[y - 1][x + c] = 2;
		game[y + 1][x + c] = 2;
	}
	/*------------------------------------------*/
	else if (d == 'l') {
		for (size_t i = 0; i < c; i++)
		{
			game[y + 1][x - i] = 2;
			game[y - 1][x - i] = 2;
			game[y][x - i] = 1;
		}
		game[y][x + 1] = 2;
		game[y - 1][x + 1] = 2;
		game[y + 1][x + 1] = 2;
		game[y][x - c] = 2;
		game[y - 1][x - c] = 2;
		game[y + 1][x - c] = 2;

	}
	/*------------------------------------------*/
	else if (d == 'u') {
		for (size_t i = 0; i < c; i++)
		{
			game[y - i][x] = 1;
			game[y - i][x - 1] = 2;
			game[y - i][x + 1] = 2;
		}
		game[y + 1][x - 1] = 2;
		game[y + 1][x] = 2;
		game[y + 1][x + 1] = 2;
		game[y - c][x - 1] = 2;
		game[y - c][x] = 2;
		game[y - c][x + 1] = 2;
	}
	/*------------------------------------------*/
	else if (d == 'd') {
		for (size_t i = 0; i < c; i++)
		{
			game[y + i][x - 1] = 2;
			game[y + i][x] = 1;
			game[y + i][x + 1] = 2;
		}
		game[y - 1][x - 1] = 2;
		game[y - 1][x] = 2;
		game[y - 1][x + 1] = 2;
		game[y + c][x - 1] = 2;
		game[y + c][x] = 2;
		game[y + c][x + 1] = 2;
	}
}


void SetCarrier(int& CarrierCounter) {
	cout << "Enter x : ";
	int x;
	cin >> x;

	cout << "Enter y : ";
	char y;
	cin >> y;
	y = toupper(y);
	cout << "enter destination : right(r), left(l) , up(u), down(d) : ";
	char d;
	cin >> d;

	if (Check(x+1, y+1, d)) {
		if (isEmpty(x+1, y+1, 4, d)) {
			SetShip(x + 1, y + 1, 4, d);
			CarrierCounter++;
		}
	}
	else {
		cout << "not empty" << endl;
		system("pause");
	}

}


void SetBattleship(int& BattleShipCounter) {
	cout << "Enter x : ";
	int x;
	cin >> x;

	cout << "Enter y : ";
	char y;
	cin >> y;
	y = toupper(y);
	cout << "enter destination : right(r), left(l) , up(u), down(d) : ";
	char d;
	cin >> d;

	if (Check(x+1, y+1, d)) {
		if (isEmpty(x+1, y+1, 3, d)) {
			SetShip(x + 1, y + 1, 3, d);
			BattleShipCounter++;
		}
		else {
			cout << "not empty" << endl;
			system("pause");
		}
	}
}

void SetCruiser(int& CruiserCounter) {

	cout << "Enter x : ";
	int x;
	cin >> x;

	cout << "Enter y : ";
	char y;
	cin >> y;
	y = toupper(y);
	cout << "enter destination : right(r), left(l) , up(u), down(d) : ";
	char d;
	cin >> d;

	if (Check(x+1, y+1, d)) {
		if (isEmpty(x+1, y+1, 2, d)) {
			SetShip(x + 1, y + 1, 2, d);
			CruiserCounter++;
		}
		else {
			cout << "not empty" << endl;
			system("pause");
		}
	}

}

void SetDestroyer(int& DestroyerCounter) {
	cout << "Enter x : ";
	int x;
	cin >> x;

	cout << "Enter y : ";
	char y;
	cin >> y;
	y = toupper(y);

	if (Check(x+1, y+1)) {
		if (isEmpty(x+1, y+1, 1, 'r')) {
			SetShip(x + 1, y + 1, 1, 'r');
			DestroyerCounter++;
		}
		else {
			cout << "not empty" << endl;
			system("pause");
		}
	}

}

void ShowShip(int c,int d) {
	mysetcolor(green, 0);
	for (size_t j = 0; j < d; j++)
	{
		for (size_t i = 0; i < c; i++)
		{
			cout << char(237);
		}
		cout << " ";
	}
	mysetcolor(white, 0);
}


void GetShipsManual() {
	//Carrier    ->4
	//BattleShip ->3
	//Cruiser    ->2
	//Destroyer  ->1
	int Ccount = 0;
	int Bcount = 0;
	int Rcount = 0;
	int Dcount = 0;
	while (Ccount != 1 || Bcount != 2 || Rcount != 3 || Dcount != 4)
	{
		char ShipName = ' ';
		if (Ccount != 1) { cout << "\nCarrier    ->"; ShowShip(4, 1-Ccount); cout << " (c)" ; }
		if (Bcount != 2) { cout << "\nBattleShip ->"; ShowShip(3, 2 -Bcount); cout << " (b)"; }
		if (Rcount != 2) { cout << "\nCruiser    ->"; ShowShip(2,3- Rcount); cout << " (d)"; }
		if (Dcount != 4) { cout << "\nDestroyer  ->"; ShowShip(1,4-Dcount); cout << " (c)"; }
		cout << "\nEnter Ship Name : ";
		cin >> ShipName;
		ShipName = tolower(ShipName);
		if (ShipName == 'c') {
			if (Ccount < 1) {
				SetCarrier(Ccount);
				system("cls");
				ShowGame();
			}
			else {
				cout << "Carrier can't be greather than 1." << endl;
				system("pause");
				system("cls");
				ShowGame();
			}

		}
		else if (ShipName == 'b') {
			if (Bcount < 2) {
				SetBattleship(Bcount);
				system("cls");
				ShowGame();
			}
			else {
				cout << "Battleship can't be greather than 2." << endl;
				system("pause");
				system("cls");
				ShowGame();
			}


		}
		else if (ShipName == 'r') {
			if (Rcount < 3) {
				SetCruiser(Rcount);
				system("cls");
				ShowGame();
			}
			else {
				cout << "Cruiser can't be greather than 3." << endl;
				system("pause");
				system("cls");
				ShowGame();
			}
		}

		else if (ShipName == 'd') {
			if (Dcount < 4) {
				SetDestroyer(Dcount);
				system("cls");
				ShowGame();
			}
			else {
				cout << "Destroyer can't be greather than 4." << endl;
				system("pause");
				system("cls");
				ShowGame();
			}
		}
		else {
			cout << "There is not such ship name. You can see ship names in RULES." << endl;
		}
	}
}

void GetShipsAuto() {
	int Ccount = 0;
	int Bcount = 0;
	int Rcount = 0;
	int Dcount = 0;
	int x = 0;
	char y = 0;

	while (Ccount != 1 )
	{
		/*---------Carrier---------*/
		x = 1 + rand() % (width - 1);
		y = 66 + rand() % (76 - 66);
		if (isEmpty(x, y, 4, 'u')) {
			SetShip(x,y,4,'u');
			Ccount++;
		}
		else if (isEmpty(x, y, 4, 'l')) {
			SetShip(x, y, 4, 'l');
			Ccount++;
		}
		else if (isEmpty(x, y, 4, 'r')) {
			SetShip(x, y, 4, 'r');
			Ccount++;
		}
		else if (isEmpty(x, y, 4, 'd')) {
			SetShip(x, y, 4, 'd');
			Ccount++;
		}
	}

		/*--------BattleShip--------*/
	while (Bcount != 2)
	{
		x = 1 + rand() % (width - 1);
		y = 66 + rand() % (76 - 66);
		if (isEmpty(x, y, 3, 'u')) {
			SetShip(x, y, 3, 'u');
			Bcount++;
		}
		else if (isEmpty(x, y, 3, 'l')) {
			SetShip(x, y, 3, 'l');
			Bcount++;
		}
		else if (isEmpty(x, y, 3, 'd')) {
			SetShip(x, y, 3, 'd');
			Bcount++;
		}
		else if (isEmpty(x, y, 3, 'r')) {
			SetShip(x, y, 3, 'r');
			Bcount++;
		}
	}
		/*-------------------------*/
	while (Rcount != 3)
	{
		x = 1 + rand() % (width - 1);
		y = 66 + rand() % (76 - 66);
		if (isEmpty(x, y, 2, 'd')) {
			SetShip(x, y, 2, 'd');
			Rcount++;
		}
		else if (isEmpty(x, y, 2, 'u')) {
			SetShip(x, y, 2, 'u');
			Rcount++;
		}
		else if (isEmpty(x, y,2, 'r')) {
			SetShip(x, y, 2, 'r');
			Rcount++;
		}
		else if (isEmpty(x, y, 2, 'l')) {
			SetShip(x, y, 2, 'l');
			Rcount++;
		}
	}
		
		/*-------------------------*/

	while (Dcount !=4)
	{
		x = 1 + rand() % (width - 1);
		y = 66 + rand() % (76 - 66);
		if (isEmpty(x, y, 1, 'r')) {
			SetShip(x, y, 1, 'r');
			Dcount++;
		}
	}
}

bool isEmptyComp(const int& x, const char& y1, const int& c, const char& d) {
	//d -destination
	int y = (int)y1 - 65;
	if (d == 'r') {
		if (x + c <= 11) {
			for (size_t i = 0; i < c; i++)
			{
				if (computer[y][x + i] == 1 || computer[y - 1][x + i] == 1 || computer[y + 1][x + i] == 1) {
					return false;
				}
			}
			if (computer[y][x - 1] == 1 || computer[y - 1][x - 1] == 1 || computer[y + 1][x - 1] == 1 ||
				computer[y][x + c] == 1 || computer[y - 1][x + c] == 1 || computer[y + 1][x + c] == 1) {
				return false;
			}
		}
		else return false;
	}
	/*------------------------------------------*/
	else if (d == 'l') {
		if (x - c >= 1) {

			for (size_t i = 0; i < c; i++)
			{
				if (computer[y][x - i] == 1 || computer[y - 1][x - i] == 1 || computer[y + 1][x - i] == 1) {
					return false;
				}
			}
			if (computer[y][x + 1] == 1 || computer[y - 1][x + 1] == 1 || computer[y + 1][x + 1] == 1 ||
				computer[y][x - c] == 1 || computer[y - 1][x - c] == 1 || computer[y + 1][x - c] == 1) {
				return false;
			}
		}
		else return false;
	}
	/*------------------------------------------*/
	else if (d == 'u') {
		if (y - c >= 1) {

			for (size_t i = 0; i < c; i++)
			{
				if (computer[y - i][x] == 1 || computer[y - i][x - 1] == 1 || computer[y - i][x + 1] == 1) {
					return false;
				}
			}
			if (computer[y + 1][x] == 1 || computer[y + 1][x - 1] == 1 || computer[y + 1][x + 1] == 1 ||
				computer[y - c][x] == 1 || computer[y - c][x - 1] == 1 || computer[y - c][x + 1] == 1) {
				return false;
			}
		}
		else return false;
	}
	/*------------------------------------------*/
	else if (d == 'd') {
		if (y + c <= 11) {

			for (size_t i = 0; i < c; i++)
			{
				if (computer[y + i][x] == 1 || computer[y + i][x - 1] == 1 || computer[y + i][x + 1] == 1) {
					return false;
				}
			}
			if (computer[y - 1][x] == 1 || computer[y - 1][x - 1] == 1 || computer[y - 1][x + 1] == 1 ||
				computer[y + c][x] == 1 || computer[y + c][x - 1] == 1 || computer[y + c][x + 1] == 1) {
				return false;
			}
		}
		else return false;
	}

	return true;
}

void SetShipComp(const int& x, const char& y1, const int& c, const char& d) {
	int y = (int)y1 - 65;
	if (d == 'r') {
		for (size_t i = 0; i < c; i++)
		{
			computer[y + 1][x + i] = 2;
			computer[y - 1][x + i] = 2;
			computer[y][x + i] = 1;
		}
		computer[y][x - 1] = 2;
		computer[y - 1][x - 1] = 2;
		computer[y + 1][x - 1] = 2;
		computer[y][x + c] = 2;
		computer[y - 1][x + c] = 2;
		computer[y + 1][x + c] = 2;
	}
	/*------------------------------------------*/
	else if (d == 'l') {
		for (size_t i = 0; i < c; i++)
		{
			computer[y + 1][x - i] = 2;
			computer[y - 1][x - i] = 2;
			computer[y][x - i] = 1;
		}
		computer[y][x + 1] = 2;
		computer[y - 1][x + 1] = 2;
		computer[y + 1][x + 1] = 2;
		computer[y][x - c] = 2;
		computer[y - 1][x - c] = 2;
		computer[y + 1][x - c] = 2;

	}
	/*------------------------------------------*/
	else if (d == 'u') {
		for (size_t i = 0; i < c; i++)
		{
			computer[y - i][x] = 1;
			computer[y - i][x - 1] = 2;
			computer[y - i][x + 1] = 2;
		}
		computer[y + 1][x - 1] = 2;
		computer[y + 1][x] = 2;
		computer[y + 1][x + 1] = 2;
		computer[y - c][x - 1] = 2;
		computer[y - c][x] = 2;
		computer[y - c][x + 1] = 2;
	}
	/*------------------------------------------*/
	else if (d == 'b') {
		for (size_t i = 0; i < c; i++)
		{
			computer[y + i][x - 1] = 2;
			computer[y + i][x] = 1;
			computer[y + i][x + 1] = 2;
		}
		computer[y - 1][x - 1] = 2;
		computer[y - 1][x] = 2;
		computer[y - 1][x + 1] = 2;
		computer[y + c][x - 1] = 2;
		computer[y + c][x] = 2;
		computer[y + c][x + 1] = 2;
	}
}


void GetShipsAutoComputer() {
	int Ccount = 0;
	int Bcount = 0;
	int Rcount = 0;
	int Dcount = 0;
	int x = 0;
	char y = ' ';

	while (Ccount != 1)
	{
		/*---------Carrier---------*/
		x = 1 + rand() % (11 - 1);
		y = 66 + rand() % (76 - 66);
		if (isEmptyComp(x, y, 4, 'r')) {
			SetShipComp(x, y, 4, 'r');
			Ccount++;
		}
		else if (isEmptyComp(x, y, 4, 'l')) {
			SetShipComp(x, y, 4, 'l');
			Ccount++;
		}
		else if (isEmptyComp(x, y, 4, 'u')) {
			SetShipComp(x, y, 4, 'u');
			Ccount++;
		}
		else if (isEmptyComp(x, y, 4, 'd')) {
			SetShipComp(x, y, 4, 'd');
			Ccount++;
		}
	}

	/*--------BattleShip--------*/
	while (Bcount != 2)
	{
		x = 1 + rand() % (11 - 1);
		y = 66 + rand() % (76 - 66);
		if (isEmptyComp(x, y, 3, 'r')) {
			SetShipComp(x, y, 3, 'r');
			Bcount++;
		}
		else if (isEmptyComp(x, y, 3, 'l')) {
			SetShipComp(x, y, 3, 'l');
			Bcount++;
		}
		else if (isEmptyComp(x, y, 3, 'u')) {
			SetShipComp(x, y, 3, 'u');
			Bcount++;
		}
		else if (isEmptyComp(x, y, 3, 'd')) {
			SetShipComp(x, y, 3, 'd');
			Bcount++;
		}
	}
	/*-------------------------*/
	while (Rcount != 3)
	{
		x = 1 + rand() % (11 - 1);
		y = 66 + rand() % (76 - 66);
		if (isEmptyComp(x, y, 2, 'r')) {
			SetShipComp(x, y, 2, 'r');
			Rcount++;
		}
		else if (isEmptyComp(x, y, 2, 'l')) {
			SetShipComp(x, y, 2, 'l');
			Rcount++;
		}
		else if (isEmptyComp(x, y, 2, 'u')) {
			SetShipComp(x, y, 2, 'u');
			Rcount++;
		}
		else if (isEmptyComp(x, y, 2, 'd')) {
			SetShipComp(x, y, 2, 'd');
			Rcount++;
		}
	}

	/*-------------------------*/

	while (Dcount != 4)
	{
		x = 1 + rand() % (11 - 1);
		y = 66 + rand() % (76 - 66);
		if (isEmptyComp(x, y, 1, 'r')) {
			SetShipComp(x, y, 1, 'r');
			Dcount++;
		}
	}
}


bool IsBurst(const int&x,const int&y) {

	if (computer[y][x + 1] == 1 || computer[y][x - 1] == 1 || computer[y - 1][x] == 1 || computer[y + 1][x] == 1) {
		return false;
	}
	return true;
}

bool IsBurstComp(const int& x, const int& y) {

	if (game[y][x + 1] == 1 || game[y][x - 1] == 1 || game[y - 1][x] == 1 || game[y + 1][x] == 1) {
		return false;
	}
	return true;
}




void ShowComputerGame() {
	int col = 0;
	int row = 65;
	mysetcolor(yellow, 0);
	cout << "Unburst ship count : " << ComputerShipCount << endl;
	mysetcolor(white, 0);
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			if (x == 0 && y == 0) {
				cout << "  ";
			}
			else if (y == 0) {
				cout << col++ << " ";
			}
			else if (x == 0) {
				cout << char(row) << " ";
				row++;
			}
			/*else if (computer[y][x] == 1) {
				mysetcolor(yellow, 0);
				cout << char(237) << " ";
				mysetcolor(white, 0);
			}*/
			else if (computer[y][x] == 0 || computer[y][x] == 2 || computer[y][x] == 1) {
				mysetcolor(blue, 0);
				cout << char(176) << " ";
				mysetcolor(white, 0);
			}
			else if (computer[y][x] == 3) {
				mysetcolor(yellow, 0);
				cout << char(235) << " ";
				mysetcolor(white, 0);
			}
			else if (computer[y][x] == 4) {
				mysetcolor(red, 0);
				cout << char(237) << " ";
				mysetcolor(white, 0);
			}

			//else cout << "  ";
		}cout << endl;
	}
}




void Show() {
	system("cls");
	mysetcolor(yellow, 0);
	cout << "Unburst ship count : " << PlayerShipCount << endl;
	mysetcolor(white, 0);
	ShowGame();
	cout << endl;
	ShowComputerGame();
}


void PlayerHitShips() {
	bool HasShot = false;
	do {
		{
			if (ComputerShipCount == 0) {
				//cout << "YOU WON" << endl;
				return;
			}
			HasShot = false;
			char x1 = ' ';
			char y1 = ' ';
			cout << "Enter x : ";
			cin >> x1;
			x1 = toupper(x1);
			int x = (int)x1 - 48;
			if (x < 0 || x > 9) {
				system("cls");
				Show();
				HasShot = true;
				continue;
			}
			cout << "Enter y : ";
			cin >> y1;

			y1 = toupper(y1);
			if (Check(x + 1, y1 + 1)) {
				int y = (int)y1 - 65;
				if (computer[y + 1][x + 1] != 3 && computer[y + 1][x + 1] != 4) {

					if (computer[y + 1][x + 1] == 1) {
						ComputerShipCount--;
						HasShot = true;
						computer[y + 1][x + 1] = 4;
						if (IsBurst(x + 1, y + 1)) {
							Show();
							PlaySound(TEXT("Musics/HitShipSong.wav"), NULL, SND_SYNC);
						}
						else {
							Show();
							cout << "\a";
						}

					}
					else {
						HasShot = false;
						computer[y + 1][x + 1] = 3;
						Show();
						PlaySound(TEXT("Musics/WaterSound.wav"), NULL, SND_SYNC);
					}
				}
				else {
					HasShot = true;
				}
			}
			else {
				HasShot = true;
			}
			Show(); 
		}
	} while (HasShot);
}

//void GORIGHT(int x,int y) {
//	if (game[y][x + 1] == 0) {
//		if (game[y][x + 1] == 1) {
//			PlayerShipCount--;
//			game[y][x + 1] = 4;
//			if (IsBurst(x, y)) {
//				PlaySound(TEXT("Musics/HitShipSong.wav"), NULL, SND_SYNC);
//				AI[0] = 0;
//				AI[1] = 0;
//			}
//			else {
//				GORIGHT(x, y);
//				cout << "\a";
//				Sleep(1000);
//			}
//		}
//	}
//}


void ArtificialIntelligent(bool& HasShot) {
	int x = AI[0] + 1;
	int y = AI[1] + 1;

	if (game[y][x + 1] ==0 || game[y][x + 1] ==2 || game[y][x + 1] == 1) {
		if (game[y][x + 1] == 1) {
			PlayerShipCount--;
			game[y][x + 1] = 4;
			Show();
			if (IsBurstComp(x, y)) {
				PlaySound(TEXT("Musics/HitShipSong.wav"), NULL, SND_SYNC);
				AI[0] = 0;
				AI[1] = 0;
			}
			else {
				AI[0] = x;
				AI[1] = y - 1;
				cout << "\a";
				Sleep(1000);
			}
			HasShot = true;
		}
		else {
			HasShot = false;
			game[y][x + 1] = 3;
			Show();
			PlaySound(TEXT("Musics/WaterSound.wav"), NULL, SND_SYNC);
		}
	}

	else if (game[y][x - 1] ==0 || game[y][x - 1] == 2 || game[y][x - 1] == 1) {
		if (game[y][x - 1] == 1) {
			PlayerShipCount--;
			game[y][x - 1] = 4;
			Show();
			if (IsBurstComp(x, y)) {
				AI[0] = 0;
				AI[1] = 0;
				PlaySound(TEXT("Musics/HitShipSong.wav"), NULL, SND_SYNC);
			}
			else {
				AI[0] = x - 2;
				AI[1] = y - 1;
				cout << "\a";
				Sleep(1000);
			}
			HasShot = true;
		}
		else {
			HasShot = false;
			game[y][x - 1] = 3;
			Show();
			PlaySound(TEXT("Musics/WaterSound.wav"), NULL, SND_SYNC);
		}
	}

	else if (game[y - 1][x] == 0 || game[y - 1][x] == 2 || game[y - 1][x] == 1) {
		if (game[y - 1][x] == 1) {
			PlayerShipCount--;
			game[y - 1][x] = 4;
			Show();
			if (IsBurstComp(x, y)) {
				AI[0] = 0;
				AI[1] = 0;
				PlaySound(TEXT("Musics/HitShipSong.wav"), NULL, SND_SYNC);
			}
			else {
				AI[0] = x - 1;
				AI[1] = y - 2;
				cout << "\a";
				Sleep(1000);
			}
			HasShot = true;
		}
		else {
			HasShot = false;
			game[y - 1][x] = 3;
			Show();
			PlaySound(TEXT("Musics/WaterSound.wav"), NULL, SND_SYNC);
		}
	}

	else if (game[y + 1][x] == 0 || game[y + 1][x] ==2 || game[y + 1][x] == 1) {
		if (game[y + 1][x] == 1) {
			PlayerShipCount--;
			game[y + 1][x] = 4;
			Show();
			if (IsBurstComp(x, y)) {
				AI[0] = 0;
				AI[1] = 0;
				PlaySound(TEXT("Musics/HitShipSong.wav"), NULL, SND_SYNC);
			}
			else {
				AI[0] = x - 1;
				AI[1] = y;
				cout << "\a";
				Sleep(1000);
			}
			HasShot = true;
		}
		else {
			HasShot = false;
			game[y + 1][x] = 3;
			Show();
			PlaySound(TEXT("Musics/WaterSound.wav"), NULL, SND_SYNC);
		}
	}
	else {
		HasShot = false;
		AI[0] = 0;
		AI[1] = 0;
		return;
	}
}



void ComputerHitShips() {

	bool HasShot = false;
	do {
		if (PlayerShipCount == 0) {
			//cout << "COMPUTER WON" << endl;
			return;
		}
		HasShot = false;
		int x = 0;
		int y = 0;
		if (AI[0] == 0 && AI[1] == 0) {
			x = 0 + rand() % (10 - 0);
			y = 0 + rand() % (10 - 0);

			if (game[y + 1][x + 1] != 3 && game[y + 1][x + 1] != 4) {
				if (game[y + 1][x + 1] == 1) {
					AI[0] = x;
					AI[1] = y;
					HasShot = true;
					PlayerShipCount--;
					game[y + 1][x + 1] = 4;
					if (IsBurstComp(x + 1, y + 1)) {
						AI[0] = 0;
						AI[1] = 0;
						Show();
						PlaySound(TEXT("Musics/HitShipSong.wav"), NULL, SND_SYNC);
					}
					else {
						Show();
						cout << "\a";
						Sleep(1000);
						ArtificialIntelligent(HasShot);
					}
				}
				else {
					game[y + 1][x + 1] = 3;
					Show();
					PlaySound(TEXT("Musics/WaterSound.wav"), NULL, SND_SYNC);
					HasShot = false;
				}

			}
			else {
				HasShot = true;
			}
		}
		else {
			ArtificialIntelligent(HasShot);

		}

		Show();

	} while (HasShot);
}

void Hits() {
	while (true)
	{
		if (PlayerShipCount == 0) {
			cout << "COMPUTER WIN" << endl;
			PlaySound(TEXT("Musics/LoseSong.wav"), NULL, SND_SYNC);
			return;
		}
		else if(ComputerShipCount == 0) {
			cout << "YOU WIN" << endl;
			PlaySound(TEXT("Musics/WinSong.wav"), NULL, SND_SYNC);
			return;
		}
		PlayerHitShips();
		if (PlayerShipCount == 0) {
			cout << "COMPUTER WIN" << endl;
			PlaySound(TEXT("Musics/LoseSong.wav"), NULL, SND_SYNC);
			return;
		}
		else if (ComputerShipCount == 0) {
			cout << "YOU WIN" << endl;
			PlaySound(TEXT("Musics/WinSong.wav"), NULL, SND_SYNC);
			return;
		}
		ComputerHitShips();
	}
	
}


void GAME() {

	while (true)
	{
		
		system("cls");
		cout << "Auto (1), Manual (2), back (0) : ";
		int select = 0;
		cin >> select;
		system("cls");
		if (select == 1) {
			GetShipsAuto();
			ShowGame();
		}
		else if (select == 2) {
			cout << "\tPLAYER 1, PLEASE FILL SHIPS\n" << endl;
			ShowGame();
			GetShipsManual();
		}
		else {
			break;
		}
		//system("pause");
		/*-----------------WAR------------------*/
		system("cls");
		GetShipsAutoComputer();
		
		Show();
		cout << endl;
		Hits();
		system("pause");
		break;
	}
}

void ShowMenu() {
	cout << "\n\n\n";
	mysetcolor(red, 0);
	cout << "    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout << "    *                                                                                                                                                                                               *"<<endl;
	cout << "    *  ** * * * * * *     ***************   *****************  *****************   **                  ** * * * * * *      ***************    **           **     *********      ***************    *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                  ***************    **           **         *          **           **    *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                  **                 **           **         *          **           **    *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                  **                 **           **         *          **           **    *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                  **                 **           **         *          **           **    *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                  **                 **           **         *          **           **    *"<<endl;
	cout << "    *  ** * * * * * *     ***************          **                 **           **                  ** * * * * * *      ***************    ***************         *          ***************    *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                               **    **           **         *          **                 *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                               **    **           **         *          **                 *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                               **    **           **         *          **                 *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                               **    **           **         *          **                 *"<<endl;
	cout << "    *  **           *     **           **          **                 **           **                  **                  ***************    **           **         *          **                 *"<<endl;
	cout << "    *  ** * * * * * *     **           **          **                 **           *****************   ** * * * * * *      ***************    **           **     *********      **                 *"<<endl;
	cout << "    *                                                                                                                                                                                               *"<<endl;
	cout << "    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	
	/*---------------------------*/
	cout << "\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\t  ";
	mysetcolor(red, 0);
	cout << "GAME 1 :" << endl;

	cout << "\t\t\t\t\t\t\t\t\t\t\t  ";
	cout << "RULES 2 :" << endl;

	cout << "\t\t\t\t\t\t\t\t\t\t\t  ";
	cout << "EXIT 0 :" << endl;
	mysetcolor(white, 0);
	cout << "\t\t\t\t\t\t\t\t\t\t\t     ";
}