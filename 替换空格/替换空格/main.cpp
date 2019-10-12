#include <iostream>
#include <string>

void ReplaceSpace(std::string& str) {
	//���м����ո�
	int spacenum = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ' ') {
			++spacenum;
		}
	}
	int p1 = str.size() - 1;

	//���ַ������ݵ��滻��Ĵ�С
	str.resize(str.size() + 2 * spacenum);
	int p2 = str.size() - 1;

	//�滻
	while (p1 >= 0 && p1 < p2) {
		if (str[p1] == ' ') {
			str[p2--] = '0';
			str[p2--] = '2';
			str[p2--] = '%';
		}
		else {
			str[p2--] = str[p1];
		}
		--p1; 
	}
}

int main() {
	std::string str;
	while (getline(std::cin, str)) {
		ReplaceSpace(str);
		std::cout << str << std::endl;
	}
	return 0;
}