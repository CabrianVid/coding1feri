
#include <iostream>
#include <fstream>
#include<vector>
#include<cmath>
#include <bitset>
using namespace std;

/*vector<vector<int>> codaZnaka(256);
vector<int>steviloPonovitev(256);
vector<int>zacetnaStevilka(256);
*/

class Znak {
public:
    int zacetniZnak;
    int steviloPonovitev;
    vector<int> codaZnaka;
};


class BinWriter {
public:
    int k;
    ofstream f;
    char x;

    BinWriter(std::string path) : k(0) {//path je datoteka
        f.open(path, ios::binary);
    }

    ~BinWriter() {
        if (k > 0) writeByte(x);
        f.close();
    }

    void writeByte(char x) {
        f.write((char*)&x, 1);
    }

    void writeInt(int y) {
        f.write((char*)&y, 4);
    }

    void writeFloat(float f1) {
        f.write((char*)&f1, 4);
    }

    void writeBit(bool b) {//^ XOR
        if (k == 8) {
            writeByte(x);
            k = 0;
        }
        x ^= (-b ^ x) & (1 << k);//nastavitev n-tega bita na b(0 ali 1)
        k++;
    }
};

class BinReader {
public:
    int k;
    ifstream f;
    char x;
    int a;
    float b;

    BinReader(std::string path) : k(0) {
        f.open(path, ios::binary);
    }

    char readByte() {
        f.read((char*)&x, sizeof(x));//lahko tudi 1
        return x;
    }

    int readInt() {
        f.read((char*)&a, 4);
        return a;
    }

    float readFloat() {
        f.read((char*)&b, sizeof(b));
        return b;
    }

    bool readBit() {
        if (k == 8) {
            readByte();
            k = 0;
        }
        bool b = (x >> k) & 1;//branje k-tega bita
        k++;
        return b;
    }
};


void shannonFanoTabela(vector<Znak>& znaki, int min, int max) {
    int sum = 0;
     int primerjava = 0;
    int razlika1, razlika2;
    int k, j;


    if ((min + 1 == max) || (min == max) || (min > max)) {
        if ((min == max) || (min > max)) {
            return;
        }
        else {
            znaki[min].codaZnaka.push_back(0);
            znaki[max].codaZnaka.push_back(1);
            return;
        }
    }
    else {
        for (int i = min; i < max; i++) {
            sum += znaki[i].steviloPonovitev;
        }
        sum += znaki[max].steviloPonovitev;
        razlika1 = sum - primerjava;
        if (razlika1 < 0) {
            razlika1 *= -1;
        }
        j = 2;
        while (j != max - min + 1) {
            k = max - j;
            sum = primerjava = 0;
            for (int i = min; i <= k; ++i) {
                sum += znaki[i].steviloPonovitev;
            }
            for (int i = max; i > k; --i) {
                primerjava += znaki[i].steviloPonovitev;
            }
            razlika2 = sum - primerjava;
            if (razlika2 < 0) {
                razlika2 *= -1;
            }
            if (razlika2 >= razlika1) {
                break;
            }
            razlika1 = razlika2;
            j++;
        }
        k++;

        for (int i = min; i <= k; i++) {
            znaki[i].codaZnaka.push_back(0);
        }
            
        for (int i = k + 1; i <= max; i++) {
            znaki[i].codaZnaka.push_back(1);
        }
            
        shannonFanoTabela(znaki, min, k);
        shannonFanoTabela(znaki, k + 1, max);
    }
}
    
    
    /*
    float sum=0;
    float half = 0;
    if ((min + 1 == max) || (min == max) || (min > max)) {
        if ((min == max) || (min > max)) {
            return;
        }
        else {
            znaki[min].codaZnaka.push_back(0);
            znaki[max].codaZnaka.push_back(1);
            return;
        }
    }
    else {
        for (int i = min;i <= max;i++) {
            sum += znaki[i].steviloPonovitev;
        }
        half = sum / 2;
        int temp = 0;
        int i = min;
        while (temp < half) {
            temp = znaki[i].steviloPonovitev;
            if (temp < half) {
                ++i;
            }
        }
        int temp2;
        for (int j = i+1; j <= max;j++) {
            temp2 = znaki[j].steviloPonovitev;
        }
        int razlika1 = temp - temp2;
        if (razlika1 < 0) {
            razlika1 *= -1;
        }
        int razlika2 = (temp - znaki[i].steviloPonovitev) - (temp2 + znaki[i].steviloPonovitev);
        if (razlika2 < 0) {
            razlika2 *= -1;
        }

        if (razlika1 > razlika2) {
            i -= 1;
        }

        for (int k = min; k <= i;k++) {
            znaki[k].codaZnaka.push_back(0);
        }
        for (int k = max;k > i;k--) {
            znaki[k].codaZnaka.push_back(1);
        }

        shannonFanoTabela(znaki, min, i);
        shannonFanoTabela(znaki, i + 1, max);
    }
}*/



