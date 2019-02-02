#include<iostream>

using namespace std;

class Foo1{
public:
    virtual void show(){
        cout << "Foo1's show" << endl;
    }
};

class Foo2 : public Foo1 {
public:
    void show(){
        cout << "Foo2's show" << endl;
    }
};

class Foo3 {
public:
    virtual void show(){
        cout << "Foo3's show" << endl;
    }
};

class Foo4 : public Foo3{
public:
    virtual void show(){
        cout << "Foo4's show" << endl;
    }
};


void showFooByPtr(Foo1 *foo)
{
    foo->show();
}

void showFooByPtr2(Foo3 *foo)
{
    foo->show();
}
void showFooByRef(Foo1 &foo)
{
    foo.show();
}

int main()
{
    Foo1 f1;
    Foo2 f2;
    Foo3 f3;
    Foo4 f4;

    showFooByPtr(&f1);
    showFooByPtr(&f2);
    //showFooByPtr(&f3);
    cout << endl;

    showFooByPtr2(&f3);
    showFooByPtr2(&f4);
    cout << endl;

    showFooByRef(f1);
    showFooByRef(f2);
    //showFooByRef(f3);
    cout << endl;

    f1.show();
    f2.show();
    f3.show();
    f4.show();
}

