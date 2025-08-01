#include <iostream>
#include <string>
#include <iterator>

#include "Question.h"
#include "Answer.h"
#include "DataHandler.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::size_t;
using std::size; // Returns the size of an array or container (C++17 and later)
using std::vector;
using std::copy;

/**
* This program demonstrates the use of structures in C++.
* It defines a simple structure for a quiz question and its answers.
* Structures have all members public by default.
* Structures and Classes are similar in C++, but structures are typically used for simple data structures.
* Both Structures and Classes can have methods, constructors, destructors, and inheritance.
*/

// This is just a testing function to load questions.
void loadQuestions(Question* questionSet)
{
    questionSet[0] = Question("What is the capital of France?", 
        Answer("Paris", true), 
        Answer("London", false), 
		Answer("Berlin", false));
    questionSet[1] = Question("What does CPU stand for?",
        Answer("Central Processing Unit", true),
        Answer("Computer Personal Unit", false),
        Answer("Central Performance Utility", false));
	questionSet[2] = Question("Who wrote \"Romeo and Juliet\"?",
        Answer("William Shakespeare", true),
        Answer("Mark Twain", false),
        Answer("Charles Dickens", false));
    questionSet[3] = Question("What is the largest planet in our solar system?",
        Answer("Jupiter", true),
        Answer("Saturn", false),
        Answer("Earth", false));
    questionSet[4] = Question("What is the chemical symbol for water?",
        Answer("H2O", true),
        Answer("CO2", false),
        Answer("O2", false));
}

void startQuiz(const Question* questionSet, int size)
{
	int correctAnswers = 0;
	int wrongAnswers = 0;

    for (size_t i = 0; i < size; i++)
    {
        int answerNum;
        cout << "Question: " << (i+1) << ". " << questionSet[i].questionText << endl;
		cout << "Possible answers:" << endl;

		// Display the possible answers
        for (size_t j = 0; j < 3; j++)
        {
            cout << (j+1) << ". " << questionSet[i].answers[j].answerText << endl;
        }
        cout << "Enter your answer 1-3: ";
        cin >> answerNum;

		// Check if the input is a valid number
        if (!cin.good() || answerNum > 3)
        {
            cout << "Enter a number (1-3) !" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--; // Decrement i to repeat the question
        }
        else
        {
            questionSet[i].Response(answerNum - 1, correctAnswers, wrongAnswers); // Adjust for 0-based index
        }
    }
	cout << "Quiz finished!" << endl;
	cout << "You answered " << correctAnswers << " questions correctly and " << wrongAnswers << " questions incorrectly." << endl;
}

int main()
{
	const string filePath = "questions.csv";

	vector<Question> questions = DataHandler::loadQuestions(filePath);
    Question questionSet[10];
	//loadQuestions(questionSet);
	copy(questions.begin(), questions.end(), questionSet);
	cout << "Welcome to the Quiz!" << endl;
	startQuiz(questionSet, size(questionSet));

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();

    return 0;
}
