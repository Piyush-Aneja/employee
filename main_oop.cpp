#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>

using namespace std;
int c;
string empType;

string get_filename(string dept, string category)
{
    string root_directory = "C:\\Users\\user\\Desktop\\oops_project\\";
    string filename = root_directory + dept + "\\" + category + ".txt";
    return filename;
}

void getdata(string dept, string category)
{
    string filename;
    if (category == "P")
    {

        cout << dept << " Permanent employees are..!!!\n";
    }
    if (category == "T")
    {
        cout << dept << " Temporary employees are..!!!\n";
    }

    ifstream fin;
    // filename = "D:\\vs code files\\c++ files\\text_files\\" + dept + "\\" + Category + ".txt";
    filename = get_filename(dept, category);
    fin.open(filename, ios::binary);
    while (!fin.eof())
    {
        string str;
        getline(fin, str);
        stringstream ss(str);

        string token;
        string ar[] = {"Name->", "ID->", "Department->", "Category->"};
        int i = 0;
        while (getline(ss, token, '-'))
        {

            cout << ar[i++] << " " << token << '\n';
        }
        cout << "\n";
    }
    fin.close();
}

void new_member()
{

    ofstream fin;
    // fin.open("D:\\vs code files\\c++ files\\text_files\\employees.txt", ios::app);
    string arr[4];
    cout << "Name:";
    getline(cin, arr[0]);
    cout << "Your id is dd-mm-yyyy\n";
    cout << "Id:";
    cin >> arr[1];
    cout << "Department:";
    cin >> arr[2];
    cout << "Category (P-Permanent Employee/T-Temporary Employee):";
    cin >> arr[3];
    if(arr[3]=="P")
        cout<<"Salary:";


    string filename;
    // filename = "D:\\vs code files\\c++ files\\text_files\\";
    // filename = filename + arr[2] +"\\"+arr[3]+ ".txt";

    filename = get_filename(arr[2], arr[3]);
    fin.open(filename, ios::app | ios::binary);

    for (int i = 0; i < 4; i++)
    {
        fin << arr[i] << "-";
    }
    fin << endl;
    fin.close();
}

void take_attendance(string dept, string category)
{

    fstream fin;
    string filename;
    // filename = "D:\\vs code files\\c++ files\\text_files\\";
    // filename = filename + dept +"\\"+category+ ".txt";
    filename = get_filename(dept, category);
    // cout << filename << endl;

    fin.open(filename, ios::in | ios::out | ios::binary);
    char attendance;
    int cur_attendance, cur_attendance_update;

    string name, str;
    int pos_tellg;
    pos_tellg = fin.tellg();
    while (getline(fin, str))
    {
        // cout << str << endl;

        int cur_pos = fin.tellg();
        stringstream ss(str);
        getline(ss, name, '-');
        cout << name << " is present or absent:";
        cin >> attendance;
        if (attendance == 'Y')
        {
            int pos;
            int i;
            for (i = 0; i < str.length(); i++)
            {
                if (str[i] == '-')
                    pos = i;
            }
            string cur_attend = str.substr(pos + 1, i - pos - 1);

            cur_attendance = stoi(cur_attend);
            cur_attendance++;
            string cur_attendance_str = to_string(cur_attendance);
            str = str.replace(pos + 1, cur_attendance_str.length(), cur_attendance_str);
            // cout << str << endl;

            fin.seekg(pos_tellg, ios::beg);
            fin << str << endl;
            pos_tellg = fin.tellg();
            str = "";
            fin.clear();
            fin.seekg(pos_tellg);
        }
        else
        {
            continue;
        }
    }
    fin.close();
}
void display__all_employees()
{
    string dept[] = {"HR", "Tech", "Sales", "PR"};
    string cat[] = {"P", "T"};
    for (int i = 0; i < 4; i++)
    {
        cout << "Employees of " << dept[i] << " Department :-\n";
        for (int j = 0; j < 2; j++)
        {
            getdata(dept[i], cat[j]);
        }
    }
}

