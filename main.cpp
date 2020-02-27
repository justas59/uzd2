#include "circle.h"

int main()
{
    int k, s, egzas, t;
    double k1, s1, egzas1, t1;
    std::vector<int> v;
    std::vector<Studentas> Stud;
    std::cout << "Ar norite duomenis nuskaityti is failo? Taip - 1; Ne - 2 ";
    std::cin >> t1;
    while(std::cin.fail() || t1==0 || t1 !=(int)t1 || (t1!=1 && t1!=2))
        Test(t1);

    t=(int)t1;

    if (t==2)
    {
        std::cout << "Iveskite studentu kieki: ";
        std::cin >> k1;

        while(std::cin.fail() || k1==0 || k1 !=(int)k1)
            Test(k1);

        k=(int)k1;

        for (int i=0; i<k; i++)
        {
            Stud.push_back(Studentas());
            std::vector<int> v;
            std::cout << "Iveskite studento varda ir pavarde: ";
            std::cin >> Stud[i].vardas >> Stud[i].pav;
            std::cout << "Ar norite kad balai butu atsitiktinai generuojami? Taip - 1 ; Ne - 2 ";
            std::cin >> s1;
            while(std::cin.fail() || s1==0 || s1 !=(int)s1 || (s1!=1 && s1!=2))
                Test(s1);

            s=(int)s1;
            if (s==2)
            {
                std::cout << "Iveskite egzamino rezultata: ";
                std::cin >> egzas1;
                while(std::cin.fail() || egzas1==0 || egzas1 !=(int)egzas1)
                    Test(egzas1);

                egzas=(int)egzas1;
                Stud[i].egzas=egzas;
                std::cout << "Iveskite namu darbu rezultatus (jei nebenoresite vesti rezultatu, iveskite skaiciu 11): ";
                while (true)
                {
                    std::cin >> s1;
                    while((std::cin.fail() && s1>=0 && s1<10)|| s1==0 || s1 !=(int)s1)
                        Test(s1);

                    s=(int)s1;
                    if (s>=0 && s<=10)
                        v.push_back(s);

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
            std::cout << "Skaiciuoti vidurki(1) ar mediana(2)? ";
            std::cin >> s1;
            while(std::cin.fail() || s1==0 || s1 !=(int)s1 || (s1!=1 && s1!=2))
                Test(s1);

            s=(int)s1;
            if (s==1)
                Stud[i].vid=Vidurkis(v, Stud, i);

            else if (s==2)
                Stud[i].med=Mediana(v, Stud, i);
        }
    }

    else
    {
        std::string st;
        go: std::cout << "Iveskite failo pavadinima: ";
        std::cin >> st;
        std::string str;

        if (st[st.length()-4]!='.')
            st+=".txt";

        std::ifstream file(st);
        try
        {
            if (file)
            {
                int c, ndsk=0;
                k=0;
                std::cout << "Skaiciuoti vidurki(1) ar mediana(2)? ";
                std::cin >> s1;
                while(std::cin.fail() || s1==0 || s1 !=(int)s1 || (s1!=1 && s1!=2))
                    Test(s1);

                s=(int)s1;
                std::stringstream buffer;
                buffer << file.rdbuf();
                file.close();
                while (true)
                {
                        buffer >> str;
                        ndsk++;
                        if (str=="Egz." || str=="Egzaminas")
                            break;
                }
                ndsk=ndsk-3;

                while (!buffer.eof())
                {
                    Stud.push_back(Studentas());
                    buffer >> Stud[k].vardas >> Stud[k].pav;
                    for (int i=0; i<ndsk; i++)
                    {
                        buffer >> c;
                        v.push_back(c);
                    }
                    buffer >> Stud[k].egzas;
                    if (s==1)
                        Stud[k].vid=Vidurkis(v, Stud, k);

                    else if (s==2)
                            Stud[k].med=Mediana(v, Stud, k);

                    k++;
                }
            }
            else
            {
                throw file;
            }
        }
        catch (std::ifstream& file)
        {
            std::cout << "Failas neegzistuoja";
            goto go;
        }
    }

    for (int i=0; i<k-1; i++)
        for (int j=i+1; j<k; j++)
            if (Stud[i].vardas > Stud[j].vardas)
                std::swap (Stud[i], Stud[j]);

    printf("%-20s%-30s%-20s%-20s","Pavarde","Vardas","Galutinis (Vid.)","Galutinis (Med)");
    std::cout << std::endl;
    for (int i=0; i<k; i++)
    {
        if (Stud[i].vid!=0)
            printf("%-20s%-30s%5.2lf",Stud[i].vardas.c_str(),Stud[i].pav.c_str(),Stud[i].vid);

        else
            printf("%-20s%-30s%30.2lf",Stud[i].vardas.c_str(),Stud[i].pav.c_str(),Stud[i].med);
        std::cout << std::endl;
    }

    return 0;
}
