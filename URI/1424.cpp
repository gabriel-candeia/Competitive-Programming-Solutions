#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> num;

int main(){
	int n, m, a, b;

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while(cin >> n >> m){
		num.clear();
		for(int i=1;i<=n;i++){
			cin >> a;
			num[a].push_back(i);
		}
		for(int i=0;i<m;i++){
			cin >> b >> a;
			if(num[a].size()>=b){
				cout << num[a][b-1] << '\n';
			}
			else{
				cout << "0\n";
			}
		}
	}
	return 0;
}
