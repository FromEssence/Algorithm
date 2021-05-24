
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1000+10;

class Extend_Euclid{

private:
	int size_e = 0; // number of equations
	int max_size; //
	int a[maxn];
	int m[maxn];

	/*
	* no need to make sure that a is nl then b
	*/
	ll gcd(ll a, ll b){
		return b ? gcd(b, a%b) : a;
	}

	/*
	* if you want the minimal non-neg x, (x mod b+b) mod b is the answer
	*/
	void extend_Euclid(ll a, ll b, ll &x, ll &y){
		if(b==0){
			x = 1;
			y = 0;
			return;
		}
		extend_Euclid(b, a%b, x, y);
		ll tmp = x;
		x = y;
		y = tmp-(a/b)*y;
	}

	bool merge(ll a1, ll m1, ll a2, ll m2, ll &new_a, ll &new_m){

		if((a1-a2) % gcd(m1, m2) != 0){
            //cout <<"here: " <<a1-a2 <<' ' << gcd(m1, m2) <<'\n';
			return false;
		}

		ll x=0, y=0;
		extend_Euclid(m1, m2, x, y);
		new_a = a1 - m1/gcd(m1, m2)*x*(a1-a2);
		new_m = m1*m2/gcd(m1, m2);
		//new_a = a2 + m2/gcd(m1, m2)*y*(a1-a2);
		new_a = (new_a%new_m + new_m) % new_m;
		return true;
	}

public:
	Extend_Euclid(int size){
		size_e = size;
	}

	void read(){
		for (int i = 0; i < size_e; ++i){
			cin >>m[i];
		}
		for (int i = 0; i < size_e; ++i){
			cin >>a[i];
		}
	}

	ll solve(){
	    //cout <<gcd(14, 57) <<'\n';
		//merge equation i and i-1
		ll new_a=a[0], new_m=m[0];
		for (int i = 1; i < size_e; ++i){
			if(!merge(new_a, new_m, a[i], m[i], new_a, new_m)){
				return -1;
			}
		}
        ll res = (new_a%new_m + new_m) % new_m;
        if(res==0) return new_m;  //有些题目不允许答案为0，可能需要适当改动
        else return res;
	}

};

/*
*以HDU 3579为例讲解应用
*/
int main(){
	int T, n, cnt=0;
	cin >>T;
	while(T--){
		cin >>n;
		Extend_Euclid ee(n);
		ee.read();
		ll res = ee.solve();
		cout <<"Case " <<++cnt <<": ";

		cout <<res <<'\n';

	}
	return 0;
}
