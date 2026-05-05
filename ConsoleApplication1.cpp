// ConsoleApplication1.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
#include <string>



// -----------------------------------------------------------------------------------------------------------A----------------------------------------------------------


class Array{
public:
	virtual int size() = 0;
	virtual int& operator[] (int index) = 0;
	operator int() {
		return size();
	}


};


class TestArray : public Array{
private:
	int* data;
	int sizea;

public:
	TestArray(int n){
		sizea = n;
		data = new int[n]();

	}

	int size(){
		return sizea;
	}


	int& operator[] (int index){
		if (index < 0 || index > sizea)
			throw "Array index out of range";
		return *(data + index);
	}
};


// -----------------------------------------------------------------------------------------------------------B---------------------------------------------------------


class Device{
private:
	std::string name;
	int memory;


public:
	Device(std::string name = "Undefiend", int memory = 1024){
		this->name = name;
		this->memory = memory <= 0 ? 1024 : memory;
		add();
	}

	static int totalMemory;
	static int totalDevices;
	static int averageMemory;

	void add(){
		totalMemory += this->memory;
		totalDevices++;
		updateAverage();
	}


	static void updateAverage(){
		if (totalDevices > 0)
			averageMemory = totalMemory / totalDevices;
	}


	virtual void screenOn() {
		std::cout << "Ýêðàí óñòðîéñòâà \"" << name << "\" âêëþ÷¸í." << std::endl;
	}

	virtual void screenOff() {
		std::cout << "Ýêðàí óñòðîéñòâà \"" << name << "\" âûêëþ÷åí." << std::endl;
	}

	std::string Name(){
		return name;
	}

	void showInfo() {
		std::cout << "Óñòðîéñòâî: " << name << ", ïàìÿòü: " << memory << " ÌÁ" << std::endl;
	}
};

int Device::totalDevices = 0;
int Device::totalMemory = 0;
int Device::averageMemory = 0;


class Phone : public Device{
private:
	int battery;

public:
	Phone(std::string name, int memory, int battery) : Device(name, memory){
		this->battery = battery > 0 ? battery : 1;
	}

	void screenOn() {
		std::cout << "Ýêðàí òåëåôîíà \"" << Name() << "\" âêëþ÷¸í." << std::endl;
	}

	void screenOff() {
		std::cout << "Ýêðàí òåëåôîíà \"" << Name() << "\" âûêëþ÷åí." << std::endl;
	}

	int getbattery(){
		return battery;
	}
};




int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");

	TestArray arr(10);
	for (int i = 0; i < arr.size(); i++){
		arr[i] = i * 2;
	}



	std::cout << "\n" << std::endl;
	std::cout << "arr[2] = " << arr[2] << "\n";

	std::cout << "Ðàçìåð: " << arr.size() << "\n";



	Device base("Áàçîâîå óñòðîéñòâî", 2048);
	base.screenOn();
	base.showInfo();
	base.screenOff();

	Phone iphone("iPhone 14", 256000, 3200);
	iphone.screenOn();
	iphone.showInfo();
	iphone.screenOff();


	std::cout << "Âñåãî ñîçäàíî óñòðîéñòâ: " << Device::totalDevices << "\n";
	std::cout << "Îáùàÿ ïàìÿòü: " << Device::totalMemory << " ÌÁ\n";
	std::cout << "Ñðåäíÿÿ ïàìÿòü: " << Device::averageMemory << std::endl;



	system("pause");
	return 0;
}
