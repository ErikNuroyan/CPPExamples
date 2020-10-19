#include <iostream>
#include <algorithm>

using namespace std;

class NonDerivable final{};
class Derived:public NonDerivable{}; //Cannot derive from final class

int main() {
    return 0;
}
