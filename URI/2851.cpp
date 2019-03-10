#include <bits/stdc++.h>
#define ll long long int
#define N 100100

using namespace std;

ll n;
ll elem[N] = {0};
ll answ[N] = {0};
ll pos[N] = {0};

void func(ll current, ll next){
	if(next>=n){
		answ[current] = -1;
		pos[current] = -1;
	}
	else if(elem[current]<elem[next]){
		answ[current]=elem[next];
		pos[current]=next;
	}
	else{
		func(next,next+1);
		if(elem[current]<answ[next]||pos[next]==-1){
			answ[current]=answ[next];
			pos[current]=pos[next];		
		}
		else{
			func(current,pos[next]);
		}
	}
}

int main(){
	cin >> n;

	for(ll i=0;i<n;i++){
		cin >> elem[i];
	}

	//elementos
	/*cout << "elementos: ";
	for(ll i=0;i<n;i++){
		cout << elem[i] << ' ';
	}
	cout << '\n';*/

	//algoritmo
	for(ll i=0;i<n;i++){
		if(answ[i]==0){
			func(i,i+1);
		}
	}

	//respostas
	//cout << "respostas: ";
	for(ll i=0;i<n;i++){
		if(answ[i]!=-1){
			cout <<	answ[i];
		}
		else{
			cout <<	'*';	
		}
		if(i!=n-1) cout << ' ';
	}
	cout << '\n';

	//indicess
	/*cout << "indices: ";
	for(ll i=0;i<n;i++){
		cout << pos[i] << ' ';
	}
	cout << '\n';*/

	return 0;
}