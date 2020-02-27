#ifndef V0_3_H_INCLUDED
#define V0_3_H_INCLUDED

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>

struct Studentas{
    std::string vardas;
    std::string pav;
    int egzas;
    double vid=0;
    double med=0;
};
double Vidurkis(std::vector<int> v, std::vector<Studentas> Stud, int i);
double Mediana(std::vector<int> v, std::vector<Studentas> Stud, int i);
void Test(double &t1);

#endif
