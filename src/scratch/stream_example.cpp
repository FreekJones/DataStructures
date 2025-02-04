#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#define DO_FILE_OUTPUT 0


int main(int argc, char** argv)
{

	#if DO_FILE_OUTPUT

	int x = 42;
	std::string s;
	std::cout << "x = " << x << "\n"; //This is a stream insertion operator, it inserts the value of x into the stream

	std::cout << "Enter a value for x: ";
	std::cin >> x;  //This is a stream extraction operator, it extracts a value from the stream and stores it in x
	if (std::cin.fail())
	{
		std::cout << "There was an error reading the value\n";
		x = -1;
		//cin attempted to read an integer, but failed.  cin consumed the text we entered, but the new line is still in the buffer.
		// cin is in an error state right now.  To fix both:
		std::cin.clear(); //Clear the error state
		std::cin.ignore(1000, '\n'); //Ignore up to 1000 characters or until we hit a newline
	}
	std::cout << "x now equals " << x << "\n";

	std::cout << "Enter a string: ";
	//This reads a string until the first whitespace character.  Any future cin's will use the remaining strings in the buffer.
	//Note how after getting our string, I use ignore to consume anything ELSE is the buffer including the newline.
	std::cin >> s; //This will only read up to the first whitespace character
	std::cin.ignore(1000, '\n');
	std::cout << "s now equals '" << s << "'\n";

	std::cout << "Enter a string with whitespace: ";
	//getline reads from cin into s until \n is reached
	std::getline(std::cin, s); //This will read the entire line
	std::cout << "s now equals '" << s << "'\n";



	//FILE OUTPUT
	std::ofstream fp("../../media/test.txt");  //This will create a file called test.txt in the current directory -- o = output (text-file by default)
	fp << "This is a line\n";
	fp << "x = " << x << "\n";
	fp << "And we're done!\n";
	fp.close(); //Closes the file

//FILE INPUT

#else
	
	std::ifstream fp("..\\..\\media\\test.txt"); //This will open the file test.txt in the current directory for reading -- i = input (text-file by default)	
	if (!fp.is_open())
	{
		std::cout << "Error opening ..\\..\\media\\test.txt\n";
		return 1;
	}

	std::string temp_line;
	std::getline(fp, temp_line);
	std::cout << "Line0=" << temp_line << "\n";

	//Line2 is of the form "x = 42" -- how to get the number?
	fp.ignore(4, '\n'); //Ignore the first 4 characters or until we hit a newline
	int real_x;
	fp >> real_x;
	fp.ignore(1000, '\n'); //Ignore up to 1000 characters or until we hit a newline
	std::cout << "got x's value of " << real_x << "\n";

	std::getline(fp, temp_line);
	std::cout << "Line2=" << temp_line << "\n";
	
	
	// Read in all data from the file

	int new_id;
	float new_rate;
	unsigned int new_hours;
	std::string new_fname, new_lname;

	std::cout << std::fixed << std::setprecision(2);

	while (true)
	{
		// When we test for end-of file (technically only when we try to read PAST the end)
		// So generally, you'll read a bit, then see if we are now at the end.
		fp >> new_id >> new_fname >> new_lname >> new_rate >> new_hours;
		if (fp.eof())
			break; //If we are at the end of the file, then break
		else if (fp.fail())
			std::cout << "Error reading data\n";
		//Do something with the data (you'll put in an array) -- we'll just print
		std::cout << "Got Person\n\tid=" << new_id << "\n\tfname='" << new_fname;
		std::cout << "\n\tlname='" << new_lname << "\n\trate=$" << new_rate << "\n\thours=";
		std::cout << new_hours << "\n";
	}


	
	fp.close();
#endif

	return 0;
}
