#include<bits/stdc++.h>
#define N int(1e5)+10
#define ll long long int
using namespace std;

int main(){
	bool lines[N], columns[N];
	ll n, m, l, c, x, y;
	ll total;

	cin >> n >> m;
	for(int i = 0;i<n;i++){
		lines[i] = false; 
		columns[i] = false;
	}

	total = n*n;
	l = n; c = n;

	while(m--){
		cin >> x >> y;
		if(!lines[x-1]&&!columns[y-1]){
			total = total - l - c + 1;
			lines[x-1] = true;
			columns[y-1] = true;
			l--;
			c--;
		}
		else if(!lines[x-1]){
			total = total-l;
			lines[x-1] = true;
			c--;
		}
		else if(!columns[y-1]){
			total = total-c;
			columns[y-1] = true;
			l--;
		}
		cout << total << ' ';
	}
	cout << '\n';
	return 0;
}