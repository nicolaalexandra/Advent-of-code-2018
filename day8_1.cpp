#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");
int sol;
void dfs (){
    int n,m,x;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        dfs ();
    for(int i=1;i<=m;i++){
        fin>>x;
        sol += x;
    }
}
int main(){

    dfs ();
    fout<<sol;

    return 0;
}
