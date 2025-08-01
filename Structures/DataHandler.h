#pragma once
#include <vector>
#include "Question.h"

using std::vector;

struct DataHandler
{
	// Function to load questions from a file
	static vector<Question> loadQuestions(const std::string& filename);
	// Function to shuffle the questions
	static void shuffleQuestions(vector<Question>& questions);
};