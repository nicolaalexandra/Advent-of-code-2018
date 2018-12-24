#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
pair <int,int> v[3000000];
char s[100];
int a[5000][5000];
int i,j,lin,col,lin1,lin2,col1,col2,k,minix,miniy,n,m,sol,jj,jmin,jmax;
void rec (int i, int j){
    /// incercam sa mergem jos, stanga dreapta
    if (i < n && a[i+1][j] == 0){
        a[i+1][j] = -1;
        rec (i+1,j);
    }
        if (j > 1 && a[i][j-1] == 0){
            a[i][j-1] = -1;
            rec (i,j-1);
        }
        if (j < m && a[i][j+1] == 0){
            a[i][j+1] = -1;
            rec (i,j+1);
        }

}
int main (){

    while (fin.getline(s,100)){
        if (s[0] == 'x'){
            /// colona + linii
            i = 2, col = 0;
            while (s[i] >= '0' && s[i] <= '9'){
                col = col*10 + s[i] - '0';
                i++;
            }
            while ( !(s[i] >= '0' && s[i] <= '9') )
                i++;
            /// prima linie
            lin1 = 0;
            while (s[i] >= '0' && s[i] <= '9'){
                lin1 = lin1*10 + s[i] - '0';
                i++;
            }

            i += 2;
            lin2 = 0;
            while (s[i] >= '0' && s[i] <= '9'){
                lin2 = lin2*10 + s[i] - '0';
                i++;
            }

            for (j=lin1;j<=lin2;j++)
                v[++k] = make_pair (j,col);


        } else{
            /// linii + coloana

            i = 2, lin = 0;
            while (s[i] >= '0' && s[i] <= '9'){
                lin = lin*10 + s[i] - '0';
                i++;
            }

            while ( !(s[i] >= '0' && s[i] <= '9') )
                i++;

            col1 = 0;
            while (s[i] >= '0' && s[i] <= '9'){
                col1 = col1*10 + s[i] - '0';
                i++;
            }

            i += 2;
            col2 = 0;
            while (s[i] >= '0' && s[i] <= '9'){
                col2 = col2*10 + s[i] - '0';
                i++;
            }

            for (j=col1;j<=col2;j++)
                v[++k] = make_pair (lin,j);
        }
    }
    /// acum le normalizez
    minix = miniy = 2000000000;
    for (i=1;i<=k;i++){
        minix = min (minix, v[i].first);
        miniy = min (miniy,v[i].second);
    }
    for (i=1;i<=k;i++)
        v[i].first -= minix, v[i].second -= miniy;

    /// maximele
    n = m = -1;
    for (i=1;i<=k;i++){
        n = max (n,v[i].first);
        m = max (m,v[i].second);
    }

    sort (v+1,v+k+1);
    /// acum le punem in matrice
    for (i=1;i<=k;i++){
        a[v[i].first][v[i].second] = 1; /// aici avem gen clei
        //fout<<v[i].first<<" "<<v[i].second<<"\n";
    }



    /// merg in jos cat pot de mult
    i = 0, j = m/2;
   // rec (0,m/2);

    /*for (;;){
        int ok = 0;
        for (i=0;i<=n;i++)
            for (j=0;j<=m;j++){
                if (a[i][j] == -1){
                    int ap = 0;
                    if (a[i][j-1] == -1) ap++;
                    if (a[i][j+1] == -1) ap++;
                    if (a[i+1][j] == -1) ap++;
                    if (ap != 3){
                        a[i][j] = 2;
                        ok = 1;
                    }
                }
            }
        if (!ok)
            break;
    }*/

    for (;;){

        while (i<=n && a[i][j] == 0){
            a[i][j] = -1;
            i++;
        }
        /// mai intai detrermin jmin si jmax
        jj = j;
        while (jj >= 0 && a[i][jj] == 0)
            jj--;
        jj++;
        jmin = jj;
        jj = j;
        while (jj <= n && a[i][jj] == 0)
            jj++;
        jj--;
        jmax = jj;


        /// acum incerc sa ma duc in stanga si in dreapta cat pot de mult
        i--;

        jj = j;
        while (jj>=jmin && a[i][jj] != 1){
            a[i][jj] = -1; /// apa dar nu sunt sigura daca intra pe aici
            jj--;
        }

        int jj2 = j;
        while (jj2 <= jmax && a[i][jj2] != -1){ /// dreapta
            a[i][jj2] = -1;
            jj2++;
        }
        i--;

        if (jj < jmin){
            j = jj;
        }
        if (jj2 > jmax){
            j = jj2; /// si acum repetam iar chestia cu mersul in jos
        }


    }


    for (i=0;i<=n;i++){
        for (j=0;j<=m;j++)
            fout<<a[i][j]<<" ";
        fout<<"\n";
    }

    for (i=0;i<=n;i++)
        for (j=0;j<=m;j++)
            if (a[i][j] == 2)
                sol++;
    fout<<sol;




    return 0;
}

