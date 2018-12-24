#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
char s[27][50003],c;
int i,x,y,j,k,modif,lmin=50003;
bool polar(char a,char b){
    if(a-b==32 || b-a==32)
        return 1;
    return 0;
}
void reactioneaza(int i){
    int x,y;
    modif=1;
    while(modif){
        modif=0;
        for(x=1; s[i][x]!=0; x++){
            while(polar(s[i][x-1],s[i][x])){
                modif=1;
                for(int y=x-1; s[i][y+1]!=0; y++)
                    s[i][y]=s[i][y+2];
            }
        }
    }
    if(strlen(s[i])<lmin)lmin=strlen(s[i]);
}
int main(){

    fin.getline(s[26], 50003);
     for(i=0; i<=25; i++){
         c=i+'a';
         k=0;
         for(j=0; s[26][j]!=0; j++){
             if(s[26][j]!=c && s[26][j]!=c-32)
                 s[i][k++]=s[26][j];
         }
         reactioneaza(i);
     }
    fout<<lmin;
    return 0;
}
