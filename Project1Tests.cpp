
#include <cassert>
#include "Project1.h"

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;


void genericTests() 
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

int main()
{
	genericTests();
	
	yourTests();
	
	return 1;
}

