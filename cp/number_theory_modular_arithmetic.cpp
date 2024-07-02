int MOD = 1e9 + 7;
int add(int x, int y) {
	return (x % MOD + y % MOD) % MOD;
}
int sub(int x, int y) {
	return ((x % MOD - y % MOD) + MOD) % MOD;
}
int mul(int x, int y) {
	return ((x % MOD) * (y % MOD)) % MOD;
}
int powr(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = mul(res, x);
		x = mul(x, x);
		y >>= 1;
	}
	return res;
}
int inv(int x) {
	return powr(x, MOD - 2);
}
int divi(int a, int b) {
	return mul(a, inv(b));
}

const int N = 1e5;
int fact[N], invFact[N];
void precompute() {
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mul(i, fact[i - 1]);
	}
	invFact[N - 1] = inv(fact[N - 1]);
	for (int i = N - 2; i >= 0 ; i--) {
		invFact[i] = mul(i + 1, invFact[i + 1]);
	}
}

int nCr(int n, int r) {
	return mul(mul(fact[n], invFact[r]), invFact[n - r]);
}