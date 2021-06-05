#pragma once
class IAnimal
{
    static int count;
public:
    IAnimal();
    virtual ~IAnimal();
    void virtual show() = 0;
    static int getCount();
    bool virtual hungry() = 0;
    static int checkAge() = 0

};

