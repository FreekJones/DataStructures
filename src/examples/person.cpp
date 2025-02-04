// person.cpp --- houses the BODIES(DEFINITIONS) of all methods
#include <person.h>

/// <summary>
/// calculates the total pay of the person by using the hourly rate and hours worked
/// </summary>
/// <returns> the total earnings of the person </returns>
float example::Person::calculate_pay()
{
	// We have access to all attributes since we're a part of the class
	return hourly_rate * hours_worked;
}

/// <summary>
/// sets the hourly rate of the person
/// </summary>
void example::Person::set_hourly_rate(float new_rate)
{
	hourly_rate = new_rate;
}

/// <summary>
/// sets the number of hours worked by the person
/// </summary>
void example::Person::set_hours_worked(unsigned int new_hours)
{
	hours_worked = new_hours;
}

/// <summary>
/// default constructor that initializes the person's attributes to default values
/// </summary>
example::Person::Person()
{
	id = -1;
	first_name = "?";
	last_name = "?";
	hourly_rate = 0.0f;
	hours_worked = 0;
}

/// <summary>
/// constructor that initializes the person's attributes to the given values
/// </summary>
example::Person::Person(int start_id, std::string start_fname, std::string start_lname)
{
	id = start_id;
	first_name = start_fname;
	last_name = start_lname;
	hourly_rate = 0.0f;
	hours_worked = 0;
}

/// <summary>
/// destructor that is used for cleanup
/// </summary>
example::Person::~Person()
{
//	std::cout << "The person named " << first_name << " " << last_name << " is about to go away.\n";


	// This is where you would do any cleanup
}

/// <summary>
/// gets the ID of the person
/// </summary>
/// <returns> the ID of the person </returns>
int example::Person::get_id()
{
	return id;
}


/// <summary>
/// gets the first name of the person
/// </summary>
/// <returns> the first name of the person </returns>
std::string example::Person::get_first_name()
{
	return first_name;
}

/// <summary>
/// gets the last name of the person
/// </summary>
/// <returns> the last name of the person </returns>
std::string example::Person::get_last_name()
{
	return last_name;
}

/// <summary>
/// gets the hourly rate of the person
/// </summary>
/// <returns> the hourly rate of the person </returns>
float example::Person::get_hourly_rate()
{
	return hourly_rate;
}

/// <summary>
/// gets the number of hours worked by the person
/// </summary>
/// <returns> the number of hours worked by the person </returns>
unsigned int example::Person::get_hours_worked()
{
	return hours_worked;
}





