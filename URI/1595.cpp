#include<bits/stdc++.h>
using namespace std;
#define N int(1e5)+3

int main(){
	int t, s, c, r, v[N];
	double acm;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--){
		cin >> s >> c >> r;
		for(int i=0;i<s;i++){
			cin >> v[i];
		}
		sort(v,v+s);
		for(int i=0;i<c;i++){ v[i]+=r;}
		acm = 0;
		for(int i=0;i<s;i++){
			acm+= 1.0/v[i];
		}
		printf("%.2lf\n",acm);
	}

	return 0;
}
