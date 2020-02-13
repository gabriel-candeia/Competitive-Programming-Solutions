/* --Non optimized solution --/
#include<bits/stdc++.h>
#define N 100+10
#define ll long long int

using namespace std;
int main(){
	int h, w;
	ll table[N][N];
	char grid[N][N];

	//input
	cin >> h >> w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> grid[i][j];
		}
	}

	//initial conditions
	for(int i=0;i<=w;i++){ table[h][i] = 0;}
	for(int i=0;i<=h;i++){ table[i][w] = 0;}
	table[h-1][w] = 1LL;
	
	for(int i=h-1;i>=0;i--){
		for(int j=w-1;j>=0;j--){
			table[i][j] = 0;	
			if(grid[i][j]!='#'){
				table[i][j] = (table[i+1][j]+table[i][j+1])%((long long) 1e9+7);
			}
		}
	}

	cout << table[0][0] << '\n';
	return 0;
}*/

//optimized solution
#include<bits/stdc++.h>
#define N 1000+10
#define ll long long int

using namespace std;
int main(){
	int h, w, current, last;
	ll table[2][N];
	string map;

	cin >> h >> w;

	//initial conditions
	for(int i=0;i<=w;i++){ table[0][i] = 0; table[1][i] = 0;}
	table[0][1] = 1LL;
	
	for(int i=1;i<=h;i++){
		current = i%2;
		last = (i+1)%2;
		cin >> map;
		for(int j = 1;j<=w;j++){
			table[current][j] = 0;	
			if(map[j-1]!='#'){
				table[current][j] = (table[last][j]+table[current][j-1])%((long long) 1e9+7);
			}
		}
	}

	cout << table[h%2][w] << '\n';
	return 0;
}