#include "DataHandler.h"

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <ctime>
#include <boost/algorithm/string.hpp>

using std::string;
using std::rand;
using std::swap;
using std::fstream;
using std::ios;
using std::exit;
using std::getline;
using std::cout;
using std::cerr;
using std::endl;
using std::size_t;
using std::runtime_error;
using std::time;
using boost::split;
using boost::is_any_of;


vector<Question> DataHandler::loadQuestions(const string& filename)
{
    fstream csvRead;
    vector<Question> questions;

    try
    {
        csvRead.open(filename, ios::in);
        if (!csvRead.is_open())
        {
            throw runtime_error("Failed to open the file: " + filename);
        }
        string line;
        getline(csvRead, line); // Skip the header line
        while (getline(csvRead, line))
        {
            std::vector<string> tokens;
            split(tokens, line, is_any_of(","), boost::token_compress_off);

            if (tokens.size() < 4) // 1 question + 3 answers
            {
                cerr << "Malformed line: " << line << endl;
                continue;
            }

            string questionText = tokens[0];
            Answer answers[3];
            for (int i = 0; i < 3; ++i)
            {
                string answerText = tokens[i + 1];
                bool isCorrect = (!answerText.empty() && answerText.front() == '*');
				if (isCorrect) answerText.erase(0, 1); // Remove the '*' character if present
                answers[i] = Answer(answerText, isCorrect);
            }

            Question question(questionText, answers[0], answers[1], answers[2]);
            questions.push_back(question);
        }

        csvRead.close();
        if (questions.empty())
        {
			throw runtime_error("No questions loaded from the file.");
        }
        else
        {
            cout << "Questions loaded successfully." << endl;
            DataHandler::shuffleQuestions(questions);
            return questions;
        }
    }
    catch (const std::exception& ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}

// Algorythm to shuffle questions and answers
void DataHandler::shuffleQuestions(vector<Question>& questions)
{
    
    int rnd;
	srand(time(0)); // Seed the random number generator with current time so each time the program runs, it shuffles differently

    if(questions.empty())
    {
        cerr << "No questions to shuffle." << endl;
        return;
	}
	
    for (size_t i = 0; i < questions.size(); ++i)
    {
        rnd = rand() % questions.size();
		if (rnd == i) continue; // Avoid swapping with itself
		swap(questions[i], questions[rnd]);
		// Shuffle answers within each question
		questions[i].shuffleAnswers();
    }
	cout << "Questions shuffled successfully." << endl;
}