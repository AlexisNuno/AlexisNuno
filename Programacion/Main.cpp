#include <iomanip>
#include "Transform.h"
#include <iostream>


Transform rotation;
Transform translation;
Transform scale;
Transform combined;




void PrintTransform(Transform& t) {
	glm::mat4 _modelMatrix = t.GetModelMatrix();
	for (size_t i = 0; i < _modelMatrix.length(); i++) {
		for (size_t j = 0; j < _modelMatrix.length(); j++) {

			std::cout << std::setw(10) << std::left << _modelMatrix[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main() {
	rotation.setRotation(45, 90, 30);
	PrintTransform(rotation);

	translation.setPosition(3, 5, -7);
	PrintTransform(translation);

	scale.setScale(2, 3, 4);
	PrintTransform(scale);

	combined.setRotation(45, 90, 30);
	combined.setPosition(3, 5, -7);
	combined.setScale(2, 3, 4);

	PrintTransform(combined);

	getchar();
	return 0;

}