#include<bits/stdc++.h>

using namespace std;

int procedure(int day,int a,int b,int c){
	int week[7] = {0,1,2,0,2,1,0};
	int cont=0;
	for(int i=day;;i++){
		i=i%7;
		cont++;
		if(week[i]==0&&a){
			a--;
		}
		else if(week[i]==1&&b){
			b--;
		}
		else if(week[i]==2&&c){
			c--;
		}
		else{
			cont--;
			break;
		}	
	}
	return cont;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	int completedWeeks;
	int answ=0;

	cin >> a >> b >> c;

	completedWeeks = a/3;
	if(b/2<completedWeeks){
		completedWeeks = b/2;
	}
	if(c/2<completedWeeks){
		completedWeeks = c/2;
	}
	a = a - completedWeeks*3;
	b = b - completedWeeks*2;
	c = c - completedWeeks*2;

	for(int i=0;i<7;i++){
		answ = max(answ,procedure(i,a,b,c));
		
	}	
	answ += completedWeeks*7;

	cout << answ << '\n';
	return 0;
}