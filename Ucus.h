#ifndef UCUS_H
#define UCUS_H

#include <string>

using namespace std;

class Ucus {
private:
    int ucusNumarasi_;              // U�u� numaras�
    string kalkisYeri_;             // Kalk�� yeri
    string varisYeri_;              // Var�� yeri
    string kalkisZamani_;           // Kalk�� zaman�
    int normalKoltukSayisi_;        // Normal koltuk say�s�
    int luksKoltukSayisi_;          // L�ks koltuk say�s�

public:
    Ucus(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri, const string& kalkisZamani,
         int normalKoltukSayisi, int luksKoltukSayisi);

    // Get fonksiyonlar�
    int getUcusNumarasi() const;
    string getKalkisYeri() const;
    string getVarisYeri() const;
    string getKalkisZamani() const;
    int getNormalKoltukSayisi() const;
    int getLuksKoltukSayisi() const;

    // Set fonksiyonlar�
    void setUcusNumarasi(int ucusNumarasi);
    void setKalkisYeri(const string& kalkisYeri);
    void setVarisYeri(const string& varisYeri);
    void setKalkisZamani(const string& kalkisZamani);
    void setNormalKoltukSayisi(int normalKoltukSayisi);
    void setLuksKoltukSayisi(int luksKoltukSayisi);

    // << operat�r�n�n a��r� y�klenmesi
    friend ostream& operator<<(ostream& os, const Ucus& ucus);
};

#endif  // UCUS_H

