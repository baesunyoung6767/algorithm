#include <iostream>

using namespace std;

long long pow(int A, int B, int C) {
	if (B == 1)
		return A;
	else
	{
		long long temp = pow(A, B / 2, C);
		if (B % 2)
			return ((temp * temp) % C * A) % C;
		else
			return (temp * temp) % C;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;
	cout << pow(A % C, B, C) << "\n";
	return 0;
}