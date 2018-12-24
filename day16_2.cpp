#include <fstream>
#include <set>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[100];
int v[5],d[5],f[5];
int t,nr1,nr2,nr3,nr4,i,x,ap,sol,a,b,c,val;
int A[] = {7,3,4,5,11,8,0,15,9,1,14,13,6,12,2,10};
set <int> L[20];
void addr (int a, int b, int c){
    v[c] = v[a] + v[b];
}
void addi (int a, int b, int c){
    v[c] = v[a] + b;
}
void mulr (int a, int b, int c){
    v[c] = v[a]*v[b];
}
void muli (int a, int b, int c){
    v[c] = v[a]*b;
}
void banr (int a, int b, int c){
    v[c] = (v[a] & v[b]);
}
void bani (int a, int b, int c){
    v[c] = (v[a] & b);
}
void borr (int a, int b, int c){
    v[c] = (v[a] | v[b]);
}
void bori (int a, int b, int c){
    v[c] = (v[a] | b);
}
void setr (int a, int b, int c){
    v[c] = v[a];
}
void seti (int a, int b, int c){
    v[c] = a;
}
void gtir (int a, int b, int c){
    if (a > v[b]) v[c] = 1;
    else v[c] = 0;
}
void gtri (int a, int b, int c){
    if (v[a] > b) v[c] = 1;
    else v[c] = 0;
}
void gtrr (int a, int b, int c){
    if (v[a] > v[b]) v[c] = 1;
    else v[c] = 0;
}
void eqir (int a, int b, int c){
    if (a == v[b]) v[c] = 1;
    else v[c] = 0;
}
void eqri (int a, int b, int c){
    if (v[a] == b) v[c] = 1;
    else v[c] = 0;
}
void eqrr (int a, int b, int c){
    if (v[a] == v[b]) v[c] = 1;
    else v[c] = 0;
}


void citeste (){
    int i = 0;
    while ( !(s[i] >= '0' && s[i] <= '9') )
        i++;
    nr1 = 0;
    while (s[i] >= '0' && s[i] <= '9'){
        nr1 = nr1*10 + s[i] - '0';
        i++;
    }
    while ( !(s[i] >= '0' && s[i] <= '9') )
        i++;
    nr2 = 0;
    while (s[i] >= '0' && s[i] <= '9'){
        nr2 = nr2*10 + s[i] - '0';
        i++;
    }
    while ( !(s[i] >= '0' && s[i] <= '9') )
        i++;
    nr3 = 0;
    while (s[i] >= '0' && s[i] <= '9'){
        nr3 = nr3*10 + s[i] - '0';
        i++;
    }
    while ( !(s[i] >= '0' && s[i] <= '9') )
        i++;
    nr4 = 0;
    while (s[i] >= '0' && s[i] <= '9'){
        nr4 = nr4*10 + s[i] - '0';
        i++;
    }

}

int main (){

    /*for (t=1;t<=815;t++){
        fin.getline (s,100);
        nr1 = nr2 = nr3 = nr4 = 0;
        citeste ();
        d[0] = nr1, d[1] = nr2, d[2] = nr3, d[3] = nr4; /// initial

        for (i=1;i<=4;i++){
            fin>>x;
            if (i == 1) val = x;
            if (i == 2) a = x;
            if (i == 3) b = x;
            if (i == 4) c = x;
        }
        fin.get();
        fin.getline (s,100);
        nr1 = nr2 = nr3 = nr4 = 0;
        citeste ();
        f[0] = nr1, f[1] = nr2, f[2] = nr3, f[3] = nr4; /// final
        /// vedem ce rezultat obtinem pentru fiecare instructiune
        ap = 0;
        for (i=1;i<=16;i++){
            v[0] = d[0],v[1] = d[1],v[2] = d[2],v[3] = d[3];
            if (i == 1) addr (a,b,c);
            if (i == 2) addi (a,b,c);
            if (i == 3) mulr (a,b,c);
            if (i == 4) muli (a,b,c);
            if (i == 5) banr (a,b,c);
            if (i == 6) bani (a,b,c);
            if (i == 7) borr (a,b,c);
            if (i == 8) bori (a,b,c);
            if (i == 9) setr (a,b,c);
            if (i == 10) seti (a,b,c);
            if (i == 11) gtri (a,b,c);
            if (i == 12) gtir (a,b,c);
            if (i == 13) gtrr (a,b,c);
            if (i == 14) eqri (a,b,c);
            if (i == 15) eqrr (a,b,c);
            if (i == 16) eqir (a,b,c);

            if (v[0]==f[0] && v[1]==f[1] && v[2]==f[2] && v[3]==f[3]){
                ap++;
                L[val].insert (i-1);
            }
        }

        if (ap >= 3)
            sol++;
        fin.get();
    }
    fout<<sol;*/

  /*  for (i=0;i<=15;i++){
        for (set<int> :: iterator it=L[i].begin();it!=L[i].end();it++)
            fout<<*it<<" ";
        fout<<"\n";
    }
*/

    //for (i=0;i<15;i++)
      //  fout<<A[i]<<"\n";
    v[0] = v[1] = v[2] = v[3] = 0;
    while (fin>>val){
        fin>>a>>b>>c;
        x = A[val];
        if (x == 0) addr (a,b,c);
        if (x == 1) addi (a,b,c);
        if (x == 2) mulr (a,b,c);
        if (x == 3) muli (a,b,c);
        if (x == 4) banr (a,b,c);
        if (x == 5) bani (a,b,c);
        if (x == 6) borr (a,b,c);
        if (x == 7) bori (a,b,c);
        if (x == 8) setr (a,b,c);
        if (x == 9) seti (a,b,c);
        if (x == 10) gtri (a,b,c);
        if (x == 11) gtir (a,b,c);
        if (x == 12) gtrr (a,b,c);
        if (x == 13) eqri (a,b,c);
        if (x == 14) eqrr (a,b,c);
        if (x == 15) eqir (a,b,c);
    }
    fout<<v[0];

    return 0;
}
