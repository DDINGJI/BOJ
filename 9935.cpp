#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string boom;
	string ans;

	getline(cin, str);
	getline(cin, boom);

	int str_l = str.length();
	int boom_l = boom.length();

	char in;
	char b_last = boom.at(boom_l - 1);
	int isboom;
	int idx = 0;

	for (int i = 0; i < str_l; i++) {

		in = str.at(i);
		ans.append(1, in);

		//���� �༮�� ��ź�� ������ �༮
		if (in == b_last) {

			int k = 0;
			//��ź���� Ȯ��
			for (int j = 0; j < boom_l; j++) {

				//cout <<"������ : "<< ans << endl << endl;
				//printf("-----\ni : %d\nj : %d\nidx : %d\n", i, j, idx);

				//�ε���(idx) ���� ��� -> �ϴ� ��ź�� �ƴ�
				if (idx - j < 0) {
					isboom = 0;
					//cout << "2 : " << ans << endl << endl;
					break;
				}//��ź Ȯ���ϴ� �κ�(�պκ� ���ڿ����� Ȯ��)
				else  if (ans.at(idx - j) == boom.at(boom_l - 1 - j)) k++;

				//printf("ans[%d]�� boom[%d]�� ���ߴ�\n", idx - j, boom_l - 1 - j);
				//printf("k : %d\n-----\n", k);

				//��ź�̴� �ƴϴ� �ǰ� ����
				if (k == boom_l) isboom = 1;
				else isboom = 0;
			}

			//cout << "Ȯ�� �� ������ ��~" << endl << endl;
			//��ź�� �����Ƿ� boom ���ڿ� ���̸�ŭ ���ÿ��� ���ش�
			if (isboom) {
				for (int k = 0; k < boom_l; k++)
					ans.pop_back();

				idx -= boom_l;
			}


			//cout << "���ֵ簡 ���簡 �� : " << ans << endl << endl;
		}

		idx++;
	}
	if (ans.empty()) printf("FRULA");
	else cout << ans;
}