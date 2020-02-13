#include<iostream>
#include<map>
#define N 100100

using namespace std;

int main(){
	int num_teams;
	int x, y;
	pair<int,int> teams[N];
	map<int,int> home_uniforms;
	int home_count[N];

	cin >> num_teams;

	for(int i=0;i<num_teams;i++){
		cin >> x >> y;
		teams[i] = pair<int,int>(x,y);
		home_count[i] = num_teams-1;
		home_uniforms[x]+=1;
	}

	for(int i=0;i<num_teams;i++){
		home_count[i]+=home_uniforms[teams[i].second];

		cout << home_count[i] << ' ' << 2*(num_teams-1)-home_count[i]<<'\n';
	}	

	return 0;
}