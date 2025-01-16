// person.cpp --- houses the BODIES(DEFINITIONS) of all methods

#include <person.h>

// General structure: ReturnType  ClassName::MethodName(Parameters)   { . . . . }

float Person::calculate_pay()
{
	// We have access to all attributes since we're a part of the class
	return hourly_rate * hours_worked;
}

void Person::set_hourly_rate(float new_rate)
{
	hourly_rate = new_rate;
}

void Person::set_hours_worked(unsigned int new_hours)
{
	hours_worked = new_hours;
}

Person::Person()
{
	id = -1;
	first_name = "?";
	last_name = "?";
	hourly_rate = 0.0f;
	hours_worked = 0;
}

Person::Person(int start_id, std::string start_fname, std::string start_lname)
{
	id = start_id;
	first_name = start_fname;
	last_name = start_lname;
	hourly_rate = 0.0f;
	hours_worked = 0;
}

int Person::get_id()
{
	return id;
}

std::string Person::get_first_name()
{
	return first_name;
}

std::string Person::get_last_name()
{
	return last_name;
}

