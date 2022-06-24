#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

bool Branje_Stevil(vector<unsigned char>& vec, const char s[]) {
    ifstream input(s);
    unsigned int st;

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

void Izpis_Stevil(unsigned char* polje, int velikost) {
    ofstream output("out.txt");

    for (int i = 0; i < velikost; i++)
        output << polje[i] << ' ';
}

int main(int argc, const char* argv[]) {
    vector<unsigned char> A;

    if (argc < 3) return 0;
    if (!Branje_Stevil(A, argv[2])) return 0;

    if (argv[1][0] == '1') {


        unsigned char* a = new unsigned char[A.size()];

        for (int i = 0; i<A.size(); i++)
        {
            a[i] = A[i];
        }

        unsigned char* d = new unsigned char[A.size()];
        //bool bit = (A[i] >> k) & 1; ta & 1 pomeni da je vrednost 0 ali 1
        for (int k = 0; k < 8; k++) {//to je za vseh 8 bitov


            for (int i = 0; i < A.size(); i++) {
                d[i]=(a[i] >> k) & 1;
            }

           
            unsigned char* c = new unsigned char[2];
            for (int i = 0; i < 2; i++) {
                c[i] = 0;
            }
            for (int i = 0; i < A.size(); i++) {
                for (int n = 0; n < 2; n++) {
                    if (d[i] == n) {
                        c[n] = c[n] + 1;
                    }

                }

            }
            for (int i = 0; i < 2;i++) {
                if (i == 0) {
                    c[i] = c[i];
                }
                else {
                    c[i] = c[i] + c[i - 1];
                }

            }
            unsigned char* b = new unsigned char[A.size()];
            int indexB;

            for (int i = A.size() - 1; i >= 0; i--) {

                indexB = c[d[i]] - 1;
                b[indexB] = a[i];
                c[d[i]] = c[d[i]] - 1;

            }
            // b je urejeno polje a
            for (int m = 0; m < A.size(); m++) {
                a[m] = b[m];
            }
            delete[]a;
            delete[]b;
            delete[]c;


        }
        for (int i = 0; i < A.size();i++) {
            A[i] = a[i];
        }
        Izpis_Stevil(&A[0], A.size());


    }

    return 0;
}