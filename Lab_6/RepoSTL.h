#pragma once
#include "Repo.h"
#include <string.h>
#include <cstring>
#include <fstream>
#include <cstddef>

using namespace std;

template<class T>

class RepoSTL : public Repo<T> {
private:
	char* fileName;
public:

	RepoSTL() : Repo<T>() {
		this->fileName = NULL;
	};

	~RepoSTL() {
		delete[] this->fileName;
	};

	RepoSTL(const char* fileName) {
		this->fileName = new char[strlen(fileName) + 1];
		//strcpy(this->fileName, fileName);
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();

	};

	void setFileName(const char* fileName) {

		if (this->fileName != NULL) {
			delete[] this->fileName;
		}
		if (fileName != NULL) {
			this->fileName = new char[strlen(fileName) + 1];
			strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
			//strcpy(this->fileName, fileName);
		}
		else
			this->fileName = NULL;

	};

	RepoSTL(const RepoSTL& r) {

		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		//strcpy(this->fileName, fileName);
		this->loadFromFile();
	}

	void loadFromFile() {

		if (this->fileName != NULL) {

			ifstream f(this->fileName);

			T elem;

			while (f>>elem) {
				Repo<T>::addElem(elem);

			}
			f.close();
		}
		else
			Repo<T>::clear();
	};

	void saveToFile() {

		if (this->fileName != NULL) {

			ofstream f(this->fileName);
			int n = Repo<T>::getSize();
			for (int i = 0; i <n; i++)
				f << Repo<T>::getElem(i);

			f.close();
		}
	};


	void addElem(T c) {
		Repo<T>::addElem(c);
	};


	void setNumberAtPos(int i, int newNumber) {
		Repo<T>::setNumar(i, newNumber);
	};


	vector<T> getAll() {
		return Repo<T>::getAll();
	};

	RepoSTL<T>& operator=(const RepoSTL<T>& repo)
	{
		this->setFileName(repo.fileName);
		this->loadFromFile();

		return *this;

	}

};