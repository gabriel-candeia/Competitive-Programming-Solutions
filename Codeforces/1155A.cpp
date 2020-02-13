#include<iostream>
#include<string>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string ent;
	cin >> n >> ent;

	for(int i=0;i<n-1;i++){
		if(ent[i]>ent[i+1]){
			cout << "YES\n";
			cout << i+1 << ' ' << i+2 << '\n';
			return 0;
		}
	}
	cout << "NO\n";


	return 0;
}