// from codewars "Factorial tail" 4 kyu
// find the number of trailing zeroes of n in base b
// e.g. zeroes(12, 26) should return 10
// note: the number n is of base 10
// e.g. for zeroes(16, 17), it is actually calculating (0x11)!

#include <math.h>
#include <stdlib.h>
#include <limits.h>

int is_prime(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (!(n % 2)) return 0;
	for (int i = 3; i <= sqrt(n); i+=2)
	   if (n % i == 0) return 0;
	return 1;
}

int zeroes (int base, int number) {
	if (base < 2 || number < 1) return 0;
	
	int p = 0, min = INT_MAX;
	int *prime = calloc(base / 2, sizeof(int));  // store the prime factors of base
	int *m = calloc(base / 2, sizeof(int));      // m[i] = no. of occurance of prime[i] in base
	int tmp = base / 2;
	
	if (is_prime(base)) {
		prime[0] = base;
		m[0] = 1;
		p = 1;
	}
	else {
		// search for prime factors in base
		while (tmp > 1) {
		   if (is_prime(tmp) && (base % tmp == 0)) {
		      prime[p] = tmp;
		      ++p;        // no. of prime factors in base
		   }
			--tmp;
		}
	
	   // calculate the no. of occurance of each prime[i]
	   for (int i = 0; i < p; i++) {
	      tmp = base;
	      while (tmp) {
	         if (tmp % prime[i] == 0) {
	            ++m[i];
	            tmp /= prime[i];
	         }
	         else break;
	      }
	   }
	}
	
	int ret = 0;
	
	for (int i = 0, a = 1; i < p; i++) {
	   tmp = number / (pow(prime[i], a));
		while (tmp) {
		   ret += tmp;
		   ++a;
		   tmp = number / (pow(prime[i], a));
		}
		if (ret / m[i] < min) min = ret / m[i];
		a = 1;
		ret = 0;
	}
	
	return min;
}
