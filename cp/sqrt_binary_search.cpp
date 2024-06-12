#include<bits/stdc++.h>
#define ld long double
using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    double lf, rt, n;
    cin >> n;

    lf = 1, rt = n;

    cout << setprecision(7) << fixed;

    while (1) {
        double mid = (lf + rt) / 2;
        double mid_sq = mid * mid;
        db(lf, rt, mid, mid_sq);

        if (mid * mid >= n) {
            rt = mid;
        }
        else {
            lf = mid;
        }

        if (rt - lf < 0.000001) {
            break;
        }
    }

    cout << lf << " " << rt << '\n';

}