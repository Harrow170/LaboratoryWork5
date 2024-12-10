#include "GetInput.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int GetInput(const string& prompt)
{
	int value;
	string input;

	while (true)
	{
		cout << prompt;
		getline(cin, input);

		try
		{
			value = stoi(input);
			return value;
		}

		catch (const invalid_argument& e)
		{
			cout << "Invalid input. Please enter an integer value.\n";
		}

		catch (const out_of_range& e)
		{
			cout << "Input is out of range. Please enter a valid integer value.\n";
		}
	}
}