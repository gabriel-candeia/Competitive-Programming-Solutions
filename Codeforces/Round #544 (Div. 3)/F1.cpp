#include <bits/stdc++.h>
#define ll long long int
#define N 200010
using namespace std;

int main(){
	ll n, e;
	ll x, y;
	ll raiz;
	cin >> n >> e;

	vector<vector<ll>> edges(n);
	vector<bool> visited(n, false);
	queue<ll> s;
	//ler
	for(ll i=0;i<e;i++){
		cin >> x >> y;
		edges[x-1].push_back(y-1);
		edges[y-1].push_back(x-1);
	}
	//printar
	/*cout << "grafo:\n";
	for(ll i = 0;i<n;i++){
		cout << i+1 << ':';
		for(ll j = 0;j<edges[i].size();j++){
			cout <<' ' << edges[i][j]+1;		
		}	
		cout << endl;
	}*/
	//encontrar raiz
	ll filhos = 0;
	ll maxFilhos = 0;
	for(ll i = 0;i<n;i++){
		filhos = edges[i].size();
		if(filhos > maxFilhos){
			raiz = i;
			maxFilhos = filhos;
		}
	}
	//cout << raiz << endl;
	//montar árvore
	s.push(raiz);
	visited[raiz] = true;
	ll temp;
	while(s.size()){
		temp = s.front();
		s.pop();	
		for(ll i = 0;i<edges[temp].size();i++){
			if(visited[edges[temp][i]]==false){
				visited[edges[temp][i]]=true;
				s.push(edges[temp][i]);
				cout << temp+1 << " " << edges[temp][i]+1 << "\n";
			}
		}
	}
	return 0;
}
