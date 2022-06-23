#include <iostream>

using namespace std;

struct vozl {
    int key;
    vozl *oce;
    vozl *leviSin;
    vozl *desniSin;
};


vozl *ustvari() {
    vozl *p;
    p = new vozl;
    p->key = NULL;
    p->desniSin = NULL;
    p->leviSin = NULL;
    p->oce = NULL;
    return p;
}

void vstavi(vozl *&koren, int key1) {

    vozl *y = NULL;
    vozl *x = koren;

    while (x != NULL) {
        y = x;
        if (key1 < x->key) {
            x = x->leviSin;
        } else if (key1 > x->key) {
            x = x->desniSin;
        } else {
            cout << "ERROR";
            return;//mogoce break
        }
    }
    vozl *z = ustvari();
    z->key = key1;
    z->oce = y;
    if (y == NULL) {
        koren = z;
    } else {
        if (z->key < y->key) {
            y->leviSin = z;
        } else {
            y->desniSin = z;
        }
    }


}

void urejenIzpis(vozl *x) {
    if (x != NULL) {
        urejenIzpis(x->leviSin);
        cout << x->key << "\t";
        urejenIzpis(x->desniSin);
    }
}

void izpisPovezav(vozl *x) {
    if (x->leviSin != NULL) {
        cout << x->key << "->" << x->leviSin->key<<"\n";
        izpisPovezav(x->leviSin);
    }
    if (x->desniSin != NULL) {
        cout << x->key << "->" << x->desniSin->key<<"\n";
        izpisPovezav(x->desniSin);
    }
}

int minimum(vozl *koren) {
    vozl *x = koren;
    while (x->leviSin != NULL) {
        x = x->leviSin;
    }
    return x->key;
}

int maximum(vozl *koren) {
    vozl *x = koren;
    while (x->desniSin != NULL) {
        x = x->desniSin;
    }
    return x->key;
}
/*
vozl naslednik(vozl *x) {
    if (x->desniSin != NULL) {
        return minimum(x->desniSin);
    }
        vozl *y = x->oce;
    while(y != NULL && x==y->desniSin){
        x=y;
        y=y->oce;
    }
    return y->key;

}*/

bool search(vozl *koren, int key1) {
    vozl *x = koren;
    while (x != NULL) {
        if (key1 == x->key) {
            return true;
        }
        if (key1 < x->key) {
            x = x->leviSin;
        } else {
            x = x->desniSin;
        }
    }
    return false;
}
/*
void brisi2(vozl* koren, vozl *z){
    if(z->leviSin==NULL || z->desniSin== NULL){
        brisi1(koren, z);
    }
    else{
        vozl *y= naslednik(z);

    }
}
*/

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "SKLAD:" << endl;
    cout << "1 ... Vnos PODATKA" << endl;
    cout << "2 ... urejen izpis vrednosti" << endl;
    cout << "3 ... izpis povezav" << endl;
    cout << "4... iskanje" << endl;
    cout << "5... izpis MAX in MIN" << endl;
    cout << "6... izpisi predhodika in naslednika" << endl;
    cout << "7 ... Ibrisi vrednost" << endl;
    cout << "8...TESTIRAJ pravilnost delovanje " << endl;
    cout << "9...EXIT " << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

int main() {

    bool running = true;
    int selection;
    vozl *koren = NULL;


    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                int key1;
                cout << "vstavi zeleno vrednost:\t";
                cin >> key1;

                vstavi(koren, key1);
                break;


            case 2:
                urejenIzpis(koren);
                break;

            case 3:
                izpisPovezav(koren);
                break;


            case 4:
                int key2;
                cout << "vpisi iskani znak:\t";
                cin >> key2;
                if (search(koren, key2) == true) {
                    cout << "Ta vrednost je v drevesu";
                } else cout << "te vrednosti ni v drevesu";

                break;

            case 5:
                cout << "izpis minimalnega elementa:\t";
                cout << minimum(koren) << "\n";
                cout << "izpis maximalnega elementa:\t";
                cout << maximum(koren) << "\n";
                break;
/*
            case 6:
                int key3;
                cout<<"vnesi stevilo od katerega zelis naslednik:\t";
                cin>> key3;
                cout<<"naslednik od stevila je:\t";
                cout<< naslednik(key3)<<"\n";
                break;

            case 7:

                break;
 */
            case 8:
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
