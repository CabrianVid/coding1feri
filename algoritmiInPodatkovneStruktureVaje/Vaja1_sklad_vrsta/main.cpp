#include <iostream>

using namespace std;


struct stack {
    int *S;
    int top;

};

struct row {
    int *arrayRow;
    int glava;
    int rep;

};

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "SKLAD:" << endl;
    cout << "1 ... VNOS PODATKA" << endl;
    cout << "2 ... BRANJE PODATKA IN IZPIS (POP)" << endl;
    cout << "3 ... IZPIS VSEBINE SKLADA" << endl;
    cout << "KROZNA VRSTA:" << endl;
    cout << "4... VNOS PODATKA" << endl;
    cout << "5...BRANJE PODATKA IN IZPIS (POP) " << endl;
    cout << "6... IZPIS PODATKOV" << endl;
    cout << "7 ... EXIT" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}


void push(stack &stack1, int userInput, int userArraySizeStack) {

    if (stack1.top >= userArraySizeStack) {
        cout << "Stack is FULL\n";
    } else {
        ++stack1.top;
        stack1.S[stack1.top] = userInput;

        cout << "number: " << userInput << " was add on top of the stack\n";

    }
}

void pop(stack &stack1) {
    if (stack1.top < 0) {
        cout << "Stack is empty";
    } else {
        cout << "number: " << stack1.S[stack1.top] << " was put off top of the stack\n";
        stack1.top--;
    }
}

void print(stack stack1) {

    if (stack1.top < 1) {
        cout << "Stack is empty\n";
    } else {

        for (int i = 1; i <= stack1.top; i++) {

            cout << stack1.S[i] << "\t";
        }
    }
    cout << "\n";
}

void vpisi(row &row1, int userInputRow, int userArraySizeRow) {
    int novi_rep = row1.rep + 1;


    if (novi_rep >= userArraySizeRow) {
        novi_rep = 0;


    }
    if (row1.glava == novi_rep) {
        cout << "Napaka: vrsta je polna\n";
    } else {
        row1.arrayRow[row1.rep] = userInputRow;
        row1.rep = novi_rep;
    }

}

void branje(row &row1, int userArraySizeRow) {
    int temp;
    if (row1.glava == row1.rep) {
        cout << "Napaka: vrsta je prazna\n";
    } else {
        temp = row1.arrayRow[row1.glava];
        row1.arrayRow[row1.glava] = 0;
        row1.glava = row1.glava + 1;
        if (row1.glava >= userArraySizeRow) {
            row1.glava = 0;
        }
        cout << "iz vrste ste vzeli element:\t" << temp << "\n";
    }
}

void printRow(row row1, int userArraySizeRow) {
    if (row1.glava < row1.rep) {
        for (int i = 0; i < userArraySizeRow; i++) {
            if (row1.arrayRow[i] != 0) {
                cout << row1.arrayRow[i] << "\t";
            }
        }
    }

    if (row1.glava > row1.rep) {
        for (int i = userArraySizeRow - 1; i >= 0; i--) {
            if (row1.arrayRow[i] != 0) {
                cout << row1.arrayRow[i] << "\t";
            }
        }
    }
    if (row1.glava == row1.rep) {
        cout << "vrsta je prazna";
    }

}


int main() {
    stack stack1{};
    int userArraySizeStack;
    cout << "Doloci velikost sklada:\t";
    cin >> userArraySizeStack;
    stack1.S = new int[userArraySizeStack];
    stack1.top = 0;

    int userArraySizeRow;
    row row1{};
    cout << "Doloci velikost vrstae:\t";
    cin >> userArraySizeRow;
    row1.arrayRow = new int[userArraySizeRow];

    row1.glava = 0;
    row1.rep = 0;
    row1.arrayRow[userArraySizeRow - 1] = 0;


    bool running = true;
    int selection;
    int userInput;
    int userInputRow;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                cout << "vnesi podatek:\t";
                cin >> userInput;
                push(stack1, userInput, userArraySizeStack);
                break;
            case 2:
                pop(stack1);
                break;
            case 3:
                print(stack1);
                break;

            case 4:
                cout << "\n vpisi podatek:\t";
                cin >> userInputRow;
                vpisi(row1, userInputRow, userArraySizeRow);
                break;

            case 5:
                branje(row1, userArraySizeRow);
                break;

            case 6:
                printRow(row1, userArraySizeRow);
                break;

            case 7:
                running = false;
                break;
            default:
                cout << "Napacna izbira!" << endl;
                break;
        }
        cout << endl;
    } while (running);

    delete[] stack1.S;
    delete[] row1.arrayRow;

    return 0;
}

