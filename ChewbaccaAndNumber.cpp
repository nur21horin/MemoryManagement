#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
   
    if(s.empty()){
        return 0;
    }
    for(int i=0;i<(int)s.size();i++){
        int t=s[i]-'0';
        int diffrence=9-t;
        if(i==0 && t==9){
            continue;
        }
        
        if(diffrence< t){
            s[i]=char('0'+diffrence);
        }
    }
    cout<<s<<endl;
    return 0;
}