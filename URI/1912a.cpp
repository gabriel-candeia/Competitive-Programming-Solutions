#include<bits/stdc++.h>
using namespace std;
#define N int(1e5)+3
#define ll long long int

ll n, a, c[N];
double answ, er1, er2, er3;

double area(ll h){
	double area = 0;
	for(int i=0;i<n;i++){
		area += (0>c[i]-h) ? 0 : (c[i]-h);
	}
	return area;
}

ll bs(ll l, ll r, ll a){
	ll med = l + (r-l)/2;
	if(l>=r){ 
		return l;
	}
	else if(a<=area(med)){
		return bs(med+1,r,a);
	}
	return bs(l,med,a);
}

int main(){

	while(cin >> n >> a){
		if(a==0) break;
		for(int i=0;i<n;i++){
			cin >> c[i];
			c[i]*=100000;
		}
		a*=100000;
		answ = bs(0,int(1e10),a);
		if(fabs(area(answ+1)-a)<=5e6){
			answ++;
		}	
		else if(fabs(area(answ-1)-a)<=5e6){
			answ--;
		}
		if(fabs(area(answ)-a)<=5e6){
			if(answ==0){
				printf(":D\n");
			}
			else{
				printf("%.4lf\n",answ/1e5);		
			}
		}
		else{
			printf("-.-\n");
		}
	}
	return 0;
}
