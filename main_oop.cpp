#include <bits/stdc++.h>

using namespace std;

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
    filename = "D:\\vs code files\\c++ files\\text_files\\" + dept + "\\" + Category + ".txt";
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
    friend class CEO;
};

class Tech : public Probies, public Permanent
{
    void Getdata(string dept, char cat)
    {
        getdata(dept, cat);
    }

    friend class CEO;
};

class Sales : public Probies, public Permanent
{
    void Getdata(string dept, char cat)
    {
        getdata(dept, cat);
    }
    friend class CEO;
};

class PR : public Probies, public Permanent
{
    void Getdata(string dept, char cat)
    {
        getdata(dept, cat);
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

void question(string dept)
{
    string filename, filename1;
    filename = "D:\\vs code files\\c++ files\\text_files\\";
    filename = filename + dept + "\\" + "question.txt";

    filename1 = "D:\\vs code files\\c++ files\\text_files\\";
    filename1 = filename1 + dept + "\\" + "ans.txt";

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
    }
    else
    {
        cout << "Sorry you didn't qualify the test..!!!\n";
        cout << "Your score is " << score << endl
             << "Better luck next time.\n";
    }
}
