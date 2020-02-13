#include<bits/stdc++.h>
#define N 300100
using namespace std;

#define ll long long int

bool comparator(pair<ll,ll> a, pair<ll,ll> b){
	return a.first < b.first;
}

int main(){
	ll n, k;
	ll cost[N];
	ll indexes[N];
	ll size=0,removido;
	ll acm=0;
	ll pos[N];
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>> heap;
	cin >> n >> k;

	for(ll i=0;i<n;i++){
		cin >> cost[i];	
	}

	for(ll i=0;i<n+k;i++){
		//insert
		if(i<n){
			heap.push(pair<ll,ll>(cost[i],i));	
		}
		//retira
		if(i>=k){
			removido = heap.top().second;
			pos[removido] = i+1;
			acm += cost[removido]*(i-removido);
			heap.pop();
		}
	}

	cout << acm << '\n';
	for(ll i=0;i<n;i++){
		cout << pos[i] << ' ';
	}
	cout << '\n';

	return 0;
}