#include "Test.h"
#include <cassert>

void TestRepoProdus::testRepo()
{
	this->r_produse.setFileName("TestProduse.txt");
	this->r_produse.loadFromFile();

	int n = this->r_produse.getAll().size();

	for (int i = 0; i < n; i++) {
		assert(this->r_produse.getAll()[i] == this->produse_test[i]);
	}
}

TestRepoProdus::TestRepoProdus()
{
	char* nume_1 = new char[strlen("Twix")+1];
	strcpy_s(nume_1, strlen("Twix") + 1, "Twix");
	Produs p1(123, nume_1, 4);
	char* nume_2 = new char[strlen("Mars") + 1];
	strcpy_s(nume_2, strlen("Mars") + 1, "Mars");
	Produs p2(23, nume_2, 5);
	char* nume_3 = new char[strlen("Milka") + 1];
	strcpy_s(nume_3, strlen("Milka") + 1, "Milka");
	Produs p3(15, nume_3, 6);

	this->produse_test.push_back(p1);
	this->produse_test.push_back(p2);
	this->produse_test.push_back(p3);
}




void TestRepoProdus::testMain()
{
	this->testRepo();
}
