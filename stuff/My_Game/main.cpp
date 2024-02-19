#include <iostream>
#include "Animal.h"

using namespace std;

void line (){
    cout << "-------------" << "\n";
}

int main(){
    Animal a1;
    Animal a2("bob", 2, 4.12);

    a2.printInfo();
    line();

    a1.changeInfo("bobby", 3, 10.99);
    a2.changeInfo("jobbbbbbby", 4, 20.1);

    a1.printInfo();
    line();
    a2.printInfo();

    return 0;
}

