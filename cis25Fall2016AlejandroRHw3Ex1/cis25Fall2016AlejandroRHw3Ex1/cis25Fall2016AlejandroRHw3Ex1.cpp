/**
* Program Name: cis25Fal2016AlejandroRHw3Ex1.cpp
* Discussion:   Homework #3
* Written By:   Alejandro R
* Due Date:     2016/10/04
*/
#include <iostream>
using namespace std;

void menu03AlejandroR(void);
void setUpExtractUncommonDigit(void);
int** setUp2D(int);
void extractDigitInfo(int* dataAry, int size, int**);
int* extractUncommonDigitAlejandroR(int**, int);

int main() {

	cout << "CIS 25 - C++ Programming\n"
		"Laney College\n"
		"Alejandro R\n\n"

		"Assignment Information --\n"
		"  Assignment Number:  Homework 03,\n"
		"                      Coding Assignment -- Exercise #1\n"
		"  Written by:         Alejandro R\n"
		"  Submitted Date:     2016/10/04\n";

	menu03AlejandroR();

	return 0;
}

void menu03AlejandroR() {
	int option;

	do {
		cout << "\n\n***********************************************"
			"\n*                     MENU                    *"
			"\n* 1. Calling extractUncommonDigitAlejandroR() *"
			"\n* 2. Quit                                     *"
			"\n***********************************************";

		cout << "\nSelect an option (1 or 2): ";
		cin >> option;

		switch (option) {
		case 1:
			setUpExtractUncommonDigit();

			break;
		case 2:
			cout << "\n  Fun exercise ..." << endl;

			break;
		default:
			cout << "\n  WRONG OPTION!\n";
		}
	} while (option != 2);
}

void setUpExtractUncommonDigit() {
	int size;
	int* dataAry = nullptr;
	int** iPtrPtrAry = nullptr;
	int* uncommonAry = nullptr;
	int i;

	cout << "\n  How many integers? ";
	cin >> size;

	dataAry = new int[size];

	for (i = 0; i < size; i++) {
		cout << "    Enter integer #" << i << ": ";
		cin >> *(dataAry + i);
	}

	cout << "\n  The original array:";
	for (i = 0; i < size; i++) {
		cout << "\n    " << *(dataAry + i);
	}

	cout << "\n\n  Calling extractUncommonDigitAlejandroR() -";

	iPtrPtrAry = setUp2D(size);

	extractDigitInfo(dataAry, size, iPtrPtrAry);

	uncommonAry = extractUncommonDigitAlejandroR(iPtrPtrAry, size);

	cout << "\n\n  Displaying after returning the array -- "
		"The Uncommon Digits:"
		"\n    There is/are " << *(uncommonAry + 0) <<
		" uncommon digit(s)\n";

	for (i = 1; i < (*(uncommonAry + 0) * 2 + 1); i += 2) {
		cout << "      {" << *(uncommonAry + i) << "," <<
			*(uncommonAry + i + 1) << "}" << endl;
	}

	delete[] dataAry;
	dataAry = nullptr;

	for (i = 0; i < size; i++) {
		delete[] * (iPtrPtrAry + i);
		*(iPtrPtrAry + i) = nullptr;
	}
	delete[] iPtrPtrAry;
	iPtrPtrAry = nullptr;

	delete[] uncommonAry;
	uncommonAry = nullptr;
}

int** setUp2D(int size) {    
	int** iPtrPtr = nullptr;
	int i;

	iPtrPtr = new int*[size];

	for (i = 0; i <size; i++) {
		*(iPtrPtr + i) = new int[10]();
	}

	return iPtrPtr;
}

void extractDigitInfo(int* dataAry, int size, int** digitInfoAry) {
	int tmp;
	int i;

	for (i = 0; i < size; i++) {
		tmp = (*(dataAry + i) < 0) ? -(*(dataAry + i)) : *(dataAry + i);

		do {
			*(*(digitInfoAry + i) + tmp % 10) = 1;

			tmp /= 10;
		} while (tmp != 0);
	}
}

