#include<bits/stdc++.h>
#define N int(2e5)+3
using namespace std;

int main(){
	int q, n;
	int arr[2*N], p, last, next; 
	char a;

    cin >> q;
    
    while(q--){
    	cin >> n;
    	for(int i=0;i<2*n;i++){
			cin >> a;
			arr[i] = (a<='2');
    	}
    	last = -1;
    	p = 0;

    	while(0<=p && p<2*n){
    		if(arr[p]==1){
    			if(p==n-1){
    				break;
    			}
    			last = p++;
    		}
    		else if(arr[p]==0 && (last==-1 || abs(last-p)<n)){
    			next = ((p<n) ? (p+n)  : (p-n));
    			if(arr[next]==0){
    				last = p;
    				p = next;
    			}
    			else{
    				break;
    			}
    		} 
    		else{
    			if(p==n-1){
    				break;
    			}
    			last = p++;
    		}
    	}
    	if(p==2*n){
    		cout << "YES\n";
    	}
    	else{
    		cout << "NO\n";	
    	}
    }
    return 0;
}