#include <iostream>
using namespace std;

typedef	struct arylist
{
	int value;
	bool used;
}AryList;

AryList arylist[5001];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	int m, n;
	cin >> m >> n;
	int arySize = m;

	for (int i = 1; i <= m; i++) {
		arylist[i].value = i;
		arylist[i].used = true;
	}

	int index = 0;
	int usedCount = 0;
	while (1) {
		index++;
		if (arylist[index].used) {
			usedCount++;
			if (usedCount == n) {
				if (arySize == m)
					cout << "<";

				cout << index;

				arylist[index].used = false;
				arySize--;
				usedCount = 0;

				if (arySize == 0)
					cout << ">";
				else
					cout << ", ";
			}
		}

		if (index == m) {
			index = 0;
		}
		if (arySize == 0)
			break;
	}


	return 0;
}

