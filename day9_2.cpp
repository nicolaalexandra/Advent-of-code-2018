#include <fstream>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int p,t,nr,pas,poz,i,ap,cur,k,x,v[8000000],ant[8000000];
unsigned long long d[100000],maxim;
int main (){

    fin>>p>>t;
    t *= 100;
    //v[1] = 1;
    nr = 1,pas = 1,poz = -1,k=1;
    /// v[i] = marmura care apare dupa
    /// ant[i] = marmura care apare inainte
    v[0] = 1, v[1] = 0;
    ant[1] = 0;
    ant[0] = 1;
    cur = 1;
    while (nr != t){
        pas++; /// pas % p = nr curent al jucatorului
        nr++;
        if (nr % 23 != 0){

            /// inseram pe pozitia poz+2 elementul nr
            /*poz += 2,k++;
            for (i=k;i>=poz+1;i--)
                v[i] = v[i-1];
            v[poz] = nr;
            if (poz == k)
                poz = -1;*/
            /// il inseram dupa urmatorul
            ant[nr] = v[cur];
            v[nr] = v[v[cur]];
            v[v[cur]] = nr;
            ant[ v[nr] ] = nr;
            cur = nr;

        } else {
            d[pas%p] += nr;
            /// numaram 7 pozitii in spate
            ap = 0;
            x = nr-1;
            while (ap <= 5){
                x = ant[x];
                ap++;
            }
            d[pas%p] += ant[x];
            /// inseram aici practic in locul asteaia

            ant[x] = ant[ant[x]];

            v[ant[x]] = x;
            cur = x;
            /*i = poz-7;
            if (i < 0)
                i += k+1;
            /// in i avem pozitia pe care trebuie sa o stergem
            d[pas%p] += v[i];
            poz = i;
           // fout<<i<<"\n";
           // for (;i<=k;i++) ///  le deplasam la stanga
             //   v[i] = v[i+1];
            k--;
            if (poz > k)
                poz = 0;
            else {
                if (poz == k)
                    poz = -1;
            }*/
        }

    }
    for (i=0;i<=p;i++)
        maxim = max (maxim,d[i]);
    fout<<maxim;

    return 0;
}
