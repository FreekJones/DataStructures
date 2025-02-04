//#pragma once does the same thing as the compiler guard

#ifndef _PERSON_H_    //"compiler guard" - prevents the file from being included more than once
#define _PERSON_H_    //header file and the stuff within it is only included once

#include <string>

/// <summary>
/// the example namespace is used to define the class Person and its methods
/// </summary>
namespace example
{ 
	/// <summary>
	/// creates a class called Person that has the attributes id, first_name, last_name, hourly_rate, and hours_worked
	/// the class also has methods to calculate pay, set and get the values of the attributes, and a constructor and destructor
	/// </summary>
	class Person
	{
	private:		//This is an ACCESS MODIFIER -- it makes the following attributes and methods public (accessible from outside the class)

		/// <summary>
		/// the id of the person
		/// </summary>
		int id;		//These are attributes -- variables that each instance of the class will get a copy of

		/// <summary>
		/// the first name of the person
		/// </summary>
		std::string first_name;   //By default, these are private (we can only access them in a method)

		/// <summary>
		/// the last name of the person
		/// </summary>
		std::string last_name;

		/// <summary>
		/// the hourly rate of the person
		/// </summary>
		float hourly_rate;

		/// <summary>
		/// the number of hours worked by the person
		/// </summary>
		unsigned int hours_worked;

	public:
		//This is the CONSTRUCTOR -- a special method that has no return type and MUST have the same name as the class
		//This is a METHOD -- a function that all instances of the class can use.  This is a DECLARATION
		
		/// <summary>
		/// constructor that initializes the person 
		/// </summary>
		Person();

		/// <summary>
		/// constructor that initializes the person with the given id, first name, and last name
		/// </summary>
		/// <param name="start_id"> the id of the person </param>
		/// <param name="start_fname"> the first name of the person </param>
		/// <param name="start_lname"> the last name of the person </param>
		Person(int start_id, std::string start_fname, std::string start_lname);

		//This is a DESTRUCTOR -- a method that is called when an instance of the class is about to go away
		// It is unusual to call this manually.  More often, it's called when an instance goes out of scope(scope is where that
		// variable is visible, or is defined)  Do any kind of cleanup you wish.  Biggie: if you dynamically allocated memory, this
		// is a good place to clean it up. 

		/// <summary>
		/// destructor that is used for cleanup
		/// </summary>
		~Person();

		/// <summary>
		/// calculates the total pay of the person by using the hourly rate and hours worked
		/// </summary>
		/// <returns> total pay of the person </returns>
		float calculate_pay();

		//These are SETTERS -- methods that allow us to change the values of the attributes

		/// <summary>
		/// sets the hourly rate of the person
		/// </summary>
		/// <param name="new_rate"> the new hourly rate of the person </param>
		void set_hourly_rate(float new_rate);	

		/// <summary>
		/// sets the number of hours worked by the person
		/// </summary>
		/// <param name="new_hours"> the new hours worked by the person </param>
		void set_hours_worked(unsigned int new_hours);	

		//These are examples of GETTERS -- methods that allow us to access the values of the attributes

		/// <summary>
		/// gets the ID of the person
		/// </summary>
		/// <returns> the person's ID </returns>
		int get_id();

		/// <summary>
		/// gets the first name of the person
		/// </summary>
		/// <returns> the first name of the person </returns>
		std::string get_first_name();

		/// <summary>
		/// gets the last name of the person
		/// </summary>
		/// <returns> the last name of the person </returns>
		std::string get_last_name();	

		/// <summary>
		/// gets the hourly rate of the person
		/// </summary>
		/// <returns> the hourly rate of the person </returns>
		float get_hourly_rate();

		/// <summary>
		/// gets the number of hours worked by the person
		/// </summary>
		/// <returns> the number of hours worked by the person </returns>
		unsigned int get_hours_worked();	

	};
}
#endif
