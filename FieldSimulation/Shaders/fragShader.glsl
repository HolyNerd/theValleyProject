#version 450 core

out vec4 color;
in vec3 oColor;

void main(void) {
	color = vec4(oColor.rgb, 1.0f);
}