#ifndef ESTRING_H
#define ESTRING_H

#include <iostream>

using namespace std;

class estring
{
  private:
    char *str;
  public:
    // constructors
    estring();
    estring(const char str[]);

    // assignment operator overloading
    void operator = (const char str[]);
    void operator = (const estring& str);

    // array index operator overloading
    char& operator[] (int index);

    // equality operator overloading
    bool operator == (const char str[]);
    bool operator == (const estring& str);
    friend bool operator == (const char str[],const estring& ob);

    // plus equal operator overloading
    void operator += (const char str[]);
    void operator += (const estring& str);

    // e_includes method
    bool e_includes(const char str[]);
    bool e_includes(const estring& str);

    // endsWith method
    bool endsWith(const char str[], int index = 0);
    bool endsWith(const estring& str, int index = 0);

    // pad end method
    estring padEnd(int len, const char str[] = " ");
    estring padEnd(int len, const estring& str);

    estring trimRight(void);   // trim Right method
    estring e_reverse(void);   // e_reverse method
    estring toLoweCase(void);  // to lower case method
    estring e_erase(int start_i, int end_i); // erase method

    // cin >> & cout << overloading
    friend ostream & operator << (ostream &out, const estring &str);
    friend istream & operator >> (istream &in,  estring &str);

    int length();
		char charAt(int x);
		int charCodeAt(int x);
  	int indexOf(estring e, int x = 0);
  	int lastIndexOf(estring e, int x = 0);
  	estring trim();
  	estring padStart(int x, estring e = " ");
  	estring toUpperCase();
  	int count(estring e);
  	bool operator!=(estring e);
  	estring erase(int x, int y);
  	estring slice(int x, int y);

    ~estring();
};

#endif // ESTRING_H
