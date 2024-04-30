#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Declare functions before using them
void addEmployeeName();
void showEmployees();
bool check();     // Changed the return type to bool
bool checkUser(); // Changed the return type to bool
bool menu();
bool low = true;
int choice;

void addEmployeeName()
{
    // adding string
    string fname, mname, lname;
    cout << "Enter the employee name (first middle last): ";
    cin >> fname >> mname >> lname;
    string fullName = fname + " " + mname + " " + lname;

    // adding salary
    int salary;
    cout << "Enter the employee salary: ";
    cin >> salary;

    // Open the file in append mode and write the employee data
    ofstream outFile("employee_data.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "ُ\nEmployee name : " << fullName << "   "
                << "Salary : " << salary << endl;
        outFile.close();
        cout << endl
             << "Employee data has been successfully added." << endl
             << endl;
    }
    else
    {
        cout << "Unable to open file for writing!" << endl;
    }
    if (!check()) // Terminate if check() returns false
        return;
}

void showEmployees()
{
    ifstream file("employee_data.txt");
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    check(); // Check for termination after retrieving
}

bool check()
{
    string choice;
    cout << "\nEnd the program (yes / no) : ";
    cin >> choice;
    if (choice == "yes")
    {
        cout << "\nThanks....End\n";
        low = false;  // Set low to false to terminate the loop in menu()
        return false; // Indicate program should terminate
    }
    else if (choice == "no")
    {
        return true; // Indicate program should continue
    }
    else
    {
        cout << "\nPlease enter the choice .......!";
        return check(); // Return the recursive call result
    }
}

bool checkUser()
{
    string userName;
    cout << "Please enter your username: ";
    cin >> userName;

    if (userName == "youcef")
    {
        cout << "Welcome youcef..!" << endl;
        int password;
        cout << "**Please enter your password: ";
        cin >> password;
        if (password == 2486)
        {
            cout << endl
                 << "Welcome to your database." << endl;
            menu();
            return true; // Correct username and password
        }
        else
        {
            cout << "# Invalid password. Please try again. #" << endl;
            checkUser();
            return false; // Incorrect password
        }
    }
    else
    {
        cout << "# Invalid username. Please try again. #" << endl;
        checkUser();
        return false; // Incorrect username
    }
}

bool menu()
{
    while (low) // Loop until user chooses to exit
    {
        cout << "Choose your process:" << endl;
        cout << "1. Add new employee" << endl;
        cout << "2. Show employees" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployeeName();
            break;
        case 2:
            showEmployees();
            break;
        case 3:
            cout << "Exiting program." << endl;
            low = false; // Terminate the loop
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main()
{
    checkUser();
}
