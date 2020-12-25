#pragma once
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <tchar.h>
#include <atlstr.h>
#include <windows.h>

//Gets the wstring
std::wstring get_wstring(int);

//The size of the TCHAR arrays used in the TCHAR_msg array
constexpr auto array_size = 10000;

//makes clear_msg cls for windows, has a unix counter part but is not needed due to
//this application using the Win32 API
constexpr auto clear_msg = "cls";

#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
//A class made for functions related to arrays
class array_functions
{
public:
	//The constructor for the array_functions class, executed upon initialization
	array_functions();

	//The destructor for the array_functions class, executes when the instance of the
	//array functions class is deleted
	~array_functions();

	//Sums up an array given to it
	TCHAR* sum_array(std::array<int, 1000> array);

	//Set the size of the array to be used in sum_array(std::array<int, 1000> array)
	void set_size(std::array<int, 1000> array);

	//Sets a private variable, var1, has no use at this time
	void set_var1(std::string* str);

	//Gets the value of the variable var1, returns a type std::string
	std::string get_var1();

protected:

private:
	std::string var1 = "Hello";
	int SIZE_OF_ARRAY = 0;
	int ACTUAL_SIZE_OF_ARRAY = 0;
};
#endif