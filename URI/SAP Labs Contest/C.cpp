#include<bits/stdc++.h>
#define N int(1e5)+3
#define ll long long int
using namespace std;
//é dijkstra

ll dist(vector<pair<int,int>> arr[N],int c){
	ll dist[N], atual;
	int st[N], topo = 0;
	for(int i=0;i<N;i++){
		dist[i] = -1;
	}
	dist[0] = 0;
	st[topo++] = 0;
	while(topo!=0){
		atual = st[--topo];
		for(int i=0;i<arr[atual].size();i++){
			if(dist[arr[atual][i].first]>dist[atual]+arr[atual][i].second || dist[arr[atual][i].first]==-1){
				dist[arr[atual][i].first]=dist[atual]+arr[atual][i].second;
				st[topo++] = arr[atual][i].first;
			}
		}
	}
	return dist[c-1];
}

int main(){
	ll sum=0, f, c, t, a, b, d;

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> f;
	while(f--){
		vector<pair<int,int>> arr[N]; 
		cin >> c >> t;
		for(int i=0;i<t;i++){
			cin >> a >> b >> d;
			arr[a-1].push_back(make_pair(b-1,d));
		}
		sum+= dist(arr,c);
	}
	cout << sum << '\n';
	return 0;
}
