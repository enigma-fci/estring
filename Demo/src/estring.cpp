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
  for(;l >= 0; l--)
    this->str[l] = str[l];
}
estring::estring(const estring& str) : str(0) {
  // get the length of parameter str
  int l = str.length();

  // free old memory
  delete[] this->str;
  this->str = 0;

  // allocate new memory space
  this->str = new char[l + 1];
  // copy every char to our str
  for(;l >= 0; l--)
    this->str[l] = str.str[l];
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

  // copy every char to this str
  for(;l >= 0; l--)
    this->str[l] = str[l];
}

void estring::operator = (const estring& str) {
  // get the length of parameter str
  int l = str.length();

  // free old memory
  delete[] this->str;
  this->str = 0;

  // allocate new memory space
  this->str = new char[l + 1];

  // copy every char to this str
  for(;l >= 0; l--)
    this->str[l] = str.str[l];
}

/***************************************
   array index operator overloading
****************************************/
char& estring::operator[] (int index)  {return str[index];}

/**************************************
    plus equal operator overloading
***************************************/
void estring::operator += (const char str[]) {
  // get length of my str
  int ol = this->length();

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
  int ol = this->length();

  // get the length of parameter str
  int pl = str.length();

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

/**************************************
    equality operator overloading
***************************************/
bool estring::operator == (const char str[]) {
  // get the length of parameter str
  int pl = 0;
  while(str[pl] != '\0') pl++;

  // get the length of object str
  int ol = this->length();

  if(pl != ol) return false;
  // compare each char with it corresponded
  for(;ol >= 0; ol--)
    if(this->str[ol] != str[ol]) return false;

  return true;
}

bool estring::operator == (const estring& str){
  int pl = str.length();   // get the length of parameter str
  int ol = this->length(); // get the length of object str

  if(pl != ol) return false;
  // compare each char with it corresponded
  for(;ol >= 0; ol--)
    if(this->str[ol] != str.str[ol]) return false;

  return true;
}

bool operator == (const char str[], const estring& ob) {
  // get the length of parameter str
  int pl = 0;
  while(str[pl] != '\0') pl++;
  // get the length of object str
  int ol = ob.length();

  if(pl != ol) return false;
  // compare each char with it correspondence
  for(;ol >= 0; ol--)
    if(ob.str[ol] != str[ol]) return false;

  return true;
}

/**************************************
    not equal operator overloading
***************************************/
bool estring::operator!= (const estring& e) {
  // get the length of this str and e str
	int lo = this->length(), le = e.length();

	if (lo != le) return true;

	// compare each char with it corresponded
	for(;lo >= 0; lo--)
		if (this->str[lo] != e.str[lo]) return true; // any char doesn't match return true

	return false;
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

/*************************
      length method
**************************/
int estring::length() const {
	int length;
	for (length = 0; str[length] != '\0'; length++);
	return length;
}

/*************************
      index of method
**************************/
int estring::indexOf(const estring& e, int x) const {
	// get length of parameter str and this str
	int le = e.length(), lo = this->length();

  // validate some conditions
	if(x < 0 || x >= lo || le > lo) return -1;

	bool found;

	for (int i = x; i < lo; i++, found = true) { // for each char
		for (int j = 0; j < le; j++)  // matching for e string
      if (! (found = this->str[i + j] == e.str[j])) // if one char doesn't match
        break; // then break the loop

		if (found) return i;  // if found return start index
  }

	return -1; // if not found return -1
}

/****************************
     last index of method
*****************************/
int estring::lastIndexOf(const estring& e, int x) const {
	// get index of parameter str and this str
	int le = e.length() - 1, lo = this->length() - 1;

  // validate some conditions
  if(x < 0 || x >= lo || le > lo) return -1;

	bool found;

	for (int i = lo - le; i >= x; i--, found = true) { // for each char
		for (int j = le; j >= 0; j--) // matching for e string
			if (!(found = this->str[i + j] == e.str[j])) // if one char doesn't match
				break;  // then break the loop

		if (found) return i; // if found return start index
	}

	return -1; // if not found return -1
}

/**********************
      count method
***********************/
int estring::count(const estring& e) const {
	int count = 0, le = e.length(), lo = this->length();

	bool found;

	for (int i = 0; i < lo; i++, found = true) { // for each char
		for (int j = 0; j < le; j++)  // matching for e str
			if (!(found = this->str[i + j] == e.str[j]))
				break;

		if (found) count++; // if fount increment count
	}

	return count;
}


/**********************************
  char Code At & char At methods
***********************************/
int estring::charCodeAt(int x) const {return str[x];}
char estring::charAt(int x) const { return str[x];}

/************************
     includes method
*************************/
bool estring::includes(const char str[]) const {
  // get index number
  int ol = this->length() - 1;

  // get index number
  int pl = 0;
  while(str[pl] != '\0') pl++;
  pl--;

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

bool estring::includes(const estring& str) const {
  // get index number
  int ol = this->length() - 1;

  // get index number
  int pl = str.length() -1 ;

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
bool estring::endsWith(const char str[], int index) const {
  // get index number
  int ol = this->length() - 1;

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

bool estring::endsWith(const estring& str, int index) const {
  // get index number
  int ol = this->length() - 1;

  if(index > 0 && index < ol) ol = index;

  // get index number
  int pl = str.length() - 1;

  if(pl > ol) return false;

  for(int i = ol - pl, j = 0; i <= ol; i++, j++)
    if(this->str[i] != str.str[j])
      return false;

  return true;
}

/**********************
    pad start method
***********************/
estring& estring::padStart(int len, const estring& str) {
  // get the length of this str
  int ol = this->length();

  if (ol >= len) return *this;

  // get the length of parameter str
  int pl = str.length();

  // copy this str to temp
  char *t = this->str;

  // allocate new memory for this str
  this->str = new char[len + 1];

  // add the str and repeat until the location of original str
  for(int i = 0, j = 0; i < len - ol; i++, j++, j %= pl)
    this->str[i] = str.str[j];

  // add original string at the end
  for(int i = 0, j = len - ol ; i < ol; j++, i++)
    this->str[j] = t[i];

  // add null char
  this->str[len] = '\0';

  // free t memory
  delete [] t;

  return *this;
}

/***********************
    pad end method
************************/
estring& estring::padEnd(int len, const char str[]) {
  // get the length of my str
  int ol = this->length();

  if (ol >= len) return *this;

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

  return *this;
}

estring& estring::padEnd(int len, const estring& str) {
  // get the length of my str
  int ol = this->length();

  if (ol >= len) return *this;

  // get the length of parameter str
  int pl = str.length();

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

  return *this;
}

/***************************
  trim & trim right methods
*****************************/
estring& estring::trim() {
  // get the index count of this str
	int l = this->length() - 1, lss = 0;

	// copy this str to temp
	char* temp = this->str;

	// get first index of string not space and store it at lss
	for (int i = 0; i < l, str[i] == ' '; i++, lss++);

  // get the last index of string not space and store it at lss
	for (; l >= 0, str[l] == ' '; l--);

  // if the string is only space
  if(l == -1) {
    delete [] temp;   // free temp memory
    this->str = new char [1];   // allocate only 1 char space
    this->str = "";   // set it to null char
    return *this;     // return and end the function
  }

	this->str = new char[++l - lss + 1]; // allocate new memory

	for (int i = lss, j = 0; i <= l; i++, j++) // copy each char between
		this->str[j] = temp[i];                       // lss and l

	this->str[l - lss] = '\0'; // add null char

	delete[] temp; // free temp memory

	return *this;
}

estring& estring::trimRight(void){
  // get index number
  int l = this->length() - 1;

  for(;l >= 0 && str[l] == ' '; l--)
    str[l] = '\0';

  char *t = str;
  str = new char[l + 2];

  for(int i = 0; i <= l; i++)
    str[i] = t[i];

  str[l + 1] = '\0';

  // free t memory
  delete [] t;

  return *this;
}

/***********************************
    to lower & upper case methods
************************************/
estring& estring::toLoweCase (void) {
  for(int i = 0; str[i] != '\0'; i++)    // for each char
    if(str[i] >= 'A' && str[i] <= 'Z')   // if it was capital
      str[i] += 32; // convert it to small

  return *this;
}

estring& estring::toUpperCase() {
  for(int i = 0; str[i] != '\0'; i++)    // for each char
    if(str[i] >= 'a' && str[i] <= 'z')   // if it was small
      str[i] -= 32; // convert it to capital

	return *this;
}

/***********************
      slice method
************************/
estring& estring::slice(int x, int y) {
	estring temp;
	if (!y) y = this->length() - 1;
	else if (x > y || (x < 0 && y != length()) || y > length()) {
    temp = *this;
    return temp;
	};

	if (x < 0) {
		temp.str = new char[-x + 1];
		for (int i = 0, j = x; y + j < y; i++, j++)
			temp.str[i] = str[y + j];
		temp.str[-x] = '\0';
	}
	else {
		temp.str = new char[y - x + 1];
		for (int i = 0, j = x; j <= y; i++, j++)
			temp.str[i] = str[j];
		temp.str[y - x + 1] = '\0';
	}
	return temp;
}

/*************************
      reverse method
**************************/
estring& estring::reverse(void) {
  // get index number
  int l = length() - 1;

  char t;
  // loop and swap each char in the first half whit it correspondence
  for(int i = 0; i <= l / 2; i++) {
    // simple swap
    t = str[i];     // store char at index i in temp variable
    str[i] = str[l - i];  // set correspondence char at index l - i to index i
    str[l - i] = t;   // set char at index l - i  to temp;
  }
  return *this;
}

/***********************
      erase method
************************/
estring& estring::erase(int start_i, int end_i) {
  // get the length
  int l = this->length();

  // check some condition
  if(start_i < 0 || start_i >= end_i) return *this;
  if(end_i < 0 || end_i >= l) return *this;

  // copy str and reallocate memory
  char *t = str;
  str = new char[l - (end_i - start_i)];

  // copy t in str without letters between start and end index
  for(int i = 0, j = 0; j <= l; i++, j++)
    (j < start_i || j > end_i)?
      str[i] = t[j] : i--;

  // free t memory
  delete [] t;

  return *this;
}

/***********************
     replace method
************************/
estring& estring::replace(const estring& e1, const estring& e2) {
	 // get the length of all strings
  int l1 = e1.length(), l2 = e2.length(), lo= this->length();

  if (l1 > lo || l1 == 0) return *this;

  char *temp = this->str; // copy this str in temp
  // allocate new memory
  this->str = new char[l1 == l2? lo + 1 : lo + (this->count(e1) * (l2 - l1) + 1)];

  // put str in temp with replace each t2 with t2
  for(int i = 0, t = 0; i <= lo; i++) {
    for(int j = 0; j < l1; j++) {
      if(temp[i + j] != e1.str[j]){  // no match
        str[t] = temp[i]; // copy str char at this index
        t++;
        break;
      } else if (j == l1 - 1) { // in case of match
        for(int x = 0; x < l2; x++, t++) // replace it with new str
          str[t] = e2.str[x];

        i += l1 - 1;
      }
    }
  }

  delete[] temp; // free temp memory

  return *this;
}

/************************
     to string method
*************************/
estring estring::toString(int x, int y) {
  estring e;
  if(!x){
    e = "0";
    return e;
  }

	int l;
	for(l = 0;x > pow(y, l); l++);

  e = new char[l + 1];
	e.str[l--] = '\0';

	for (int i = x % y; x; l--, x /= y, i = x % y)
		e.str[l] = i < 10? i + 48 : i + 87;

	return e;
}

estring::~estring() {
  // free old memory
  delete [] str;
  str = 0;
}
