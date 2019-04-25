//main
#include <iostream>
#include <ctime>
#include <string>
#include "MasterMindDigits.h"
using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	MasterMindDigits numberToGuess;

	bool checkValue = false;
	bool checkMode = true;

	char gameMode;
	unsigned myDigits;
	unsigned test;
	unsigned play;
	bool notCorrect = true;
	int tstcount = 0;
	int playcount = 0;

	cout << "Wilkommen bei MasterMindDigits!\n\nTest(0) oder Spielen(1)\n";
	cin >> gameMode;	

	while (checkMode)
	{
		if (gameMode == '0' || gameMode == '1')
		{
			checkValue = true;
			checkMode = false;
		}
		else
		{
			cout << "Eingabe nicht gueltig, bitte wiederholen:\n";
			cin >> gameMode;
		}
	}

	while (checkValue)
	{
		switch (gameMode)
		{
		case '0':

			cout << "Bitte geben sie eine Testzahl ein:\n";
			cin >> numberToGuess;

			while (notCorrect)
			{
				cout << "\nVersuchen Sie die Zahl zu erraten (Zahl muss 4 Stellig und aus 1-6 bestehen):\n ";
				cin >> myDigits;

				if (myDigits <= 6666 && myDigits >= 1111)
				{
					cout << "Zahlen an richtigen Stellen: " << to_string(numberToGuess.locationRight(myDigits)) << endl;
					cout << "Sonst richtig: " << to_string(numberToGuess.locationWrong(myDigits)) << endl;
					tstcount++;

					if (numberToGuess.locationRight(myDigits) == 4)
					{
						cout << "Sie haben es in " << tstcount << " Versuchen geschafft.\n" << endl;
						notCorrect = false;
						checkValue = false;
					}
				}
				else
				{
					cout << "Zahl ungueltig, bitte erneut eingeben:\n";
					cin >> myDigits;

				}
			}
			break;


		case '1':
			cout << "Spiel Modus ausgewaehlt:\n";
			numberToGuess.makeDigitsToGuess();

			while (notCorrect)
			{
				cout << "\nVersuchen Sie die Zahl zu erraten (Zahl muss 4 Stellig und aus 1-6 bestehen):\n ";
				cin >> play;


				if (play <= 6666 && play >= 1111)
				{
					cout << "Zahlen an richtigen Stellen: " << to_string(numberToGuess.locationRight(play)) << endl;
					cout << "Sonst richtig: " << to_string(numberToGuess.locationWrong(play)) << endl;
					playcount++;

					if (numberToGuess.locationRight(play) == 4)
					{
						cout << "Sie haben es in " << playcount << " Versuchen geschafft." << endl;
						notCorrect = false;
						checkValue = false;
					}
				}
				else
				{
					cout << "Zahl ungueltig, bitte erneut eingeben:\n";
				}
			}
			break;

		default:
			cout << "Ungueltige Eingabe!\n\nBitte 0 fur Test oder 1 fuer Spielen:\n";
			cin >> gameMode;
			break;
		}
	}
}
