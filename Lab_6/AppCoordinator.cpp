#include <iostream>
#include "RepoSTL.h"
#include "Console.h"
#include "Test.h"
using namespace std;


int main() {
	TestRepoProdus t;

	t.testMain();
	RepoSTL<Produs> repo_prod("Produse.txt");

	RepoSTL<Monede> repo_monede("Monede.txt");
	
	Service s(repo_prod, repo_monede);
	
	Console c(s);

	c.console();

	return 0;

}