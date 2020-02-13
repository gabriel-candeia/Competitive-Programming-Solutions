#include<bits/stdc++.h>
#define N int(1e5)+3
using namespace std;
#define ll long long int

int main(){
	int s, tl, tr, count=0;
	ll l[N], r[N];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	tl=s-1; 
	tr=s-1;
	for(int i=0;i<s;i++){ cin >> l[i];}
	for(int i=0;i<s;i++){ cin >> r[i];}

	sort(l,l+s);
	sort(r,r+s);
	while(tl>=0 && tr>=0){
		if(l[tl]<r[tr]){
			tr--;
			count++;	
		}
		tl--;
	}
	cout << count << '\n';
}