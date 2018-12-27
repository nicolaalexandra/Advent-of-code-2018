#include <fstream>
#define INF 1000000000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
struct punct{
    long long x,y,z,r;
};
punct v[10000];
long long n,x,y,z,r,i,j,maxim,semn,solx,soly,solz,w[10000];
long long maximy,minimy,maximz,minimz,maximx,minimx,dist;
int viz[10000];
char s[1000];
long long modul (long long n){
    if (n < 0) return -n;
    return n;
}
long long distt (punct a, punct b){
    return modul (a.x-b.x) + modul (a.y-b.y) + modul (a.z-b.z);
}
long long zzz (){

    maximz = -INF,minimz = INF;
    for(int i=1;i<=n;i++){
        if (!viz[i]){
            maximz = max(maximz,v[i].z-v[i].r);
            minimz = min(minimz,v[i].z+v[i].r);
        }
    }
    long long poz;
    for(poz=maximz;poz<=minimz;poz++){
        int ok = 0;
        for(int i=1;i<=n;i++){
            if (!viz[i]){
                v[i].r = v[i].r - modul(poz-v[i].z);
                if(v[i].r < 0)
                    ok = 1;
            }
        }
        for(int i=1;i<=n;i++){
            if(viz[i]==1)
                continue;
            for(int j=1;j<=n;j++){
                if(viz[j]==1)
                    continue;
                long long dist = modul(v[i].x-v[j].x) + modul(v[i].y-v[j].y);
                if(dist > v[i].r+v[j].r){
                    ok=1;
                    break;
                }
            }
            if(ok == 1)
                break;
        }
        if(ok == 0)
            break;
        for(int i=1;i<=n;i++){
            if(viz[i] == 1)
                continue;
            v[i].r += modul(poz-v[i].z);
        }
    }

    return poz;
}
long long yyy(){

    for(int i=1;i<=n;i++)
        if (!viz[i])
            v[i].r -= modul(solz-v[i].z);

    maximy = -INF,minimy = INF;
    for(int i=1;i<=n;i++)
        if (!viz[i]){
            maximy = max(maximy,v[i].y-v[i].r);
            minimy = min(minimy,v[i].y+v[i].r);
        }

    long long poz;
    for(long long poz=maximy;poz<=minimy;poz++){
        int ok = 0;
        for(int i=1;i<=n;i++)
            if (!viz[i]){
                v[i].r -= modul(poz - v[i].y);
                if(v[i].r < 0)
                    ok = 1;
            }

        for(int i=1;i<=n;i++){
            if(viz[i]==1) continue;
            for(int j=1;j<=n;j++){
                if(viz[j] == 1)
                    continue;
                long long dist = modul(v[i].x-v[j].x);
                if(dist > v[i].r+v[j].r){
                    ok = 1;
                    break;
                }
            }
            if(ok == 1)
                break;
        }
        if(ok == 0)
            break;
        for(int i=1;i<=n;i++)
            if (!viz[i])
                v[i].r += modul(poz-v[i].y);
    }
    return poz;
}
long long xxx(){

    for(int i=1;i<=n;i++)
        if (!viz[i])
            v[i].r -= modul(solz-v[i].z);

    for(int i=1;i<=n;i++)
        if (!viz[i])
            v[i].r -= modul(soly-v[i].z);

    maximx = -INF,minimx = INF;
    for(int i=1;i<=n;i++)
        if (!viz[i]){
            maximx = max(maximx,v[i].x-v[i].r);
            minimx = min(minimx,v[i].x+v[i].r);
        }

    long long poz;
    for(poz=maximy;poz<=minimy;poz++){
        int ok = 0;
        for(int i=1;i<=n;i++){
            if(viz[i] == 1)
                continue;
            v[i].r -= modul(poz-v[i].x);
            if(v[i].r < 0) ok = 1;
        }
        for(int i=1;i<=n;i++){
            if(viz[i]==1)
                continue;
            for(int j=1;j<=n;j++){
                if(viz[j]==1)
                    continue;
                long long dist = 0;
                if(v[i].r + v[j].r < dist){
                    ok = 1;
                    break;
                }
            }
            if(ok == 1)
                break;
        }
        if(ok == 0)
            break;
        for(int i=1;i<=n;i++){
            if(viz[i]==1)
                continue;
            v[i].r += modul(poz - v[i].x);
        }
    }
    return poz;
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
        n++;
        v[n].x = x, v[n].y = y,v[n].z = z, v[n].r = r;
     /*   if (r > maxim){
            maxim = r;
            p = k;
        } */
    }

    for (;;){

        maxim = 0;
        for(i=1;i<=n;i++){
            if (viz[i])
                continue;
            for(j=1;j<=n;j++){
                if (viz[j]) continue;
                dist = modul (v[i].x-v[j].x) + modul (v[i].y-v[j].y) + modul (v[i].z-v[j].z);
                if(v[i].r + v[j].r < dist){
                    w[j]++;
                    maxim = max(maxim,w[j]);
                }
            }

        }
        if(maxim){
            for(i=1;i<=n;i++){
                if (w[i] == maxim)
                    viz[i] |= 1;
                else viz[i] |= 0;
            }
        } else
            break;
    }

    solz = zzz();
    soly = yyy();
    solx = xxx();

    fout<<modul (solx) + modul (soly) + modul (solz);

    return 0;
}
