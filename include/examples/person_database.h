#ifndef PERSON_DATABASE_H
#define PERSON_DATABASE_H

#include <person.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

/// <summary>
/// namespace example is used to define the class PersonDatabase and its methods.
/// </summary>
namespace example
{
    /// <summary>
	/// The class PersonDatabase represents a database of Person objects that is dynamically allocated 
	/// and can be saved to and loaded from a file.  It has methods to add and remove people from the database. 
	/// It also has a method to return a string representation of the database called to_string.
    /// </summary>
    class PersonDatabase 
    {
	private:

        /// <summary>
		/// Person* person_array is a dynamically allocated array of Person objects that grows and shrinks as people are
        /// added or removed. 
        /// </summary>
        Person* person_array;

        /// <summary>
		/// person_array_size is the number of people currently stored in the database.
        /// </summary>
        int person_array_size;

        /// <summary>
		/// std::string filename is the file path for loading/saving the database.
        /// </summary>
        std::string filename;

	public:
        /// <summary>
		/// Constructs a PersonDatabase object and loads the database from a file.
        /// </summary>
        /// <param name="filename"> The path to the file containing the person data </param>
        PersonDatabase(std::string filename); 

        /// <summary>
		//// Destroys the PersonDatabase object, saving all stored data to the file before deallocating memory.
        /// </summary>
        ~PersonDatabase();                   

        /// <summary>
		/// add_person method that adds a person to the database ensuring no duplicate ID exists.
        /// </summary>
        /// <param name="new_person"> The Person object to be added to the database </param>
        void add_person(Person new_person);

        /// <summary>
		/// remove_person method that removes a person from the database.
        /// </summary>
        /// <param name="id"> The ID of the person to be removed </param>
        /// <returns> Returns TRUE if successfully removed, else returns FALSE </returns>
        bool remove_person(int id);

        /// <summary>
		/// get_num_people method that returns the number of people in the database.
        /// </summary>
        /// <returns> The number of people in the database </returns>
        int get_num_people();

        /// <summary>
		/// to_string is a method that returns a string representation of PersonDatabase.
        /// </summary>
        /// <returns>  A string containing a formatted representation of all stored people in the database </returns>
        std::string to_string();
    };
}
#endif // PERSON_DATABASE_H
