#include <iostream>
#include <vector>

#include "tridiagonal_matrix_algorithm.h"

int main() {
	int N = 6;
	std::vector<double> A(N, 1.0), B(N, 2.0), C(N, 1.0), X(N, 0.0);
	std::vector<double> D {4.0, 8.0, 12.0, 16.0, 21.0, 19.0};

	A[0] = 0.0;
	C[N - 1] = 0.0;

	tridiag_mtx_algo(X.size(), A, B, C, D, X);

	for (int i = 0; i < N; i++) {
		std::cout << X[i] << std::endl;
	}
	std::cin.get();
	return 0;
}