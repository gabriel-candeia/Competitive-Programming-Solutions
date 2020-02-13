#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ll t;
	ll n, k;
	ll id, h, w, l;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while(t--){
		vector<pair<ll,ll>> presentes;	
		vector<ll> ids;
		cin >> n >> k;
		for(ll i=0;i<n;i++){
			cin >> id >> h >> w >> l;
			presentes.push_back(pair<ll,ll>(-1*h*w*l,id));
		}
		sort(presentes.begin(),presentes.end());

		for(ll i=0;i<k;i++){
			ids.push_back(presentes[i].second);
		}
		sort(ids.begin(),ids.end());

		cout << ids[0];
		for(ll i=1;i<k;i++){
			cout << ' ' << ids[i];
		}
		cout << '\n';
		
	}

	return 0;
}

