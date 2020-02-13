#include<bits/stdc++.h>
#define N 3000+10
using namespace std;

char path[N][N];	

int main(){
	int n, m;
	string str1, str2, answ = "";
	int lcs[2][N], current, last;

	//input
	cin >> str1 >> str2;
	n = str1.size();
	m = str2.size();

	//initial conditions
	for(int i=0;i<=m;i++){
		lcs[0][i] = 0;
		lcs[1][i] = 0;
	}

	//alg
	for(int i=n-1;i>=0;i--){
		current = i%2;
		last = (i+1)%2;
		for(int j=m-1;j>=0;j--){
			if(str1[i]==str2[j]){
				lcs[current][j] = lcs[last][j+1]+1;
				path[i][j] = '=';
			}
			else{
				if(lcs[current][j+1]>lcs[last][j]){
					path[i][j] = '>';
				}
				else{
					path[i][j] = '<';	
				}
				lcs[current][j] = max(lcs[current][j+1],lcs[last][j]);
			}
		}
	}

	for(int i=0,j=0;i<n&&j<m;){
		if(path[i][j]=='='){
			answ+=str1[i];
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

	cout << answ << '\n';

	return 0;
}