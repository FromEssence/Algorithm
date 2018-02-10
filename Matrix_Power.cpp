#define ll long long
const ll N=10;
const ll MOD=1e9+7;
ll tmp[N][N];
void multi(ll a[][N],ll b[][N],ll n)
{
    memset(tmp,0,sizeof tmp);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
        for(ll k=1;k<=n;k++)
        tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j]+MOD)%MOD; //小心这里会不会因为+MOD而越界
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
        a[i][j]=tmp[i][j];
}
ll res[N][N];
void Pow(ll a[][N],ll n, ll k)
{
    memset(res,0,sizeof res);
    for(ll i=1;i<=n;i++) res[i][i]=1;
    while(k)
    {
        if(k&1)
            multi(res,a,n);//res=res*a;复制直接在multi里面实现了；
        multi(a,a,n);//a=a*a
        k>>=1;
    }
}
