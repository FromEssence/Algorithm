ll q_pow(ll a, ll b, int mod){
    if(!a) return 0;
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1, a=a*a%mod;
    }
    return ans;
}
