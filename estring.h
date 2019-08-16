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
    char operator[] (int index);

    // equality operator overloading
    bool operator == (const char str[]);
    bool operator == (const estring& str);
    friend bool operator == (const char str[],const estring& ob);
    
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
