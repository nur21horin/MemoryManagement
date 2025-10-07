#include "bits/stdc++.h"
#include <type_traits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int totalA=0,totalB=0;

        for(char a:s){
            if(a=='a') totalA++;
            else totalB++;
        }

        int D=totalA-totalB;
        if(D==0) {
            cout<<0<<endl;
            continue;
        }
        map<int,int> mp;
        mp[0]=0;
        int cur=0;
        int min_len=n+1;

        for(int i=1;i<=n;i++){
            char c=s[i-1];
            cur+=(c=='a'?1:-1);
            int target=cur-D;
            auto it=mp.find(target);
            if(it!=mp.end()){
                int j=it->second;
                int len=i-j;
                if(len<min_len) min_len=len;
            }
            mp[cur]=i;
        }

        if(min_len==n){
            cout<<-1<<endl;
        }else{
            cout<<min_len<<endl;
        }

    }

    return 0;

}