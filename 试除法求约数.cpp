#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> get(int n){
    vector<int> res;
    for(int i=1;i<=n/i;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i){
                res.push_back(n/i);
            }
            // 防止重复加入

        }
    }
    sort(res.begin(),res.end());
    return res;
}
// 采用vector来储存答案
int main(){
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        vector<int> res=get(a);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;

}