#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n,x;
    cin>>n>>x;
    vector<int>dp(x+1,0);
    vector<int>price(n);
    vector<int>page(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>page[i];
    }
    for(int j=0;j<n;j++){
        for(int i=x;i>0;--i){
            if(price[j]>i)continue;
            dp[i]=max(dp[i],dp[i-price[j]]+page[j]);
        }
    }
    cout<<dp[x];
    return 0;
}