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

   // pas = 1000;
    for (i=1;i<k;i++)
    for (j=i+1;j<=k;j++){
        dist = modul (v[i].first.first - v[j].first.first) + modul (v[i].first.second-v[j].first.second);
        if (dist > maxim)
            maxim = dist;
    }

    for (;;){

        mini = 1000000000;
        maxi = -1000000000;
        for (i=1;i<=k;i++){
            v[i].first.first += v[i].second.first, v[i].first.second += v[i].second.second;
            mini = min (mini,min(v[i].first.first,v[i].first.second));
            maxi = max (maxi,max(v[i].first.first,v[i].first.second));
        }

       /// calculam distanta dintre puncte
       maxant = maxim;
       maxim = 0;
       for (i=1;i<k;i++)
       for (j=i+1;j<=k;j++){
            dist = modul (v[i].first.first - v[j].first.first) + modul (v[i].first.second-v[j].first.second);
            if (dist > maxim)
                maxim = dist;
       }
       pas++;
       if (maxim > maxant){
            break; /// se departeaza iar
       }


    }
    fout<<pas-1;

    return 0;
}
