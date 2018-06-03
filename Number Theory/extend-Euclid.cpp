/*
* HDU 2669
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
	return b ? gcd(b, a%b):a;
}

/*
* 求解 ax + by = gcd(a, b)的一个整数解
* 通解 x = x0+bk, y = y0-ak
*/
ll extgcd(ll a, ll b, ll& x, ll& y)
{
    ll d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}



int main(){
	ll a, b;
	while(cin >>a >>b){
		if(gcd(a, b) != 1){
			cout <<"sorry\n";
			continue;
		}
		ll x0=0, y0=0;
		extgcd(a, b, x0, y0);
		//通解 x = x0+bk, y = y0-ak
		//here, a, b>0
		if(x0 < 0){
			if(x0 % b==0)
				x0 = x0 + (-x0)/b*b;
			else
				x0 = x0 + (-x0)/b*b+b;
		}
		else{
			x0 = x0 - x0/b*b;
		}
		y0 = (1-a*x0)/b;
		cout <<x0 <<" "<<y0 <<'\n';
	}
	return 0;
}
