#ifndef UCUS_H
#define UCUS_H

#include <string>

using namespace std;

class Ucus {
private:
    int ucusNumarasi_;              // Uçuþ numarasý
    string kalkisYeri_;             // Kalkýþ yeri
    string varisYeri_;              // Varýþ yeri
    string kalkisZamani_;           // Kalkýþ zamaný
    int normalKoltukSayisi_;        // Normal koltuk sayýsý
    int luksKoltukSayisi_;          // Lüks koltuk sayýsý

public:
    Ucus(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri, const string& kalkisZamani,
         int normalKoltukSayisi, int luksKoltukSayisi);

    // Get fonksiyonlarý
    int getUcusNumarasi() const;
    string getKalkisYeri() const;
    string getVarisYeri() const;
    string getKalkisZamani() const;
    int getNormalKoltukSayisi() const;
    int getLuksKoltukSayisi() const;

    // Set fonksiyonlarý
    void setUcusNumarasi(int ucusNumarasi);
    void setKalkisYeri(const string& kalkisYeri);
    void setVarisYeri(const string& varisYeri);
    void setKalkisZamani(const string& kalkisZamani);
    void setNormalKoltukSayisi(int normalKoltukSayisi);
    void setLuksKoltukSayisi(int luksKoltukSayisi);

    // << operatörünün aþýrý yüklenmesi
    friend ostream& operator<<(ostream& os, const Ucus& ucus);
};

#endif  // UCUS_H

