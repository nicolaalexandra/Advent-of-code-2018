#include <fstream>
#include <cstring>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char a[100][100],b[100][100],w[100][100],d[1000][55][55];
int n,m,i,j,t,copaci,lum,liber,iv,jv,ok;
int di[] = {-1,-1,-1, 0,0, 1,1,1};
int dj[] = {-1, 0, 1,-1,1,-1,0,1};
/*
    1 1 1
    1 0 1
    1 1 1
*/
int inmat (int i, int j){
    if (i >= 1 && i <= n && j >= 1 && j <= m)
        return 1;
    return 0;
}
int main (){

    while (fin.getline(a[++n]+1,100)){
        strcpy (b[n]+1,a[n]+1);
        //strcpy (w[n]+1,a[n]+1);
    }
    m = strlen (a[1]+1);
    for (t=1;t<=417+23;t++){

        for (i=1;i<=n;i++){
            for (j=1;j<=m;j++){
                liber = copaci = lum = 0;
                for (int dir=0;dir<=7;dir++){
                    iv = i + di[dir];
                    jv = j + dj[dir];
                    if (inmat (iv,jv)){
                        if (b[iv][jv] == '.')
                            liber++;
                        if (b[iv][jv] == '|')
                            copaci++;
                        if (b[iv][jv] == '#')
                            lum++;
                    }
                }
                if (b[i][j] == '.' && copaci >= 3)
                    a[i][j] = '|';
                if (b[i][j] == '|' && lum >= 3)
                    a[i][j] = '#';
                if (b[i][j] == '#'){
                    if ( !(lum >= 1 && copaci >= 1) ) /// devine liber
                        a[i][j] = '.';
                }
            }

            strcpy(d[t][i]+1,a[i]+1);

        }
        /// copiem
        for (i=1;i<=n;i++)
            strcpy (b[i]+1,a[i]+1);

        /// acum vedem daca s a mai repetat vreodata
        for (i=1;i<t;i++){
            ok = 0;
            for (j=1;j<=n;j++){
                for (int k=1;k<=m;k++)
                    if (d[i][j][k] != b[j][k]){
                        ok = 1;
                        break;
                    }
                if (ok)
                    break;
            }

            if (!ok){
                fout<<t<<" ";
                break;
            }
        }

        //for (i=1;i<=n;i++){
          //  fout<<a[i]+1<<"\n";
        //}
        //fout<<"\n";

    }
    copaci = lum = 0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++){
            if (a[i][j] == '|')
                copaci++;
            if (a[i][j] == '#')
                lum++;
        }

    fout<<copaci*lum;

    return 0;
}
