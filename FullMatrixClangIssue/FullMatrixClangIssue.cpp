// FullMatrixClangIssue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FullMatrix.h"

using namespace MbD;
void runFullMat();

int main()
{
	runFullMat();
}
void runFullMat() {
	auto fullMat = std::make_shared<FullMatrix<double>>(3, 3);
	fullMat->atijput(0, 0, 1.0);
	fullMat->atijput(0, 1, 1.0);
	fullMat->atijput(1, 0, 1.0);
	fullMat->atijput(1, 1, 1.0);
	fullMat->atijput(1, 2, 1.0);
	fullMat->atijput(2, 1, 1.0);
	fullMat->atijput(2, 2, 1.0);
	auto fullCol = std::make_shared<MbD::FullColumn<double>>(3);
	fullCol->atiput(0, 1.0);
	fullCol->atiput(1, 2.0);
	fullCol->atiput(2, 3.0);
	auto col = fullMat->timesFullColumn(fullCol);
	std::cout << *col;
}
