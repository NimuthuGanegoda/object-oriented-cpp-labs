#include "Liger.h"
#include <iostream>

using namespace std;

int main() {
    cout << "--- Mammal ---" << endl;
    Mammal m("Manny");
    m.speak();

    cout << "\n--- Lion ---" << endl;
    Lion l("Leo");
    l.speak();

    cout << "\n--- Tiger ---" << endl;
    Tiger t("Tigger");
    t.speak();

    cout << "\n--- Liger ---" << endl;
    Liger lg("Napoleon");
    lg.speak();

    return 0;
}
