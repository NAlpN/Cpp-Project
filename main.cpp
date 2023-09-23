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
    // U�u� listeleri olu�turuluyor
    UcusNumarasina_Gore_Ucus_Listesi ucusNumarasiListesi;
    Kalkis_Yerine_Gore_Ucus_Listesi kalkisYeriListesi;

    setlocale(LC_ALL, "Turkish"); 
    int secim = 0;
    while (secim != 10) 
    {
        // Men� se�enekleri g�steriliyor
        cout << "----------- MENU -----------" << endl;
        cout << "1. L�ks koltuk i�ermeyen yeni bir u�u� ekle" << endl;
        cout << "2. L�ks koltuk i�eren yeni bir u�u� ekle" << endl;
        cout << "3. Bir u�u�un l�ks koltuk say�s�n� g�ncelle" << endl;
        cout << "4. Bir u�u�u iptal et" << endl;
        cout << "5. Bir u�u�un bilgilerini g�r�nt�le" << endl;
        cout << "6. L�ks koltuk i�eren u�u�lar� listele" << endl;
        cout << "7. Var�� yerine g�re u�u�lar� listele" << endl;
        cout << "8. Kalk�� yerine g�re u�u�lar� listele" << endl;
        cout << "9. Kalk�� ve var�� yerine g�re u�u�lar� listele" << endl;
        cout << "10. ��k��" << endl;
        cout << "Yapmak istedi�iniz i�lemi giriniz: ";
        cin >> secim;
        
        switch (secim) 
        {
            case 1: 
            {
                // L�ks koltuk i�ermeyen yeni bir u�u� eklemek i�in gereken bilgiler al�n�yor
                int ucusNumarasi, normalKoltukSayisi;
                string kalkisYeri, varisYeri, kalkisZamani;

                cout << "U�u� Numaras� giriniz: ";
                cin >> ucusNumarasi;

                // U�u� numaras� daha �nceden mevcutsa hata mesaj� veriliyor
                if (ucusNumarasiListesi.ara(ucusNumarasi) != nullptr) 
                {
                    cout << "Bu numaraya sahip bir u�u� zaten mevcut." << endl;
                    break;
                }
                cout << "Kalk�� Yerini girin: ";
                cin  >> kalkisYeri;
                if (kalkisYeri.length() > 20)
                {
                	cout << "Hata: Kalk�� yeri uzunlu�u en fazla 20 karakter olabilir." << endl;
                	break;
				}
                transform(kalkisYeri.begin(), kalkisYeri.end(), kalkisYeri.begin(), ::toupper);
				cout << "Var�� Yerini girin: ";
                cin  >> varisYeri;
                if (varisYeri.length() > 20)
                {
                	cout << "Hata: Var�� yeri uzunlu�u en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(varisYeri.begin(), varisYeri.end(), varisYeri.begin(), ::toupper);
				cout << "Kalk�� Zaman�n� girin: ";
                cin  >> kalkisZamani;
                if (kalkisZamani.length() > 5 || stoi(kalkisZamani) < 0 || stoi(kalkisZamani) > 23)
                {
                	cout << "Hata: Kalk�� zaman� uzunlu�u en fazla 5 karakter olabilir ve Kalk�� saati 24 saat dilimine g�re 00-23 aras�nda olabilir." << endl;
                	break;
				}
				cout << "Normal Koltuk Say�s�n� girin: ";
                cin >> normalKoltukSayisi;

                // U�u� listelerine l�ks koltuk i�ermeyen u�u�u ekliyoruz
                ucusNumarasiListesi.ekleLukssuz(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi);
                kalkisYeriListesi.ekleLukssuz(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi);
                cout << "U�u� eklendi." << endl;
                cout << setw(15) << "U�u� Numaras�" << setw(20) << "Kalk�� Yeri" << setw(20) << "Var�� Yeri" << setw(25) << "Kalk�� Zaman�" << setw(22) << "Normal Koltuk Say�s�" << setw(20) << "L�ks Koltuk Say�s�" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdir();
                break;
            }
            case 2: 
            {
                // L�ks koltuk i�eren yeni bir u�u� eklemek i�in gereken bilgiler al�n�yor
                int ucusNumarasi, normalKoltukSayisi, luksKoltukSayisi;
                string kalkisYeri, varisYeri, kalkisZamani;
                cout << "U�u� Numaras�n� girin: ";
                cin >> ucusNumarasi;

                // U�u� numaras� daha �nceden mevcutsa hata mesaj� veriliyor
                if (ucusNumarasiListesi.ara(ucusNumarasi) != nullptr) 
                {
                    cout << "Bu numaraya sahip bir u�u� zaten mevcut." << endl;
                    break;
                }

                cout << "Kalk�� Yerini girin: ";
                cin >> kalkisYeri;
                if (kalkisYeri.length() > 20)
                {
                	cout << "Hata: Kalk�� yeri uzunlu�u en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(kalkisYeri.begin(), kalkisYeri.end(), kalkisYeri.begin(), ::toupper);
                cout << "Var�� Yerini girin: ";
                cin >> varisYeri;
                if (varisYeri.length() > 20)
                {
                	cout << "Hata: Var�� yeri uzunlu�u en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(varisYeri.begin(), varisYeri.end(), varisYeri.begin(), ::toupper);
				cout << "Kalk�� Zaman�n� girin: ";
                cin >> kalkisZamani;
                if (kalkisZamani.length() > 5 || stoi(kalkisZamani) < 0 || stoi(kalkisZamani) > 23)
                {
                	cout << "Hata: Kalk�� zaman� uzunlu�u en fazla 5 karakter olabilir ve Kalk�� saati 24 saat dilimine g�re 00-23 aras�nda olabilir." << endl;
                	break;
				}
				cout << "Normal Koltuk Say�s�n� girin: ";
                cin >> normalKoltukSayisi;
                cout << "Luks Koltuk Say�s�n� girin: ";
                cin >> luksKoltukSayisi;

                // U�u� listelerine l�ks koltuk i�eren u�u�u ekliyoruz
                ucusNumarasiListesi.ekleLuks(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
                kalkisYeriListesi.ekleLuks(ucusNumarasi, kalkisYeri, varisYeri, kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
                cout << "U�u� eklendi." << endl;
                cout << setw(15) << "U�u� Numaras�" << setw(20) << "Kalk�� Yeri" << setw(20) << "Var�� Yeri" << setw(25) << "Kalk�� Zaman�" << setw(22) << "Normal Koltuk Say�s�" << setw(20) << "L�ks Koltuk Say�s�" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdir();
                break;
            }
            case 3: 
            {
                // Bir u�u�un l�ks koltuk say�s�n� g�ncellemek i�in gereken bilgiler al�n�yor
                int ucusNumarasi, yeniLuksKoltukSayisi;
            
                cout << "G�ncellenecek U�u� Numaras�n� girin: ";
                cin >> ucusNumarasi;
            
                // U�u� numaras� mevcut de�ilse hata mesaj� veriliyor
                Ucus* ucus = ucusNumarasiListesi.ara(ucusNumarasi);
                Ucus* ucus2 = kalkisYeriListesi.araUcusNumarasinaGore(ucusNumarasi);  // ayn� u�u� numaras�n� kalkisYeriListesi'nde de ar�yoruz
            
                if (ucus == nullptr || ucus2 == nullptr) 
                {
                    cout << "Bu numaraya sahip bir u�u� bulunamad�." << endl;
                    break;
                }
            
                cout << "Yeni Luks Koltuk Say�s�n� girin: ";
                cin >> yeniLuksKoltukSayisi;
            
                // U�u�un l�ks koltuk say�s�n� g�ncelliyoruz
                ucus->setLuksKoltukSayisi(yeniLuksKoltukSayisi);
                ucus2->setLuksKoltukSayisi(yeniLuksKoltukSayisi);  // kalkisYeriListesi'nde bulunan u�u�un l�ks koltuk say�s�n� da g�ncelliyoruz
            
                cout << "Luks koltuk say�s� g�ncellendi." << endl;
                cout << setw(15) << "U�u� Numaras�" << setw(20) << "Kalk�� Yeri" << setw(20) << "Var�� Yeri" << setw(25) << "Kalk�� Zaman�" << setw(22) << "Normal Koltuk Say�s�" << setw(20) << "L�ks Koltuk Say�s�" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdir();
                break;
            }
            case 4: 
            {
                // Bir u�u�u iptal etmek i�in u�u� numaras� al�n�yor
                int ucusNumarasi;

                cout << "�ptal Edilecek U�u� Numaras�n� girin: ";
                cin >> ucusNumarasi;

                // U�u�u listelerden siliniyor
                ucusNumarasiListesi.sil(ucusNumarasi);
                kalkisYeriListesi.sil(ucusNumarasi);
                cout << "U�u� iptal edildi." << endl;
                cout << setw(15) << "U�u� Numaras�" << setw(20) << "Kalk�� Yeri" << setw(20) << "Var�� Yeri" << setw(25) << "Kalk�� Zaman�" << setw(22) << "Normal Koltuk Say�s�" << setw(20) << "L�ks Koltuk Say�s�" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdir();
                break;
            }
            case 5: 
            {
                // Bir u�u�un bilgilerini g�r�nt�lemek i�in u�u� numaras� al�n�yor
                int ucusNumarasi;

                cout << "Bilgilerini g�rmek istedi�iniz U�u� Numaras�n� girin: ";
                cin >> ucusNumarasi;

                // U�u� numaras�na g�re ilgili u�u� bulunuyor ve bilgileri g�steriliyor
                Ucus* ucus = ucusNumarasiListesi.ara(ucusNumarasi);
                if (ucus == nullptr) 
                {
                    cout << "Bu numaraya sahip bir u�u� bulunamad�." << endl;
                    break;
                }
				cout << setw(15) << "U�u� Numaras�" << setw(20) << "Kalk�� Yeri" << setw(20) << "Var�� Yeri" << setw(25) << "Kalk�� Zaman�" << setw(22) << "Normal Koltuk Say�s�" << setw(20) << "L�ks Koltuk Say�s�" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                cout << *ucus << endl;
                break;
            }
            case 6: 
            {
                // L�ks koltuk i�eren u�u�lar� listelemek i�in ilgili fonksiyon �a�r�l�yor
                cout << setw(15) << "U�u� Numaras�" << setw(20) << "Kalk�� Yeri" << setw(20) << "Var�� Yeri" << setw(25) << "Kalk�� Zaman�" << setw(22) << "Normal Koltuk Say�s�" << setw(20) << "L�ks Koltuk Say�s�" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                ucusNumarasiListesi.yazdirLuksUcuslar();
                break;
            }
            case 7: 
            {
                // Var�� yerine g�re u�u�lar� listelemek i�in var�� yeri al�n�yor
                string varisYeri;
                cout << "Var�� yerini girin: ";
                cin >> varisYeri;
                if (varisYeri.length() > 20)
                {
                	cout << "Hata: Var�� yeri uzunlu�u en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(varisYeri.begin(), varisYeri.end(), varisYeri.begin(), ::toupper);
                cout << setw(15) << "U�u� Numaras�" << setw(20) << "Kalk�� Yeri" << setw(20) << "Var�� Yeri" << setw(25) << "Kalk�� Zaman�" << setw(22) << "Normal Koltuk Say�s�" << setw(20) << "L�ks Koltuk Say�s�" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                kalkisYeriListesi.yazdirVarisYerineGore(varisYeri);
                break;
            }
            case 8: 
            {
                // Kalk�� yerine g�re u�u�lar� listelemek i�in kalk�� yeri al�n�yor
                string kalkisYeri;

                cout << "Kalk�� Yerini girin: ";
                cin >> kalkisYeri;
                if (kalkisYeri.length() > 20)
                {
                	cout << "Hata: Kalk�� yeri uzunlu�u en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(kalkisYeri.begin(), kalkisYeri.end(), kalkisYeri.begin(), ::toupper);
                // Kalk�� yeri listelerinde ilgili u�u�lar� buluyoruz
                Ucus* ucus = kalkisYeriListesi.araKalkisYerineGore(kalkisYeri);
                if (ucus == nullptr) 
                {
                    cout << "Bu kalk�� yerinden kalkan bir u�u� bulunamad�." << endl;
                    break;
                }
                cout << "Bu kalk�� yerinden kalkan u�u�lar:" << endl;
                
                cout << setw(15) << "U�u� Numaras�" << setw(20) << "Kalk�� Yeri" << setw(20) << "Var�� Yeri" << setw(25) << "Kalk�� Zaman�" << setw(22) << "Normal Koltuk Say�s�" << setw(20) << "L�ks Koltuk Say�s�" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
				kalkisYeriListesi.yazdirKalkisYerineGore(kalkisYeri);
                break;
            }
            case 9: 
            {
                // Kalk�� ve var�� yerine g�re u�u�lar� listelemek i�in bilgiler al�n�yor
                string kalkisYeri, varisYeri;

                cout << "Kalk�� Yerini girin: ";
                cin >> kalkisYeri;
                if (kalkisYeri.length() > 20)
                {
                	cout << "Hata: Kalk�� yeri uzunlu�u en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(kalkisYeri.begin(), kalkisYeri.end(), kalkisYeri.begin(), ::toupper);
                cout << "Var�� Yerini girin: ";
                cin >> varisYeri;
                if (varisYeri.length() > 20)
                {
                	cout << "Hata: Var�� yeri uzunlu�u en fazla 20 karakter olabilir." << endl;
                	break;
				}
				transform(varisYeri.begin(), varisYeri.end(), varisYeri.begin(), ::toupper);
                cout << "Bu kalk�� yerinden bu var�� yerine olan u�u�lar:" << endl;
                // �lgili kalk�� ve var�� yerine g�re u�u�lar listeleniyor
                cout << setw(15) << "U�u� Numaras�" << setw(20) << "Kalk�� Yeri" << setw(20) << "Var�� Yeri" << setw(25) << "Kalk�� Zaman�" << setw(22) << "Normal Koltuk Say�s�" << setw(20) << "L�ks Koltuk Say�s�" << endl;
				cout << setw(15) << "------------" << setw(20) << "-----------" << setw(20) << "----------" << setw(25) << "-------------" << setw(22) << "-------------------" << setw(20) << "-----------------" << endl;
                kalkisYeriListesi.yazdirZamanYerineGore(kalkisYeri, varisYeri);
                break;
            }
            case 10: 
            {
                cout << "��k�� yap�l�yor..." << endl;
                break;
            }
            default: 
            {
                cout << "Ge�ersiz se�im. Tekrar deneyin." << endl;
                break;
            }
        }
    }
}
