#version 450 core

vec4 verts[] = vec4[3] (
	vec4(-0.25f, -0.25f, 0.25f, 1.0f),
	vec4(0.0f, 0.25f, 0.25f, 1.0f),
	vec4(0.25f, -0.25f, 0.25f, 1.0f)
);

void main(void) {
	gl_Position = verts[gl_VertexID];
}
