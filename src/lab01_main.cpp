#include <person_database.h>


/// <summary>
/// Main function that runs the program.
/// Allows users to add, remove, and print people from the database
/// </summary>
int main() 
{
	example::PersonDatabase db("../../media/person_data.txt");   //create a PersonDatabase object and load the database from a file

    while (true) 
    {
		std::cout << "\nMenu:\n1. Add Person\n2. Remove Person\n3. Print Database\n4. Quit\n";   //menu to prompt user for input
        int choice;

        std::cout << "Enter your choice: ";
		while (!(std::cin >> choice))            //input validation
        {  
            std::cin.clear();
            std::cin.ignore(1000, '\n');  
            std::cout << "Invalid input. Please enter a number between 1 and 4: ";
        }

		if (choice == 1)                 //if user chooses to add a person
        {
			std::string first_name, last_name;      //variables to store user input
            int id;
            float hourly_rate;
            unsigned int hours_worked;

			std::cout << "Enter first name: ";        //get the person's data from the user
            std::cin >> first_name;                  
            std::cout << "Enter last name: ";
            std::cin >> last_name;

			std::cout << "Enter ID: ";             //gets the person's ID from the user with input validation
            while (!(std::cin >> id)) 
            {  
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input. Please enter a valid ID: ";
            }

			std::cout << "Enter hourly rate: ";         //gets the person's hourly rate from the user with input validation
            while (!(std::cin >> hourly_rate)) 
            {  
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input. Please enter a valid hourly rate: ";
            }

			std::cout << "Enter hours worked: ";         //gets the person's hours worked from the user with input validation
            while (!(std::cin >> hours_worked)) 
            {  
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input. Please enter a valid number of hours: ";
            }

			example::Person new_person(id, first_name, last_name);     //create a new Person object with the user's input
			new_person.set_hourly_rate(hourly_rate);               //uses the setter methods to set the hourly rate and hours worked
            new_person.set_hours_worked(hours_worked);

			try                                           //try to add the person to the database
            {
                db.add_person(new_person);  
            } 
			catch (std::runtime_error e)          //if the ID already exists, catch the exception and print an error message
            {
                std::cerr << e.what() << "\n";                 
            }
        }
        else if (choice == 2) 
        {
            int id;
            std::cout << "Enter ID to remove: ";
            while (!(std::cin >> id)) 
            {  
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input. Please enter a valid ID: ";
            }

			if (db.remove_person(id))            //if the ID exists, remove the person from the database
            {
                std::cout << "Person removed.\n";
            }
            else 
            {
                std::cout << "Person not found.\n";
            }
        }
        else if (choice == 3)               //print the database
        {
            std::cout << db.to_string();  
        }
        else if (choice == 4) 
        {
            break;  
        }
        else 
        {
            std::cerr << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}