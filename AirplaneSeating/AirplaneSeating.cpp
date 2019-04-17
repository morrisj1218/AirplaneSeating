// AirplaneSeating.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Programmer:		Jack Morris
// Course:			ITSE-1307 Intro to C++
// Description:		Application mimics an airline's seat reservation system for commercial flights 
// Date:			Successful test on 04/17/2019

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <string>

using namespace std;

const int MAX_ROWS = 13;
const int MAX_COLS = 6;

void print_Aircraft_Layout(const char colHeaders[], const char matrix[][MAX_COLS], int MAX_ROWS); // Outputs CURRENT seating chart
void reserve_Seats(const char colHeaders[], char matrix[][MAX_COLS], int MAX_ROWS);
void show_Help();
void main_Menu();
void reserve_Menu();
int seqSearch(const char list[], int length, char searchItem);

int main()
{
	char aircraft_Layout[MAX_ROWS][MAX_COLS];
	char seatColumns[MAX_COLS] = { 'A','B','C','D','E','F' };
	char available = '*';
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
			show_Help();
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
	int row, col;
	int n = 1;

	cout << " Seating plan for flight number xxxx." << endl;
	cout << " '*' indicates an AVAILABLE seat. 'X' indicates seat is UNAVAILABLE." << endl;
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
	cout << "  Rows 1 and 2 are reserved for FIRST CLASS ticket holders." << endl;
	cout << "  Rows 3 through 7 are reserved for BUISNESS CLASS ticket holders." << endl;
	cout << "  Rows 8 through 13 are for ECONOMY ticket holders." << endl;
}

