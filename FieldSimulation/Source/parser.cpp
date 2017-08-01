
#include <parser.h>
#include <iostream>
#include <string>
#include <charge.h>

std::string parsing(Canvas* c) {

	static Charge* buffer = nullptr;

	std::string comand;
	std::cin >> comand;

	if(comand == "add") {
		std::cin >> comand;
		if(comand == "pos") {
			c->add(1);
			buffer = c->getPointer(c->getSize()-1);
		}
		else if(comand == "neg") {
			c->add(1);
			buffer = c->getPointer(c->getSize()-1);
			buffer->setCharge(Charge::NEGATIVE);
		}
		else {
			std::cout << "Wrong command" << std::endl;
		}
	}
	else if(comand == "move") {
		std::cin >> comand;
		
		if(comand == "up") {
			std::cin >> comand;
			float val = getVal(comand);
			
			buffer->move(0, val / 480.0, false);
		}
		else if(comand == "down") {
			std::cin >> comand;
			float val = getVal(comand);

			buffer->move(0, val / -480.0, false);
		}
		else if(comand == "right") {
			std::cin >> comand;
			float val = getVal(comand);

			buffer->move(val / 640, 0, false);
		}
		else if(comand == "left") {
			std::cin >> comand;
			float val = getVal(comand);

			buffer->move( val / -640, 0, false);
		}
		else {
			std::cout << "Wrong command" << std::endl;
		}
	}
	return comand;
}

float getVal(std::string str) {
	std::stringstream ss(str);
	float val;
	ss >> val;
	return val;
}
