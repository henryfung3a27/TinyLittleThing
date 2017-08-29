// from codewars "Factorial tail" 4 kyu
// find the number of trailing zeroes of n! in base b
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
	
	int p = 0, min = INT_MAX;							// p = number of prime factors, min = return value
	int *prime = calloc(base / 2, sizeof(int));  // store the prime factors of base
	int *m = calloc(base / 2, sizeof(int));      // m[i] = no. of occurance of prime[i] in base
	int tmp = base / 2;
	
	if (is_prime(base)) {
		prime[0] = base;
		m[0] = 1;
		p = 1;
	}
	else {
		// find prime factors in base
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
	
	int sum = 0;
	
	for (int i = 0, a = 1; i < p; i++) {
	   tmp = number / (pow(prime[i], a));
		while (tmp) {
		   sum += tmp;
		   ++a;
		   tmp = number / (pow(prime[i], a));
		}
		if (sum / m[i] < min) min = sum / m[i];
		a = 1;
		sum = 0;
	}
	
	return min;
}

/***
	Thinking:
	e.g. zeroes(18, 244) i.e. 244! in base 18
	
	We need to find how many times did the base(18) appear in the number(244). Since
	not only the number 18 will produce a 0, any combination of 3*3*2 will also
	produce a 0. Hence, we need to decompose all the number in number(244) into prime
	factors, then find the number of composition of 18.
	
	1. Decompose the base(18) into prime factors (3*3*2)
	
	2. Find number of numbers in 244! which is divisible to the first prime factor (3)
		i.		244 / 3^1	= 81
		ii.	244 / 3^2	= 27
		iii.	244 / 3^3	= 9
		iv.	244 / 3^4	= 3
		v.		244 / 3^5	= 1
								------ (sum of these number)
								= 121		<- there are 121 3s in the number 244
		However, since we need TWO 3s to compose 18, we need to divide the sum by 2.
		i.e. 121 / 2 = 60
		
	3. Find number of numbers in 244! which is divisible to the second prime factor (2)
		i.		244 / 2^1	= 122
		ii.	244 / 2^2	= 61
		iii.	244 / 2^3	= 30
		iv.	244 / 2^4	= 15
		v.		244 / 2^5	= 7
		vi.	244 / 2^6	= 3
		vii.	244 / 2^7	= 1
								------ (sum of these number)
								= 239		<- there are 239 2s in the number 244
		Since we only need ONE 2 to compose 18, we do not need to divide the sum.
	
	4. Since 60 < 239, i.e. there are less 3 than 2 in 244!, we can only have SIXTY 18s, 
		i.e. we can produce SIXTY 0s only.
		
	5. Therefore, zeroes(18, 244) will return 60.
	
	NOTE: it is not a must that the larger prime has less occurance than the smaller prime
***/
