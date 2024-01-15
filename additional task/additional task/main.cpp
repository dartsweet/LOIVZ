#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <iomanip>

using namespace std;

void reverseGraph(const vector < vector < int>>& Org, vector < vector < int>>& RevMatr) {
	int n = Org.size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// ��������� ����������� � �������
			RevMatr[i][j] = (Org[i][j] == 1) ? -1 : ((Org[i][j] == -1) ? 1 : 0);
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;
	cout << "������� ���-�� ������ �������: ";
	cin >> n;

	vector < vector < int>> Matr(n, vector<int>(n));
	vector < vector < int>> RevMatr(n, vector<int>(n, 0));

	// ������� ���������
	cout << "������� ��������� ����� " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matr[i][j] = 0;
			}
			else {
				Matr[i][j] = rand() % 2;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				Matr[i][j] = 0;
			}
			else {
				Matr[i][j] = (-1) + rand() % 3;
				Matr[j][i] = Matr[i][j];
			}
		}
	}

	// ����� �������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << std::setw(3) << Matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n";


	// ����� ������ ���������
	cout << "������ ���������:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << "������� " << i + 1 << ": ";
		for (int j = 0; j < n; ++j) {
			if (Matr[i][j] == 1) {
				cout << j + 1 << " ";
			}
		}
		cout << endl;
	}

	// ��������� �����
	reverseGraph(Matr, RevMatr);

	// ����� ������� �������
	cout << "\n������� ��������� �������:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << std::setw(3) << RevMatr[i][j] << " ";
		}
		cout << endl;
	}

	// ����� ������ ��������� �������
	cout << "\n������ ��������� �������:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << "������� " << i + 1 << ": ";
		for (int j = 0; j < n; ++j) {
			if (RevMatr[i][j] == 1) {
				cout << j + 1 << " ";
			}
		}
		cout << endl;
	}

	return 0;
}