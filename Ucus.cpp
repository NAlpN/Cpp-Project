#include "Ucus.h"
#include <iostream>
#include <iomanip>

using namespace std;

Ucus::Ucus(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri, const string& kalkisZamani,
           int normalKoltukSayisi, int luksKoltukSayisi)
    : ucusNumarasi_(ucusNumarasi), kalkisYeri_(kalkisYeri), varisYeri_(varisYeri), kalkisZamani_(kalkisZamani),
      normalKoltukSayisi_(normalKoltukSayisi), luksKoltukSayisi_(luksKoltukSayisi) {
}

// U�u� numaras�n� d�nd�ren get fonksiyonu
int Ucus::getUcusNumarasi() const {
    return ucusNumarasi_;
}

// Kalk�� yerini d�nd�ren get fonksiyonu
string Ucus::getKalkisYeri() const {
    return kalkisYeri_;
}

// Var�� yerini d�nd�ren get fonksiyonu
string Ucus::getVarisYeri() const {
    return varisYeri_;
}

// Kalk�� zaman�n� d�nd�ren get fonksiyonu
string Ucus::getKalkisZamani() const {
    return kalkisZamani_;
}

// Normal koltuk say�s�n� d�nd�ren get fonksiyonu
int Ucus::getNormalKoltukSayisi() const {
    return normalKoltukSayisi_;
}

// L�ks koltuk say�s�n� d�nd�ren get fonksiyonu
int Ucus::getLuksKoltukSayisi() const {
    return luksKoltukSayisi_;
}

// U�u� numaras�n� ayarlayan set fonksiyonu
void Ucus::setUcusNumarasi(int ucusNumarasi) {
    ucusNumarasi_ = ucusNumarasi;
}

// Kalk�� yerini ayarlayan set fonksiyonu
void Ucus::setKalkisYeri(const string& kalkisYeri) {
    kalkisYeri_ = kalkisYeri;
}

// Var�� yerini ayarlayan set fonksiyonu
void Ucus::setVarisYeri(const string& varisYeri) {
    varisYeri_ = varisYeri;
}

// Kalk�� zaman�n� ayarlayan set fonksiyonu
void Ucus::setKalkisZamani(const string& kalkisZamani) {
    kalkisZamani_ = kalkisZamani;
}

// Normal koltuk say�s�n� ayarlayan set fonksiyonu
void Ucus::setNormalKoltukSayisi(int normalKoltukSayisi) {
    normalKoltukSayisi_ = normalKoltukSayisi;
}

// L�ks koltuk say�s�n� ayarlayan set fonksiyonu
void Ucus::setLuksKoltukSayisi(int luksKoltukSayisi) {
    luksKoltukSayisi_ = luksKoltukSayisi;
}

// U�u� bilgilerini ekrana yazd�ran << operat�r�n�n a��r� y�klenmi� versiyonu
ostream& operator<<(ostream& os, const Ucus& ucus) {
	os << setw(15) << ucus.ucusNumarasi_ << setw(20) << ucus.kalkisYeri_ << setw(20) << ucus.varisYeri_ << setw(25) << ucus.kalkisZamani_ << setw(22) << ucus.normalKoltukSayisi_ << setw(20) << ucus.luksKoltukSayisi_ << endl;
	return os;
}

