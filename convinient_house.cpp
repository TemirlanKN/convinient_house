#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b);
int min(int a, int b);
void scan(vector<vector<int>> *houses, vector<int> *pr);
void show(vector<vector<int>> houses);
void convinient_house(vector<vector<int>> *houses, vector<int> *pr);

#define places 3 //(gym, school, store)

int main() {
	vector<vector<int>> houses;
	vector<int> pr;
	scan(&houses, &pr);
	convinient_house(&houses, &pr);
	return 0;
}

void convinient_house(vector<vector<int>> *houses, vector<int> *pr) {
	int i, j, k;
	int n = houses->size();
	int m = pr->size();
	int val;
	vector<vector<int>> ans(n);
	for (i = 0; i < n; i++) {
		ans[i].resize(places);
	}

	for (j = 0; j < m; j++) {
		k = 0;
		while (k < n && (*houses)[k][(*pr)[j]] == 0) {
			ans[k][(*pr)[j]] = n;
			k++;
		}
		for (i = k; i < n; i++) {
			if ((*houses)[i][(*pr)[j]]) {
				val = 0;
			} else {
				val++;
			}
			ans[i][(*pr)[j]] = val;
		}
		val = n;
		for (i = n - 1; i >= 0; i--) {
			if ((*houses)[i][(*pr)[j]]) {
				val = 0;
			} else {
				val++;
			}
			ans[i][(*pr)[j]] = min(ans[i][(*pr)[j]], val);
		}
	}
	int best = -1, tmp;
	val = n;

	for (i = 0; i < n; i++) {
		tmp = 0;
		for (j = 0; j < m; j++) {
			tmp = max(tmp, ans[i][ (*pr)[j] ]);
		}
		ans[i][0] = tmp;
		
		if (tmp < val) {
			best = i;
			val = tmp;
		}
	}
	//ans
	if (best == -1) {
		cout << "there is no best choise, then you need to delete places which are not placed in any houses\n";
	} else {
		cout << "{ ";
		for (i = 0; i < n; i++) {
			if (ans[i][0] == val) {
				cout << i+1 << " ";
			}
		}
		cout << "}" << " <--- best house/houses (list goes from 1 to n)\n";
	}
}

void show(vector<vector<int>> houses) {
	for (int i = 0; i < houses.size(); i++) {
		cout << i << " : ";
		for (int j = 0; j < places; j++) {
			cout << houses[i][j] << " ";
		}
		cout << endl;
	}
}

void scan(vector<vector<int>> *houses, vector<int> *pr){
	int i, j, n, m;
	do {
		cout << "Enter the number of houses (n > 0) -> ";
		cin >> n;
	} while (n <= 0);
	(*houses).resize(n);
	cout << "Enter boolen of each place every house has -> \n";
	for (i = 0; i < n; i++) {
		(*houses)[i].resize(places);
		for (j = 0; j < places; j++) {
			cin >> (*houses)[i][j];
		}
	}
	do {
		cout << "How many places do you prefer (m > 0)? -> ";
		cin >> m;
	} while (m <= 0);
	(*pr).resize(m);
	cout << "so which of them you prefer atmost (enter places 1,2,3,... ) ? -> ";
	for (i = 0; i < m; i++) {
		cin >> (*pr)[i];
		(*pr)[i]--;
	}
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}
