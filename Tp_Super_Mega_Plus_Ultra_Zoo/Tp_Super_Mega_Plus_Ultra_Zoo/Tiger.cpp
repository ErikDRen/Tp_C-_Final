#include <iostream>
using namespace  std;
#include "Tiger.h"

Tiger::Tiger(Zoo* zoo):IAnimal(zoo)
{
}
void Tiger::show(){
}
bool Tiger::fire(){
    cout << "Tiger rugisse" << endl;
    return false;

}
#include "Tiger.h"
