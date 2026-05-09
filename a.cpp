#include <iostream>
#include <string>
using namespace std;


class Array {
public:
	virtual int size() = 0;
	virtual int& operator[] (int index) = 0;
	operator int() {
		return size();
	}


};


class TestArray : public Array {
private:
	int* data;
	int sizea;

public:
	TestArray(int n) {
		sizea = n;
		data = new int[n]();

	}

	int size() {
		return sizea;
	}


	int& operator[] (int index) {
		if (index < 0 || index >= sizea)
			throw "Array index out of range";
		return *(data + index);
	}
};


int main()
{
	setlocale(LC_ALL, "");

	TestArray arr(10);
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = i * 2;
	}

	std::cout << "Full array" << std::endl;

	for (int i = 0; i < arr.size(); i++) {
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}



	std::cout << "\n" << std::endl;
	std::cout << "arr[2] = " << arr[2] << "\n";

	std::cout << "Length: " << arr.size() << "\n";


	system("pause");
	return 0;
}