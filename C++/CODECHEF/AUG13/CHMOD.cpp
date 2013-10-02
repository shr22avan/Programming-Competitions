#include<iostream>
#include<cstdio>
#define getlint(a) scanf("%lld",&a)
#define MAX 100000
#define MOD 1000000007
#define ll long long
using namespace std;

ll re[MAX],q[MAX],a[MAX];

ll fastpow(ll a, ll b, ll mod) {

	if(a == 0)
		return 0;
	if(b == 0)
		return 1%mod;
	if(b == 1)
		return a%mod;
	ll temp = fastpow(a, b/2, mod);
	if(b%2)
		return (((temp*temp)%mod)*a)%mod;
	return (temp*temp)%mod;

}

ll modinverse(ll a, ll mod) {

	return fastpow(a,mod-2,mod);

}

int main() {

	ll n,t,l,r,m;

	getlint(n);

	for(int i = 0; i < n; i++) {

		getlint(a[i]);

	}

	re[0] = a[0];

	for(int i = 1; i < n; i++) {

		re[i] = re[i-1] * a[i];
		q[i] = re[i]/MOD;
		if(re[i] >= MOD)
			re[i] %= MOD;

	}

	for(int i = 1; i < n; i++)

		q[i] += a[i]*q[i-1];

	ll val, val1, val2;
	getlint(t);

 
	while(t--) {

		getlint(l);
		getlint(r);
		getlint(m);

		l--,r--;

		if(l == 0)
 
			val = ((((q[r]%m) * (MOD%m))%m) + (re[r]%m))%m;

		else {

			val2 = ((q[r]%m * MOD%m) + re[r]) % m;
			val1 = modinverse(re[l-1],MOD) % m;
			val = (val2 * val1) % m;

		}

		printf("%lld\n", val);

	}
	
	return 0;
}
