#ifndef CPP_3_04_HEADER_H_INCLUDED
#define CPP_3_04_HEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string.h>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>

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
void output(vector <results> students);
void output1(vector <results> students);
bool sortname(const results &a, const results &b);
bool sortfm(const results &a, const results &b);

#endif // CPP_3_03_HEADER_H_INCLUDED
