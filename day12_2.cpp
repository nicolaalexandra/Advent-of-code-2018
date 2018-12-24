#include <fstream>
#include <cstring>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char a[100][100],v[8000000],w[7],d[8000000],h[8000000];
int k,n,i,j,g,ok,sol,nr,m,solant;
int main (){

    fin>>v+1;
    fin.get();
    while (fin.getline(a[++k],100));

    k--;
    n = strlen (v+1);
    strcpy (h,v);
    m = n;
    for (g=1;g<=200;g++){ /// se vor repeta
        /// pun doua puncte in fata si in spate
        for (i=n+4;i>4;i--)
            v[i] = v[i-4];
        //for (i=n+2;i<=n;i++)

        v[1] = v[2] = v[3] = v[4] ='.';
        n += 4;
        v[n+1] = v[n+2] = v[n+3] = v[n+4] ='.';
        n += 4;
        //for (i=1;i<=n;i++)
          //  fout<<v[i];
        //fout<<"\n";
        for (i=3;i<=n-2;i++){
            /// verific daca secventa ..i.. in ce se transforma
            w[0] = v[i-2];
            w[1] = v[i-1];
            w[2] = v[i];
            w[3] = v[i+1];
            w[4] = v[i+2];
            /// acum caut printre sabloane
            ok = 0;
            for (j=1;j<=k;j++){
                if (a[j][0] == w[0] && a[j][1] == w[1] && a[j][2] == w[2] && a[j][3] == w[3] && a[j][4] == w[4]){
                    /// asta e sablon bun
                    w[2] = a[j][9];
                    ok = 1;
                    break;
                }
            }
            if (!ok)
                w[2] = '.';

            d[i] = w[2];
            /*if (ok)
                v[i] = w[2];
            else v[i] = '.';*/
        }
        for (i=3;i<=n-2;i++)
            v[i] = d[i];
        solant = sol;
        sol = 0;
        for (i= g*4+2,nr=1;i<=n;i++,nr++)
            if (v[i] == '#')
                sol += nr;
        for (i=g*4,nr=1;i>=1;i--,nr++)
            if (v[i] == '#')
                sol -= nr;
        fout<<sol<<" "<<sol-solant<<"\n";
        /*if (g==20 || g == 40){
            for (i=1;i<=n;i++)
                fout<<v[i];
            fout<<"\n";
        }*/
        /// verific daca coincide cu sablonul
        i = 1;
        while (v[i] == '.')
            i++;
        ok = 0;
        for (j=1;j<=m;j++,i++)
            if (v[i] != h[j])
                ok = 1;
        if (ok == 0)
            fout<<i;
    }
    /// pe poz 41 avem practic 0;

    return 0;
}
