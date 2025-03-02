#include <iostream>
#include <typeinfo>

using namespace std;

template <class T1, class T2>
class myType {
    public:
    T1 member1;
    T2 member2;
    myType(T1 member1, T2 member2) {
        this->member1=member1;
        this->member2=member2;
    }
    void display() {
        cout << "member1 (type " << typeid(member1).name() << ")=" << member1 << " member2 (type " << typeid(member2).name()<< ")=" << member2 << endl;
    }
};

int main() {
    myType<int,string> m1(1, "aaa");
    myType<string,double> m2("bbb", 2.71);
    m1.display();
    m2.display();

    int a = 9 ;
    int b = 0 ;

    cout << a/b ;

}
