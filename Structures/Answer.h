#pragma once
#include <string>

using std::string;

struct Answer
{
	string answerText;
	bool isCorrect;

	// Constructor to initialize the answer
	Answer(const string& text, bool correct);
	
	// Default constructor
	Answer() {};

};