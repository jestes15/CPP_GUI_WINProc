#include "secondary.h"
using namespace std;

void array_functions::set_var1(std::string* str)
{
	var1 = *str;
}

std::string array_functions::get_var1()
{
	return var1;
}

array_functions::array_functions()
{
	cout << "Array Functions ready!" << endl;
}

array_functions::~array_functions()
{
	cout << "Thank you for using me!" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	system(clear_msg);
}

TCHAR* array_functions::sum_array(array<int, 1000> array)
{
	auto sum = 0;
	try
	{
		for (auto x = 0; x < ACTUAL_SIZE_OF_ARRAY; x++)
		{
			sum += array[x];
		}
	}
	catch (char* e)
	{
		cout << "An error occurred: " << e;
	}
	ACTUAL_SIZE_OF_ARRAY = 0;
	std::wstring string_ascpect(L"The sum is ");
	std::wstring num_ascpect = std::to_wstring(sum);
	std::wstring return_val_wstring = string_ascpect + num_ascpect;
	TCHAR* return_val = (TCHAR*)return_val_wstring.c_str();

	return return_val;
}

void array_functions::set_size(array<int, 1000> array)
{
	SIZE_OF_ARRAY = array.size();
	for (auto x = 0; x < SIZE_OF_ARRAY; x++)
	{
		try {
			if (array[x] != NULL) { ACTUAL_SIZE_OF_ARRAY++; }
		}
		catch (...)
		{
			cout << "An error has occurred" << endl;
			throw;
		}
	}
}

std::wstring get_wstring(int choice)
{
	std::wstring menu(L"What kind of operation do you want to do?\n0: sum\n1: subtraction\n"
		"2: multiplication\n3: division\n4: modulus\n5: sin\n6: cos\n7: tan\n8: arc-sin\n"
		"9: arc-cos\n10: arc-tan\n11: UAH Logo\n12: CS 102 Array homework\n13: Sum of a user made array\nType exit to quit.\nmsr> ");

	std::wstring instruction_v1(L"Please enter your first number then your second.");
	std::wstring instruction_v2(L"Please enter your number");
	std::wstring instruction_v3(L"What kind of initialization of the array? A (auto)/U (User input)");

	std::wstring return_msg_v1(L"Your final value is: ");
	std::wstring return_msg_v2(L"The sum of all the components in the array is: ");

	std::wstring help_msg(L"Commands:\nexit :: Exits the program\nclear :: Clears the screen and prints the help menu.");

	std::wstring exit_msg(L"It appears you made an error, please try again.");
	std::wstring switch_error(L"There is no option which was inputted into the function");

	switch (choice)
	{
	case 1:
		return menu;
	case 2:
		return instruction_v1;
	case 3:
		return instruction_v2;
	case 4:
		return instruction_v3;
	case 5:
		return return_msg_v1;
	case 6:
		return return_msg_v2;
	case 7:
		return help_msg;
	case 8:
		return exit_msg;
	default:
		return switch_error;
	}
}