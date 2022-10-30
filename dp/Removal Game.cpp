#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    vector<vector<long long>>dp(n,vector<long long>(n));
    vector<long long>pre(n+1);
    for(int i=0;i<n;++i){
        dp[i][i]=x[i];
        pre[i+1]+=x[i]+pre[i];
    }//pre[i+1]
    for(int l=2;l<=n;l++){
        for(int i=0;i+l-1<n;i++){
            int j=i+l-1;
            dp[i][j]=x[i]+pre[j+1]-pre[i+1]-dp[i+1][j];
            dp[i][j]=max(dp[i][j],x[j]+pre[j]-pre[i]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1];
    return 0;
}