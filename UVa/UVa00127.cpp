#include<bits/stdc++.h>

using namespace std;

int main(){
	string line, line2;
	stringstream input;
	char a, b;
	pair<char, char> pivot;
	int position;

	while(true){
		vector<stack<pair<char,char> > > rows;
		getline(cin,line);
		if(line=="#"){
			break;
		}
		getline(cin,line2);
		input = stringstream(line+line2);
		while(input >> a >> b){
			//try to move the currenct card the most you can
			rows.push_back(stack<pair<char,char>>());
			rows[rows.size()-1].push(make_pair(a,b));
			position = rows.size()-1;
			while(position<rows.size()){
				if(rows[position].empty()){
					rows.erase(rows.begin()+position);
					continue;
				}
				pivot = rows[position].top();
				rows[position].pop();
				while(position>0){
					if(position>=3 && (rows[position-3].top().first==pivot.first||rows[position-3].top().second==pivot.second)){
						position-=3;
					}
					else if(position>=1 && (rows[position-1].top().first==pivot.first||rows[position-1].top().second==pivot.second)){
						position-=1;
					}
					else{
						break;
					}
				}
				rows[position].push(pivot);
				position++;
			}
		}
		if(rows.size()==1){
			printf("%lu pile remaining:",rows.size());	
		}
		else{
			printf("%lu piles remaining:",rows.size());		
		}
		for(int i=0;i<rows.size();i++){
			printf(" %lu",rows[i].size());
		}
		printf("\n");
	}
	return 0;
}