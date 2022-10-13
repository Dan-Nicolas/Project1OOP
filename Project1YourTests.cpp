
#include <cassert>
#include "Project1.h"

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;



void yourTests() 
{
	//you must write 4 additional tests cases
	//and document specifically what you are testing in each test
	//you must add test cases, which were not coverred in the 10 test cases
	//included in the project
	//cases
	string output;
	int    uniqueWord;
	// tests for a mix of '\n', hypens and a space
	assert( funWithCallLetter( "bravo\nbravo-yankee-lima-\nuniform quebec-x-ray", output, uniqueWord ) == 8); 
	assert( output.length() == 14 ); // tests outputs length
	assert( output.compare("b\nb-y-l-\nu q-x") == 0 ); // tests the output
	cout << "additional test #1 completed" << endl;

	// tests for spaces, Uppercase, and '\n', hyphens
	// in the case of 'x-ray' the hyphen will not be included as it is part of the word by default and is treated as another other letter
	assert( funWithCallLetter( "x-rayIndiazulu-x-ray \n  mike\nOscar-Kilo", output, uniqueWord ) == 3);
	assert( output.compare("xiz-x \n  m\no-k") == 0 );
	cout << "additional test #2 completed" << endl;
		
	// tests hyphen followed by a '\n'
	assert( funWithCallLetter( "juliettALPHAromeo-\ntangosierra OSCAR x-ray", output, uniqueWord ) == 3);
	assert( output.compare("jar-\nts o x") == 0 );
	cout << "additional test #3 completed" << endl;
		
	//tests for unique words
	assert( funWithCallLetter( "mikeSierramike yankeejuliettfoxtrot - ALPHAzulu\ntango- yankeejuliettfoxtrot\nmikeSierramike", output, uniqueWord ) == 6);
	assert( output.compare("msm yjf - az\nt- yjf\nmsm") == 0 );
	assert( uniqueWord == 4 );
	cout << "additional test #4 completed" << endl;
}

