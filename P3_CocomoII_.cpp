#include <iostream>
#include <cmath>
using namespace std;

double calculateB(int *value) {
    double Scaling_factor[5][6] = {
        {6.20, 4.96, 3.72, 2.48, 1.24, 0.00},
        {5.07, 4.05, 3.04, 2.03, 1.01, 0.00},
        {7.07, 5.65, 4.24, 2.83, 1.41, 0.00},
        {5.48, 4.38, 3.29, 2.19, 1.10, 0.00},
        {7.80, 6.24, 4.68, 3.12, 1.56, 0.00}
    };

    double sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += Scaling_factor[i][value[i]];
    }

    return (0.91 + (0.01 * sum));
}

double calculate_effort_multiplier(int *value_effortMultiplier) {
    double matrix[7][7] = {
        {0.73, 0.81, 0.98, 1.00, 1.30, 1.74, 2.38},
        {0.00, 0.00, 0.95, 1.00, 1.07, 1.15, 1.24},
        {0.00, 0.00, 0.87, 1.00, 1.29, 1.81, 2.61},
        {2.12, 1.62, 1.26, 1.00, 0.83, 0.63, 0.50},
        {1.59, 1.33, 1.12, 1.00, 0.87, 0.71, 0.62},
        {1.43, 1.30, 1.10, 1.00, 0.87, 0.73, 0.62},
        {0.00, 1.43, 1.14, 1.00, 1.00, 1.00, 0.00}
    };

    double effortMultiplier = 1;
    for (int i = 0; i < 7; i++) {
        effortMultiplier *= matrix[i][value_effortMultiplier[i]];
    }

    return effortMultiplier;
}

int main() {
    double A = 2.5;
    int size;

    cout << "Enter the size of the software in KLOC (thousands of lines of code): ";
    cin >> size;

    cout << "\nEnter the Scale Factor (0: Very Low, 1: Low, 2: Nominal, 3: High, 4: Very High, 5: Extra High)\n";

    string Scaling_factors[5] = {"Precedent ness", "Development flexibility", "Architecture/Risk resolution", "Team cohesion", "Process maturity"};

    int value_scalingFactor[5];
    for (int i = 0; i < 5; i++) {
        cout << Scaling_factors[i] << ": ";
        cin >> value_scalingFactor[i];
    }

    double B = calculateB(value_scalingFactor);
    double PM_nominal = A * pow(size, B);

    string Early_design_cost_driver[7] = {"RCPX", "RUSE", "PDIF", "PERS", "PREX", "FCIL", "SCED"};

    cout << "\nEnter the Effort multiplier(0: Extra Low, 1: Very Low, 2: Low, 3: Nominal, 4: High, 5: Very High, 6: Extra High)\n";

    int value_effortMultiplier[7];
    for (int i = 0; i < 7; i++) {
        cout << Early_design_cost_driver[i] << ": ";
        cin >> value_effortMultiplier[i];
    }

    double effort_multiplier = calculate_effort_multiplier(value_effortMultiplier);
    double PM_adjusted = PM_nominal * effort_multiplier;

    cout << "\nPM nominal is: " << PM_nominal;
    cout << "\nPM adjusted is: " << PM_adjusted;

    return 0;
}
