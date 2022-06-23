#include <iostream>
#include <ctime>
#include<vector>
#include <chrono>
#include <fstream>


using namespace std;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::steady_clock;


class Vozlisce {
public:
    int predhodnik;
    int ime;
    int cenaPoti;


    Vozlisce(int p, int cP, int i) : predhodnik(p), cenaPoti(cP), ime(i) {};
};

class Povezava {
public:
    int start, finish, cena;

    Povezava(int u, int v, int c) : start(u), finish(v), cena(c) {};

};

vector<Vozlisce *> bellmanFordovAlgo(int s, vector<Vozlisce *> &V, vector<Povezava *> &P) {
    for (int i = 0; i < V.size(); i++) {
        if (V[i]->ime == s) {
            V[i]->cenaPoti = 0;
            V[i]->predhodnik = -1;
        }
    }

    for (int i = 1; i < V.size(); i++) {
        for (Povezava *povezava: P) {
            if ((V[povezava->start]->cenaPoti + povezava->cena) < V[povezava->finish]->cenaPoti) {
                if (i < V.size()) {
                    V[povezava->finish]->cenaPoti = V[povezava->start]->cenaPoti + povezava->cena;
                    V[povezava->finish]->predhodnik = V[povezava->start]->ime;
                } else {
                    cout << "ERROR";
                    return V;
                }
            }
        }
    }
    return V;
}



void readFromFile(int **&C, int &steviloVozlisc, vector<Povezava *> &P, vector<Vozlisce *> &V) {
    ifstream f("grafBig.txt");//graf1.txt, grafBig.txt, graf2.txt
    steviloVozlisc = 0;
    f >> steviloVozlisc;
    int c=0;
    for(int i=0;i<steviloVozlisc; i++){
        for(int j=0;j<steviloVozlisc;j++){
            f>>c;
            if(c==0){
                continue;
            }

            P.push_back(new Povezava(i, j, c));
        }

        V.push_back(new Vozlisce(-1, INT32_MAX / 2, i));
    }

}


void generiranjeRandomGrafa(int steviloVozlisc, int min, int max, vector<Vozlisce *> &V, vector<Povezava *> &P) {

    for (int i = 0; i < steviloVozlisc; i++) {
        V.push_back(new Vozlisce(-1, INT32_MAX / 2, i));
    }


    for (int k = 0; k < steviloVozlisc; k++) {
        for (int i = 0; i < steviloVozlisc; i++) {
            if (k != i) {
                int random_variable1 = (std::rand() % (max - min)) + 1;
                random_variable1 += min;

                P.push_back(new Povezava(k, i, random_variable1));
            }
        }
    }
}


void izpisNajkrajsePoti(int s, int userInput, const vector< Vozlisce *> V){
    int temp= userInput;
    while(userInput!=s){
        cout<<userInput<< "->"<< V[userInput]->predhodnik<<endl;
        userInput= V[userInput]->predhodnik;
    }
    cout<< "cena:\t"<< V[temp]->cenaPoti;
}


void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "SKLAD:" << endl;
    cout << "1 ... preberi graf iz datoteke" << endl;
    cout << "2 ... generiraj nakljucni graf z n vozlisc od a do b" << endl;
    cout << "3 ... pozeni algoritem" << endl;
    cout << "4 ... izpisi seznam vozlisc" << endl;
    cout << "5...izpisi najkrajso pot " << endl;
    cout << "6...EXIT " << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

int main() {
    std::srand(std::time(NULL));
    vector<Vozlisce *> V;
    vector<Povezava *> P;
    int s; //izbrano vozlisce
    int steviloVozlisc;
    int row, col;
    int **C = new int *[row];
    for (int i = 0; i < row; ++i)
        C[i] = new int[col];
    bool running = true;
    int selection;
    int minVrednost, maxVrednost, userInput;

    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                readFromFile(C, steviloVozlisc, P, V);


                break;


            case 2:
                cout << "vpisi zeleno stevilo vozlisc\t";
                cin >> steviloVozlisc;
                cout << "\nod katere vrednosti naj bodo cene?\t";
                cin >> minVrednost;
                cout << "\ndo katere vrednosti naj bodo cene?\t";
                cin >> maxVrednost;
                generiranjeRandomGrafa(steviloVozlisc, minVrednost, maxVrednost, V, P);


                break;

            case 3:
                cout << "izberi zacetno vozlisce:\n";
                cin >> s;
                start = std::chrono::steady_clock::now();
                bellmanFordovAlgo(s, V, P);
                end = std::chrono::steady_clock::now();
                std::cout << "Trajanje: " << chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                          << "ns";
                break;

            case 4:
                for (int i = 0; i < V.size(); i++) {
                    cout<<"ime vozlisca:\t" << V[i]->ime << endl;
                    cout<<"predhodnik:\t" << V[i]->predhodnik << endl;
                    cout<< "cena poti:\t" << V[i]->cenaPoti << endl;
                    cout << endl;
                }


                break;

            case 5:
               /*for(int i=0;i<P.size();i++){
                     cout<<P[i]->start<<endl;
                     cout<<P[i]->finish<<endl;
                     cout<<P[i]->cena<<endl;
                     cout<<endl;
                 }*/

                cout << "vnesi tocko do katere bi rad zvedel najkrajso pot:\n";
                cin >> userInput;
                izpisNajkrajsePoti(s,userInput,V);



                break;
            case 6:
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
