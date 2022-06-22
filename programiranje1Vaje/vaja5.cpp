#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <string>
#include <time.h>  
#include <sstream>  
using namespace std;




void napolni(int arr[][7]){	
	for(int i=0; i<166;i++){
		arr[i][0]=i+1;//stevilka uèenca
		arr[i][1]=(rand() % 30) + 1;//ime
		arr[i][2]=(rand() % 20) + 1;//priimek
		arr[i][3]=(rand() % 100) + 1;//kv
		arr[i][4]=(rand() % 100) + 1;//RV
		arr[i][5]=(rand() % 100) + 1;//VI
		arr[i][6]=((arr[i][3]+arr[i][4]+arr[i][5])/3);
}
for(int i = 0; i < 166; i++){
 
        int o = ((arr[i][3] + arr[i][4] + arr[i][5]) / 3);
 
        if ( o< 50) {
            arr[i][6] = 5;
        };
        if (o > 49) {
            arr[i][6] = 6;
        }
        if (o > 60) {
            arr[i][6] = 7;
        }
        if (o > 70) {
            arr[i][6] = 8;
        }
        if (o > 80) {
            arr[i][6] = 9;
        }
        if (o > 90) {
            arr[i][6] = 10;
        }
        if (arr[i][4] < 50) {
            arr[i][6] = -1;
        }
        if (arr[i][5] < 50) {
            arr[i][6] = -2;
        }
        if (arr[i][4] < 50 &&arr[i][5] < 50) {
            arr[i][6] = -3;
        }
}
}

void razporeditev(int redovalnica[][7]){
	
	
		for(int k=0;k<166;k++)
	{
		for(int j=k+1;j<166;j++){
			if(redovalnica[j][6]>redovalnica[k][6]){
				int temp=redovalnica[k][0];
				redovalnica[k][0]=redovalnica[j][0];
				redovalnica[j][0]=temp;
				
				temp=redovalnica[k][1];
				redovalnica[k][1]=redovalnica[j][1];
				redovalnica[j][1]=temp;	
				
				temp=redovalnica[k][2];
				redovalnica[k][2]=redovalnica[j][2];
				redovalnica[j][2]=temp;	
				
				temp=redovalnica[k][3];
				redovalnica[k][3]=redovalnica[j][3];
				redovalnica[j][3]=temp;	
				
				temp=redovalnica[k][4];
				redovalnica[k][4]=redovalnica[j][4];
				redovalnica[j][4]=temp;		
				
				temp=redovalnica[k][5];
				redovalnica[k][5]=redovalnica[j][5];
				redovalnica[j][5]=temp;			
				
				temp=redovalnica[k][6];
				redovalnica[k][6]=redovalnica[j][6];
				redovalnica[j][6]=temp;		
			}
		}
	}
}

double povprecje(int redovalnica[][7]) { 
 
    double count = 0;
    double vsota = 0;
    double povprecje;
 
    for (int i = 0; i < 166; i++) {
        if ((redovalnica[i][6] > 5) && (redovalnica[i][5]> 50) && (redovalnica[i][4])> 50) {
            count++;
            vsota = vsota + redovalnica[i][6];
        }
    }
    povprecje = vsota / count;
    return (povprecje);
};

int main()
{
	srand(time(NULL));
	int redovalnica[166][7];
	string imena[20]={"SMITH", "JOHNSON", "WILLIAMS", "BROWN", "JONES", "GARCIA", "MILLER", "DAVIS", "RODRIGUEZ", "MARTINEZ", "HERNANDEZ", "LOPEZ", "GONZALEZ", "WILSON", "ANDERSON", "THOMAS", "TAYLOR", "MOORE", "JACKSON", "MARTIN"};
	string priimki[30]={"Juan", "Miguel", "José", "Francisco", "Jesús", "Antonio", "Alejandro", "Pedro", "Carlos", "Guadalupe", "María", "Juana", "Carmen", "Margarita", "Verónica", "Elizabeth", "Alejandra", "Leticia", "Elena", "Michaela", "Amar", "Vedad", "Ahmed", "Adin", "Emir", "Davud", "Imran", "Tarik", "Haruz", "Aladin"};
	string nezadostno[3]={"RV", "IV", "RV, IV"};
	

	napolni(redovalnica);
	razporeditev(redovalnica);
    cout << "povprecje ucencov ki so naredili:"<< povprecje(redovalnica)<<"\n";





	for (int n = 0; n < 166; n++){
		if ((6<povprecje(redovalnica)<6.5) && redovalnica[n][6]==6){
			cout<< redovalnica[n][0]<<"\t";
		
		}
		if((6.5<=povprecje(redovalnica)<7.5) && redovalnica[n][6]==7){
			cout<< redovalnica[n][0]<<"\t";
		
		}
		if((7.5<=povprecje(redovalnica)<8.5) && redovalnica[n][6]==8){
			cout<< redovalnica[n][0]<<"\t";
		
		}
		if((8.5<=povprecje(redovalnica)<9.5) && redovalnica[n][6]==9){
			cout<< redovalnica[n][0]<<"\t";
		
		}
		if((9.5<=povprecje(redovalnica)<=10) && redovalnica[n][6]==10){
			cout<< redovalnica[n][0]<<"\t";
		}
	}
	cout<<"\n";





for (int row = 0; row < 166; row++) {
        for (int i = 0; i < 97; i++) {
            cout << "-";
        };
        cout << endl;
        cout << "| " << std::setw(10) << std::left << redovalnica[row][0] << " | " << std::setw(10) << std::left << imena[redovalnica[row][1]] << " | " << std::setw(10) << std::left << priimki[redovalnica[row][2]] << " | " << std::setw(10) << std::left << redovalnica[row][3] << " | " << std::setw(10) << std::left << redovalnica[row][4] << " | " << std::setw(10) << std::left << redovalnica[row][5] << " | " << std::setw(15) << std::left ;
            if (redovalnica[row][6] > 0) {
                cout << redovalnica[row][6];
            }
            if (redovalnica[row][6] == -1) {
                cout << nezadostno[0];
            }
            if (redovalnica[row][6] == -2) {
                cout << nezadostno[1];
            }
            if (redovalnica[row][6] == -3) {
                cout << nezadostno[2];
            }
        cout << " | " << endl;
    }
    for (int i = 0; i < 97; i++) {
            cout << "-";
        }
     cout<<"\n";

    
    return 0;   
    }

	
	






