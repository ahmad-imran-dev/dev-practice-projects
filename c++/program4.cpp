#include <iostream>
using namespace std;

const int CURRENT_YEAR = 2025;
const int MAX_EMPLOYEES = 100;
const double BONUS_RATE = 0.1;
const int BONUS_EXP_LIMIT = 5;
int count = 0;
char continueInput = 'y';

int calculateExperience(int startingYear)
{
    return CURRENT_YEAR - startingYear;
}
double calculateSalary(int experience, double baseSalary)
{
    if (experience > BONUS_EXP_LIMIT)
    {
        return baseSalary + (baseSalary * BONUS_RATE);
    }
    return baseSalary;
}

void inputEmployee(string names[], int experiences[], int salaries[], int index)
{
    cout << "Enter employee name: ";
    cin >> names[index];
    cout << "Enter last experience year: ";
    int lastExperienceYear;
    cin >> lastExperienceYear;
    cout << "Enter base salary: $";
    double baseSalary;
    cin >> baseSalary;

    experiences[index] = calculateExperience(lastExperienceYear);
    salaries[index] = calculateSalary(experiences[index], baseSalary);
}

void displayEmployee(const string &name, int experience, int salary)
{
    cout << "Name: " << name << endl;
    cout << "Years of Experience: " << experience << endl;
    cout << "Net Salary: $" << salary << endl;
    cout << "----------------------------------------" << endl;
}

void choiceFunc(string names[], int experiences[], int salaries[])
{
    while (continueInput == 'y' && count < MAX_EMPLOYEES)
    {
        inputEmployee(names, experiences, salaries, count);
        count++;

        cout << "\nAdd another employee? (y/n): ";
        cin >> continueInput;
    }
}

void displaySummary(string names[], int experiences[], int salaries[])
{
    cout << "\nEmployees Summary:" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < count; i++)
    {
        displayEmployee(names[i], experiences[i], salaries[i]);
    }
}

int main()
{
    string names[MAX_EMPLOYEES];
    int experiences[MAX_EMPLOYEES];
    int salaries[MAX_EMPLOYEES];

    choiceFunc(names, experiences, salaries);
    displaySummary(names, experiences, salaries);
    return 0;
}