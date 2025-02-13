#include <iostream>
#include "array_list.h"

int main()
{
    ssuds::ArrayList<int> int_list;

    std::cout << "=====Appending values (10,20,30)=====\n";
    int_list.append(10);
    int_list.append(20);
    int_list.append(30);
	int_list.append(40);
	int_list.append(50);
	int_list.append(60);
    int_list.output(std::cout);
    std::cout << std::endl;
    std::cout << "\n";

	std::cout << "=====Finding value 30=====\n";
	int index = int_list.find(30);
	std::cout << "Index of 30: " << index << "\n";
	std::cout << "\n";

	std::cout << "=====Value at index 4=====\n";
	std::cout << int_list.at(4) << "\n";
	std::cout << "\n";

    try
    {
    std::cout << "=====Attempting to access index 3 (out of range)=====\n";
    std::cout << "Value at index 3: " << int_list.at(12) << std::endl;  
    }
    catch (const std::out_of_range& e)
    {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	std::cout << "\n";
		

    std::cout << "\n=====Prepending value (5)=====\n";
    int_list.prepend(5);
    int_list.output(std::cout);
    std::cout << "\n";

    std::cout << "\n=====Inserting (15) at index 2=====\n";
    int_list.insert(15, 2);
    int_list.output(std::cout);
    std::cout << "\n";

    std::cout << "\n=====Removing value at index 1=====\n";
    int_list.remove(1);
    int_list.output(std::cout);
    std::cout << "\n";

    std::cout << "\n=====Appending duplicate 20's and testing remove_all=====\n";
    int_list.append(20);
    int_list.append(20);
    int_list.output(std::cout);
    std::cout << "\n";

    unsigned int removed_count = int_list.remove_all(20);
    std::cout << "Removed " << removed_count << " occurrences of 20\n";
    int_list.output(std::cout);
    std::cout << "\n";

    std::cout << "\n=====Testing reserve()=====\n";
    std::cout << "Initial capacity: " << int_list.capacity() << "\n";
    int_list.reserve(42);
    std::cout << "Capacity after reserve(): " << int_list.capacity() << "\n";

    std::cout << "\n=====Testing array shrinkage=====\n";

    std::cout << "=====Appending values to grow capacity=====\n";
    for (int i = 0; i < 50; i++)
    {
        int_list.append(i);
    }
    int_list.output(std::cout);
    std::cout << "\nCurrent capacity: " << int_list.capacity() << "\n";

    std::cout << "\n=====Removing elements one by one=====\n";
    for (int i = 0; i < 40; i++)
    {
        int_list.remove(0);
    }
    int_list.output(std::cout);
    std::cout << "\nCapacity after removal: " << int_list.capacity() << "\n";

    std::cout << "\n=====Testing with strings=====\n";
    ssuds::ArrayList<std::string> string_list;
    string_list.append("John");
    string_list.append("Bear");
    string_list.prepend("Bocephus");
    string_list.insert("FreekJones", 1);
    string_list.prepend("Micah");
    string_list.append("Micah");
    string_list.append("Micah");
    string_list.output(std::cout);
    std::cout << "\n";
    std::cout << "=====Testing remove_all=====\n";
    string_list.remove_all("Micah");
    string_list.output(std::cout);
    std::cout << "\n";

    std::cout << "=====Testing floats=====\n";
	ssuds::ArrayList<float> float_list;
	float_list.append(1.1f);
	float_list.append(2.2f);
	float_list.prepend(3.3f);
	float_list.insert(4.4f, 1);
	float_list.prepend(5.5f);
	float_list.append(5.5f);
	float_list.append(5.5f);
	float_list.output(std::cout);
	std::cout << "\n";
	std::cout << "=====Testing remove_all=====\n";
	float_list.remove_all(5.5f);
	float_list.output(std::cout);
	std::cout << "\n";

    return 0;
}