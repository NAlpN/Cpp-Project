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

    Node* head_;  // Ba� d���m�n i�aret etti�i liste ba��

public:
    Kalkis_Yerine_Gore_Ucus_Listesi();
    ~Kalkis_Yerine_Gore_Ucus_Listesi();

    void ekle(const Ucus& ucus);
    // Belirli bir u�u�u uygun konuma ekler

    void ekleLukssuz(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri,
                    const string& kalkisZamani, int normalKoltukSayisi);
    // L�ks olmayan bir u�u� ekler

    void ekleLuks(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri,
                  const string& kalkisZamani, int normalKoltukSayisi, int luksKoltukSayisi);
    // L�ks bir u�u� ekler

    void sil(int ucusNumarasi);
    // Belirli bir u�u�u listeden siler

    Ucus* araKalkisYerineGore(const string& kalkisYeri) const;
    // Belirli bir kalk�� yeri ile u�u� arar ve bulunursa u�u�un adresini d�nd�r�r

    Ucus* araUcusNumarasinaGore(int ucusNumarasi) const;
    // Belirli bir u�u� numaras�na g�re u�u� arar ve bulunursa u�u�un adresini d�nd�r�r

    void yazdir() const;
    // T�m u�u�lar� ekrana yazd�r�r

    void yazdirVarisYerineGore(const string& varisYeri) const;
    // Belirli bir var�� yeri i�in u�u�lar� ekrana yazd�r�r

    void yazdirKalkisYerineGore(const string& kalkisYeri) const;
    // Belirli bir kalk�� yeri i�in u�u�lar� ekrana yazd�r�r

    void yazdirZamanYerineGore(const string& kalkisYeri, const string& varisYeri) const;
    // Belirli bir kalk�� yeri ve var�� yeri i�in u�u�lar� ekrana yazd�r�r
};

#endif  // KALKISLISTESI_H
