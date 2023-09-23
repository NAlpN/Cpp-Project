#include "Ucus.h"
#include <iostream>
#include <iomanip>

using namespace std;

Ucus::Ucus(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri, const string& kalkisZamani,
           int normalKoltukSayisi, int luksKoltukSayisi)
    : ucusNumarasi_(ucusNumarasi), kalkisYeri_(kalkisYeri), varisYeri_(varisYeri), kalkisZamani_(kalkisZamani),
      normalKoltukSayisi_(normalKoltukSayisi), luksKoltukSayisi_(luksKoltukSayisi) {
}

// Uçuþ numarasýný döndüren get fonksiyonu
int Ucus::getUcusNumarasi() const {
    return ucusNumarasi_;
}

// Kalkýþ yerini döndüren get fonksiyonu
string Ucus::getKalkisYeri() const {
    return kalkisYeri_;
}

// Varýþ yerini döndüren get fonksiyonu
string Ucus::getVarisYeri() const {
    return varisYeri_;
}

// Kalkýþ zamanýný döndüren get fonksiyonu
string Ucus::getKalkisZamani() const {
    return kalkisZamani_;
}

// Normal koltuk sayýsýný döndüren get fonksiyonu
int Ucus::getNormalKoltukSayisi() const {
    return normalKoltukSayisi_;
}

// Lüks koltuk sayýsýný döndüren get fonksiyonu
int Ucus::getLuksKoltukSayisi() const {
    return luksKoltukSayisi_;
}

// Uçuþ numarasýný ayarlayan set fonksiyonu
void Ucus::setUcusNumarasi(int ucusNumarasi) {
    ucusNumarasi_ = ucusNumarasi;
}

// Kalkýþ yerini ayarlayan set fonksiyonu
void Ucus::setKalkisYeri(const string& kalkisYeri) {
    kalkisYeri_ = kalkisYeri;
}

// Varýþ yerini ayarlayan set fonksiyonu
void Ucus::setVarisYeri(const string& varisYeri) {
    varisYeri_ = varisYeri;
}

// Kalkýþ zamanýný ayarlayan set fonksiyonu
void Ucus::setKalkisZamani(const string& kalkisZamani) {
    kalkisZamani_ = kalkisZamani;
}

// Normal koltuk sayýsýný ayarlayan set fonksiyonu
void Ucus::setNormalKoltukSayisi(int normalKoltukSayisi) {
    normalKoltukSayisi_ = normalKoltukSayisi;
}

// Lüks koltuk sayýsýný ayarlayan set fonksiyonu
void Ucus::setLuksKoltukSayisi(int luksKoltukSayisi) {
    luksKoltukSayisi_ = luksKoltukSayisi;
}

// Uçuþ bilgilerini ekrana yazdýran << operatörünün aþýrý yüklenmiþ versiyonu
ostream& operator<<(ostream& os, const Ucus& ucus) {
	os << setw(15) << ucus.ucusNumarasi_ << setw(20) << ucus.kalkisYeri_ << setw(20) << ucus.varisYeri_ << setw(25) << ucus.kalkisZamani_ << setw(22) << ucus.normalKoltukSayisi_ << setw(20) << ucus.luksKoltukSayisi_ << endl;
	return os;
}

