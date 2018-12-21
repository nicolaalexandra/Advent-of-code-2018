#include <fstream>
#define DIM 200000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
long long sol,nr,sum,i,val,mini;
int s;
int f[1000000],ok,n,v[1000000];
int main (){

    while (fin>>s){
        v[++n] = s;
        sum += s;
    }
    /// the sum of all the elements
    /// fout<<sum;
    val = 0;
    f[0] = 1;
    while (!ok){

        for (i=1;i<=n;i++){
            val += v[i];
            if (f[val+DIM] != 0){
                ok = 1;
                sol = val;
                break;
            }
            f[val+DIM] = 1;
        }

    }
    fout<<sol;

    return 0;
}
