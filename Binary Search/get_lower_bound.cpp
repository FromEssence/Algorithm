#define ll long long

/*
*在[l,r]区间二分满足m*(m+1)/2 <= n的最大m 
*/ 
ll binSearch(ll l, ll r, ll n){
	while(l < r){
		ll mid = (l+r) >> 1;
		if(((double)(mid)) * (mid+1)/2 < n){ //使用double来判断，防止爆long long
			l = mid+1;
		}
		else r = mid;
	}
	return l;
	
}
