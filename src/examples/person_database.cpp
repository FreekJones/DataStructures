#include <person_database.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>


/// <summary>
/// constructs a PersonDatabase object and loads the database from a file
/// </summary>
example::PersonDatabase::PersonDatabase(std::string fname) //constructor
{
    person_array = nullptr;
    person_array_size = 0;
    filename = fname;

	std::ifstream in_file(filename); //open the file for reading
    if (!in_file) return;

    int id;
    std::string first_name;
    std::string last_name;
    float hourly_rate;
    unsigned int hours_worked;

	while (in_file >> id >> first_name >> last_name >> hourly_rate >> hours_worked)   //read the data from the file
    {
        Person new_person(id, first_name, last_name);             
        new_person.set_hourly_rate(hourly_rate);
        new_person.set_hours_worked(hours_worked);
        add_person(new_person);
    }
}

/// <summary>
/// destructor that saves all stored data to the file before deallocating the memory
/// </summary>
example::PersonDatabase::~PersonDatabase()             //destructor
{	       
	std::ofstream out_file(filename);                  //open the file for writing
	if (out_file)                                      //if the file is open
    {                             
		for (int i = 0; i < person_array_size; i++)           //loop through person_array
        {  
			out_file << person_array[i].get_id() << " "      //write the person's data to the file
				<< person_array[i].get_first_name() << " "
                << person_array[i].get_last_name() << " "
                << person_array[i].get_hourly_rate() << " "
                << person_array[i].get_hours_worked() << "\n";
        }
    }
	delete[] person_array;                               //deallocate the memory
}

/// <summary>
/// adds a new person to the database and throws an exception if the ID already exists
/// </summary>
void example::PersonDatabase::add_person(example::Person new_person)           //add a person to the database
{     
	for (int i = 0; i < person_array_size; i++)                                //loop through all person_array
    {                                 
		if (person_array[i].get_id() == new_person.get_id())                   //if the ID already exists
        {                   
			throw std::runtime_error("ID already exists in the database.");    //throw an exception 
        }
    }

	example::Person* new_array = new Person[person_array_size + 1];     //allocate a new array with one more element
	for (int i = 0; i < person_array_size; i++)                         //copy all elements from the old array to the new array
    {                       
		new_array[i] = person_array[i];                                 //copy the element
    }
	new_array[person_array_size] = new_person;                          //add the new person to the new array
	delete[] person_array;                                              //delete the old array
    person_array = new_array;                                           //assign the new array to the old array
	person_array_size++;                                                //increment the number of person_array_size
}

/// <summary>
/// removes a person from the database by ID if it exists
/// </summary>
/// <returns> TRUE if the person was removed, otherwise FALSE </returns>
bool example::PersonDatabase::remove_person(int id)         //remove a person from the database
{        
	for (int i = 0; i < person_array_size; i++)                    //loop through person_array_size 
    {                    
		if (person_array[i].get_id() == id)                       //if the ID matches
        {                      
			Person* new_array = new Person[person_array_size - 1];  //allocate a new array with one less element
			for (int j = 0, k = 0; j < person_array_size; j++)      //copy all elements except the one to be removed
            {    
				if (j != i)                                  //skip the element to be removed
                {                                
					new_array[k++] = person_array[j];              //copy the element to the new array
                }
            }
			delete[] person_array;          //delete the old array      
            person_array = new_array;       //assign the new array to the old array
			person_array_size--;		    //decrement person_array_size
			return true;		            //return true for successful removal
        }
    }
	return false;                   //return false if the ID was not found
}

/// <summary>
/// returns the number of people in the database
/// </summary>
/// <returns> the number of people in the database </returns>
int example::PersonDatabase::get_num_people()           //return the number of people in the database
{         
	return person_array_size;                           //return the number of people
} 

/// <summary>
/// generates a formatted string report of the database including a total of all salaries
/// the formatting automatically adjusts to the longest name
/// </summary>
/// <returns> a string containing all the data in the database </returns>
std::string example::PersonDatabase::to_string()
{
    std::stringstream report;
    report << std::fixed << std::setprecision(2);  //sets the precision of the output of floats to 2 decimal places

    int max_name_length = 0;                      //set default value of max_name_length to 0
    for (int i = 0; i < person_array_size; i++)    //loop through all person_array
    {
        int name_length = person_array[i].get_first_name().length() + 1 + person_array[i].get_last_name().length();
        //get the length of the full name including the space between the first and last name
        if (name_length > max_name_length)
        {
            max_name_length = name_length;    //update the max_name_length if the current name is longer
        }
    }

    report << "Name";
    for (int i = 4; i < max_name_length; i++)    //starts int at 4 to account for the length of the word "Name"
    {
        report << " ";                      //while its less than the max_name_length, add spaces to the report
    }
    report << "\tID\tHours\tRate\tMonthly Salary\n";   //tabs between each column

    for (int i = 0; i < max_name_length; i++)  //adds a line of equal signs under the name column according to max_name_length
    {
        report << "=";
    }
    report << "\t====\t=====\t======\t==============\n";      //tabs and equal signs aligned with other column headers

    float total_salary = 0;

    for (int i = 0; i < person_array_size; i++)             //loop through all person_array
    {
        float salary = person_array[i].calculate_pay();   //calculate the salary of each person

        report << person_array[i].get_first_name() << " " << person_array[i].get_last_name();  //get the full name of the person

        for (int j = (person_array[i].get_first_name().length() + 1 + person_array[i].get_last_name().length()); j < max_name_length; j++)     
            //add spaces to the report to align the columns
        {
            report << " ";
        }

        report << "\t" << person_array[i].get_id()                 //print the data with tabs between each column
            << "\t" << person_array[i].get_hours_worked()
            << "\t$" << person_array[i].get_hourly_rate()
            << "\t$" << salary << "\n";

        total_salary += salary;                                   //add the salary to the total salary
    }

    report << std::string(max_name_length, '=') << "\t====\t=====\t======\t==============\n";
    report << "Total:";
    for (int i = 5; i < max_name_length; i++)      //adds spacing to the report according to max_name_length
    {
        report << " ";
    }
    report << "\t\t\t\t$" << total_salary << "\n";   //tabs aligned with other columns

    return report.str();          //return the report as a string
}            
