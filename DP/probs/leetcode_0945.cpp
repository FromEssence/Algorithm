class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int dp[20+5][5000+5];
        memset (dp[0],0x80,sizeof (dp[0])); //重要的初始化 -2139062144
        //cout <<dp[0][1]<<endl;
        dp[0][0] = 0;
        int n = rods.size();
        for(int i=1; i<=n; i++)
            for(int dif=0; dif<5001; dif++){
                dp[i][dif] = dp[i-1][dif];
                
                if(dif >= rods[i-1])
                    // 加到前i个状态下的大的一堆
                    dp[i][dif] = max(dp[i][dif], dp[i-1][dif-rods[i-1]]+rods[i-1]);
                if(dif+rods[i-1]<5001)
                    // 加到前i个状态下小的一堆，且当前这根的长度小于原差
                    dp[i][dif] = max(dp[i][dif], dp[i-1][dif+rods[i-1]]);
                if(dif<=rods[i-1])
                    // 加到前i个状态下小的一堆，且当前这根的长度大于原差
                    dp[i][dif] = max(dp[i][dif], dp[i-1][rods[i-1]-dif]+dif);
            }
        return dp[n][0];
    }
};
