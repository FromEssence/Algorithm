/*
*操作
×1. 区间乘法
*2. 区间加法
*3. 区间求和
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL a[N], f[N * 4], tag_k[N * 4], tag_b[N * 4], n, m, MOD;
void build(int x, int l, int r)
{
	tag_k[x] = 1;
	tag_b[x] = 0;
	if(l == r) f[x] = a[l] % MOD;
	else
	{
		int mid = (l + r) / 2;
		build(x * 2, l, mid);
		build(x * 2 + 1, mid + 1, r);
		f[x] = (f[x * 2] + f[x * 2 + 1]) % MOD;
	}
}
void downtag(int x, int l, int r)
{
	if(tag_k[x] == 1 && tag_b[x] == 0) return;
	int mid = (l + r) / 2;
	tag_k[x * 2] = tag_k[x * 2] * tag_k[x] % MOD;
	tag_k[x * 2 + 1] = tag_k[x * 2 + 1] * tag_k[x] % MOD;
	tag_b[x * 2] = (tag_b[x * 2] * tag_k[x] + tag_b[x]) % MOD;
	tag_b[x * 2 + 1] = (tag_b[x * 2 + 1] * tag_k[x] + tag_b[x]) % MOD;
	f[x * 2] = (f[x * 2] * tag_k[x] + tag_b[x] * (mid - l + 1)) % MOD;//[l, mid]
	f[x * 2 + 1] = (f[x * 2 + 1] * tag_k[x] + tag_b[x] * (r - mid)) % MOD;//[mid+1, r]
	tag_k[x] = 1;
	tag_b[x] = 0;
}
void change_k(int x, int l, int r, int pl, int pr, LL key)
{
	if(l >= pl && r <= pr)
	{
		tag_k[x] = tag_k[x] * key % MOD;
		tag_b[x] = tag_b[x] * key % MOD;
		f[x] = f[x] * key % MOD;
		return;
	}
	int mid = (l + r) / 2;
	downtag(x, l, r);
	if(pl <= mid) change_k(x * 2, l, mid, pl, pr, key);
	if(pr >= mid + 1) change_k(x * 2 + 1, mid + 1, r, pl, pr, key);
	f[x] = (f[x * 2] + f[x * 2 + 1]) % MOD;
}
void change_b(int x, int l, int r, int pl, int pr, LL key)
{
	if(l >= pl && r <= pr)
	{
		tag_b[x] = (tag_b[x] + key) % MOD;
		f[x] = f[x] + key * (r - l + 1) % MOD;
		return;
	}
	int mid = (l + r) / 2;
	downtag(x, l, r);
	if(pl <= mid) change_b(x * 2, l, mid, pl, pr, key);
	if(pr >= mid + 1) change_b(x * 2 + 1, mid + 1, r, pl, pr, key);
	f[x] = (f[x * 2] + f[x * 2 + 1]) % MOD;
}
LL get(int x, int l, int r, int pl, int pr)
{
	if(l >= pl && r <= pr) return f[x];
	int mid = (l + r) / 2;
	downtag(x, l, r);
	LL tmp = 0;
	if(pl <= mid) tmp = (tmp + get(x * 2, l, mid, pl, pr)) % MOD;
	if(pr >= mid + 1) tmp = (tmp + get(x * 2 + 1, mid + 1, r, pl, pr)) % MOD;
	return tmp;
}
int main()
{
	cin >> n >> MOD;
	for(int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	build(1, 1, n);
	cin >> m;
	for(int i = 1;i <= m;i++)
	{
		int type, l, r;
		LL key;
		scanf("%d%d%d", &type, &l, &r);
		if(type == 1)
		{
			scanf("%lld", &key);
			change_k(1, 1, n, l, r, key);
		}
		if(type == 2)
		{
			scanf("%lld", &key);
			change_b(1, 1, n, l, r, key);
		}
		if(type == 3)
			printf("%lld\n", get(1, 1, n, l, r));
	}
}
