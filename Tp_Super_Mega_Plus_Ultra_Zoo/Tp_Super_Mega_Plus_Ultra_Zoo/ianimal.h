#ifndef IANIMAL_H_INCLUDED
#define IANIMAL_H_INCLUDED

class IAnimal
{
    static int count;
public:
    IAnimal();
    virtual ~IAnimal();
    void virtual show() = 0;
    static int getCount();
};
#endif // IANIMAL_H_INCLUDED

