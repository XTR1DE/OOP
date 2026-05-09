#include "Devices.h"
#include <iostream>
#include <string>
using namespace std;


template <class T>
class DeviceArray {
private:
	T** data;
	int sizea;

public:
	DeviceArray(int n = 0) {
		sizea = n;
		data = new T * [sizea];

		for (int i = 0; i < sizea; i++) {
			data[i] = nullptr;
		}
	}

	~DeviceArray() {
		delete[] data;
	}

	int size() {
		return sizea;
	}

	T*& operator[] (int index) {
		if (index < 0 || index >= sizea)
			throw "Index out of range";

		return data[index];
	}

	void show() {
		for (int i = 0; i < sizea; i++) {
			if (data[i] != nullptr) {
				data[i]->showInfo();
			}
		}
	}
};


int main()
{
	std::cout << "\n----- TEMPLATE ARRAY -----\n" << std::endl;

	DeviceArray<Device> devices(3);

	devices[0] = new Device("Base", 2048);
	devices[1] = new Phone("iPhone", 256000, 3200);
	devices[2] = new Phone("Samsung", 128000, 5000);

	devices.show();

	std::cout << "\nSize array: " << devices.size() << std::endl;

	devices[1]->screenOn();
	devices[1]->screenOff();

	std::cout << "\nDevices array\n" << std::endl;

	devices.show();

	system("pause");
	return 0;
}