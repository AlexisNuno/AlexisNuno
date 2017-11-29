#version 330

in vec3 InterpolatedColor;
in vec3 PixelPosition;
out vec4 FragColor;

in vec3 InterpolatedNormal; 


uniform vec3 LightPosition;
uniform vec3 LightColor;
uniform vec3 CameraPosition;

in vec2 InterpolatedTexCoord;
uniform sampler2D DiffuseTexture;
uniform sampler2D Mesher;

void main()
{
	vec3 ambient = 0.9f * LightColor;
	
	vec3 L= LightPosition - PixelPosition;
	L = normalize(L);
	vec3 diffuse = pow(dot(L, InterpolatedNormal),2)* LightColor;
	
	vec3 R= reflect(-L, InterpolatedNormal);

	vec3 V = CameraPosition-PixelPosition;
	V = normalize(V);

	vec3 specular = 0.5f * dot(V,R)*LightColor;
	vec3 R= reflect(-L, InterpolatedNormal);

	vec3 V = CameraPosition-PixelPosition;
	V = normalize(V);

	vec3 specular = 0.5f * dot(V,R)*LightColor;
	

	vec3 phong = (ambient + diffuse + specular);

vec4 imgUno= texture2D(DiffuseTexture, InterpolatedTexCoord);
	vec4 imgDos= texture2D(Mesher, InterpolatedTexCoord);
	vec4 imgTres=mix(imgUno,imgDos,0.5f);

	FragColor = vec4 (phong, 1.0f)* imgTres;
	
}