#include <iostream>
#include <string>
using namespace std;


class Ship {
protected:
	int volume;
	int sailors;
	std::string name;
	std::string type;

	Ship* next;
	static Ship* head;


public:
	Ship(int volume = 0, int sailors = 0, std::string name = "Undefiend", std::string type = "Undefiend") {
		this->volume = volume >= 0 ? volume : 0;
		this->sailors = sailors >= 0 ? sailors : 0;
		this->name = name;
		this->type = type;
		next = nullptr;

		add();
	}

	void add() {
		next = head;
		head = this;
	}

	static void showList() {
		Ship* current = head;
		while (current != nullptr) {
			current->show();
			current = current->next;
		}
	}

	virtual void show() {
		std::cout << "\nVolume: " << volume << "\nSailors: " << sailors << "\nName: " << name << "Type: " << type << std::endl;
	}
};

Ship* Ship::head = nullptr;


class SteamShip : public Ship {
	float power;
public:
	SteamShip(int volume, int sailors, std::string name, std::string type, float power) : Ship(volume, sailors, name, type) {
		this->power = power;
	}

	void show() {
		Ship::show();
		std::cout << "Power " << power << std::endl;
	}
};


class SailBoat : public Ship {
	int sails;
public:
	SailBoat(int volume, int sailors, std::string name, std::string type, int sails) : Ship(volume, sailors, name, type) {
		this->sails = sails;
	}

	void show() {
		Ship::show();
		std::cout << "Count matches: " << sails << std::endl;
	}
};


class Corvette : public Ship {
	int cannons;
public:
	Corvette(int volume, int sailors, std::string name, std::string type, int cannons) : Ship(volume, sailors, name, type) {
		this->cannons = cannons;
	}

	void show() {
		Ship::show();
		std::cout << "Count cannons: " << cannons << std::endl;
	}
};


int main()
{
	Ship alpha(1000, 40, "St. Maria", "Ship");
	SteamShip beta(1001, 160, "Titanic", "SteamShip", 200);
	SailBoat gamma(400, 10, "SailBoat", "SailBoat", 5);
	Corvette epsilon(1500, 150, "Corvette", "Corvette", 20);


	Ship::showList();

	system("pause");
	return 0;
}