void reserve_Seats(const char colHeaders[], char matrix[][MAX_COLS], int MAX_ROWS)
{
	char section_ID;
	char seat_ID;
	char y_or_n;
	char reserved = 'X';
	int rowNum;
	int seatIndex;

	do {
		reserve_Menu();
		cin >> section_ID;
		section_ID = toupper(section_ID);

		switch (section_ID) {
			case 'F':
			do {
				y_or_n = 'N';
				print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
				cout << endl;
				cout << " Select which seat you would like to reserve in FIRST CLASS: >> ";
				cin >> rowNum >> seat_ID;
				cout << endl;
				rowNum--;
				seat_ID = toupper(seat_ID);
				seatIndex = seqSearch(colHeaders, MAX_COLS, seat_ID);

				if (seatIndex < 0) 
				{
					cout << endl;
					cout << " Invalid input for seat. Please try again." << endl;
					y_or_n = 'Y';
				}

				if (y_or_n != 'Y')
				{
					if (rowNum < 0 || rowNum > 1)
					{
						cout << endl;
						cout << " The seat you have selected is not located in FIRST CLASS." << endl;
						cout << " Would you like to choose a different seat? 'Y' or 'N': >> ";
						cin >> y_or_n;
						y_or_n = toupper(y_or_n);
						cout << endl;
					}
				}
				
				if (y_or_n != 'Y') 
				{
					if (matrix[rowNum][seatIndex] != reserved) 
					{
						matrix[rowNum][seatIndex] = reserved;
						print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
						cout << endl;
						cout << " Congratulations on a successful reservation." << endl;
						cout << " Would you like to reserve another seat? 'Y' or 'N': >> ";
						cin >> y_or_n;
						y_or_n = toupper(y_or_n);

					} else 
					{
						rowNum++;
						cout << "  " << rowNum << seat_ID << " is NOT AVAILABLE." << endl;
						cout << " Please select a seat that is marked AVAILABLE('*')." << endl;
						cout << endl;
						y_or_n = 'Y';
					}
				}

			} while(y_or_n == 'Y');
			break;

			case 'B':
			do {
				y_or_n = 'N';
				print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
				cout << endl;
				cout << " Select which seat you would like to reserve in BUISNESS CLASS: >> ";
				cin >> rowNum >> seat_ID;
				cout << endl;
				rowNum--;
				seat_ID = toupper(seat_ID);
				seatIndex = seqSearch(colHeaders, MAX_COLS, seat_ID);

				if (seatIndex < 0)
				{
					cout << endl;
					cout << " Invalid input for seat. Please try again." << endl;
					y_or_n = 'Y';
				}

				if (y_or_n != 'Y')
				{
					if (rowNum < 2 || rowNum > 6)
					{
						cout << endl;
						cout << " The seat you have selected is not located in BUISNESS CLASS." << endl;
						cout << " Would you like to choose a different seat? 'Y' or 'N': >> ";
						cin >> y_or_n;
						y_or_n = toupper(y_or_n);
						cout << endl;
					}
				}

				if (y_or_n != 'Y')
				{
					if (matrix[rowNum][seatIndex] != reserved)
					{
						matrix[rowNum][seatIndex] = reserved;
						print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
						cout << endl;
						cout << " Congratulations on a successful reservation." << endl;
						cout << " Would you like to reserve another seat? 'Y' or 'N': >> ";
						cin >> y_or_n;
						y_or_n = toupper(y_or_n);

					}
					else
					{
						rowNum++;
						cout << "  " << rowNum << seat_ID << " is NOT AVAILABLE." << endl;
						cout << " Please select a seat that is marked AVAILABLE('*')." << endl;
						cout << endl;
						y_or_n = 'Y';
					}
				}

			} while (y_or_n == 'Y');
			break;

			case 'E':
			do {
				y_or_n = 'N';
				print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
				cout << endl;
				cout << " Select which seat you would like to reserve in ECONOMY CLASS: >> ";
				cin >> rowNum >> seat_ID;
				cout << endl;
				rowNum--;
				seat_ID = toupper(seat_ID);
				seatIndex = seqSearch(colHeaders, MAX_COLS, seat_ID);

				if (seatIndex < 0)
				{
					cout << endl;
					cout << " Invalid input for seat. Please try again." << endl;
					y_or_n = 'Y';
				}

				if (y_or_n != 'Y')
				{
					if (rowNum < 7 || rowNum > 12)
					{
						cout << endl;
						cout << " The seat you have selected is not located in ECONOMY." << endl;
						cout << " Would you like to choose a different seat? 'Y' or 'N': >> ";
						cin >> y_or_n;
						y_or_n = toupper(y_or_n);
						cout << endl;
					}
				}

				if (y_or_n != 'Y')
				{
					if (matrix[rowNum][seatIndex] != reserved)
					{
						matrix[rowNum][seatIndex] = reserved;
						print_Aircraft_Layout(colHeaders, matrix, MAX_ROWS);
						cout << endl;
						cout << " Congratulations on a successful reservation." << endl;
						cout << " Would you like to reserve another seat? 'Y' or 'N': >> ";
						cin >> y_or_n;
						y_or_n = toupper(y_or_n);

					}
					else
					{
						rowNum++;
						cout << "  " << rowNum << seat_ID << " is NOT AVAILABLE." << endl;
						cout << " Please select a seat that is marked AVAILABLE('*')." << endl;
						cout << endl;
						y_or_n = 'Y';
					}
				}

			} while (y_or_n == 'Y');
			break;

			case 'X':
			break;

			default:
			cout << " Invalid input. Please try again." << endl;
			break;
		}
	} while(section_ID != 'X');
}

void show_Help()
{
	cout << endl;
	cout << "Follow the instructions within the various menus" << endl;
	cout << "IMPORTANT when selecting a seat to reserve be sure to reference" << endl;
	cout << "the row number first followed by seat letter together! (i.e. 4B for Row 4 Seat B)" << endl;
	cout << endl;
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
	cout << "  Selection:  >> ";
}

int seqSearch(const char list[], int length, char searchItem)
{
	bool found = false;
	int index = 0;
	while (index < length && !found)
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
