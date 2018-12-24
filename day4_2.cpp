#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

struct event{
    int an;
    int luna;
    int zi;
    int ora;
    int minut;
    int id;
    int tip;
};

event v[100000];

int f[10000][70],w[10000];
int i,j,maxim,maxi,nr,solid,an,luna,zi,ora,minut,val,ok,k,nrminute,rez,sum,minutt;
char s[100];
int cmp (event a, event b){
    if (a.an != b.an)
        return a.an < b.an;
    else{
        if (a.luna != b.luna)
            return a.luna < b.luna;
        else{
            if (a.zi != b.zi)
                return a.zi < b.zi;
            else{
                if (a.ora != b.ora)
                    return a.ora < b.ora;
                else{
                    if (a.minut != b.minut)
                        return a.minut < b.minut;
                    else
                        return a.tip < b.tip;
                }
            }
        }
    }
}
int main (){

    for (i=1;i<=1028;i++){
        fin>>v[i].luna>>v[i].zi>>v[i].ora>>v[i].minut>>v[i].id>>v[i].tip;
    }
    k = 1028;
    /*while (fin.getline(s,100)){
        i = 1;
        an = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            an = an*10 + s[i] - '0';
            i++;
        }
        i++, luna = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            luna = luna*10 + s[i] - '0';
            i++;
        }
        i++,zi = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            zi = zi*10 + s[i] - '0';
            i++;
        }
        i++,ora = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            ora = ora*10 + s[i] - '0';
            i++;
        }
        i++, minut = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            minut = minut*10 + s[i] - '0';
            i++;
        }


        /// verificam daca avem un nou id sau nu
        while (s[i]!=NULL && s[i] != '#')
            i++;

        k++;
        if (s[i] == '#'){
            i++;
            val = 0;
            while (s[i] >= '0' && s[i] <= '9'){
                val = val*10 + s[i] - '0';
                i++;
            }
            v[k].tip = 0;
            v[k].id = val;
        } else {
            i = 0,ok = 0;
            while (s[i] != NULL){
                if (s[i] == 'w')
                    ok = 1;
                i++;
            }
            if (ok == 0)
                v[k].tip = 1; /// falls asleep
            else
                v[k].tip = 2; /// wakes up
        }

        /// val - id

        v[k].an = an;
        v[k].luna = luna;
        v[k].zi = zi;
        v[k].ora = ora;
        v[k].minut = minut;

    }*/
    sort (v+1,v+k+1,cmp);
    //for (i=1;i<=k;i++)
      //  fout<<v[i].luna<<" "<<v[i].zi<<" "<<v[i].ora<<" "<<v[i].minut<<" "<<v[i].id<<" "<<v[i].tip<<"\n";
    maxim = val = nrminute = 0;
    for (i=1;i<=k;i++){
        if (val == 3433)
            val = 3433;
        if (v[i].tip == 0){

            /*if (nrminute > maxim){
                maxim = nrminute;
                solid = v[i].id;
            }*/
            w[val] += nrminute;
            val = v[i].id;
            nrminute = 0;
        }
        else{
            if (v[i].tip == 1){ /// adoarme
                nrminute += v[i+1].minut - v[i].minut;
                for (j=v[i].minut;j<v[i+1].minut;j++)
                    f[val][j]++;
            }
        }

    }

    for (i=1;i<=9999;i++)
        for (j=0;j<=59;j++)
            if (f[i][j] > maxim){
                maxim = f[i][j];
                solid = i;
                minutt = j;
            }
    fout<<minutt*solid;
/*    for (i=1;i<=9999;i++){
        //if (i == 3433)
          //  i = 3433;
        if (w[i] > maxim){
            maxim = w[i];
            solid = i;
        }
    }
*/
   /* for (i=1;i<=9999;i++){
        sum = 0;
        for (j=0;j<=59;j++)
            sum += f[i][j];
        if (sum > maxim){
            maxim = sum;
            solid = i;
        }
    }


    /// acum determinam minutul la care frecventa este maxima
    maxi = 0;
    for (i=0;i<=59;i++)
        if (f[solid][i] > maxi){
            maxi = f[solid][i];
            rez = i;
        }

    fout<<solid*rez;
*/


    return 0;
}

