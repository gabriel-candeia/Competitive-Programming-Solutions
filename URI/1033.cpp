#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	int count=0;
	ll n, b, x=1, y=1, z=1;

	while(cin >> n >> b && b){
		count++;
		x=1, y=1, z=1;
		for(int i=2;i<=n;i++){
			z = (x+y+1)%b;
			x = y;
			y = z;
		}
		printf("Case %d: %lld %lld %lld\n",count,n,b,z);
	}
	return 0;
}
