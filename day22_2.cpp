#include <fstream>
#include <queue>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int a[5000][5000];
int depth,n,w,e,r;
int ic,jc,iv,jv,X,Y,x,y,i,j;
pair <int,int> b[5000][5000];
int d[5000][5000],f[5000][5000];
//priority_queue < pair<int,int>, vector< pair<int,int> >, greater<pair<int,int> > > c;
queue < pair<int,int> > c;
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
    for (i=0;i<=depth;i++)
        for (j=0;j<=depth;j++){
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

    c.push (make_pair(0,0)); /// avem torch
    b[0][0].second = 1; /// torch
    d[0][0] = 0;
    f[0][0] = 1;
    /// 2 - climbing
    /// 3 neither
    while (!c.empty()){
        ic = c.front().first;
        jc = c.front().second;
        f[ic][jc] = 0;
        c.pop();
        for (int dir=0;dir<=3;dir++){
            iv = ic + di[dir];
            jv = jc + dj[dir];
            if (inmat(iv,jv)){
                /// ma aflu in ic jc si incerc sa schimb
                /// astfel incat sa pot trece in iv jv
                if (b[ic][jc].first == 0){
                    /// acum sa vad in ce pot schimba
                    if (verif(b[iv][jv].first,b[ic][jc].second)){
                        if (d[ic][jc]+1 < d[iv][jv]){
                            b[iv][jv].second = b[ic][jc].second;
                            d[iv][jv] = d[ic][jc]+1;
                            if (!f[iv][jv]){
                                c.push (make_pair(iv,jv));
                                f[iv][jv] = 1;
                            }
                        }
                    }
                    x = b[ic][jc].second;
                    if (x == 1) x = 2;
                    else x = 1;

                    if (verif(b[iv][jv].first,x))
                        if (d[ic][jc]+7 < d[iv][jv]){
                            d[iv][jv] = d[ic][jc]+7;
                            b[iv][jv].second = x;
                            if (!f[iv][jv]){
                                c.push (make_pair(iv,jv));
                                f[iv][jv] = 1;
                            }
                        }
                        //d[iv][jv] = min (d[iv][jv],d[ic][jc]+7);

                } else {
                    if (b[ic][jc].first == 1){
                        x = b[ic][jc].second;
                        if (verif(b[iv][jv].first,x))
                            if (d[ic][jc]+1 < d[iv][jv]){
                                d[iv][jv] = d[ic][jc]+1;
                                b[iv][jv].second = x;
                                if (!f[iv][jv]){
                                    c.push (make_pair(iv,jv));
                                    f[iv][jv] = 1;
                                }
                            }
                            //d[iv][jv] = min (d[iv][jv],d[ic][jc]+1);
                        if (x == 2) x = 3;
                        else x = 2;
                        if (verif(b[iv][jv].first,x))
                            if (d[ic][jc]+7 < d[iv][jv]){
                                d[iv][jv] = d[ic][jc]+7;
                                b[iv][jv].second = x;
                                if (!f[iv][jv]){
                                    c.push (make_pair(iv,jv));
                                    f[iv][jv] = 1;
                                }
                            }
                            //d[iv][jv] = min (d[iv][jv],d[ic][jc]+1);

                    } else {
                        x = b[ic][jc].second;
                        if (verif(b[iv][jv].first,x))
                            if (d[ic][jc]+1 < d[iv][jv]){
                                d[iv][jv] = d[ic][jc]+1;
                                b[iv][jv].second = x;
                                if (!f[iv][jv]){
                                    c.push (make_pair(iv,jv));
                                    f[iv][jv] = 1;
                                }
                            }
                            //d[iv][jv] = min (d[iv][jv],d[ic][jc]+1);
                        if (x == 1) x = 3;
                        else x = 3;
                        if (verif(b[iv][jv].first,x))
                            if (d[ic][jc]+7 < d[iv][jv]){
                                d[iv][jv] = d[ic][jc]+7;
                                b[iv][jv].second = x;
                                if (!f[iv][jv]){
                                    c.push (make_pair(iv,jv));
                                    f[iv][jv] = 1;
                                }
                            }
                            //d[iv][jv] = min (d[iv][jv],d[ic][jc]+1);
                    }
                }
            }
        }
    }
    fout<<d[X][Y];

    return 0;
}

