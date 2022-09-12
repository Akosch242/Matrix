#include <iostream>
#include "MyMatrix.h"

using namespace std;
using namespace GHA;

int main(void) {
	//2 parametrige Konstruktor, die Elementen werden auf 0 initialisiert.
	MyMatrix<int> Test1(4, 4);

	//Einheitsmatrix um die Rank des Matrix einfach zu überprüfen
	for (unsigned int i = 0; i < 4; i++) {
		Test1(i, i) = 1;
	}

	cout << Test1.rank() << endl;					// Rank einer N×N Einheitsmatrix
	for (unsigned int i = 0; i < 6; i++) {			// G geht bis 6, Überprüfung von die Ausnahme bei zu größe Index
		try {
			Test1(i, i) = 0;							// Einheitsmatrix -> NUllmatrix, wir überprüfen die Rank in jedem Zyklus
			cout << "Rang: " << Test1.rank() << endl;
		}
		catch (exception& e) {
			cout << "Ausnahme: " <<e.what() << endl << endl;	// Ausschreiben der Ausnahme und Austreten
			break;
		}
	}

	//3 parametrige Konstruktor, die Elementen werden auf die Wert der dritten Paramter initialisiert.
	MyMatrix<int> Test2(5, 4, 3);
	cout << "Test2 Matrix, dessen Elementen drei sind:" << endl;
	cout << Test2;
	try {
		MyMatrix<int> SUM = Test2 + Test2;			// Verwendung von der Additionsoperator.
		cout << "SUM = Test2 + Test2:" << endl;
		cout << SUM;								// Ausschreiben der Ergebnis
		Test2 += SUM;								// Verwendung von der Additionsoperator mit Zuweisung
		cout << "Test2 += SUM:" << endl;
		cout << Test2;								// Jetzt ist die Ergebnis n Test2 gespeichert
		MyMatrix<int> SUM2 = Test1 + Test2;			// Ausnahme: wir probieren zwei, in Dimensionen  verschiedene Matricen zusammen addieren
	}
	catch (exception& e) {
		cout << "Ausnahme: " << e.what() << endl << endl; // Ausschriben der Ausnahme
	}

	MyMatrix<int> Test3(4, 4);
	// Einstellung von bestimmten Elementen:
	// 1. Zeile
	Test3(0, 0) = 1;
	Test3(0, 1) = 1;
	Test3(0, 2) = -2;
	Test3(0, 3) = -1;
	// 2. Zeile
	Test3(1, 0) = 2;
	Test3(1, 1) = 1;
	Test3(1, 2) = 1;
	Test3(1, 3) = -3;
	// 3. Zeile
	Test3(2, 0) = 4;
	Test3(2, 1) = -1;
	Test3(2, 2) = -2;
	Test3(2, 3) = 1;
	// 4. Zeile
	Test3(3, 0) = -1;
	Test3(3, 1) = 0;
	Test3(3, 2) = -3;
	Test3(3, 3) = 3;
	// Die Determinante soll in diesem Fall 19 sein.
	cout << "Test3.determinant(): " << Test3.determinant() << endl;
	cout << "Test2.determinant(): ";
	try {
		cout << Test2.determinant(); // Test2 ist nicht ein quadratische Matrix
	}
	catch (exception& e) {
		cout << e.what() << endl << endl; // Ausnahme: Determinante kann nicht auf einen nicht quadratischen Matrix berechnet
	}

	MyMatrix<double> Test4(2, 3, 2.5);
	Test4(0, 2) = 1;
	Test4(1, 1) = 1;
	cout << "Test4:" << endl;
	cout << Test4;
	try {
		cout << "3.5 * Test4:" << endl;
		cout << 3.5 * Test4;						// Skalar * Matrix
		cout << "Test4 * 2.5:" << endl;				
		cout << Test4 * 2.5;						// Matrix * Skalar
		cout << "Test4 *= 2:" << endl;
		Test4 *= 2;									// '*=' Operator
		cout << Test4;
		cout << "Test4 = Test4 * Test4.transposition():" << endl;
		Test4 *= Test4.transposition();				// Matrix * Matrix transponiert
		cout << Test4;
		cout << "Test4 = Test4 * Test5:" << endl;
		MyMatrix<double> Test5(5, 5, 5);
		Test4 = Test4 * Test5;						// Matrix * Matrix mit nicht geigneten Größen
	}
	catch (exception& e) {
		cout << "Ausnahme: " << e.what() << endl << endl; // Bei Multiplikation waren die Größen der Matrixen nicht in form n×k * k×m
	}

	cout << "Test4.rowAdd(0,1).rowMult(1,2.0).rowInterchange(0,1):" << endl;
	cout << (Test4.rowAdd(0, 1).rowMult(0, 2.0).rowInterchange(0, 1)) << endl; // Zeilenoperationen können verkettet werden.
}