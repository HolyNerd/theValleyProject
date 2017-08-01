#ifndef CHARGE_H
#define CHARGE_H

#include <object.h>
#include <color.h>

class Charge : public Object {
public:
	enum kind { POSITIVE, NEGATIVE };
	Charge();
	Charge(kind);

	void update();

	void setCharge(kind);
	void setValue(float);
	
private:
	kind charge;
	float value;
	bool chargeChanged;
};



#endif