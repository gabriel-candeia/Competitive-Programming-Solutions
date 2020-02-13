#include<bits/stdc++.h>
#define N int(1e6)+3
using namespace std;
//é kruskal
pair<double,double> pares[N];  

double dist(pair<double,double> a, pair<double,double> b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int parent(vector<int> dsu, int v){
	if(v!=dsu[v]){
		dsu[v] = parent(dsu,dsu[v]);
	}
	return dsu[v];
}

double kruskal(vector<pair<double,pair<double,double>>> edges,double n){
	double acm = 0;
	int atual, prox, a, b,cont=0;
	vector<int> dsu;
	vector<int> rnk;
	for(int i=0;i<n;i++){
		dsu.push_back(i);
		rnk.push_back(1);
	}
	for(int i=0;i<edges.size();i++){
		a = parent(dsu,(edges[i].second.first));
		b = parent(dsu,(edges[i].second.second)); 
		if(a!=b){
			acm+=edges[i].first;
			if(rnk[a]>=rnk[b]){
				dsu[b] = a;
				rnk[a]+=rnk[b];
			}
			else{
				dsu[a] = b;
				rnk[b]+=rnk[a];	
			}
			cont++;
		}
		if(cont==n-1){
			break;
		}
	}
	return acm;
}

int main(){
	double p, c, t, a, b, d;
	vector<pair<double,pair<double,double>>> edges;  

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> p;
	for(int i=0;i<p;i++){
		cin >> a >> b;
		pares[i] = make_pair(a,b);
	}

	for(int i=0;i<p;i++){
		for(int j=i+1;j<p;j++){
			edges.push_back(make_pair(dist(pares[i],pares[j]),make_pair(i,j)));
		}
	}
	printf("%lf\n",kruskal(edges,p));
	return 0;
}
