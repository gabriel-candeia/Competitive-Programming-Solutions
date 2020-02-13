#include<bits/stdc++.h>
#define N int(1e5)+3
using namespace std;

void troca(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = *x;
}

int main(){
	int pos[N], arr[N], n, t, count;

	cin >>t;
	while(t--){
		cin >> n;
		count = 0;
		for(int i=1;i<=n;i++){
			cin >> arr[i];
			pos[arr[i]] = i;
		}
		for(int i=1;i<=n;i++){
			if(pos[i]!=i){
				count++;
				troca(&arr[pos[i]],&arr[i]);
				pos[arr[i]] = pos[i];
				pos[i] = i;
			}
		}
		cout << count << '\n';
	}

	return 0;
}
