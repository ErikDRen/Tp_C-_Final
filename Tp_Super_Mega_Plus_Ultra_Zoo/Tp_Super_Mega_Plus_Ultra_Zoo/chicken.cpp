#include <iostream>
using namespace  std;
#include "Chicken.h"

Chicken::Chicken(Zoo* zoo):IAnimal(zoo)
{
}
void Chicken::show(){

}

bool Chicken::fire(){
    cout << "Chicken Dead" << endl;
    return false;
}
