#include <fstream>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int i,j,n,x,maxim,soli,solj,val,si,s[302][302];
int f (int i, int j){
    int nr = 0;
    nr = i + 10;
    nr *= j;
    nr += x;
    nr *= (i+10);
    nr = (nr/100) % 10;
    nr -= 5;
    return nr;
}
int main (){

    fin>>x;
    for (i=1;i<=300;i++)
        for (j=1;j<=300;j++){
            /*val = f(i,j)+f(i,j+1)+f(i,j+2)+f(i+1,j)+f(i+1,j+1)+f(i+1,j+2);
            val += f(i+2,j)+f(i+2,j+1)+f(i+2,j+2);
            if (val > maxim){
                maxim = val;
                soli = i;
                solj = j;
            }*/
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + f(i,j);
        }


    maxim = -2000000000;
    for (i=1;i<=300;i++)
        for (j=1;j<=300;j++)
            for (int k=1;k<=min(300-i+1,300-j+1);k++){ /// dim
                val = s[i+k-1][j+k-1] - s[i+k-1][j-1] - s[i-1][j+k-1] + s[i-1][j-1];
                if (val > maxim){
                    maxim = val;
                    soli = i;
                    solj = j;
                    si = k;
                }
            }

    fout<<soli<<","<<solj<<","<<si;


    return 0;
}
