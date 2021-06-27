/*
 * POJ 3093 Margaritas on the River Walk
 * 01背包; 装满方案计数
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxV = 1000+10;
const int maxn = 32;
int cost[maxn];
int dp[maxV];

void init(){
    memset(dp, 0, sizeof dp);
    dp[0] = 1; // 为了计数
}
void dp_zero_one_count(int c, int vol){
    // 花费、权重、体积
    // 在一维数组上滚动
    // 计算装满当前容量背包的方案数
    for(int v=vol; v>=c; --v){
        dp[v] = (dp[v]+dp[v-c]);
    }
}

int main(){
    int case_num, n, vol;

    cin >>case_num;
    for(int i=1; i<=case_num; ++i){
        int presum=0; // 枚举时从后向前，所以这里不需要数组
        cin >>n >>vol;
        for(int j=0; j<n; ++j)
            cin >>cost[j], presum+=cost[j];
        sort(cost, cost+n);
        if(cost[0] > vol){
            cout <<i <<' ' <<0 <<endl;
            continue;
        }
        if(presum <= vol){
            // 这个判断是必须的
            // case: n=5, vol=5, cost[]={1,1,1,1}
            cout <<i <<' ' <<1 <<endl;
            continue;
        }
        init();
        int ans = 0;
        for(int j=n-1; j>=0; --j){
            presum -= cost[j];
            for(int v=max(vol-presum-(cost[j]-1),0); v<=vol-presum; ++v){
                ans += dp[v];
            }
            dp_zero_one_count(cost[j], vol);

        }
        cout <<i <<" "<<ans <<endl;
    }
    return 0;
}
