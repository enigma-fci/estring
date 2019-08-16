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

/**************************************
    plus equal operator overloading
***************************************/
void estring::operator += (const char str[]) {
  // get length of my str
  int ol = 0;
  while(this->str[ol] != '\0') ol++;

  // get the length of parameter str
  int pl = 0;
  while(str[pl] != '\0') pl++;

  // copy my str in temp variable
  char *t = this->str;

  // get the total length
  int total_len = ol + pl;

  // reallocate my str
  this->str = new char[total_len + 1];

  // copy char from temp to new space
  for(int i = 0; i < ol; i++)
    this->str[i] = t[i];

  // copy char from parameter str to new space
  for(int i = ol, j = 0; i <= total_len; i++, j++)
    this->str[i] = str[j];

  // free t memory
  delete[] t;
}

void estring::operator += (const estring& str) {
  // get length of my str
  int ol = 0;
  while(this->str[ol] != '\0') ol++;

  // get the length of parameter str
  int pl = 0;
  while(str.str[pl] != '\0') pl++;

  // copy my str in temp variable
  char *t =  this->str;

  // get the total length
  int total_len = ol + pl;

  // reallocate my str
  this->str = new char[total_len + 1];

  // copy char from temp to new space
  for(int i = 0; i < ol; i++)
    this->str[i] = t[i];

  // copy char from parameter str to new space
  for(int i = ol, j = 0; i <= total_len; i++, j++)
    this->str[i] = str.str[j];

  // free t memory
  delete[] t;
}

/**************************
     e_includes method
***************************/
bool estring::e_includes(const char str[]) {
  // get index number
  int ol = 0;
  while(this->str[ol] != '\0') ol++;
  ol--;

  // get index number
  int pl = 0;
  while(str[pl] != '\0') pl++;          // remove null char index to
  pl--;                                 // compare letters only

  // matching for one char
  if(!pl) {
    for(int i = 0; i <= ol; i++)
      if(this->str[i] == str[0])
        return true;
    return false;
  }

  // matching for array of char
  for(int i = 0; i <= ol - pl; i++)
    if(this->str[i] == str[0])
      for(int j = 1; j <= pl; j++)
        if(this->str[i + j] != str[j])
          break;
        else if(j == pl)
          return true;

  return false;
}

bool estring::e_includes(const estring& str) {
  // get index number
  int ol = 0;
  while(this->str[ol] != '\0') ol++;
  ol--;

  // get index number
  int pl = 0;
  while(str.str[pl] != '\0') pl++;        // remove null char index to
  pl--;                                   // compare letters only

  // matching for one char
  if(!pl) {
    for(int i = 0; i <= ol; i++)
      if(this->str[i] == str.str[0])
        return true;
    return false;
  }

  // matching for array of char
  for(int i = 0; i <= ol - pl; i++)
    if(this->str[i] == str.str[0])
      for(int j = 1; j <= pl; j++)
        if(this->str[i + j] != str.str[j])
          break;
        else if(j == pl)
          return true;

  return false;
}

/************************
     endsWith method
*************************/
bool estring::endsWith(const char str[], int index) {
  // get index number
  int ol = 0;
  while(this->str[ol] != '\0') ol++;
  ol--;

  if(index > 0 && index < ol) ol = index;

  // get index number
  int pl = 0;
  while(str[pl] != '\0') pl++;
  pl--;

  if(pl > ol) return false;

  for(int i = ol - pl, j = 0; i <= ol; i++, j++)
    if(this->str[i] != str[j])
      return false;

  return true;
}

bool estring::endsWith(const estring& str, int index) {
  // get index number
  int ol = 0;
  while(this->str[ol] != '\0') ol++;
  ol--;

  if(index > 0 && index < ol) ol = index;

  // get index number
  int pl = 0;
  while(str.str[pl] != '\0') pl++;
  pl--;

  if(pl > ol) return false;

  for(int i = ol - pl, j = 0; i <= ol; i++, j++)
    if(this->str[i] != str.str[j])
      return false;

  return true;
}

/***********************
    pad end method
************************/
estring estring::padEnd(int len, const char str[]) {
  // get the length of my str
  int ol = 0;
  while(this->str[ol] != '\0') ol++;

  if (ol >= len) return this->str;

  // get the length of parameter str
  int pl = 0;
  while(str[pl] != '\0') pl++;

  char *t = this->str;
  this->str = new char[len + 1]; // for null char

  // add original string at first
  for(int i = 0; i < ol; i++)
    this->str[i] = t[i];

  // add the parameter str add the end and repeat it until the end
  for(int i = ol, j = 0; i < len; i++, j++, j %= pl)
    this->str[i] = str[j];

  // finally add null char
  this->str[len] = '\0';

  // free t memory
  delete [] t;

  return this->str;
}

estring estring::padEnd(int len, const estring& str) {
    // get the length of my str
  int ol = 0;
  while(this->str[ol] != '\0') ol++;

  if (ol >= len) return this->str;

  // get the length of parameter str
  int pl = 0;
  while(str.str[pl] != '\0') pl++;

  char *t = this->str;
  this->str = new char[len + 1]; // for null char

  // add original string at first
  for(int i = 0; i < ol; i++)
    this->str[i] = t[i];

  // add the str and repeat until the end
  for(int i = ol, j = 0; i < len; i++, j++, j %= pl)
    this->str[i] = str.str[j];

  // add null char
  this->str[len] = '\0';

  // free t memory
  delete [] t;

  return this->str;
}

