#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

bool Branje_Stevil(vector<int>& vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void Izpis_Stevil(int* polje, int velikost) {//tu sem zbrisal ven unsigned
    ofstream output("out.txt");

    for (int i = 0; i < velikost; i++)
        output << polje[i] << ' ';
}

int main(int argc, const char* argv[]) {
    vector<int> A;

    if (argc < 3) return 0;
    if (!Branje_Stevil(A, argv[2])) return 0;

    if (argv[1][0] == '1') {	//counting sort

      //  if (Branje_Stevil(A, argv[2])) {

            int najmanjsi = *min_element(A.begin(), A.end());

            for (int i = 0; i < A.size(); i++) {
                if (najmanjsi < 0) {
                    A[i] = A[i] - najmanjsi;
                }
            }
            int* a = new int[A.size()];
            for (int i = 0; i < A.size(); i++) {
                a[i] = A[i];
            }
            int sizeC = *max_element(A.begin(), A.end()) + 1;
            int* c = new int[sizeC];

            for (int i = 0; i < sizeC; i++) {
                c[i] = 0;
            }

            for (int i = 0; i < A.size(); i++) {
                for (int k = 0; k < sizeC; k++) {
                    if (a[i] == k) {
                        c[k] = c[k] + 1;
                    }

                }

            }

            for (int i = 0; i < sizeC;i++) {
                if (i == 0) {
                    c[i] = c[i];
                }
                else {
                    c[i] = c[i] + c[i - 1];
                }

            }

            int* b = new int[A.size()];
            int indexB;

            for (int i = A.size() - 1; i >= 0; i--) {

               /*a[i] = b[c[a[i]] - 1];
                c[a[i]] -= 1;*/ 
                indexB = c[a[i]] - 1;
                b[indexB] = a[i];
                c[a[i]] = c[a[i]] - 1;

            }
            for (int i = 0; i < A.size(); i++) {
                a[i] = b[i];
            }

            for (int i = 0; i < A.size(); i++) {
                a[i] += najmanjsi;
            }


            for (int i = 0; i < A.size(); i++) {
                A[i] = a[i];
            }
            Izpis_Stevil(&A[0], A.size());

            delete[]a;
            delete[]b;
            delete[]c;

       // }
    }
    else {//Roman sort
       // if (Branje_Stevil(A, argv[2])) {

        int najmanjsi = *min_element(A.begin(), A.end());

        for (int i = 0; i < A.size(); i++) {
            if (najmanjsi < 0) {
                A[i] = A[i] - najmanjsi;
            }
        }
        int* a = new int[A.size()];
        for (int i = 0; i < A.size(); i++) {
            a[i] = A[i];
        }
        int sizeC = *max_element(A.begin(), A.end()) + 1;
        int* c = new int[sizeC];

        for (int i = 0; i < sizeC; i++) {
            c[i] = 0;
        }

        for (int i = 0; i < A.size(); i++) {
            for (int k = 0; k < sizeC; k++) {
                if (a[i] == k) {
                    c[k] = c[k] + 1;
                }

            }

        }

            int* b = new int[A.size()];
           for (int i = 0; i < A.size(); i++) {
                b[i] = 1;
            }

           for (int i = 0;i < sizeC; i++) {
               if (c[i] != 0) {
                   int temp = c[i];
                   while(temp>0){
                       for (int n = 0; n < A.size();n++) {
                           if (b[n] == 1) {
                               b[n] = i;
                               temp = temp - 1;
                               break;
                           }
                       }
                   }
               }
           }


            //for (int k = 0;k < A.size();k++) {
           /*for (int i = 0; i < sizeC; i++) {
               if (c[i] > 0) {
               for (int k = 0;k < A.size();k++) {

                   if (b[k] !=1) {
                       b[k] = i;
                       c[i] = c[i] - 1;
                       i = i - 1;
                   }
                   else {
                       break;
                   }
               }
           }
                }*/
            //}




            /*for (int i = 0; i < sizeC; i++) {
                if (c[i] != 0) {
                    for (int k = 1; k <= c[i];k++) {
                        for (int n = 0; n < A.size(); n++) {
                            if (b[n] == -1) {
                                b[n] = i;
                            }
                        }
                    }
                }
            }*/

            for (int i = 0; i < A.size(); i++) {
                a[i] = b[i];
            }

            for (int i = 0; i < A.size(); i++) {
               a[i] += najmanjsi;
            }
            for (int i = 0; i < A.size(); i++) {
                A[i] = a[i];
            }

            Izpis_Stevil(&A[0], A.size());

            delete[]a;
            delete[]b;
            delete[]c;

       // }
    }
    //Izpis_Stevil(&A[0], A.size());

    return 0;
}