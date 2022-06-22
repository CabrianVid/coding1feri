#include <iostream>
#include <cmath>
using namespace std;

bool je_ni_prast (int poljubnostevilo1){
     if (poljubnostevilo1<=1) {
        return false;
        }
     else {
          for (int i = 2; i < (poljubnostevilo1-1); i++){
              if (poljubnostevilo1 % i == 0){
                  return false;
              }
          }
     return true;
     }
}


 
int koliko_pra(int koncno_st){
    for (int j=2; j<=9001; j++){
        je_ni_prast(j);
        if (je_ni_prast(j)){
             koncno_st++;
        }
    }
return koncno_st;
}

int povprecje(int vecja_stevila[], int vstavljeno_st){
	int k =0;
	while(k<20){
		if(je_ni_prast(vstavljeno_st)){
		vecja_stevila[k]=vstavljeno_st;
		k++;
		}
		vstavljeno_st++;
		
	}//zdaj smo doloèili 20 veèjih pra stevil
	double sestevek =0;
	for (int l=0; l<20; l++){
       sestevek=sestevek+vecja_stevila[l];
    }
	double izracun_povprecja;
    izracun_povprecja = sestevek/20;
    return izracun_povprecja;
}



int najblizje_st(int podano_st, int velikost_polja[]){
    int najblizje_st = velikost_polja[0];
    for(int d=0;d<20;d++){
        
        if (abs(sqrt(podano_st)-velikost_polja[d]) < (abs(sqrt(podano_st)-najblizje_st))){
            najblizje_st= velikost_polja[d];
        }
    }
    return najblizje_st;
}


int main()
{
	int st1, st2, st3, st4;
	cout<<"Vstavi poljubno stevilo: ";
	cin>> st1;
	if (je_ni_prast(st1)){
		cout<< "Stevilo je prastevilo";
	}
	else {
		cout<< "stevilo ni prastevilo";
	}
	cout<< endl;
	st2=0;
	cout<< "med stevili -217 in 9001 je "<< koliko_pra(st2)<<" prastevil."<<endl;
	
	cout<< "vstavi se eno stevilo in izpisalo ti bo povprecje naslednjih 20 prastevil: ";
	cin>>st3;
	int velikost_polja[20];
	cout<<"povprecje naslednjih 20 prastevil od "<<st3<<" je: "<<povprecje(velikost_polja, st3)<<endl;
	
	int velikost_polja2[20];
	cout<<"Vnesi se eno stevilo in izpisalo ti bo od njegovega korena najblizjo najmanjso"<<endl;
	cout<<" stevilo iz skupine 20 stevil, ki so bila naslednja prastevila od tvojega prejsnjega poljubnega vnosa :";
	 cin>>st4;
	 cout<<"najblizje stevilo korena "<<st4<<" je: "<<najblizje_st(st4, velikost_polja);
	 
	
	
	
	
	return 0;
}

