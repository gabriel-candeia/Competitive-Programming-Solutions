#include<iostream>
#define N int(1e5)+10
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l, r, k, m, tam;
	int positions[N];
	int siz;
	string ent, answ;

	cin >> ent;
	tam = ent.size();	
	for(int i=0;i<tam;i++){
		positions[i] = i;
	}

	cin >> m;
	int qtd;
	while(m--){
		cin >> l >> r >> k;
		l--; r--;
		qtd = r-l+1;
		for(int i=0;i<tam;i++){
			if(positions[i]>=l && positions[i]<=r){
				positions[i]+=k;
				positions[i] = (positions[i]-l)%qtd+l;
			}
		}
	}

	answ = string(tam,'0');
	for(int i=0;i<tam;i++){
		answ[positions[i]] = ent[i];
	}

	cout << answ << '\n';

	return 0;
}