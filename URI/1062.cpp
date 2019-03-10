#include<iostream>
using namespace std;
#define N 1001
#define ll long long int

int main(){
	ll A[N], B[N], C[N], END[N];
	ll topA, topB, topC;
	ll n, next;
	bool yes;
	while(true){
		cin >> n;
		while(n){
			topA = 0;
			topB = 0;
			topC = 0;
			for(ll i=0;i<n;i++){
				cin >> END[i];
				A[topA++] = n-i;
				if(END[0]==0) break;
			}
			if(END[0]){
				next = 0;
				yes = true;
				while(topA || topB){
					if(!topB){
						B[topB++] = A[--topA];
					}
					else{
						if(B[topB-1]==END[next]){
							C[topC++] = B[--topB];
							next++;
						}
						else if(!topA){
							yes = false;
							break;
						}
						else{
							B[topB++] = A[--topA];		
						}
					}
				}
				cout << ((yes) ? ("Yes\n") : ("No\n"));
			}
			else break;
		}
		if(n==0) break;
		cout << "\n";
	}
	return 0;
}




