#include <iostream>
using namespace std;

void Swap(int &x, int &y){
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main(){
	int x = 5, y = 3;
	cout << "---Swapping two integer values---\n";
	cout << "Before Swapping" << endl;
	cout << "Value of x: " << x << "\n" << "Value of y: " << y << "\n\n";
	Swap(x,y);
	cout << "After Swapping" << endl;
	cout << "Value of x: " << x << "\n" << "Value of y: " << y << "\n\n";
	
	return 0;
}
