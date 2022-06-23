#include <iostream>

using namespace std;
int countDevisors(int poljubnoSt){
    int count=0;
    for (int i = 1; i <= poljubnoSt; i++) {

        if (poljubnoSt % i == 0) {
            count++;
        }
    }
    return count;
}

bool isPerfect(int poljubnoSt) {
    int sum = 0;

    for (int i = 1; i <= poljubnoSt / 2; i++) {

        if (poljubnoSt % i == 0) {
            sum = sum + i;
        }
    }

    if (sum == poljubnoSt) {
        return true;
    }
    else {
        return false;
    }
}

int sumOfAllNumbers(int poljubnoSt) {
    int sum = 0;
    while (poljubnoSt > 0) {
        int zadnjoSt = poljubnoSt % 10;
        sum = sum + zadnjoSt;
        poljubnoSt = poljubnoSt / 10;
    }
    return sum;
}


int main() {
    int poljubnoSt=0;

    while (poljubnoSt < 1){
        cout << "Vnesi poljubno stevilo: \t" << endl;
        cin >> poljubnoSt;

    }

    cout << "sestevek vseh stevk je: \t" << sumOfAllNumbers(poljubnoSt) << "\n";

    if (isPerfect(sumOfAllNumbers(poljubnoSt)) == true) {
        cout << "Stevilo je popolno.\n";
    } else {
        cout << "Stevilo ni popolno.\n";
    }

    cout<< "stevilo deliteljev vstavljenega stevila je:\t"<< countDevisors(poljubnoSt);




    return 0;
}
