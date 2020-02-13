#include<iostream>

using namespace std;

int main(){
	int t[2100], m[2100], h[2100], x, n;
	int pulo_atual, ultimo_doce, ultimo_pulo;
	int proximo_tipo, acm1, acm2;
	bool visited[2100];
	cin >> n >> x;
	for(int i=0;i<n;i++){
		cin >> t[i] >> h[i] >> m[i];
	}

	acm2 =0;
	for(int tipo_inicial = 0;tipo_inicial<2;tipo_inicial++){
		for(int i=0;i<n;i++){
			visited[i] = false;
		}
		proximo_tipo = tipo_inicial;
		acm1 = 0;
		pulo_atual = x;
		int opt;
		while(true){
			opt = -1;
			for(int i=0;i<n;i++){
				if(!visited[i] && t[i]==proximo_tipo && pulo_atual>=h[i] && (opt==-1||m[i]>m[opt])){
					opt = i;
				}
			}

			if(opt==-1) break;

			acm1++;
			visited[opt] = true;
			pulo_atual += m[opt];
			proximo_tipo = !proximo_tipo;
		}
		acm2 = max(acm1,acm2);
	}
	cout << acm2 << '\n';
	return 0;
}
