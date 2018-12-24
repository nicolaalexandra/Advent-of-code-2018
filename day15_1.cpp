#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <bitset>
#include <cstring>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
struct player{
    int x;
    int y;
    int tip;
    int att;
    int hit;
};
player v[1000],d[1000];

int di[] = {-1,0,0,1};
int dj[] = {0,-1,1,0};
int b[1000][1000];
int n,m,i,j,dir,iv,jv,k,nr1,nr2,sum,minim,poz,pas,rez,ok,K,x,y,el,st,dr,mid,ap;
vector < pair<int,int> > w;
int f[1000][1000];
//deque < pair<int,int> > c;
int c[1000][2];
char s[100],a[1000][1000];
int leee (int is, int js){
    /// facem lee sa vedem daca se poatr ajunge
//    c.clear();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            f[i][j] = 0;
  //  c.push_back (make_pair(is,is));
    c[1][0] = is;
    c[1][1] = js;
    int p = 1, u = 1;
    f[is][js] = 1;
    while (p <= u){
        int ic = c[p][0];
        int jc = c[p][1];
        for (int dir=0;dir<=3;dir++){
            int iv = ic + di[dir];
            int jv = jc + dj[dir];
            if (a[iv][jv]=='.' && b[iv][jv]==0 && f[iv][jv]==0){
                f[iv][jv] = 1 + f[ic][jc];
                //c.push_back (make_pair(iv,jv));
                c[++u][0] = iv;
                c[u][1] = jv;
            }
        }
        p++;
    }

}
int verif (int i, int j){ /// verific dacq sunt adiacente

    for (int dir=0;dir<=3;dir++){
        int iv = v[i].x + di[dir];
        int jv = v[i].y + dj[dir]; ///
        if (v[j].x == iv && v[j].y == jv)
            return 1;
    }
    return 0;
}
int cmp (player a, player b){
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int F (int i, int j){
    if (v[i].x < v[j].x)
        return 1;
    if (v[i].y < v[j].y)
        return 1;
    return 0;
}
int main (){

    while (fin.getline(s+1,100)){
        strcpy (a[++n]+1,s+1);
        m = strlen (s+1);
        for (i=1;i<=m;i++){
            if (s[i] == 'G'){
                v[++k].x = n, v[k].y = i;
                v[k].tip = 1;
                v[k].att = 3;
                v[k].hit =  200;
                a[n][i] = '.', b[n][i] = 1;
            }
            if (s[i] == 'E'){
                v[++k].x = n, v[k].y = i;
                v[k].tip = 2;
                v[k].att = 3;
                v[k].hit = 200;
                a[n][i] = '.', b[n][i] = 2;
            }
        }
    }
     ok = 0,pas = 0;
    for (;;){
        sort (v+1,v+k+1,cmp);
        for (i=1;i<=k;i++){
            if (v[i].x == -1) continue;/// e mort deja

            minim = 2000000000;
            for (j=1;j<=k;j++){
                if (i == j) continue;
                if (v[i].tip != v[j].tip){
                    /// vedem daca sunt adiacente
                    if (verif(i,j)){
                        if (v[j].hit < minim){
                            minim = v[j].hit;
                            poz = j;
                        }
                    }
                }
            }
            /// acum trebuie sa scadem puterea celui gasit
            if (minim != 2000000000){ /// a gasit pe cn sa atace
                v[poz].hit -= v[i].att;
                if (v[poz].hit <= 0){ /// moare
                    b[v[poz].x][v[poz].y] = 0;
                    v[poz].x = v[poz].y = -1;
                }
            } else {
                /// daca nu ataca pe nimeni trebuie deplasat
                /// trebuie sa ii gasim targhetele
                /// si sa decidem pe care o alege
                w.clear();
                for (j=1;j<=k;j++){
                    if (i == j) continue;
                    if (v[i].tip != v[j].tip){
                        /// incercam sa plasam tpate poz posibile
                        x = v[j].x, y = v[j].y;
                        w.push_back (make_pair(x,y));
                        if (a[x][y-1] == '.')
                            w.push_back (make_pair(x,y-1));
                        if (a[x][y+1] == '.')
                            w.push_back (make_pair(x,y+1));
                        if (a[x-1][y] == '.')
                            w.push_back (make_pair(x-1,y));
                        if (a[x+1][y] == '.')
                            w.push_back (make_pair(x+1,y));
                    }
                }
               // for (j=0;j<w.size();j++)
                 //   fout<<w[j].first<<" "<<w[j].second<<"\n";
                //fout<<"\n";
                /// acum trebuie sa vedem in care poate ajunge
                leee (v[i].x,v[i].y);
                minim = 2000000000;
                sort (w.begin(),w.end());
                for (j=0;j<w.size();j++){
                    if (f[w[j].first][w[j].second] != 0){
                        if (f[w[j].first][w[j].second] < minim){
                            minim = f[w[j].first][w[j].second];
                            poz = j;
                        }
                    }
                }
                /// am determinat pozitia spre care ar trebui sa ne deplasam
                /// sau vedem daca i se termina tura
                if (minim == 2000000000) /// i se termina tura
                    continue;
               // fout<<poz<<" ";
                if (minim != 0){
                    /// acum ca am determinat pozitia selectata si distanta
                    /// trebuie sa deplasam jucatorul
                    /// facem lee din nou din pozselectata
                    /// si alegem patratica adiacenta care are dist min
                    /// si e si in ordinea citirii
                    leee (w[poz].first,w[poz].second);
                    for (dir=0;dir<=3;dir++){
                        iv = v[i].x + di[dir];
                        jv = v[i].y + dj[dir];
                        if (f[iv][jv] == minim-1){
                            /// !!! il deplasez aici
                            b[v[i].x][v[i].y] = 0;
                            v[i].x = iv, v[i].y = jv;
                            b[v[i].x][v[i].y] = v[i].tip;
                            break;
                        }
                    }
                    /// l am deplasat
                    /// acum poate sa si atace, deci mai facem odata ce am facut la inceput
                    //****************************************************
                    minim = 2000000000;
                    for (j=1;j<=k;j++){
                        if (i == j) continue;
                        if (v[i].tip != v[j].tip){
                            /// vedem daca sunt adiacente
                            if (verif(i,j)){
                                if (v[j].hit < minim){
                                    minim = v[j].hit;
                                    poz = j;
                                }
                            }
                        }
                    }
                    /// acum trebuie sa scadem puterea celui gasit
                    if (minim != 2000000000){ /// a gasit pe cn sa atace
                        v[poz].hit -= v[i].att;
                        if (v[poz].hit <= 0){ /// moare
                            b[v[poz].x][v[poz].y] = 0;
                            v[poz].x = v[poz].y = -1;
                        }
                    }
                    //*****************************************************
                }
            }

        }
        /// eliminam jucatorii morti :( rip pt ei si pt mn
        el = 0;
        for (i=1;i<=k;i++){
            if (v[i].x != -1) v[++el] = v[i];
        }
        k = el;

        pas++;
        /// acum vedem daca pe tabla au ramas doar de un singur tip
        nr1 = nr2 = sum = 0;
        for (i=1;i<=k;i++){
            if (v[i].tip == 1)
                nr1++;
            else nr2++;

            sum += v[i].hit;
        }
        if (nr1 == 0 || nr2 == 0){
            /// s a terminat deci
            if (nr2 == ap){ /// sum intacti
                rez = sum*(pas-1);
                //return 0;
                ok = 1;
                break;
                //return 0;
            }
            break;
        }
        if (pas == 29)
            pas = 29;
    }


    fout<<rez;

    return 0;
}

