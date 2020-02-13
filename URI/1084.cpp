#include<bits/stdc++.h>
#define N int(1e5)+10
using namespace std;

int main(){
	int n, d, temp,top = 0;
	char st[N], a;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n >> d){
		if(n==0&&d==0) break;
		top = 0;
		temp = d;
		for(int i=0;i<n;i++){
			cin >> a;
			while(top!=0 && st[top-1]<a && d!=0){ 
				top--;
				d--;
			}
			st[top++]=a;	
		}
		for(int i=0;i<n-temp;i++){
			cout << st[i];
		}
		cout << '\n';
	}
	return 0;
}
