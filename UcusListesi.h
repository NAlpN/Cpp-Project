#ifndef UCUSLISTESI_H // Ön iþlemci direktifi, ayný header dosyasýnýn birden fazla kez dahil edilmesini engeller.
#define UCUSLISTESI_H // Ön iþlemci direktifi, UCUSLISTESI_H'nin tanýmlandýðýný belirtir.
#include "Ucus.h" // Ucus.h header dosyasýný dahil eder.

using namespace std; // std isim uzayýný kullanýr.

// Uçuþ listesi sýnýfýný tanýmlar.
class UcusNumarasina_Gore_Ucus_Listesi {
private:
    // Ýçerisinde bir Ucus nesnesi ve bir sonraki düðüme iþaret eden bir pointer bulunduran bir düðüm sýnýfý tanýmlar.
    class Node {
    public:
        Ucus ucus; // Ucus türünde ucus nesnesi.
        Node* next; // Sonraki düðüme iþaret eden pointer.

        // Düðümün yapýcý fonksiyonu.
        Node(const Ucus& ucus, Node* next = nullptr)
            : ucus(ucus), next(next) {
        }
    };

    Node* head_; // Listenin baþýný gösteren pointer.

public:
    // UcusNumarasina_Gore_Ucus_Listesi sýnýfýnýn yapýcý ve yýkýcý fonksiyonlarý.
    UcusNumarasina_Gore_Ucus_Listesi();
    ~UcusNumarasina_Gore_Ucus_Listesi();

    // Uçuþ eklemek için metodlar.
    void ekle(const Ucus& ucus);
    void ekleLukssuz(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri,
                    const string& kalkisZamani, int normalKoltukSayisi);
    void ekleLuks(int ucusNumarasi, const string& kalkisYeri, const string& varisYeri,
                  const string& kalkisZamani, int normalKoltukSayisi, int luksKoltukSayisi);

    void sil(int ucusNumarasi); // Uçuþ silmek için metod.
    Ucus* ara(int ucusNumarasi) const; // Uçuþ aramak için metod.
    
    // Uçuþlarý yazdýrmak için metodlar.
    void yazdir() const; 
    void yazdirLuksUcuslar() const;
};

#endif  // UCUSNUMARASINA_GORE_UCUS_LISTESI_H // Ön iþlemci direktifi, UCUSNUMARASINA_GORE_UCUS_LISTESI_H'nin sonunu belirtir.

