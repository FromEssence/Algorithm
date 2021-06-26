/*
 * POJ 3624 Charm Bracelet
 * 01背包模板题
 */
#include <iostream>
#include <cstring>
using namespace std;
const int maxV = 13000;
const int maxn = 3500;
int cost[maxn];
int weight[maxn];
int dp[maxV]; // 内存不足以开二维

void init(){
    memset(dp, 0, sizeof dp);
}
void dp_zero_one(int c, int w, int vol){
    // 花费、权重、体积
    // 在一维数组上滚动
    for(int v=vol; v>=c; --v){
        dp[v] = max(dp[v], dp[v-c]+w);
    }
}
int main(){

    init();
    int n, vol;
    cin >>n >>vol;
    for (int i = 0; i < n; ++i) {
        cin >>cost[i] >>weight[i];
    }
    for(int i=0; i<n; ++i){
        dp_zero_one(cost[i], weight[i], vol);
    }
    cout <<dp[vol] <<endl;
    return 0;
}
