#include<iostream>
#define N 100100

using namespace std;

int main(){
	int bills[4]={0};
	int money;
	int n;
	bool poss = true;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> money;
		if(poss){
			if(money==25){
				bills[0]++;
			}
			else if(money==50){
				poss*=(bills[0]--!=0);
				bills[1]++;
			}
			else{
				if(bills[1]>=1 and bills[0]>=1){
					bills[0]--;
					bills[1]--;
				}
				else if(bills[0]>=3){
					bills[0]-=3;
				}
				else{
					poss = false;
				}
			}
		}
	}

	cout << ((poss==true) ? "YES\n" : "NO\n");

	return 0;
}