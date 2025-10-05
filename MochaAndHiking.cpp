#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<=n;i++){
           if(arr[i]==0){
            ans.push_back(n+1-i);
           }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
    return 0; 
}