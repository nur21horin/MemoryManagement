#include "iostream"
#include "vector"
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%3==0){
            cout<<0<<endl;
        }else{
            int ans=3-(n%3);
            cout<<ans<<endl;
        }
    }
    return 0;
}