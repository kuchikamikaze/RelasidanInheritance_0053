#include <iostream>
#include <vector>
using namespace std;

//deklaras class dokter
class dokter;

//deklarasi dan pembuatan class pasien
class pasien {
public:
    //deklarasi member variabel dari class pasien
    string nama;
    vector<dokter*> daftar_dokter;

