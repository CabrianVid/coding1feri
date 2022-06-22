#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include <stdio.h>		//za stopanje casa je oboje
#include <time.h>
#include <iomanip>
using namespace std;

//vse funkcije
void izris_slike (int st_poskus);


struct igralci{
	int stev;
	string ime;
	string geslo;
	char ugib;
	int st_poskusov=10;
	char prejsnji_poskusi[26];
	clock_t start;
	clock_t end;
	double cas;	

};

int main(){
	srand(time(NULL));
	igralci players[5];
	string gesla [100]={"reality", "alcohol", "variety", "inflation", "product", "county", "estate", "category", "tennis", "bathroom", "platform", "relation", "weakness", "painting", "boyfriend", "country", "computer", "artisan", "satisfaction", "disaster", "management", "comparison", "trainer", "administration", "obligation", "ability", "people", "fishing", "worker", "vehicle", "shopping", "inspection", "cookie", "theory", "inspector", "examination", "baseball", "assumption", "grandmother", "safety", "currency", "procedure", "housing", "chapter", "failure", "recipe", "reaction", "supermarket", "customer", "property", "potato", "development", "election", "engineering", "device", "success", "trainer", "driver", "manufacturer", "contribution", "tongue", "presentation", "coffee", "studio", "teaching", "temperature", "ability", "insect", "passenger", "safety", "magazine", "association", "negotiation", "cabinet" ,"airport" ,"tension" ,"technology", "instruction", "recording", "cookie", "inspection", "chapter", "director", "impression", "aspect", "performance", "society", "growth", "complaint", "camera", "concept", "income", "information", "church", "emphasis", "comparison", "medicine", "difficulty", "refrigerator", "player"};
	
	bool pravilniPoskus = false;
	//v tej for zanki bo vse ter bo slo 5x skozi doklar vsi igralci ne konèajo igre
	for(int i=0; i<5; i++){

			
	cout << "vnesi ime igralca "<< i+1<< ":\t ";
	cin >> players[i].ime;//naredit se mores arraj 5 igralcev ki igrajo in pol ga klici tu not
				players[i].start = clock();//ura se zacne

	players[i].stev= i+1; // dolocimo igralcu njegovo stevilo od 1 do 5	
	
	
		int k;
	k = rand()%100;
	players[i].geslo = gesla[k];//izbrali smo nakljuèno geslo
	string skritoGeslo(players[i].geslo.length(), '*');// skrijemo izbrano geslo
		cout<< "Vase geslo, ki ga morate ugotoviti je: " <<skritoGeslo<< "\n";
	
		int counter=0;// steje kolko krat gre while loop okoli
		
		while(players[i].st_poskusov>=0){
		
			
				bool pravilniPoskus = false;
				if(players[i].st_poskusov==0){
					cout<<" Konec igre vse poskuse si porabil.\n\n\n";
					break;
				}

		cout<< "lahko se zmotis se "<< players[i].st_poskusov<< " preden bos obesen.\n\n\n";
		cout<< "Vnesi svoj ugib: \t";
		cin >>  players[i].ugib;
		for(int j=0; j< players[i].geslo.length(); j++){
			if(players[i].geslo[j] == players[i].ugib){
				skritoGeslo[j] = players[i].ugib;
				cout<< "Bravo "<< players[i].ugib<<" je pravilno.\n\n";
				cout<<"Vase preostalo geslo:"<< skritoGeslo<<"\n\n\n";
				
				pravilniPoskus = true;				
			}
		}
	
	if( players[i].geslo== skritoGeslo){
		cout<<"BRAVO!!!\n Koncal si igro.\n Ugutovil si vse crke besede:"<< skritoGeslo<<"\n\n\n\n";

		break;
	}
	if(pravilniPoskus == false){
		players[i].st_poskusov--;
		cout<<"Vas poskus "<< players[i].ugib <<" ni pravilen\n\n";
		cout<<"Vase preostalo geslo:"<< skritoGeslo<<"\n\n\n";
		//players[i].napacni_poskusi[players[i].st_poskusov-1]=players[i].ugib;
		
	}
	
	
	

	izris_slike(players[i].st_poskusov);
	cout<<"\n";
		if(players[i].st_poskusov==0){
					cout<<" Konec igre vse poskuse si porabil.\n\n\n";
					break;
				}
				
		cout<<"\n\n\n\n\n\n";
		

	}
		 players[i].end = clock();//zakljuci cas
		players[i].cas = (players[i].end - players[i].start)/ CLOCKS_PER_SEC;//izracunamo koliko sekund je trajalo
		 	cout<<"Vas cas v sekundah je bil:"<< players[i].cas<<"\n\n";



	counter++;
	

	
}
    for (int i = 0; i < 110; i++) {
            cout << "-";
        }
     cout<<"\n";
     
cout << "| " << std::setw(10) << std::left << "STEVILO"<< " | " << std::setw(15) << std::left << "IME IGRALCA"<< " | " << std::setw(15) << std::left << "GESLO"<< " | " << std::setw(32) << std::left << "STEVILO PREOSTALIH POSKUSOV" << " | " << std::setw(22) << std::left << "CAS IGRE V SEKUNDAH" << " | \n";

    for (int i = 0; i < 110; i++) {
            cout << "-";
        }
     cout<<"\n";

for(int o=0; o<5;o++){
cout << "| " << std::setw(10) << std::left << players[o].stev << " | " << std::setw(15) << std::left << players[o].ime << " | " << std::setw(15) << std::left << players[o].geslo << " | " << std::setw(32) << std::left << players[o].st_poskusov << " | " << std::setw(22) << std::left << players[o].cas << " | \n";
}
    for (int i = 0; i < 110; i++) {
            cout << "-";
        }
     cout<<"\n";
     
     cout<< "Igralec, ki je porabil najmanj poskusov je:";
     
if(players[0].st_poskusov>players[1].st_poskusov && players[0].st_poskusov>players[2].st_poskusov && players[0].st_poskusov>players[3].st_poskusov && players[0].st_poskusov>players[4].st_poskusov){

cout<< players[0].ime;
}

if(players[1].st_poskusov>players[0].st_poskusov && players[1].st_poskusov>players[2].st_poskusov && players[1].st_poskusov>players[3].st_poskusov && players[1].st_poskusov>players[4].st_poskusov){

cout<< players[1].ime;
}

if(players[2].st_poskusov>players[1].st_poskusov && players[2].st_poskusov>players[0].st_poskusov && players[2].st_poskusov>players[3].st_poskusov && players[2].st_poskusov>players[4].st_poskusov){

cout<< players[2].ime;
}

if(players[3].st_poskusov>players[1].st_poskusov && players[3].st_poskusov>players[2].st_poskusov && players[3].st_poskusov>players[0].st_poskusov && players[3].st_poskusov>players[4].st_poskusov){

cout<< players[3].ime;
}

if(players[4].st_poskusov>players[1].st_poskusov && players[4].st_poskusov>players[2].st_poskusov && players[4].st_poskusov>players[3].st_poskusov && players[4].st_poskusov>players[0].st_poskusov){

cout<< players[4].ime;
}
}



