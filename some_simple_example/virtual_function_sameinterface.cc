#include <iostream>
class Foo1
{
    public:
        void show()
        {
            std::cout << "Foo1's show\n";
        }
        
        virtual void show2()
        {
            std::cout << "Foo1's show2\n";
        }

        virtual void show3(int)
        {
            std::cout << "Foo1's show3\n";
        }


};

class Foo2 : public Foo1
{
    public:
        void show()
        {
            std::cout << "Foo2's show\n";
        }

        void show2()
        {
            std::cout << "Foo2's show2\n";
        }

        void show3(int) const override
        {
            std::cout << "Foo2's show3\n";
        }

};

int main()
{
    int a = 0;
    float b = 0.;
    Foo1 *f1 = new Foo1();
    Foo2 *f2 = new Foo2();

    Foo1 *f11 = f2;
    f1->show();
    f1->show2();
    f1->show3(a);

    f2->show();
    f2->show2();
    f2->show3(b);
    
    f11->show();
    f11->show2();

}

