#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[510][510];

int main(){
	cin >> n >> m;
	int ans = 0, flag = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	if(n<=2 && m<=2){
		cout << 0 << "\n";
	}
	else if(n<=2){
		if(n==1)
			for(int i=1;i<m-1;i++)
				mat[1][i]=='.';
		for(int i=1;i<m-1;i++){
			ans += (mat[0][i]=='.' && mat[1][i]=='.');
		}
		cout << ans <<"\n";
	}
	else if(m<=2){
		if(m==1)
			for(int i=1;i<n-1;i++)
				mat[i][1]=='.';
		for(int i=1;i<n-1;i++){
			ans += (mat[i][0]=='.' && mat[i][1]=='.');
		}
		cout << ans <<"\n";
	}
	else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mat[i][j] == '.' && ((i > 0 && i < n-1) && (j > 0 && j < m-1))){
					++ans;
				}else if(mat[i][j] == '#' && (i == 0 || i == n-1 || j == 0 || j == m-1)){
					flag = 1;
				}
			}
		}
		cout << ans + (1-flag) << "\n";
	}

	return 0;
}