#ifndef ESTRING_H
#define ESTRING_H

#include <iostream>

class estring
{
  private:
    char *str;

    int power(int base, int p);

  public:
    // constructors
    estring();
    estring(const char str[]);
    estring(const estring& str);

    /***************************
        operator overloading
    ****************************/
      // assignment
    void operator = (const char str[]);
    void operator = (const estring& str);
      // array index
    char& operator[] (int index);
      // plus
    estring operator + (const char str[]);
    estring operator + (const estring& str);
    friend estring operator + (const char str[], const estring& obstr);
      // plus equal
    void operator += (const char str[]);
    void operator += (const estring& str);
      // equality
    bool operator == (const char str[]);
    bool operator == (const estring& str);
    friend bool operator == (const char str[],const estring& ob);
      // not equal
    bool operator!=(const estring& e);
      // cin >> & cout <<
    friend std::ostream & operator << (std::ostream &out, const estring &str);
    friend std::istream & operator >> (std::istream &in,  estring &str);


    /*********************
          Query method
    **********************/
    int length() const;//-------------------------------------> length method
		int indexOf(const estring& e, int x = 0) const;//---------> index of method
  	int lastIndexOf(const estring& e, int x = 0) const;//-----> last index of method
  	int count(const estring& e) const;//----------------------> count method
    int charCodeAt(int x) const;//----------------------------> char code at method
		char charAt(int x) const;//-------------------------------> char at method
    bool includes(const char str[]) const;//------------------> includes method
    bool includes(const estring& str) const;//----------------> includes method
    bool endsWith(const char str[], int index = 0) const;//---> ends with method
    bool endsWith(const estring& str, int index = 0) const;//-> ends with method

  	/************************
          modify method
    *************************/
    estring& padStart(int len, const estring& e = " ");//> pad start method
    estring& padEnd(int len, const char str[] = " ");//--> pad end method
    estring& padEnd(int len, const estring& str);//------> pad end method
    estring& trim();//-----------------------------------> trim method
    estring& trimRight(void);//--------------------------> trim Right method
    estring& toLoweCase(void);//-------------------------> to lower case method
  	estring& toUpperCase();//----------------------------> to upper case method
   	estring slice(int x, int y = 0);//-------------------> slice method
    estring substring (int start_i, int end_i = -1);//---> substring method
   	estring repeat(int times);//-------------------------> repeat method
    estring& reverse(void);//----------------------------> reverse method
  	estring& erase(int start_i, int end_i);//------------> erase method
    estring& replace(const estring& e1, const estring& e2);//replace method

    static estring toString(int x, int y = 10);

    ~estring();
};




#endif // ESTRING_H
