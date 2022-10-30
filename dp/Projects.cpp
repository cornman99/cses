#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<long long>>intv;
    for(int i=0;i<n;++i){
        int a,b,c;
        cin>>a>>b>>c;
        intv.push_back({a,b,c});
    }
    vector<long long>dp(n);

    sort(intv.begin(),intv.end(),[&](auto a,auto b){
        return a[1]<b[1];
    });
    map<int,int>end_to_id;
    for(int i=0;i<n;i++){
        dp[i]=i>=1?dp[i-1]:0;
        auto p=end_to_id.lower_bound(intv[i][0]);
        long long t=intv[i][2];
        if(p!=end_to_id.begin()){
            p=prev(p);
            t+=dp[p->second];
        }
        dp[i]=max(dp[i],t);
        if(!end_to_id.count(intv[i][1])||dp[end_to_id[intv[i][1]]]<dp[i])
            end_to_id[intv[i][1]]=i;
    }
    cout<<dp[n-1];
    return 0;
}