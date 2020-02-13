#include<bits/stdc++.h>
#define N int(1e6)+3
using namespace std;
char s[N];

int main(){
	int q, n, k, top;

	cin >> q;
	while(q--){
		cin >> n >> k;
		scanf("%s",s);
		top = 0;
		for(int i=0;i<n && k>0;i++){
			if(s[i]=='0'){
				s[i] = s[max(i-k,top)];
				s[max(i-k,top)]='0';
				k-=i-top;
				top++;
			}
		}
		printf("%s\n",s);
	}

	return 0;
}
