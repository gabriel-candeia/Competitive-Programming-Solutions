 #include<bits/stdc++.h>
using namespace std;
#define N 21
char mat[N*N];
int h, w;
int xa, ya, na, xb, yb, nb;
string sa, sb;

int next(int a, char dir){
	return a + ((dir=='N') ? -w : ((dir=='S') ? w : ((dir=='E') ? +1 : -1)));
}

int lcs(int a, int b, int i, int j){
	if(i==na || j==nb){
		return 0;
	}
	if(mat[a]==mat[b]){
		return lcs(next(a,sa[i]),next(b,sb[j]),i+1,j+1)+1;
	}
	return max(lcs(next(a,sa[i]),b,i+1,j),lcs(a,next(b,sb[j]),i,j+1));
}

int lcs_(int ia, int ib){
	int memo[N*N][N*N][2][2];
	for(int i=0;i<=h*w;i++){
		for(int j=0;j<=h*w;j++){
			memo[i][j][0][0] = 0;
			memo[i][j][0][1] = 0;
			memo[i][j][1][0] = 0;
			memo[i][j][1][1] = 0;
		}
	}
	for(int i=na-1;i>=0;i--){
		for(int j=nb-1;j>=0;j--){
			for(int a=0;a < h*w;a++){
				for(int b=0; b < h*w;b++){
					if(mat[a]==mat[b]){
						memo[a][b][i%2][j%2] = memo[next(a,sa[i])][next(b,sb[j])][(i+1)%2][(j+1)%2]+1;
					}
					else{
						memo[a][b][i%2][j%2] = max(memo[next(a,sa[i])][b][(i+1)%2][j%2],memo[a][next(b,sb[j])][i%2][(j+1)%2]);	
					}
				}	
			}
		}
	}
	return memo[ia][ib][(na+1)%2][(nb+1)%2];
}

int main(){
	int rem, t, count = 0;
	cin >> t;
	while(t--){
		count++;
		cin >> h >> w;
		for(int i=0;i<h*w;i++){
			cin >> mat[i];
		}
		for(int i=0;i<h*w;i++){

		}
		cin >> na >> xa >> ya >> sa;
		cin >> nb >> xb >> yb >> sb; 

		rem = lcs_((xa-1)*(ya-1),(xb-1)*(yb-1));
		printf("Case %d: %d %d\n",count,na-rem,nb-rem);
	}

	return 0;
}
