#include "Question.h"
//#include "Answer.h"

using std::cout;
using std::endl;
using std::swap;
using std::size;

Question::Question(const string& text, const Answer& ans1, const Answer& ans2, const Answer& ans3)
	: questionText(text)
{
	answers[0] = ans1;
	answers[1] = ans2;
	answers[2] = ans3;
}

void Question::Response(const int answerNum, int &correctAns, int &wrongAns) const
{
	if (answers[answerNum].isCorrect)
	{
		cout << "\033[32mCorrect!\033[0m\n\n--------------------------------------------------------------------------------" << endl;
		correctAns++;
	}
	else
	{
		//cout << "Incorrect. The correct answer is: " << this->getCorrectAnswer().answerText << "\n\n--------------------------------------------------------------------------------" << endl;
		cout << "\033[31mIncorrect. The correct answer is: " << this->getCorrectAnswer().answerText << "\033[0m"
			<< "\n\n--------------------------------------------------------------------------------" << endl;
		wrongAns++;
	}
}

Answer Question::getCorrectAnswer() const
{
	for (const Answer answer : answers)
	{
		if (answer.isCorrect)
		{
			return answer;
		}
	}
	return Answer(); // Return a default Answer if no correct answer is found
}

void Question::shuffleAnswers()
{
	srand(time(0)); // Seed the random number generator with current time so each time the program runs, it shuffles differently
	for (int i = 0; i < 3; ++i)
	{
		int j = rand() % size(this->answers); // Generate a random index
		swap(answers[i], answers[j]); // Swap the answers
	}
}
