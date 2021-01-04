#include <bits/stdc++.h>

using namespace std;

#define maxn 100100

string s;
int t, n, m, linha, coluna, sc, dc, sl, dl, ans;
int l[maxn], c[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m >> s;
        int up=0, down=0, left=0, right=0, x=0, y=0;
        linha = coluna = sc = dc = sl = dl = 0;
        int answ = 0;
        for(int i = 0; i < s.size(); i++){
           if(s[i] == '<'){
               if(left-y+1==m){
                   answ++;
               }
               else{
                   y--;
               }
               //cout << "Coluna = " << coluna << "\n";
           }else if(s[i] == '>'){
               if(y-right+1==m){
                   answ++;
               }
               else{
                   y++;
               }
               //cout << "Coluna = " << coluna << "\n";
           }else if(s[i] == 'v'){
               if(up-x+1==n){
                   answ++;
               }
               else{
                   x--;
               }
              // cout << "Linha = " << linha << "\n";
           }else if(s[i] == '^'){
               if(x-down+1==n){
                   answ++;
               }
               else{
                   x++;
               }
            //   cout << "Linha = " << linha << "\n";
           }
           up = max(up,x);
           down = min(down,x);
           left = max(left,y);
           right = min(right,y);
        }
        //cout << up << " " << down << " " << left << " " << right <<'\n';
        cout << answ <<'\n';
        //cout << abs((n-1-up-down)+(m-1-left-right)) << "\n";
        //cout << max(sc, dc)-min(sc, dc) + max(sl, dl)-min(sl, dl) << "\n";
        
    }
}