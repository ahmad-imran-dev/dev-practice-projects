// Pass by reference and pass by value in C++ older version

#include <iostream>
using namespace std;

// Function to pass an array by value
void passByValue(int arr[], int size)
{
    cout << "Inside passByValue function: " << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] += 10; // Modifying array values
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

// Function to pass an array by reference
void passByReference(int (&arr)[5], int size)
{
    cout << "Inside passByReference function: " << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] += 20; // Modifying array values
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main()
{
    const int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};

    cout << "Original array in main: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // Passing array by value
    passByValue(arr, size);

    cout << "\nArray after passByValue (back in main): " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // Passing array by reference
    passByReference(arr, size);

    cout << "\nArray after passByReference (back in main): " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    return 0;
}