/*************************
    trim right method
**************************/
// working functionality  good for memory
estring estring::trimRight(void){
  // get index number
  int l = 0;
  while(str[l] != '\0') l++;
  l--;

  for(;l >= 0 && str[l] == ' '; l--)
    str[l] = '\0';

  char *t = str;
  str = new char[l + 2]; // for null char and convert from index to length

  for(int i = 0; i <= l; i++)
    str[i] = t[i];

  str[l + 1] = '\0';

  // free t memory
  delete [] t;

  return str;
}

/*************************
     e_reverse method
**************************/
estring estring::e_reverse(void) {
  // get index number
  int l = 0;
  while(str[l] != '\0') l++;
  l--;

  char t;
  // loop and swap each char in the first half whit it correspondence
  for(int i = 0; i <= l / 2; i++) {
    // simple swap
    t = str[i];     // store char at index i in temp variable
    str[i] = str[l - i];  // set correspondence char at index l - i to index i
    str[l - i] = t;   // set char at index l - i  to temp;
  }
  return this->str;
}

/***************************
    to lower case method
****************************/
estring estring::toLoweCase (void) {
  for(int i = 0; str[i] != '\0'; i++)    // for each char
    if(str[i] >= 'A' && str[i] <= 'Z')   // if it was capital
      str[i] += 32; // convert it to small

  return this->str;
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

int estring::length()
{
	int length;
	for (length = 0; str[length] != '\0'; length++);
	return length;
}

char estring::charAt(int x)
{

	return str[x];
}

int estring::charCodeAt(int x) {
	return str[x];
}

int estring::indexOf(estring e, int x)
{
	// get length of the new string
	int le, lo = this->length();
	bool test;
	for (le = 0; e.str[le] != '\0'; le++);
	for (int i = x; i < lo; i++) {
		test = true;
		for (int j = 0; j < le; j++) {
			if (this->str[i + j] != e.str[j]) {
				test = false;
				break;
			}
		}
		if (test) return i;
	}
	return -1;
}

int estring::lastIndexOf(estring e, int x)
{
	int le, lo = this->length();
	bool test;
	for (le = 0; e.str[le] != '\0'; le++);
	for (int i = lo - 1; i >= x; i--) {
		test = true;
		for (int j = le - 1; j >= 0; j--) {
			if (this->str[i - j] != e.str[j]) {
				test = false;
				break;
			}
		}
		if (test) return i;
	}
	return -1;
}

estring estring::trim()
{
	int l = this->length(), lss = 0, lse = 0;
	char* temp = this->str;
	for (int i = 0; i < l; i++)
		if (str[i] == ' ')
			lss++;
		else
			break;
	for (int i = l - 1; i >= 0; i--)
		if (str[i] == ' ')
			lse++;
		else
			break;
	this->str = new char[l - (lss + lse)];
	for (int i = lss, j = 0; i < l- lse; i++, j++)
		this->str[j] = temp[i];
	this->str[l - (lss + lse)] = '\0';
	delete[] temp;
	return this->str;
}

estring estring::padStart(int x, estring e)
{
	for (int i = 0; i < x; i++) {
		str--;
		str[0] = e.str[0];
	}
	return this->str;
}

estring estring::toUpperCase()
{
	int l = length();
	for (int i = 0; i < l; i++)
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
	return str;
}

int estring::count(estring e)
{
	int count = 0, le = e.length(), lo = this->length();
	bool test;
	for (int i = 0; i < lo; i++) {
		test = true;
		for (int j = 0; j < le; j++) {
			if (this->str[i + j] != e.str[j]) {
				test = false;
				break;
			}
		}
		if (test) count++;
	}
	return count;

}

bool estring::operator!=(estring e)
{
	int lo = this->length(), le = e.length();

	if (lo != le) return true;
	// compare each char with it corresponded
	while (lo >= 0) {
		if (this->str[lo] != e.str[lo]) return true;
		lo--;
	}

	return false;
}

estring estring::erase(int x, int y)
{
	int l = this->length();
	if (x < 0 || x > y || y > l) return "Error";
	char* temp = this->str;
	this->str = new char[l - (y - x)];
	for (int i = 0, j = 0; i <= l; i++, j++)
		if (j < x || j > y)
			str[i] = temp[j];
		else
			i--;
	delete[] temp;
	return this->str;
}

estring estring::slice(int x, int y)
{
	if (y == 0) 
		y = length();
	if (x > y || (x < 0 && y != length()) || y > length())
		return "Error";
	char* temp;
	if (x < 0) {
		temp = new char[-x + 1];
		for (int i = 0, j = x; y + j < y; i++, j++)
			temp[i] = str[y + j];
		temp[-x] = '\0';
	}
	else {
		temp = new char[y - x + 1];
		for (int i = 0, j = x; j <= y; i++, j++)
			temp[i] = str[j];
		temp[y - x + 1] = '\0';
	}
	return temp;
}


estring::~estring() {
  // free old memory
  delete [] str;
  str = 0;
}
