#include <person.h>
#include <iostream>
#include <string>

void func()
{
	Person a(45, "Sally", "Smith");
	std::cout << "Doing something...\n";
}

int main(int argc, char** argv)
{
	//making two instances (or object) of the person class
	Person p(42, "Bob", "Jones");  //using the "real" constructor
	Person q;  // using the default constructor

	p.set_hourly_rate(13.5f);
	p.set_hours_worked(17);

	func();

	Person* pptr;             // Declaring a pointer to a Person(not a person)
							  //uninitialized at the moment;
	pptr = NULL;   // NULL is a special value that means "nothing"
	int x = NULL;
	pptr = nullptr;  //like NULL but can only be assigned to pointer types
	
	pptr = new Person(46, "Jim", "Price"); //new is like malloc in c++ - it allocates memory on the heap - Returns a pointer to a person
						                   //malloc doesn't do anything with constructors or destructors
	// Examples of DE-REFERENCING a pointer
	pptr->set_hourly_rate(11.3f);
	(*pptr).set_hourly_rate(11.3f);  //This is the same as the line above
	std::cout << "Doing some more stuff with the Person pointed to by pptr\n";
	// Free up that Person object that we allocated from (new)
	delete pptr;  //delete is like free in c++ - it calls the destructor and frees up the memory
	//pptr's still holding the address of the memory that was allocated, but that memory is no longer valid (DANGLING POINTER)
	//don't use that address or bad things will happen. Calling delete causes the destructor to get run AND then the memory is freed up

	pptr = nullptr;

	pptr = new Person(47, "Julia", "Young");
	pptr->set_hourly_rate(14.5f);
	delete pptr;   //This calls the destructor and frees up the memory
				   //pointed to by pptr.  

	std::cout << "The pay for p is " << p.calculate_pay() << "\n";
	std::cout << "The pay for q is " << q.calculate_pay() << "\n";


	return 0;
}