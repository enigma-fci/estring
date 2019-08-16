#include "estring.h"



/********************
    constructors
********************/
estring::estring(): str(0) {}
estring::estring(const char str[]) : str(0) {
  // get the length of parameter str
  int l = 0;
  while(str[l] != '\0') l++;

  // free old memory
  delete[] this->str;
  this->str = 0;

  // allocate new memory space
  this->str = new char[l + 1];
  // copy every char to our str
  while(l >= 0) {
    this->str[l] = str[l];
    l--;
  }
}

/****************************************
    assignment operator overloading
*****************************************/
void estring::operator = (const char str[]) {
  // get the length of parameter str
  int l = 0;
  while(str[l] != '\0') l++;

  // free old memory
  delete[] this->str;
  this->str = 0;

  // allocate new memory space
  this->str = new char[l + 1];
  while(l >= 0) {
    this->str[l] = str[l];
    l--;
  }
}

void estring::operator = (const estring& str) {
  // get the length of parameter str
  int l = 0;
  while(str.str[l] != '\0') l++;

  // free old memory
  delete[] this->str;
  this->str = 0;

  // allocate new memory space
  this->str = new char[l + 1];
  // copy every char to our str
  while(l >= 0) {
    this->str[l] = str.str[l];
    l--;
  }
}

/***************************************
   array index operator overloading
****************************************/
char estring::operator[] (int index)  {
  // get the length
  int l = 0;
  while(str[l] != '\0') l++;

  if (index >= l)
      index = --l;
  return str[index];
}

/**************************************
    equality operator overloading
***************************************/
bool estring::operator == (const char str[]) {
  // get the length of parameter str
  int pl = 0;
  while(str[pl] != '\0') pl++;

  // get the length of object str
  int ol = 0;
  while(this->str[ol] != '\0') ol++;

  if(pl != ol) return false;
  // compare each char with it corresponded
  while(ol >= 0) {
    if(this->str[ol] != str[ol]) return false;
    ol--;
  }

  return true;
}

bool estring::operator == (const estring& str){
  // get the length of parameter str
  int pl = 0;
  while(str.str[pl] != '\0') pl++;
  // get the length of object str
  int ol = 0;
  while(this->str[ol] != '\0') ol++;

  if(pl != ol) return false;
  // compare each char with it corresponded
  while(ol >= 0) {
    if(this->str[ol] != str.str[ol]) return false;
    ol--;
  }

  return true;
}

bool operator == (const char str[], const estring& ob) {
  // get the length of parameter str
  int pl = 0;
  while(str[pl] != '\0') pl++;
  // get the length of object str
  int ol = 0;
  while(ob.str[ol] != '\0') ol++;

  if(pl != ol) return false;
  // compare each char with it correspondence
  while(ol >= 0) {
    if(ob.str[ol] != str[ol]) return false;
    ol--;
  }

  return true;
}



/***********************
    e_erase method
************************/
estring estring::e_erase(int start_i, int end_i) {
  // get the length
  int l = 0;
  while(str[l] != 0) l++;

  // check some condition
  if(start_i < 0 || end_i < 0) return this->str;
  if(start_i >= end_i || end_i >= l) return this->str;

  // copy str and reallocate memory
  char *t = str;
  str = new char[l - (end_i - start_i)];

  // copy t in str without letters between start and end index
  for(int i = 0, j = 0; j <= l; i++, j++)
    (j < start_i || j > end_i)?
      str[i] = t[j] : i--;

  // free t memory
  delete [] t;

  return this->str;
}

/**************************
    cout << overloading
***************************/
ostream & operator << (ostream &out, const estring &str) {
  out << str.str;
  return out;
}

/*************************
    cin >> overloading
**************************/
istream & operator >> (istream &in, estring &str) {
  char t[100];
  in.getline(t, 100);

  // get the length of t
  int l = 0;
  while(t[l] != '\0') l++;

  // free old memory
  delete [] str.str;
  str.str = 0;

  // allocate new memory space
  str.str = new char[l + 1];
  // copy every char to our str
  for(;l >= 0; l--)
    str.str[l] = t[l];

  return in;
}

estring::~estring() {
  // free old memory
  delete [] str;
  str = 0;
}
