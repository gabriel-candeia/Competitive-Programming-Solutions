#include<bits/stdc++.h>
#define N int(5e6)+3
using namespace std;

int t, n, arr[N];
int ending[N], answ = 0;

int main(){	
	int count=0;
	char a;	

	cin >> t;
	while(t--){
		count++;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a;
			arr[i] = a-'0';
			ending[i+1]=0;
		}
		ending[0]=arr[0];
		for(int i=1;i<n;i++){
			ending[i] = ending[i-1]+arr[i];
		}
		answ = 0;
		for(int i=0;i<=n/2;i++){
			answ = max(answ,ending[i+n/2-(n%2==0)]-ending[i]+arr[i]);
		}
		printf("Case #%d: %d\n",count,answ);
	}
	return 0;
}

