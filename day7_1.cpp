#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <bitset>
using namespace std;
ifstream fin ("date.in");
ofstream fout ("date.out");
char s[100];
vector <int> L[100],tata[100];
deque <int> q;
pair <int,int> v[100];
bitset <100> f;
int sol[100],g[100],viz[100],w[100];
int n,i,x,y,rad,k,j,t,nod,vecin,ok,pas,val,gasit,lit;

int main (){

    while (fin.getline(s,100)){

        i=1;
        while ( !(s[i]>='A' && s[i] <= 'Z'))
            i++;

        x = s[i]-'A'+1;
        i++;
        while ( !(s[i]>='A' && s[i]<='Z'))
            i++;

        y = s[i]-'A'+1;

        L[x].push_back (y);
        g[y]++;
        f[x] = f[y] = 1;
        tata[y].push_back (x);
    }


    for (i=1;i<=27;i++)
        sort (L[i].begin(),L[i].end());

    /// sortare topologica

    for (i=1;i<=27;i++){
        if (f[i] == 1)
            lit++;
        if (g[i] == 0 && f[i]){
            q.push_back (i);
            w[i] = 1;
        }
    }

    while (q.size()!=0){
        nod = q.front();
        q.pop_front();
        fout<<(char)(nod+'A'-1);
        for (i=0;i<L[nod].size();i++){
            vecin = L[nod][i];
            g[vecin]--;
            if (g[vecin]==0)
                q.push_back(vecin);
        }
        sort (q.begin(),q.end());
    }


    return 0;
}
