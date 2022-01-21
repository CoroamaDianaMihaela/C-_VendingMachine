#pragma once
#include "RepoSTL.h"
#include "Produs.h"
#include <vector>
class TestRepoProdus {
private:
	RepoSTL<Produs> r_produse;
	vector<Produs> produse_test;
	void testRepo();
public:
	TestRepoProdus();
	void testMain();
};