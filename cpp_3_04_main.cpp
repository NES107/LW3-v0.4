#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

struct results
{
    string surname;
    string name;
    vector <float> hwm;
    float examm;
    float average;
    float fpointsa;
    float fpointsm;
};

void random(struct results *results);
void mean(struct results *results);
void median(struct results *results);

int main ()
{
    vector <results> students;
    results results;

    //ofstream stud;
    //stud.open("100_students.txt");
    FILE* write;
    write=fopen("100_students.txt","w");
    //stud<<endl<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<right<<"Final points (Avg.) / Final points (Med.)"<<endl;
    //for(int i=0; i<82; i++)stud<<"-";
    //stud<<endl;
    fprintf(write,"Surname%15sName%15sFinal points (Avg.) / Final points (Med.)\n","","");
    for(int i=0; i<82; i++)fprintf(write,"-");
    fprintf(write,"\n");
    for(int i=1; i<=100; i++)
    {
        //results.surname = "Surname";
        //results.surname += to_string (i);
        //results.name = "Name";
        //results.name += to_string (i);
        random(&results);
        mean(&results);
        median(&results);
        results.hwm.resize(0);
        students.push_back(results);
        //stud<<students[i].surname<<setw(22-students[i].surname.size())<<cout.fill(' ')<<right<<
        //students[i].name<<setw(26-students[i].name.size())<<cout.fill(' ')<<right<<
        //setprecision(2)<<students[i].fpointsa<<setw(18)<<cout.fill(' ')<<left<<
        //setprecision(2)<<students[i].fpointsm<<endl;
        //fprintf(write,"Surname%d  Name%d  %.2f %.2f\n",i,i,students[i].fpointsa,students[i].fpointsm);
        fprintf(write,"Surname%d\t\tName%d\t\t\t\t%d\n",i,i,students[i].examm);
    }
    //stud.close();
    fclose(write);
    system("pause");
    return 0;
}

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
