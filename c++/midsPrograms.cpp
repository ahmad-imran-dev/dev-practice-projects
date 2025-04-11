
// This program display numbers from 1 to 10

#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " ";
    }
    return 0;
}

// This program calculates the table of a number.

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    for (int i = 1; i <= 10; i++)
    {
        cout << num << " x " << i << " = " << num * i << endl;
    }
    return 0;
}

// This program checks if a number is even or odd.

#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Even numbers: ";
    for (int num : arr)
    {
        if (num % 2 == 0)
            cout << num << " ";
    }

    cout << "\nOdd numbers: ";
    for (int num : arr)
    {
        if (num % 2 != 0)
            cout << num << " ";
    }
    return 0;
}

// This program take input for array.

#include <iostream>
using namespace std;

void inputArray(int ar[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> ar[i];
    }
}

// This program displays the elements of an array.

#include <iostream>
using namespace std;

void displayArray(int ar[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

// This program counts the number of positive integers in an array.

#include <iostream>
using namespace std;

int countPositive(int ar[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (ar[i] > 0)
            count++;
    }
    return count;
}

// This program calculates the net salary based on experience and salary.

#include <iostream>
using namespace std;

int main()
{
    const int BONUS = 1000;
    int experience;
    float salary, net_salary;

    for (int i = 1; i <= 3; i++)
    {
        cout << "User " << i << ":\n";
        cout << "Enter experience (years): ";
        cin >> experience;
        cout << "Enter salary: ";
        cin >> salary;

        net_salary = (experience > 5) ? salary + BONUS : salary;
        cout << "Net Salary: " << net_salary << "\n\n";
    }
    return 0;
}

// This program counts the number of negative integers in an array.

#include <iostream>
using namespace std;

int countNegative(int ar[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (ar[i] < 0)
            count++;
    }
    return count;
}

// This program finds the minimum and maximum values in an array.

#include <iostream>
using namespace std;

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

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// This program calculates the percentage of marks obtained by a student.

#include <iostream>
using namespace std;

int main()
{
    string name;
    float marks[5], total = 0;

    cout << "Enter student name: ";
    cin >> name;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter mark " << i + 1 << ": ";
        cin >> marks[i];
        total += marks[i];
    }

    float percentage = (total / 500) * 100;
    cout << "Percentage: " << percentage << "%" << endl;
    return 0;
}

// This program checks the day name.

#include <iostream>
using namespace std;

int main()
{
    int day;
    cout << "Enter day number (1-7): ";
    cin >> day;

    switch (day)
    {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:
        cout << "Invalid day";
    }
    return 0;
}

// This program copies elements from one array to another.

#include <iostream>
using namespace std;

int main()
{
    int source[] = {10, 20, 30, 40, 50};
    int dest[5];

    for (int i = 0; i < 5; i++)
    {
        dest[i] = source[i];
    }

    cout << "Copied array: ";
    for (int num : dest)
    {
        cout << num << " ";
    }
    return 0;
}

// This program calculates the average of 5 numbers.

#include <iostream>
using namespace std;

float calculateAverage()
{
    float values[5], sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> values[i];
        sum += values[i];
    }
    return sum / 5;
}

int main()
{
    float avg = calculateAverage();
    cout << "Average: " << avg;
    return 0;
}
