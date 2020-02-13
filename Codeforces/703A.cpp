#include<bits/stdc++.h>


using namespace std;
int main(){
	int chris=0, miska=0, n, a, b;
	cin >> n;
	while(n--){
		cin >> a >> b;
		chris += (a<=b);
		miska += (a>=b);
	}

	if(miska>chris){
		cout << "Mishka\n";
	}
	else if(chris>miska){
		cout << "Chris\n";
	}
	else{
		cout << "Friendship is magic!^^\n";	
	}

	return 0;
}