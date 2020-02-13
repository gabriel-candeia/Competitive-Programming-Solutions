#include<bits/stdc++.h>
#define N int(1e3)+10
using namespace std;

int lcs[N][N];
char path[N][N];

int main(){
	int n, m;
	string s1, s2;

	cin >> s1 >> s2;
	n = s1.size();
	m = s2.size();

	for(int i=0;i<=m;i++){
		lcs[i][n] = 0;
	}
	for(int j=0;j<=n;j++){
		lcs[m][j] = 0;
	}

	for(int i=m;i>=0;i--){
		for(int j=n;j>=0;j--){
			if(s2[i]==s1[j]){
				path[i][j] = '=';
				lcs[i][j] = lcs[i+1][j+1]+1;
			}
			else if(lcs[i+1][j] > lcs[i][j+1]){
				path[i][j] = 'v';
				lcs[i][j] = lcs[i+1][j];
			}
			else{
				path[i][j] = '>';
				lcs[i][j] = lcs[i][j+1];
			}
		}		
	}
	
	int cont = 0, i=0, j=0;
	for(;i<m&&j<n;){
		cont++;
		if(path[i][j]=='='){
			i++;
			j++;
		}
		else if(path[i][j]=='>'){
			j++;
		}
		else{
			i++;
		}
	}

	cout << cont + m-i + n-j << '\n';

	return 0;
}
