// Project1.cpp : 
// Your names: Daniel Nicolas and Joe Lane
//
#include <string>
#include <iostream>  
#include <sstream>
#include <map>
#include <cassert>
#include <regex>

using namespace std;
using std::istringstream;
using std::string;
using std::cout;
using std::endl;
using std::regex;

/*
   You must complete the function funWithCallLetter.
   funWithCallLetter return the count of words in a string(s)

   The words are written using NATO Phonetic Alphabet: https://www.worldometers.info/languages/nato-phonetic-alphabet/.
   The words can be written with mixed cases.

   Word separator: 
	   Words can be separated by space(s), punctuation(.?!), new line ('\n').
	   If a word is finished by '-' and is followed by a new line, 
	   the next word is part of the last word on the previous line 
	   and count only as one(hyphenated).

	inputText: the input text you must processed
	outputText: the converted text to english. The word separator are transferred as-is 
				from the inputText. The outputText is always in lowercase.

	uniqueWord: count how many unique word was in the input text. 
	            The same word,with different case, count for one word(not case sensitive)

	Project1.cpp : you must implement the fcuntion funWithCallLetter, you cannot change its signature

	Project1.h    : the declaration of funWithCallLetter

	Project1Test  : unit tests to test countWords
	                you must add 4 additional unit tests(implemented in yourTests).  Each test must verify 
					additional logic that was not covered in the previous tests. Comment what specifically
					each of your additionnal tests is testing for.

	Grading       : 1 unit test for empty string         = 0
	                10 unit tests x 7 pts each           = 70
					4 additional unit tests x 5 pts each = 20 (you must complete them in yourTests)
					program structure                    = 10
					total                                = 100
	Your grade will be calculated on the last test your program manage to successfully execute, based on the 
	order in Project1Test.
	
	Program that do not compile will receive a grade of 0.

	Submission    : one submission per team
*/
//map<string, int> uni(const string & inputText)
//{
////Count how many unique word was in the input text.
////The same word,with different case, count for one word(not case sensitive)
//	//input is empty
//	if(inputText.length() == 0)
//	{
//		return 0;
//	}
//	string word;
//	map<string,int> counter;
//	//int counter = 0;
//	
//	if(!counter.count(word))
//	{
//		counter.insert(make_pair(word, 1);
//    }
//	else
//	{
//		counter[word]++;
//	}
//
//	for(int i = counter.begin(); i < counter.end(); i++){
//		if(i->second==1)
//		{
//			cout << i->first << endl;
//		}	
//	}
//	cout << "UNIQUE WORD COUNT IS: " << counter << endl;
//	return counter;
//}


string output(const string & inputText)
{
	string word = "";
	// input is empty
	if(inputText.length() == 0)
	{
		return word;
	}
	string temp = "";
	string NATO[] = {"alpha", "bravo", "charlie",	"delta", "echo", "foxtrot",	"golf",	"hotel", "india", "juliett",	
						"kilo",	"lima",	"mike",	"november", "oscar", "papa", "quebec",	"romeo", "sierra",	
						"tango", "uniform", "victor", "whiskey", "x-ray", "yankee", "zulu",
					};

	for(int i = 0; i < inputText.length(); i++)
	{
		// adds spaces and punctuation when needed and skip to next iteration
		if(inputText[i] == ' ' || inputText[i] == '?' || inputText[i] == '.' || inputText[i] == '!' || inputText[i] == '-')
		{
			word += inputText[i];
			continue;
		}
		temp += inputText[i];
		// adds '\n' when needed and skip to next iteration 
		if(temp == "\n")
		{
			word += "\n";
			temp = "";
			continue;
		}
		//checks to see if temp is found in NATO once its long enough
		if(temp.length() >= 4)
		{
			// makes the word lowercase to match the words in NATO 
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			int size = sizeof(NATO) / sizeof(*NATO);
			// checks to see if temp is in NATO, returns 0 if false 1 if true
			bool check = find(NATO, NATO + size, temp) != NATO + size;
			if(check)
			{
				word += temp[0];
				temp = "";
			}
		}
	}
	return word;
}

