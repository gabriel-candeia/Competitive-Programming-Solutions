#include <iostream>
#include <algorithm>
#define ll long long int
#define N 200010	
 
using namespace std;
 
int main(){
	ll n, k;
	ll num[N];
	ll modulos[N];
	ll poss;
 
	cin >> n >> k;
 
	for(ll i=0;i<k;i++){
		modulos[i] = 0;
	}	
 
	for(ll i=0;i<n;i++){
		cin >> num[i];
	}
 
	for(ll i=0;i<n;i++){
		modulos[num[i]%k]++;
	}
 
	poss = 0;
	poss += modulos[0]-modulos[0]%2;
	for(ll i=1;i<k;i++){
		if(i==k-i){
			poss+= modulos[i]-modulos[i]%2;
		}
		else{
			poss +=	min(modulos[i],modulos[k-i]);
		}
	}
 
	/*for(int i=0;i<k;i++){
		cout << modulos[i] << ' ';
	}
	cout << '\n';*/
	cout << poss << '\n';
 
	return 0;
}