#include<bits/stdc++.h>

using namespace std;

int n, m;
char x, y;
bool poss;
vector<int> edges[26];
string w1, w2;

bool bfs(int start, int end){
	bool visited[26] = {false};
	queue<int> q;
	int temp;

	q.push(start);
	visited[start] = true;
	while(q.size()){
		temp = q.front();
		q.pop();

		for(int i=0;i<edges[temp].size();i++){
			if(!visited[edges[temp][i]]){
				visited[edges[temp][i]] = true;
				q.push(edges[temp][i]);
				if(edges[temp][i]==end){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){

	cin >> m >> n;

	for(int i=0;i<m;i++){
		cin >> x >> y;
		edges[x-97].push_back(y-97);
	}

	for(int i=0;i<n;i++){
		cin >> w1 >> w2;

		poss = true;
		if(w1.size()!=w2.size()){
			poss = false;
		}
		for(int j=0;(w1[j]!='\0')&&poss;j++){
			if(w1[j]!=w2[j]){
				poss = bfs(w1[j]-97,w2[j]-97);
			}
		}
		cout << ((poss) ? "yes" : "no") << '\n'; 
	}

	return 0;
}
