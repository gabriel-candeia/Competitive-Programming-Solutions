#include <bits/stdc++.h>

using namespace std;

#define maxn 200005

typedef pair<int, int> ii;

int n;
array<int, 3> v[maxn];
ii prox[maxn];
int ordem[maxn];
 
void proxd(){
    ii par;
    stack<ii> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top().first < v[i][1]){
            par = st.top();
            prox[par.second].first = i;
            st.pop();
        }
        st.push(ii(v[i][1], i));
    }
}

void proxe(){
    ii par;
    stack<ii> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top().first < v[i][1]){
            par = st.top();
            prox[par.second].second = i;
            st.pop();
        }
        st.push(ii(v[i][1], i));
    }
}

int main(){
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v[i][0] = a;
        v[i][1] = b;
        v[i][2] = i+1;
    }
    sort(v, v+n);
    for(int i = 0; i < n; i++){
        ordem[v[i][2]-1] = i;
    }    
    for(int i = 0; i < n; i++)
        prox[i] = {-1, -1};
    proxd(); proxe();
    int i;
    for(int i1 = 0; i1 < n; i1++){
        i = ordem[i1];
        if(prox[i].first == -1 && prox[i].second == -1){
            cout << "-1 ";
        }else{
            a = prox[i].first; b = prox[i].second;
            if(b == -1){
                cout << v[a][2] << " ";
            }else if(a == -1){
                cout << v[b][2] << " ";
            }else if(abs(v[i][0]-v[a][0]) == abs(v[i][0]-v[b][0])){
                cout << (v[a][1] > v[b][1] ? v[a][2] : v[b][2]) << " ";
            }else if(abs(v[i][0]-v[a][0]) < abs(v[i][0]-v[b][0])){
                cout << v[a][2] << " ";
            }else{
                cout << v[b][2] << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}