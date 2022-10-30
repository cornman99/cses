#include <iostream>
#include <vector>
#include <set>
#include <numeric>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    int sum=accumulate(x.begin(),x.end(),0);
    set<int>s;
    s.insert(0);
    for(int t:x){
        for(int i=sum;i>0;i--){
            if(s.count(i)){
                continue;
            }
            if(s.count(i-t)){
                s.insert(i);
            }
        }
    }
    cout<<s.size()-1<<endl;
    for(auto p=next(s.begin());p!=s.end();p++){
        cout<<*p<<" ";
    }
    return 0;
}