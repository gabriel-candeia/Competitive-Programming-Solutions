#include<bits/stdc++.h>
#define N int(1e4)+3
using namespace std;
int parent[N], rnk[N];

int find(int x){
	if(parent[x]!=x){
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(rnk[x]>rnk[y]){
		parent[x] = y;
		rnk[y]+=rnk[x];
	}
	else{
		parent[y] = x;
		rnk[x]+=rnk[y];	
	}
}

int main(){
	int n, m, q, a, b;
	bool first = true;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n >> m >> q){
		if(!first){
			cout << '\n';
		}
		for(int i=0;i<n;i++){
			parent[i] = i;
			rnk[i] = 0;
		}
		for(int i=0;i<m;i++){
			cin >> a >> b;
			merge(a-1,b-1);
		}
		for(int i=0;i<q;i++){
			cin >> a >> b;
			cout << (find(a-1)==find(b-1) ? "S" : "N") << '\n';
		}
		first = false;
	}

	return 0;
}
