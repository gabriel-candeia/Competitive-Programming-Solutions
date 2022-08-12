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

int n,s,e;
string str;

pii get(int pos, char target) {
	pii ans = {-1,-1};
	for(int i=pos-1; i>=0; i--) {
		if(str[i] == '#') break;
		if(str[i] == target) { ans.fi = pos-i-1; break; }
	}
	for(int i=pos+1; i<n; i++) { 
		if(str[i] == '#') break;
		if(str[i] == target) { ans.se = i-pos-1; break; }
	}
	return ans;
}

int fix(pii p) {
	if(p.fi == 0 || p.se == 0) return -1;
	if(p.fi != -1 && p.se != -1) return 2;
	if(p.fi != -1 || p.se != -1) return 1;
	return 0;
}

int32_t main(){	
	freopen("portals.in","r",stdin);

	int t;
	cin>>t;
	while(t--) {
		cin>>n>>str;
		for(int i=0; i<n; i++) {
			if(str[i] == 's') s = i;
			if(str[i] == 'e') e = i;
		}

		int ans=0;
		pii SE = get(s,'e');
		
		if(SE.fi != -1) {
			for(int i=s-1; i>=0; i--) {
				if(str[i] == 'e') { ans = -1; break; }
				if(str[i] == '.') { ans++; str[i] = '#'; break; }
			}
		}		
		if(SE.se != -1) {
			for(int i=s+1; i<n; i++) {
				if(str[i] == 'e') { ans = -1; break; }
				if(str[i] == '.') { ans++; str[i] = '#'; break; }
			}
		}
		
		if(ans == -1) {
			cout<<ans<<endl;
			continue;
		}
        
        //cout << get(s,'o').first << " " << get(s,'o').second <<"\n";
        //cout << get(e,'o').first << " " << get(e,'o').second <<"\n";
		int SO = fix(get(s,'o')), EO = fix(get(e,'o'));

		if(SO == -1 && EO == -1)
			cout<<-1<<endl;
		else {
			if(SO == -1) SO = llinf;
			if(EO == -1) EO = llinf;
			cout<<ans+min(SO,EO)<<endl; 
		}

	}
	return 0;
}