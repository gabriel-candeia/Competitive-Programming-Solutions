#include<bits/stdc++.h>
#define N 300100
#define ll long long int
using namespace std;

int comparator(pair<ll,ll> a, pair<ll,ll> b){
	return a.first < b.first;
}

int main(){
	ll n;
	ll a[N];
	vector<pair<ll,ll>> ratings;

	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> a[i];
		ratings.push_back(pair<ll,ll>(a[i],i));
	}

	sort(ratings.begin(),ratings.end(),comparator);

	for(ll i=1;i<n;i++){
		if(ratings[i].first==ratings[i-1].first){
			a[ratings[i].second] =  a[ratings[i-1].second]+1;
		}
		else if(a[ratings[i-1].second]>=ratings[i].first){
			a[ratings[i].second] =  a[ratings[i-1].second]+1;	
		}
	}

	for(ll i=0;i<n;i++){
		cout << a[i] << " ";
	}	
	cout << "\n";

	return 0;
}