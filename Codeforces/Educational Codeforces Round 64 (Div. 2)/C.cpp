#include<bits/stdc++.h>
#define N 200100
#define ll long long int
using namespace std;
int main(){
	ll i, j;
	ll x[N], z, n;
	ll paresC=0;
	ll paresD=0;
	bool visited[N];
	cin >> n >> z;
	for(int i=0;i<n;i++){
		cin >> x[i];
		visited[i] = false;
	}
	sort(x,x+n);
	for(i=0,j=1;i<n;i++){
		if(!visited[i]){
			while(j<n && x[j]-x[i]<z){
				j++;	
			} 
			if(j==n) break;
			paresC++;
			visited[j++] = true;
		}
	}

	for(int i=0;i<n;i++){ visited[i] = false;}
	for(i=n-1,j=n-2;i>0;i--){
		if(!visited[i]){
			while(j>=0 && x[i]-x[j]<z){
				j--;	
			} 
			if(j==-1) break;
			paresD++;
			visited[j--] = true;
		}
	}

	cout << max(paresD,paresC) << '\n';
	return 0;
}

//4 7
//1 8 10 15