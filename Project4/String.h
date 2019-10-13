#ifndef STRING_H_
#define STRING_H_
class String{
public:
char * myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);
int myStringCompare(const char * str1, const char * str2);
size_t myStringLength(const char * str);
};
#endif
