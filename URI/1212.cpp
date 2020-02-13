#include<iostream>
using namespace std;

int main(){
	int a, b;
	while(cin >> a >> b){
		int s1[10], s2[10], t1=0, t2=0,cont=0;	
		if(a==0 && b==0){
			break;
		}

		for(int i=0;i<10;i++){
			s1[i] = 0;
			s2[i] = 0;
		}

		while(a){
			s1[t1++] = a%10;
			a/=10;
		}

		while(b){
			s2[t2++] = b%10;
			b/=10;
		}

		for(int i=0;i<max(t1,t2);i++){
			if(s1[i]+s2[i]>=10){
				cont++;
				s1[i+1]++;
			}
		}
		if(cont == 0){
			cout << "No carry operation.\n";
		}
		else if(cont==1){
			cout << "1 carry operation.\n";
		}
		else{
			cout << cont << " carry operations.\n";	
		}
	}
	return 0;
}
