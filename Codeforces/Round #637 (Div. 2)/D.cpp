#include<bits/stdc++.h>
#define N 2003
using namespace std;
string visited[N][N];

int convert(bitset<7> src, bitset<7> destiny){
    int acm=0;
    for(int i=0;i<7;i++){
        if(src[i]==1 && destiny[i]==0){
            return 5000;
        }
        acm += (destiny[i]==1 && src[i]==0);
    }  
    return acm;
}

int to_key(int i, int k){
    return i*2001 + k;
}

int main(){
    vector<string> p = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    vector<bitset<7>> nums, digit;
    for(auto s:p){ nums.push_back(bitset<7>(s));}

    int n, k;
    string s;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> s;
        digit.push_back(bitset<7>(s));
    }

    queue<pair<pair<int,int>,string>> q;
    pair<pair<int,int>,string> u;

    string answ = "";
    int i, rem, needed, key;
    string st;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            visited[i][j] = "";
        }
    }

    /*q.push({{0,k},""});
    int cnt=0;
    while(q.size()){
        cnt++;
        u = q.front(); q.pop();

        i = u.first.first, rem = u.first.second;
        st = u.second;

        //cout << "(" << i <<" "<< rem <<" "<< st <<")\n";
        if(i==n){
            if(rem==0 && st>answ){
                answ = st;
            }
            continue;
        }

        for(int j=9;j>=0;j--){
            needed = convert(digit[i],nums[j]);
            if(needed<=rem && visited[i+1][rem-needed]==false){
                visited[i+1][rem-needed] = true;
                q.push({{i+1,rem-needed},st+to_string(j)});
            }
        }
    }*/
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            for(int k=9;k>=0;k--){
                //needed = convert(digit[i],nums[k]);
                needed = digit[i].count();
                if(needed<=j){
                    
                }
            }
        }
    }
    answ = "";
    //cout << cnt <<"\n";
    if(answ==""){
        cout << -1 <<"\n";
    }
    else{
        cout << answ <<'\n';
    }

    return 0;   
}