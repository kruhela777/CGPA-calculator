#include <iostream>
#include <conio.h>
#include <cstdlib> // for system("cls")

using namespace std;

// Function to calculate SGPA for a semester
double calculateSGPA()
{
    int NoOfSubs;
    cout << "Enter number of subjects for this semester: ";
    cin >> NoOfSubs;
    
    double* credits = new double[NoOfSubs]; // dynamic array allocation
    double* marks = new double[NoOfSubs];   // dynamic array allocation
    
    double totalPoints = 0;
    double totalCredits = 0;
    
    for (int i = 0; i < NoOfSubs; i++)
    {
        cout << "Enter credits for subject #" << i + 1 << ": ";
        cin >> credits[i];
        cout << "Enter marks for subject #" << i + 1 << ": ";
        cin >> marks[i];
        
        double gpa = (marks[i] / 10.0); // Assuming 100 marks = 10-point scale
        totalPoints += gpa * credits[i];
        totalCredits += credits[i];
    }
    
    double sgpa = totalPoints / totalCredits;
    
    delete[] credits; // free allocated memory
    delete[] marks;   // free allocated memory
    
    return sgpa;
}

void calculateCGPA()
{
    system("cls");
    cout << "------------------------------------------------" << endl;
    cout << "|                CGPA Calculator               |" << endl;
    cout << "------------------------------------------------" << endl;
    
    const int NoOfSems = 2; // Assuming CGPA is calculated for 2 semesters
    double semesters[NoOfSems];
    double semTotal = 0;
    
    // Getting SGPA for each semester
    for (int i = 0; i < NoOfSems; i++)
    {
        cout << "Calculating SGPA for Semester #" << i + 1 << endl;
        semesters[i] = calculateSGPA();
        cout << "SGPA for Semester #" << i + 1 << ": " << semesters[i] << endl;
    }
    
    // Summing up the SGPAs
    for (int i = 0; i < NoOfSems; i++)
    {
        semTotal += semesters[i];
    }
    
    // Calculating CGPA
    double cgpa = semTotal / NoOfSems;
    
    // Ensuring CGPA is above 8
    if (cgpa < 8.0) {
        cout << "Your CGPA is less than 8. Please enter valid marks to ensure CGPA is above 8." << endl;
    } else {
        cout << "Your CGPA: " << cgpa << endl;
    }
    
    cout << "\n Press any key to go back to Main Menu...";
    getch();
}

void instructions()
{
    system("cls");
    cout << endl << endl;
    cout << "How to Calculate SGPA and CGPA:" << endl;
    cout << "------------------------------" << endl << endl;
    cout << "SGPA = sum of (marks / 10 * credits) / total credits" << endl;
    cout << "CGPA = sum of SGPAs for all semesters / number of semesters" << endl;
    cout << "\nExample: If you have 2 semesters with SGPAs of 8.5 and 9.0 respectively, the CGPA is calculated as (8.5 + 9.0) / 2 = 8.75" << endl;
    cout << "\nNote: Ensure your CGPA is above 8 by entering appropriate marks for your subjects." << endl;
    cout << "\n Press any key to go back to Main Menu...";
    getch();
}

int main()
{
    do
    {
        system("cls");
        cout << "------------------------------------------------" << endl;
        cout << "|                CGPA Calculator               |" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. Calculate CGPA" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Quit" << endl << endl;
        cout << "Select Option: ";
        
        char op;
        cin >> op;
        
        if (op == '1') calculateCGPA();
        else if (op == '2') instructions();
        else if (op == '3') exit(0);
        
    } while (true);
    
    return 0;
}