int * wordSeperator(const string & inputText)
{
	// input is empty
	if(inputText.length() == 0)
	{
		return 0;
	}
	map<string,int> words; // word = {abc : 1}
	int counter = 0;
	int uniqueCounter = 0;
	static int results[2]; 
    string text = inputText + " "; // add a space at the end to denote where the last word ends

	int hypen = text.find("-"); // gives the index of where '-' is, -1 if cannot be found
	int nl = text.find("\n");

	if( (hypen < nl) && (hypen + 1 == nl) ) // if '-' is one index right before '\n'
	{
		text = regex_replace(text, regex("\n"), ""); // deletes '\n'
		text = regex_replace(text, regex("-"), ""); // deletes '-'
	}
	else if(hypen != -1) // if there is a '-' but not one index right before a "\n" just remove it 
	{
		text = regex_replace(text, regex("-"), " ");
	}

	text = regex_replace(text, regex("\n"), " "); // changes any '\n' found in inputText to a space

	transform(text.begin(), text.end(), text.begin(), ::tolower); // changes text to lowercase
	string temp = ""; // temp used to keep track of words
	string uniqueTemp = ""; // used to keep track of unique words
	

	for(int i = 0; i < text.length(); i++) // iterate thru the word
	{
		temp += text[i];
		// checks if temp has any letters and isn't just all spaces and punctuation to add to the counter
		bool check = any_of(temp.begin(), temp.end(), [](const char& c) -> bool { return isalpha(c); });
		if(check)
		{
			// if current character is a space or punctuaction add 1 to counter as there is a new word 
			if (text[i] == ' ' || text[i] == '?' || text[i] == '.' || text[i] == '!' || text[i] == '-')
			{
				counter += 1;
				temp = "";
			}
		}
		// unique words block
		if(text[i] == ' ' || text[i] == '?' || text[i] == '.' || text[i] == '!' || text[i] == '-')
		{
			if ( uniqueTemp != "" && words.find(uniqueTemp) == words.end()) {
				uniqueCounter += 1;
				words[uniqueTemp] = counter;
    		}
			uniqueTemp = "";
			continue;
		}
		uniqueTemp += text[i];
	}

	cout << "THE WORD IS " << text <<  endl;

	results[0] = counter;
	results[1] = uniqueCounter;
	cout << "THERE ARE " << results[0] << " WORDS HERE" << endl;
	cout << "THERE ARE " << results[1] << " UNIQUE WORDS HERE" << endl;
	return results;
}


unsigned int  funWithCallLetter(const string & inputText, string & outputText, int & uniqueWord ) 
{
	// empty string
	if(inputText.length() == 0)
	{
		uniqueWord = 0;
		outputText = "";
		return 0;
	}
	int * results_ptr = wordSeperator(inputText); // points to array [ wordCounter, uniqueWordCounter]
	int wordCount = results_ptr[0];
	cout << "# of words " << wordCount << endl;
	uniqueWord = results_ptr[1];

	cout << "# of UNIQUE words " << uniqueWord << endl;
	outputText = output(inputText);
	return wordCount;
	
}

int main()
{
	string output;
	int    uniqueWord;
	//for an empty string
	assert(funWithCallLetter( "", output, uniqueWord ) == 0);
	cout << "test #1 completed" << endl;

	//punctuation characters will be considered letter/word
	assert( funWithCallLetter( " .   ! ", output, uniqueWord ) == 0);
	assert( output.length() == string(" .   ! ").length() );
	cout << "test #2 completed" << endl;

	//multiple characters words separated by a single spaces
	assert( funWithCallLetter( "alphabravocharlie deltaechofoxtrot", output, uniqueWord ) == 2);
	assert( output.length() == 7 );
	assert( output.compare("abc def") == 0 );
	cout << "test #3 completed" << endl;

	//for multiples characters words separated by multiple spaces
	//and some word in uppercase/lowercase
	assert( funWithCallLetter( "alphaBravoCharlie   deltaechofoxtrot\n    ", output, uniqueWord ) == 2);
	assert( output.compare("abc   def\n    ") == 0 );
	cout << "test #4 completed" << endl;
		
	//newline to separate words
	assert( funWithCallLetter( "alphaBravoCharlie\ndeltaechofoxtrot", output, uniqueWord ) == 2);
	assert( output.compare("abc\ndef") == 0 );
	cout << "test #5 completed" << endl;
		
	//multiple words before a new line
	assert( funWithCallLetter( "alphaBravoCharlie deltaechofoxtrot deltaechofoxtrot\nalphaBravoCharlie", output, uniqueWord ) == 4);
	assert( output.compare("abc def def\nabc") == 0 );
	cout << "test #6 completed" << endl;

	//check for word separators	
	assert( funWithCallLetter( "alphaBravo\nalphaBravo!alphaBravo?alphaBravo.alphaBravo", output, uniqueWord ) == 5);
	assert( output.compare("ab\nab!ab?ab.ab") == 0 );
	assert( uniqueWord == 1 );
	cout << "test #7 completed" << endl;
		
	//check for uniqueWord and case	sensitive
	assert( funWithCallLetter( "ALPHAbravo\nalphaBRAVO!AlphaBravo", output, uniqueWord ) == 3);
	assert( output.compare("ab\nab!ab") == 0 );
	assert( uniqueWord == 1 );
	cout << "test #8 completed" << endl;

	//hyphen character followed by a single newline
	//will considered the 2 parts word as a single word
	assert( funWithCallLetter( ".whiskeyhotelalphatango!deltaindiadelta yankeeoscaruniform\nfoxtrotindianovemberdelta?", output, uniqueWord ) == 4);
	assert( output.compare(".what!did you\nfind?") == 0 );
	assert( uniqueWord == 4 );
	cout << "test #9 completed" << endl;


	//hyphen character as words separator
	assert( funWithCallLetter( "ALPHAbravo-deltaecho", output, uniqueWord ) == 2);
	assert( output.compare("ab-de") == 0 );
	assert( uniqueWord == 2 );
	cout << "test #10 completed" << endl;

	//hyphen character followed by a single newline
	//will considered the 2 parts word as a single word
	assert( funWithCallLetter( "ALPHAbravo-\ndeltaecho", output, uniqueWord ) == 1);
	assert( output.compare("ab-\nde") == 0 );
	assert( uniqueWord == 1 );
	cout << "test #11 completed" << endl;
}