void tranfer_probie_to_permanent(string dept, string id)
{
    fstream fin, ofin;
    string filename = get_filename(dept, "T");
    fin.open(filename);
    ofin.open("C:\\Users\\user\\Desktop\\oops_project\\temp.txt"); //temporary file later we will rename to probie again after deleting person

    string str;
    while (fin)
    {
        // string str;
        int pos;
        getline(fin, str);
        if ((pos = str.find(id)) == -1)
        {
            ofin << str;
            // continue;
        }
        else
        {
            continue;
        }
    }
    fin.close();
    remove(filename.c_str());
    rename("C:\\Users\\user\\Desktop\\oops_project\\temp.txt", filename.c_str());
    fin.close();
    ofin.close();

    filename = get_filename(dept, "P");
    fin.open(filename, ios::app);
    fin >> str;
    fin.close();
}

void take_test(string dept)
{
    string filename, filename1, id;

    // filename = "D:\\vs code files\\c++ files\\text_files\\";
    // filename = filename + dept + "\\" + "question.txt";
    filename = get_filename(dept, "question");

    // filename1 = "D:\\vs code files\\c++ files\\text_files\\";
    // filename1 = filename1 + dept + "\\" + "ans.txt";

    filename1 = get_filename(dept, "ans");

    ifstream fin;
    fin.open(filename, ios::binary);
    ifstream ans_file;
    char ans;
    ans_file.open(filename1, ios::binary);

    int score = 0;
    cout << "You must score 4 or above to become a permanent employee...!!!\n";
    while (!fin.eof())
    {
        string ques;

        string mcq;
        getline(fin, ques);
        getline(fin, mcq);
        ans_file >> ans;
        char ch;
        char ans;
        fin >> ans; //choice
        cout << ques << "\n"
             << mcq << endl;

        cin >> ch;
        if (ch == ans)
        {
            score++;
        }
    }
    if (score >= 4)
    {
        cout << "Congratulations, You are selected..!!!\n";
        filename = get_filename(dept, "P");
        tranfer_probie_to_permanent(filename, id);
    }
    else
    {
        cout << "Sorry you didn't qualify the test..!!!\n";
        cout << "Your score is " << score << endl
             << "Better luck next time.\n";
    }
    fin.close();
    ans_file.close();
}

void display_item(string dept, string category, string id)
{
    string str;
    string filename = get_filename(dept, category);

    fstream fin;
    fin.open(filename, ios::binary);
    while (fin)
    {
        int pos;
        getline(fin, str);
        if ((pos = str.find(id)) == -1)
        {
            continue;
        }
        else //str has that person whose detail you want  to display(Add here subtr)
        {
        }
    }
    fin.close();
}

void search(string filename, string key)
{
}

// void displayOptions()
// {
//     cout << "1.TAKE ATTENDANCE\n2.SHOW ATTENDANCE\n3. SHOW PROBIE'S ASSESSMENT\n4. TAKE PROBIES ASSESSMENT\n";
// }

void employeeType()
{
    cout << "\nPress 'P' for Permanent employees\nPress 'T' for Probies\n";
}

class Permanent
{

protected:
    int id;
    string name;
    float salary;
    string dept;
};

class Probies
{
protected:
    int id;
    string name;
    float stipend;
    string dept;
};

class HR : public Probies, public Permanent
{
public:
    void Getdata(string cat)
    {
        if (cat == "P")
            getdata("HR", cat);
        if (cat == "T")
            getdata("HR", cat);
    }
    void Take_test()
    {
        take_test("HR");
    }
};

class Tech : public Probies, public Permanent
{
public:
    void Getdata(string cat)
    {
        if (cat == "P")
            getdata("Tech", cat);
        if (cat == "T")
            getdata("Tech", cat);
    }
    void Take_test()
    {
        take_test("Tech");
    }
};

class Sales : public Probies, public Permanent
{
public:
    void Getdata(string cat)
    {
        if (cat == "P")
            getdata("Sales", cat);
        if (cat == "T")
            getdata("Sales", cat);
    }
    void Take_test()
    {
        take_test("Sales");
    }
};

class PR : public Probies, public Permanent
{
public:
    void Getdata(string cat)
    {
        if (cat == "P")
            getdata("PR", cat);
        if (cat == "T")
            getdata("PR", cat);
    }
    void Take_test()
    {
        take_test("PR");
    }
};

