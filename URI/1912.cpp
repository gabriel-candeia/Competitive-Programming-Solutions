#include<bits/stdc++.h>
using namespace std;
#define N int(1e5)+3
#define tol 1e-4
int n, a, c[N];
long double answ, lim;

int cmp(long double y, long double x){
	return (y>=x+tol) ? 1 : ((y<=x-tol) ? -1 : 0);
}


long double area(long double h){
	long double area = 0;
	for(int i=n-1;i>=0 && c[i]>h;i--){
		area += c[i]-h;
	}
	return area;
}

long double bs(long double l, long double r, int a){
	long double med, ar;
	while(cmp(l,r)!=1){
		med = (r+l)*0.5, ar = area(med);
		if(cmp(a,ar)==0){ 
			return med;
		}
		else if(cmp(a,ar)==1){
			r = med;
		}
		else{
			l = med;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n >> a){
		if(a==0) break;
		lim = 0;
		for(int i=0;i<n;i++){
			cin >> c[i];
			lim = (lim > c[i]) ? lim : c[i];
		}
		sort(c,c+n);
		if(area(0)==a){
			printf(":D\n");
		}
		else if(area(0)<a){
			printf("-.-\n");
		}
		else{
			answ = bs(0,lim,a);
			printf("%.4Lf\n",answ);		
		}
	}
	return 0;
}
