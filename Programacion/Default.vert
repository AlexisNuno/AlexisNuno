#version 330

in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormal;

out vec3 InterpolatedColor;
out vec3 InterpolatedNormal; 
out vec3 PixelPosition;

uniform mat4 mvpMatrix;
uniform mat4 ModelMatrix;
uniform mat3 NormalMatrix;
in vec2 VertexTexCoord;
out vec2 InterpolatedTexCoord;


void main()
{
	InterpolatedColor = VertexColor;
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
	InterpolatedNormal = NormalMatrix*VertexNormal;
	PixelPosition= vec3(ModelMatrix* vec4(VertexPosition, 1.0f));
	InterpolatedTexCoord = VertexTexCoord;
}