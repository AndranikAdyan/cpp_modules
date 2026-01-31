#include "Serializer.hpp"
#include <iostream>

int main() {
	Data originalData;
	originalData.index = 665;
	originalData.serialNumber = 654;
	originalData.coefficient = 3.141592;
	std::cout << "Original Data object:" << std::endl;
	std::cout << "  address      : " << &originalData << std::endl;
	std::cout << "  index        : " << originalData.index << std::endl;
	std::cout << "  serialNumber : " << originalData.serialNumber << std::endl;
	std::cout << "  coefficient  : " << originalData.coefficient << std::endl;
	uintptr_t serializedPointer = Serializer::serialize(&originalData);
	std::cout << "\nSerialized value (uintptr_t): " << serializedPointer << std::endl;

	Data* deserializedData = Serializer::deserialize(serializedPointer);
	std::cout << "\nRestored Data object:" << std::endl;
	std::cout << "  address      : " << deserializedData << std::endl;
	std::cout << "  index        : " << deserializedData->index << std::endl;
	std::cout << "  serialNumber : " << deserializedData->serialNumber << std::endl;
	std::cout << "  coefficient  : " << deserializedData->coefficient << std::endl;
	if (deserializedData == &originalData)
		std::cout << "\nPointers match!" << std::endl;
	else
		std::cout << "\nPointers do not match!" << std::endl;

	return 0;
}
