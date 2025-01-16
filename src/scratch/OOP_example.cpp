#include <person.h>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	//making two instances (or object) of the person class
	Person p(42, "Bob", "Jones");  //using the "real" constructor
	Person q;  // using the default constructor

	p.set_hourly_rate(13.5f);
	p.set_hours_worked(17);

	std::cout << "The pay for p is " << p.calculate_pay() << "\n";
	std::cout << "The pay for q is " << q.calculate_pay() << "\n";


	return 0;
}