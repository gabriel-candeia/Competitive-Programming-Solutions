#include<bits/stdc++.h>
using namespace std;
#define N int(1e5)+3
#define ll long long int

ll arr[N], n, c, t;
ll tmin;

ll teste(ll lim){
	ll acm = 0, d = 0;
	for(int i=0;i<n;i++){
		if((acm+arr[i])>lim*t){
			d++;
			acm = arr[i];
		}
		else{
			acm+=arr[i];
		}
	}
	d++;
	return d;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c >> t;
	tmin = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		tmin = (tmin<arr[i]) ? arr[i] : tmin;
	}

	ll l=ceil(tmin*1.0/t), r= (1e10L), mid, cmp;
	while(l<r){
		mid = l + (r-l)/2;
		cmp = teste(mid);
		if(cmp<=c){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	if(teste(l-1)==c && l != ceil(tmin*1.0/t)){
		l--;	
	}
	else if(teste(l)>c){
		l++;
	} 

	cout <<  l << '\n';
	return 0;
}
