#include<bits/stdc++.h>

using namespace std;

string inverter(string s){
	string res = "";
	char digit;
	bool only9 = true;
	for(int i=0;i<s.size();i++){
		digit = s[i]-'0';
		if(digit>9-digit && (9-digit || res.size()!=0)){
			res+=9-digit+'0';	
		}
		else{
			res+=digit+'0';
		}
	}

	return res;
}


int main(){
	string ent;

	cin >> ent;

	cout << inverter(ent) << "\n";

	return 0;
}