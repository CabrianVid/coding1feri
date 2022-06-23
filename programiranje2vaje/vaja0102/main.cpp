#include <iostream>
#include <ctime>
#include<cstdlib>

using namespace std;

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "1 ... GENERATE WATER INTAKES" << endl;
    cout << "2 ... PRINT WATER INTAKES" << endl;
    cout << "3 ... AVERAGE WATER INTAKES" << endl;
    cout << "4... WATER INTAKE LESS THAN AVERAGE" << endl;
    cout << "5... DAY WITH BIGGEST WATER INTAKE" << endl;
    cout << "6... DAY WITH INTAKE BETWEEN 2.0 AND 2.5" << endl;
    cout << "7... PRINT" << endl;
    cout << "0 ... EXIT" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void fillArray(float* array, const unsigned int size) {
    float temp;
    unsigned int i = 0;
    while ( i < size) {
        temp =((std::rand() % 65) + 1); //1 + std::rand()/((RAND_MAX + 1u)/6)
        temp/=10;
        if(temp > 1){
            array[i]=temp;
            i++;
        }
    }
}

void printArray(const float* array, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        cout << ((i > 0) ? ", " : "") << array[i];
    }
}

float average(const float* array, const unsigned int size){
    float sum=0;

    for(int i=0; i<size; i++){
        sum+=array[i];
    }
    sum/=size;
    return sum;
}

float biggestIntake(const float* array, const unsigned int size){
    float biggest=0;
    for(int i=0;i<size;i++){
        if(array[i]>biggest){
            biggest= array[i];
        }
    }
    return biggest;
}

void waterBetween(const float* array, const unsigned int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(array[i]<2.5 && array[i]>2.0){
            cout<< "In day "<< i+1<< "intake was between 2.0 and 2.5, to be exact: "<< array[i]<<"\n";
            count++;
        }
    }
    cout<< " this happened exactly: "<< count<<" days";
}

void print (const float* array, const unsigned int size){
    for(int i=0;i<size; i++){
        if(array[i]<2){
            cout<<"-";
        }
        if(array[i] >= 2 && array[i] < 4){
            cout<<"o";
        }
        if(array[i] >= 4){
            cout<<"+";
        }

    }
    cout<<"\n";
}
int countOfDaysWithLess(const float* array, const unsigned int size, float average){
    int count=0;
    for(int k=0;k<size; k++){
        if(array[k]<average){
            count++;
        }
    }
    return count;
}





int main() {
    std::srand(std::time(nullptr));
    const unsigned int days = 30;
    float* waterIntakes = new float[days];


    bool running = true;
    int selection;
    int count=0;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                fillArray(waterIntakes, days);
                break;
            case 2:
                printArray(waterIntakes, days);
                break;
            case 3:
                cout<<"Average is:\t "<<average(waterIntakes, days);
                break;
            case 4:

                cout<< "\n number of days:"<< countOfDaysWithLess(waterIntakes, days, average(waterIntakes, days));
                break;

            case 5:
                cout<<"the biggest water intake was :\t "<< biggestIntake(waterIntakes, days);
                break;
            case 6:
                cout<<"days when water was between  2.0 and 2.5:\n ";
                waterBetween(waterIntakes, days);
                break;
            case 7:
                cout<<"print:\n \n \n";
                print(waterIntakes, days);
                break;



            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;
    } while (running);

    delete[] waterIntakes;

    return 0;
}
