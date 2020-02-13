#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int a, x, b, y;

	cin >> n >> a >> x >> b >> y;
	while(true){	
		if(a==b){
			cout << "Yes\n";
			break;
		}
		else if(a==x||b==y){
			cout << "No\n";
			break;
		}
		if(a!=x){
			a++;	
			if(a>n){
				a = 1;
			}
		}
		if(b!=y){
			b--;
			if(b<=0){
				b = n;
			}	
		}
	}
	return 0;
}