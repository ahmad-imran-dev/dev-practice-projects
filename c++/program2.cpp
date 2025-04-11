#include <iostream>
#include <vector>
using namespace std;

// Code for comparing numbers in array

int minIndex = 0;
int maxIndex = 0;

void compareFunc(int arr[])
{
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < 8; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    }
}

int main()
{
    int arr[8] = {10, 2, 11, 5, 3, 1, 9, 17};
    compareFunc(arr);

    cout << "Maximum Number is " << arr[maxIndex] << " at " << maxIndex << endl;
    cout << "Minimum Number is " << arr[minIndex] << " at " << minIndex << endl;
    return 0;
}

// Advanced code -----------------------------------------------------------

int main()
{
    char choice;
    int minIndex = 0;
    int maxIndex = 0;
    vector<int> arr = {};
    auto compareFunc = [&](vector<int> arr, int arrSize)
    {
        int max = arr[0];
        int min = arr[0];

        for (int i = 0; i < arrSize; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                maxIndex = i;
            }
            if (arr[i] < min)
            {
                min = arr[i];
                minIndex = i;
            }
        }
    };

    do
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        arr.push_back(num);
        cout << "Do you want to enter another number? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    compareFunc(arr, arr.size());
    cout << "Maximum Number is " << arr[maxIndex] << " at " << maxIndex << endl;
    cout << "Minimum Number is " << arr[minIndex] << " at " << minIndex << endl;
    return 0;
}