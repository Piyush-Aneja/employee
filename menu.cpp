#include <iostream>
using namespace std;
int c;
char empType;
void displayOptions()
{
    cout << "1.TAKE ATTENDANCE\n2.SHOW ATTENDANCE\n3. SHOW PROBIE'S ASSESSMENT";
    //cout<<"enter 'P' for permanent employee(s)\n enter 'p' probies\n");
}

void employeeType()
{
    cout << "\nPress 'P' for Permanent employees\nPress 'p' for Probies\nPress 'A' for all employees under the dept\n"
         << endl;
}

void head_sales()
{
    displayOptions();
    cin >> c;
    if (c == 1)
    {
        employeeType();
        cin >> empType;
        // if (empType == 'P')          // take attendance of permanent employee
            // else if (empType == 'p') //take attendance of Probies
            //     else                 //call to take attendance of all employees in SALES
    }
    else if (c == 2)
    {
        employeeType();
        cin >> empType;
        // if (empType == 'P')          // show attendance of permanent employee
        //     else if (empType == 'p') //show attendance of Probies
        //         else                 //call to show attendance of all employees in SALES
    }
    else
    {
        //here goes the assessment of probies of SALES dept
    }
}

void head_pr()
{
    displayOptions();
    cin >> c;
    if (c == 1)
    {
        employeeType();
        cin >> empType;
        // if (empType == 'P')          // take attendance of permanent employee
        //     else if (empType == 'p') //take attendance of Probies
        //         else                 //call to take attendance of all employees in PR
    }
    else if (c == 2)
    {
        employeeType();
        cin >> empType;
        // if (empType == 'P')          // show attendance of permanent employee
        //     else if (empType == 'p') //show attendance of Probies
        //         else                 //call to show attendance of all employees in PR
    }
    else
    {
        //here goes the assessment of probies of PR dept
    }
}

void head_tech()
{
    displayOptions();
    cin >> c;
    if (c == 1)
    {
        employeeType();
        cin >> empType;
        // if (empType == 'P')          // take attendance of permanent employee
        //     else if (empType == 'p') //take attendance of Probies
        //         else                 //call to take attendance of all employees in TECH
    }
    else if (c == 2)
    {
        employeeType();
        cin >> empType;
        // if (empType == 'P')          // show attendance of permanent employee
        //     else if (empType == 'p') //show attendance of Probies
        //         else                 //call to show attendance of all employees in TECH
    }
    else
    {
        //here goes the assessment of probies of TECH dept
    }
}

void head_hr()
{
    displayOptions();
    cin >> c;
    if (c == 1)
    {
        employeeType();
        cin >> empType;
        // if (empType == 'P')          // take attendance of permanent employee
        //     else if (empType == 'p') //take attendance of Probies
        //         else                 //call to take attendance of all employees in HR
    }
    else if (c == 2)
    {
        employeeType();
        cin >> empType;
        // if (empType == 'P')          // show attendance of permanent employee
        //     else if (empType == 'p') //show attendance of Probies
        //         else                 //call to show attendance of all employees in HR
    }
    else
    {
        //here goes the assessment of probies of HR dept
    }
}

void showDept()
{
    cout<<"choose from the following:\n B) SALES HEAD\n C) PUBLIC RELATIONS HEAD\n D) TECHNICAL HEAD\n E) HR HEAD\n";
}
int main()
{
    int a, k1, k, k2, deptSelect;
    char ch;
    cout << "%-15WELCOME TO EMPLOYEE MANAGEMENT SYSTEM\n\n"
         << endl;
    cout << "press 1 for EMPLOYER\npress 2 for EMPLOYEE\npress 3 for PROBIES\n"
         << endl;
    cin >> a;
    switch (a)
    {
    case 1: //this section is for HEADS
        cout<<"choose from the following:\n A) CEO\n B) SALES HEAD\n C) PUBLIC RELATIONS HEAD\n D) TECHNICAL HEAD\n E) HR HEAD\n";
        cin >> ch;
        switch (ch)
        {
        case 'A': //CEO
            cout<<"choose the type of data to be retrieved\n1.VIEW EMPLOYEE(S)\n2.TOTAL EXPENDITURE ON WORKFORCE\n\n";
            cin >> k;
            switch (k1)
            {
            case 1:
                cout<<"1.VIEW ALL EMPLOYEES\n2.VIEW BY SPECIFIC DEPT.\n";
                    cin>>k;
                if (k2 == 1)
                {
                    //retrieve all names from all files
                }
                else
                {
                    /* enter the department from where data is to be received */
                }
                break;
            case 2: //expenditure retrieval
            }

        case 'B':
            head_sales();
            break;

        case 'C':
            head_pr();
            break;

        case 'D':
            head_tech();
            break;

        case 'E':
            head_hr();
        }
        break;

    case 2: //this section for EMPLOYEES to check their attendance
        showDept();
        cin >> deptSelect; // this is char
        switch (deptSelect)
        {
        case 'B': //sales

            break;

        case 'C': //PR

            break;

        case 'D': //technical

            break;

        case 'E': //HR
        }
        break;

    case 3: //this section is for probies to show their assessment
    }
}
