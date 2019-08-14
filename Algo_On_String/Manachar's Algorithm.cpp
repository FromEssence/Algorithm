//模板测试：http://acm.hdu.edu.cn/showproblem.php?pid=3068
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 120000;
const int MAX = 0x3f3f3f3f;

int p[maxn*2]; //注意需要2倍空间，因为需要插入字符

/*
** @str 插入特殊字符后的字符串
** @P[] 存储以str[i]为中心最长的回文串半径，注意空间需不小于原字符串2倍
** @len str长度
*/
void Manachar(string &str, int P[], int len){
    memset(P, 0, sizeof(int)*len);
    int C=0, R=-1, rad;
    for(int i=0; i<len; i++){
        if(i < R){
            rad = min(P[2*C-i], R-i);
        }
        else rad=0;
        //Try to extend
        while(i+rad+1 < len && i-(rad+1)>=0 && str[i-rad-1]==str[i+rad+1]){
            rad++;
        }
        P[i] = rad;
        if(i+rad > R){
            C=i;
            R=i+rad;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    string s;
    while(cin >>s){
        string ss(s.size()*2+1, '0');
        for(int i=0; i<s.size(); i++){
            ss[i*2]='#', ss[i*2+1]=s[i];
        }
        ss[ss.size()-1]='#';
        Manachar(ss, p, ss.size());
        int res = 0;
        for(int i=0; i<ss.size(); i++)
            res = max(res, p[i]); //p[]存储为半径
        cout <<res<<'\n';
    }
    return 0;
}
