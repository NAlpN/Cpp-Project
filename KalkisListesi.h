#ifndef KALKISLISTESI_H
#define KALKISLISTESI_H

#include "Ucus.h"
#include <vector>
#include <algorithm>

using namespace std;

class Kalkis_Yerine_Gore_Ucus_Listesi {
private:
    class Node {
    public:
        Ucus ucus;
        Node* prev;
        Node* next;

        Node(const Ucus& ucus, Node* prev = nullptr, Node* next = nullptr)
            : ucus(ucus), prev(prev), next(next) {
        }
    };

    Node* head_;  // Baþ düðümün iþaret ettiði liste baþý

public:
    Kalkis_Yerine_Gore_Ucus_Listesi();
    ~Kalkis_Yerine_Gore_Ucus_Listesi();

    void ekle(const Ucus& ucus);
    // Belirli bir uçuþu uygun konuma ekler

    void ekleLukssuz(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri,
                    const string& kalkisZamani, int normalKoltukSayisi);
    // Lüks olmayan bir uçuþ ekler

    void ekleLuks(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri,
                  const string& kalkisZamani, int normalKoltukSayisi, int luksKoltukSayisi);
    // Lüks bir uçuþ ekler

    void sil(int ucusNumarasi);
    // Belirli bir uçuþu listeden siler

    Ucus* araKalkisYerineGore(const string& kalkisYeri) const;
    // Belirli bir kalkýþ yeri ile uçuþ arar ve bulunursa uçuþun adresini döndürür

    Ucus* araUcusNumarasinaGore(int ucusNumarasi) const;
    // Belirli bir uçuþ numarasýna göre uçuþ arar ve bulunursa uçuþun adresini döndürür

    void yazdir() const;
    // Tüm uçuþlarý ekrana yazdýrýr

    void yazdirVarisYerineGore(const string& varisYeri) const;
    // Belirli bir varýþ yeri için uçuþlarý ekrana yazdýrýr

    void yazdirKalkisYerineGore(const string& kalkisYeri) const;
    // Belirli bir kalkýþ yeri için uçuþlarý ekrana yazdýrýr

    void yazdirZamanYerineGore(const string& kalkisYeri, const string& varisYeri) const;
    // Belirli bir kalkýþ yeri ve varýþ yeri için uçuþlarý ekrana yazdýrýr
};

#endif  // KALKISLISTESI_H
