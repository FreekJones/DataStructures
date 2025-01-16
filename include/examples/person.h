//#pragma once does the same thing as the compiler guard

#ifndef _PERSON_H_    //"compiler guard" - prevents the file from being included more than once
#define _PERSON_H_		//header file and the stuff within it is only included once

#include <string>
class Person
{
public:		//This is an ACCESS MODIFIER -- it makes the following attributes and methods public (accessible from outside the class)
	int id;		//These are attributes -- variables that each instance of the class will get a copy of
	std::string first_name;   //By default, these are private (we can only access them in a method)
	std::string last_name;
	float hourly_rate;
	unsigned int hours_worked;

public:

	//This is a METHOD -- a function that all instances of the class can use.  This is a DECLARATION
	float calculate_pay();

};

#endif
