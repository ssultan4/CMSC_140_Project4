/*
 * Class: CMSC 140 CRN 23506
 * Instructor: Greg Grinberg
 * Description: Project 4: Input the number of employees and number of absences per employee and determine the average number of absences per employee.
 * Due: 11/22/2020
 * I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 Print your Name here: Sereen Sultana ____
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ofstream fout; //create object to write to file

/*
 * The function will receive no arguments.
 * It will ask the user for the total number of employees in the company.
 * The function will return the inputted number of employees in the company.
 */
int numOfEmployees()
{
    int numEmployees = 0;
    
    cout << "Please enter the number of employees at the company: ";
    cin >> numEmployees; //Input the number of employees in the company
    while (numEmployees <= 0) //Verify the number of employees is not equal to or less than 0
    {
        if (numEmployees < 0) //If less than 0, remind the user the company cannot have negative employees!
        {
            cout << "You cannot have less than 0 employees!" << endl;
        }
        else if (numEmployees == 0) //If number is equal to 0, remind the user the company must have at least one employee.
        {
            cout << "You cannot have 0 employees!" << endl;
        }
        cout << "Your entry was invalid. The company must have at least 1 employee. \nPlease enter the number of employees at the company: ";
        cin >> numEmployees;
    }
    return numEmployees; //Return the number of employees
}

/*
 * The function will receive one int arguments.
 * The function will receive the number of employees in the company, ask the user for each employee's number ID, and the number of days that employee was absent. This information will be written to file. The total number of absences will be recorded.
 * The function will return the total number of absences from all of the employees.
 */
int totDaysAbsent(int numEmployees)
{
    int numID = 0;
    int numDaysAbsent = 0;
    int totDaysAbsent = 0;
    
    fout << left << setw(30) << "Employee Number ID:" << "Number of Absences:" << endl;
    //Write the heading for the two columns to the file
    
    for (int n = 1; n <= numEmployees; n++) //for loop will go through each employee in the company
    {
        cout << "\nEnter the 4 digit number ID for employee number " << n << " please: ";
        cin >> numID; //Input ID number for each employee
        fout << left << setw(30) << numID; //write the numID for each employee into the file. Have a space so the number of days absent will be store next to the employee ID number
        cout << "Thank you. For employee with the ID number " << numID << ", please enter the number of days this employee was absent this year: ";
        cin >> numDaysAbsent;
        while (numDaysAbsent < 0)
            //Validate the number of days abscent is not negative
        {
            cout << "The number of days absent cannot be less than 0!" << endl;
            cout << "Please enter the number of days employee with the ID number " << numID << " was absent this year: ";
            cin >> numDaysAbsent;
        }
        fout << numDaysAbsent << endl; //write the number of days absent for each employee into the file
        totDaysAbsent += numDaysAbsent;
    }
    return totDaysAbsent;
}

/*
 * The function will receive two int arguments and return one double.
 * The function will receive the number of employees and the number of total days absent in the company. It will calculate the average and store the value as  double.
 * The function will return the calculated double of the average number of absences for each employee.
 */
double AverageAbsent(int numEmployees, int totDaysAbsent)
{
    double avgDaysAbsent = 0.0;
    avgDaysAbsent = totDaysAbsent / (numEmployees / 1.0); //calculate the average
    return avgDaysAbsent;
}

/*
 * The main function
 */
int main() {
    //Variables
    string programmerName = "Sereen Sultana";
    string projectNum = "Project 4";
    string dueDate = "November 22, 2020";
    string response = "Yes";
    int numEmployees = 0;
    int totalDaysAbsent = 0;
    double avgAbsent = 0.0;
    fout.open("employeeAbsences.txt"); //open the file
    
    cout << "Welcome to the Employee Abscense Program." << endl;
    cout << "Today, we will help you calculate the average number of absences per employee in your company." << endl;
    cout << "Would you like to use this program? Please type Yes or No: ";
    cin >> response;
    
    while (response != "Yes" && response != "No") //Invalid entry
    {
        cout << "\nThat is not a valid entry. Please type Yes or No if you would like to use this program: ";
        cin >> response;
    }
    
    if (response == "Yes") //Choose to use the program.
    {
        numEmployees = numOfEmployees(); //call function to input number of employees
        totalDaysAbsent = totDaysAbsent(numEmployees); //call function to determine number of days absent in total
        avgAbsent = AverageAbsent(numEmployees, totalDaysAbsent); //call function to determine the average number of days absent per employee
        
        cout << "\nIn a company with " << numEmployees << " employees, the total and average number of absences are as follows: " << endl;
        cout << left << setw(30) << "Total number of absences: " << left << setw(30) << totalDaysAbsent << endl;
        cout << fixed << setprecision(1) << left << setw(30) << "Average number of absences: " << left << setw(30) << avgAbsent << endl;
        cout << "\nThank you for using our program! We hope you have a good day." << endl;
        
        //Write to file
        fout << "\nIn a company with " << numEmployees << " employees, the total and average number of absences are as follows: " << endl;
        fout << left << setw(30) << "Total number of absences: " << left << setw(30) << totalDaysAbsent << endl;
        fout << fixed << setprecision(1) << left << setw(30) << "Average number of absences: " << left << setw(30) << avgAbsent << endl;
    }
    
    if (response == "No") //Choose to not use the program.
    {
        cout << "\nYou chose to not use the program. Thank you and have a good day." << endl;
    }
    
    fout.close(); //close the file
    cout << endl;
    //End the program by stating name of programmer
    cout << left << setw(20) << "Programmer: " << left << setw(10) << programmerName << endl;
    cout << left << setw(20) << "Project Number: " << left << setw(10) << projectNum << endl;
    cout << left << setw(20) << "Due Date: " << left << setw(10) << dueDate << endl;
    return 0;
}
