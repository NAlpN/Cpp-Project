#ifndef STRING_H
#define STRING_H

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// String s�n�f� tan�m�
class String {
private:
    string str_;  // string veri �yesi

public:
    // Varsay�lan yap�c� fonksiyon
    String();

    // Parametreli yap�c� fonksiyon
    String(const string& str);

    // Mevcut string'i d�nd�ren bir get fonksiyonu
    string getString() const;

    // Mevcut string'i ayarlayan bir set fonksiyonu
    void setString(const string& str);

    // �ki String nesnesini kar��la�t�ran < operat�r�.
    // Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
    bool operator<(const String& other) const;

    // �ki String nesnesini kar��la�t�ran > operat�r�.
    // Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
    bool operator>(const String& other) const;

    // �ki String nesnesini kar��la�t�ran <= operat�r�.
    // Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
    bool operator<=(const String& other) const;

    // �ki String nesnesini kar��la�t�ran >= operat�r�.
    // Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
    bool operator>=(const String& other) const;

    // �ki String nesnesini kar��la�t�ran == operat�r�.
    // Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
    bool operator==(const String& other) const;

    // �ki String nesnesini kar��la�t�ran != operat�r�.
    // Kar��la�t�rma, b�y�k-k���k harf duyarl�l��� olmadan yap�l�r.
    bool operator!=(const String& other) const;

    // String nesnesini ��kt� ak�m�na yazd�ran bir << operat�r�.
    friend ostream& operator<<(ostream& os, const String& str);
};

#endif  // STRING_H

