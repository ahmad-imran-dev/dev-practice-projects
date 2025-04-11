// Array pass by value in C++ new version

#include <iostream>
using namespace std;

struct arr_structure
{
    int array[5];
};

// Function to pass an array by value
void passByValue(arr_structure arr)
{
    cout << "Inside passByValue function: " << endl;
    for (int i = 0; i < 5; i++)
    {
        arr.array[i] += 10; // Modifying array values
        cout << "arr[" << i << "] = " << arr.array[i] << endl;
    }
}

int main()
{
    arr_structure arr = {1, 2, 3, 4, 5};

    cout << "Original array in main: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "arr[" << i << "] = " << arr.array[i] << endl;
    }

    // Passing array by value
    passByValue(arr);

    cout << "\nArray after passByValue (back in main): " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "arr[" << i << "] = " << arr.array[i] << endl;
    }

    return 0;
}