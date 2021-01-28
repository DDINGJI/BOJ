#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//2805 �����ڸ��� ������ ����
int main() {

	int k, n;
	scanf("%d%d", &k, &n);
	vector <long long> v;

	long long tmp;
	for (int i = 0; i < k; i++) {
		scanf("%lld", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	long long gaesoo;
	long long max_l = 1;

	long long low = 1;
	long long mid;
	long long high = v.back();

	//�̺�Ž������ ã�°��� �ε����� �ƴ� max_l��
	while (low <= high) {
		mid = (low + high) / 2;
		gaesoo = 0;
		for (int i = 0; i < k; i++) {
			gaesoo += v.at(i) / mid;
		}
		if (gaesoo >= n) {
			if (mid > max_l)
				max_l = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	printf("%lld", max_l);
}