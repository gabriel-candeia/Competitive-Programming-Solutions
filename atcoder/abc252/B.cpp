#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
  	vector<int> arr, ls;
  	
  	cin >> n >> m;
  
  	int mx = -1;
  	arr.assign(n,0);
  	for(auto &x:arr){
		cin >> x;
        mx = max(mx,x);
    }
  	
  	bool ok = false;
  	ls.assign(m,0);
  	for(auto &x:ls){
		cin >> x;
      	ok = ok || arr[x-1]==mx;
    }
  
  	if(ok)
      cout <<"Yes\n";
    else
      cout <<"No\n";
    
  
	return 0;
}