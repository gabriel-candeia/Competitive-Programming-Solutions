#include<bits/stdc++.h>
#define N int(1e6)+3
#define M 1000000007
#define ll long long int
using namespace std;

ll A[N], coef[N], x[N], y[N];

ll modex(int a, int k){
	if(k==0){
		return 1L;
	}
	ll temp = modex(a,k/2);
	if(k%2){
		return (((temp*temp))*a);
	}
	return ((temp*temp));
}

void fill_A(int n,ll x0,ll y0,int c,int d, int e1,int e2,int f){
	x[0]=x0;
	y[0]=y0;
	A[0] = (x[0]+y[0])%f;
	for(int i=1;i<n;i++){
		x[i] = ((c*x[i-1])%f+(d*y[i-1])%f+e1)%f;
		y[i] = ((d*x[i-1])%f+(c*y[i-1])%f+e2)%f;; 
		A[i] = (x[i]+y[i])%f;
	}
}

void fill_coef(int n){
	coef[n]= 0;
	for(int i=n-1;i>=0;i--){
		coef[i]= (coef[i+1] + (A[i]*(n-i))%M)%M;
	}
	for(int i=0;i<n;i++){
		coef[i]=(coef[i]*(i+1))%M;
	}
} 

ll powerk(int n,int k){
	ll sum = (coef[0]*k)%M;
	for(int i=1;i<n;i++){
		sum = (sum+(coef[i]*((-1L+modex(i+1,k))/(i)))%M)%M;
	}
	return sum;
}

int main(){
	int t, n, k, x0, y0, c, d, e1, e2, f, count = 0;
	cin >> t;
	while(t--){
		count++;
		cin >> n >> k >> x0 >> y0 >> c >> d >> e1 >> e2 >> f;
		fill_A(n,x0,y0,c,d,e1,e2,f);
		fill_coef(n);
		printf("Case #%d: %lld\n",count,powerk(n,k));
	}
	
	return 0;
}
