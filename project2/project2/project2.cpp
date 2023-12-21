#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace chrono;
void bubblesort(int* arr, int n)
{
	int g;
	g = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n - j; i++) {
			if (arr[i] < arr[i - 1]) {
				g = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = g;
			}
		}
	}
}
void snakersort(int* B, int end2)
{
	bool swapped = true;
	int start2 = 0;
	while (swapped) {
		swapped = false;
		for (int i = start2; i < end2; ++i) {
			if (B[i] > B[i + 1]) {
				swap(B[i], B[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
		swapped = false;
		--end2;
		for (int i = end2 - 1; i >= start2; --i) {
			if (B[i] > B[i + 1]) {
				swap(B[i], B[i + 1]);
				swapped = true;
			}
		}
		++start2;
	}
}
void combsort(int* B, int massivelen)
{
	float k = 1.247;
	float S = massivelen - 1;
	int count = 0;
	while (S >= 1)
	{
		for (int i = 0; i + S < massivelen; i++)
		{
			if (B[i] > B[int(i + S)])
			{
				swap(B[int(i + S)], B[i]);
			}
		}
		S /= k;
	}
	while (true)
	{
		for (int i = 0; i < massivelen - 1; i++)
		{
			if (B[i] > B[i + 1])
			{
				swap(B[i + 1], B[i]);
			}
			else count++;
		}
		if (count == massivelen - 1)
			break;
		else
			count = 0;
	}
}
void insertsort(int* B, int massivelen)
{
	int key;
	int j;
	for (int i = 1; i < massivelen; i++) {
		key = B[i];
		j = i - 1;
		while (j >= 0 && B[j] > key) {
			B[j + 1] = B[j];
			j = j - 1;
		}
		B[j + 1] = key;
	}
}
void quicksort(int* arr, int  end, int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l)
	{
		while (arr[f] < mid)
			f++;
		while (arr[l] > mid)
			l--;
		if (f <= l)
		{
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l)
		quicksort(arr, l, begin);
	if (f < end)
		quicksort(arr, end, f);
}
int binarySearch(int arr[], int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}

		return binarySearch(arr, value, mid + 1, end);
	}

	return -1;
}
int main()
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	while (true) {
		int a;
		int b;
		int f;
		int count;
		int middle;
		short int maxim;
		short int minim;
		const int massivelen = 100;
		short int number;
		bool _continue;
		int index[massivelen];
		int A[massivelen];
		int B[massivelen];
		srand(time(0));
		for (int i = 0; i < massivelen; i++) {
			A[i]=(rand() % 199)-99;
		}
		while (true) {
			cout << "IDZ 9? (1 - yes, 0 - no)" << endl;
			if (!(cin >> number && number >= 0 && number <= 1))
			{
				cout << "error, you have run out of limits" << endl;
				return -1;
			}
			if (number == 1) {
				while (true) {
					srand(time(0));
					cout << "Print your number" << endl;
					if (!(cin >> a && a >= -238609195 && a <= 238609195))
					{
						cout << "error, you have run out of limits" << endl;
						return -1;
					}
					for (int i = 0; i < massivelen; i++) {
						if (A[i] % 2 == 1) {
							A[i] -= a;
							if (A[i] % 2 == 1)
								A[i] *= ((rand() % 9) + 1);
						}

					}
					count = 0;
					cout << "Amount of elements, that devides on numbers:" << endl;
					for (int i = 1; i < 10; i++) {
						for (int j = 0; j < massivelen; j++) {
							if (A[j] % i == 0)
								count++;
						}
						cout << i << " - " << count << " elements" << endl;
						count = 0;
					}
					cout << "Do you want to repeat (1 - yes, 0 - no)" << endl;
					if (!(cin >> number && number >= 0 && number <= 1))
					{
						cout << "error, you have run out of limits" << endl;
						return -1;
					}
					if (number == 0)
						break;
				}
			}
			for (int i = 0; i < massivelen; i++) {
				B[i] = A[i];
			}
			cout << "Please, print what type of sort you want to use " << endl << "1 - bubble sort" << endl << "2 - snaker sort" << endl << "3 - comb sort" << endl << "4 - insert sort" << endl << "5 - quick sort" << endl << "0 - close programm" << endl;
			if (!(cin >> number && number >= 0 && number <= 5))
			{
				cout << "error, you have run out of limits" << endl;
				return -1;
			}
			switch (number)
			{
			case 0:
				break;
			case 1:
				start = steady_clock::now();
				bubblesort(B, massivelen);
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				cout << "it has taken "<< result.count()<< " nanoseonds" << endl;
				break;
			case 2:
				start = steady_clock::now();
				snakersort(B, massivelen - 1);
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				cout << "it has taken " << result.count() << " nanoseonds" << endl;
				break;
			case 3:
				start = steady_clock::now();
				combsort(B, massivelen);
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				cout << "it has taken " << result.count() << " nanoseonds" << endl;
				break;
			case 4:
				start = steady_clock::now();
				insertsort(B, massivelen);
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				cout << "it has taken " << result.count() << " nanoseonds" << endl;
				break;
			case 5:
				start = steady_clock::now();
				quicksort(B, massivelen-1, 0);
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				cout << "it has taken " << result.count() << " nanoseonds" << endl;
				break;
			}
			if (number == 0)
				break;
			cout << "Do you want to try another sort? (1 - yes, 0 - no)" << endl;
			if (!(cin >> _continue && _continue >= 0 && _continue <= 1))
			{
				cout << "error, you have run out of limits" << endl;
				return -1;
			}
			if (_continue == false)
				break;
			else {
				cout << "Do you want to create new massive? (1 - yes, 0 - no)" << endl;
				if (!(cin >> _continue && _continue >= 0 && _continue <= 1))
				{
					cout << "error, you have run out of limits" << endl;
					return -1;
				}
				if (_continue == true) {
					for (int i = 0; i < massivelen; i++) {
						A[i] = (rand() % 198) - 99;
					}
				}
			}
		}
		if (number == 0)
			break;
		while (true) {
			cout << "What do you want to do with this massive?" << endl << "1 - find max and min" << endl << "2 - average value of max and min " << endl << "3 - amount of elements less than a" << endl << "4 - amount of elements more than b" << endl << "5 - find exact number" << endl << "6 - switch 2 elements" << endl << "0 - exit" << endl;
			if (!(cin >> number && number >= 0 && number <= 6))
			{
				cout << "error, you have run out of limits" << endl;
				return -1;
			}
			if (number == 0)
				break;
			switch (number)
			{
			case 1:
				start = steady_clock::now();
				minim = B[0];
				maxim = B[massivelen - 1];
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				cout << "it has taken " << result.count() << " nanoseonds to find max and min in sorted massive" << endl << "max = " << maxim << " min = " << minim << endl;
				start = steady_clock::now();
				minim = A[1];
				maxim = A[0];
				if (A[0] < A[1]) {
					minim = A[0];
					maxim = A[1];
				}
				for (int i = 2; i < massivelen; i++) {
					if (minim > A[i])
						minim = A[i];
					if (maxim < A[i])
						maxim = A[i];
				}
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				cout << "it has taken " << result.count() << " nanoseonds to find max and min in unsorted massive" << endl << "max = " << maxim << " min = " << minim << endl;
				break;
			case 2:
				for (int i = 0; i < massivelen; i++) {
					index[i] = 0;
				}
				start = steady_clock::now();
				minim = B[0];
				maxim = B[massivelen - 1];
				if ((maxim + minim) % 2 == 0)
					middle = (maxim + minim) / 2;
				else
					middle = (maxim + minim + 1) / 2;
				count = 0;
				for (int i = 0; i < massivelen; i++) {
					if (B[i] == middle) {
						index[count] = i;
						count++;
					}
					if (B[i] > middle)
						break;
				}
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				cout << "it has taken " << result.count() << " nanoseonds to find average value of max and min in sorted massive" << endl << "average value = " << middle << endl << "index:" << endl;
				if (count > 0) {
					for (int i = 0; i < count; i++) {
						cout << index[i] << endl;
					}
				}
				else
					cout << "NONE" << endl;
				cout << "count = " << count << endl;

				for (int i = 0; i < massivelen; i++) {
					index[i] = 0;
				}
				minim = 0;
				maxim = 0;
				middle = 0;
				start = steady_clock::now();
				minim = A[1];
				maxim = A[0];
				if (A[0] < A[1]) {
					minim = A[0];
					maxim = A[1];
				}
				for (int i = 2; i < massivelen; i++) {
					if (minim > A[i])
						minim = A[i];
					if (maxim < A[i])
						maxim = A[i];
				}
				if ((maxim + minim) % 2 == 0)
					middle = (maxim + minim) / 2;
				else
					middle = (maxim + minim + 1) / 2;
				count = 0;
				for (int i = 0; i < massivelen; i++) {
					if (A[i] == middle) {
						index[count] = i;
						count++;
					}
				}
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				cout << "it has taken " << result.count() << " nanoseonds to find average value of max and min in unsorted massive" << endl << "average value = " << middle << endl << "index:" << endl;
				if (count > 0) {
					for (int i = 0; i < count; i++) {
						cout << index[i] << endl;
					}
				}
				else
					cout << "NONE" << endl;
				cout << "count = " << count << endl;
				break;
			case 3:
				cout << "Print your number" << endl;
				if (!(cin >> a && a >= -2147483648 && a <= 2147483648))
				{
					cout << "error, you have run out of limits" << endl;
					return -1;
				}
				for (int i = 0; i < massivelen; i++) {
					if (B[i] >= a) {
						count = i;
						break;
					}
				}
				cout << count << " elements are lower than " << a << endl;
				break;
			case 4:
				cout << "Print your number" << endl;
				if (!(cin >> b && b >= -2147483648 && b <= 2147483648))
				{
					cout << "error, you have run out of limits" << endl;
					return -1;
				}
				for (int i = 0; i < massivelen; i++) {
					if (B[massivelen - i - 1] <= b) {
						count = i;
						break;
					}
				}
				cout << count << " elements are highter than " << b << endl;
				break;
			case 5:
				cout << "Print number that you want to find" << endl;
				if (!(cin >> a && a >= -2147483648 && a <= 2147483648))
				{
					cout << "error, you have run out of limits" << endl;
					return -1;
				}
				start = steady_clock::now();
				if (binarySearch(B, a, 0, massivelen - 1) < 0)
					cout << "This massive do not has a number " << a << "(by binary)" << endl;
				else
					cout << "This massive has a number " << a << "(by binary)" << endl;
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				b = result.count();
				start = steady_clock::now();
				f = 0;
				for (int i = 0; i < massivelen; i++) {
					if (B[i] == a) {
						f = 1;
						break;
					}
					if (B[i] > a)
						break;
				}
				if (f == 0)
					cout << "This massive do not has a number " << a << "(without binary)" << endl;
				else
					cout << "This massive has a number " << a << "(without binary)" << endl;
				end = steady_clock::now();
				result = duration_cast<nanoseconds>(end - start);
				f = result.count();
				cout << "it has taken " << b << " nanoseonds to find your number in massive by using binary search and " << f << " nanoseconds to find without binary search" << endl;
				if (b < f)
					cout << "binary search was faster on " << f - b << " nanoseconds" << endl;
				if (b == f)
					cout << "both types of search was taken one time" << endl;
				if (b > f)
					cout << "binary search was slower on " << b - f << " nanoseconds" << endl;
				break;
			case 6:
				cout << "Print first index of number that you want to switch from 0 to 99" << endl;
				if (!(cin >> a && a >= 0 && a <= 99))
				{
					cout << "error, you have run out of limits" << endl;
					return -1;
				}
				cout << "Print second index of number that you want to switch from 0 to 99" << endl;
				if (!(cin >> b && b >= 0 && b <= 99))
				{
					cout << "error, you have run out of limits" << endl;
					return -1;
				}
				if (a == b)
					cout << "error, your the first index is equals to the second";
				else {
					start = steady_clock::now();
					f = A[a];
					A[a] = A[b];
					A[b] = f;
					end = steady_clock::now();
					result = duration_cast<nanoseconds>(end - start);
				}
				cout << "it has taken " << result.count() << " nanoseonds" << endl;
				break;

			}
			cout << "Do you want to do something else with this massive? (1 - yes, 0 - no)" << endl;
			if (!(cin >> _continue && _continue >= 0 && _continue <= 1))
			{
				cout << "error, you have run out of limits" << endl;
				return -1;
			}
			if (_continue == false)
				break;
		}
		cout << "Do you want to create new massive? (1 - yes, 0 - close programm)" << endl;
		if (!(cin >> _continue && _continue >= 0 && _continue <= 1))
		{
			cout << "error, you have run out of limits" << endl;
			return -1;
		}
		if (_continue == false)
			break;
	}
	return 0;
}


