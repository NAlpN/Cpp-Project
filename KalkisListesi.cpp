#include "Ucus.h"
#include "KalkisListesi.h"
#include <iostream>
#include <vector>

using namespace std;

Kalkis_Yerine_Gore_Ucus_Listesi::Kalkis_Yerine_Gore_Ucus_Listesi() : head_(nullptr) {
}

Kalkis_Yerine_Gore_Ucus_Listesi::~Kalkis_Yerine_Gore_Ucus_Listesi() {
    // Yýkýcý fonksiyon, baðlý listeyi temizlemek için kullanýlýr.
    Node* current = head_;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ekle(const Ucus& ucus) {
    // Uçuþu uygun konuma ekleyen fonksiyon
    Node* newNode = new Node(ucus);
    if (head_ == nullptr || ucus.getKalkisYeri() < head_->ucus.getKalkisYeri() ||
        (ucus.getKalkisYeri() == head_->ucus.getKalkisYeri() && ucus.getKalkisZamani() < head_->ucus.getKalkisZamani())) {
        // Eðer liste boþsa veya yeni uçuþ listenin baþýna eklenmelidir.
        newNode->next = head_;
        if (head_ != nullptr) {
            head_->prev = newNode;
        }
        head_ = newNode;
    } else {
        // Yeni uçuþ listenin içine uygun konuma eklenmelidir.
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
    // Lüks olmayan bir uçuþ eklemek için kullanýlýr.
    Ucus ucus(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, 0);
    ekle(ucus);
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ekleLuks(int ucusNumarasi, const string& kalkisYeri,
                                              const string& varisYeri, const string& kalkisZamani,
                                              int normalKoltukSayisi, int luksKoltukSayisi) {
    // Lüks bir uçuþ eklemek için kullanýlýr.
    Ucus ucus(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
    ekle(ucus);
}

void Kalkis_Yerine_Gore_Ucus_Listesi::sil(int ucusNumarasi) {
    // Belirli bir uçuþu listeden siler.
    if (head_ == nullptr) {
        return;
    }

    if (head_->ucus.getUcusNumarasi() == ucusNumarasi) {
        // Ýlk düðüm silinmelidir.
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
        // Aradan bir düðüm silinmelidir.
        Node* temp = current->next;
        current->next = current->next->next;
        if (current->next != nullptr) {
            current->next->prev = current;
        }
        delete temp;
    }
}

Ucus* Kalkis_Yerine_Gore_Ucus_Listesi::araKalkisYerineGore(const string& kalkisYeri) const {
    // Belirli bir kalkýþ yeri ile uçuþ arar ve bulunursa uçuþun adresini döndürür.
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
    // Belirli bir uçuþ numarasýna göre uçuþ arar ve bulunursa uçuþun adresini döndürür.
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
    // Tüm uçuþlarý ekrana yazdýrýr.
    Node* current = head_;
    while (current != nullptr) {
        cout << current->ucus << endl;
        current = current->next;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::yazdirKalkisYerineGore(const string& kalkisYeri) const {
    // Belirli bir kalkýþ yeri için uçuþlarý ekrana yazdýrýr.
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
        cout << kalkisYeri << " kalkýþ yerine sahip bir uçuþ bulunamadý." << endl;
        return;
    }

    // Kalkýþ zamanlarýna göre sýralama (artan sýra)
    sort(kalkisYeriUcuslari.begin(), kalkisYeriUcuslari.end(),
        [](const Ucus& a, const Ucus& b) { return a.getKalkisZamani() < b.getKalkisZamani(); });

    // Zaman sýrasýna göre listeleme
    for (const auto& ucus : kalkisYeriUcuslari) {
        cout << ucus << endl;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::yazdirVarisYerineGore(const string& varisYeri) const {
    // Belirli bir varýþ yeri için uçuþlarý ekrana yazdýrýr.
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
        cout << varisYeri << " varýþ yerine sahip bir uçuþ bulunamadý." << endl;
        return;
    }

    // Kalkýþ yerlerine göre sýralama
    sort(varisYeriUcuslari.begin(), varisYeriUcuslari.end(),
              [](const Ucus &a, const Ucus &b) { return a.getKalkisYeri() < b.getKalkisYeri(); });

    // Alfabetik sýraya göre listeleme
    for (const auto& ucus : varisYeriUcuslari) {
        cout << ucus << endl;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::yazdirZamanYerineGore(const string& kalkisYeri, const string& varisYeri) const {
    // Belirli bir kalkýþ yeri ve varýþ yeri için uçuþlarý ekrana yazdýrýr.
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
        cout << kalkisYeri << " kalkýþ yerinden " << varisYeri << " varýþ yerine sahip bir uçuþ bulunamadý." << endl;
        return;
    }

    // Kalkýþ zamanlarýna göre sýralama (azalan sýra)
    sort(zamanYeriUcuslari.begin(), zamanYeriUcuslari.end(),
        [](const Ucus& a, const Ucus& b) { return a.getKalkisZamani() > b.getKalkisZamani(); });

    // Zaman sýrasýna göre listeleme
    for (const auto& ucus : zamanYeriUcuslari) {
        cout << ucus << endl;
    }
}
