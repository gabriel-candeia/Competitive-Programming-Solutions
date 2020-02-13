#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;


int main(){
	string ent;
	int n;
	cin >> n;
	while(n--){
		int letras[27] = {0};
		bool pos = false;
		cin >> ent;

		if(ent.size()==1){
			pos = true;
		}
		sort(ent.begin(),ent.end());
		for(int i=0;i < ent.size()-1;i++){
			if(ent[i+1]-ent[i]==1){
				pos = true;
			}
			else{
				pos = false;
				break;
			}
		}

		if(pos){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";	
		}
	}

	return 0;
}