// Math Quiz
// Brandon Bullock

#include <iostream>
#include <conio.h>
#include <vector> // include the vector library
#include <string>
#include <fstream> // include the fstream library for file I/O>

using namespace std;


string readQuestionsFromTextFile(vector<string>& questions, const string& filePath) 
{
	// ask user for the path to the text file containing questions
	cout << "For this exercise, we will simulate a student taking a math quiz. To set things up, do you have a text file containing the questions (y/n)? \n" "NOTE: We will create one otherwise. This would not be asked in a live application, but is being done here for the sake of this exercise. \n";
	string existingFile;
	cin >> existingFile;
	if (existingFile == "y")
	{
		// ask the user for the path to the text file containing questions
		cout << "Please enter the path to the text file containing the questions: ";
		string filePath;
		cin >> filePath;
		ifstream ifs(filePath);
		if (!ifs)
		{
			cout << "Error opening file. Please check the path and try again. Press 'n' if you would like one created.\n";
			cin.ignore();
			cin.get();
		}
	}
	else
	{
		// create a text file with some sample questions
		cout << "No text file provided. Creating: C:\\Temp\\QuizQuestions.txt \n";

		string filePath = "C:\\Temp\\QuizQuestions.txt"; // path to text file to save
		string input;

		questions.push_back("1 + 1");	// 1 + 1
		questions.push_back("2 * 3");	// 2 * 3
		questions.push_back("4 / 2");	// 4 / 2
		questions.push_back("5 - 3");	// 5 - 3
		questions.push_back("6 + 4");	// 6 + 4
		questions.push_back("8 * 2");	// 8 * 2
		questions.push_back("10 / 5");	// 10 / 5
		questions.push_back("7 - 2");	// 7 - 2
		questions.push_back("9 + 1");	// 9 + 1
		questions.push_back("3 * 5");	// 3 * 5

		#pragma region Old ways to itterate through vector
		// iterate through the vector and print out the questions
			/*for (int i = 0; i < questions.size(); i++)
			{
				cout << questions[i] << "\n";
			}*/

			// faster way to iterate through a vector using an iterator
				/*vector<string>::iterator it = questions.begin();
				for ( ; it != questions.end(); ++it )
				{
					cout << *it << "\n";
				}*/
		#pragma endregion

		//newer way to iterate through a vector using a range-based for loop
		for (const string& i : questions)
		{
			cout << i << "\n";
		}		

		ofstream ofs(filePath);

		ofs << input << "\n"; // write the questions to the file
		for (const string& i : questions)
		{
			ofs << i << "\n";
		}
		ofs.close();

		return filePath;
	}

	// Read the questions from the text file and store them in memory.

}

//int generateRandomMathProblems()
//{
//	// call this once before you call rand()
//	srand(time(NULL)); // initialize the random number generator
//
//	// get a random number between 1 & 10
//	int randomNumber = rand() % 10 + 1;
//	
//	string input;
//	getline(cin, input); // get the user's answer
//	cout << input;
//}

//void saveResultsToTextFile()
//{
//	string filePath = "C:\\Temp\\QuizResults.txt"; // path to text file to save results
//	ofstream ofs(filePath);
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

	string filePath; // path to text file containing questions
	string otherPath; // path to text file containing questions

	string question; // variable to store the question
	ifstream ifs(filePath);
	while (getline(ifs, question))
	{
		int n = stoi(question); // convert the string to an integer)
		cout << question << "\n";
	}

	vector<string> questions; // vector to store the questions
	
	// Read the questions from the text file and store them in memory.
	filePath = readQuestionsFromTextFile(questions, filePath);

	//	string line;
	//	ifstream ifs(filePath);
	//	while (getline(ifs, line))
	//	{
	//		cout << line << "\n";
	//	}
	//	ifs.close();

	////Generate three random math problems for the user to solve:
	//	generateRandomMathProblems();

	////Save the question, along with the user's answer, to a text file called QuizResults.txt.
	//	saveResultsToTextFile();

	for (const string& i : questions)
	{
		cout << i << "\n";
	}

	(void)_getch();
	return 0;
} 