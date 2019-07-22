/*
* 可用于long long取模乘法
*/
ll q_mul(ll a, ll b, ll mod){
    if(!a | !b) return 0;

    ll ans=0;
    while(b){
        if(b&1) ans=(ans+a)%mod;
        b>>=1, a=a*2%mod;
    }
    return ans;
}
