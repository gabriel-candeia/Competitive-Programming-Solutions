#include<bits/stdc++.h>
#define N int(1e4)+3
using namespace std;

int main(){
	int degree[N], n, m, a, b,t;
	bool pos;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--){
		cin >> n >> m;
		while(m--){
			cin >> a >> b;
			degree[a]++;
			degree[b]++;
		}
		pos = true;
		for(int i=0;i<=n;i++){
			pos *= (degree[i]%2==0);
			degree[i] = 0;
		}
		cout << ((pos) ? "Yes" : "No") << '\n';
	}
	return 0;
}
