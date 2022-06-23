#include <iostream>
#include "Element.h"
#include "SparseMatrix2D.h"
#include"Line.h"
using namespace std;

int main() {
    Line a(5,12);
    Element e(1,1,a);
    cout<<e.getValue().toString() <<endl;
    SparseMatrix2D bigLineMatrix(4, 10, Line(0, 0));
    bigLineMatrix.set(5, 5, a);

    cout << endl;
    for (int i = 0; i < bigLineMatrix.getSizeX(); i++) {
        for (int j = 0; j < bigLineMatrix.getSizeY(); j++) {
            cout << bigLineMatrix.at(i,j).toString() << (j != bigLineMatrix.getSizeY() - 1 ? " ; " : "");
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;

     SparseMatrix2D bigIntMatrix(4, 4, 0);
     bigIntMatrix.set(3, 3, 8);

     bigIntMatrix.set(1, 1, 2);
     bigIntMatrix.set(1, 2, 4);
     bigIntMatrix.clearColum(1);

     for (int i = 0; i < bigIntMatrix.getSizeX(); i++) {
         for (int j = 0; j < bigIntMatrix.getSizeY(); j++) {
             cout << bigIntMatrix.at(i,j) << (j != bigIntMatrix.getSizeY() - 1 ? " ; " : "");
         }
         cout << endl;
     }
    cout << endl;
    cout << endl;
     cout<<bigIntMatrix.at(8,9);

    return 0;
}
