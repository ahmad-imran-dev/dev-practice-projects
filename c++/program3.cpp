#include <iostream>
using namespace std;

void inputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void displayArray(int arr[], int size)
{
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int countPositive(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            count++;
    }
    return count;
}

int countNegative(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            count++;
    }
    return count;
}

int findMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main()
{
    const int SIZE = 5;
    int arr[SIZE];

    inputArray(arr, SIZE);
    displayArray(arr, SIZE);

    cout << "Sum of Positive numbers: " << countPositive(arr, SIZE) << endl;
    cout << "Sum of Negative numbers: " << countNegative(arr, SIZE) << endl;
    cout << "Minimum number in array is " << findMin(arr, SIZE) << endl;
    return 0;
}
