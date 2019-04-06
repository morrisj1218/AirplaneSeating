// AirplaneSeating.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Programmer:		Jack Morris
// Course:			ITSE-xxxx Intro to C++
// Description:
// Date:			30/30/2019

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

const int MAX_ROWS = 13;
const int MAX_COLS = 6;

void print_Aircraft_Layout(const char colHeaders[], const char matrix[][MAX_COLS], int MAX_ROWS); // Outputs CURRENT seating chart
void reserve_Seats(const char colHeaders[], char matrix[][MAX_COLS], int MAX_ROWS);
void main_Menu();
void reserve_Menu();
int seqSearch(const char list[], int list_length, char searchItem);

int main()
{
	char aircraft_Layout[MAX_ROWS][MAX_COLS];
	char seatColumns[MAX_COLS] = { 'A','B','C','D','E','F' };
	char available = '*'; // AVAILABLE seat designator
	int choice;

	for (int row = 0; row < MAX_ROWS; row++) // Initialize aircraft_Layout with all seats empty
	{
		for (int col = 0; col < MAX_COLS; col++)
		{
			aircraft_Layout[row][col] = available;
		}
	}

	do
	{
		main_Menu();
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			case 1: // Show current seating chart
			print_Aircraft_Layout(seatColumns, aircraft_Layout, MAX_ROWS);
			break;

			case 2: // Make seat reservations
			reserve_Seats(seatColumns, aircraft_Layout, MAX_ROWS);
			break;

			case 3: // Show help

			break;

			case 4: // Exit

			break;

			default:
			cout << "  Invalid input. Please try again." << endl;
			break;
		} // End of SWITCH

	} while (choice != 4);

	return 0;
} // End of main()

void print_Aircraft_Layout(const char colHeaders[], const char matrix[][MAX_COLS], int MAX_ROWS) // Outputs the CURRENT seating chart
{
	int row, col, n = 1;

	cout << " Seating plan for flight number 666." << endl;
	cout << " '*' indicates an available seat. 'X' indicates seat is reserved and unavailable." << endl;
	cout << endl;

	cout << "\t";
	for (int i = 0; i < MAX_COLS; i++)
	{
		cout << colHeaders[i] << "\t";
	}
	cout << "\n" << endl;

	for (row = 0; row < MAX_ROWS; row++)
	{
		cout << "Row " << n << "\t";
		for (col = 0; col < MAX_COLS; col++)
		{
			cout << matrix[row][col] << "\t";
		}
		cout << endl;
		n++;
	}
	cout << endl;
	cout << "  Rows 1 and 2 are reserved for FIRST CLASS ticket holders" << endl;
	cout << "  Rows 3 through 7 are reserved for BUISNESS CLASS ticket holders" << endl;
	cout << "  Rows 8 through 13 are for ECONOMY ticket holders" << endl;
}

