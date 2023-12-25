#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Method {
public:
    string name;
    unordered_set<string> calledMethods;

    Method(string n) : name(n) {}

    void addCalledMethod(string methodName) {
        calledMethods.insert(methodName);
    }
};

class Metrics {
public:
    string Name;
    vector<Method> methods;

    void addMethod(string name) {
        methods.push_back(Method(name));
    }

    void addMethodCall(string methodName, string calledMethodName) {
        for (auto& method : methods) {
            if (method.name == methodName) {
                method.addCalledMethod(calledMethodName);
                break;
            }
        }
    }

    int calculateRFC() {
        unordered_set<string> rfcSet;
        for (const auto& method : methods) {
            rfcSet.insert(method.calledMethods.begin(), method.calledMethods.end());
        }
        return rfcSet.size();
    }
};

int main() {
    // Example usage
    Metrics myClass;
    myClass.Name = "MyClass";

    // Adding methods to the class
    myClass.addMethod("methodA");
    myClass.addMethod("methodB");
    myClass.addMethod("methodC");

    // Adding method calls (e.g., methodA calls methodB)
    myClass.addMethodCall("methodA", "methodB");
    myClass.addMethodCall("methodA", "methodC");
    myClass.addMethodCall("methodB", "methodC");

    // Calculate and display the RFC
    int rfc = myClass.calculateRFC();
    cout << "Response for a Class (RFC) for " << myClass.Name << ": " << rfc << endl;

    return 0;
}
