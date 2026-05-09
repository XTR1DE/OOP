#pragma once
#include <string>
#include <iostream>


class Device {
private:
	std::string name;
	int memory;


public:
	Device(std::string name = "Undefiend", int memory = 1024) {
		this->name = name;
		this->memory = memory <= 0 ? 1024 : memory;
		add();
	}

	static int totalMemory;
	static int totalDevices;
	static int averageMemory;

	void add() {
		totalMemory += this->memory;
		totalDevices++;
		updateAverage();
	}


	static void updateAverage() {
		if (totalDevices > 0)
			averageMemory = totalMemory / totalDevices;
	}


	virtual void screenOn() {
		std::cout << "Device: " << Name() << " sceen on" << std::endl;
	}

	virtual void screenOff() {
		std::cout << "Device: " << Name() << " sceen off" << std::endl;
	}

	std::string Name() {
		return name;
	}

	void showInfo() {
		std::cout << "Device: " << name << ". Memory: " << memory << "MB" << std::endl;
	}
};

int Device::totalDevices = 0;
int Device::totalMemory = 0;
int Device::averageMemory = 0;


class Phone : public Device {
private:
	int battery;

public:
	Phone(std::string name, int memory, int battery) : Device(name, memory) {
		this->battery = battery > 0 ? battery : 1;
	}

	void screenOn() {
		std::cout << "Device: " << Name() << " sceen on" << std::endl;
	}

	void screenOff() {
		std::cout << "Device: " << Name() << " sceen off" << std::endl;
	}

	int getbattery() {
		return battery;
	}
};
