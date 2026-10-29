#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    string branch;
    float marks[5];
    float total;
    float per;
    char grade;
};

class School
{
    Student s[100];
    int n = 0;

public:
    int findStudent(int r)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i].roll == r)
            {
                return i;
            }
        }
        return -1;
    }

    void addStudent()
    {
        if (n == 100)
        {
            cout << "Student limit reached!\n";
            return;
        }

        int r;
        cout << "Enter roll number: ";
        cin >> r;

        if (r <= 0 || findStudent(r) != -1)
        {
            cout << "Invalid or already existing roll number!\n";
            return;
        }

        s[n].roll = r;

        cout << "Enter student name: ";
        cin >> ws;
        getline(cin, s[n].name);

        cout << "Enter branch: ";
        getline(cin, s[n].branch);

        for (int i = 0; i < 5; i++)
        {
            s[n].marks[i] = 0;
        }

        s[n].total = 0;
        s[n].per = 0;
        s[n].grade = 'N';

        n++;

        cout << "Student added successfully!\n";
    }

    void updateStudent()
    {
        int r;

        cout << "Enter roll number to update: ";
        cin >> r;

        int pos = findStudent(r);

        if (pos == -1)
        {
            cout << "Student not found!\n";
            return;
        }

        cout << "Enter new name: ";
        cin >> ws;
        getline(cin, s[pos].name);

        cout << "Enter new branch: ";
        getline(cin, s[pos].branch);

        cout << "Student details updated successfully!\n";
    }

    void searchStudent()
    {
        int r;

        cout << "Enter roll number: ";
        cin >> r;

        int pos = findStudent(r);

        if (pos == -1)
        {
            cout << "Student not found!\n";
            return;
        }

        cout << "\nRoll Number: " << s[pos].roll << endl;
        cout << "Name: " << s[pos].name << endl;
        cout << "Branch: " << s[pos].branch << endl;
        cout << "Percentage: " << s[pos].per << "%\n";
        cout << "Grade: " << s[pos].grade << endl;
    }

    void displayStudents()
    {
        if (n == 0)
        {
            cout << "No student records found!\n";
            return;
        }

        cout << "\n----- Student List -----\n";

        for (int i = 0; i < n; i++)
        {
            cout << "Roll: " << s[i].roll
                 << " | Name: " << s[i].name
                 << " | Branch: " << s[i].branch << endl;
        }
    }

    void enterMarks()
    {
        int r;

        cout << "Enter roll number: ";
        cin >> r;

        int pos = findStudent(r);

        if (pos == -1)
        {
            cout << "Student not found!\n";
            return;
        }

        s[pos].total = 0;

        cout << "Enter marks out of 100 for 5 subjects:\n";

        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> s[pos].marks[i];

            if (s[pos].marks[i] < 0 || s[pos].marks[i] > 100)
            {
                cout << "Invalid marks! Enter marks from 0 to 100.\n";
                i--;
                continue;
            }

            s[pos].total += s[pos].marks[i];
        }

        s[pos].per = s[pos].total / 5;

        if (s[pos].per >= 90)
            s[pos].grade = 'A';
        else if (s[pos].per >= 75)
            s[pos].grade = 'B';
        else if (s[pos].per >= 60)
            s[pos].grade = 'C';
        else if (s[pos].per >= 40)
            s[pos].grade = 'D';
        else
            s[pos].grade = 'F';

        cout << "Marks entered successfully!\n";
    }

    void resultReport()
    {
        int r;

        cout << "Enter roll number: ";
        cin >> r;

        int pos = findStudent(r);

        if (pos == -1)
        {
            cout << "Student not found!\n";
            return;
        }

        cout << "\n======= STUDENT RESULT =======\n";
        cout << "Roll Number: " << s[pos].roll << endl;
        cout << "Name: " << s[pos].name << endl;
        cout << "Branch: " << s[pos].branch << endl;

        cout << "\nSubject Marks:\n";

        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": "
                 << s[pos].marks[i] << "/100\n";
        }

        cout << "Total Marks: " << s[pos].total << "/500\n";
        cout << "Percentage: " << s[pos].per << "%\n";
        cout << "Grade: " << s[pos].grade << endl;

        if (s[pos].grade == 'N')
        {
            cout << "Result: Marks not entered yet\n";
        }
        else if (s[pos].grade == 'F')
        {
            cout << "Result: Fail\n";
        }
        else
        {
            cout << "Result: Pass\n";
        }

        cout << "==============================\n";
    }
};

int main()
{
    School sc;
    int ch;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student Details\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Enter Marks and Calculate Grade\n";
        cout << "6. Generate Result Report\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            sc.addStudent();
            break;

        case 2:
            sc.updateStudent();
            break;

        case 3:
            sc.searchStudent();
            break;

        case 4:
            sc.displayStudents();
            break;

        case 5:
            sc.enterMarks();
            break;

        case 6:
            sc.resultReport();
            break;

        case 0:
            cout << "Program closed successfully!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (ch != 0);

    return 0;
}