#include<bits/stdc++.h>
#define ll long long int
#define N 1000000
using namespace std;

ll n;
ll c;
ll x, y;
ll counter;
string ent;
vector<ll> edges[N];
bool visited[N] = {false};
	
int func(ll vert){
	queue<ll> q;
	ll current;
	int ret = 26;
	bool letra = false;
	char last;

	q.push(vert);
	visited[vert]=false;
	while(q.size()){
		current = q.front();
		q.pop();

		if(ent[current]!='*'){
			if(letra&&last!=ent[current]){
				ret = 0;
				break;
			}
			else{
				last = ent[current];
				letra = true;
				ret = 1;	
			}
			
		}

		for(ll i=0;i<edges[current].size();i++){
			if(visited[edges[current][i]]==false){
				q.push(edges[current][i]);
				visited[edges[current][i]] = true;
			}
		}
	}

	return ret;
}

int main(){

	cin >> n >> c;
	cin >> ent;

	//adicionar arestas basicas
	for(ll i=0;i<n/2;i++){
		edges[i].push_back(n-i-1);
		edges[n-i-1].push_back(i);
	}

	//ler e adicionar demais arestas
	for(ll i=0;i<c;i++){
		cin >> x >> y;
		edges[x-1].push_back(y-1);
		edges[y-1].push_back(x-1);
	}

	//printar grafo
	/*for(ll i = 0;i<n;i++){
		cout << i << ": ";
		for(ll j = 0;j<edges[i].size();j++){
			cout << edges[i][j] << ' ';
		}
		cout << endl;
	}*/

	//algoritmo
	counter = 1;
	for(ll i=0;i<n&&counter;i++){
		if(visited[i]==false){
			counter *= func(i);
			counter = counter%(1000000007);
		}
	}

	cout << counter <<'\n';

	return 0;
}













