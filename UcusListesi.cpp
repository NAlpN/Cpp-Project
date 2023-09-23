#include "UcusListesi.h"
#include <iostream>

using namespace std;

// UcusNumarasina_Gore_Ucus_Listesi s�n�f�n�n yap�c� fonksiyonu.
UcusNumarasina_Gore_Ucus_Listesi::UcusNumarasina_Gore_Ucus_Listesi() : head_(nullptr) {
}

// UcusNumarasina_Gore_Ucus_Listesi s�n�f�n�n y�k�c� fonksiyonu.
UcusNumarasina_Gore_Ucus_Listesi::~UcusNumarasina_Gore_Ucus_Listesi() {
    Node* current = head_;
    // Ba�l� listedeki her d���m� bellekten serbest b�rak.
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// UcusNumarasina_Gore_Ucus_Listesi'ne bir Ucus ��esi ekler.
void UcusNumarasina_Gore_Ucus_Listesi::ekle(const Ucus& ucus) {
    Node* newNode = new Node(ucus);
    // Liste bo�sa veya eklenen ucusun numaras�, listenin ba��ndaki ucustan k���kse:
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

// UcusNumarasina_Gore_Ucus_Listesi'ne lukssuz bir u�u� ekler.
void UcusNumarasina_Gore_Ucus_Listesi::ekleLukssuz(int ucusNumarasi, const string& kalkisYeri,
                                                  const string& varisYeri, const string& kalkisZamani,
                                                  int normalKoltukSayisi) {
    // UcusNumarasina_Gore_Ucus_Listesi'nde bu numaraya sahip bir u�u� varsa, ekleme i�lemini ger�ekle�tirme ve hata mesaj� verme.
    if (ara(ucusNumarasi) != nullptr) {
        cout << "Bu numaraya sahip bir u�u� zaten mevcut." << endl;
        return;
    }

    // Yeni bir Ucus ��esi olu�tur ve UcusNumarasina_Gore_Ucus_Listesi'ne ekle.
    Ucus ucus(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, 0);
    ekle(ucus);
}

// UcusNumarasina_Gore_Ucus_Listesi'ne luks bir u�u� ekler.
void UcusNumarasina_Gore_Ucus_Listesi::ekleLuks(int ucusNumarasi, const string& kalkisYeri,
                                               const string& varisYeri, const string& kalkisZamani,
                                               int normalKoltukSayisi, int luksKoltukSayisi) {
    // UcusNumarasina_Gore_Ucus_Listesi'nde bu numaraya sahip bir u�u� varsa, ekleme i�lemini ger�ekle�tirme ve hata mesaj� verme.
    if (ara(ucusNumarasi) != nullptr) {
        cout << "Bu numaraya sahip bir u�u� zaten mevcut." << endl;
        return;
    }

    // Yeni bir Ucus ��esi olu�tur ve UcusNumarasina_Gore_Ucus_Listesi'ne ekle.
    Ucus ucus(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
    ekle(ucus);
}

// Belirtilen bir u�u� numaras�na sahip u�u�u UcusNumarasina_Gore_Ucus_Listesi'nden siler.
void UcusNumarasina_Gore_Ucus_Listesi::sil(int ucusNumarasi) {
    if (head_ == nullptr) {
        return;
    }

    // Silinecek u�u�, listenin ba��ndaki u�u�sa:
    if (head_->ucus.getUcusNumarasi() == ucusNumarasi) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        return;
    }

    Node* current = head_;
    // Silinecek u�u�un konumunu bulana kadar ilerle.
    while (current->next != nullptr && current->next->ucus.getUcusNumarasi() != ucusNumarasi) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Belirtilen bir u�u� numaras�na sahip u�u�u UcusNumarasina_Gore_Ucus_Listesi'nde arar ve bulunursa ona bir referans d�nd�r�r.
Ucus* UcusNumarasina_Gore_Ucus_Listesi::ara(int ucusNumarasi) const {
    Node* current = head_;
    // Listenin sonuna kadar ilerle ve aranan u�u�u bul.
    while (current != nullptr) {
        if (current->ucus.getUcusNumarasi() == ucusNumarasi) {
            return &(current->ucus);
        }
        current = current->next;
    }
    // Aranan u�u� bulunamad�ysa, nullptr d�nd�r.
    return nullptr;
}

// UcusNumarasina_Gore_Ucus_Listesi'ndeki t�m u�u�lar� ekrana yazd�r�r.
void UcusNumarasina_Gore_Ucus_Listesi::yazdir() const {
    Node* current = head_;
    // Listenin sonuna kadar ilerle ve her bir u�u�u ekrana yazd�r.
    while (current != nullptr) {
        cout << current->ucus << endl;
        current = current->next;
    }
}

// UcusNumarasina_Gore_Ucus_Listesi'ndeki t�m luks u�u�lar� ekrana yazd�r�r.
void UcusNumarasina_Gore_Ucus_Listesi::yazdirLuksUcuslar() const {
    Node* current = head_;
    bool luksUcusBulundu = false;

    // Listenin sonuna kadar ilerle ve luks koltuk i�eren u�u�lar� ekrana yazd�r.
    while (current != nullptr) {
        if (current->ucus.getLuksKoltukSayisi() > 0) {
            cout << current->ucus << std::endl;
            luksUcusBulundu = true;
        }
        current = current->next;
    }

    // Hi�bir luks u�u� bulunamazsa, mesaj yazd�r.
    if (!luksUcusBulundu) {
        cout << "L�ks koltuk i�eren bir u�u� bulunamad�." << endl;
    }
}
