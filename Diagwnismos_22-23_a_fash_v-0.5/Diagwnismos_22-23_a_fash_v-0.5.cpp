#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    ifstream in("coupon.in");
    ofstream out("coupon.out");
    int n = 0, b = 0, sum = 0;
    float a = 0, x1 = 0;
    /*
    n = poses oikonomikes omades (6)
    a = poso to opoio katevazei to poso pou tha parei h kathe oikonomikh omada
    (0.5) b = synoliko poso pou tha paroun oles oi omades mazi (1000000) c[n] =
    poses oikogeneies exei h kathe oikonomikh omada
  */
    in >> n >> a >> b;
    int* c = new int[n];
    float* x = new float[n];
    for (int i = 0; i < n; i++) {
        in >> c[i];

        // initializing x
        x[i] = 0;
    }
    // καντο με arrays για να φτιάξεις το πρόβλημα με τα exponentials
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (c[i] >= 10) {
                x1 += c[i];
            }
        } else {
            if (c[i] * pow(a, i) >= 10) x1 += c[i] * (pow(a, i));
        }
    }
    x1 = b / x1;
    x[0] = x1;
    for (int i = 0; i < n; i++) {
        if (x1 * pow(a, i) >= 10) {
            x[i] = x1 * (pow(a, i));
        } else {
            x[i] = 0;
        }
        sum += x[i] * c[i];
    }
    out << sum << endl;

    // printing output
    for (int i = 0; i < n; i++) {
        out << x[i];

        if (i != n - 1) {
            out << endl;
        }
    }
    delete[] c, x;
}