int* extractUncommonDigitAlejandroR(int** iPtrPtr, int size) {
	int* allDigitOcc = new int[20](); 
	int* uncommAry;
	int uncDigitCnt = 0;
	int uncommonEvenCnt = 0;
	int i, j, k;

	for (i = 0; i < size; i++) {
		for (j = 0, k = 0; j < 10 || k < 20; j++, k += 2) {
			if (*(*(iPtrPtr + i) + j) > 0) {
				*(allDigitOcc + k) += *(*(iPtrPtr + i) + j); //Adds occurrncs
				                                            //of digit (i/2)
				*(allDigitOcc + k + 1) = i; //Stores index of int in which digit
			}                               //(i/2) last occurrs in the next int
		}
	}

	for (i = 0; i < 20; i += 2) {
		if (*(allDigitOcc + i) == 1)
			uncDigitCnt++;            //Counts # of occurred uncommon digits   
	}

	uncommAry = new int[uncDigitCnt * 2 + 1]();

	*(uncommAry + 0) = uncDigitCnt;

	for (i = 0, j = 1; i < 20; i += 4) { //EvenUncomnDigits
		if (*(allDigitOcc + i) == 1) {
			*(uncommAry + j) = i / 2;    //(i/2) gives digit to be worked with
			j++;
			*(uncommAry + j) = *(allDigitOcc + i + 1);
			j++;
			uncommonEvenCnt++;
		}
	}

	for (i = 2, j = (uncommonEvenCnt * 2 + 1); i < 20; i += 4) { //OddUncomnDigits
		if (*(allDigitOcc + i) == 1) {
			*(uncommAry + j) = i / 2;
			j++;
			*(uncommAry + j) = *(allDigitOcc + i + 1);
			j++;
		}
	}

	return uncommAry;
}

/* Program Output
CIS 25 - C++ Programming
Laney College
Alejandro R

Assignment Information --
  Assignment Number:  Homework 03,
                      Coding Assignment -- Exercise #1
  Written by:         Alejandro R
  Submitted Date:     2016/10/04


***********************************************
*                     MENU                    *
* 1. Calling extractUncommonDigitAlejandroR() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2): 4

  WRONG OPTION!


***********************************************
*                     MENU                    *
* 1. Calling extractUncommonDigitAlejandroR() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2): 1

  How many integers? 3
    Enter integer #0: 32965
    Enter integer #1: -275721
    Enter integer #2: 3028063

  The original array:
    32965
    -275721
    3028063

  Calling extractUncommonDigitAlejandroR() -

  Displaying after returning the array -- The Uncommon Digits:
    There is/are 5 uncommon digit(s)
      {0,2}
      {8,2}
      {1,1}
      {7,1}
      {9,0}


***********************************************
*                     MENU                    *
* 1. Calling extractUncommonDigitAlejandroR() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2): 1

  How many integers? 4
    Enter integer #0: 32965
    Enter integer #1: -275721
    Enter integer #2: 3028063
    Enter integer #3: 10789

  The original array:
    32965
    -275721
    3028063
    10789

  Calling extractUncommonDigitAlejandroR() -

  Displaying after returning the array -- The Uncommon Digits:
    There is/are 0 uncommon digit(s)


***********************************************
*                     MENU                    *
* 1. Calling extractUncommonDigitAlejandroR() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2): 2

  Fun exercise ...
*/

/* Comments
 // No issues

 // Logic
 This program uses a ptr to #size pointers to 10 ints,
 in order to get and store which digits occure in the integers 
 entered by the user. 
 A pointer to 20 ints is then used to store each digit's # of 
 occurrences (one occurrence per entered int) followed by the 
 index of entered int in which the digit last occurres. 
 The program then counts the digits that only occurre once 
 (uncommon digits) and creates a pointer to 
 (#uncommonCount * 2 + 1) ints to store the # of uncommon digits in
 index 0, followed by pairs of the even uncommon digits and 
 the index of the int in which they occurre, and then the pairs for 
 the odd uncommon digits. 
*/