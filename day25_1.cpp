#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int i,x,y,z,t,sol,semn,k,j,f[100000];
char s[100];
struct punct{
    int x,y,z,t;
};
punct v[100000];
vector <int> L[100000];
void dfs (int nod){
    f[nod] = 1;
    for (int i=0;i<L[nod].size();i++){
        int vecin = L[nod][i];
        if (!f[vecin])
            dfs (vecin);
    }
}
int modul (int n){
    if (n < 0) return -n;
    return n;
}
int dist (int i, int j){
    return modul(v[i].x-v[j].x)+modul(v[i].y-v[j].y)+modul(v[i].z-v[j].z)+modul(v[i].t-v[j].t);
}
int main (){

    while(fin.getline(s,100)){
        i = 0;
        semn = 1;
        if (s[i] == '-'){
            semn = -1;
            i++;
        }
        x = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            x = x*10 + s[i] - '0';
            i++;
        }
        x *= semn;

        i++;
        semn = 1;
        if (s[i] == '-'){
            semn = -1;
            i++;
        }
        y = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            y = y*10 + s[i] - '0';
            i++;
        }
        y *= semn;

        i++;
        semn = 1;
        if (s[i] == '-'){
            semn = -1;
            i++;
        }
        z = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            z = z*10 + s[i] - '0';
            i++;
        }
        z *= semn;

        i++;
        semn = 1;
        if (s[i] == '-'){
            semn = -1;
            i++;
        }
        t = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            t = t*10 + s[i] - '0';
            i++;
        }
        t *= semn;

        k++;
        v[k].x = x, v[k].y = y, v[k].z = z, v[k].t = t;
    }
    for (i=2;i<=k;i++){
        /// incerc sa leg asta de anterioarele
        for (j=1;j<i;j++)
            if (dist(i,j) <= 3){
                L[i].push_back (j);
                L[j].push_back (i);
            }
    }
    for (i=1;i<=k;i++)
        if (!f[i]){
            sol++;
            dfs (i);
        }

    fout<<sol;

    return 0;
}
