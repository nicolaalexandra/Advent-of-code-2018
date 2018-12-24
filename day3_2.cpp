#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
int i,id,x,y,n,m,sol;
char c;
//bitset <10001> v1[10001];
int v1[1001][1001];
bitset <10001> v2[10001];
bitset <1312> f;
int v3[10001][10001];
int ii,jj,I,J,comune;
int main(){

    for(i=1;i<=1311;i++){
        fin>>c>>id>>c>>x>>c>>y>>c>>n>>c>>m;
       // fout<<id<<" "<<x<<" "<<y<<" "<<n<<" "<<m<<"\n";
       for(ii=x+1;ii<=x+n;ii++)
        for(jj=y+1;jj<=y+m;jj++){
           if(v1[ii][jj]==0){
               v1[ii][jj]=id;
               ///doar o data
           }
           else{
               if(v2[ii][jj]==0){

                   ///a doua oara
                   ///marcam cerintele in v3
                   f[v1[ii][jj]]=1;
                   f[id]=1;
                   v1[ii][jj]=id;
                   v2[ii][jj]=1;
                   sol++;
               }
               else{
                    sol++;
                    f[id]=1;
                    f[v1[ii][jj]]=1;
                }
           }
       }
    }
    //fout<<comune;
    for(i=1;i<=1311;i++)
        if(f[i]==0){
            fout<<i<<" ";
            break;
        }
    //fout<<sol;

    return 0;
}
