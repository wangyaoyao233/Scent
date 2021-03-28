#pragma once
#include <iostream>


class SparseArray
{
public:
	void Test()
	{
		int arr[11][11] = {};
		arr[1][2] = 1;
		arr[2][3] = 2;

		//show arr
		printf("origin arr:\n");
		for (int i = 0; i < 11; i++){
			for (int j = 0; j < 11; j++){
				printf("%d  ", arr[i][j]);
			}
			printf("\n");
		}

		//arr => SparseArr
		//1. 获取原数组非0的个数
		int cnt = 0;
		for (int i = 0; i < 11; i++){
			for (int j = 0; j < 11; j++){
				if (arr[i][j] != 0) {
					cnt++;
				}
			}
		}

		//2. 根据cnt建立SparseArr第一行
		auto sparseArr = new int[cnt + 1][3];
		sparseArr[0][0] = 11;
		sparseArr[0][1] = 11;
		sparseArr[0][2] = cnt;

		//3. 建立SparseArr其他行
		int value = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				if (arr[i][j] != 0) {
					value++;
					sparseArr[value][0] = i;
					sparseArr[value][1] = j;
					sparseArr[value][2] = arr[i][j];
				}
			}
		}

		printf("SparseArray:\n");
		for (int i = 0; i < cnt + 1; i++) {
			printf("%2d %2d %2d\n", sparseArr[i][0], sparseArr[i][1], sparseArr[i][2]);
		}
		

		// SparseArr => arr
		//1. 根据SparseArr第一行创建数组
		const int row = sparseArr[0][0];
		const int col = sparseArr[0][1];
		const int c = sparseArr[0][2];

		int** arr2 = new int* [row];
		for (int i = 0; i < row; i++) {
			arr2[i] = new int[col] {};
		}

		//2. 填入其他行
		for (int i = 1; i < c + 1; i++) {
			arr2[sparseArr[i][0]][sparseArr[i][1]] = sparseArr[i][2];
		}
		

		printf("orgin arr:\n");
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				printf("%d  ", arr2[i][j]);
			}
			printf("\n");
		}

		delete[] sparseArr;
		delete[] arr2;
	}

};



