#include <string>
#include <sstream>
#include <fstream>
#include<vector>
#include<iostream>

using namespace std;

ofstream out;

string inputText(const string& pot) {
	ifstream input(pot);
	stringstream sstream;

	if (!input.is_open()) {
		return string();
	}

	sstream << input.rdbuf();
	return sstream.str();
}

void izpis_BCH(const vector<int> polje) {
	for (int i = 0; i < polje.size(); ++i) {
		out << polje[i] << ' ';
	}
	out << endl;
	out << endl;
	out << endl;

}

void sunday(const string& text, const string& vzorec) {
	int m = vzorec.size();
	int n = text.size();
	string x = vzorec;
	string y = text;



	vector<int> BCH(256, m+1);//256 ker je tolko znakov v ASCII... m+1 za zanke ki jih ni v vzorcu
	

	for (int i = 0; i < m;i++) {
		BCH[x[i]] = m - i;
	}

	izpis_BCH(BCH);


	vector<int>ujemanja;
	int counter;

		for (int j = 0;j < n;j++) {
		for (int i =0; i<m; i++) {
			if (x[i] != y[j + i]) {
				j += BCH[y[j + m]];
				i = 0;
			}
			else if (i == 0) {
				counter=0;
				for(int k=0;k<m;k++){
					
					if (x[k] == y[k + j]) {
						counter++;
					}
				}
				if (counter == m - 1) {
					ujemanja.push_back(j);
					j += m;
					i = 0;
				}

			}
		}
	}

	izpis_BCH(ujemanja);




}

int main(int argc, const char* const argv[]) {
	if (argc != 3) {
		return -1;
	}

	string text = inputText(argv[2]);
	string vzorec = argv[1];
	out.open("out.txt");

	if (!out) {
		return -2;
	}

	sunday(text, vzorec);
	return 0;
}