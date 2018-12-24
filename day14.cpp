#include <iostream>
using namespace std;
int x,i,poz1,poz2,s,k,el,pas,r,v[100000000],w[100];
int f (int &poz){
    /// trebuie sa le deplasez
    int nr = v[poz]+1;
    nr %= k;
    poz += nr;
    if (poz > k)
        poz -= k;

}
int main (){
    //ifstream (fin, "date.in");
  //  ofstream (fout, "date.out");
    cin>>x;
    v[1] = 3;
    v[2] = 7;
    poz1 = 1, poz2 = 2; k=2;
    for (;;){
    	////cout<<k<<"\n ";
        pas++;
        if (pas == 10000000) break;
        s = v[poz1]+v[poz2];

        el = 0;
        if (s==0)
           w[++el] = 0;
        while (s != 0){
          //  r=r*10+s%10;
            w[++el] = s%10;
            s /= 10;
        }
        for(i=el;i>=1;i--)
           v[++k]=w[i];


        /// acum afam noile pozitii
        f (poz1);
        f (poz2);
      //  for (i=1;i<=k;i++)
          //  cout<<v[i]<<" ";
      //  cout<<"\n";

    /*    if (k>=x+10){
            for (i=x+1;i<=x+10;i++)
                cout<<v[i];
            break;
        } */
    }
    for (i=1;i<=k-5;i++)
        if (v[i]==9 && v[i+1]==1 && v[i+2]==9 && v[i+3]==9 && v[i+4]==0 && v[i+5]==1){
            cout<<i-1;
            return 0;
        }


    return 0;
}