void shannonFanoKodiranje(string path) {

    BinReader br(path);

    vector<unsigned char> vhodniNiz;

    vector<Znak>znaki(256);
    int stetjeZnakov=0;

    while (!br.f.eof()) {
        vhodniNiz.push_back(br.readByte());
        stetjeZnakov += 1;
    }
    br.f.close();

    for (int i = 0; i < vhodniNiz.size();i++) {
        znaki[vhodniNiz[i]].steviloPonovitev++;
        //steviloPonovitev[vhodniNiz[i]]++;

    }
    br.f.close();

    //urejanje
    for (int i = 0;i < 256;i++) {
        znaki[i].zacetniZnak = i;
    }

    BinWriter bw("test.bin");
    bw.writeInt(znaki.size());
    for (int i = 0;i < znaki.size();i++) {
        bw.writeByte(znaki[i].zacetniZnak);
        bw.writeInt(znaki[i].steviloPonovitev);
    }



    int temp1, temp2;
    for (int i = 0;i < znaki.size();i++)
    {
        for (int j = i + 1;j < znaki.size();j++) {
            if (znaki[j].steviloPonovitev > znaki[i].steviloPonovitev) {
                temp1 = znaki[i].steviloPonovitev;
                znaki[i].steviloPonovitev = znaki[j].steviloPonovitev;
                znaki[j].steviloPonovitev = temp1;

                temp2 = znaki[i].zacetniZnak;
                znaki[i].zacetniZnak = znaki[j].zacetniZnak;
                znaki[j].zacetniZnak = temp2;
            }
        }
    }
    

    shannonFanoTabela(znaki, 0, 255);
    int stetjeBitov = 0;
    BinReader br2(path);
    unsigned char prebraniZnak;
    vector<int> bits;
    
   
    while (br2.f.peek() != EOF) {
        prebraniZnak = br2.readByte();
        
        for (int i = 0; i<znaki.size(); i++) {
            if (znaki[i].zacetniZnak == prebraniZnak) {
                bits = znaki[i].codaZnaka;
                break;
            }
        }

        for (int i = 0;i < bits.size();i++) {
            bw.writeBit(bits[i]);
            stetjeBitov++;
        }
    }

    cout << "Kompresijsko razmerje: " << ((float)(stetjeZnakov * 8) / stetjeBitov);
}

int main(int argc, const char* argv[]) {


    if (argc < 2) {
        return -1;
    }

    string path = argv[2];
    char option = argv[1][0];

    if (option == 'c') shannonFanoKodiranje(path);
    else if (option == 'd');

    /*
    BinWriter bw("test.bin");
    bw.writeBit(1);
    bw.writeBit(0);
    bw.writeBit(0);
    bw.writeBit(0);
    bw.writeBit(0);
    bw.writeBit(0);
    bw.writeBit(1);
    bw.writeBit(0);
    bw.writeByte(bw.x);
    bw.f.close();

    BinReader br("test.bin");
    br.readByte();
    for (int i = 0; i < 8; ++i)
        std::cout << (int)br.readBit() << "\n";
    br.f.close();
    */
    /*shannonFanoKodiranje("alice.txt");*/

    return 0;
}