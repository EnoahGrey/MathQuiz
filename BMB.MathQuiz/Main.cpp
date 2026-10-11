// Math Quiz
// Brandon Bullock

#include <iostream>
#include <conio.h>
#include <vector> // include the vector library
#include <string>
#include <fstream> // include the fstream library for file I/O>

using namespace std;

void readQuestionsFromTextFile(const string& filePath, vector<string>& questions, string& question) 
{		
	// Read the questions from the text file and store them in memory.
	ifstream ifs(filePath);
	while (getline(ifs, question))
	{
		questions.push_back(question); // add the question to the vector
	}

	ifs.close(); // free up the file.
	cout << "Preperation complete. \n";
}

string generateRandomMathProblems(const vector<string>& questions, const string& question, const string& resultsPath)
{	
	int quizSize = 3; // number of questions to ask the user
	int i = 0; // counter for the number of questions asked

	// call this once before you call rand()
	srand(time(NULL)); // initialize the random number generator

	// get a random number between 1 & 10
	int randomNumber = rand() % 10 + 1;
	
	while (i < quizSize)
	{
		string input; // variable to store the user's answer

		randomNumber = rand() % 10 + 1; // get a new random number if the previous one is out of range
		cout << questions[randomNumber] << " = ";
		cin >> input;
		getline(cin, input); // get the user's answer
		cout << "count is " << i << "\n"; // display the counter
		i++; // increment the counter
	}	

	return resultsPath; //this should return the user's answers to main() so that they can be saved to a text file, but I am not sure how to do that yet.
}

//void saveResultsToTextFile(const string& resultsPath)
//{
//	string resultsPath = resultsPath; // path to text file to save results
//	ofstream ofs(resultsPath);
//
//	ofs << input_iterator << "\n"; // write the user's answer to the file
//	ofs.close();
//}

int main()
{
	/*
		For this assignment, you will create a math quiz program in C++.The program will generate random math problems 
		for the user to solve.The user will be prompted to enter the answer to each problem, and the program will keep 
		track of the user's score.
	*/

	string filePath = "C:\\Temp\\QuizQuestions.txt"; // path to text file containing questions
	string resultsPath = "C:\\Temp\\QuizResults.txt"; // path to text file containing user answered questions

	vector<string> questions; // vector to store the question(s)
	string question; // variable to store the question being retrieved from the text file

	#pragma region File Check
	// check if question file exists, if not create one with some sample questions
	if (!ifstream(filePath))
	{
		cout << "No QuizQuestions.txt file found. Creating: C:\\Temp\\QuizQuestions.txt \n";
		ofstream ofs(filePath);
		ofs << "1 + 1 \n"; // 1 + 1
		ofs << "2 * 3 \n"; // 2 * 3
		ofs << "4 / 2 \n"; // 4 / 2
		ofs << "5 - 3 \n"; // 5 - 3
		ofs << "6 + 4 \n"; // 6 + 4
		ofs << "8 * 2 \n"; // 8 * 2
		ofs << "10 / 5 \n"; // 10 / 5
		ofs << "7 - 2 \n"; // 7 - 2
		ofs << "9 + 1 \n"; // 9 + 1
		ofs << "3 * 5 \n"; // 3 * 5
	}
	else
	{
		cout << "QuizQuestions.txt file found. The quiz Will commence! \n";
	}
	#pragma endregion
		
	// Read the questions from the text file and store them in memory.
	cout << "Reading questions from text file:\n";
	readQuestionsFromTextFile(filePath,questions, question);

	// Generate random math problems for the user to solve.
	cout << "Generating random math problems.\n";
	generateRandomMathProblems(questions, question, resultsPath);

	//// Save the user's answers to a text file.
	//cout << "Saving results to text file.\n";
	//saveResultsToTextFile(resultsPath);

	(void)_getch();
	return 0;
} 