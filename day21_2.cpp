#include <fstream>
#include <map>
#define DIM 31
using namespace std;
long long w[6],a,b,c,ip,nr,last;
struct st{
    int tip;
    int a;
    int b;
    int c;
};
st v[100];
char s[100];
int i,k;
map <int,int> d;
ifstream fin ("a.in");
ofstream fout ("a.out");

void addr(int i){
    w[v[i].c]=w[v[i].a]+w[v[i].b];
}
void addi(int i){
    //printf ("a");
    w[v[i].c]=w[v[i].a]+v[i].b;
}
void mulr(int i){
    w[v[i].c]=w[v[i].a]*w[v[i].b];
}
void muli(int i){
    w[v[i].c]=w[v[i].a]*v[i].b;
}
void banr(int i){
    w[v[i].c]=(w[v[i].a]&w[v[i].b]);
}
void bani(int i){
    w[v[i].c]=(w[v[i].a]&v[i].b);
}
void borr(int i){
    w[v[i].c]=(w[v[i].a]|w[v[i].b]);
}
void bori(int i){
    w[v[i].c]=(w[v[i].a]|v[i].b);
}
void setr(int i){
    w[v[i].c]=w[v[i].a];
}
void seti(int i){
    w[v[i].c]=v[i].a;
}
void gtir(int i){
    w[v[i].c]=(v[i].a>w[v[i].b]);
}
void gtri(int i){
    w[v[i].c]=(w[v[i].a]>v[i].b);
}
void gtrr(int i){
    w[v[i].c]=(w[v[i].a]>w[v[i].b]);
}
void eqir(int i){
    w[v[i].c]=(v[i].a==w[v[i].b]);
}
void eqri(int i){
    w[v[i].c]=(w[v[i].a]==v[i].b);
}
void eqrr(int i){
    w[v[i].c]=(w[v[i].a]==w[v[i].b]);
}
int main(){

    while (fin.getline(s+1,100)){
        i = 1;
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
        if (s[1] == 'a' && s[4]=='r')
            v[k].tip=0;
        else if (s[1]=='a' && s[4]=='i')
            v[k].tip=1;
        else if (s[1]=='m' && s[4]=='r')
            v[k].tip=2;
        else if (s[1]=='m' && s[4]=='i')
            v[k].tip=3;
        else if (s[1]=='b' && s[2]=='a' && s[4]=='r')
            v[k].tip=4;
        else if (s[1]=='b' && s[2]=='a' && s[4]=='i')
            v[k].tip=5;
        else if (s[1]=='b' && s[2]=='o' && s[4]=='r')
            v[k].tip=6;
        else if (s[1]=='b' && s[2]=='o' && s[4]=='i')
            v[k].tip=7;
        else
            if (s[1]=='s' && s[4]=='r')
                v[k].tip=8;
        else if (s[1]=='s' && s[4]=='i')
            v[k].tip=9;
        else if (s[1]=='g' && s[3]=='i' && s[4]=='r')
            v[k].tip=10;
        else if (s[1]=='g' && s[3]=='r' && s[4]=='i')
            v[k].tip=11;
        else if (s[1]=='g' && s[3]=='r' && s[4]=='r')
            v[k].tip=12;
        else if (s[1]=='e' && s[3]=='i' && s[4]=='r')
            v[k].tip=13;
        else if (s[1]=='e' && s[3]=='r' && s[4]=='i')
            v[k].tip=14;
        else if (s[1]=='e' && s[3]=='r' && s[4]=='r')
            v[k].tip=15;
        v[k].a=a, v[k].b=b, v[k].c=c;
        k++;
    }

    //for (i=0;i<=0;i++){
    ip = 0, nr = 2;
    long long pas = 0;
    while (ip<DIM){
        //op++;
        /// executa instructiunea ip
        w[nr]=ip;
        if (v[ip].tip==0)
            addr(ip);
        else if (v[ip].tip==1)
            addi(ip);
        else if (v[ip].tip==2)
            mulr(ip);
        else if (v[ip].tip==3)
            muli(ip);
        else if (v[ip].tip==4)
            banr(ip);
        else if (v[ip].tip==5)
            bani(ip);
        else if (v[ip].tip==6)
            borr(ip);
        else if (v[ip].tip==7)
            bori(ip);
        else if (v[ip].tip==8)
            setr(ip);
        else if (v[ip].tip==9)
            seti(ip);
        else if (v[ip].tip==10)
            gtir(ip);
        else if (v[ip].tip==11)
            gtri(ip);
        else if (v[ip].tip==12)
            gtrr(ip);
        else if (v[ip].tip==13)
            eqir(ip);
        else if (v[ip].tip==14)
            eqri(ip);
        else if (v[ip].tip==15)
            eqrr(ip);

        ip=w[nr]+1;
        if (ip == 28){
            break;
            /// vedem daca s a mai repetat
            if (d[w[3]] == 0)
                d[w[3]] = 1;
            else {
                fout<<last;
                break;
            }
            last = w[3];
            //op++;
            //if (op == 100)
              //  break;
        }

    }
    //fout<<w[0];
    return 0;
}

