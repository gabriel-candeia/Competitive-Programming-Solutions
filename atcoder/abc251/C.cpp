#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int best = 0, id = 0;
    set<string> st;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        int score;
        cin >> s >> score;
        if(st.find(s)==st.end() && score>best){
            best = score;
            id = i;
        }
        st.insert(s);
    }

    cout << id+1 <<"\n";

    return 0;
}