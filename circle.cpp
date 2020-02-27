#include "circle.h"


double Vidurkis(std::vector<int> v, std::vector<Studentas> Stud, int i)
{
    int b=0;
    for (int j=0; j<v.size(); j++)
        b+=v[j];

    return (double)(b/v.size())*0.4+Stud[i].egzas*0.6;
}

double Mediana(std::vector<int> v, std::vector<Studentas> Stud, int i)
{
    v.push_back(Stud[i].egzas);
    for (int a=0; a<v.size()-1; a++)
        for (int b=a+1; b<v.size(); b++)
            if (v[a]>v[b])
                std::swap (v[a], v[b]);

    if (v.size()%2!=0)
        return v[v.size()/2];
    else
        return (double)(v[v.size()/2-1]+v[v.size()/2])/2;
}

void Test(double &t1)
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Iveskite is naujo: ";
    std::cin >> t1;
}
