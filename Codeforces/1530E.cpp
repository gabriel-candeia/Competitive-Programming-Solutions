#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        string s;
        int n;
        cin >> s;
        map<char,int> cnt;
        n = s.size();

        for(auto c:s){
            cnt[c]++;
        }

        char menor = 0;  
        for(auto p:cnt){
            if(menor==0 || p.second < cnt[menor]){
                menor = p.first;
            }
        }

        string answ = "";
        if(cnt[menor]==1){
            cnt[menor]--;
            answ.push_back(menor);
            for(auto &p:cnt){
                while(p.second){
                    answ.push_back(p.first);
                    p.second--;
                }
            }
        }
        else{
            vector<char> arr;
            for(auto &p:cnt)
                arr.push_back(p.first);

            if(cnt[arr[0]]-2<=n-cnt[arr[0]]){
                int ptr = 1;
                answ.push_back(arr[0]);
                answ.push_back(arr[0]);
                cnt[arr[0]]-=2;
                while(cnt[arr[0]]){
                    if(cnt[arr[ptr]]==0) ptr++;
                    answ.push_back(arr[ptr]);
                    cnt[arr[ptr]]--;
                    answ.push_back(arr[0]);
                    cnt[arr[0]]--;
                }
                for(auto c:arr){
                    while(cnt[c]){
                        answ.push_back(c);
                        cnt[c]--;
                    }
                }
            }
            else{
                if(cnt.size()==2){
                    answ.push_back(arr[0]), cnt[arr[0]]--;
                    while(cnt[arr[1]]){
                        answ.push_back(arr[1]);
                        cnt[arr[1]]--;
                    }
                    while(cnt[arr[0]]){
                        answ.push_back(arr[0]);
                        cnt[arr[0]]--;
                    }
                }
                else{
                    int ptr = 0;
                    answ.push_back(arr[0]), cnt[arr[0]]--;
                    if(ptr+1<cnt.size()){
                        answ.push_back(arr[ptr+1]), cnt[arr[ptr+1]]--;
                    }
                    while(cnt[arr[0]]){
                        answ.push_back(arr[0]);
                        cnt[arr[0]]--;
                    }
                    if(ptr+2<cnt.size()){
                        answ.push_back(arr[ptr+2]), cnt[arr[ptr+2]]--;
                    }
                    for(auto c:arr){
                        while(cnt[c]){
                            answ.push_back(c);
                            cnt[c]--;
                        }
                    }
                }
            }
        }

        cout << answ <<"\n";

    }

    return 0;
}