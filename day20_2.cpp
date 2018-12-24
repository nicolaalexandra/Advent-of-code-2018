#include <fstream>
#include <vector>
#include <cstring>
#define DIM 5000000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[DIM];
vector < pair<int,int> > L[DIM];
vector <int> v[DIM];
int d[DIM],viz[DIM],w[DIM];
int i,j,poz,sol,st,l,k,nr,ok;
void rec (int poz){

    if (s[poz+1] == '|'){
        rec (poz+1);
    }
    else {
        if (s[poz+1] >= 'A' && s[poz+1] <= 'Z'){
            v[poz].push_back (poz+1);
            rec (poz+1);
        } else {
            if (s[poz+1] == '('){
                nr++;
                w[++k] = poz+1;
                for (int i=0;i<L[poz+1].size();i++){
                    v[poz].push_back (L[poz+1][i].first);
                    //v[L[poz+1][i].second].push_back ()
                    rec (L[poz+1][i].first);
                }
                //st++;
            } else {
                if (k < 0)
                    k = k;
                //if (k > 0){
                if (s[poz+1] == ')'){
                    if (s[poz+2] >= 'A' && s[poz+2] <= 'Z'){
                        /// o legam de restul din paranteza
                        for (int i=0;i<L[w[k]].size();i++){
                            v[L[w[k]][i].second].push_back (poz+2);
                        }
                        k--;
                        rec (poz+2);
                    } else{
                        k--;
                        rec (poz+1);
                    }
                    //k--;
                }
                //}
            }
        }
    }
}
void dfs (int nod){
    viz[nod] = 1;
    for (int i=0;i<v[nod].size();i++){
        int vecin = v[nod][i];
        if (!viz[vecin]){
            dfs (vecin);
            d[nod] = max (d[nod],d[vecin]+1);
            sol +=(d[nod]>= 1000);
        }
    }
}
int main (){

    fin>>s;
    l = strlen (s);
    //x = 1;
    for (i=2;i<l-1;i++){
        /*if (s[i] >= 'A' && s[i] <= 'Z'){
            n++;
            L[x].push_back (n);
        }
        if (s[i] == '('){
            /// trebuie sa pastram valoarea lui n
            val = n;
        }
        if (s[i] == '|')
            n = val;*/
        if (s[i] == '|' && s[i+1] == '(') ok = 1;
        if (s[i] == '('){
            w[++k] = i;
           // nr++;
            if (s[i+1] >= 'A' && s[i+1] <= 'Z'){
                j = i+1;
                while (s[j] >= 'A' && s[j] <= 'Z')
                    j++;

                L[w[k]].push_back (make_pair(i+1,j-1));
            }
        }
        if (s[i] == '|'){
            /// pe asta o cuplam cu ultima din stiva
            //L[v[k]].push_back (poz1);
            if (s[i+1] >= 'A' && s[i+1] <= 'Z'){
                /// acum ii cautam sfarsitul
                j = i+1;
                while (s[j] >= 'A' && s[j] <= 'Z')
                    j++;
                L[w[k]].push_back (make_pair(i+1,j-1));
            }
        }
        if (s[i] == ')')
            k--; /// scoatem paranteza
    }
    /// acum facem recursiv
    st = 1;
    //s[14089] = s[14090] = s[14091] = s[14088] = 0;
    //rec (1);
    //fout<<ok;
    /// am construit graful acum vedem drumul de lungime maxima
    sol = 0;
    dfs (1);
    fout<<sol;

    return 0;
}
