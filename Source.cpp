#include <iostream>
#include <fstream>
#include <iomanip>
#include "Header.h"
using namespace std;

//loop after throwing errors until there's a valid input?
//he wants user input, right?
//^^yes, main menu and while loop

int main() {
	//cin.exceptions(ios_base::failbit | ios_base::badbit); //in order to error handle invalid input

	ifstream inputdata;
	inputdata.open("A1input.txt");

	int* myarray = new int[100]; 
	/* ^^^dynamically allocating newarray so that way it can be assigned to the dynamically
	allocated arrays that are returned from the functions */
	int capacity = 100;
	int arraysize = 100; //arraysize = the number of elements currently in the array
	//^^^we're loading 100 elements soon, so I just initialied arraysize as 100

	loadArray(inputdata, myarray, arraysize);

	inputdata.close();

	while (true) { //keeps looping until user wants to quit
		try {
			cout << setw(23) << "MENU:" << endl;
			cout << "1. Find Index of Desired Integer in Array" << endl;
			cout << "2. Modify Value of Integer in Array Using its Index" << endl;
			cout << "3. Add New Integer to End of Array" << endl;
			cout << "4. Remove Integer from Array Using its Index" << endl;
			cout << "5. Print out Current Array" << endl;
			cout << "6. Quit" << endl;

			int userchoice;
			cout << endl;
			cout << "Select an Option: ";
			cin >> userchoice;

			//branch 1: finding index of an integer
			if (userchoice == 1) {
				cout << endl;
				int findValue;
				int indexLocation;
				cout << "Enter Desired Integer: ";
				cin >> findValue;
				cout << endl;
				indexLocation = findInteger(myarray, arraysize, findValue);

				if (indexLocation == -1) {
					cout << "Oops! Desired Integer not found in the array." << endl;
				}
				else {
					cout << "The Desired Integer is found at index: " << indexLocation << endl;
				}
				cout << endl;
				cout << endl;
			}

			//branch 2: modifying integer through index
			else if (userchoice == 2) {
				int indexLocation;
				int initialValue;
				int replacementValue;
				cout << endl;
				cout << "The number at which Index would you like to modify?: ";
				cin >> indexLocation;
				/* if (cin.fail()) { //if they don't enter an integer
					cin.clear(); // Clear the error state
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
					throw ios_base::failure("Error: Value must be an integer");
				}   */

				if (indexLocation < 0 || indexLocation >= arraysize) {
					cout << endl;
					throw out_of_range("Error: Index is out of bounds. Unable to complete operation.");
				}

				cout << endl;
				cout << "What Value do you want to replace it with?: ";
				cin >> replacementValue;
				/* if (cin.fail()) { //if they don't enter an integer
						cin.clear(); // Clear the error state
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
						throw ios_base::failure("Error: Value must be an integer");
					}   */
				cout << endl;
				initialValue = modifyInteger(myarray, indexLocation, replacementValue);
				cout << "The value at index " << indexLocation << " was originally " << initialValue
					<< " and is now " << replacementValue << endl;
				cout << endl;
				cout << endl;
			}

			//branch 3: add new integer to end of array
			else if (userchoice == 3) {
				int addValue;
				cout << endl;
				cout << "What integer would you like to add?: ";
				cin >> addValue;
				/* if (cin.fail()) { //if they don't enter an integer
                        cin.clear(); // Clear the error state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        throw ios_base::failure("Error: Value must be an integer");
                   }   */

				myarray = addInteger(myarray, arraysize, addValue, capacity);
				/* Exception throwing is WITHIN addInteger function^^^
				
				 I couldn't think of any exception I could throw on the user input specifically,
				 unless they didn't enter an integer, and I could not figure out how to catch that
				 error to save my life. You can see the throw and catch attempts at it commented out.*/

				cout << endl;
				cout << "Sucessfully added the integer." << endl;
				cout << endl;
				cout << endl;
			}

			//branch 4: remove integer through index
			else if (userchoice == 4) {
				int deleteIndex;
				cout << endl;
				cout << "The number at which Index would you like to remove?: ";
				cin >> deleteIndex;
				myarray = removeIndex(myarray, arraysize, deleteIndex);
				cout << endl;
				cout << "Number sucessfully removed." << endl;
				cout << endl;
				cout << endl;
			}

			//branch 5: print out array
			else if (userchoice == 5) {
				cout << endl;
				cout << "Current Array:" << endl;
				for (int i = 0; i < arraysize; i++) {
					cout << myarray[i] << " ";
				}
				cout << endl;
				cout << endl;
				cout << endl;
			}

			//branch 6: quit
			else if (userchoice == 6)
				break;
		}

		//exception handlers:
		catch (const out_of_range& e) {
			cout << e.what() << endl;
			cout << endl;
			cout << endl;
		}
		catch (const runtime_error& e) {
			cout << e.what() << endl;
		}

		/*catch (const ios_base::failure& e) {
			cerr << e.what() << endl; //try cout instead??
			//cin.clear(); // Clear the fail state
			//cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
		}*/
	}
	return 0;
}