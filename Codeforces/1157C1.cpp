#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, temp;
	deque<int> ent;
	stack<int> aux;
	string answ = "";

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> temp;
		ent.push_back(temp);
	}

	while(true){
		if(ent.size()==0){
			break;
		}
		if(aux.size()==0||min(ent.front(),ent.back())>aux.top()){
			aux.push(min(ent.front(),ent.back()));
			if(ent.front()==min(ent.front(),ent.back())){
				answ+='L';
				ent.pop_front();
			}
			else if(ent.back()==min(ent.front(),ent.back())){
				answ+='R';
				ent.pop_back();
			}
		}
		else if(max(ent.front(),ent.back())>aux.top()){
			aux.push(max(ent.front(),ent.back()));
			if(ent.front()==max(ent.front(),ent.back())){
				answ+='L';
				ent.pop_front();
			}
			else if(ent.back()==max(ent.front(),ent.back())){
				answ+='R';
				ent.pop_back();
			}
		}
		else{
			break;
		}
	}
	cout << answ.size() << '\n';
	cout << answ << '\n';

	return 0;
}