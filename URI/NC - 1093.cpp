#include<bits/stdc++.h>
using namespace std;

double vampiros(int ev1,int ev2,int at,int d,double prob){
	if(ev1<=0 || prob <= 0.0000001){
		return prob;
	}
	else if(ev2<=0){
		return prob;
	}
	return (at)*vampiros(ev1+d,ev2-d,at,d,prob/6.0)+(6-at)*vampiros(ev1-d,ev2+d,at,d,prob/6.0);
}

int main(){
	int ev1, ev2, at, d;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> ev1 >> ev2 >> at >> d){
		if(ev1==0) break;

		printf("%.1lf\n",vampiros(ev1,ev2,at,d,100.0));
	}

	return 0;
}
