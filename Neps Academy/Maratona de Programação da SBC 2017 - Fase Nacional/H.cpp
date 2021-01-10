#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;

#define maxc 100100

int l, c, n;
int freq[maxc];
set<iii> range;

void colorir(int l, int r, int cor){
    viii inserir, apagar;
    auto lw = range.lower_bound(iii(ii(l, 0), 0));
    if(lw != range.begin()){ 
        lw--;
    }

    //cout << "[ "  << lw->first.first << " " << lw->first.second <<" "<< lw->second <<" ] ";

    int x, y, cor2;
    while(lw != range.end()){
        x = (*lw).first.first;
        y = (*lw).first.second;
        cor2 = (*lw).second;// 3 .. 4 5
        if(l > y){
            lw++;
            continue;
        }
        if(x > r){
            break;
        }
        apagar.emplace_back(iii(ii(x, y), cor2));
        freq[cor] += y-x+1;
        freq[cor2] -= y-x+1;
        if(l > x){
            freq[cor2] += l-x;
            freq[cor] -= l-x;
            inserir.emplace_back(iii(ii(x, l-1), cor2));
        }    
        if(y > r){
            //r+1...y
            //y-(r+1)+1 = y-r-1+1 = y-r
            freq[cor2] += y-r;
            freq[cor] -= y-r;
            inserir.emplace_back(iii(ii(r+1, y), cor2));
        }
        ++lw;
    }
    for(auto sla:apagar){
        range.erase(sla);
    }
    for(auto sla:inserir){
        range.insert(sla);
    }
    range.insert(iii(ii(l, r), cor));
}

int main(){
    ll p, x, a, b, s, m1, m2;
    cin >> l >> c >> n;
    freq[1] = l;
    range.insert(iii(ii(0, l-1), 1));
    while(n--){
        cin >> p >> x >> a >> b;
        s = freq[p];
        m1 = (a+s*s)%l;
        m2 = (a + ((s+b)*(s+b)))%l;
       /* cout << "ANTES DE " << m1 << " " << m2 << " = " << x << "\n";
        for(auto temp:range){
            cout << " (" << temp.first.first << " " << temp.first.second << ") ";
        }cout<<'\n'; */
        colorir(min(m1, m2), max(m1, m2), x);

        /*cout << "DEPOIS DE " << m1 << " " << m2 << " = " << x << "\n";
        for(auto temp:range){
            cout << " (" << temp.first.first << " " << temp.first.second << ") ";
        }cout<<'\n';   */
    }
    int maior = 0, f;
    for(int i = 1; i <= c; i++){
        if(freq[i] > maior){
            maior = freq[i];
            f = i;
        }
    }
    cout << maior << "\n";
    return 0;
}