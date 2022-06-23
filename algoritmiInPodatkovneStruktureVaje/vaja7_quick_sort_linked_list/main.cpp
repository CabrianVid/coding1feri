#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element {
    int key;
    element *prev, *next;
};


void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "SKLAD:" << endl;
    cout << "1 ... generiraj nakljucno zaporedje" << endl;
    cout << "2 ... Izpis zaporedja" << endl;
    cout << "3 ... Preveri urejenost zaporedja" << endl;
    cout << "4... izpisi vsoto elementov" << endl;
    cout << "5...uredi " << endl;
    cout << "6...EXIT " << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

bool srecala(element *head, element *tail) {
    element *temp = head;
    if (temp == tail) {
        return true;
    } else {
        while (temp != nullptr) {
            if (temp == tail) {
                return false;
            }
            temp = temp->next;
        }
    }
    return true;
}


element *deli(element *&head, element *&tail) {
    int pivot = head->key;
    element *l = head;
    element *d = tail;


    while (!srecala(head, tail)) {
        while (l->key <= pivot && l != tail) {
            l = l->next;
            srecala(head, tail);
        }
        while (d->key >= pivot && d != tail) {
            d = d->prev;
           srecala(head, tail);
        }
        if (!srecala(head,tail)) {
            int temp = l->key;
            l->key = d->key;
            d->key = temp;
            break;
        }
    }
    int temp = head->key;
    head->key = d->key;
    d->key = temp;
    return d;

}

void hitroUredi(element *head, element *tail) {
    element *temp = head;
    int count;
    while (temp != tail) {
        count++;
        temp = temp->next;
    }
    if (count > 1) {
        element *j = deli(head, tail);
        if (head != j) {
            hitroUredi(head, j->prev);
        }
        if (tail != j) {
            hitroUredi(j->next, tail);
        }
    }
}

void generirajNakljucno(int vrednost, element *&head, element *&tail) {

    element *elements = new element;
    elements->key = vrednost;
    elements->prev = tail;
    elements->next = nullptr;
    if (tail != nullptr && head != nullptr) {
        tail->next = elements;
    } else {
        head = elements;
        tail = elements;
    }
    tail = elements;
}

void print(element *head) {
    element *temp = head;
    while (temp != nullptr) {
        cout << temp->key << "\t";
        temp = temp->next;
    }
}

bool urejenost(element *&head) {
    element *temp = head;
    while (temp->next != nullptr) {
        if (temp->key > temp->next->key) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

int vsota(element *&head) {
    int sum = 0;
    element *temp = head;
    while (temp != nullptr) {
        sum += temp->key;
        temp = temp->next;
    }
    return sum;
}

int main() {
    std::srand(std::time(nullptr));
    element *head = nullptr;
    element *tail = nullptr;

    bool running = true;
    int selection;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                int dolzina;
                cout << "Vnesi dolzino seznama:";
                cin >> dolzina;
                for (int i = 0; i < dolzina; i++) {
                    int random_variable = (std::rand() % 10000) + 1;
                    generirajNakljucno(random_variable, head, tail);
                }

                break;


            case 2:
                print(head);
                break;

            case 3:
                if (urejenost(head) == true) {
                    cout << "zaporedje je urejeno";
                } else {
                    cout << "zaporedje ni urejeno";
                }
                break;

            case 4:
                cout << "vsota vseh elementov je:" << vsota(head) << "\n\n";

                break;

            case 5:
                hitroUredi(head, tail);

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
