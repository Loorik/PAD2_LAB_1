#pragma once
//MasterMindDigits.h
#include <iostream>

class MasterMindDigits
{
	friend std::istream& operator>>(std::istream&, MasterMindDigits&);

public:
	MasterMindDigits(unsigned = 0);	
	MasterMindDigits(const MasterMindDigits&);
	~MasterMindDigits();
	const MasterMindDigits& operator=(unsigned&);

	void makeDigitsToGuess();
	unsigned locationRight(MasterMindDigits) const;
	unsigned locationWrong(MasterMindDigits) const;
	operator unsigned() const;


private:
	unsigned int* digits;

};