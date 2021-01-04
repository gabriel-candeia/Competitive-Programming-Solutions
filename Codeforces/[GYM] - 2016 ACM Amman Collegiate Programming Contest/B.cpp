#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int t, n, arr[10] = {6,2,5,5,4,5,6,3,7,6};

    cin >> t;
    while(t--){
        cin >> n >> s;
        int qtd=0, cnt=0;
        for(int i=0;i<n;i++){
            qtd+=(arr[s[i]-'0']-2);
        }
        
        //velho que tenta ir transformando em 9 até onde dá
        for(int i=0;i<n;i++){
            for(int j=9;j>=0;j--){
                if(qtd>=arr[j]-2){
                    s[i] = '0'+j;
                    qtd-=(arr[j]-2);
                    break;
                }
            }
        }
        
        //novo
        for(int i=n-1;i>=0 && qtd;i--){
            int nxt=-1;
            for(int j=9;j>=0;j--){
                if(qtd>=(arr[j]-arr[s[i]-'0']) && arr[j]-arr[s[i]-'0']>=0){
                    if(nxt == -1)
                        nxt = j;
                    if(arr[j]-arr[s[i]-'0']>arr[nxt]-arr[s[i]-'0'])
                        nxt = j;
                }
            }
            
            if(nxt!=-1){
                qtd-=(arr[nxt]-arr[s[i]-'0']);
                s[i] = nxt+'0';
            }
        }

        cout << s <<'\n';
    }


}