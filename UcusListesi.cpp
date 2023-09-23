#include "UcusListesi.h"
#include <iostream>

using namespace std;

// UcusNumarasina_Gore_Ucus_Listesi sýnýfýnýn yapýcý fonksiyonu.
UcusNumarasina_Gore_Ucus_Listesi::UcusNumarasina_Gore_Ucus_Listesi() : head_(nullptr) {
}

// UcusNumarasina_Gore_Ucus_Listesi sýnýfýnýn yýkýcý fonksiyonu.
UcusNumarasina_Gore_Ucus_Listesi::~UcusNumarasina_Gore_Ucus_Listesi() {
    Node* current = head_;
    // Baðlý listedeki her düðümü bellekten serbest býrak.
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// UcusNumarasina_Gore_Ucus_Listesi'ne bir Ucus öðesi ekler.
void UcusNumarasina_Gore_Ucus_Listesi::ekle(const Ucus& ucus) {
    Node* newNode = new Node(ucus);
    // Liste boþsa veya eklenen ucusun numarasý, listenin baþýndaki ucustan küçükse:
    if (head_ == nullptr || ucus.getUcusNumarasi() < head_->ucus.getUcusNumarasi()) {
        newNode->next = head_;
        head_ = newNode;
    } else {
        Node* current = head_;
        // Listede uygun konumu bulana kadar ilerle.
        while (current->next != nullptr && ucus.getUcusNumarasi() > current->next->ucus.getUcusNumarasi()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// UcusNumarasina_Gore_Ucus_Listesi'ne lukssuz bir uçuþ ekler.
void UcusNumarasina_Gore_Ucus_Listesi::ekleLukssuz(int ucusNumarasi, const string& kalkisYeri,
                                                  const string& varisYeri, const string& kalkisZamani,
                                                  int normalKoltukSayisi) {
    // UcusNumarasina_Gore_Ucus_Listesi'nde bu numaraya sahip bir uçuþ varsa, ekleme iþlemini gerçekleþtirme ve hata mesajý verme.
    if (ara(ucusNumarasi) != nullptr) {
        cout << "Bu numaraya sahip bir uçuþ zaten mevcut." << endl;
        return;
    }

    // Yeni bir Ucus öðesi oluþtur ve UcusNumarasina_Gore_Ucus_Listesi'ne ekle.
    Ucus ucus(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, 0);
    ekle(ucus);
}

// UcusNumarasina_Gore_Ucus_Listesi'ne luks bir uçuþ ekler.
void UcusNumarasina_Gore_Ucus_Listesi::ekleLuks(int ucusNumarasi, const string& kalkisYeri,
                                               const string& varisYeri, const string& kalkisZamani,
                                               int normalKoltukSayisi, int luksKoltukSayisi) {
    // UcusNumarasina_Gore_Ucus_Listesi'nde bu numaraya sahip bir uçuþ varsa, ekleme iþlemini gerçekleþtirme ve hata mesajý verme.
    if (ara(ucusNumarasi) != nullptr) {
        cout << "Bu numaraya sahip bir uçuþ zaten mevcut." << endl;
        return;
    }

    // Yeni bir Ucus öðesi oluþtur ve UcusNumarasina_Gore_Ucus_Listesi'ne ekle.
    Ucus ucus(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
    ekle(ucus);
}

// Belirtilen bir uçuþ numarasýna sahip uçuþu UcusNumarasina_Gore_Ucus_Listesi'nden siler.
void UcusNumarasina_Gore_Ucus_Listesi::sil(int ucusNumarasi) {
    if (head_ == nullptr) {
        return;
    }

    // Silinecek uçuþ, listenin baþýndaki uçuþsa:
    if (head_->ucus.getUcusNumarasi() == ucusNumarasi) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        return;
    }

    Node* current = head_;
    // Silinecek uçuþun konumunu bulana kadar ilerle.
    while (current->next != nullptr && current->next->ucus.getUcusNumarasi() != ucusNumarasi) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Belirtilen bir uçuþ numarasýna sahip uçuþu UcusNumarasina_Gore_Ucus_Listesi'nde arar ve bulunursa ona bir referans döndürür.
Ucus* UcusNumarasina_Gore_Ucus_Listesi::ara(int ucusNumarasi) const {
    Node* current = head_;
    // Listenin sonuna kadar ilerle ve aranan uçuþu bul.
    while (current != nullptr) {
        if (current->ucus.getUcusNumarasi() == ucusNumarasi) {
            return &(current->ucus);
        }
        current = current->next;
    }
    // Aranan uçuþ bulunamadýysa, nullptr döndür.
    return nullptr;
}

// UcusNumarasina_Gore_Ucus_Listesi'ndeki tüm uçuþlarý ekrana yazdýrýr.
void UcusNumarasina_Gore_Ucus_Listesi::yazdir() const {
    Node* current = head_;
    // Listenin sonuna kadar ilerle ve her bir uçuþu ekrana yazdýr.
    while (current != nullptr) {
        cout << current->ucus << endl;
        current = current->next;
    }
}

// UcusNumarasina_Gore_Ucus_Listesi'ndeki tüm luks uçuþlarý ekrana yazdýrýr.
void UcusNumarasina_Gore_Ucus_Listesi::yazdirLuksUcuslar() const {
    Node* current = head_;
    bool luksUcusBulundu = false;

    // Listenin sonuna kadar ilerle ve luks koltuk içeren uçuþlarý ekrana yazdýr.
    while (current != nullptr) {
        if (current->ucus.getLuksKoltukSayisi() > 0) {
            cout << current->ucus << std::endl;
            luksUcusBulundu = true;
        }
        current = current->next;
    }

    // Hiçbir luks uçuþ bulunamazsa, mesaj yazdýr.
    if (!luksUcusBulundu) {
        cout << "Lüks koltuk içeren bir uçuþ bulunamadý." << endl;
    }
}
