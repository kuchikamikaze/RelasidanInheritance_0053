#ifndef JANTUNG_H
#define JANTUNG_H

#include <iostream>
using namespace std;

//membuat class jantung di file header jantung.h
class Jantung {
public:
    //membuat constructor dan destructor dari class jantung
    Jantung() {
        cout << "Jantung Ditambah\n";
    }

    ~Jantung() {
        cout << "Jantung Dimatikan\n";
    }
};

#endif // !JANTUNG_H