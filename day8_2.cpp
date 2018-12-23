#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
long long copii,nr,i,x,sum,meta,k,v[1000000],d[1000000];
long long poz=1;
vector <int> w[100000];
int dfs (int nod, int tata){
    //fin>>copii>>meta;
    poz++;
    int copii = v[k], meta = v[k+1];
    k += 2;
    for (int i=1;i<=copii;i++){
        w[nod].push_back (poz);
        dfs (poz, nod);

    }

    /// am terminat cu nod
    if (copii != 0){
        for (int i=1;i<=meta;i++){
            /// ma intereseaza al v[k] lea fiu al lui nod
            if (v[k] <= copii){
                d[nod] += d[ w[nod][v[k]-1] ];
            }
            k++;
        }
    } else {
        for (int i=1;i<=meta;i++)
            d[nod] += v[k++];
    }

}

int main (){

    while (fin>>x)
        v[++k] = x;


    /// ultimele v[2] numere din v repr metadatele pentru radacina

    k = 1;
    dfs (1,0);
    fout<<d[1];


    return 0;
}
