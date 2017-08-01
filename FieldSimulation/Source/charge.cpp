#include <charge.h>

Charge::Charge() 
	: charge(POSITIVE), value{1.0f}, chargeChanged{true} 
{
	va.add(3);

	setVertexCoordinate(0, 0.0f, 0.06f, 0.0f);
	setVertexCoordinate(1, 0.06f, -0.06f, 0.0f);
	setVertexCoordinate(2, -0.06f, -0.06, 0.0f);

	type = GL_TRIANGLES;
}

Charge::Charge(kind k) 
	: charge(k), value{1.0f}, chargeChanged{true}
{
	va.add(3);

	setVertexCoordinate(0, 0.0f, 0.06f, 0.0f);
	setVertexCoordinate(1, 0.06f, -0.06f, 0.0f);
	setVertexCoordinate(2, -0.06f, -0.06, 0.0f);

	type = GL_TRIANGLES;
}

void Charge::setCharge(kind k) {
	charge = k;
	changed = true;
	chargeChanged = true;
}
void Charge::setValue(float v) {
	value = v;
	changed = true;
}

void Charge::update() {

	if(chargeChanged) {
		Color colors[3];
			
		switch(charge) {
			case POSITIVE: {
				
				colors[0].r = 249 / 255.0;
				colors[0].g = 121 / 255.0;
				colors[0].b = 112 / 255.0;
				

				colors[1].r = 249 / 255.0;
				colors[1].g = 210 / 255.0;
				colors[1].b = 112 / 255.0;
				

				colors[2].r = 151 / 255.0;
				colors[2].g = 249 / 255.0;
				colors[2].b = 112 / 255.0;
				
			} break;
			case NEGATIVE: {
				
				colors[0].r = 112 / 255.0;
				colors[0].g = 249 / 255.0;
				colors[0].b = 238 / 255.0;
				

				colors[1].r = 112 / 255.0;
				colors[1].g = 151 / 255.0;
				colors[1].b = 249 / 255.0;
				

				colors[2].r = 220 / 255.0;
				colors[2].g = 112 / 255.0;
				colors[2].b = 249 / 255.0;
				
			}break;
		};

		setVertexColor(0, colors[0].r,  colors[0].g,  colors[0].b);
		setVertexColor(1, colors[1].r,  colors[1].g,  colors[1].b);
		setVertexColor(2, colors[2].r,  colors[2].g,  colors[2].b);
	}


	Object::update();
}