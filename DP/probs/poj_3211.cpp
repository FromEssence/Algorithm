/*
 * POJ 3211 Washing Clothes
 * 01背包; 关键在于确定问题模型
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <string>
using namespace std;
const int maxV = 1000*100+10;
int dp[maxV];
vector<int> group[10];

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
    ios::sync_with_stdio(false);
    map<string, int> col_to_int;
    string col_name;
    int num_of_color, n, time;
    while(cin >>num_of_color >>n) {
        if(num_of_color+n==0) break;
        int ans_time = 0;
        col_to_int.clear();
        for(int i=0; i<10; ++i) group[i].clear();// 不要遗忘
        for (int i = 0; i < num_of_color; ++i) {
            cin >> col_name;
            col_to_int[col_name] = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >>time >>col_name;
            group[col_to_int[col_name]].push_back(time);
        }

        // 对每个颜色进行背包；颜色顺序与总时间无关
        for(int i=0; i<num_of_color; ++i){
            init();
            if(group[i].size()==0) continue; // 防止有颜色为空;注意不能使用break
            int num = group[i].size();
            int group_sum = 0;
            for(int j=0; j<num; ++j){
                group_sum += group[i][j];
            }
            for(int j=0; j<num; ++j){
                dp_zero_one(group[i][j], group[i][j], group_sum/2);
            }
            ans_time += max(dp[group_sum/2], group_sum-dp[group_sum/2]); //其实肯定是后面>=前面
        }
        cout <<ans_time <<"\n";
    }

    return 0;
}
