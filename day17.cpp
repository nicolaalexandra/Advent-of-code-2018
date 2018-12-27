#include <fstream>
#define DIM 10000
#define INF 2000000000
using namespace std;

int a[DIM][DIM];
int minj = INF, maxj = -INF;
int a1,b1,b2,sol,ok,i,j;
char c,x;
int main(){
    ifstream fin ("date.in");
    ofstream fout ("date.out");
	while(fin>>x) {
		fin>>c>>a1>>c>>c>>c>>b1>>c>>c>>b2;
		if(x == 'y') {
			minj = min(minj, a1);
			maxj = max(maxj, a1);
		}
		for(i=b1;i<=b2;i++) {
			if(x == 'x') {
				a[a1][i] = 1;
				minj = min(minj, i);
				maxj = max(maxj, i);
			} else
				a[i][a1] = 1;
		}
	}

	i = 500, j = ok = 0;

	for (;;) {

		if(ok)
			i = 500, j = ok = 0;
		while(j <= maxj-1 && a[i][j+1] == 0)
            j++;
		if(j == maxj) {
			a[i][j] = 3;
			sol++, ok = 1;
			continue;
		} else
            if (j < minj)
                break;

		/// orizontal
		if(a[i-1][j] == 0) {
			while((a[i][j+1] == 1 || a[i][j+1] == 2) && a[i-1][j] == 0)
                i--;
		} else {
            if(a[i+1][j] == 0)
                while((a[i][j+1] == 1 || a[i][j+1] == 2) && a[i+1][j]==0)
					i++;
		}
		if(a[i][j+1] != 0) {
			ok = 1;
			if(a[i-1][j]==3 || a[i][j+1]==3 || a[i+1][j]==3) {
				a[i][j] = 3;
				int x = i;
				while(a[x+1][j] == 2) {
					a[x+1][j] = 3;
					x++;
				}
				x = i;
				while(a[x-1][j] == 2) {
					a[x-1][j] = 3;
					x--;
				}
			} else a[i][j] = 2;

			sol++;
		}
	}
	/// part 1
	fout<<sol<<"\n";

	sol = 0;
	for(int i=0;i<DIM;i++) {
		for(int j=0;j<DIM;j++) {
			if(a[i][j] == 2)
                sol++;
		}
	}
	/// part 2
	fout<<sol;

	return 0;
}
