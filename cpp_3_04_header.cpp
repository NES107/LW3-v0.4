#include "cpp_3_04_header.h"

void random(struct results *results)
{
    int randd;
    for(int i=0;i<5;i++)
    {
        randd=rand()%10+1;
        results->hwm.push_back(randd);
    }
    results->examm = rand()%10+1;
}

void mean(struct results *results)
{
    results->average = accumulate(results->hwm.begin(),results->hwm.end(),0.0)/results->hwm.size();
    results->fpointsa = results->examm*0.6+results->average*0.4;
}

void median(struct results *results)
{
    if (results->hwm.size()%2!=0) results->fpointsm = 0.4*results->hwm[results->hwm.size()/2]+0.6*results->examm;
    else results->fpointsm = 0.4*((results->hwm[results->hwm.size()/2-1] + results->hwm[results->hwm.size()/2])/2)+0.6*results->examm;
}

void output(vector <results> students)
{
    cout<<endl<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<right<<"Final points (Avg.) / Final points (Med.)"<<endl;
    for(int i=0; i<82; i++)cout<<"-";
    cout<<endl;
    for(unsigned int i=0; i<students.size(); i++)
    {
        cout<<students[i].surname<<setw(22-students[i].surname.size())<<cout.fill(' ')<<right<<
        students[i].name<<setw(26-students[i].name.size())<<cout.fill(' ')<<right;
        printf("%.2f",students[i].fpointsa);
        cout<<setw(18)<<cout.fill(' ')<<left;
        printf("%.2f\n",students[i].fpointsm);
    }
}
