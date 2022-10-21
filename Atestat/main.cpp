#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include <string.h>
using namespace std;
char s[255], op[255],input[10];
long double v[515];
int i,j,k,ok;
double adunare(double a, double b)
{
    return a + b;
}
double scadere(double a, double b)
{
    return a - b;
}
double inmultire(double a, double b)
{
    return a * b;
}
double impartire(double a, double b)
{
    return a / b;
}
int putere(int zec)
{
    int x = 1;
    while (zec)
    {
        x = x * 10;
        zec = zec / 10;
    }
    return x;
}
void background()
{
    cout << "              .__               .__          __                 " << endl;
    cout << "  ____ _____  |  |   ____  __ __|  | _____ _/  |_  ___________  " << endl;
    cout << " / ___\\\\__  \\ |  | _/ ___\\|  |  \\  | \\__  \\\\   __\\/  _ \\_  __ \\" << endl;
    cout << " \\ \\___ / __ \\|  |_\\  \\___|  |  /  |__/ __ \\|  | (  <_> )  | \\/ " << endl;
    cout << "  \\____>______/____/\\_____>____/|____(______/__|  \\____/|__|    " << endl;
    cout << "                                                de Gergely Mark"<<endl;
    char introducere[] = "Acest calculator suporta urmatoarele operatii:\n 1)Operatia de adunare:'+' \n 2)Operatia de scadere:'-' \n 3)Operatia de inmultire:'*' \n 4)Operatia de impartire:'/' \n";
    for (i = 0; i < strlen(introducere); i++)
    {
        cout << introducere[i];
        Sleep(35);
    }

}
void intrebare()
{
    char s2[]="Doriti sa calculati alta expresie? (Da/Nu)\n";
    for(i=0; i<strlen(s2); i++)
    {
        cout<<s2[i];
        Sleep(35);
    }
    cin.getline(input,5);
}
void stergere(int nr,int nrx)
{
    for (i = j + 1; i < nr; i++)
        v[i] = v[i + 1];
    for (i = k; i < nrx; i++)
        op[i] = op[i + 1];
}
void rezultat(int ok)
{
    if (ok == 0)
    {
        char s5[]="Rezultatul este: ";
        for(i=0; i<strlen(s5); i++)
        {
            cout<<s5[i];
            Sleep(35);
        }
        Sleep(100);
        cout <<v[1] <<" \n";
    }
    else
        cout << "Impartirea la 0 nu este definita \n";
}
void calculator (char op1, char op2,int nrx, int nr,int& ok)
{
    k=1;
    j=1;
    while (k < nrx)
    {
        if (op[k] == op1 or op[k] == op2)
        {
            if(op1=='*' and op2=='/')
            {
                if (op[k] == op1)
                    v[j] = inmultire(v[j], v[j + 1]);
                else
                {
                    if (v[j + 1] == 0)
                        ok++;
                    v[j] = impartire(v[j], v[j + 1]);
                }
                stergere(nr,nrx);
                nr--;
                nrx--;
            }
            else
            {
                if (op[k] == op1)
                    v[j] = adunare(v[j], v[j + 1]);
                else
                    v[j] = scadere(v[j], v[j + 1]);
                stergere(nr,nrx);
                nr--;
                nrx--;
            }
        }
        else
        {
            k++;
            j++;
        }
    }

}
void calculare()
{
    int nr=1,nrx=1,p,sin=0;
    double zec=0;
    sin=0;
    ok=0;
    char s1[]="Introduceti expresia pe care doriti sa o calculati: \n";
    for(i=0; i<strlen(s1); i++)
    {
        cout<<s1[i];
        Sleep(35);
    }
    cin.getline(s, 255);
    for(i=0; i<250; i++)
        v[i]=0;
    i=0;
    for(i=0; i<strlen(s); i++)
    {
        if(isdigit(s[i])==0)
        {
            if(strchr("+-*/.",s[i])==0)
                sin++;
            if(strchr("+-*/.",s[i]) and strchr("+-*/.",s[i+1]))
                sin++;
        }

    }
    if(sin)
    {
        char s4[]="Sintaxa incorecta!\n";
        for(i=0; i<strlen(s4); i++)
        {
            cout<<s4[i];
            Sleep(35);
        }
    }
    else
    {
        i=0;
        //formarea vectorului de numere in float si vectorul de operatii in char
        while (i < strlen(s))
        {
            while (isdigit(s[i]))
            {
                v[nr] = v[nr] * 10 + s[i] - '0';
                i++;
            }
            if (s[i] == '.')
            {
                zec = 0;
                p = i;
                i++;
                while (isdigit(s[i]))
                {
                    zec = zec * 10 + s[i] - '0';
                    i++;
                }
                v[nr] = v[nr] + zec / putere(zec);
            }
            nr++;
            op[nrx] = s[i];
            nrx++;
            i++;
        }
        //calcularea operatiilor prioritare (*/)
        calculator('*','/',nrx,nr,ok);
        //calcularea operatiilor simple (+-)
        calculator('+','-',nrx,nr,ok);
        rezultat(ok);
    }
    intrebare();
    if(strcmp(input,"Da")==0)
        calculare();
    else
    {
        char s3[]="Va multumesc pentru atentie!";
        for(i=0; i<strlen(s3); i++)
        {
            cout<<s3[i];
            Sleep(35);
        }
    }
}
int main()
{
    background();
    calculare();
}
