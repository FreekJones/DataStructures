//#pragma once does the same thing as the compiler guard

#ifndef _PERSON_H_    //"compiler guard" - prevents the file from being included more than once
#define _PERSON_H_		//header file and the stuff within it is only included once

#include <string>
class Person
{
private:		//This is an ACCESS MODIFIER -- it makes the following attributes and methods public (accessible from outside the class)
	int id;		//These are attributes -- variables that each instance of the class will get a copy of
	std::string first_name;   //By default, these are private (we can only access them in a method)
	std::string last_name;
	float hourly_rate;
	unsigned int hours_worked;

public:
	//This is the CONSTRUCTOR -- a special method that has no return type and MUST have the same name as the class
	//This is a METHOD -- a function that all instances of the class can use.  This is a DECLARATION
	Person();	

	//This is another CONSTRUCTOR
	Person(int start_id, std::string start_fname, std::string start_lname);

	//This is a DESTRUCTOR -- a method that is called when an instance of the class is about to go away
	// It is unusual to call this manually.  More often, it's called when an instance goes out of scope(scope is where that
	// variable is visible, or is defined)  Do any kind of cleanup you wish.  Biggie: if you dynamically allocated memory, this
	// is a good place to clean it up. 
	~Person();

	float calculate_pay();

	//These are SETTERS -- methods that allow us to change the values of the attributes
	void set_hourly_rate(float new_rate);	
	void set_hours_worked(unsigned int new_hours);	

	//These are examples of GETTERS -- methods that allow us to access the values of the attributes
	int get_id();	
	std::string get_first_name();	
	std::string get_last_name();	
	float get_hourly_rate();	
	unsigned int get_hours_worked();	

};

#endif
