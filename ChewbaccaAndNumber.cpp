#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    if(s.empty()){
        return 0;
    }
    for(int i=0;i<n;i++){
        int t=s[i]-'0';
        int diffrence=9-t;
        if(i==0 && diffrence==9){
            continue;
        }
        else
        if(diffrence< t){
            s[i]=char('0'+diffrence);
        }
    }
    cout<<s<<endl;
    return 0;
}