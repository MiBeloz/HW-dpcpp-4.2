#include <iostream>
#include <string>
#include <fstream>
#include <memory>

#include "Data_Originally.hpp"
#include "Data_DrySolid.hpp"


int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	std::cout << "\tСвойства хорошего кода. Принципы DRY и SOLID.\n\n" << std::endl;

	std::ofstream out_file("out.txt", std::ios::out);
	std::string str = "Hello World!";

	{
		std::cout << "\tОперации с объектом класса с оригинальным кодом:\n" << std::endl;

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

		std::unique_ptr<MyData> p_data = std::make_unique<Text>(str);
		std::cout << "Создан объект 'Text' со строкой '" + str + '\n' << std::endl;
		std::cout << "Вызов метода 'print()':" << std::endl;
		std::cout << p_data->print() << std::endl;
		std::cout << std::endl;

		p_data.reset(new HTML(str));
		std::cout << "Создан объект 'HTML' со строкой '" + str + '\n' << std::endl;
		std::cout << "Вызов метода 'print()':" << std::endl;
		std::cout << p_data->print() << std::endl;
		std::cout << std::endl;

		p_data.reset(new JSON(str));
		std::cout << "Создан объект 'JSON' со строкой '" + str + '\n' << std::endl;
		std::cout << "Вызов метода 'print()':" << std::endl;
		std::cout << p_data->print() << std::endl;
		std::cout << std::endl;
	}

	
	std::cin.get();
	return 0;
}
