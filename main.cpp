#include <iostream>
#include <cstring>
#include <clocale>
#include "Ucus.h"
#include "UcusListesi.h"
#include "KalkisListesi.h"
#include "Ucus.cpp"
#include "UcusListesi.cpp"
#include "KalkisListesi.cpp"

using namespace std;

int main() 
{
    // Uçuþ listeleri oluþturuluyor
    UcusNumarasina_Gore_Ucus_Listesi ucusNumarasiListesi;
    Kalkis_Yerine_Gore_Ucus_Listesi kalkisYeriListesi;

    setlocale(LC_ALL, "Turkish"); 
    int secim = 0;
    while (secim != 10) 
    {
        // Menü seçenekleri gösteriliyor
        cout << "----------- MENU -----------" << endl;
        cout << "1. Lüks koltuk içermeyen yeni bir uçuþ ekle" << endl;
        cout << "2. Lüks koltuk içeren yeni bir uçuþ ekle" << endl;
        cout << "3. Bir uçuþun lüks koltuk sayýsýný güncelle" << endl;
        cout << "4. Bir uçuþu iptal et" << endl;
        cout << "5. Bir uçuþun bilgilerini görüntüle" << endl;
        cout << "6. Lüks koltuk içeren uçuþlarý listele" << endl;
        cout << "7. Varýþ yerine göre uçuþlarý listele" << endl;
        cout << "8. Kalkýþ yerine göre uçuþlarý listele" << endl;
        cout << "9. Kalkýþ ve varýþ yerine göre uçuþlarý listele" << endl;
        cout << "10. Çýkýþ" << endl;
        cout << "Yapmak istediðiniz iþlemi giriniz: ";
        cin >> secim;
        
        switch (secim) 
        {
            case 1: 
            {
                // Lüks koltuk içermeyen yeni bir uçuþ eklemek için gereken bilgiler alýnýyor
                int ucusNumarasi, normalKoltukSayisi;
                string kalkisYeri, varisYeri, kalkisZamani;

                cout << "Uçuþ Numarasý giriniz: ";
                cin >> ucusNumarasi;

                // Uçuþ numarasý daha önceden mevcutsa hata mesajý veriliyor
                if (ucusNumarasiListesi.ara(ucusNumarasi) != nullptr) 
                {
                    cout << "Bu numaraya sahip bir uçuþ zaten mevcut." << endl;
                    break;
                }
                cout << "Kalkýþ Yerini girin: ";
                cin  >> kalkisYeri;
                if (kalkisYeri.length() > 20)
                {
                	cout << "Hata: Kalkýþ yeri uzunluðu en fazla 20 karakter olabilir." << endl;
                	break;
				}
                transform(kalkisYeri.begin(), kalkisYeri.end(), kalkisYeri.begin(), ::toupper);
				cout << "Varýþ Yerini girin: ";
                cin  >> varisYeri;
                if (varisYeri.length() > 20)
                {
                	cout << "Hata: Varýþ yeri uzunluðu en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(varisYeri.begin(), varisYeri.end(), varisYeri.begin(), ::toupper);
				cout << "Kalkýþ Zamanýný girin: ";
                cin  >> kalkisZamani;
                if (kalkisZamani.length() > 5 || stoi(kalkisZamani) < 0 || stoi(kalkisZamani) > 23)
                {
                	cout << "Hata: Kalkýþ zamaný uzunluðu en fazla 5 karakter olabilir ve Kalkýþ saati 24 saat dilimine göre 00-23 arasýnda olabilir." << endl;
                	break;
				}
				cout << "Normal Koltuk Sayýsýný girin: ";
                cin >> normalKoltukSayisi;

                // Uçuþ listelerine lüks koltuk içermeyen uçuþu ekliyoruz
                ucusNumarasiListesi.ekleLukssuz(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi);
                kalkisYeriListesi.ekleLukssuz(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi);
                cout << "Uçuþ eklendi." << endl;
                cout << setw(15) << "Uçuþ Numarasý" << setw(20) << "Kalkýþ Yeri" << setw(20) << "Varýþ Yeri" << setw(25) << "Kalkýþ Zamaný" << setw(22) << "Normal Koltuk Sayýsý" << setw(20) << "Lüks Koltuk Sayýsý" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdir();
                break;
            }
            case 2: 
            {
                // Lüks koltuk içeren yeni bir uçuþ eklemek için gereken bilgiler alýnýyor
                int ucusNumarasi, normalKoltukSayisi, luksKoltukSayisi;
                string kalkisYeri, varisYeri, kalkisZamani;
                cout << "Uçuþ Numarasýný girin: ";
                cin >> ucusNumarasi;

                // Uçuþ numarasý daha önceden mevcutsa hata mesajý veriliyor
                if (ucusNumarasiListesi.ara(ucusNumarasi) != nullptr) 
                {
                    cout << "Bu numaraya sahip bir uçuþ zaten mevcut." << endl;
                    break;
                }

                cout << "Kalkýþ Yerini girin: ";
                cin >> kalkisYeri;
                if (kalkisYeri.length() > 20)
                {
                	cout << "Hata: Kalkýþ yeri uzunluðu en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(kalkisYeri.begin(), kalkisYeri.end(), kalkisYeri.begin(), ::toupper);
                cout << "Varýþ Yerini girin: ";
                cin >> varisYeri;
                if (varisYeri.length() > 20)
                {
                	cout << "Hata: Varýþ yeri uzunluðu en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(varisYeri.begin(), varisYeri.end(), varisYeri.begin(), ::toupper);
				cout << "Kalkýþ Zamanýný girin: ";
                cin >> kalkisZamani;
                if (kalkisZamani.length() > 5 || stoi(kalkisZamani) < 0 || stoi(kalkisZamani) > 23)
                {
                	cout << "Hata: Kalkýþ zamaný uzunluðu en fazla 5 karakter olabilir ve Kalkýþ saati 24 saat dilimine göre 00-23 arasýnda olabilir." << endl;
                	break;
				}
				cout << "Normal Koltuk Sayýsýný girin: ";
                cin >> normalKoltukSayisi;
                cout << "Luks Koltuk Sayýsýný girin: ";
                cin >> luksKoltukSayisi;

                // Uçuþ listelerine lüks koltuk içeren uçuþu ekliyoruz
                ucusNumarasiListesi.ekleLuks(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
                kalkisYeriListesi.ekleLuks(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
                cout << "Uçuþ eklendi." << endl;
                cout << setw(15) << "Uçuþ Numarasý" << setw(20) << "Kalkýþ Yeri" << setw(20) << "Varýþ Yeri" << setw(25) << "Kalkýþ Zamaný" << setw(22) << "Normal Koltuk Sayýsý" << setw(20) << "Lüks Koltuk Sayýsý" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdir();
                break;
            }
            case 3: 
            {
                // Bir uçuþun lüks koltuk sayýsýný güncellemek için gereken bilgiler alýnýyor
                int ucusNumarasi, yeniLuksKoltukSayisi;
            
                cout << "Güncellenecek Uçuþ Numarasýný girin: ";
                cin >> ucusNumarasi;
            
                // Uçuþ numarasý mevcut deðilse hata mesajý veriliyor
                Ucus* ucus = ucusNumarasiListesi.ara(ucusNumarasi);
                Ucus* ucus2 = kalkisYeriListesi.araUcusNumarasinaGore(ucusNumarasi);  // ayný uçuþ numarasýný kalkisYeriListesi'nde de arýyoruz
            
                if (ucus == nullptr || ucus2 == nullptr) 
                {
                    cout << "Bu numaraya sahip bir uçuþ bulunamadý." << endl;
                    break;
                }
            
                cout << "Yeni Luks Koltuk Sayýsýný girin: ";
                cin >> yeniLuksKoltukSayisi;
            
                // Uçuþun lüks koltuk sayýsýný güncelliyoruz
                ucus->setLuksKoltukSayisi(yeniLuksKoltukSayisi);
                ucus2->setLuksKoltukSayisi(yeniLuksKoltukSayisi);  // kalkisYeriListesi'nde bulunan uçuþun lüks koltuk sayýsýný da güncelliyoruz
            
                cout << "Luks koltuk sayýsý güncellendi." << endl;
                cout << setw(15) << "Uçuþ Numarasý" << setw(20) << "Kalkýþ Yeri" << setw(20) << "Varýþ Yeri" << setw(25) << "Kalkýþ Zamaný" << setw(22) << "Normal Koltuk Sayýsý" << setw(20) << "Lüks Koltuk Sayýsý" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdir();
                break;
            }
            case 4: 
            {
                // Bir uçuþu iptal etmek için uçuþ numarasý alýnýyor
                int ucusNumarasi;

                cout << "Ýptal Edilecek Uçuþ Numarasýný girin: ";
                cin >> ucusNumarasi;

                // Uçuþu listelerden siliniyor
                ucusNumarasiListesi.sil(ucusNumarasi);
                kalkisYeriListesi.sil(ucusNumarasi);
                cout << "Uçuþ iptal edildi." << endl;
                cout << setw(15) << "Uçuþ Numarasý" << setw(20) << "Kalkýþ Yeri" << setw(20) << "Varýþ Yeri" << setw(25) << "Kalkýþ Zamaný" << setw(22) << "Normal Koltuk Sayýsý" << setw(20) << "Lüks Koltuk Sayýsý" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdir();
                break;
            }
            case 5: 
            {
                // Bir uçuþun bilgilerini görüntülemek için uçuþ numarasý alýnýyor
                int ucusNumarasi;

                cout << "Bilgilerini görmek istediðiniz Uçuþ Numarasýný girin: ";
                cin >> ucusNumarasi;

                // Uçuþ numarasýna göre ilgili uçuþ bulunuyor ve bilgileri gösteriliyor
                Ucus* ucus = ucusNumarasiListesi.ara(ucusNumarasi);
                if (ucus == nullptr) 
                {
                    cout << "Bu numaraya sahip bir uçuþ bulunamadý." << endl;
                    break;
                }
				cout << setw(15) << "Uçuþ Numarasý" << setw(20) << "Kalkýþ Yeri" << setw(20) << "Varýþ Yeri" << setw(25) << "Kalkýþ Zamaný" << setw(22) << "Normal Koltuk Sayýsý" << setw(20) << "Lüks Koltuk Sayýsý" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                cout << *ucus << endl;
                break;
            }
            case 6: 
            {
                // Lüks koltuk içeren uçuþlarý listelemek için ilgili fonksiyon çaðrýlýyor
                cout << setw(15) << "Uçuþ Numarasý" << setw(20) << "Kalkýþ Yeri" << setw(20) << "Varýþ Yeri" << setw(25) << "Kalkýþ Zamaný" << setw(22) << "Normal Koltuk Sayýsý" << setw(20) << "Lüks Koltuk Sayýsý" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdirLuksUcuslar();
                break;
            }
            case 7: 
            {
                // Varýþ yerine göre uçuþlarý listelemek için varýþ yeri alýnýyor
                string varisYeri;
                cout << "Varýþ yerini girin: ";
                cin >> varisYeri;
                if (varisYeri.length() > 20)
                {
                	cout << "Hata: Varýþ yeri uzunluðu en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(varisYeri.begin(), varisYeri.end(), varisYeri.begin(), ::toupper);
                cout << setw(15) << "Uçuþ Numarasý" << setw(20) << "Kalkýþ Yeri" << setw(20) << "Varýþ Yeri" << setw(25) << "Kalkýþ Zamaný" << setw(22) << "Normal Koltuk Sayýsý" << setw(20) << "Lüks Koltuk Sayýsý" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                kalkisYeriListesi.yazdirVarisYerineGore(varisYeri);
                break;
            }
            case 8: 
            {
                // Kalkýþ yerine göre uçuþlarý listelemek için kalkýþ yeri alýnýyor
                string kalkisYeri;

                cout << "Kalkýþ Yerini girin: ";
                cin >> kalkisYeri;
                if (kalkisYeri.length() > 20)
                {
                	cout << "Hata: Kalkýþ yeri uzunluðu en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(kalkisYeri.begin(), kalkisYeri.end(), kalkisYeri.begin(), ::toupper);
                // Kalkýþ yeri listelerinde ilgili uçuþlarý buluyoruz
                Ucus* ucus = kalkisYeriListesi.araKalkisYerineGore(kalkisYeri);
                if (ucus == nullptr) 
                {
                    cout << "Bu kalkýþ yerinden kalkan bir uçuþ bulunamadý." << endl;
                    break;
                }
                cout << "Bu kalkýþ yerinden kalkan uçuþlar:" << endl;
                
                cout << setw(15) << "Uçuþ Numarasý" << setw(20) << "Kalkýþ Yeri" << setw(20) << "Varýþ Yeri" << setw(25) << "Kalkýþ Zamaný" << setw(22) << "Normal Koltuk Sayýsý" << setw(20) << "Lüks Koltuk Sayýsý" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
				kalkisYeriListesi.yazdirKalkisYerineGore(kalkisYeri);
                break;
            }
            case 9: 
            {
                // Kalkýþ ve varýþ yerine göre uçuþlarý listelemek için bilgiler alýnýyor
                string kalkisYeri, varisYeri;

                cout << "Kalkýþ Yerini girin: ";
                cin >> kalkisYeri;
                if (kalkisYeri.length() > 20)
                {
                	cout << "Hata: Kalkýþ yeri uzunluðu en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(kalkisYeri.begin(), kalkisYeri.end(), kalkisYeri.begin(), ::toupper);
                cout << "Varýþ Yerini girin: ";
                cin >> varisYeri;
                if (varisYeri.length() > 20)
                {
                	cout << "Hata: Varýþ yeri uzunluðu en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(varisYeri.begin(), varisYeri.end(), varisYeri.begin(), ::toupper);
                cout << "Bu kalkýþ yerinden bu varýþ yerine olan uçuþlar:" << endl;
                // Ýlgili kalkýþ ve varýþ yerine göre uçuþlar listeleniyor
                cout << setw(15) << "Uçuþ Numarasý" << setw(20) << "Kalkýþ Yeri" << setw(20) << "Varýþ Yeri" << setw(25) << "Kalkýþ Zamaný" << setw(22) << "Normal Koltuk Sayýsý" << setw(20) << "Lüks Koltuk Sayýsý" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                kalkisYeriListesi.yazdirZamanYerineGore(kalkisYeri, varisYeri);
                break;
            }
            case 10: 
            {
                cout << "Çýkýþ yapýlýyor..." << endl;
                break;
            }
            default: 
            {
                cout << "Geçersiz seçim. Tekrar deneyin." << endl;
                break;
            }
        }
    }
}
