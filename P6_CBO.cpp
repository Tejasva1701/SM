#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class ClassA {
public:
    void methodA() {
        cout << "Method A in ClassA\n";
    }
};

class ClassB {
public:
    void methodB(ClassA& objA) {
        objA.methodA();
        cout << "Method B in ClassB\n";
    }
};

class ClassC {
public:
    void methodC() {
        cout << "Method C in ClassC\n";
    }
};

int calculateCBO(const vector<unordered_set<string>>& dependencies) {
    int cbo = 0;
    for (const auto& set : dependencies) {
        cbo += set.size();
    }
    return cbo;
}

int main() {    
    vector<unordered_set<string>> dependencies;

    // First dependency set
    unordered_set<string> dependencySet1;
    dependencySet1.insert("ClassA");
    dependencies.push_back(dependencySet1);

    // Second dependency set
    unordered_set<string> dependencySet2;
    dependencySet2.insert("ClassB");
    dependencies.push_back(dependencySet2);

    // Third dependency set
    unordered_set<string> dependencySet3;
    dependencySet3.insert("ClassC");
    dependencies.push_back(dependencySet3);

    int cbo = calculateCBO(dependencies);
    cout << "Coupling Between Objects (CBO): " << cbo << endl;

    return 0;
}
