#include <iostream>
#include <vector>
using namespace std;

class BaseClass {
public:
    virtual void func() {}
};

class IntermediateClass1 : public BaseClass {};

class IntermediateClass2 : public IntermediateClass1 {};

class LeafClass : public IntermediateClass2 {};

int calculateDIT(const vector<string>& inheritanceHierarchy, const string& className) {
    int depth = 0;
    for (const auto& currentClass : inheritanceHierarchy) {
        if (currentClass == className) {
            break;
        }
        depth++;
    }
    return depth;
}

int main() {
    // Inheritance Hierarchy
    vector<string> hierarchy = {"BaseClass", "IntermediateClass1", "IntermediateClass2", "LeafClass"};

    // Calculate DIT for each class in the hierarchy
    for (const auto& className : hierarchy) {
        int dit = calculateDIT(hierarchy, className);
        cout << "Depth of Inheritance Tree (DIT) for " << className << ": " << dit << endl;
    }

    return 0;
}
