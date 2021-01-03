#include <bits/stdc++.h>

using namespace std;

string get_filename(string dept, string category)
{
    string root_directory = "D:\\vs code files\\c++ files\\text_files\\";
    string filename = root_directory + dept + "\\" + category + ".txt";
    return (filename);
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
    cout << "Category (P/T):";
    cin >> arr[3];

    string filename;
    // filename = "D:\\vs code files\\c++ files\\text_files\\";
    // filename = filename + arr[2] +"\\"+arr[3]+ ".txt";

    filename = get_filename(arr[2], arr[3]);
    fin.open(filename, ios::app);

    for (int i = 0; i < 4; i++)
    {
        fin << arr[i] << "-";
    }
    fin << endl;
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
    int cur_attendace, cur_attendace_update;

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

            cur_attendace = stoi(cur_attend);
            cur_attendace_update = cur_attendace;
            cur_attendace_update++;
            string cur_attendace_str = to_string(cur_attendace);
            str = str.replace(pos + 1, cur_attendace_str.length(), to_string(cur_attendace_update));
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
}
void display__all_employees()
{
    ifstream fin;
    fin.open("D:\\vs code files\\c++ files\\text_files\\employees.txt");
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
}

void tranfer_probie_to_permanent(string filename, string id)
{
    fstream fin, ofin;
    fin.open(filename);
    ofin.open("D:\\vs code files\\c++ files\\text_files\\temp.txt"); //temporary file later we will rename to probie again after deleting person

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
    remove(filename);
    rename("D:\\vs code files\\c++ files\\text_files\\temp.txt", filename);
    fin.close();
    ofin.close();

    filename=get_filename(dept,"P");
    fin.open(filename,ios::app);
    fin>>str;
    fin.close();


}

void getdata(string dept, char category)
{
    string Category, filename;
    if (category == 'P')
    {
        Category = "P";
        cout << dept << " Permanent employees are..!!!\n";
    }
    else
    {
        Category = "T";
        cout << dept << " Temporary employees are..!!!\n";
    }

    ifstream fin;
    // filename = "D:\\vs code files\\c++ files\\text_files\\" + dept + "\\" + Category + ".txt";
    filename = get_filename(dept, Category);
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
}
void take_test(string dept)
{
    string filename, filename1;

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
        filename=get_filename(dept,"P");
        tranfer_probie_to_permanent(string filename,string id);
    }
    else
    {
        cout << "Sorry you didn't qualify the test..!!!\n";
        cout << "Your score is " << score << endl
             << "Better luck next time.\n";
    }
}

void display_item(string dept, string category,string id)
{
    string filename = get_filename(dept, category);

    fstream fin;
    fin.open(filename, ios::binary);
    while (fin)
    {
        int pos;
        getline(fin, str);
        if ((pos = str.find(id)) == -1)
        {
            continue();
          
        }
        else //str has that person whose detail you want  to display(Add here subtr)
        {
           
        }
    }
    fin.close();
}

void search(string filename,string key)
{

}

class Permanent
{

protected:
    int id;
    string name;
    float salary;
};

class Probies
{
    int id;
    string name;
    float stipend;
};

class HR : public Probies, public Permanent
{
    void Getdata(string dept, char cat)
    {
        getdata(dept, cat);
    }
    void Take_test(string dept)
    {
        take_test(dept);
    }

    friend class CEO;
};

class Tech : public Probies, public Permanent
{
    void Getdata(string dept, char cat)
    {
        getdata(dept, cat);
    }
    void Take_test(string dept)
    {
        take_test(dept);
    }

    friend class CEO;
};

class Sales : public Probies, public Permanent
{
    void Getdata(string dept, char cat)
    {
        getdata(dept, cat);
    }
    void Take_test(string dept)
    {
        take_test(dept);
    }
    friend class CEO;
};

class PR : public Probies, public Permanent
{
    void Getdata(string dept, char cat)
    {
        getdata(dept, cat);
    }
    void Take_test(string dept)
    {
        take_test(dept);
    }
    friend class CEO;
};

class CEO
{
    void display(HR &a, Tech &b, Sales &c, PR &d)
    {
        a.Getdata();
        b.Getdata();
        c.Getdata();
        d.Getdata();
    }
};

// name id dept(HR, TECH, SALES, PR) category(P/p)

int main()
{

    return 0;
}