void reserve_Seats(const char colHeaders[], char matrix[][MAX_COLS], int MAX_ROWS)
{
	char classDesignator, seat_Selection;
	char reserved = 'X';
	char y_or_n;
	int rowNum, seatIndex;

	do
	{
		reserve_Menu();
		cin.get(classDesignator);
		classDesignator = static_cast<char>(toupper(classDesignator));

		switch (classDesignator)
		{
			case 'F':
			do
			{
				print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
				cout << " To reserve seat type Row number followed by seat's letter and press 'Enter': >> " << endl;
				cin >> rowNum;
				cin.get(seat_Selection);
				seat_Selection = static_cast<char>(toupper(seat_Selection));

				if (rowNum == 1 || rowNum == 2)
				{
					seatIndex = seqSearch(colHeaders, MAX_COLS, seat_Selection);
					if (seatIndex != -1 && matrix[rowNum][seatIndex] != reserved)
					{
						matrix[rowNum][seatIndex] = reserved;
						cout << " Congratulations on making a successful reservation. Please confirm your reservation\n" <<
							" by insuring that your seat is now marked RESERVED ('X')." << endl;
						print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
						cout << " Would you like to make another reservation? 'Y' | 'N': >> " << endl;
						cin.get(y_or_n);
						static_cast<char>(toupper(y_or_n));
					}
					else
					{
						if (seatIndex = -1)
						{
							cout << seat_Selection << " is not a valid seat identifier. Please try again." << endl;
						}
						else
						{
							cout << " Seat " << rowNum << seat_Selection << " has already been reserved." << endl;
							cout << " Please select a seat that is marked available (*)." << endl;
						}
						
					}
				}
				else
				{
					cout << " The seat you have selected is not located in FIRST ClASS. Please try again." << endl;
				}
			} while (y_or_n != 'N');
			break;

			case 'B':
			do
			{
				print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
				cout << " To reserve seat type Row number followed by seat's letter and press 'Enter': >> " << endl;
				cin >> rowNum;
				cin.get(seat_Selection);
				seat_Selection = static_cast<char>(toupper(seat_Selection));

				if (rowNum >=3 && rowNum <= 7)
				{
					seatIndex = seqSearch(colHeaders, MAX_COLS, seat_Selection);
					if (seatIndex != -1 && matrix[rowNum][seatIndex] != reserved)
					{
						matrix[rowNum][seatIndex] = reserved;
						cout << " Congratulations on making a successful reservation. Please confirm your reservation\n" <<
							" by insuring that your seat is now marked RESERVED ('X')." << endl;
						print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
						cout << " Would you like to make another reservation? 'Y' | 'N': >> " << endl;
						cin.get(y_or_n);
						static_cast<char>(toupper(y_or_n));
					}
					else
					{
						if (seatIndex = -1)
						{
							cout << seat_Selection << " is not a valid seat identifier. Please try again." << endl;
						}
						else
						{
							cout << " Seat " << rowNum << seat_Selection << " has already been reserved." << endl;
							cout << " Please select a seat that is marked available (*)." << endl;
						}

					}
				}
				else
				{
					cout << " The seat you have selected is not located in BUISNESS ClASS. Please try again." << endl;
				}
			} while (y_or_n != 'N');
			break;

			case 'E':
			do
			{
				print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
				cout << " To reserve seat type Row number followed by seat's letter and press 'Enter': >> " << endl;
				cin >> rowNum;
				cin.get(seat_Selection);
				seat_Selection = static_cast<char>(toupper(seat_Selection));

				if (rowNum >= 8 && rowNum <= 13)
				{
					seatIndex = seqSearch(colHeaders, MAX_COLS, seat_Selection);
					if (seatIndex != -1 && matrix[rowNum][seatIndex] != reserved)
					{
						matrix[rowNum][seatIndex] = reserved;
						cout << " Congratulations on making a successful reservation. Please confirm your reservation\n" <<
							" by insuring that your seat is now marked RESERVED ('X')." << endl;
						print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
						cout << " Would you like to make another reservation? 'Y' | 'N': >> " << endl;
						cin.get(y_or_n);
						static_cast<char>(toupper(y_or_n));
					}
					else
					{
						if (seatIndex = -1)
						{
							cout << seat_Selection << " is not a valid seat identifier. Please try again." << endl;
						}
						else
						{
							cout << " Seat " << rowNum << seat_Selection << " has already been reserved." << endl;
							cout << " Please select a seat that is marked available (*)." << endl;
						}

					}
				}
				else
				{
					cout << " The seat you have selected is not located in ECONOMY. Please try again." << endl;
				}
			} while (y_or_n != 'N');
			break;

			case 'X':
			break;
			default:
			cout << " Invalid input. Please try again." << endl;
			break;
		}

	} while (classDesignator != 'X');
}

void main_Menu() // Main menu options
{
	cout << endl;
	cout << "    Welcome to Fictitious Airways' Seat picker App!\n" << endl;
	cout << "\t1 -- Current aircraft seating plan\n" << endl;
	cout << "\t2 -- Make seat reservations\n" << endl;
	cout << "\t3 -- Help\n" << endl;
	cout << "\t4 -- Exit application\n" << endl;
	cout << "  Select a menu item: >> ";
}

void reserve_Menu() // Reserve menu options
{
	cout << "  Select your class: \n" << endl;
	cout << "\tF -- First Class\n" << endl;
	cout << "\tB -- Buisness Class\n" << endl;
	cout << "\tE -- Economy Class\n" << endl;
	cout << "\tX -- Return to main menu\n" << endl;
	cout << "  Selection:  >> " << endl;
}

int seqSearch(const char list[], int list_length, char searchItem)
{
	bool found = false;
	int index = 0;
	while (index < list_length && !found)
	{
		if (list[index] == searchItem)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}
	if (found)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
