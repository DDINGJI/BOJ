#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main() {
	stack <char> s;
	string str;
	getline(cin, str);
	
	int ans = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == '(') {
			if (str.at(i + 1) == ')') {//��������
				if (!s.empty()) {//���ÿ� ����ִ� '(' ������ŭ �߸� ���� �þ
					ans += s.size();
					printf("---������---%d��ŭ �߰��ߴ�\n", s.size());
					printf("����� ���� : %d\n\n", ans);
				}
				else {//���߸�
					printf("---���߸��� ������---\n");
				}
				i++;
			}
			else {//����� ���� ��
				s.push('(');
				ans++;
				printf("�� �������\n����� ���� : %d\n", ans);
			}
		}
		else {// ) �ݴ� ��ȣ ����
			s.pop();// VPS�̹Ƿ� stack�� ����ִµ� ���� �� ����
			printf("\npop��\nstack ���� ( ���� : %d\n", s.size());
		}

	}
	printf("�̰ǵ�\n");
	printf("%d", ans);

}