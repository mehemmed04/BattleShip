#pragma once
#include<iostream>
#include"Functions.h"
using namespace std;

void Start() {
	srand(time(0));
	while (true)
	{
		
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t k = 0; k < 11; k++)
			{
				if (i == 0) game[i][k] = 9;
				else if (k == 0) game[i][k] = 9;
				else {
					game[i][k] = 0;
					computer[i][k] = 0;
				}
			}
		}
		int PlayerShipCount = 20;
		int ComputerShipCount = 20;

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