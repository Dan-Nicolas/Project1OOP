// Project1.cpp : 
// Your names
//
#include <string>
#include <iostream>  
#include <sstream>
#include <map>
#include <cassert>
#include <regex>

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
string output(const string & inputText)
{
	string word = "";
	string text = inputText + " "; // add a space at the end to denote where the last word ends
	text = regex_replace(text, regex("\n"), " "); // changes any '\n' found in inputText to a space
	cout << "TEXT " << text << endl;
	return "";
}

unsigned int wordSeperator(const string & inputText)
{
	unsigned counter = 0;
    string text = inputText + " "; // add a space at the end to denote where the last word ends
	text = regex_replace(text, regex("\n"), " "); // changes any '\n' found in inputText to a space
	cout << "TEXT " << text << endl;
	for(int i = 0; i < text.length(); i++)
	{
		// if current character is a space or punctuaction add 1 to counter as there is a new word 
		if (text[i] == ' ' || text[i] == '?' || text[i] == '.' || text[i] == '!')
		{
			counter += 1;
		}

	}
	
	cout << "COUNTER " << counter << endl;
	cout << "TEXT " << text << endl;
	cout << "INPUT " << inputText << endl;
	return counter;
}

unsigned int  funWithCallLetter(const string & inputText, string & outputText, int & uniqueWord ) 
{
	int wordCount = wordSeperator(inputText);
	cout << "WORD COUNT " << wordCount << endl;
	string NATO[26] = {"Alpha", "Bravo", "Charlie",	"Delta", "Echo", "Foxtrot",	"Golf",	"Hotel", "India", "Juliett",	
						"Kilo",	"Lima",	"Mike",	"November", "Oscar", "Papa", "Quebec",	"Romeo", "Sierra",	
						"Tango", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu",
					};
	string words = {};
	
	uniqueWord = 0;
	outputText = "";

	uniqueWord = 0;
	output(inputText);
	return wordCount;
}

int main()
{
	cout << "Yes" << endl;
	string output;
	int    uniqueWord;
	int w = wordSeperator("alphaBravoCharlie\ndeltaechofoxtrot");
	cout << "\n" << endl;
	int p = funWithCallLetter("alphaBravoCharlie\ndeltaechofoxtrot", output, uniqueWord);
	cout << "word ?? " << w << endl;
	cout << "word !! " << p << endl;
	cout << "UNI " << uniqueWord << endl;
	//for an empty string
	assert(funWithCallLetter( "", output, uniqueWord ) == 0);
	cout << "test #1 completed" << endl;

	//punctuation characters will be considered letter/word
	//assert( funWithCallLetter( " .   ! ", output, uniqueWord ) == 0);
	//assert( output.length() == string(" .    ! ").length() );
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