void izris_slike (int st_poskus)
{
	
	const char *scenarij0 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **             \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";
	
	 const char *scenarij1 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **       O     \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";


 const char *scenarij2 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O     \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";


				

 const char *scenarij3 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";


				

 const char *scenarij4 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *        |     \n"
 "       *        |     \n"
 "       *              \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";
			
				

 const char *scenarij5 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *        |     \n"
 "       *        |     \n"
 "       *       /      \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";

				

 const char *scenarij6 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *        |     \n"
 "       *        |     \n"
 "       *       / \\   \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";
			


 const char *scenarij7 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *        |=    \n"
 "       *        |     \n"
 "       *       / \\   \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";

				

 const char *scenarij8 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *       =|=    \n"
 "       *        |     \n"
 "       *       / \\    \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";


 const char *scenarij9 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *       =|=--    \n"
 "       *        |     \n"
 "       *       / \\   \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n";


 const char *scenarij10 = 
 "       *  * * * *     \n"
 "       * *      *     \n"
 "       **      -O-    \n"
 "       *     --=|=--  \n"
 "       *        |     \n"
 "       *       / \\   \n"
 "       *              \n"
 "      * *             \n"
 "     *   *            \n"
"     GAME OVER!!!      \n";
 
 
const char *scenariji[11]= {scenarij0, scenarij1, scenarij2, scenarij3, scenarij4, scenarij5, scenarij6, scenarij7, scenarij8, scenarij9, scenarij10};
	if (st_poskus==10){
		cout<< scenarij0;
	}
	if (st_poskus==9){
		cout<< scenarij1;
	}
		if (st_poskus==8){
		cout<< scenarij2;
	}
		if (st_poskus==7){
		cout<< scenarij3;
	}
		if (st_poskus==6){
		cout<< scenarij4;
	}
		if (st_poskus==5){
		cout<< scenarij5;
	}
		if (st_poskus==4){
		cout<< scenarij6;
	}
		if (st_poskus==3){
		cout<< scenarij7;
	}
		if (st_poskus==2){
		cout<< scenarij8;
	}
		if (st_poskus==1){
		cout<< scenarij9;
	}
		if (st_poskus==0){
		cout<< scenarij10;
	}
}
