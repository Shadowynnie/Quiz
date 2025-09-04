# Quiz
# C++ Structures Educational Project

This project demonstrates the use of C++ structures and basic file I/O by implementing a simple console-based quiz application.

## Features

- Loads quiz questions and answers from a CSV file
- Supports shuffling of questions and answers
- Colored console output for correct and incorrect answers (multiplatform, using ANSI escape codes)
- Example of struct usage, constructors, and member functions in C++
- Input validation for user responses

## Getting Started

### Prerequisites

- C++20 compatible compiler (tested with Visual Studio 2022)
- [Boost](https://www.boost.org/) library (for string splitting)
- A CSV file named `questions.csv` in the executable directory, formatted as:
question,answer1,answer2,answer3
What is the capital of France?,Berlin,*Paris,Rome
What does CPU stand for?,*Central Processing Unit,Computer Personal Unit,Central Performance Utility
Who wrote "Romeo and Juliet"?,Charles Dickens,*William Shakespeare,Jane Austen
Which planet is known as the Red Planet?,*Mars,Jupiter,Venus
What is the largest mammal in the world?,African Elephant,Giraffe,*Blue Whale
What is the chemical symbol for Gold?,Go,Gd,*Au
In which year did World War II end?,1939,*1945,1951
What is the square root of 64?,6,*8,10
Which continent is the Sahara Desert located on?,*Africa,Asia,South America
Who is known as the founder of Microsoft?,Steve Jobs,*Bill Gates,Mark Zuckerberg
