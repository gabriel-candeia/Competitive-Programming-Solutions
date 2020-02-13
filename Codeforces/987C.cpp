#include<iostream>
#define ll long long int
#define N 3100
using namespace std;

int main(){
	ll s[N];
	ll c[N];
	ll n;
	ll mincost=-1;

	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> s[i];
	}
	for(ll i=0;i<n;i++){
		cin >> c[i];
	}

	ll tempcost;
	ll min;
	for(ll i=1;i<n-1;i++){
		tempcost=c[i];
		min = -1;
		for(ll j=0;j<i;j++){
			if((c[j]<min||min==-1)&&(s[j]<s[i])){
				min = c[j];
			}
		}
		if(min==-1){
			continue;
		}
		tempcost+=min;
		min = -1; 
		for(ll j=i+1;j<n;j++){
			if((c[j]<min||min==-1)&&(s[i]<s[j])){
				min = c[j];
			}
		}
		if(min==-1){
			continue;
		}
		tempcost+=min;

		if((tempcost<mincost||mincost==-1)&&tempcost>0){
			mincost = tempcost;
		}
	}

	cout << mincost << '\n';
}