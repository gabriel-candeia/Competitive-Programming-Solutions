#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define aint(A) A.begin(),A.end()
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
#define intinf 0x3f3f3f3f3f3f3f3f
#define int long long

using namespace std;

int n,m;
int dist[1005];
vii v[1005];

int dfs(int pos) {
	if(dist[pos] != -1) return dist[pos];
	int ans=0;
	for(auto &i : v[pos]) 
		ans = max(ans, dfs(i.fi) + i.se);
	return dist[pos] = ans;
}

int32_t main(){
	cin>>n>>m;
	mset(dist,-1);
	for(int i=0; i<m; i++) {
		int a,b,c; cin>>a>>b>>c;
		v[a].push_back({b,c});
	}

	int ans=0;
	for(int i=1; i<=n; i++)
		if(dist[i] == -1)
			ans = max(ans, dfs(i));

	cout<<ans<<endl;

	return 0;
}