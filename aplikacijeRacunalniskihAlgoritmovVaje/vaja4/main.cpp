#include <iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;


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

void LZW(std::string vhodniNiz, int size, unordered_map<string, int>& S) {
    // BinWriter bw("out_c.bin");
    std::string T = "";
    int numBit = ceil(log2(size + 1));
    for (int i = 0;i < vhodniNiz.size(); i++) {

    }


    cout << "Kompresijsko razmerje: ";
}



int main(int argc, const char* argv[]) {

    if (argc < 3) {
        return -1;
    }
    char option = argv[1][0];
    int size = stoi(argv[2]);
    std::string path = argv[3];
    std::string temp;
    unordered_map<string, int> S(size);

    for (int i = 0; i < 256; i++) {//napolnimo slovar S s vsemi kodami 256 znakov
        temp = (unsigned char)i;
        S[temp] = i;
    }

    std::string vhodniNiz;
    LZW(vhodniNiz, size, S);
    /*
   if (option == 'c') {
        BinReader br(path);
        while (!br.f.eof()) {
            vhodniNiz += br.readByte();
        }
        vhodniNiz.pop_back();//mogoce ni treba
        br.f.close();

        LZW(vhodniNiz, size, S);
    }
    else if (option == 'd') {
        //LZWde(path, size, S);
    }*/

    return 0;
}



