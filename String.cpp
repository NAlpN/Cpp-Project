#include "String.h"

using namespace std;

// String s�n�f�n�n varsay�lan yap�c� fonksiyonu.
String::String() : str_("") {
}

// String s�n�f�n�n parametreli yap�c� fonksiyonu.
String::String(const string& str) : str_(str) {
}

// Mevcut string'i d�nd�ren bir get fonksiyonu.
string String::getString() const {
    return str_;
}

// Mevcut string'i ayarlayan bir set fonksiyonu.
void String::setString(const string& str) {
    str_ = str;
}

// �ki String nesnesini kar��la�t�ran < operat�r�.
// Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
bool String::operator<(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 < str2;
}

// �ki String nesnesini kar��la�t�ran > operat�r�.
// Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
bool String::operator>(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 > str2;
}

// �ki String nesnesini kar��la�t�ran <= operat�r�.
// Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
bool String::operator<=(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 <= str2;
}

// �ki String nesnesini kar��la�t�ran >= operat�r�.
// Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
bool String::operator>=(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 >= str2;
}

// �ki String nesnesini kar��la�t�ran == operat�r�.
// Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
bool String::operator==(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 == str2;
}

// �ki String nesnesini kar��la�t�ran != operat�r�.
// Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
bool String::operator!=(const String& other) const {
    string str1 = str_;
    string str2 = other.str_;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 != str2;
}

// String nesnesini ��kt� ak�m�na yazd�ran bir << operat�r�.
ostream& operator<<(ostream& os, const String& str) {
    os << str.str_;
    return os;
}
