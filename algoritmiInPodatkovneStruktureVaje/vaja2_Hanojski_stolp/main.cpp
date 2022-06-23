#include <iostream>
#include <stack>
using namespace std;

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "============================" << endl;
    cout << "1 ... Velikost zacetnega stolpa" << endl;
    cout << "2 ... Prestavi iz 1. stolpa na 2." << endl;
    cout << "3 ... Prestavi iz 1. stolpa na 3." << endl;
    cout << "4... Prestavi iz 2. stolpa na 1." << endl;
    cout << "5...Prestavi iz 2. stolpa na 3. " << endl;
    cout << "6... Prestavi iz 3.. stolpa na 1.." << endl;
    cout << "7 ... Prestavi iz 3.. stolpa na 2." << endl;
    cout << "EXIT" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void fillStack(stack<int> &stolp, int userInputSize) {
    for (int i = userInputSize; i >= 1; i--) {
        stolp.push(i);
    }
}

void printStack(stack<int> stolp1, stack<int> stolp2, stack<int> stolp3) {
    cout << "Elementi stolpa 1: \n";
    while (!stolp1.empty()) {
        cout << "\n";
        for (int i = 1; i <= stolp1.top(); i++) {
            cout << "*";
        }
        stolp1.pop();
    }
    cout << "\nElementi stolpa 2: \n";
    while (!stolp2.empty()) {
        cout << "\n";
        for (int i = 1; i <= stolp2.top(); i++) {
            cout << "*";
        }
        stolp2.pop();
    }
    cout << "\nElementi stolpa 3: \n";
    while (!stolp3.empty()) {
        cout << "\n";
        for (int i = 1; i <= stolp3.top(); i++) {
            cout << "*";
        }
        stolp3.pop();
    }


}

void move(stack<int> &stolp1, stack<int> &stolp2) {
    int temp;
    if(stolp1.empty()){
        cout<<"ta poteza ni mogoca ker je stolp prazen\n";
    }
   else if (stolp2.empty() || stolp2.top() > stolp1.top()) {
        temp = stolp1.top();
        stolp2.push(temp);
        stolp1.pop();
    }
   else {
        cout << "ta poteza ni mogoca\n";
    }
}

int main() {
    int userInputSize;
    stack<int> stolp1, stolp2, stolp3;

    bool running = true;
    int selection;
    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                cout << "Vnesi velikost stolpa:\t";
                cin >> userInputSize;
                fillStack(stolp1, userInputSize);
                printStack(stolp1, stolp2, stolp3);
                break;
            case 2:
                move(stolp1, stolp2);
                printStack(stolp1, stolp2, stolp3);
                break;
            case 3:
                move(stolp1, stolp3);
                printStack(stolp1, stolp2, stolp3);
                break;

            case 4:
                move(stolp2, stolp1);
                printStack(stolp1, stolp2, stolp3);
                break;

            case 5:
                move(stolp2, stolp3);
                printStack(stolp1, stolp2, stolp3);
                break;

            case 6:
                move(stolp3, stolp1);
                printStack(stolp1, stolp2, stolp3);
                break;

            case 7:
                move(stolp3, stolp2);
                printStack(stolp1, stolp2, stolp3);
                break;
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
