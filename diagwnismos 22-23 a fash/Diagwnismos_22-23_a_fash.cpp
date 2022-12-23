/* USER: theodoridis_geo35pdp
LANG: C++
TASK: coupon */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("coupon.in");
    ofstream out("coupon.out");

    int n = 0, b = 0, x1 = 0, sum = 0;
    float a = 0;
    int *c = new int[n];
    int *x = new int[n];
    int *x_result = new int[n];

    in >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        in >> c[i];
    }

    x1 = b / c[0];
    int tempSize = x1;
    x1 += 1;
    for (int i = 0; i <= tempSize; i++) {
        x1 -= 1;
        sum = 0;
        for (int k = 0; k < n; k++) {
            if (k == 0) {
                x[0] = x1;
            } else {
                x[k] = x[k - 1] * a;
            }

            if (x[k] >= 10) {
                x_result[k] = x[k] * c[k];
                sum = sum + x_result[k];

                if (sum > b) {
                    break;
                }
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