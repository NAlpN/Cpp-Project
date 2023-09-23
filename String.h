#ifndef STRING_H
#define STRING_H

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// String sýnýfý tanýmý
class String {
private:
    string str_;  // string veri üyesi

public:
    // Varsayýlan yapýcý fonksiyon
    String();

    // Parametreli yapýcý fonksiyon
    String(const string& str);

    // Mevcut string'i döndüren bir get fonksiyonu
    string getString() const;

    // Mevcut string'i ayarlayan bir set fonksiyonu
    void setString(const string& str);

    // Ýki String nesnesini karþýlaþtýran < operatörü.
    // Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
    bool operator<(const String& other) const;

    // Ýki String nesnesini karþýlaþtýran > operatörü.
    // Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
    bool operator>(const String& other) const;

    // Ýki String nesnesini karþýlaþtýran <= operatörü.
    // Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
    bool operator<=(const String& other) const;

    // Ýki String nesnesini karþýlaþtýran >= operatörü.
    // Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
    bool operator>=(const String& other) const;

    // Ýki String nesnesini karþýlaþtýran == operatörü.
    // Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
    bool operator==(const String& other) const;

    // Ýki String nesnesini karþýlaþtýran != operatörü.
    // Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
    bool operator!=(const String& other) const;

    // String nesnesini çýktý akýmýna yazdýran bir << operatörü.
    friend ostream& operator<<(ostream& os, const String& str);
};

#endif  // STRING_H

