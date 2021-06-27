/*
 * POJ 1837 Balance
 * 01背包;
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxV = 20*25*15+10;
const int maxn = 24;
int cost[maxn];
int pos[maxn];
int dp[maxn][2*maxV];

void init(){
    memset(dp, 0, sizeof dp);
    dp[0][7500] = 1; //初始平衡状态
}

int main(){
    const int posOffset = 15000;
    int numOfPos, n;
    cin >>numOfPos >>n;
    for(int i=1; i<=numOfPos; ++i) cin >>pos[i]; // 钩子位置，可复数
    for(int i=1; i<=n; ++i) cin >>cost[i]; // 砝码重量
    init();
    for(int i=1; i<=n; ++i)
        for(int j=0; j<=15000; ++j)
            for(int k=1; k<=numOfPos; ++k){
                dp[i][j+cost[i]*pos[k]] += dp[i-1][j];
            }
    cout <<dp[n][7500];


    return 0;
}
