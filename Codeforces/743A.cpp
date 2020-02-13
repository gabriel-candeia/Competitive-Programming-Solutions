#include<iostream>
#include<string>

using namespace std;

int main(){
	int n, a, b;
	string ent;
	cin >> n >> a >> b;
	cin >> ent;

	cout << ((ent[a-1]==ent[b-1]) ? "0\n" : "1\n");
}