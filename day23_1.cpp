#include <fstream>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000];
long long i,x,y,z,p,maxim,nr,r,k,semn;
struct ceva{
    long long x,y,z,r;
};
ceva v[10000];
long long modul (long long n){
    if (n < 0) return -n;
    return n;
}
long long dist (ceva a, ceva b){
    return modul (a.x-b.x) + modul (a.y-b.y) + modul (a.z-b.z);
}
int main (){


    while (fin.getline(s,1000)){
        i = 0;
        while (!(s[i] >= '0' && s[i] <= '9'))
            i++;
        if (s[i-1] == '-')
            semn = -1;
        else semn = 1;
        x = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            x = x*10 + s[i] - '0';
            i++;
        }
        x *= semn;

        while (!(s[i] >= '0' && s[i] <= '9'))
            i++;
        if (s[i-1] == '-')
            semn = -1;
        else semn = 1;
        y = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            y = y*10 + s[i] - '0';
            i++;
        }
        y *= semn;
        while (!(s[i] >= '0' && s[i] <= '9'))
            i++;
        if (s[i-1] == '-')
            semn = -1;
        else semn = 1;
        z = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            z = z*10 + s[i] - '0';
            i++;
        }
        while (!(s[i] >= '0' && s[i] <= '9'))
            i++;
        z *= semn;
        r = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            r = r*10 + s[i] - '0';
            i++;
        }
        k++;
        v[k].x = x, v[k].y = y,v[k].z = z, v[k].r = r;
        if (r > maxim){
            maxim = r;
            p = k;
        }
    }
    for (i=1;i<=k;i++)
        if (dist(v[i],v[p]) <= maxim)
            nr++;
    fout<<nr;

    return 0;
}
