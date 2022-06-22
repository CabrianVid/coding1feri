	#include <iostream>
	using namespace std;
	
	int main()
	
	{
	double hitrost, trajanje, dolzina, manjkajoce;
	
	cout<<"vnesi hitrost ";
	cin>>hitrost;
	
	cout<<"vnesi trajanje ";
	cin>>trajanje;
	
	cout<<"vnesi dolzino ";
	cin>>dolzina;
	
	cout<< hitrost<<" "<< trajanje<<" "<< dolzina<<" "<< endl;
	
	
	manjkajoce = dolzina - trajanje * hitrost;
	cout<< dolzina<<"-"<<trajanje<<"*"<<hitrost<<"="<<manjkajoce<<endl;
	if(manjkajoce==0){
		cout<<"100%";
		
	}else if(manjkajoce>0){
		cout<<"ni se prisel do cilja,manjka mu se "<< manjkajoce<<".";
	}else {
		cout<<"sel je ze mimo cilja.";
	}
	return 0;
}
