#include <array_list.h>
#include <iostream>
#include <string>

int main()
{

	//--------------------------------------------------------------------------------------------------------//
	//Creates an ArrayList of integers with an initializer list.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Creating an ArrayList with an initializer list==========" << std::endl;

    ssuds::ArrayList<int> list = { 10, 20, 30, 40, 50 };
    std::cout << "\n";

    //--------------------------------------------------------------------------------------------------------//
	// Tests the overloaded << operator for the ArrayList class.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Testing overloaded << operator==========" << std::endl;
    
    std::cout << "List: " << list << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	// Tests the begin() and end() functions for the ArrayList class with forward iteration.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Testing forward iteration==========" << std::endl;
    
    std::cout << "Forward Iteration: ";
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";     
    }
    std::cout << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	// Tests the rbegin() and rend() functions for the ArrayList class with reverse iteration.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Testing reverse iteration==========" << std::endl;
    
    std::cout << "Reverse Iteration: ";
    for (auto it = list.rbegin(); it != list.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//Tests the find() and remove() function for the ArrayList class.
    //--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Testing find() and remove() functions==========" << std::endl;
    
    std::cout << "Finding value 30..." << std::endl;
    auto it = list.find(30);

    if (it != list.end())
    {
        std::cout << "Found 30, removing it..." << std::endl;
        list.remove(it);
        std::cout << "List after removal: " << list << std::endl;
    }
    else
    {
        std::cout << "Value 30 not found in the list." << std::endl;
    }
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//Foward Iteration after removing 30.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Testing forward iteration after removing 30==========" << std::endl;
    
    std::cout << "Forward Iteration: ";
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//Reverse Iteration after removing 30.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Testing reverse iteration after removing 30==========" << std::endl;
    
    std::cout << "Reverse Iteration: ";
    for (auto it = list.rbegin(); it != list.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//Output the list size and capacity.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Testing size() and capacity()==========" << std::endl;
    
    std::cout << "List size: " << list.size() << std::endl;
	std::cout << "List capacity: " << list.capacity() << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//Testing the insert() function and re-inserting 30.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Testing insert() function==========" << std::endl;

    std::cout << "Inserting 30 at index 2" << std::endl;
	list.insert(30, 2);

	std::cout << "List: " << list << std::endl;
    std::cout << "\n";

    //--------------------------------------------------------------------------------------------------------//
    //This test uses the remove_all() function to remove all occurrences of a value from the list.
    //--------------------------------------------------------------------------------------------------------//
    std::cout << "==========Testing remove_all() function==========" << std::endl;
    list.append(42);
    list.prepend(42);
    list.append(42);

    std::cout << "Before remove_all(42): " << list << std::endl;

    unsigned int removed_count = list.remove_all(42);

    std::cout << "After remove_all(42): " << list << std::endl;
    std::cout << "Number of elements removed: " << removed_count << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//Testing appending 50 items to ensure the list still grows properly.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Appending 50 items to the list==========" << std::endl;
    for (int i = 0; i < 50; i++)
	{
		list.append(i);
	}
	std::cout << "List: " << list << std::endl;

	std::cout << "List size: " << list.size() << std::endl;
	std::cout << "List capacity: " << list.capacity() << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//Testing the remove() function by removing 50 items from the list to ensure list shrinks properly.
	//--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Removing 50 items from the list==========" << std::endl;
    for (int i = 0; i < 50; i++)
    {
        list.remove(list.rbegin()); 
    }
	std::cout << "List: " << list << std::endl;
	std::cout << "List size: " << list.size() << std::endl;
	std::cout << "List capacity: " << list.capacity() << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//Testing the reserve() function alone by increasing the capacity to 20.
	//--------------------------------------------------------------------------------------------------------//
    std::cout << "==========Manually reserving capacity for 20 for testing==========" << std::endl;
    list.reserve(20);
	
	std::cout << "List size: " << list.size() << std::endl;
	std::cout << "List capacity: " << list.capacity() << std::endl;
    std::cout << "\n";

    //--------------------------------------------------------------------------------------------------------//
    // Testing the overloaded + operator for ArrayListIterator.
    // This test moves the iterator forward and backward using integer addition.
    //--------------------------------------------------------------------------------------------------------//
    std::cout << "==========Testing iterator position shifting with + operator==========" << std::endl;

    auto it_test = list.begin();  
    std::cout << "Initial iterator position (should be first element): " << *it_test << std::endl;

    it_test = it_test + 2;  
    std::cout << "Iterator after moving forward 2 positions: " << *it_test << std::endl;

    it_test = it_test + (-1);  
    std::cout << "Iterator after moving backward 1 position: " << *it_test << std::endl;
    std::cout << "\n";

    //--------------------------------------------------------------------------------------------------------//
    // Testing reverse iterator position shifting with + operator.
    // This test moves the reverse iterator forward (which means backward in index).
    //--------------------------------------------------------------------------------------------------------//
	std::cout << "==========Testing reverse iterator position shifting with + operator==========" << std::endl;

    auto reverse_it_test = list.rbegin();  
    std::cout << "Initial reverse iterator position (should be last element): " << *reverse_it_test << std::endl;

    reverse_it_test = reverse_it_test + 2;  
    std::cout << "Reverse iterator after moving forward 2 positions (back in index): " << *reverse_it_test << std::endl;

    reverse_it_test = reverse_it_test + (-1);  
    std::cout << "Reverse iterator after moving backward 1 position (forward in index): " << *reverse_it_test << std::endl;
    std::cout << "\n";

    //--------------------------------------------------------------------------------------------------------//
	//This test uses the [] operator to access and modify elements in the list.
	//--------------------------------------------------------------------------------------------------------//
    std::cout << "==========Testing [] operator==========" << std::endl;
    std::cout << "Element at index 1 using []: " << list[1] << std::endl;

    list[1] = 42;
    std::cout << "After modifying index 1 with [], List: " << list << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//This test uses the copy constructor to create a new list with the same elements.
	//--------------------------------------------------------------------------------------------------------//
    std::cout << "==========Testing copy constructor==========" << std::endl;
    ssuds::ArrayList<int> copiedList = list;
    std::cout << "Copied list: " << copiedList << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//This test uses the assignment operator to assign the list to a new list.
	//--------------------------------------------------------------------------------------------------------//
    std::cout << "==========Testing assignment operator==========" << std::endl;
    ssuds::ArrayList<int> assignedList;
    assignedList = list;
    std::cout << "Assigned list: " << assignedList << std::endl;
    std::cout << "\n";

	//--------------------------------------------------------------------------------------------------------//
	//This test uses the move constructor to create a new list by moving the elements from the original list.
	//--------------------------------------------------------------------------------------------------------//
    std::cout << "==========Testing move constructor==========" << std::endl;
    ssuds::ArrayList<int> movedList = std::move(list);
    std::cout << "Moved list: " << movedList << std::endl;

    //--------------------------------------------------------------------------------------------------------//
    // Testing ArrayList with floats
    //--------------------------------------------------------------------------------------------------------//
    std::cout << "==========Testing ArrayList with float==========" << std::endl;

    ssuds::ArrayList<float> floatList = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
    std::cout << "Float List: " << floatList << std::endl;

    floatList.append(6.6f);
    std::cout << "After appending 6.6: " << floatList << std::endl;

    floatList.remove_all(2.2f);
    std::cout << "After removing 2.2: " << floatList << std::endl;

    std::cout << "Forward Iteration: [";
    for (auto it = floatList.begin(); it != floatList.end(); ++it)
    {
        std::cout << *it;
        if ((it + 1) != floatList.end()) std::cout << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Reverse Iteration: [";
    for (auto it = floatList.rbegin(); it != floatList.rend(); ++it)
    {
        std::cout << *it;
        if ((it + 1) != floatList.rend()) std::cout << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "\n";

    //--------------------------------------------------------------------------------------------------------//
    // Testing ArrayList with strings
    //--------------------------------------------------------------------------------------------------------//
    std::cout << "==========Testing ArrayList with strings==========" << std::endl;

    ssuds::ArrayList<std::string> stringList = { "Bocephus", "FreekJones", "Jerron", "Squirrel" };
    std::cout << "String List: " << stringList << std::endl;

    stringList.append("Aaron");
    std::cout << "After appending 'Aaron': " << stringList << std::endl;

	stringList.prepend("Aaron");
	std::cout << "After prepending 'Aaron': " << stringList << std::endl;

	stringList.insert("Aaron", 2);
	std::cout << "After inserting 'Aaron' at index 2: " << stringList << std::endl;

    stringList.remove_all("Aaron");
    std::cout << "After removing 'Aaron': " << stringList << std::endl;

    std::cout << "Forward Iteration: [";
    for (auto it = stringList.begin(); it != stringList.end(); ++it)
    {
        std::cout << *it;
        if ((it + 1) != stringList.end()) std::cout << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Reverse Iteration: [";
    for (auto it = stringList.rbegin(); it != stringList.rend(); ++it)
    {
        std::cout << *it;
        if ((it + 1) != stringList.rend()) std::cout << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "\n";

    return 0;
}