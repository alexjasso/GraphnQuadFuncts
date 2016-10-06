/**
 * Program Name: PrecalQuadFunctions.cpp
 * Discussion:   Graphin Quadratic Functions 
 * Written By:   Alejandro Ramirez
 * Last Update:  2016/10/06
 */
#include <iostream>
using namespace std;

void menu(void);
int* setUpQuadFunction(void);
void graphQuadFunction(int*);
void getVertex(void);

int main() {
	menu();

	return 0;
}

void getVertex() {

}

void graphQuadFunction(int* ptr) {
	
	cout << "Step 1: " << *(ptr + 0) << "x^2 + " << *(ptr + 1) << "x + " << *(ptr + 2) << endl;

	cout << "Step 2: " << *(ptr + 0) << "(x^2 + " << *(ptr + 1) << "/"
		<< *(ptr + 0) << "x) + " << *(ptr + 2) << endl;

	cout << "Step 3: " << *(ptr + 0) << "(x^2 + " << *(ptr + 1) << "/"
		<< *(ptr + 0) << "x + (" << *(ptr + 1) << "/" 
		<< 2 * *(ptr + 0) << ")^2) + " << *(ptr + 2) 
		<< " - " << *(ptr + 0) << "((" << *(ptr + 1) << "/" 
		<< 2 * *(ptr + 0) << ")^2)" << endl;

	cout << "Step 4: " << *(ptr + 0) << "(x^2 + " << *(ptr + 1) << "/"
		<< *(ptr + 0) << "x + " << *(ptr + 1) * *(ptr + 1) << "/" 
		<< 4 * *(ptr + 0) * *(ptr + 0) << ") + " << *(ptr + 2) 
		<< " - " << *(ptr + 0) << "(" << *(ptr + 1) * *(ptr + 1) << "/" 
		<< 4 * *(ptr + 0) * *(ptr + 0) << ")" << endl;

	cout << "Step 5: " << *(ptr + 0) << "(x + " << *(ptr + 1) << "/" 
		<< 2 * *(ptr + 0) << ")^2 + " << *(ptr + 2) << " - " << *(ptr + 1) * *(ptr + 1) << "/" 
		<< 4 * *(ptr + 0) << endl;

	cout << "Step 6: " << *(ptr + 0) << "(x + " << *(ptr + 1) << "/" 
		<< 2 * *(ptr + 0) << ")^2 + " << *(ptr + 2) << " * " << 4 * *(ptr + 0) << "/" << 4 * *(ptr + 0) 
		<< " - " << *(ptr + 1) * *(ptr + 1) << "/" 
		<< 4 * *(ptr + 0) << endl;

	cout << "Step 7: " << *(ptr + 0) << "(x + " << *(ptr + 1) << "/" 
		<< 2 * *(ptr + 0) << ")^2 + (" << *(ptr + 2) * 4 * *(ptr + 0)
		<< "-" << *(ptr + 1) * *(ptr + 1) << ")/" 
		<< 4 * *(ptr + 0) << endl;

	cout << "Step 8: " << *(ptr + 0) << "(x + " << *(ptr + 1) << "/" 
		<< 2 * *(ptr + 0) << ")^2 + (" << (*(ptr + 2) * 4 * *(ptr + 0))
		- (*(ptr + 1) * *(ptr + 1)) << ")/" 
		<< 4 * *(ptr + 0) << endl;
}

int* setUpQuadFunction() {
	int* ptr = new int[3]();
	char abc[3] = { 'a','b','c'};
	int i;

	cout << "\nFor the quadratic function of the form ax^2 + bx + c (a != 0)," << endl;
	for (i = 0; i < 3; i++) {
		cout << "  Enter " << abc[i] << ": ";
		cin >> *(ptr + i);
	}

	return ptr;
}
void menu() {
	int option;
	int* abcPtr = nullptr;
	do {
		cout << "\n\n**********************************"
			"\n*              Menu               *"
			"\n* (1) Calling setUpQuadFunction() *"
			"\n* (2) Calling graphQuadFunction() *"
			"\n* (3) Calling getVertex()         *"
			"\n* (4) Quit                        *"
			"\n***********************************";

		cout << "\nSelect an option (1, 2, 3 or 4): ";
		cin >> option;

		switch (option) {
		case 1:
			abcPtr = setUpQuadFunction();
			break;
		case 2:
			graphQuadFunction(abcPtr);
			break;
		case 3:
			getVertex();
			break;
		case 4:
			cout << "\n  Math is Fun..." << endl;
			break;
		default: 
			cout << "\n  WRONG OPTION!" << endl;
		}
	} while (option != 4);
}