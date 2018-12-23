#include <fstream>
#include <cstring>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
long long nr2,nr3;
char s[100],a[300][100];
int i,nr,ap,poz,j,k,f[30];
int main (){

    while (fin>>s){
        for (i=0;i<=26;i++)
            f[i] = 0;
        for (i=0;s[i]!=NULL;i++)
            f[s[i]-'a']++;

        for (i=0;i<=26;i++)
            if (f[i] == 2){
                nr2++;
                break;
            }

        for (i=0;i<=26;i++)
            if (f[i] == 3){
                nr3++;
                break;
            }

    }
    fout<<nr2*nr3;

    return 0;
}

