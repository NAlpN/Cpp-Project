#include "String.h"

using namespace std;

// String sýnýfýnýn varsayýlan yapýcý fonksiyonu.
String::String() : str_("") {
}

// String sýnýfýnýn parametreli yapýcý fonksiyonu.
String::String(const string& str) : str_(str) {
}

// Mevcut string'i döndüren bir get fonksiyonu.
string String::getString() const {
    return str_;
}

// Mevcut string'i ayarlayan bir set fonksiyonu.
void String::setString(const string& str) {
    str_ = str;
}

// Ýki String nesnesini karþýlaþtýran < operatörü.
// Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
bool String::operator<(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 < str2;
}

// Ýki String nesnesini karþýlaþtýran > operatörü.
// Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
bool String::operator>(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 > str2;
}

// Ýki String nesnesini karþýlaþtýran <= operatörü.
// Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
bool String::operator<=(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 <= str2;
}

// Ýki String nesnesini karþýlaþtýran >= operatörü.
// Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
bool String::operator>=(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 >= str2;
}

// Ýki String nesnesini karþýlaþtýran == operatörü.
// Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
bool String::operator==(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 == str2;
}

// Ýki String nesnesini karþýlaþtýran != operatörü.
// Karþýlaþtýrma, büyük-küçük harf duyarlýlýðý olmadan yapýlýr.
bool String::operator!=(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 != str2;
}

// String nesnesini çýktý akýmýna yazdýran bir << operatörü.
ostream& operator<<(ostream& os, const String& str) {
    os << str.str_;
    return os;
}
