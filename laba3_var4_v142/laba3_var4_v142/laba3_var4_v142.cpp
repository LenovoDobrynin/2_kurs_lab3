#include <iostream>
#include <random>
#include <time.h>
#include "CustomExpressionEvaluator.h"
#include "Summator.h"
#include "Multiplier.h"
#include "MobilePhone.h"
#include "Tablet.h"

void CustomExpressionEval() {
	CustomExpressionEvaluator c(4);
	c.setOneOperand(50, 0);
	c.setOneOperand(40, 1);
	c.setOneOperand(-10, 2);
	c.setOneOperand(-2, 3);
	c.logToScreen();
	c.logToFile("CustomExpressionEvaluator.txt");
}

void Summat() {
	Summator s(6);
	s.setManyOperands(new double[6]{ 2.6, -8.1, 13.2, 1.5, 3.4, -4 }, 6);
	s.logToScreen();
	s.logToFile("Summator.txt");
	s.shuffle();
	std::cout << "\nПодсчет после перемешивания:\n";
	s.logToScreen();
}

void Multipl() {
	Multiplier m(4);
	m.setManyOperands(new double[4]{ -0.5, -8, 1.5, 16 }, 4);
	m.logToScreen();
	m.logToFile("Multiplier.txt");
	m.shuffle(0, 3);
	std::cout << "\nПодсчет после перемешивания:\n";
	m.logToScreen();
}


void Task1() {

	std::cout << "=======================" << std::endl << "CustomExpressionEvaluator" << std::endl << std::endl;
	CustomExpressionEval();

	std::cout << "\n\n=======================" << std::endl << "Multiplier" << std::endl;
	Multipl();

	std::cout << "\n\n=======================" << std::endl << "Summator" << std::endl;
	Summat();
}

void Task2() {
	MobilePhone* mp1 = new MobilePhone("Iphone 14 Pro Max", "00000000", "11111111", 99.3, 100);
	MobilePhone* mp2 = new MobilePhone("Samsung Galaxy A51", "22222222", "33333333", 25.0, 30);

	mp1->PrettyPrint();
	mp1->call("88805553535", 10);
	mp1->PrettyPrint();

	mp2->PrettyPrint();
	mp2->call("q1234134314d", 35);
	mp2->PrettyPrint();

	mp1->serialize();
	mp1->deserialize();


	std::cout << "\n\nПланшеты\n\n";
	Tablet* t1 = new Tablet("Xiaomi Pad 5", "444444", "55555555", 100);
	Tablet* t2 = new Tablet("Apple Ipad 10.2", "666666", "777777", 9);

	t1->PrettyPrint();
	std::cout << std::endl;
	t1->call("6424");
	t1->PrettyPrint();

	t2->PrettyPrint();
	t2->call("1111");
	t2->PrettyPrint();


	std::cout << "\nПроверка типов объектов\n\n";
	std::cout << typeid(*mp1).name() << std::endl
		<< typeid(*mp2).name() << std::endl
		<< typeid(*t1).name() << std::endl
		<< typeid(*t2).name() << std::endl;


	std::cout << "\nПроверка RTTI\n\n";
	Phone* phones[4];
	phones[0] = mp1;
	phones[1] = mp2;
	phones[2] = t1;
	phones[3] = t2;

	for (size_t counter = 0; counter < 4; counter++) {
		Phone* phone = dynamic_cast<Phone*>(phones[counter]);
		if (phone) {
			std::cout << "Преобразование (" << typeid(*phones[counter]).name() << ") в Phone успешно!\n";
		}
		else {
			std::cout << "Не получилось преобразовать (" << typeid(*phones[counter]).name() << "( в Phone.\n";
		}
	}


}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));

	Task1();

	Task2();

	return 0;
}