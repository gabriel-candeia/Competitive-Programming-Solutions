#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll comparator(ll a, ll b){
	return a > b;
}

int main(){
	ll n, k;
	string ent;
	ll letras[30];
	ll stack[30];
	ll topo=0;

	ll acm;

	cin >> n >> k;
	cin >> ent;

	for(ll i=0;i<30;i++){
		letras[i]=0;
	}

	for(ll i=0;ent[i]!='\0';i++){
		letras[ent[i]-'A']++;
	}

	for(ll i=0;i<26;i++){
		if(letras[i]!=0){
			stack[topo++] = letras[i];
		}
	}

	sort(stack,stack+topo,comparator);

	acm = 0;
	for(ll i=0;i<topo&&(k>0);i++){
		acm+=min(k*k,stack[i]*stack[i]);
		
		k-=stack[i];
	}

	cout << acm << "\n";

	return 0;
}	