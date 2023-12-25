#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Method {
public:
    string name;
    int complexity;

    Method(string n, int c) : name(n), complexity(c) {}
};

class Metrics {
public:
    string Name;
    vector<Method> methods;

    void addMethod(string name, int complexity) {
        methods.push_back(Method(name, complexity));
    }

    int calculateWMC() {
        int wmc = 0;
        for (const auto& method : methods) {
            wmc += method.complexity;
        }
        return wmc;
    }
};

int main() {
    // Example usage
    Metrics myClass;
    myClass.Name = "MyClass";

    // Adding methods with their complexities
    myClass.addMethod("methodA", 5);
    myClass.addMethod("methodB", 3);
    myClass.addMethod("methodC", 4);

    // Calculate and display the WMC
    int wmc = myClass.calculateWMC();
    cout << "Weighted Methods per Class (WMC) for " << myClass.Name << ": " << wmc << endl;

    return 0;
}
