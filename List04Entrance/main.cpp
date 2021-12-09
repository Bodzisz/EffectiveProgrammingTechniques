
#include <cassert>
#include <string>
#include <iostream>



template<typename Addable>
struct Add
{ /*implementation of Add*/
    typedef Addable ValueType;

    ValueType operator()(const Addable &comp1, const Addable &comp2) {
        return comp1 + comp2;
    }
};



template <class Funct >
struct Fold
{ /* implementation of Fold*/
    typename Funct::ValueType acc;

    Fold() {
        acc = typename Funct::ValueType();
    }

    Fold& operator()(const typename Funct::ValueType &val) {
        Funct funct;
        acc = funct(acc, val);
        return *this;
    }

    typename Funct::ValueType operator*() const {
        return acc;
    }
};



int main()
{

    Fold< Add<int> > f;

    f(1)(2)(3)(4)(5);

    f(6)(7)(8)(9)(10);



    assert(*f == 55);


    Fold< Add<std::string> > s;

    s("foo")("bar")("baz");



    assert(*s == "foobarbaz");


    return 0;
}
