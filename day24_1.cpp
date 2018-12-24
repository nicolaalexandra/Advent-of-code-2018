#include <fstream>
#include <algorithm>
#define NR 2
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

struct ceva{
    int u;
    int hit;
    int d;
    int type;
    int weak[6];
    int imm[6];
    int init;
    int eff;
};
ceva v[2][1000];
pair < pair<int,int>, pair<int,int> > a[10000];
int i,j,t,nr,x,ok,maxim,maxim2,maxim3,el,poz,damage,q,sol,k,dead;
int cmp (pair< pair<int,int>,pair<int,int> > a,pair< pair<int,int>,pair<int,int> > b){
    if (a.first != b.first)
        return a.first > b.first;
    return a.second.first > b.second.first;
}

struct ceva2{
    int alacareataca;
    int atacat;
    int tip;
    int init;
};
ceva2 b[10000];
/// de refacut
int cmp2 (ceva2 a,ceva2 b){
    return a.init > b.init;
}
int f (ceva a, ceva b){
    /// calculez damage;
    int nr = a.u * a.d;
    /// acum vedem daca se dubleaza sau ramane la fel
    int ok = 0;
    for (int q=1;q<=5;q++){
        if (b.imm[q] == a.type){
            ok = 1;
            break;
        }
    }
    if (ok) return 0;

    ok = 0;
    for (int q=1;q<=5;q++){
        if (b.weak[q] == a.type){
            ok = 1;
            break;
        }
    }
    if (ok) nr *= 2;
    return nr;
}
int main (){
    /// units, hit points, attack damage, att type,
    /// weaknesses, imunities, initiative, effective pow
    /// fire,cold,radiation,slashing,bludgeoning
    /// 1     2    3         4           5

    for (i=1;i<=NR;i++){
        fin>>v[0][i].u>>v[0][i].hit>>v[0][i].d>>v[0][i].type;
        fin>>nr; /// weakness
        for (j=1;j<=nr;j++){
            fin>>x;
            v[0][i].weak[j] = x;
        }
        fin>>nr;
        for (j=1;j<=nr;j++){
            fin>>x;
            v[0][i].imm[j] = x;
        }
        fin>>v[0][i].init;
        v[0][i].eff = v[0][i].u * v[0][i].d;
    }

    for (i=1;i<=NR;i++){
        fin>>v[1][i].u>>v[1][i].hit>>v[1][i].d>>v[1][i].type;
        fin>>nr; /// weakness
        for (j=1;j<=nr;j++){
            fin>>x;
            v[1][i].weak[j] = x;
        }
        fin>>nr;
        for (j=1;j<=nr;j++){
            fin>>x;
            v[1][i].imm[j] = x;
        }
        fin>>v[1][i].init;
        v[1][i].eff = v[1][i].u * v[1][i].d;
    }

    for (;;){

        /// le punem intr un vector si le sortam
        el = 0;
        for (i=1;i<=NR;i++){
            if (v[0][i].u == 0) continue;
            a[++el].first.first = v[0][i].eff;
            a[el].second.first = v[0][i].init;
            a[el].second.second = 0;
            a[el].first.second = i;
        }
        for (i=1;i<=NR;i++){
            if (v[1][i].u == 0) continue;
            a[++el].first.first = v[1][i].eff;
            a[el].second.first = v[1][i].init;
            a[el].second.second = 1;
            a[el].first.second = i;
        }

        sort (a+1,a+el+1,cmp);

        for (i=1;i<=el;i++){
            t = 1 - a[i].second.second;
            poz = a[i].first.second;
            //damage = v[1-t][poz].u * v[1-t][poz].d;
            damage = v[1-t][poz].eff;
            maxim = 0, dead = 0, sol = 0;
            for (j=1;j<=NR;j++){
                /// acum alegem targetul
                /// practic vedem daca dublam damage sau il lasam asa
                /// vedem daca asta e imun la ala cu care ataca
                ok = 0;
                for (q=1;q<=5;q++){
                    if (v[t][j].imm[q] == v[1-t][poz].type){
                        ok = 1;
                        break;
                    }
                }
                if (ok) continue;
                /// acum vedem daca cumva se dubleaza
                ok = 0;
                for (q=1;q<=5;q++){
                    if (v[t][j].weak[q] == v[1-t][poz].type){
                        ok = 1;
                        break;
                    }
                }
                if (ok == 1) nr = 2*damage;
                else nr = damage;

                if (nr > maxim){
                    maxim = nr, maxim2 = v[t][j].eff;
                    sol = j;
                } else {
                    if (nr == maxim){ /// largest eff pow
                        if (v[t][j].eff > maxim2){
                            maxim2 = v[t][j].eff, maxim3 = v[t][j].init;
                            sol = j;
                        } else {
                            if (v[t][j].eff == maxim2){ /// highest inn
                                if (v[t][j].init > maxim3){
                                    maxim3 = v[t][j].init, ok = 0;
                                    sol = j;
                                }
                                else{
                                    if (v[t][j].init == maxim3)
                                        dead = 1;
                                }
                            }
                        }
                    }
                }
            }

            if (!dead){
               /* b[i].first.first = sol; /// POZITIA DIN V PRACTIC;
                b[i].second.first = maxim; /// damage
                b[i].second.second = v[1-t][poz].init;
                b[i].first.second = t; /// tipul*/
                /*b[sol].first.first = i;
                b[sol].second.first = maxim; /// damageul care i se aplica
                b[sol].second.second = v[1-t][poz].init;
                b[sol].first.second = t; /// tipul*/
                b[i].init = v[1-t][poz].init;
                b[i].atacat = sol;
                b[i].alacareataca = i;
                b[i].tip = t; /// tipul aluia atacat

            } else {
                b[sol].atacat = -1;
            }

        }
        /// am stabilit pentru fiecare pe cine ataca
        sort (b+1,b+el+1,cmp2);
        for (i=1;i<=el;i++){
            if (b[i].atacat == -1) continue;
            t = b[i].tip;
            v[t][b[i].atacat].u = f (v[1-t][b[i].alacareataca],v[t][b[i].atacat]) / v[t][b[i].atacat].hit;

            /*if (b[i].first.first == -1) continue;
            t = b[i].first.second;
            poz = b[i].first.first;
            int dam = b[i].second.first/v[t][poz].hit;
            v[t][poz].u -= dam;
            /// acum ar trebuie sa actualizam in b?
           // if (b[i].second.first%v[t][b[i].first.first].hit == 0 && b[i].second.first != 0)
             //   v[t][b[i].first.first].u++;
*/
        }

        /// acum elimanam daca am ramas cumva cu u < 0
        ok = 0;
        for (t=0;t<=1;t++){
            k = 0;
            for (i=1;i<=NR;i++){
                if (v[t][i].u > 0)
                    v[t][++k] = v[t][i];
            }
            for (i=k+1;i<=NR;i++)
                v[t][i].u = 0;
            if (k == 0) ok = 1;
        }
        if (ok) break;
    }
    sol = 0;
    for (i=1;i<=NR;i++)
        sol += v[0][i].u + v[1][i].u;
    fout<<sol;



    return 0;
}
