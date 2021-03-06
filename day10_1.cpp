#include <fstream>
#include <algorithm>
#include <vector>
#define DIM 100000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int i,j,p,k,lin,col,x,y,semn,mini,maxi,pas,ok,poz,dist,maxant,maxim;
pair < pair <int,int>, pair<int,int> > v[1000000];
vector <int> w[1000000];
char s[100];
int modul (int n){
    if (n < 0)
        return -n;
    return n;
}
int main (){

    while (fin.getline(s,100)){

        i = 0, semn = 1;
        while ( !(s[i] >= '0' && s[i] <= '9') ){
            if (s[i] == '-')
                semn = -1;
            i++;
        }
        lin = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            lin = lin*10 + s[i] - '0';
            i++;
        }
        lin *= semn;


        col = 0, semn = 1;
        while ( !(s[i] >= '0' && s[i] <= '9') ){
            if (s[i] == '-')
                semn = -1;
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9'){
            col = col*10 + s[i] - '0';
            i++;
        }
        col *= semn;


        x = 0, semn = 1;
        while ( !(s[i] >= '0' && s[i] <= '9') ){
            if (s[i] == '-')
                semn = -1;
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9'){
            x = x*10 + s[i] - '0';
            i++;
        }
        x *= semn;

        y = 0, semn = 1;
        while ( !(s[i] >= '0' && s[i] <= '9') ){
            if (s[i] == '-')
                semn = -1;
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9'){
            y = y*10 + s[i] - '0';
            i++;
        }
        y *= semn;

        swap (lin,col);
        swap (x,y);

        v[++k].first.first = lin;
        v[k].first.second = col;

        v[k].second.first = x;
        v[k].second.second = y;

    }

    pas = 1000;
    mini = 1000000000;
    maxi = -1000000000;
    for (i=1;i<=k;i++){
        v[i].first.first += 10710*v[i].second.first, v[i].first.second += 10710*v[i].second.second;
        mini = min (mini,min(v[i].first.first,v[i].first.second));
        maxi = max (maxi,max(v[i].first.first,v[i].first.second));
    }

    sort (v+1,v+k+1);

    for (i=mini;i<=maxi;i++){
        for (j=mini;j<=maxi;j++){
            ok = 0;
            for (p=1;p<=k;p++)
            if (v[p].first.first == i && v[p].first.second == j){
                ok = 1;
                break;
            }
            if (ok)
                fout<<"#";
            else fout<<".";
        }
        fout<<"\n";
    }

    return 0;
}

