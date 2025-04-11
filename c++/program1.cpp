// // OOP Concepts

// // Array Programs

// // calPerc: Calculate Percentage

// #include <iostream>
// using namespace std;

// float calPerc(int obtainedMarks, int totalMarks)
// {
//     return (float(obtainedMarks) / totalMarks) * 100;
// }

// int main()
// {
//     const int maxStudents = 100;
//     string studentNames[maxStudents];
//     float studentPercentages[maxStudents];
//     char choice;
//     int totalMarks = 500;
//     int studentCount = 0;
//     string subjects[5] = {"Math", "Physics", "Computer", "Chemistry", "English"};

//     do
//     {
//         if (studentCount >= maxStudents)
//         {
//             cout << "Maximum number of students reached.\n";
//             break;
//         }

//         cout << "Enter Student Name: ";
//         cin >> studentNames[studentCount];

//         int obtainedMarks = 0;
//         cout << "Enter marks for subjects of " << studentNames[studentCount] << ":\n";
//         for (int i = 0; i < 5; i++)
//         {
//             int mark;
//             cout << subjects[i] << ": ";
//             cin >> mark;
//             obtainedMarks += mark;
//         }

//         studentPercentages[studentCount] = calPerc(obtainedMarks, totalMarks);
//         studentCount++;

//         cout << "Do you want to enter another student? (y/n): ";
//         cin >> choice;
//     } while (choice == 'y' || choice == 'Y');

//     cout << "\n--- Students' Percentages ---\n";
//     for (int i = 0; i < studentCount; i++)
//     {
//         cout << studentNames[i] << "'s Percentage: " << studentPercentages[i] << "%\n";
//     }

//     return 0;
// }

// OOP Concepts

// Array Programs

// calPerc: Calculate Percentage

#include <iostream>
using namespace std;

const int maxStudents = 100;
const int totalMarks = 500; // 5 subjects * 100 marks each
string studentNames[maxStudents];
float studentPercentages[maxStudents];
char choice;
int obtainedMarks = 0;

int studentCount = 0;
string subjects[5] = {"Math", "Physics", "Computer", "Chemistry", "English"};

float calPerc(int obtainedMarks, int totalMarks)
{
    return (float(obtainedMarks) / totalMarks) * 100;
}

void showPerc()
{
    cout << "\n--- Students' Percentages ---\n";
    for (int i = 0; i < studentCount; i++)
    {
        cout << studentNames[i] << "'s Percentage Summary: " << studentPercentages[i] << "%\n";
    }
}

void getStudents()
{
    cout << "Enter Student Name: ";
    cin >> studentNames[studentCount];

    cout << "Enter marks for subjects of " << studentNames[studentCount] << ":\n";
    for (int i = 0; i < 5; i++)
    {
        int mark;
        cout << subjects[i] << ": ";
        cin >> mark;
        obtainedMarks += mark;
    }

    studentPercentages[studentCount] = calPerc(obtainedMarks, totalMarks);

    // Show percentage immediately for this student
    cout << "\nPercentage for " << studentNames[studentCount] << ": "
         << studentPercentages[studentCount] << "%\n";

    studentCount++;

    cout << "--------------------------------------------------" << endl;

    cout << "Do you want to enter another student? (y/n): ";
    cin >> choice;
}

// void getStudents()
// {

//     cout << "Enter Student Name: ";
//     cin >> studentNames[studentCount];

//     int obtainedMarks = 0;
//     cout << "Enter marks for subjects of " << studentNames[studentCount] << ":\n";
//     for (int i = 0; i < 5; i++)
//     {
//         int mark;
//         cout << subjects[i] << ": ";
//         cin >> mark;
//         obtainedMarks += mark;
//     }

//     studentPercentages[studentCount] = calPerc(obtainedMarks, totalMarks);
//     studentCount++;

//     cout << "--------------------------------------------------" << endl;

//     cout << "Do you want to enter another student? (y/n): ";
//     cin >> choice;
// }

int main()
{

    do
    {
        if (studentCount >= maxStudents)
        {
            cout << "Maximum number of students reached.\n";
            break;
        }
        getStudents();

    } while (choice == 'y' || choice == 'Y');

    showPerc();

    return 0;
}
