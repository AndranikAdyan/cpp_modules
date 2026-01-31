# include <ctime>
# include <cstdlib>
# include <iostream>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

static Base*	generate(void) {
	int randomNumber = std::rand();
	if (!(randomNumber & 3)) randomNumber |= 1;
	switch(randomNumber & 3) {
		case 3:
			return new A();
		case 2:
			return new B();
		case 1:
			return new C();
	};
	return NULL;
}

void	identify(Base& baseRef) {
	try {
		A a = dynamic_cast<A&>(baseRef);
		std::cout << "Instance of A class" << std::endl;
		return ;
	}
	catch (...) {
	}
	try {
		B b = dynamic_cast<B&>(baseRef);
		std::cout << "Instance of B class" << std::endl;
		return ;
	}
	catch (...) {
	}
	try {
		C c = dynamic_cast<C&>(baseRef);
		std::cout << "Instance of C class" << std::endl;
		return ;
	}
	catch(...) {
	}
	std::cout << "Not Hierarchic object" << std::endl;
}
	
int	main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	for (int index = 0; index < 10; ++index) {
		Base* baseObject = generate();
		identify(*baseObject);
		delete baseObject;
	}

	return 0;
}

