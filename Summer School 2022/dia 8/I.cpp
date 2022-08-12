#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define all(A) A.begin(),A.end()
#define mset(A,X) memset(A,X,sizeof A)
#define bb(V,X) binary_search(V.begin(),V.end(),X);
#define upperb(V,X) (int)(upper_bound(V.begin(),V.end(),(X))-V.begin())
#define lowerb(V,X) (int)(lower_bound(V.begin(),V.end(),(X))-V.begin())
#define SZ(V) (int) V.size()
#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'
#define _ << " , " <<

#define vi vector<int>
#define pii pair<int,int>
#define pdd pair<double,double>
#define vii vector< pair<int,int> >
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define MAX 300000
#define endl '\n'
#define ok cerr<<"OK"<<endl
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define int long long

using namespace std;

int n;
bool check(int m, vi &h, vi &v) {
	for(int i=0; i<n; i++) {
		if(h[i]+m > v[i]) return true;
		if(h[i]+m < v[i]) return false;
	}
	return true;
}

int32_t main(){
	cin>>n;

	vi h(n),v(n),p(n,0);
	for(int &i : h)	cin>>i;
	for(int &i : v)	cin>>i;
	
	int l=0,r=1000,ans=0;
	while(r>=l) {
		int m = (l+r)/2;
		if(check(m,h,v)) ans=m, r=m-1;
		else l=m+1; 
	}
	cout<<ans<<endl;

	return 0;
}