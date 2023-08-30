#include <iostream>

#include "Data_Originally.hpp"


int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	std::cout << "\tСвойства хорошего кода. Принципы DRY и SOLID.\n\n" << std::endl;

	{
		std::cout << "\tОперации с объектом класса с оригинальным кодом:\n" << std::endl;
		std::ofstream out_file("out.txt", std::ios::out);
		std::string str = "Hello World!";

		Data data(str, Data::Format::kText);
		std::cout << "Создан объект со строкой '" + str + "' и форматом 'kText'.\n" << std::endl;

		try {
			std::cout << "Вызов метода 'printAsHTML()':" << std::endl;
			std::cout << data.printAsHTML() << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			std::cout << "Вызов метода 'printAsJSON()':" << std::endl;
			std::cout << data.printAsJSON() << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			std::cout << "Вызов метода 'printAsText()':" << std::endl;
			std::cout << data.printAsText() << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;


		try {
			std::cout << "Вызов метода 'saveTo()' для формата 'kHTML':" << std::endl;
			saveTo(out_file, data, Data::Format::kHTML);
			std::cout << "Сохранение прошло успешно!" << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			std::cout << "Вызов метода 'saveTo()' для формата 'kJSON':" << std::endl;
			saveTo(out_file, data, Data::Format::kJSON);
			std::cout << "Сохранение прошло успешно!" << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			std::cout << "Вызов метода 'saveTo()' для формата 'kText':" << std::endl;
			saveTo(out_file, data, Data::Format::kText);
			std::cout << "Сохранение прошло успешно!" << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
	}

	std::cout << std::endl << std::endl;

	{
		std::cout << "\tОперации с объектом класса после применения принципов DRY и SOLID:\n" << std::endl;
		std::ofstream out_file("out.txt", std::ios::out);
		std::string str = "Hello World!";

		Data data(str, Data::Format::kText);
		std::cout << "Создан объект со строкой '" + str + "' и форматом 'kText'.\n" << std::endl;

		try {
			std::cout << "Вызов метода 'printAsHTML()':" << std::endl;
			std::cout << data.printAsHTML() << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			std::cout << "Вызов метода 'printAsJSON()':" << std::endl;
			std::cout << data.printAsJSON() << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			std::cout << "Вызов метода 'printAsText()':" << std::endl;
			std::cout << data.printAsText() << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;


		try {
			std::cout << "Вызов метода 'saveTo()' для формата 'kHTML':" << std::endl;
			saveTo(out_file, data, Data::Format::kHTML);
			std::cout << "Сохранение прошло успешно!" << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			std::cout << "Вызов метода 'saveTo()' для формата 'kJSON':" << std::endl;
			saveTo(out_file, data, Data::Format::kJSON);
			std::cout << "Сохранение прошло успешно!" << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			std::cout << "Вызов метода 'saveTo()' для формата 'kText':" << std::endl;
			saveTo(out_file, data, Data::Format::kText);
			std::cout << "Сохранение прошло успешно!" << std::endl;
		}
		catch (std::runtime_error& re) {
			std::cerr << re.what() << std::endl;
		}
	}
	
	
	std::cin.get();
	return 0;
}
