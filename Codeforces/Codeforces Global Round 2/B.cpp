#include <bits/stdc++.h>
#define N 1001
using namespace std;

int main(){
	int n, h, ch;
	int k, p, answ;
	int vec[N];

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> n >> h;
	
	for(int i = 0; i < n; i++){
		cin >> vec[i];
		
		sort(vec,vec+i+1);
		
		ch = 0;
		p = 0;
		for(int j=i; j>=0; j--){
			if(p==0){
				ch += vec[j];
				p=1;
			}else{
				p = 0;
			}
		}
		
		if(ch > h){
			break;
		}
		
		answ = i+1;
	}
	
	cout << answ << '\n';
	
    return 0;
}