#include "cpp_3_04_header.h"
#include "cpp_3_04_header.cpp"


int main()
{
    vector <results> students;
    results resultss;

    cout<<"1 - manual mark input/random value generation"<<endl<<"2 - file output"<<endl<<"3 - file generation"<<endl<<"-> ";
    int path;
    cin>>path;
    while(path !=1 && path !=2 && path !=3)
        {
            try
            {
                throw runtime_error("Error in input!(1,2,3)");
            }catch(const runtime_error &e)
            {
                cout<<e.what();
                cin.ignore(256,'\n');
                cout<<"Enter one more time:"<<endl<<"-> ";
                cin>>path;
            }
        }
    if(path==1)         //Manual input
    {
        int path1;
        char choice1='y';
        cout<<"1 - manual mark input"<<endl<<"2 - random value generation"<<endl<<"-> ";
        cin>>path1;
        while(path1!=1 && path1!=2)
            {
                try
                {
                    throw runtime_error("Error in input!(1,2)\n");
                }catch(const runtime_error &e)
                {
                    cout<<e.what();
                    cin.ignore(256,'\n');
                    cout<<"Enter one more time:"<<endl<<"-> ";
                    cin>>path1;
                }
            }
        while(choice1!='n')
        {
            cout<<"Enter surname: ";
            cin>>resultss.surname;
            cout<<"Enter name: ";
            cin>>resultss.name;

            if(path1==1)
            {
                mmanualinput(resultss);
            }
            else if(path1==2)random(&resultss);                      //random mark generation

            mean(&resultss);
            median(&resultss);
            resultss.hwm.resize(0);
            students.push_back (resultss);
            cout<<"Add student "<<students.size()+1<<"(y/n)?: ";
            cin>>choice1;
            while(choice1 !='y' && choice1 !='n')
            {
                try
                {
                    throw runtime_error("Error in input!(y/n)\n");
                }catch(const runtime_error &e)
                {
                    cout<<e.what();
                    cin.ignore(256,'\n');
                    cout<<"Enter one more time:"<<endl<<"-> ";
                    cin>>choice1;
                }
            }
        }
        sort(students.begin(),students.end(),sortname);
        output(students);
    }
    else if(path==2)    //Reading from a file
    {
        readff(students, resultss);
    }
    else if(path==3)    //File Generation
    {
        cout<<"1 - 100 students"<<endl<<"2 - 1000 students"<<endl
        <<"3 - 10000 students"<<endl<<"4 - 100000 students"<<endl<<"-> ";
        int path2;
        cin>>path2;
        if(path2==1)    //100 students
        {
            string fname1 = "100_students.txt";
            string fname2 = "100_students_passed.txt";
            string fname3 = "100_students_notpassed.txt";
            int number = 100;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        else if(path2==2)   //1000 students
        {
            string fname1 = "1000_students.txt";
            string fname2 = "1000_students_passed.txt";
            string fname3 = "1000_students_notpassed.txt";
            int number = 1000;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        else if(path2==3)    //10000 students
        {
            string fname1 = "10000_students.txt";
            string fname2 = "10000_students_passed.txt";
            string fname3 = "10000_students_notpassed.txt";
            int number = 10000;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        else if(path2==4)    //100000 students
        {
            string fname1 = "100000_students.txt";
            string fname2 = "100000_students_passed.txt";
            string fname3 = "100000_students_notpassed.txt";
            int number = 100000;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        while(path2 !=1 && path2 !=2 && path2 !=3 && path2 !=4)
        {
            try
            {
                throw runtime_error("Error in input!(1,2,3,4)");
            }catch(const runtime_error &e)
            {
                cout<<e.what();
                cin.ignore(256,'\n');
                cout<<"Enter one more time:"<<endl<<"-> ";
                cin>>path2;
            }
        }
    }
    return 0;
}

