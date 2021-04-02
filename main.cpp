#include <iostream>
#include "Matrix.h"
#include "SquareMatrix.h"
#include "Identity.h"

using namespace std;

int main() {
    int n;

//    cin >> n;
//    SquareMatrix a(n);
//    cin >> a;
//
//    cin >> n;
//    SquareMatrix b(n);
//    cin >> b;
//
//    cin >> n;
//    SquareMatrix c(n);
//    cin >> c;

    cin >> n;
    Identity i(n);
    cout << i << endl;
    cout << i.transposed() << endl;

//
//    try
//    {
//        cout << a + b << endl;
//    } catch (exception& e) {
//        cout << e.what() << endl;
//    }
//
//    try
//    {
//        cout << b - a << endl;
//    } catch (exception& e) {
//        cout << e.what() << endl;
//    }
//
//    try
//    {
//        cout << c * a << endl;
//    } catch (exception& e) {
//        cout << e.what() << endl;
//    }
//
//    cout << a.transposed() << endl;

    return 0;
}
