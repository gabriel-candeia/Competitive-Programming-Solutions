#include<bits/stdc++.h>
#define N int(3e5)+3
using namespace std;


int main(){
	int t, t1, t2, i, j;
	int even[N], odd[N];
	string s;

	cin >> t;
	while(t--){
		cin >> s;
		t1 = 0; t2 = 0;
		for(i=0;i<s.length();i++){
			if(s[i]%2){
				odd[t2++] = s[i]-'0';
			}
			else{
				even[t1++] = s[i]-'0';	
			}
		}
		for(i=0, j=0;i<t1 && j<t2;){
			if(odd[j]<even[i]){
				cout << odd[j++];
			}
			else{
				cout << even[i++];
			}
		}
		while(i<t1){
			cout << even[i++];
		}
		while(j<t2){
			cout << odd[j++];
		}
		cout << '\n';
	}

	return 0;
}