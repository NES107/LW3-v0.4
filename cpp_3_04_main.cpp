#include "cpp_3_04_header.h"
#include "cpp_3_04_header.cpp"


int main()
{
vector <results> students;
results results;

int path;
cout<<"1 - manual mark input/random value generation"<<endl<<"2 - file output"<<endl<<"3 - file generation"<<endl;
cin>>path;
int path1;
if(path==1)
    {
        try
        {
            cout<<"1 - manual mark input"<<endl<<"2 - random value generation"<<endl;
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

                    else if(path1==2)random(&results);
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

    }
else if(path==2)
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
    }
else if(path==3)
{
    ofstream stud;
    stud.open("100_students.txt");
    stud<<endl<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<right<<"Final points (Avg.) / Final points (Med.)"<<endl;
    for(int i=0; i<82; i++)stud<<"-";
    stud<<endl;
    for(int i=1; i<=100; i++)
    {
        results.surname = "Surname";
        results.surname += to_string(i);
        results.name = "Name";
        results.name += to_string(i);
        random(&results);
        mean(&results);
        median(&results);
        results.hwm.resize(0);
        students.push_back(results);
        stud<<students[i].surname<<setw(22-students[i].surname.size())<<cout.fill(' ')<<right<<
        students[i].name<<setw(26-students[i].name.size())<<cout.fill(' ')<<right<<
        setprecision(2)<<students[i].fpointsa<<setw(18)<<cout.fill(' ')<<left<<
        setprecision(2)<<students[i].fpointsm<<endl;
    }
    stud.close();
}
else cout<<endl<<"Error in input. Only 'y' or 'n'!"<<endl;

output(students);

return 0;
}

