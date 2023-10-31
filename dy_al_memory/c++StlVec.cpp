#include <iostream>
#include <vector>

int main()
{
	int a, b;

	std::cout << "행의 크기를 입력하세요 : ";
	std::cin >> a;
	std::cout << "열의 크기를 입력하세요 : ";
	std::cin >> b;

	std::vector<std::vector<int>> mx_1(a, std::vector<int>(b));	
	std::vector<std::vector<int>> mx_2(a, std::vector<int>(b));	
	std::vector<std::vector<int>> mx_sum(a, std::vector<int>(b));

	std::cout << "첫번째 행렬의 수를 입력하세요:\n";
	for (int i = 0; i < a; i ++){
		for (int j =0; j < b; j++){
			std::cin >> mx_1[i][j];
		}
	}

	std::cout << "첫번째 행렬의 수를 입력하세요:\n";
	for (int i = 0; i < a; i ++){
		for (int j =0; j < b; j++){
			std::cin >> mx_2[i][j];
		}
	}
	
	for(int i = 0; i < a; i ++){
		std::cout << "\n";
		for (int j = 0; j < b; j++){
			mx_sum[i][j] = mx_1[i][j]+mx_2[i][j];
			std::cout << mx_sum[i][j] << " ";

		}
	}
	std::cout << "\n";
	return 0;

}

