void new_member()
{

    ofstream fin;
    // fin.open("D:\\vs code files\\c++ files\\text_files\\employees.txt", ios::app);
    string arr[4];
    cout << "Name:";
    getline(cin, arr[0]);
    cout<<"Your id is dd-mm-yyyy\n";
    cout << "Id:";
    cin >> arr[1];
    cout << "Department:";
    cin >> arr[2];
    cout << "Category (P/T):";
    cin >> arr[3];

    string filename;
    filename = "D:\\vs code files\\c++ files\\text_files\\";
    filename = filename + arr[2] +"\\"+arr[3]+ ".txt";
    fin.open(filename,ios::app);



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
    filename = "D:\\vs code files\\c++ files\\text_files\\";
    filename = filename + dept +"\\"+category+ ".txt";
    cout << filename << endl;
   
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
            fin <<str<<endl;
            pos_tellg=fin.tellg();
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
