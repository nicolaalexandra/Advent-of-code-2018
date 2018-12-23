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

    /// pot sa am mai multe radacini?

    //for (i=1;i<=27;i++){
      //  if (f[i] == 1)
       //     lit++;
      //  if (g[i] == 0 && f[i]){
        //    q.push_back (i);
           // w[i] = 1;
        //}
    //}

    f.reset ();

    for (;;){

        for (i=1;i<=5;i++){
            if (v[i].second != 0){
                v[i].second--;
                if (v[i].second == 0){
                    f[v[i].first] = 1;
                    v[i].first = 0;
                }
            }
        }
        for (i=1;i<=5;i++){
            if (v[i].first == 0){
                //f[v[i].first] = 1; /// tocmai i s a terminat tura
                //v[i].first = 0;
                /// vreau sa plasez un muncitor nou
                for (j=1;j<=27;j++){
                    if (f[j] || w[j])
                        continue;
                    /// verific daca toti tatii lui
                    /// s au terminat
                    gasit = 0;
                    for (int p=0;p<tata[j].size();p++)
                        if (f[tata[j][p]] == 0){
                            gasit = 1;
                            break;
                        }
                    if (gasit == 0){
                        /// il plasez aici
                        v[i].first = j;
                        v[i].second = j+60; //
                        w[j] = 1;
                        break;
                    }
                }
            }
        }

        pas++;
        ok = 0;
        for (i=1;i<=5;i++)
            if (v[i].first != 0)
                ok = 1;
        if (!ok)
            break;
    }

    fout<<pas-1;




   /* for (;;){
        ok = 0;
        /// parcurgem muncitorii disponibili
        for (i=1;i<=5;i++){
            if (v[i].first != 0){
                v[i].second--;
                if (v[i].second == 0){
                    f[v[i].first] = 1; /// s a terminat tura
                    val = v[i].first;
                    v[i].first = 0;
                    ///adaugam toti noi muncitorii care pot incepe
                    for (j=0;j<L[val].size();j++){
                        /// verificam daca toti tatii lui L[val][j] au fost pusi

                        //if (f[L[val][j]])
                          //  continue;
                        nod = L[val][j];
                        gasit = 0;
                        for (int p=0;p<tata[nod].size();p++){
                            if (f[tata[nod][p]] == 0)
                                gasit = 1;
                        }
                        if (gasit == 0 && w[nod] == 0){ /// nu a mai fost adaugat niciodata
                            q.push_back (nod);
                            w[nod] = 1;
                  //          lit++;
                        }
                    }

                }
            }

        }
        sort (q.begin(),q.end());
        /// completam locurile goale
        for (i=1;i<=5;i++)
            if (v[i].first == 0 && q.size()!=0){
                v[i].first = v[i].second = q.front();
                q.pop_front();
            }

        pas++;

        ok = 0;
        for (i=1;i<=5;i++)
            if (v[i].second != 0)
                ok = 1;
        if (!ok)
            break;
    }*/


    return 0;
}

