#pragma once
#include <string>
#include <iostream>
#include "Answer.h"


using std::string;

struct Question
{
	string questionText;
	Answer answers[3];

	// Constructor to initialize the question with text and answers
	Question(const string& text, const Answer& ans1, const Answer& ans2, const Answer& ans3);

	Question() {}

	void Response(const int answerNum, int& correctAns, int& wrongAns) const;

	Answer getCorrectAnswer() const;

	// Function to shuffle the answers
	void shuffleAnswers();
};
