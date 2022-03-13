#pragma once
#include<iostream>
#include"Functions.h"
using namespace std;

void Start() {
	srand(time(0));
	while (true)
	{
		
		/*cout << "\t\t\t\t\t\tBATTLESHIP GAME" << endl;
		cout << "\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t  GAME 1 :" << endl;
		cout << "\t\t\t\t\t\t  RULES 2 :" << endl;
		cout << "\t\t\t\t\t\t  EXIT 0 :" << endl;
		cout << "\t\t\t\t\t\t     ";*/
		ShowMenu();
		int select = 0;
		cin >> select;
		system("cls");
		if (select == 1) {
			GAME();
		}
		else if (select == 2) {
			ShowRules();
		}
		else if (select == 0) {
			break;
		}





		/*else {
			cout << "Invalid input. Try again" << endl;
		}*/
	}
}