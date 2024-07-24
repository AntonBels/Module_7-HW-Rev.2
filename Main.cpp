#include "IntArray.h"
#include "BadLength.h"
#include "BadRange.h"
#include <iostream>

using namespace std;

int main()
{
  
    try
    {
        IntArray array(10); // Declare an array with n elements

        for (int i{ 0 }; i < 10; ++i) // Fill the array with numbers 1 through 10
            array[i] = i + 1;

        array.resize(8); // Resize the array to 8 elements

        array.insertBefore(20, 5);   // Insert the number 20 before element with index 5

        array.remove(3); // Remove the element with index 3

        array.insertAtEnd(30); // Add 30 and 40 to the end and beginning
        array.insertAtBeginning(40);

        /*A few more tests to ensure copy constructing / assigning arrays
        doesn't break things*/
        {
            IntArray b{ array };
            b = array;
            b = b;
            array = array;
        }

        // Print out all the numbers
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
            std::cout << '\n';
    }
    
    catch (const BadRange& ex_l)
    {
        cout << ex_l.what() << endl;

    }
    catch (const BadLength& ex_r)
    {
        cout << ex_r.what() << endl;
    }
   
return 0;
}

