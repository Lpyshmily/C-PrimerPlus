// string1.cpp -- String class methods
#include "string1.h"
using namespace std;
int String::num_strings = 0;

// constructors and other methods
String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings++;
}
String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
String::String(const String & st)
{
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	num_strings++;
}
String::~String()
{
	num_strings--;
	delete[] str;
}

// overloaded operator methods
String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}
String & String::operator=(const char * s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}
char & String::operator[](int i)
{
	return str[i];
}
const char & String::operator[](int i)const
{
	return str[i];
}
// overloaded operator friends
bool operator<(const String & st, const String & st2)
{
	return (strcmp(st.str, st2.str)<0);
}
bool operator>(const String & st, const String & st2)
{
	return (strcmp(st.str, st2.str)>0);
}
bool operator==(const String & st, const String & st2)
{
	return (strcmp(st.str, st2.str)==0);
}
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
// static function
int String::HowMany()
{
	return num_strings;
}