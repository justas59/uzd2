#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    int k, s, egzas, b;
    double vid, med, k1, s1, egzas1;

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
    std::string V[k], vardas, pavarde;
    double Vid[k]={0}, Med[k]={0};
    int E[k];
    std::vector<int> v = {};
    for (int i=0; i<k; i++)
    {
        std::vector<int> v = {};
        b=0;
        std::cout << "Iveskite studento varda ir pavarde: ";
        std::cin >> vardas >> pavarde;
        V[i] = vardas + " " + pavarde;
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
            E[i]=egzas;
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
        if (s==1)
        {
            for (int j=0; j<v.size(); j++)
            {
                b+=v[j];
            }
            Vid[i]=(double)(b/v.size())*0.4+E[i]*0.6;
        }
        else if (s==2)
        {
            v.push_back(E[i]);
            for (int a=0; a<v.size()-1; a++)
                for (int b=a+1; b<v.size(); b++)
                    if (v[a]>v[b])
                        std::swap (v[a], v[b]);

            if (v.size()%2!=0)
                Med[i]=v[v.size()/2];
            else
                Med[i]=(double)(v[v.size()/2-1]+v[v.size()/2])/2;
        }
    }
    std::cout << "Pavarde   " << "Vardas    " << "Galutinis (Vid.) / Galutinis (Med.)" << std::endl << "--------------------------------------------------------" << std::endl;
    for (int i=0; i<k; i++)
    {
        std::cout << V[i] << "  ";
        if (Vid[i]!=0)
            std::cout << std::fixed << std::setprecision(2) << Vid[i] << std::endl;

        else
            std::cout << "                                      " << std::fixed << std::setprecision(2) << Med[i] << std::endl;
    }

    return 0;
}
