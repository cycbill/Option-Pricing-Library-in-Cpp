#include <iostream>
#include <vector>

#include "tridiagonal_matrix_algorithm.h"

int main() {
	int N = 10;
	std::vector<double> A(N, 1.0), B(N, 1.0), C(N, 1.0), D(N, 3.0), X(N, 0.0);

	A[0] = 0.0;
	C[N - 1] = 0.0;
	D[0] = 2.0;
	D[N - 1] = 2.0;

	tridiag_mtx_algo(X.size(), A, B, C, D, X);

	for (int i = 0; i < N; i++) {
		std::cout << X[i] << std::endl;
	}
	std::cin.get();
	return 0;
}