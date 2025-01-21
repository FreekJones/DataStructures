#include <iostream>
#include <string>
#include <fstream>

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

#endif

	return 0;
}