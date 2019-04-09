#include "cpp_3_04_header.h"


void mmanualinput(struct results &resultss)
{   do
    {
        char choice2 ='y';
        try
        {
            while(choice2!='n')
            {
                do
                {
                    float hw;
                    try
                    {
                        cout<<"Enter HW mark "<<resultss.hwm.size()+1<<": ";
                        cin>>hw;
                        if(hw<=0 || hw>10)throw runtime_error("Error in input!hw[1,10]\n");
                        resultss.hwm.push_back (hw);
                    }catch(const runtime_error &e)
                        {
                            cout<<e.what();
                            cin.clear();
                            cin.ignore(256,'\n');
                            cout<<"Enter one more time"<<endl<<"-> ";
                            cin>>hw;
                        }
                }while(cin.fail()==true);

                cout<<"Add mark (y/n)?: ";
                cin>>choice2;
                if(choice2 !='y' && choice2 !='n')throw runtime_error("Error in input!(y/n)\n");
            }
        }catch(const runtime_error &e)
            {
                cout<<e.what();
                cin.clear();
                cin.ignore(256,'\n');
                cout<<"Enter one more time"<<endl<<"-> ";
                cin>>choice2;
            }
    }while(cin.fail()==true);
    do
    {
        try
        {
            cout<<"Enter EXAM mark: ";
            cin>>resultss.examm;
            if(resultss.examm<=0 || resultss.examm>10)throw runtime_error("Error in input! Exam[1,10]\n");
        }catch(const runtime_error &e)
            {
                cout<<e.what();
                cin.clear();
                cin.ignore(256,'\n');
                cout<<"Enter one more time"<<endl<<"-> ";
                cin>>resultss.examm;
            }
    }while(cin.fail()==true);
}
void random(struct results *resultss)
{
    int randd;
    for(int i=0;i<5;i++)
    {
        randd=rand()%10+1;
        resultss->hwm.push_back(randd);
    }
    resultss->examm = rand()%10+1;
}
void mean(struct results *resultss)
{
    resultss->average = accumulate(resultss->hwm.begin(),resultss->hwm.end(),0.0)/resultss->hwm.size();
    resultss->fpointsa = resultss->examm*0.6+resultss->average*0.4;
}
void median(struct results *resultss)
{
    if (resultss->hwm.size()%2!=0) resultss->fpointsm = 0.4*resultss->hwm[resultss->hwm.size()/2]+0.6*resultss->examm;
    else resultss->fpointsm = 0.4*((resultss->hwm[resultss->hwm.size()/2-1] + resultss->hwm[resultss->hwm.size()/2])/2)+0.6*resultss->examm;
}
void output(vector <results> students)
{
    cout<<endl<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<right<<"Final points (Avg.) / Final points (Med.)"<<endl;
    for(int i=0; i<82; i++)cout<<"-";
    cout<<endl;
    for(unsigned int i=0; i<students.size(); i++)
    {
        stringstream ss;
        ss<<students[i].fpointsa;
        cout<<students[i].surname<<setw(22-students[i].surname.size())<<cout.fill(' ')<<right<<
        students[i].name<<setw(26-students[i].name.size())<<cout.fill(' ')<<right<<
        setprecision(3)<<students[i].fpointsa<<setw(18-ss.str().size())<<cout.fill(' ')<<left<<
        setprecision(3)<<students[i].fpointsm<<endl;
    }
}
void output1(vector <results> students)
{
    cout<<endl<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<right<<"Final points (Avg.) / Final points (Med.)"<<endl;
    for(int i=0; i<82; i++)cout<<"-";
    cout<<endl;
    for(unsigned int i=0; i<students.size()-1; i++)
    {
        stringstream ss;
        ss<<students[i].fpointsa;
        cout<<students[i].surname<<setw(22-students[i].surname.size())<<cout.fill(' ')<<right<<
        students[i].name<<setw(26-students[i].name.size())<<cout.fill(' ')<<right<<
        setprecision(3)<<students[i].fpointsa<<setw(18-ss.str().size())<<cout.fill(' ')<<left<<
        setprecision(3)<<students[i].fpointsm<<endl;
    }
}
template <typename T>
    string to_string(const T &value) {
    stringstream ss;
    ss << value;
    return ss.str();
}
bool sortname(const results &a, const results &b)
{
    return a.surname < b.surname;
}
bool sortfm(const results &a, const results &b)
{
    return a.fpointsa > b.fpointsa;
}

void filegen(string fname,vector <results> &students,struct results resultss,int number)
{
    ofstream stud;
            stud.open(fname);
            stud<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<left
            <<"HW1"<<setw(2)<<cout.fill(' ')<<left<<"HW2"<<setw(2)<<cout.fill(' ')<<left
            <<"HW3"<<setw(2)<<cout.fill(' ')<<left<<"HW4"<<setw(2)<<cout.fill(' ')<<left
            <<"HW5"<<setw(2)<<cout.fill(' ')<<left<<"EXAM"<<setw(2)<<cout.fill(' ')<<left
            <<"Final points(Average / Median)"<<endl;
            for(int i=0; i<105; i++)stud<<"-";
            stud<<endl;
            for(int i=1; i<=number; i++)
            {
                resultss.surname = "Surname";
                resultss.surname +=to_string(i);
                resultss.name = "Name";
                resultss.name +=to_string(i);
                random(&resultss);
                mean(&resultss);
                median(&resultss);
                students.push_back(resultss);
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
                stud<<setw(6-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].examm;
                stringstream ss1;
                ss1<<students[i-1].fpointsa;
                stud<<setw(15-ss1.str().size())<<cout.fill(' ')<<left<<setprecision(3)<<students[i-1].fpointsa;
                stringstream ss2;
                ss2<<students[i-1].fpointsm;
                stud<<setw(15-ss2.str().size())<<cout.fill(' ')<<left<<setprecision(3)<<students[i-1].fpointsm<<endl;
                resultss.hwm.resize(0);
            }
            stud.close();
            sort(students.begin(),students.end(),sortfm);
}
int firstntp(vector <results> &students)
{
    int found;
    for(int i=students.size()-1; i>=0; i--)
    {
        if(students[i].fpointsa<5)
        {
            found=i;
        }
    }
    return found;
}


