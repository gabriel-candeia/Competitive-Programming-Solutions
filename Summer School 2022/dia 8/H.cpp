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

int m;

int binpow(int a, int b) {
	int res = 1;
	while(b>0) {
		if(b&1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

pair<bool,int> check(int n) {
	int ans=0,i=1;
	for(;ans < m; i++) 
		ans += binpow(i,n);
	return {ans == m, i-1};
}

int32_t main(){
	cin>>m;
	if(m == 1) return cout<<"3 1"<<endl, 0;

	for(int n=2;;n++) {
		auto [flag, s] = check(n);
		if(flag) return cout<<n+1<<" "<<s<<endl, 0;
		if(!flag && s == 2) break;
	}
	cout<<"impossible"<<endl;
	
	return 0;
}
