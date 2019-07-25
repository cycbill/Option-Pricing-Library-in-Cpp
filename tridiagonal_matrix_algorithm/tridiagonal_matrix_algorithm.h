#pragma once

#include <vector>

void tridiag_mtx_algo(size_t N,
	std::vector<double>& A,
	std::vector<double> B,
	std::vector<double>& C,
	std::vector<double> D,
	std::vector<double>& X)
	/*
	{
		double W;

		for (int i = 1; i < N; i++) {
			W = A[i] / B[i - 1];
			B[i] = B[i] - W * C[i - 1];
			D[i] = D[i] - W * D[i - 1];
		}

		X[N - 1] = D[N - 1] / B[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			X[i] = (D[i] - C[i] * X[i + 1]) / B[i];
		}

		return;
	}
	*/
{
	std::vector<double> C_prime(N, 0.0), D_prime(N, 0.0);

	C_prime[0] = C[0] / B[0];
	D_prime[0] = D[0] / B[0];
	for (int i = 1; i < N; i++) {
		C_prime[i] = C[i] / (B[i] - A[i] * C_prime[i - 1]);
		D_prime[i] = (D[i] - A[i] * D_prime[i-1]) / (B[i] - A[i] * C_prime[i-1]);
	}

	X[N - 1] = D_prime[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		X[i] = D_prime[i] - C_prime[i] * X[i + 1];
	}
	
	return;
}