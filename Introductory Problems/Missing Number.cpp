#include <iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sum=0;
    for(int i=0;i<n-1;i++){
        int t;
        cin>>t;
        sum+=t;
    }
    cout<<(n+1)*n/2-sum;
    return 0;
}