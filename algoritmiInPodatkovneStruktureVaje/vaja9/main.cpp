#include <iostream>
#include<string>
#include <ctime>
#include<vector>
#include <chrono>
#include <fstream>


using namespace std;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::steady_clock;

class Povezava {
public:
    int pVozlisce;
    int qVozlisce;
    int cena;
};

void randomGeneriranje(int steviloVozlisc, vector<Povezava *> &A) {

    for (int i = 1; i < steviloVozlisc + 1; i++) {
        for (int k = i; k < steviloVozlisc + 1; k++) {//pazi 3-1 in 1-3 sta ista povezava
            if (i != k) {
                int random_variable1 = (std::rand() % 500) + 1;
                Povezava *povezava = new Povezava;
                povezava->cena = random_variable1;
                povezava->pVozlisce = i;
                povezava->qVozlisce = k;
                A.push_back(povezava);
            }
        }

    }

}

int deli(vector<Povezava *> &vec, int dno, int vrh) {
    int pivot = vec[dno]->cena;
    int l = dno;
    int d = vrh;

    while (l < d) {
        while (vec[l]->cena <= pivot && l < vrh) {
            l++;
        }
        while (vec[d]->cena >= pivot && d > dno) {
            d--;
        }
        if (l < d) {
            Povezava *temp;
            temp = vec[l];
            vec[l] = vec[d];
            vec[d] = temp;
        }
    }
    Povezava *temp1;
    temp1 = vec[dno];
    vec[dno] = vec[d];
    vec[d] = temp1;
    return d;

}


void medianaHitroUredi(vector<Povezava *> &vec, int dno, int vrh) {
    if (dno > vrh) {}
    else {

        int mediana = dno + (vrh - dno) / 2;
        int temp1;
        temp1 = vec[mediana]->cena;
        vec[mediana]->cena = vec[dno]->cena;
        vec[dno]->cena = temp1;

        int p = deli(vec, dno, vrh);
        medianaHitroUredi(vec, dno, (p - 1));
        medianaHitroUredi(vec, (p + 1), vrh);

    }

}


vector<Povezava *> kruskal(vector<Povezava *> &A, int steviloVozlisc) {

    medianaHitroUredi(A, 0, A.size() - 1);
    vector<Povezava *> R;

    vector<int> skupine(steviloVozlisc + 1, 0);
    int a = 0;
    for (Povezava *&x: A) {
        a++;
        if (skupine[x->pVozlisce] != 0 && skupine[x->qVozlisce] != 0 &&
            skupine[x->pVozlisce] == skupine[x->qVozlisce]) {//obe pripadata isti mnozici
            continue;
        } else if ((skupine[x->pVozlisce] != 0 && skupine[x->qVozlisce] != 0) &&
                   (skupine[x->pVozlisce] != skupine[x->qVozlisce])) {
            //vozlisci v razlicni mnozici
            for (int i = 0; i < steviloVozlisc + 1; i++) {
                if (skupine[x->qVozlisce] == skupine[i]) {
                    skupine[i] = skupine[x->pVozlisce];
                }
            }
            R.push_back(x);
        } else if ((skupine[x->pVozlisce] == 0 && skupine[x->qVozlisce] != 0) ||
                   (skupine[x->pVozlisce] != 0 && skupine[x->qVozlisce] == 0)) {
            //ena se ni v nobeni druga pa v eni
            if (skupine[x->qVozlisce] > skupine[x->pVozlisce]) {
                skupine[x->pVozlisce] = skupine[x->qVozlisce];
            } else if (skupine[x->qVozlisce] < skupine[x->pVozlisce]) {
                skupine[x->qVozlisce] = skupine[x->pVozlisce];
            }
            R.push_back(x);

        } else if (skupine[x->pVozlisce] == 0 && skupine[x->qVozlisce] == 0) {
            //nobena v nobeni
            skupine[x->qVozlisce] += a;
            skupine[x->pVozlisce] += a;
            R.push_back(x);
        }
        if(R.size()==steviloVozlisc-1){
            return R;
        }
    }
    cout<<"napaka";
    return R;
}

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "SKLAD:" << endl;
    cout << "1 ... preberi graf iz datoteke" << endl;
    cout << "2 ... generiraj nakljucni graf" << endl;
    cout << "3 ... pozeni" << endl;
    cout << "4 ... izpis sprejetih povezav" << endl;
    cout << "5...EXIT " << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void beriIzDatoteke(vector<Povezava *> &A, int &steviloVozlisc) {
    ifstream f("graf.txt");
    int steviloPovezav, q, p, cena1;
    steviloVozlisc = 0;


    f >> steviloVozlisc;
    f >> steviloPovezav;
    for (int i = 0; i < steviloPovezav; i++) {
        f >> p >> q >> cena1;
        Povezava *povezava = new Povezava;
        povezava->cena = cena1;
        povezava->pVozlisce = p;
        povezava->qVozlisce = q;
        A.push_back(povezava);
    }
}

int main() {
    std::srand(std::time(NULL));
    bool running = true;
    int selection;
    int userInput;
    vector<Povezava *> A;
    int steviloVozlisc;

    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                beriIzDatoteke(A, steviloVozlisc);

                break;


            case 2:
                cout << "vnesi stevilo vozisc za nakljucen graf:\n";
                cin >> userInput;
                steviloVozlisc = userInput;
                randomGeneriranje(steviloVozlisc, A);


                break;

            case 3:
                cout << " stevilo vhodnih vozlisc:" << steviloVozlisc << "\n";
                cout << "stevilo vhodnih povezav:" << A.size() << "\n";
                start = std::chrono::steady_clock::now();
                cout << "stevilo povezav v resitvi:" << kruskal(A, steviloVozlisc).size() << "\n";
                end = std::chrono::steady_clock::now();
                std::cout << "Trajanje: " << chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                          << "ns";
                break;

            case 4:
                cout << "sprejete povezave:\n";
                for (int i = 0; i < kruskal(A, userInput).size(); i++) {
                    cout << kruskal(A, steviloVozlisc)[i]->qVozlisce << "\t";
                    cout << kruskal(A, steviloVozlisc)[i]->pVozlisce << "\t";
                    cout << kruskal(A, steviloVozlisc)[i]->cena << "\n";
                }

                break;

            case 5:
                running = false;
                break;

            default:
                cout << "Napacna izbira!" << endl;
                break;

        }
        cout << endl;
    } while (running);


    return 0;
}
