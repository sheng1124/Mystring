#ifndef MYSTR_H_
#define MYSTR_H_

#include <iostream>
#include <cstring>
#include <cstdio>

class Mystring
{
public:
    Mystring(): str_(new char('\0')), size_(0), capacity_(0) {}
    Mystring(const char *str);
    Mystring(const Mystring &s): Mystring(s.str_) {}
    ~Mystring();
    int size() const { return size_; }
    const char * c_str() const;
    char & operator [] (int index) const;
    Mystring & operator += (const Mystring& rhs);
    const Mystring operator + (const Mystring& rhs) const;
    void clear();
    Mystring & operator = (const Mystring &s);
    void swap(Mystring & rhs);

    bool operator < (const Mystring& rhs) const;
    bool operator == (const Mystring& rhs) const;
    bool operator != (const Mystring& rhs) const;

    friend std::ostream & operator << (std::ostream &os, const Mystring &s);
    friend std::istream & operator >> (std::istream &is, Mystring &s);

    bool reSizeCapacity(int Csize);
    int capacity() const { return capacity_; }
    Mystring substr(int start, int bias) const;
    char * begin() const { return &(str_[0]); }
    char * end() const { return &(str_[size_ - 1]); }

private:
    char *str_;
    size_t size_;
    size_t capacity_;

    void setSize_(int size){ size_ = size; }
    void setCharInStr_(int index, char c ){ str_[index] = c; }
};

#endif
