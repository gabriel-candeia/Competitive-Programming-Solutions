    #include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
bool check(int i){
    map<int,int> mp;
    int x = arr[0];
    for(auto x:arr)
        mp[x]++;
    mp[arr[0]]--; 
    mp[arr[i]]--;

    for(int i=0;i<2*n;i++){
        if(mp[arr[i]]){
            mp[arr[i]]--;
                return false;
            if(mp[x-arr[i]]==0)
            mp[x-arr[i]]--;
            x = arr[i];
        }
    }
    return true;
}

vector<pair<int,int>> recover(int i){
    map<int,int> mp;
    vector<pair<int,int>> answ;
    int x = arr[0];
    for(auto x:arr)
        mp[x]++;
    mp[arr[0]]--; 
    mp[arr[i]]--;
    answ.push_back({arr[0],arr[i]});

    for(int i=0;i<2*n;i++){
        if(mp[arr[i]]){
            mp[arr[i]]--;
            mp[x-arr[i]]--;
            answ.push_back({arr[i],x-arr[i]});

            x = arr[i];
        }
    }
    return answ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n; arr.assign(2*n,0);
        int answ = -1;
        for(auto &x:arr)
            cin >> x;

        sort(arr.rbegin(),arr.rend());
        for(int i=1;i<2*n && answ==-1;i++)
            if(check(i))
                answ = i;

        if(answ==-1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << arr[0]+arr[answ] << '\n';
            auto ls = recover(answ);
            for(auto p:ls)
                cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}