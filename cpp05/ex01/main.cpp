#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test 1: Create bureaucrats with wrong grade ===" << std::endl;
	try {
		Bureaucrat tooHigh("High", 0);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat tooLow("Low", 200);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 2: Increment / Decrement ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 2);
		std::cout << alice << std::endl;
		alice.increment();
		std::cout << alice << std::endl;
		alice.increment();
		std::cout << alice << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bob("Bob", 149);
		std::cout << bob << std::endl;
		bob.decrement();
		std::cout << bob << std::endl;
		bob.decrement();
		std::cout << bob << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 3: Forms with wrong grades ===" << std::endl;
	try {
		Form badForm1("Bad1", 0, 10);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Form badForm2("Bad2", 151, 100);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 4: Bureaucrats signing forms ===" << std::endl;
	Bureaucrat charlie("Charlie", 50);
	Bureaucrat dave("Dave", 120);
	Form contract("Contract", 100, 50);

	std::cout << charlie << std::endl;
	std::cout << dave << std::endl;
	std::cout << contract << std::endl << std::endl;

	charlie.signForm(contract);

	std::cout << contract << std::endl;

	dave.signForm(contract);

	std::cout << std::endl << "=== Test 5: Multiple forms ===" << std::endl;
	Form tax("Tax Report", 100, 70);
	Form secret("Secret Dossier", 20, 5);

	charlie.signForm(tax);
	dave.signForm(tax);
	dave.signForm(secret);
	charlie.signForm(secret);

	std::cout << std::endl << tax << std::endl;
	std::cout << secret << std::endl;

	return 0;
}
