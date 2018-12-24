#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char a[300][10000];
struct punct {
    int x;
    int y;
    int tip;
    int fr;
};
punct v[1000000];
int n,k,i,j,x,y,el,pas,ap,solx,soly,F[1000000];
vector <int> d;
int f (int x, int y){
    if (a[x][y] == '+'){
        v[i].fr++;
        if (v[i].fr % 3 == 1){ /// face la stanga
            if (v[i].tip == 1) v[i].tip = 4;
            else
                if (v[i].tip == 2) v[i].tip = 3;
                else
                    if (v[i].tip == 3) v[i].tip = 1;
                    else v[i].tip = 2;
        } else{
            if (v[i].fr % 3 == 0){ /// face la dreapta
                if (v[i].tip == 1) v[i].tip = 3;
                else
                    if (v[i].tip == 2) v[i].tip = 4;
                    else
                        if (v[i].tip == 3) v[i].tip = 2;
                        else v[i].tip = 1;
            }
        }
    }

    if (a[x][y] == '/'){
        if (v[i].tip == 1) v[i].tip = 4;
        else{
            if (v[i].tip == 2) v[i].tip = 3;
            else
                if (v[i].tip == 3) v[i].tip = 2;
                else  v[i].tip = 1;
        }
    }

    if (a[x][y] == '\\' ){
        if (v[i].tip == 1) v[i].tip = 3;
        else {
            if (v[i].tip == 2) v[i].tip = 4;
            else
                if (v[i].tip == 3) v[i].tip = 1;
                else v[i].tip = 2;
        }
    }

}
int verif (int i,int j){
    int x = v[i].x;
    int y = v[i].y;
    if (v[i].tip == 1) y--;
    else{
        if (v[i].tip == 2) y++;
        else
            if (v[i].tip == 3) x--;
            else x++;
    }

    int X = v[j].x, Y = v[j].y;
    if (v[j].tip == 1) Y--;
    else{
        if (v[j].tip == 2) Y++;
        else
            if (v[j].tip == 3) X--;
            else X++;
    }

    if (x==v[j].x && y==v[j].y && X==v[i].x && Y==v[i].y)
        return 1;
    return 0;
}
int cmp (punct a, punct b){
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int main (){

    while (fin.getline(a[++n],10000)){
        //fout<<a[n]<<"\n";
        for (i=0;a[n][i]!=NULL;i++){
            if (a[n][i] == '<'){ /// 1
                v[++k].x = n;
                v[k].y = i;
                v[k].tip = 1;
            }
            if (a[n][i] == '>'){ /// 2
                v[++k].x = n;
                v[k].y = i; /// coordonatele
                v[k].tip = 2;
            }
            if (a[n][i] == '^'){ /// 3
                v[++k].x = n;
                v[k].y = i;
                v[k].tip = 3;
            }
            if (a[n][i] == 'v'){ /// 4
                v[++k].x = n;
                v[k].y = i;
                v[k].tip = 4;
            }
        }
    }

    /// acum le deplasam pe toate
    for (;;){
        pas++;
        sort (v+1,v+k+1,cmp);
        d.clear();
        for (i=1;i<=k;i++){
    //        if (F[i])
      //          continue;
            x = v[i].x;
            y = v[i].y;
            /// sunt la o pozitie data;
            /// daca intalnesc ceva schi,b sensul
            f (x,y);
            /// am schimbat practic tipul acum trebuie sa vad pentru
            /// urmatorul pas urm pozitii

            if (v[i].tip == 1) y--;
            else{
                if (v[i].tip == 2) y++;
                else
                    if (v[i].tip == 3) x--;
                    else x++;
            }
            v[i].x = x;
            v[i].y = y;
            /// acum putem verifica daca a dat peste una
            for (j=1;j<=k;j++){
                if (i == j)
                    continue;
                if (v[i].x == v[j].x && v[i].y == v[j].y){
                    //v[i].x = v[j].x = -1;
                    d.push_back (i);
                    d.push_back (j);
                }
            }
        }
        /// le am deplasat pe tpate cu o pozitie
        /// acum vedem daca se intersecteaza



        /*for (i=1;i<k;i++)
            for (j=i+1;j<=k;j++)
                if (v[i].x == v[j].x && v[i].y == v[j].y){
                    d.push_back (i);
                    d.push_back (j);
                }
        for (i=1;i<k;i++)
            for (j=i+1;j<=k;j++)
                if (verif(i,j)){ /// le pun pe alea adiacente
                    //v[i].x = v[i].y = -1;
                    //v[j].x = v[j].y = -1;
                    d.push_back (i);
                    d.push_back (j);
                }*/
        for (i=0;i<d.size();i++)
            v[d[i]].x = -1;
        el = 0;
        for (i=1;i<=k;i++)
            if (v[i].x != -1)
                v[++el] = v[i];
        k = el;

        /// elimin dublurile
/*
        el = 0;
        v[k+1].x = v[k+1].y = 0;
        for (i=1;i<=k;i++)
            if ( !(v[i].x == v[i-1].x && v[i].y == v[i-1].y) && !(v[i].x == v[i+1].x && v[i].y == v[i+1].y))
                v[++el] = v[i];
        /// acum vedem daca sunt adiacente
        k = el;

*/


        if (k == 1){
            fout<<v[1].y<<" "<<v[1].x-1;
            return 0;
        }
        /*for (i=1;i<k;i++){
            for (j=i+1;j<=k;j++)
                if (F[i] == 0 && F[j] == 0)
                if ((v[i].x==v[j].x && v[i].y==v[j].y) || verif(i,j)){
                    F[i] = F[j] = 1;
                    //v[i].x = v[i].y = v[j].x = v[j].y = 0;
                }

        }

        ap = 0;
        for (i=1;i<=k;i++)
            if (F[i] == 0){
                ap++;
                solx = v[i].y;
                soly = v[i].x-1;
            }

        if (ap == 1){
            fout<<solx<<","<<soly;
            return 0;
        }
        fout<<ap<<"\n";*/
    }

    return 0;
}
