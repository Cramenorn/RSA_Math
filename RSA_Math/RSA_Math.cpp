#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

using namespace std;

int main()
{
	cout << "\nEnter the first prime number: ";
	cin >> p;
	flag = prime(p);
	if (flag == 0)
	{
		cout << "\nWrong Input, you must enter a prime number\n";
		exit(1);
	}

	cout << "\nEnter the second prime number: ";
	cin >> q;
	flag = prime(q);
	if (flag == 0)
	{
		cout << "\nWrong Input, you must enter a prime number\n";
		exit(1);
	}

	/*
	Once you have entered the prime numbers, they will be moltiplicated to find n, which is the first part of the public key.
	To do that you just need to do a moltiplication between p and q
	*/

	n = p * q; //public key part 1
	cout << "The compute of n is: " << n << endl;

	/*
	Now you need to find lambda, to do that you must compute the totient of the product.
	In number theory, Euler's totient function counts the positive integers up to a given integer n that are relatively prime to n
	For example, the totatives of n = 9 are the six numbers 1, 2, 4, 5, 7 and 8
	*/

	lambda = lcm(p - 1, q - 1);
	cout << "The lambda value is: " << lambda << endl;

	/*
	Choose any number 1 < e < lambda that is coprime to lambda.
	You must choose a number (e) that is not a divisor of lambda
	*/

	cout << "\nChoose a coprime number < " << lambda << ": ";
	cin >> e; //public key part 2

	if (e > lambda) {
		cout << "Wrong Input, you must choose a prime number < " << lambda << endl;
		exit(1);
	}

	flag = prime(e);
	if (flag == 0)
	{
		cout << "\nWRONG INPUT\n";
		exit(1);
	}

	/*
	The last thing to do is find d, which is the private key.
	You must use the modulo Inverse and give to the modInverse method e and lambda
	*/

	d = modInverse(e, lambda);
	cout << "The compute of d is: " << d << endl << endl;

	cout << "Enter a number to encrypt: ";
	cin >> message;

	encryptResult = moduloPow(message, e, n);
	cout << "The encrypt number is: " << encryptResult << endl;

	decryptResult = moduloPow(encryptResult, d, n);
	cout << "The decrypt number is: " << decryptResult << endl;

	cout << "Thanks for use our RSA program." << endl;
	return 0;
}

