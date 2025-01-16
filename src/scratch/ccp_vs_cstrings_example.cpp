#include <iostream>
#include <string>  //<string.h> is the c sting library (not this)
using namespace std; //

int main()
{
    char s;
    s = 'a';
    char c_string[64] = "bob";  
    const char* c_string2 = "sally";
    printf("c_string: %s\n", c_string);
    //c_string = "robert";
    c_string[0] = 'R';
    c_string[1] = 'o';
    c_string[2] = 0;
    strcpy_s(c_string, 64, "robert");
    printf("c_string: %s\n", c_string);
    if (strcmp(c_string, "moo") > 0)
        printf("%s come after \"moo\"\n", c_string);


    //Same, but with c++ strings

    std::string cpp_string = "bob";   //making an INSTANCE of the string class called cpp_string
                                        // std is the NAMESPACE that the string class exists in
    std::cout << cpp_string << "\n";  //C++ style console output -- a taste of c++ streams (this is an ouput stream which is why <<)
    int x = 42;
    std::cout << "a string" << x << "\n";
    cpp_string[0] = 'R';
    cpp_string[1] = 'o';
    cpp_string[2] = 0;
    std::cout << cpp_string << "\n";
    cpp_string = "robert";      //The class handles the memory compy and making enough space to hold this new string
    
    if(cpp_string > "moo")
		std::cout << cpp_string << " comes after \"moo\"\n";
    c_string2 = cpp_string.c_str();  //c_str() is a method of the string class that returns a c-style string

    

}

