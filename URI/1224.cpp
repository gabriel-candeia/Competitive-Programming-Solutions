#include<bits/stdc++.h>
#define N int(1e4)+3
#define ll long long int
#define MIN 0
using namespace std;

ll jogo(int arr[N],int l, int r, bool id){
	if(l>r){
		return 0;
	}
	if(id==1){
		return max(jogo(arr,l+1,r,0)+arr[l],jogo(arr,l,r-1,0)+arr[r]);
	}
	return min(jogo(arr,l+1,r,1),jogo(arr,l,r-1,1));
}

ll jogo1(int arr[N],int n){
	ll memo[1000][1000], moves;
	bool current = true, last;
	for(int l=0;l<=n;l++){
		for(int r=0;r<=n;r++){
			memo[l][r] = 0;
		}
	}
	for(int l=n;l;l--){
		for(int r=1;r<=n;r++){
			moves = l + n-r;
			if(l>r){
				memo[l][r] = 0;
			}
			else if(moves%2==1){
				memo[l][r] = max(memo[l+1][r]+arr[l],memo[l][r-1]+arr[r]);
			}
			else{
				memo[l][r] = min(memo[l+1][r],memo[l][r-1]);
			}
		}
	}
	return memo[1][n];
}

ll jogo2(int arr[N],int n){
	ll memo[2][N], moves;
	bool current = true, last;
	for(int r=0;r<=n;r++){
		memo[0][r] = 0;
		memo[1][r] = 0;
	}
	for(int l=n;l;l--){
		current = l%2;
		last = !current;
		for(int r=1;r<=n;r++){
			moves = l + n-r;
			if(l>r){
				memo[current][r] = 0;
			}
			else if(moves%2==1){
				memo[current][r] = max(memo[last][r]+arr[l],memo[current][r-1]+arr[r]);
			}
			else{
				memo[current][r] = min(memo[last][r],memo[current][r-1]);
			}
		}
	}
	return memo[current][n];
}

int main(){
	int n, arr[N];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n){
		for(int i=1;i<=n;i++){
			cin >> arr[i];
		}
		cout << jogo2(arr,n) << '\n'; 
	}
	return 0;
}