class CEO : public HR, Tech, Sales, PR
{
public:
    void display()
    {
        string dept;
        cout << "Enter department name: ";
        cin >> dept;
        char ch = 'A';
        switch (ch)
        {
        case 'A':
        case 'P':
            if (dept == "HR")
                HR::Getdata(to_string(ch));
            if (dept == "Tech")
                Tech::Getdata(to_string(ch));
            if (dept == "Sales")
                Sales::Getdata(to_string(ch));
            if (dept == "PR")
                PR::Getdata(to_string(ch));
            break;
        case 'T':
            if (dept == "HR")
                HR::Getdata(to_string(ch));
            if (dept == "Tech")
                Tech::Getdata(to_string(ch));
            if (dept == "Sales")
                Sales::Getdata(to_string(ch));
            if (dept == "PR")
                PR::Getdata(to_string(ch));
        }
    }
};

void head_hr()
{
    HR head;
    cout << "1.TAKE ATTENDANCE\n2.SHOW ATTENDANCE\n3. TAKE PROBIES ASSESSMENT\n4. VIEW EMPLOYEES\n";
    cin >> c;
    if (c == 1)
    {
        employeeType();
        // cout << "Press 'A' for all employees under the dept\n"<<endl;
        cin >> empType;
        take_attendance("HR", empType);
    }
    if (c == 2)
    {
        employeeType();
        cin >> empType;
        // show_attendance("HR",empType);                //call to show attendance of all employees in SALES
    }
    if (c == 3)
    {
        head.Take_test();
    }
    if (c == 4)
    {
        head.Getdata("P");
        head.Getdata("T");
    }
}

void head_tech()
{
    Tech head;
    cout << "1.TAKE ATTENDANCE\n2.SHOW ATTENDANCE\n3. TAKE PROBIES ASSESSMENT\n4. VIEW EMPLOYEES\n";
    cin >> c;
    if (c == 1)
    {
        employeeType();
        // cout << "Press 'A' for all employees under the dept\n"<<endl;
        cin >> empType;
        take_attendance("Tech", empType);
    }
    if (c == 2)
    {
        employeeType();
        cin >> empType;
        // show_attendance("Tech",empType);                //call to show attendance of all employees in SALES
    }
    if (c == 3)
    {
        head.Take_test();
    }
    if (c == 4)
    {
        head.Getdata("P");
        head.Getdata("T");
    }
}

void head_sales()
{
    Sales head;
    cout << "1.TAKE ATTENDANCE\n2.SHOW ATTENDANCE\n3. TAKE PROBIES ASSESSMENT\n4. VIEW EMPLOYEES\n";
    cin >> c;
    if (c == 1)
    {
        employeeType();
        // cout << "Press 'A' for all employees under the dept\n"<<endl;
        cin >> empType;
        take_attendance("Sales", empType);
    }
    if (c == 2)
    {
        employeeType();
        cin >> empType;
        // show_attendance("Sales",empType);                //call to show attendance of all employees in SALES
    }
    if (c == 3)
    {
        head.Take_test();
    }
    if (c == 4)
    {
        head.Getdata("P");
        head.Getdata("T");
    }
}

void head_pr()
{
    PR head;
    cout << "1.TAKE ATTENDANCE\n2.SHOW ATTENDANCE\n3. TAKE PROBIES ASSESSMENT\n4. VIEW EMPLOYEES\n";
    cin >> c;
    if (c == 1)
    {
        employeeType();
        // cout << "Press 'A' for all employees under the dept\n"<<endl;
        cin >> empType;
        take_attendance("PR", empType);
    }
    if (c == 2)
    {
        employeeType();
        cin >> empType;
        // show_attendance("PR",empType);                //call to show attendance of all employees in SALES
    }
    if (c == 3)
    {
        head.Take_test();
    }
    if (c == 4)
    {
        head.Getdata("P");
        head.Getdata("T");
    }
}
void showDept()
{
    cout << "\n A) HR HEAD\n B) SALES HEAD\n C) PUBLIC RELATIONS HEAD\n D) TECHNICAL HEAD\n Press \'*\' to goto last menu\n";
}

// name id dept(HR, TECH, SALES, PR) category(P/p)

