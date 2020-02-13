#include<bits/stdc++.h>
#define N int(1e4)+3
#define K int(1e5)+3
#define ANSW int(1e8)+3
using namespace std;

int x[N], p[K];
int n, m, l, k, answ;
 
int proc(int n, int m, int l){
	int qtd = -1, count = 0;

	for(int i=0;i<N;i++){ x[i] = 0;}
	for(int i=0;i<k;i++){ x[p[i]]++;}

	if((n*100)%l==0){
		qtd = n*100/l;
		for(int i=k-1;i>=0 && qtd>0;i--){
			if(x[p[i]]!=0 && p[i]<=m){
				x[p[i]]--;
				if(p[i]==m){
					count++;
					qtd--;
				}
				else if(x[m-p[i]]!=0){
					count+=2;
					x[m-p[i]]--;	
					qtd--;
				}
				else{
					x[p[i]]++;
				}
			}
		}
	}	
	return ((qtd!=0) ? ANSW : count);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n >> m){
		if(n==0 && m==0){
			break;
		}
		cin >> l >> k;
		
		for(int i=0;i<k;i++){
			cin >> p[i];
		}
		sort(p,p+k);

		answ = min(proc(n,m,l),proc(m,n,l));
		if(answ==ANSW){
			cout << "impossivel\n";
		}
		else{
			cout << answ << '\n';
		}
	}
	return 0;
}
