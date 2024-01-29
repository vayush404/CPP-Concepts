#include<iostream>

class A{
    public:
        int x;
        void print1(){
            std::cout<<this->x<<std::endl;
        }
    private:
        int y;
        void print2(){
            std::cout<<this->y<<std::endl;
        }
    protected:
        int z;
        void print3(){
            std::cout<<this->z<<std::endl;
        }
};
class B : public A{
    public:
    void foo(){
        x = 1;
        print1();
    }
    /** Inaccessible as private member can't be accessed outside the class they are declared , unless a friend class
     void foo2(){
        y = 1;
        print2();
    }
    */

   // protected can be accessed from the derived heirarchy
    void foo3(){
        z = 3;
        print3();
    }
};

int main(){
    B b;
    b.foo();
    b.x = 2; // accessible as it is public
    std::cout<<b.x<<std::endl;
    b.foo();
    b.foo3();
    //b.y = 3; inaccessible as private
    //b.z = 4; inaccessible as protected (outside the derived class heirarchies)

    
    return 0;
}
