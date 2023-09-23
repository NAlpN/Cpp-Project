#include "Ucus.h"
#include "KalkisListesi.h"
#include <iostream>
#include <vector>

using namespace std;

Kalkis_Yerine_Gore_Ucus_Listesi::Kalkis_Yerine_Gore_Ucus_Listesi() : head_(nullptr) {
}

Kalkis_Yerine_Gore_Ucus_Listesi::~Kalkis_Yerine_Gore_Ucus_Listesi() {
    // Y�k�c� fonksiyon, ba�l� listeyi temizlemek i�in kullan�l�r.
    Node* current = head_;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ekle(const Ucus& ucus) {
    // U�u�u uygun konuma ekleyen fonksiyon
    Node* newNode = new Node(ucus);
    if (head_ == nullptr || ucus.getKalkisYeri() < head_->ucus.getKalkisYeri() ||
        (ucus.getKalkisYeri() == head_->ucus.getKalkisYeri() && ucus.getKalkisZamani() < head_->ucus.getKalkisZamani())) {
        // E�er liste bo�sa veya yeni u�u� listenin ba��na eklenmelidir.
        newNode->next = head_;
        if (head_ != nullptr) {
            head_->prev = newNode;
        }
        head_ = newNode;
    } else {
        // Yeni u�u� listenin i�ine uygun konuma eklenmelidir.
        Node* current = head_;
        while (current->next != nullptr &&
               (ucus.getKalkisYeri() > current->next->ucus.getKalkisYeri() ||
                (ucus.getKalkisYeri() == current->next->ucus.getKalkisYeri() &&
                 ucus.getKalkisZamani() > current->next->ucus.getKalkisZamani()))) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ekleLukssuz(int ucusNumarasi, const string& kalkisYeri,
                                                 const string& varisYeri, const string& kalkisZamani,
                                                 int normalKoltukSayisi) {
    // L�ks olmayan bir u�u� eklemek i�in kullan�l�r.
    Ucus ucus(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, 0);
    ekle(ucus);
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ekleLuks(int ucusNumarasi, const string& kalkisYeri,
                                              const string& varisYeri, const string& kalkisZamani,
                                              int normalKoltukSayisi, int luksKoltukSayisi) {
    // L�ks bir u�u� eklemek i�in kullan�l�r.
    Ucus ucus(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
    ekle(ucus);
}

void Kalkis_Yerine_Gore_Ucus_Listesi::sil(int ucusNumarasi) {
    // Belirli bir u�u�u listeden siler.
    if (head_ == nullptr) {
        return;
    }

    if (head_->ucus.getUcusNumarasi() == ucusNumarasi) {
        // �lk d���m silinmelidir.
        Node* temp = head_;
        head_ = head_->next;
        if (head_ != nullptr) {
            head_->prev = nullptr;
        }
        delete temp;
        return;
    }

    Node* current = head_;
    while (current->next != nullptr && current->next->ucus.getUcusNumarasi() != ucusNumarasi) {
        current = current->next;
    }

    if (current->next != nullptr) {
        // Aradan bir d���m silinmelidir.
        Node* temp = current->next;
        current->next = current->next->next;
        if (current->next != nullptr) {
            current->next->prev = current;
        }
        delete temp;
    }
}

Ucus* Kalkis_Yerine_Gore_Ucus_Listesi::araKalkisYerineGore(const string& kalkisYeri) const {
    // Belirli bir kalk�� yeri ile u�u� arar ve bulunursa u�u�un adresini d�nd�r�r.
    Node* current = head_;
    while (current != nullptr) {
        if (current->ucus.getKalkisYeri() == kalkisYeri) {
            return &(current->ucus);
        }
        current = current->next;
    }
    return nullptr;
}

Ucus* Kalkis_Yerine_Gore_Ucus_Listesi::araUcusNumarasinaGore(int ucusNumarasi) const {
    // Belirli bir u�u� numaras�na g�re u�u� arar ve bulunursa u�u�un adresini d�nd�r�r.
    Node* current = head_;
    while (current != nullptr) {
        if (current->ucus.getUcusNumarasi() == ucusNumarasi) {
            return &(current->ucus);
        }
        current = current->next;
    }
    return nullptr;
}

void Kalkis_Yerine_Gore_Ucus_Listesi::yazdir() const {
    // T�m u�u�lar� ekrana yazd�r�r.
    Node* current = head_;
    while (current != nullptr) {
        cout << current->ucus << endl;
        current = current->next;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::yazdirKalkisYerineGore(const string& kalkisYeri) const {
    // Belirli bir kalk�� yeri i�in u�u�lar� ekrana yazd�r�r.
    Node* current = head_;
    bool bulundu = false;
    vector<Ucus> kalkisYeriUcuslari;

    while (current != nullptr) {
        if (current->ucus.getKalkisYeri() == kalkisYeri) {
            kalkisYeriUcuslari.push_back(current->ucus);
            bulundu = true;
        }
        current = current->next;
    }

    if (!bulundu) {
        cout << kalkisYeri << " kalk�� yerine sahip bir u�u� bulunamad�." << endl;
        return;
    }

    // Kalk�� zamanlar�na g�re s�ralama (artan s�ra)
    sort(kalkisYeriUcuslari.begin(), kalkisYeriUcuslari.end(),
        [](const Ucus& a, const Ucus& b) { return a.getKalkisZamani() < b.getKalkisZamani(); });

    // Zaman s�ras�na g�re listeleme
    for (const auto& ucus : kalkisYeriUcuslari) {
        cout << ucus << endl;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::yazdirVarisYerineGore(const string& varisYeri) const {
    // Belirli bir var�� yeri i�in u�u�lar� ekrana yazd�r�r.
    Node* current = head_;
    bool bulundu = false;
    vector<Ucus> varisYeriUcuslari;

    while (current != nullptr) {
        if (current->ucus.getVarisYeri() == varisYeri) {
            varisYeriUcuslari.push_back(current->ucus);
            bulundu = true;
        }
        current = current->next;
    }

    if (!bulundu) {
        cout << varisYeri << " var�� yerine sahip bir u�u� bulunamad�." << endl;
        return;
    }

    // Kalk�� yerlerine g�re s�ralama
    sort(varisYeriUcuslari.begin(), varisYeriUcuslari.end(),
              [](const Ucus &a, const Ucus &b) { return a.getKalkisYeri() < b.getKalkisYeri(); });

    // Alfabetik s�raya g�re listeleme
    for (const auto& ucus : varisYeriUcuslari) {
        cout << ucus << endl;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::yazdirZamanYerineGore(const string& kalkisYeri, const string& varisYeri) const {
    // Belirli bir kalk�� yeri ve var�� yeri i�in u�u�lar� ekrana yazd�r�r.
    Node* current = head_;
    bool bulundu = false;
    vector<Ucus> zamanYeriUcuslari;

    while (current != nullptr) {
        if (current->ucus.getKalkisYeri() == kalkisYeri && current->ucus.getVarisYeri() == varisYeri) {
            zamanYeriUcuslari.push_back(current->ucus);
            bulundu = true;
        }
        current = current->next;
    }

    if (!bulundu) {
        cout << kalkisYeri << " kalk�� yerinden " << varisYeri << " var�� yerine sahip bir u�u� bulunamad�." << endl;
        return;
    }

    // Kalk�� zamanlar�na g�re s�ralama (azalan s�ra)
    sort(zamanYeriUcuslari.begin(), zamanYeriUcuslari.end(),
        [](const Ucus& a, const Ucus& b) { return a.getKalkisZamani() > b.getKalkisZamani(); });

    // Zaman s�ras�na g�re listeleme
    for (const auto& ucus : zamanYeriUcuslari) {
        cout << ucus << endl;
    }
}
