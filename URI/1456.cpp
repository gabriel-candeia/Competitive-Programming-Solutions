#include<bits/stdc++.h>
using namespace std;
#define N int(1e5)+3

int main(){
	int cont=0, n;

	char mem[N], prog[N], input[N];
	int st[N], loops[N], top;
	int ptr, inptr;

	scanf("%d",&n);
	while(n--){
		printf("Instancia %d\n",++cont);
		scanf(" %s",input);
		scanf(" %s",prog);
		for(int i=0;i<N;i++){
			mem[i] = 0;
		}

		top = 0;
		for(int i=0;prog[i]!='\0';i++){
			loops[i] = -1;
			if(prog[i]=='['){
				st[top++] = i;
			}
			else if(prog[i]==']'){
				loops[st[--top]] = i;
			}
		}

		top = 0; ptr = 0; inptr = 0;
		for(int i=0;prog[i]!='\0';i++){
			if(prog[i]=='+'){
				mem[ptr]++;
			}
			else if(prog[i]=='-'){
				mem[ptr]--;
			}
			else if(prog[i]=='>'){
				ptr++;
			}
			else if(prog[i]=='<'){
				ptr--;
			}
			else if(prog[i]=='['){
				if(mem[ptr]!=0){
					st[top++] = i;	
				}
				else{
					i = loops[i];
				}	
			}
			else if(prog[i]==']'){
				if(mem[ptr]!=0){
					i = st[top-1];
				}
				else{
					top--;
				}
			}
			else if(prog[i]==',' && input[inptr]!='\0'){
				mem[ptr] = input[inptr++];
			}
			else if(prog[i]=='#'){
				for(int j=0;j<10;j++){
					printf("%c",mem[j]);
				}
			}
			else if(prog[i]=='.'){
				printf("%c",mem[ptr]);
			}
		}
		printf("\n\n");
	}
	return 0;
}
