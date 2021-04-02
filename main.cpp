#include <iostream>
#include "Matrix.h"
#include "SquareMatrix.h"
#include "Identity.h"
#include "EliminationMatrix.h"
#include "PermutationMatrix.h"

using namespace std;

int main() {
    int n;

    cin >> n;
    SquareMatrix<double> a(n);
    cin >> a;

    EliminationMatrix<double> elim21A(
            n, 1, 0, - a.getElementAt(1, 0) / (double) a.getElementAt(0, 0)
            );
    cout << elim21A << endl;

    auto b = elim21A * a;
    cout << b << endl;

    PermutationMatrix<int> p(n, 0, 1);
    cout << p << endl;

    cout << p * a << endl;

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
