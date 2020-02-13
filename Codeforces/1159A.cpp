#include<bits/stdc++.h>
#define N 110
using namespace std;

int main(){
	int n, menor=0, start=0;
	char s[N];

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s[i];
		start += ((s[i]=='+') ? 1 : -1);
		if(start<menor){
			menor = start;
		}
	}
	start = abs(menor);

	for(int i=0;i<n;i++){
		start += ((s[i]=='+') ? 1 : -1);
	}

	cout << start << '\n';

	return 0;
}