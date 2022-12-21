#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("coupon.in");
    ofstream out("coupon.out");

    int n = 0, b = 0, x1 = 0, sum = 0;
    float a = 0;
    int *c = new int[n];
    float *x = new float[n];
    float *x_result = new float[n];

    in >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        in >> c[i];
    }

    x1 = 100;  // temporary (set it to something like b / c[0])
    int tempSize = x1;
    x1 += 1;
    x[0] = x1;
    for (int i = 0; i <= tempSize; i++) {
        x1 -= 1;

        for (int k = 0; k < n; k++) {
            x[k] = k == 0
                       ? x1
                       : x[k - 1] * 0.8;  // is this ok? pros thn k. efraimidou
            if (x[k] >= 10) {
                x_result[k] = x[k] * c[k];
                sum = sum + x_result[k];
            } else {
                x[k] = 0;
                x_result[k] = 0;
            }
        }

        if (sum <= b) break;
    }

    // printing output
    out << sum;
    for (int i = 0; i < n; i++) {
        out << endl << x[i];
    }

    delete[] c, x, x_result;
}