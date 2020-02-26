#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <cstdio>
#include <string>

struct Studentas{
    std::string vardas;
    std::string pav;
    int egzas;
    double vid=0;
    double med=0;
};

int main()
{
    int k, s, egzas, b, t;
    double vid, med, k1, s1, egzas1, t1;
    std::cout << "Ar norite duoneis nuskaityti is failo? Taip - 1; Ne - 2 ";
    std::cin >> t1;
    while(std::cin.fail() || t1==0 || t1 !=(int)t1 || (t1!=1 && t1!=2))
    {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Iveskite is naujo: ";
            std::cin >> t1;
    }
    t=(int)t1;

    if (t==2)
    {
        std::cout << "Iveskite studentu kieki: ";
        std::cin >> k1;

        while(std::cin.fail() || k1==0 || k1 !=(int)k1)
        {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Iveskite is naujo: ";
                std::cin >> k1;
        }
        k=(int)k1;
        Studentas Stud[k];
        std::vector<int> v;
        for (int i=0; i<k; i++)
        {
            std::vector<int> v;
            b=0;
            std::cout << "Iveskite studento varda ir pavarde: ";
            std::cin >> Stud[i].vardas >> Stud[i].pav;
            std::cout << "Ar norite kad balai butu atsitiktinai generuojami? Taip - 1 ; Ne - 2 ";
            std::cin >> s1;
            while(std::cin.fail() || s1==0 || s1 !=(int)s1 || (s1!=1 && s1!=2))
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Iveskite is naujo: ";
                std::cin >> s1;
            }
            s=(int)s1;
            if (s==2)
            {
                std::cout << "Iveskite egzamino rezultata: ";
                std::cin >> egzas1;
                while(std::cin.fail() || egzas1==0 || egzas1 !=(int)egzas1)
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Iveskite is naujo: ";
                    std::cin >> egzas1;
                }
                egzas=(int)egzas1;
                Stud[i].egzas=egzas;
                std::cout << "Iveskite namu darbu rezultatus (jei nebenoresite vesti rezultatu, iveskite skaiciu 11): ";
                go: while (true)
                {
                    std::cin >> s1;
                    while((std::cin.fail() && s1>=0 && s1<10)|| s1==0 || s1 !=(int)s1)
                    {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Iveskite is naujo: ";
                        std::cin >> s1;
                    }
                    s=(int)s1;
                    if (s>=0 && s<=10)
                    {
                        v.push_back(s);
                    }
                    else if (s==11)
                        break;
                }

            }
            else if (s==1)
            {
                for (int j=0; j<(rand()%100); j++)
                    v.push_back((rand()%10));
                Stud[i].egzas=rand()%10;
            }
        }
    }
    std::cout << "Skaiciuoti vidurki(1) ar mediana(2)? ";
    std::cin >> s1;
    while(std::cin.fail() || s1==0 || s1 !=(int)s1)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Iveskite is naujo: ";
        std::cin >> s1;
    }
    s=(int)s1;
    else
    {
        std::ifstream file("myFile");
        std::string str;
        int ndsk=0, m=0;
        if ( file )
        {
            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();
            do
            {
                    buffer >> str;
                    ndsk++;
            }
            while (str!="Egz." || str!="Egzaminas");
            ndsk=ndsk-3;

            while (!buffer.eof())
            {
                    buffer >> S[m].vardas >> S[m].pav;
                    for (i)
            }

        }
    }

        if (s==1)
        {
            for (int j=0; j<v.size(); j++)
            {
                b+=v[j];
            }
            Stud[i].vid=(double)(b/v.size())*0.4+Stud[i].egzas*0.6;
        }
        else if (s==2)
        {
            v.push_back(Stud[i].egzas);
            for (int a=0; a<v.size()-1; a++)
                for (int b=a+1; b<v.size(); b++)
                    if (v[a]>v[b])
                        std::swap (v[a], v[b]);

            if (v.size()%2!=0)
                Stud[i].med=v[v.size()/2];
            else
                Stud[i].med=(double)(v[v.size()/2-1]+v[v.size()/2])/2;
        }






    for (int i=0; i<k-1; i++)
        for (int j=i+1; j<k; j++)
            if (S[i].vardas > S[j].vardas)
                std::swap (S[i], S[j]);

    printf("|%-20s|%-30s|%-20s|%-20s|","Pavarde","Vardas","Galutinis (Vid.)","Galutinis (Med)");
    for (int i=0; i<k; i++)
    {
        //std::cout << Stud[i].vardas << "  " << Stud[i].pav << " ";
        if (Stud[i].vid!=0)
            printf("|%-20s|%-30s|%5.2lf|%5.2lf|",Stud[i].vardas.c_str(),Stud[i].pav.c_str(),Stud[i].vid,Stud[i].med);
            //std::cout << std::fixed << std::setprecision(2) << Stud[i].vid << std::endl;

        else
            printf("|%-20s|%-30s|%5.2lf|%5.2lf|",Stud[i].vardas.c_str(),Stud[i].pav.c_str(),Stud[i].vid,Stud[i].med);
        std::cout << std::endl;
    }

    return 0;
}
