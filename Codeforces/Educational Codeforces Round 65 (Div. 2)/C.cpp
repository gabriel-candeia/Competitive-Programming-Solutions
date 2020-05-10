#include<bits/stdc++.h>
#define N 500100

int parent[N];

void make_set(int v){ parent[v] = v; }

int find(int v){
	int temp = v;
	int next;
	while(parent[v]!=v){
		v = parent[v];
	}

	while(parent[temp]!=temp){
		next = parent[temp];
		parent[temp] = v;
		temp = next;
	}

	return v;
}

void set_union(int a, int b){
	a = find(a);
	b = find(b);
	parent[b] = a;
}

using namespace std;
int main(){
	int n, m, k, rep, x;
	int target, acm[N];

	cin >> n >> m;	
	for(int i=0;i<n;i++){
		parent[i] = -1;
		acm[i] = 0;
	}


	while(m--){
		cin >> k;
		if(k){
			k--;
			cin >> rep;
			rep--;
			if(parent[rep]==-1){ make_set(rep);}
			while(k--){
				cin >> x;
				x--;
				if(parent[x]==-1){ make_set(x);}
				set_union(rep,x);
			}
		}
	}


	for(int i=0;i<n;i++){
		if(parent[i]!=-1){
			find(i);
			acm[parent[i]]++;	
		}
	}

	for(int i=0;i<n;i++){
		if(parent[i]!=-1){
			cout << acm[parent[i]] << ' ';
		}
		else{
			cout << 1 << ' ';
		}
	}
	cout << '\n';

	return 0;

}