int main()
{
    int a, k1, k, k2, deptSelect;
    char ch;
    string empName, empID;
    cout << "WELCOME TO EMPLOYEE MANAGEMENT SYSTEM\n\n"
         << endl;
AGAIN:
    cout << "1. EMPLOYER\n2. EMPLOYEE\n3. PROBIES\n"
         << endl;
    cin >> a;
    switch (a)
    {
        prev1:
    case 1: //this section is for HEADS
        cout << "Choose from the following:\n A) CEO\n B) HR HEAD\n C) TECHNICAL HEAD\n D) SALES HEAD\n E) PUBLIC RELATIONS HEAD\n Press \'*\' to go to last menu\n";
        cin >> ch;
        switch (ch)
        {
        case 'A': //CEO
            prev2:
            cout << "Choose the type of data to be retrieved\n1.VIEW EMPLOYEE(S)\n2.TOTAL EXPENDITURE ON WORKFORCE\n\nPress \'0\' to go to last menu\n\n";
            cin >> k;
            switch (k1)
            {
            case 1:
                cout << "1.VIEW ALL EMPLOYEES\n2.VIEW BY SPECIFIC DEPT.\n";
                cin >> k;
                if (k2 == 1)
                {
                    display__all_employees();
                }
                else
                {
                    CEO obj;
                    obj.display();
                }
                goto prev2;
                break;
            case 2: //expenditure retrieval
                goto prev2;
                break;
            case 0:
                goto prev1;
                break;
            }
            goto prev1;
            break;

        case 'B':
            head_hr();
            goto prev1;
            break;

        case 'C':
            head_tech();
            goto prev1;
            break;

        case 'D':
            head_sales();
            goto prev1;
            break;

        case 'E':
            head_pr();
            goto prev1;
            break;
        case '*':
            goto AGAIN;
        }
        break;
    prev3:
    case 2: //this section for EMPLOYEES to check their attendance
        cout << "Enter from the following departments to check your attendance\n", showDept();
        cin >> deptSelect; // this is char
        switch (deptSelect)
        {
        case 'A': //HR
            cout << "\nenter your name:";
            cin >> empName; //string type
            cout << "\nenter your employee ID:";
            cin >> empID; //string type
            goto prev3;
            break;
        case 'B': //sales
            cout << "\nEnter your name:";
            cin >> empName; //string type
            cout << "\nEnter your employee ID:";
            cin >> empID; //string type
            goto prev3;
            break;

        case 'C': //PR
            cout << "\nenter your name:";
            cin >> empName; //string type
            cout << "\nenter your employee ID:";
            cin >> empID; //string type
            goto prev3;
            break;

        case 'D': //technical
            cout << "\nenter your name:";
            cin >> empName; //string type
            cout << "\nenter your employee ID:";
            cin >> empID; //string type
            goto prev3;
            break;
        case '*':
            goto prev2;

        }
        break;
    prev4:
    case 3: //this section is for probies to show their assessment
        cout << "Enter from the following departments to check your assessment\n", showDept();
        cin >> deptSelect; // this is char
        switch (deptSelect)
        {
        case 'A': //HR probie
            cout << "\nenter your name:";
            cin >> empName; //string type
            cout << "\nenter your probies ID:";
            cin >> empID; //string type
            goto prev4;
            break;
        case 'B': //sales probie
            cout << "\nEnter your name:";
            cin >> empName; //string type
            cout << "\nEnter your probies ID:";
            cin >> empID; //string type
            goto prev4;
            break;

        case 'C': //PR probie
            cout << "\nEnter your name:";
            cin >> empName; //string type
            cout << "\nEnter your probies ID:";
            cin >> empID; //string type
            goto prev4;
            break;

        case 'D': //technical probie
            cout << "\nenter your name:";
            cin >> empName; //string type
            cout << "\nenter your probies ID:";
            cin >> empID; //string type
            goto prev4;
            break;
        case '*':
            goto prev3;
        }
        break;

    default:
        int runDecision;
        cout << "Enter 1 to Re-enter or,\nEnter 0 to exit\n";
        cin >> runDecision;
        if (runDecision == 1)
        {
            goto AGAIN;
        }
        else
            exit(0);
    }
    return 0;
}
