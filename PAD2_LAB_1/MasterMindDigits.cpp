//MasterMindDigits.cpp
#include <iostream>
#include <array>
#include "MasterMindDigits.h"
using namespace std;

MasterMindDigits::MasterMindDigits(unsigned number)
	:digits(new unsigned[4]{ 0 })
{
	if (number != 0)
	{
		/*for (int i = 3; i >= 0; i--)
		{
			digits[i] = number % 10;
			number /= 10;
		}*/
		*this = number;		//selbst definierter zuweisungsoperator
	}
}

MasterMindDigits::MasterMindDigits(const MasterMindDigits &orig)
	:digits(new unsigned[4]{ 0 })
{
	for (int i = 3; i >= 0; i--)		//rückwärts, damit zahlen richtige reihenfolge haben in digits
	{
		digits[i] = orig.digits[i];
	}
}

MasterMindDigits::~MasterMindDigits()
{
	delete[] digits;
}

void MasterMindDigits::makeDigitsToGuess()
{
	for (int i = 0; i < 4; i++)
	{
		digits[i] = 1 + (rand() % 6);
	}
}

unsigned MasterMindDigits::locationRight(MasterMindDigits my) const
{
	unsigned counter = 0;

	for (int i = 0; i < 4; i++)
	{
		if (digits[i] == my.digits[i])
		{
			counter++;
		}
	}
	return counter;
}

unsigned MasterMindDigits::locationWrong(MasterMindDigits my) const
{
	array<int, 4> alreadyConsideredInMy{ -1,-1,-1,-1 };		//Positionen merken
	array<int, 4> alreadyConsideredInPc{ -1,-1,-1,-1 };		//der bereits benutzten Ziffern
	unsigned counter = 0;

	for (int i = 0; i < 4; i++)			//schaue nach, ob in beiden digit arrays an der selben position die gleiche Ziffer steht
	{
		if (digits[i] == my.digits[i])
		{
			alreadyConsideredInMy[i] = i;		//falls die obere Bedingung zutrifft, speichere in das jeweilige lokale array die genutzte Position!
			alreadyConsideredInPc[i] = i;
		}
	}

	for (int i = 0; i < 4; i++)		//äußere schleife geht meine Zahlen durch
	{
		for (int j = 0; j < 4; j++)		//innere schleife geht andere Zahlen durch
		{
			if (digits[j] == my.digits[i])	//wenn an der gleiche Ziffern entdeckt werden
			{
				if (i != j)					//und position in meinem digits nicht gleich position im anderen digits ist
				{
					bool correct = true;
					for (int k = 0; k < 4; k++)	//gehe die lokalen arrays durch und schaue nach, ob die position scon mal vorkam
					{
						if (alreadyConsideredInMy[k] == i || alreadyConsideredInPc[k] == j)
						{
							correct = false;				//wenn sie schon vorgekommen ist, setze correct auf false und breche ab
							break;
						}
					}
					if (correct)
					{
						counter++;						//nur wenn die Position noch nicht "genutzt" wurde zähle den counter hoch
						alreadyConsideredInMy[i] = i;	//und füge die Positionen in das jeweilige lokale array ein
						alreadyConsideredInPc[j] = j;
					}
				}
				else
				{
					break;		//wenn sie sowieso nicht gleich sind, dann breche ab bzw. mach weiter
				}
			}
		}
	}

	return counter;
}

MasterMindDigits::operator unsigned() const
{
	unsigned number = 0;
	unsigned factor = 1;

	for (int i = 3; i >= 0; i++)
	{
		number += digits[i] * factor;
		factor *= 10;
	}

	return number;
}

istream& operator>>(istream& in, MasterMindDigits& m)
{
	unsigned number;
	in >> number;
	m = number;
	return in;
}

const MasterMindDigits& MasterMindDigits::operator=(unsigned& n)
{
	for (int i = 3; i >= 0; i--)
	{
		digits[i] = n % 10;
		n /= 10;
	}
	return *this;
}