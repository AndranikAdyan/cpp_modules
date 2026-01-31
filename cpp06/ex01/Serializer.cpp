#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::~Serializer() {
}

Serializer::Serializer(const Serializer&) {
}

Serializer&	Serializer::operator=(const Serializer&) {
	return *this;
}

uintptr_t	Serializer::serialize(Data* obj) {
	return reinterpret_cast<uintptr_t>(obj);
}

Data*	Serializer::deserialize(uintptr_t ptr) {
		return reinterpret_cast<Data*>(ptr);
}
