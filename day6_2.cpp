#include <fstream>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int i,j,n,m,lin,col,k,minim,sol,ap,p,dist,maxim;
int f[1000][1000],a[1000][1000],d[10000],w[10000];
pair <int,int> v[10000];
char s[100];
int modul (int n){
    if (n < 0)
        return -n;
    return n;
}
int main (){

    while (fin.getline(s,100)){
        i = 0, lin = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            lin = lin * 10 + s[i] - '0';
            i++;
        }
        i += 2, col = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            col = col*10 + s[i] - '0';
            i++;
        }
        swap (lin,col);
        v[++k] = make_pair (lin,col);
        f[lin][col] = k;

        n = max (n,lin);
        m = max (m,col);

    }

    /*for (i=0;i<=n;i++)
        for (j=0;j<=m;j++){
            /// aflam distanta manhattan minima
            if (f[i][j] != 0){
                a[i][j] = f[i][j];
                d[a[i][j]]++;
                continue;
            }
            if (i == 6 && i == 7)
                sol = 0;
            minim = 2000000000;
            for (p=1;p<=k;p++){
                dist = modul (i-v[p].first) + modul (j-v[p].second);
                if (dist < minim){
                    minim = dist;
                    sol = p;
                    ap = 1;
                } else {
                    if (dist == minim)
                        ap++;
                }
            }

            if (ap == 1){
                a[i][j] = f[v[sol].first][v[sol].second];
                d[a[i][j]]++;

            } else {
                a[i][j] = 0;
            }

        }*/

    /*for (i=0;i<=n;i++){
        for (j=0;j<=m;j++)
            fout<<a[i][j]<<" ";
        fout<<"\n";
    }*/
///
    /*for (i=0;i<=n;i++){
        w[a[i][0]] = 1;
        w[a[i][m]] = 1;
    }
    for (j=0;j<=m;j++){
        w[a[0][j]] = 1;
        w[a[n][j]] = 1;
    }

    maxim = 0;
    for (i=1;i<=k;i++)
        if (w[i] == 0){
            if (d[i] > maxim)
                maxim = d[i];
        }
    fout<<maxim<<" ";*/
    sol = 0;
    for (i=0;i<=10000;i++)
        for (j=0;j<=10000;j++){
            dist = 0;
            for (p=1;p<=k;p++){
                dist += modul (i-v[p].first) + modul (j-v[p].second);
            }
            if (dist < 10000)
                sol++;
        }
    fout<<sol;
    return 0;
}
