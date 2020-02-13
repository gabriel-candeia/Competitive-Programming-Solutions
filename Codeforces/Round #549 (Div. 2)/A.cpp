#include<bits/stdc++.h>
#define N 200100

using namespace std;

int main(){
	int n;
	int doors[N];	
	int last;
	int i;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> doors[i];
	}

	last = doors[n-1];
	i = n-1;
	while(doors[i]==last){
		i--;
	}

	cout << i+1 << endl;
	return 0;
}
