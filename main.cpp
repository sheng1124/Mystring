#include "mystr.h"
#include <iostream>

using namespace std;
int main ()
{

    Mystring s("NTNU is great!"), t;
    cout << "s = " << s << " at" << static_cast<const void *> (s.c_str()) << endl;
    cout << "t = " << t << " at" << static_cast<const void *> (t.c_str()) << endl;

    Mystring s1("NTNU"), t1 = s1, u1;
    u1 = s1;

    cout << "s1 = " << s1 << " at" << static_cast<const void *> (s1.c_str()) << endl;
    cout << "t1 = " << t1 << " at" << static_cast<const void *> (t1.c_str()) << endl;
    cout << "u1 = " << u1 << " at" << static_cast<const void *> (u1.c_str()) << endl;

    Mystring s2("NTU"), t2("NTNU");
    s2 = t2;
    cout << "s2 = " << s2 << " at" << static_cast<const void *> (s2.c_str()) << endl;
    cout << "t2 = " << t2 << " at" << static_cast<const void *> (t2.c_str()) << endl;

    Mystring s3("NTNU");
    cout << "s3 size: " <<  s3.size() << endl; // 4
    const char *p = s3.c_str();
    s3[1] = 'F';
    cout << "modified s3 = " << s3 << " at" << static_cast<const void *> (s3.c_str()) << endl;
    cout << "p is " << p << endl;

    Mystring s4 = "NT", t4 = "NU", u4;
    s4 += t4;
    cout << "s4 = " << s4 << " at" << static_cast<const void *> (s4.c_str()) << endl;
    cout << "t4 = " << t4 << " at" << static_cast<const void *> (t4.c_str()) << endl;
    u4 = s4 + t4;
    cout << "u4 = " << u4 << " at" << static_cast<const void *> (u4.c_str()) << endl;
    u4.clear();
    cout << "cleared u4 = " << u4 << " at" << static_cast<const void *> (u4.c_str()) << endl;
    s4.swap(t4);
    cout << "swaped s4 = " << s4 << " at" << static_cast<const void *> (s4.c_str()) << endl;
    cout << "swaped t4 = " << t4 << " at" << static_cast<const void *> (t4.c_str()) << endl;

    return 0;

}
