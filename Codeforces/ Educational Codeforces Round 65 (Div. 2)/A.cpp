#include<bits/stdc++.h>

using namespace std;
int main(){
	string ent;
	int t, n, i;

	cin >> t;
	while(t--){
		cin >> n;
		cin >> ent;
		for(i=0;i<n;i++){
			if(ent[i]=='8'){
				break;
			}
		}
		if(n-i>=11){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}

	return 0;
}
]