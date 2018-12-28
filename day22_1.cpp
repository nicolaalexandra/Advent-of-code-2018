#include <fstream>
#include <queue>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int a[5000][5000];
int depth,n,w,e,r;
int ic,jc,iv,jv,X,Y,x,y,i,j;
pair <int,int> b[5000][5000];
int d[5000][5000];
priority_queue < pair<int,int>, vector< pair<int,int> >, greater<pair<int,int> > > c;
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
int verif (int tip,int tool){
    if (tip == 0){
        if (tool == 3) return 0;
        return 1;
    } else {
        if (tip == 1){
            if (tool == 1) return 0;
            return 1;
        } else {
            if (tool == 2) return 0;
            return 1;
        }
    }
}
int inmat (int iv, int jv){
    if (iv >= 0 && jv >= 0 && iv <= X && jv <= Y)
        return 1;
    return 0;
}
int main (){

    //depth = 11991;
    //x = 6, y = 797;
    fin>>depth>>x>>y;
    X = x, Y = y;
    for (i=0;i<=X;i++)
        for (j=0;j<=Y;j++){
            if ((i==0 && j==0) || (i==x && j==y))
                e = 0;
            else {
                if (i == 0)
                    e = j*48271;
                else {
                    if (j == 0)
                        e = i*16807;
                    else
                        e = a[i][j-1]*a[i-1][j];
                }
            }
            /// in a avem erosions level
            a[i][j] = (e + depth) % 20183;
            if (a[i][j] % 3 == 0){
                r++;
            }
            else {
                if (a[i][j] % 3 == 1)
                    w++;
                else
                    n++;
            }
            b[i][j].first = a[i][j] % 3;
            d[i][j] = 2000000000;
        }
    /// part 1
    fout<<w+2*n;


    return 0;
}

