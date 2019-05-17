#define _CRT_SECURE_NO_WARNINGS
#pragma once
using namespace std;
#include <iostream>
#include <string>

void findMajority(int arr[], int n);
void KMPSearch(char* pat, char* txt);
void computeLPSArray(char* pat, int M, int* lps);
int min(int x, int y);
int Jump(int *arr, int n);

void findMajority(int arr[], int n)
{
	int maxCount = 0;
	int index = -1; // sentinels 
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i] == arr[j])
				count++;
		}

		// update maxCount if count of  
		// current element is greater 
		if (count > maxCount)
		{
			maxCount = count;
			index = i;
		}
	}

	// if maxCount is greater than n/2  
	// return the corresponding element  
	if (maxCount > n / 2)
		cout << arr[index] << endl;

	else
		cout << "No Majority Element" << endl;
}

void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int *lps = (int*) calloc(M,sizeof(int));

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix 
	int len = 0;

	lps[0] = 0; // lps[0] is always 0 

				// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len]) 
		{
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment 
				// i here 
			}
			else // if (len == 0) 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int min(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int Jump(int *arr, int n)
{
	if (n <2) 
		return arr[n];
	else
		return(min(Jump(arr, n - 1), Jump(arr, n - 2)) + arr[n]);
}

int main()
{
	//int arr[] = {1, 1, 2, 1, 3, 5, 1}; 
	//int n = sizeof(arr) / sizeof(arr[0]);
	//findMajority(arr,n) // find majorty number, if exsist more then n/2 times at given array

	//char txt[] = "ABABDABACDABABCABAB";
	//char pat[] = "ABABCABAB";
	//KMPSearch(pat, txt);

	//int arr[] = {0,1,2,3,4,5}
	//int n = sizeof(arr) / sizeof(arr[0]);
	// cout << Jump(arr,n) << endl

	// char pat[] = "ABABABABABA";
	// int M = strlen(pat);
	// int *lps = (int*) calloc(M,sizeof(int));
	//void computeLPSArray(char* pat, int M, int* lps)
	
	cout << "Press enter to continue..." << endl;
	getchar();
	return 1;
}