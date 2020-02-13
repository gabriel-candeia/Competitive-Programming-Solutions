#include<bits/stdc++.h>
#define N 1000+3
#define eh_operador(i) (i=='+'||i=='-'||i=='*'||i=='/'||i=='^')
using namespace std;



int main(){
	int n, t1=0,t2=0;
	bool cont = false;
	char op[N], st[N], str[N];

	cin >> n;
	while(n--){
		cont = false; t1=0; t2=0;
		scanf("%s",str);
		for(int i=0;str[i]!='\0';i++){
			if(eh_operador(str[i])){
				op[t2++] = str[i];
			}
			else if(str[i]==')'){
				st[t1++] = op[--t2];
				cont = true;
			}
			else if(str[i]!='('){
				st[t1++] = str[i];
				if(cont==true){
					st[t1++] = op[--t2];
				}
				cont = !cont;
			}
		}
		for(int i=0;i<t1;i++){
			cout << st[i];
		}
		cout << '\n';
	}
	return 0;
}