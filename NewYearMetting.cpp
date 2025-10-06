#include "iostream"
#include "vector"
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int x1,x2,x3;
    cin>>x1>>x2>>x3;
    int arr[3]={x1,x2,x3};
    sort(arr,arr+3);
    //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<endl;
    int high=arr[2];
    int mid=arr[1];
    int low=arr[0];
    int ans=(high-mid)+(mid-low);
    cout<<ans<<endl;
    return 0;
}