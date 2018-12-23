#include <fstream>
#include <cstring>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
long long nr2,nr3;
char s[100],a[300][100];
int i,nr,ap,poz,j,k;
int main (){

    while (fin>>s){
        strcpy (a[++k],s);
    }
    for (i=1;i<k;i++)
        for (j=i+1;j<=k;j++){
            ap = 0;
            for (poz=0;a[i][poz]!=NULL;poz++){
                if (a[i][poz] != a[j][poz]){
                    ap++;
                    nr = poz;
                }
            }
            if (ap == 1){
                for (poz=0;a[i][poz]!=NULL;poz++)
                    if (poz != nr)
                        fout<<a[i][poz];
                return 0;
            }
        }

    return 0;
}
