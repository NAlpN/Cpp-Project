#ifndef UCUSLISTESI_H // �n i�lemci direktifi, ayn� header dosyas�n�n birden fazla kez dahil edilmesini engeller.
#define UCUSLISTESI_H // �n i�lemci direktifi, UCUSLISTESI_H'nin tan�mland���n� belirtir.
#include "Ucus.h" // Ucus.h header dosyas�n� dahil eder.

using namespace std; // std isim uzay�n� kullan�r.

// U�u� listesi s�n�f�n� tan�mlar.
class UcusNumarasina_Gore_Ucus_Listesi {
private:
    // ��erisinde bir Ucus nesnesi ve bir sonraki d���me i�aret eden bir pointer bulunduran bir d���m s�n�f� tan�mlar.
    class Node {
    public:
        Ucus ucus; // Ucus t�r�nde ucus nesnesi.
        Node* next; // Sonraki d���me i�aret eden pointer.

        // D���m�n yap�c� fonksiyonu.
        Node(const Ucus& ucus, Node* next = nullptr)
            : ucus(ucus), next(next) {
        }
    };

    Node* head_; // Listenin ba��n� g�steren pointer.

public:
    // UcusNumarasina_Gore_Ucus_Listesi s�n�f�n�n yap�c� ve y�k�c� fonksiyonlar�.
    UcusNumarasina_Gore_Ucus_Listesi();
    ~UcusNumarasina_Gore_Ucus_Listesi();

    // U�u� eklemek i�in metodlar.
    void ekle(const Ucus& ucus);
    void ekleLukssuz(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri,
                    const string& kalkisZamani, int normalKoltukSayisi);
    void ekleLuks(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri,
                  const string& kalkisZamani, int normalKoltukSayisi, int luksKoltukSayisi);

    void sil(int ucusNumarasi); // U�u� silmek i�in metod.
    Ucus* ara(int ucusNumarasi) const; // U�u� aramak i�in metod.
    
    // U�u�lar� yazd�rmak i�in metodlar.
    void yazdir() const; 
    void yazdirLuksUcuslar() const;
};

#endif  // UCUSNUMARASINA_GORE_UCUS_LISTESI_H // �n i�lemci direktifi, UCUSNUMARASINA_GORE_UCUS_LISTESI_H'nin sonunu belirtir.

