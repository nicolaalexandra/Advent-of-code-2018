#include <fstream>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

long long a,b,c,i,nr,pas,ip,tip,k,ok,v[10];
char s[100];
struct op{
    int tip;
    long long a;
    long long b;
    long long c;
};
op A[10000];
void addr (long long a, long long b, long long c){
    v[c] = v[a] + v[b];
}
void addi (long long a, long long b, long long c){
    v[c] = v[a] + b;
}
void mulr (long long a, long long b, long long c){
    v[c] = v[a]*v[b];
}
void muli (long long a, long long b, long long c){
    v[c] = v[a]*b;
}

void setr (long long a, long long b, long long c){
    v[c] = v[a];
}
void seti (long long a, long long b, long long c){
    v[c] = a;
}
void gtir (long long a, long long b, long long c){
    if (a > v[b]) v[c] = 1;
    else v[c] = 0;
}
void gtri (long long a, long long b, long long c){
    if (v[a] > b) v[c] = 1;
    else v[c] = 0;
}
void gtrr (long long a, long long b, long long c){
    if (v[a] > v[b]) v[c] = 1;
    else v[c] = 0;
}
void eqir (long long a, long long b, long long c){
    if (a == v[b]) v[c] = 1;
    else v[c] = 0;
}
void eqri (long long a, long long b, long long c){
    if (v[a] == b) v[c] = 1;
    else v[c] = 0;
}
void eqrr (long long a, long long b, long long c){
    if (v[a] == v[b]) v[c] = 1;
    else v[c] = 0;
}
int main (){

    /// 0 1 2 3 4 5
    ///for (i=0;i<=5;i++) v[i] = 0;
    while (fin.getline(s,100)){
        i = 0;
        while ( !(s[i] >= '0' && s[i] <= '9') )
            i++;
        a = 0;
        while ( s[i] >= '0' && s[i] <= '9' ){
            a = a*10 + s[i] - '0';
            i++;
        }
        i++;
        b = 0;
        while ( s[i] >= '0' && s[i] <= '9' ){
            b = b*10 + s[i] - '0';
            i++;
        }
        i++;
        c = 0;
        while ( s[i] >= '0' && s[i] <= '9' ){
            c = c*10 + s[i] - '0';
            i++;
        }

        if (s[0] == 's' && s[3] == 'i'){
            tip = 1;
            //seti (a,b,c);
        }
        if (s[0] == 's' && s[3] == 'r'){
            tip = 2;
            //setr (a,b,c);
        }
        if (s[0] == 'a' && s[3] == 'i'){
            tip = 3;
          //  addi (a,b,c);
        }
        if (s[0] == 'a' && s[3] == 'r'){
            tip = 4;
        //    addr (a,b,c);
        }
        if (s[0] == 'm' && s[3] == 'i'){
            tip = 5;
            //muli (a,b,c);
        }
        if (s[0] == 'm' && s[3] == 'r'){
            tip = 6;
            //mulr (a,b,c);
        }
        if (s[0] == 'e' && s[1] == 'q'&& s[2] == 'r' && s[3] == 'i'){
            tip = 7;
            //eqri (a,b,c);
        }
        if (s[0] == 'e' && s[1] == 'q'&& s[2] == 'r' && s[3] == 'r'){
            tip = 8;
            //eqrr (a,b,c);
        }
        if (s[0] == 'e' && s[1] == 'q'&& s[2] == 'i' && s[3] == 'r'){
            tip = 9;
            //eqir (a,b,c);
        }
        if (s[0] == 'g' && s[1] == 't'&& s[2] == 'r' && s[3] == 'r'){
            tip = 10;
            //gtrr (a,b,c);
        }
        A[k].tip = tip;
        A[k].a = a;
        A[k].b = b;
        A[k].c = c;
        //fout<<A[k].tip<<" "<<A[k].a<<" "<<A[k].b<<" "<<A[k].c<<"\n";
        k++;
    }
    nr = 2; /// ip ul meu din test
    ip = 0;
    for (;;){
        pas++;
        if (ip >= k)
            break;
        v[nr] = ip;
     //   for (i=0;i<=5;i++)
       //     fout<<v[i]<<" ";
        //fout<<"\n";
        /// executam instructiunea cu numarul v[2]
        if (A[v[nr]].tip == 1){
            seti (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
        if (A[v[nr]].tip == 2){
            setr (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
        if (A[v[nr]].tip == 3){
            addi (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
        if (A[v[nr]].tip == 4){
            addr (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
        if (A[v[nr]].tip == 5){
            muli (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
        if (A[v[nr]].tip == 6){
            mulr (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
        if (A[v[nr]].tip == 7){
            eqri (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
        if (A[v[nr]].tip == 8){
            eqrr (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
        if (A[v[nr]].tip == 9){
            eqir (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
        if (A[v[nr]].tip == 10){
            gtrr (A[v[nr]].a,A[v[nr]].b,A[v[nr]].c);
            ip = v[nr]+1;
            continue;
        }
    }
   //for (i=0;i<=5;i++)
       //     fout<<v[i]<<" ";
        //fout<<"\n";
    fout<<v[0];

    return 0;
}
