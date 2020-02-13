#include<bits/stdc++.h>
using namespace std;
#define N 100

void retrieve_string(char mat[N][N],int x, int y,int n, char s[502]){
	s[0] = mat[x][y];
	for(int i=1;i<=n;i++){
		switch (s[i]){
			case 'E':
				y++;
				break;	
			case 'W':
				y--;
				break;
			case 'S':
				x++;
				break;
			default:
				x--;
		}
		s[i]=mat[x][y];
	}
}

int lcs_dp(string s1, string s2, int n1, int n2){
	int memo[502][502];
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			memo[i][j] = 0;
		}
	}
	for(int i=n1-1;i>=0;i--){
		for(int j=n2-1;j>=0;j--){
			if(s1[i]==s2[j]){
				memo[i][j] = memo[i+1][j+1] + 1;
			}
			else{
				memo[i][j] = max(memo[i][j+1],memo[i+1][j]);
			}
		}
	}
	return memo[0][0];
}

int main(){
	char mat[N][N];
	int rem, t, count = 0;
	int x, y, n1, n2;
	int h, w;
	char s1[502], s2[502];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--){
		count++;
		cin >> h >> w;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin >> mat[i][j];
			}
		}

		cin >> n1 >> x >> y;
		for(int i=1;i<=n1;i++){ cin >> s1[i];}
		retrieve_string(mat,x-1,y-1,n1,s1);

		cin >> n2 >> x >> y;
		for(int i=1;i<=n2;i++){ cin >> s2[i];}
		retrieve_string(mat,x-1,y-1,n2,s2);
		n1++; n2++;

		rem = lcs_dp(s1,s2,n1,n2);
		printf("Case %d: %d %d\n",count,n1-rem,n2-rem);
	}

	return 0;
}
