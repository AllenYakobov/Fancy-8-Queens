// Allen Yakobov Fancy 8-Queens Project

#include <iostream>
using namespace std;

bool ok(int q[], int c) { // ok function checks if you can place queen
	for (int i = 0; i < c; i++) {
		if ((q[c] == q[i]) || (c - i == abs(q[c] - q[i]))) { //row test and diagonal test
			return false; // return false if does not pass row test or diagonal test
		}
	}
	return true; // otherwise, return true
}

void print(int q[]) { // prints solution #, 1d array values, and board with 92 solutions
	int i, j, k, l; // initialize 
	typedef char box[5][7]; // typedef for box, (char box[5][7])
	box blackBox, whiteBox, *board[8][8]; // initialize white box, black box, pointer to board
	static int numSol = 1; // initialize number of solutions to 1
	
	cout << "Solution #" << numSol++ << endl; // print number of solutions

	// create black queen (char(219)) for black spaces
	box blackQueen = {	{' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
						{' ', char(219), ' ', char(219), ' ', char(219), ' '},
						{' ', char(219), char(219), char(219), char(219), char(219), ' '},
						{' ', char(219), char(219), char(219), char(219), char(219), ' '},
						{' ', ' ', ' ', ' ', ' ', ' ', ' '}
	};
	
	// create white queen (char(219)) for black spaces
	box whiteQueen = {  {char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
						{char(219), ' ', char(219), ' ', char(219), ' ', char(219)},
						{char(219), ' ', ' ', ' ', ' ', ' ', char(219)},
						{char(219), ' ', ' ', ' ', ' ', ' ', char(219)},
						{char(219), char(219), char(219), char(219), char(219), char(219), char(219)}
	};

	//fill in black box and white box
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 7; j++) {
			whiteBox[i][j] = ' '; // fill in white box with white (' ')
			blackBox[i][j] = char(219); // fill in black box with black (char(219))
		}
	}

	// fill board with pointers to black box and white box alternate positions
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) { // if row + col is even
				if (q[j] == i) { // if q[j] = i
					board[i][j] = &blackQueen; // place black queen
				}
				else { // otherwise 
					board[i][j] = &whiteBox; // just have white box with no black queen
				}
			}
			else  { // otherwise (if row + col is not even)
				if (q[j] == i) { // if q[j] = i
					board[i][j] = &whiteQueen; // place white queen
				}
				else { //otherwise
					board[i][j] = &blackBox; // just have black box with no white queen
				}
			}
		}
	}
	// print the board via the pointers in array board
	
	// first print upper border
	cout << "    ";
	for (i = 0; i < 7 * 8; i++) {
		cout << '_'; // upper boarder
	}
	cout << endl;
	
	// now print the board
	for (i = 0; i < 8; i++) {
		for (k = 0; k < 5; k++) {
			cout << "   " << char(179); // print left board
			for (j = 0; j < 8; j++) {
				for (l = 0; l < 7; l++) {
					cout << (*board[i][j])[k][l]; // print board
				}
			}
			cout << char(179) << endl; // at end of line print bar and then newline
		}
	}
	
	//before exiting now print the lower border
	cout << "    ";
	for (i = 0; i < 7 * 8; i++) {
		cout << char(196); // print lower border
	}
	cout << endl;
}


int main() {
	int q[8] = { 0 }; // initialize array
	int c = 0;

	while (c >= 0) { // while col is greater than 0
		c++; // next col
		if (c == 8) { // if last col has been passed
			print(q); // print function is called
			c--; // backtrack
		}
		else {
			q[c] = -1; // otherwise, move to one before the first row
		}
		while (c >= 0) { // while col is greater than 0
			q[c]++; // next row
			if (q[c] == 8) { // if end of col has been passed
				c--; // backtrack
			}
			else if (ok(q, c)) { // otherwise, ok function is called
				break; // go back to top of the loop
			}
		}
	}
	return 0;
}