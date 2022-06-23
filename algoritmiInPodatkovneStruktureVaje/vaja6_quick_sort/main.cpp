
#include<iostream>
#include<vector>
#include <chrono>

using namespace std;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::steady_clock;

int deli(vector<int> &vec, int dno, int vrh) {
    int pivot = vec[dno];
    int l = dno;
    int d = vrh;

    while (l < d) {
        while (vec[l] <= pivot && l < vrh) {
            l++;
        }
        while (vec[d] >= pivot && d > dno) {
            d--;
        }
        if (l < d) {
            int temp;
            temp = vec[l];
            vec[l] = vec[d];
            vec[d] = temp;
        }
    }
    int temp1;
    temp1 = vec[dno];
    vec[dno] = vec[d];
    vec[d] = temp1;
    return d;

}


void hitroUredi(vector<int> &vec, int dno, int vrh) {
    if (dno < vrh) {
        int p = deli(vec, dno, vrh);
        hitroUredi(vec, dno, (p - 1));
        hitroUredi(vec, (p + 1), vrh);
    }

}


void ustvariNarascajoceZaporedje(int key, vector<int> &vec) {
    for (int i = 0; i < key; i++) {
        vec.push_back(i);
    }

}

void ustvariPadajoceZaporedje(int key, vector<int> &vec) {
    for (int i = key - 1; i >= 0; i--) {
        vec.push_back(i);
    }
}

void ustvariNakljucnoZaporedje(int key, vector<int> &vec) {
    for (int i = 0; i < key; i++) {
        int random_variable = (std::rand() % 1000000) + 1;
        vec.push_back(random_variable);
    }


}

void izpisZaporedja(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << ' ';
    }

}

bool jeUrejeno(vector<int> vec, int dno, int vrh) {
    for (int i = dno; i <= vrh - 2; i++) {
        if (vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}

void medianaHitroUredi(vector<int> &vec, int dno, int vrh) {
    if (dno > vrh) {}
    else {

        int mediana = dno + (vrh - dno) / 2;
        int temp1;
        temp1 = vec[mediana];
        vec[mediana] = vec[dno];
        vec[dno] = temp1;

        int p = deli(vec, dno, vrh);
        medianaHitroUredi(vec, dno, (p - 1));
        medianaHitroUredi(vec, (p + 1), vrh);

    }

}

void bubleSort(vector<int> &vec, int dno, int vrh) {
    int temp;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[i]) {
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}


void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "SKLAD:" << endl;
    cout << "1 ... Genereiraj narascujoce zaporedje" << endl;
    cout << "2 ... Generiraj padajoce zaporedje" << endl;
    cout << "3 ...  Generiraj naključno zaporedje" << endl;
    cout << "4... Izpis zaporedja" << endl;
    cout << "5... Preveri ali je zaporedje urejeno" << endl;
    cout << "6... Uredi s hitrim urejanjem brez mediane" << endl;
    cout << "7 ...Uredi s hitrim urejanjem z mediano" << endl;
    cout << "8...Uredi z drugim algoritmom za urejanje " << endl;
    cout << "9...EXIT " << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}


int main() {
    std::srand(std::time(NULL));
    bool running = true;
    int selection;
    int n1, n2, n3;

    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;


    vector<int> vec;
    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                cout << "Vstavi velikost narascujocega zaporedja:" << "\n";
                cin >> n1;
                ustvariNarascajoceZaporedje(n1, vec);

                break;

            case 2:
                cout << "Vstavi velikost padajocega zaporedja:" << "\n";
                cin >> n2;
                ustvariPadajoceZaporedje(n2, vec);

                break;

            case 3:
                cout << "Vstavi velikost nakljucnega zaporedja:" << "\n";
                cin >> n3;
                ustvariNakljucnoZaporedje(n3, vec);
                break;


            case 4:
                izpisZaporedja(vec);

                break;

            case 5:
                if (jeUrejeno(vec, 0, vec.size()) == true) {
                    cout << "Je urejeno\n";
                }
                if (jeUrejeno(vec, 0, vec.size()) == false) {
                    cout << "Ni urejeno\n";
                }


                break;

            case 6:
                start = std::chrono::steady_clock::now();
                hitroUredi(vec, 0, vec.size());
                end = std::chrono::steady_clock::now();
                std::cout << "Trajanje: " << chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                          << "ns";


                break;

            case 7:
                start = std::chrono::steady_clock::now();
                medianaHitroUredi(vec, 0, vec.size());
                end = std::chrono::steady_clock::now();
                std::cout << "Trajanje: " << chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                          << "ns";
                break;
            case 8:
                start = std::chrono::steady_clock::now();
                bubleSort(vec, 0, vec.size());
                end = std::chrono::steady_clock::now();
                std::cout << "Trajanje: " << chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                          << "ns";
                break;

            case 9:
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
