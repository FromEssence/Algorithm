/*
* HDU 1686 AC 62MS
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long

vector<int> pi;
vector<int> match_pos;

//模式串的前缀函数
void prefix_function(string &s) {
  int n = (int)s.length();
  pi.resize(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
}

void kmp(string &p, string &t){
    int m = p.size();
    int n = t.size();

    int t_now = 0;
    int p_now = 0;

    while(t_now<n){
        while(t_now<n&&p_now<m&&t[t_now]==p[p_now])
            t_now++, p_now++;
        if(p_now==m) match_pos.push_back(t_now-m+1);
        if(p_now) p_now = pi[p_now-1];
        else  t_now++; //主串当前位置与p[0]不同，前进
    }
}

int main(){
    ios::sync_with_stdio(false);
    string w, t;
    int T;
    cin >>T;
    while(T--){
        pi.clear();
        match_pos.clear();

        cin >>w >>t;

        prefix_function(w);
        kmp(w, t);
        cout <<match_pos.size() <<'\n';
    }
    return 0;
}
