#include "cpp_3_04_header.h"
#include "cpp_3_04_header.cpp"


int main()
{
vector <results> students;
results results;

int path;
cout<<"1 - manual mark input/random value generation"<<endl<<"2 - file output"<<endl<<"3 - file generation"<<endl<<"-> ";
cin>>path;
int path1;
if(path==1)     //Manual input
    {
        try
        {
            cout<<"1 - manual mark input"<<endl<<"2 - random value generation"<<endl<<"-> ";
            cin>>path1;

            char choice1='y';
            while(choice1!='n')
                {
                    cout<<"Enter surname: ";
                    cin>>results.surname;
                    cout<<"Enter name: ";
                    cin>>results.name;
                    if(path1==1)
                    {
                        try
                        {
                            char choice2 ='y';
                            while(choice2!='n')
                            {
                                float hw;
                                cout<<"Enter HW mark "<<results.hwm.size()+1<<": ";
                                cin>>hw;
                                results.hwm.push_back (hw);
                                cout<<"Add mark (y/n)?: ";
                                cin>>choice2;
                                if(choice2 !='y' && choice2 !='n')throw 0;
                            }

                        }catch(int x)
                            {
                                cout<<endl<<"Error in input. Only 'y' or 'n'!"<<endl;
                            }
                            cout<<"Enter EXAM mark: ";
                            cin>>results.examm;
                            cout<<endl;
                        }

                    else if(path1==2)random(&results);                      //random mark generation
                    else cout<<"Error in input. Only '1' or '2'!"<<endl;

                    mean(&results);
                    median(&results);
                    results.hwm.resize(0);
                    students.push_back (results);
                    cout<<"Add student "<<students.size()+1<<"(y/n)?: ";
                    cin>>choice1;
                    if(choice1 !='y' && choice1 !='n')throw 0;
                }
        }catch(int x)
            {
                cout<<endl<<"Error in input. Only 'y' or 'n'!"<<endl;
            }
        output(students);
    }
else if(path==2)    //Reading from a file
    {
        ifstream student_list;
        student_list.open("student_list.txt");
        if(!student_list.is_open())
        {
            cerr<<"Error Opening File"<<endl;
            exit(EXIT_FAILURE);
        }
        student_list.ignore( 1000, '\n' );
        while(!student_list.eof())
        {
            student_list>>results.surname;
            student_list>>results.name;
            for(int i=0; i<5; i++)
            {
                float mark;
                student_list>>mark;
                results.hwm.push_back(mark);
            }
        student_list>>results.examm;
        mean(&results);
        median(&results);
        results.hwm.resize(0);
        students.push_back (results);
        }
    student_list.close();
    output(students);
    }
else if(path==3)    //File Generation
{
    try
    {
        int path3;
        cout<<"1 - 100 students"<<endl<<"2 - 1000 students"<<endl<<"3 - 10000 students"<<endl<<"4 - 100000 students"<<endl<<"-> ";
        cin>>path3;
        if(path3==1)    //100 students
        {
            ofstream stud;
            stud.open("100_students.txt");
            stud<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<left
            <<"HW1"<<setw(2)<<cout.fill(' ')<<left<<"HW2"<<setw(2)<<cout.fill(' ')<<left
            <<"HW3"<<setw(2)<<cout.fill(' ')<<left<<"HW4"<<setw(2)<<cout.fill(' ')<<left
            <<"HW5"<<setw(2)<<cout.fill(' ')<<left<<"EXAM"<<endl;
            for(int i=0; i<70; i++)stud<<"-";
            stud<<endl;
            for(int i=1; i<=100; i++)
            {
                results.surname = "Surname";
                results.surname +=to_string(i);
                results.name = "Name";
                results.name +=to_string(i);
                random(&results);
                mean(&results);
                median(&results);
                students.push_back(results);
                stud<<students[i-1].surname
                <<setw(22-students[i-1].surname.size())<<cout.fill(' ')<<left<<students[i-1].name
                <<setw(16-students[i-1].name.size())<<cout.fill(' ')<<right;
                for(int p=0;p<5;p++)
                {
                    stringstream ss;
                    ss<<students[i-1].hwm[p];
                    stud<<setw(5-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].hwm[p];
                }
                stringstream ss;
                ss<<students[i-1].examm;
                stud<<setw(6-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].examm<<endl;
                results.hwm.resize(0);
            }
            stud.close();
        }
        else if(path3==2)   //1000 students
        {
            ofstream stud;
            stud.open("1000_students.txt");
            stud<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<left
            <<"HW1"<<setw(2)<<cout.fill(' ')<<left<<"HW2"<<setw(2)<<cout.fill(' ')<<left
            <<"HW3"<<setw(2)<<cout.fill(' ')<<left<<"HW4"<<setw(2)<<cout.fill(' ')<<left
            <<"HW5"<<setw(2)<<cout.fill(' ')<<left<<"EXAM"<<endl;
            for(int i=0; i<70; i++)stud<<"-";
            stud<<endl;
            for(int i=1; i<=1000; i++)
            {
                results.surname = "Surname";
                results.surname +=to_string(i);
                results.name = "Name";
                results.name +=to_string(i);
                random(&results);
                mean(&results);
                median(&results);
                students.push_back(results);
                stud<<students[i-1].surname
                <<setw(22-students[i-1].surname.size())<<cout.fill(' ')<<left<<students[i-1].name
                <<setw(16-students[i-1].name.size())<<cout.fill(' ')<<right;
                for(int p=0;p<5;p++)
                {
                    stringstream ss;
                    ss<<students[i-1].hwm[p];
                    stud<<setw(5-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].hwm[p];
                }
                stringstream ss;
                ss<<students[i-1].examm;
                stud<<setw(6-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].examm<<endl;
                results.hwm.resize(0);
            }
            stud.close();
        }
        if(path3==3)    //10000 students
        {
            ofstream stud;
            stud.open("10000_students.txt");
            stud<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<left
            <<"HW1"<<setw(2)<<cout.fill(' ')<<left<<"HW2"<<setw(2)<<cout.fill(' ')<<left
            <<"HW3"<<setw(2)<<cout.fill(' ')<<left<<"HW4"<<setw(2)<<cout.fill(' ')<<left
            <<"HW5"<<setw(2)<<cout.fill(' ')<<left<<"EXAM"<<endl;
            for(int i=0; i<70; i++)stud<<"-";
            stud<<endl;
            for(int i=1; i<=10000; i++)
            {
                results.surname = "Surname";
                results.surname +=to_string(i);
                results.name = "Name";
                results.name +=to_string(i);
                random(&results);
                mean(&results);
                median(&results);
                students.push_back(results);
                stud<<students[i-1].surname
                <<setw(22-students[i-1].surname.size())<<cout.fill(' ')<<left<<students[i-1].name
                <<setw(16-students[i-1].name.size())<<cout.fill(' ')<<right;
                for(int p=0;p<5;p++)
                {
                    stringstream ss;
                    ss<<students[i-1].hwm[p];
                    stud<<setw(5-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].hwm[p];
                }
                stringstream ss;
                ss<<students[i-1].examm;
                stud<<setw(6-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].examm<<endl;
                results.hwm.resize(0);
            }
            stud.close();
        }
        if(path3==4)    //100000 students
        {
            ofstream stud;
            stud.open("100000_students.txt");
            stud<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<left
            <<"HW1"<<setw(2)<<cout.fill(' ')<<left<<"HW2"<<setw(2)<<cout.fill(' ')<<left
            <<"HW3"<<setw(2)<<cout.fill(' ')<<left<<"HW4"<<setw(2)<<cout.fill(' ')<<left
            <<"HW5"<<setw(2)<<cout.fill(' ')<<left<<"EXAM"<<endl;
            for(int i=0; i<70; i++)stud<<"-";
            stud<<endl;
            for(int i=1; i<=100000; i++)
            {
                results.surname = "Surname";
                results.surname +=to_string(i);
                results.name = "Name";
                results.name +=to_string(i);
                random(&results);
                mean(&results);
                median(&results);
                students.push_back(results);
                stud<<students[i-1].surname
                <<setw(22-students[i-1].surname.size())<<cout.fill(' ')<<left<<students[i-1].name
                <<setw(16-students[i-1].name.size())<<cout.fill(' ')<<right;
                for(int p=0;p<5;p++)
                {
                    stringstream ss;
                    ss<<students[i-1].hwm[p];
                    stud<<setw(5-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].hwm[p];
                }
                stringstream ss;
                ss<<students[i-1].examm;
                stud<<setw(6-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].examm<<endl;
                results.hwm.resize(0);

            }
            stud.close();
        }
        else if(path3 !=1 && path3 !=2 && path3 !=3 && path3 !=4) throw 1;
    }catch(int x)
        {
            cout<<"Error in input!(1,2,3,4)"<<endl;
        }
}
else cout<<endl<<"Error in input. Only 'y' or 'n'!"<<endl;
return 0;
}

