#include "mystr.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

template <class T>
bool isNewSuccess(T* newA, T* oldA = nullptr)
{
    if(newA == oldA || newA == nullptr)
    {
        cerr << "out of memory" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

Mystring::Mystring(const char *str)
{
    size_ = strlen(str);
    capacity_ = size_ * 2;
    str_ = new char[capacity_];
    strcpy(str_, str);
}

Mystring::~Mystring()
{
    delete [] str_;
}

const char * Mystring::c_str() const
{
    const char * temp = str_;
    return temp;
}

char & Mystring::operator [] (const int index) const
{
    if(index >= size_ || index < 0)
    {
        cerr << "[] index out of range" << endl;
        char *p = nullptr;
        return *p;
    }
    return str_[index];
}

Mystring & Mystring::operator += (const Mystring& rhs)
{
    int afterSize = size_ + rhs.size_;
    if(capacity_ <= afterSize && !(this->reSizeCapacity(afterSize * 2)))
    {
        return *this;
    }
    for(int i = size_; i < afterSize ; i++)
    {
        str_[i] = rhs.str_[i - size_];
    }
    str_[afterSize] = '\0';
    size_ = afterSize;
    return *this;
}

const Mystring Mystring::operator + (const Mystring& rhs) const
{
    Mystring temp = *this;
    temp += rhs;
    return temp;
}

void Mystring::clear()
{
    str_[0] = '\0';
    size_ = 0;
}

Mystring & Mystring::operator = (const Mystring &s) // my = "1234" -> Mystring s = "1234" -> s -> operator =
{
    if(&s == this) return *this;
    if(capacity_ <= s.size_ && !(this->reSizeCapacity(s.size_ * 2)))
    {
        return *this;
    }
    strcpy(str_, s.str_);
    size_ = s.size_;
    return *this;
}

void Mystring::swap(Mystring & rhs)
{
    char *p = str_;
    str_ = rhs.str_;
    rhs.str_ = p;
}

bool Mystring::operator < (const Mystring& rhs) const
{
    for(int i = 0; i < size_; i++)
    {
        if(str_[i] != rhs.str_[i])
        {
            return str_[i] < rhs.str_[i];
        }
    }
    return false;
}

bool Mystring::operator == (const Mystring& rhs) const
{
    if(size_ != rhs.size_) return false;
    for(int i = 0; i < size_; i++)
    {
        if(str_[i] != rhs.str_[i])
        {
            return false;
        }
    }
    return true;
}

bool Mystring::operator != (const Mystring& rhs) const
{
    return !(*this == rhs);
}

ostream & operator << (ostream &os, const Mystring &s)
{
    if(s.str_ == nullptr) return os;
    os << s.str_;
    return os;
}

istream & operator >> (istream &is, Mystring &s)
{
    s.size_ = 0;
    char c = getchar();
    while(c != ' ' && c != '\n')
    {
        s.size_ += 1;
        if(s.capacity_ == 0 && !(s.reSizeCapacity(8))) return is; //out of memory
        else if(s.capacity_ <= s.size_ && !(s.reSizeCapacity(s.size_ * 2))) return is;

        s.str_[s.size_ - 1] = c;
        c = getchar();
    }
    s.str_[s.size_] = '\0';
    return is;
}

bool Mystring::reSizeCapacity(int Csize)
{
    if(Csize <= capacity_)
    {
        cerr << "capacity_ > Csize" << endl;
        return false;
    }
    char *temp = str_;
    str_ = new char[Csize];
    if(!isNewSuccess(str_, temp)) return false;
    if(temp != nullptr) strncpy(str_, temp, size_);
    capacity_ = Csize;
    delete [] temp;
    return true;
}

Mystring Mystring::substr(int start = 0, int bias = 0) const
{
    Mystring temp;
    if(!temp.reSizeCapacity(bias + 1)) return temp;
    temp.setSize_(bias);
    for(int i = start; i < start + bias; i++)
    {
        temp[i - start] = str_[i];
    }
    temp.setCharInStr_(bias, '\0');
    return temp;
}
