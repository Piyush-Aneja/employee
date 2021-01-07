#include <bits/stdc++.h>
using namespace std;
string get_filename(string dept, string category)
{
    string root_directory = "C:\\Users\\user\\Desktop\\oops_project\\";
    string filename = root_directory + dept + "\\" + category + ".txt";
    return filename;
}
void new_member()
    {
        string name,id,cat,dept;
        int salary,stipend;
        int attendance = 0;
        dept = "HR";
        cout << "Category (P- Employee/T-Temporary Employee): ";
        cin >> cat;
        if (cat.compare("P")==0)
        {
            cout << "Name: ";
            cin >> name;
            // cout << "Your id is dd-mm-yyyy\n";
            // cout << "Id: ";
            // cin >> id;

            // cout << "Salary:";
            // cin >> salary;
            string filename;

            // filename = get_filename(dept, cat);
            string root_directory = "C:\\Users\\user\\Desktop\\oops_project\\";
    filename = root_directory + dept + "\\" + cat + ".txt";
            cout<<filename<<endl;
            ofstream fin;
            fin.open(filename,ios::ate);
            if(fin.is_open())
            {
                cout<<"Entering\n";
            fin << name;
            }
            else
            {
                cout<<"no\n";
            }
            // <<"-"<< id <<"-"<< dept <<"-"<< cat <<"-"<< salary <<"-"<< attendance;
        }
        else
        {
            cout << "Name: ";
            getline(cin,name);
            cout << "Your id is dd-mm-yyyy\n";
            cout << "Id: ";
            cin >> id;

            cout << "Stipend allowed:";
            cin >> stipend;
            string filename;

            filename = get_filename(dept, cat);
            fin.open(filename, ios::app | ios::binary);
            fin << name << "-" << id << "-" << dept << "-" << cat << "-" << stipend << "-" << attendance;
        }

        fin << endl;
        fin.close();
    }

int main()
{
    new_member();
}
