/*Filename: BigInteger.cpp
 *Author: Mushiyo
 */

#include <iostream>

using namespace std;

class BigInteger {
public:
	enum {
		MAX_DIGIT = 430
	}; // 72 digits ���Ӱ��a, �����ۤv�[
	void static add(char*, char*, char*);
	void static twoscom(char x[]); // �� 2's complement

	BigInteger(long x = 0) {
		char tmp[99];
		sprintf(tmp, "%Ld", x);
		setData(tmp);
	}
	BigInteger(char * x) {
		setData(x);
	} // x �O�r��
	BigInteger(char * x, int m) {
		for (int k = 0; k <= MAX_DIGIT; k++) {
			d[k] = x[k];
		}
	}
	BigInteger& operator+(BigInteger& y);
	BigInteger& operator-(BigInteger& y);
	friend istream& operator>>(istream&ii, BigInteger&x);
	friend ostream& operator<<(ostream&oo, const BigInteger&x);

private:
	char d[MAX_DIGIT + 1];
	/////////////////////// void inBigInteger(char*);
	void setData(char*); // ��Ӫ� inBigInteger � setData() �M operator>>
	//void pBigInteger(char*); // �אּ operator<<

};

BigInteger& BigInteger::operator+(BigInteger& y) {
	BigInteger *ans;
	char tmp[BigInteger::MAX_DIGIT + 1];
	//  cout << "d==" << *this << endl;
	// cout << "y==" << y << endl;
	BigInteger::add(d, y.d, tmp);
	ans = new BigInteger(tmp, 2);
	//cout << "*ans==" << *ans << endl;
	return *ans;
}

ostream& operator<<(ostream& oo, const BigInteger& x) {
	if (x.d[BigInteger::MAX_DIGIT]) { // negative number
		oo << "-"; // ���L�t����N��2's complement �A�L�X
		BigInteger::twoscom((char*) x.d); // twoscom() �O static function!
	}
	int k = BigInteger::MAX_DIGIT - 1; //�q x[71] �}�l��Ĥ@�Ӥ��O 0 �� x[k]
	while ((k > 0) && (x.d[k] == 0))
		k--; // �O�� k �ܦ��t��
	for (; k >= 0; k--)
		oo << (int) x.d[k]; // �]�O char, �ҥH�n cast
	return oo;
}

void BigInteger::add(char x[], char y[], char sum[]) {
	int k, carry, tmp;
	carry = 0; // �@�}�l�Ӧ�S�i��, �u�n x[0]+y[0]
	for (k = 0; k < MAX_DIGIT; k++) { // ���]�u�� x[71], �h�N�n��j�@�I
		tmp = x[k] + y[k] + carry; // ���Ӧ��, �å[�e�����i��
		sum[k] = tmp % 10; // ���H�Q���l�Ưd�b�Ӧ�
		carry = tmp / 10; // �Ӷi��U�@��
	}
	sum[MAX_DIGIT] = x[MAX_DIGIT] + y[MAX_DIGIT] + carry;
	sum[MAX_DIGIT] %= 2; // sign ���Ƭ���, �_�Ƭ��t, �u�d 0 �� 1
}

void BigInteger::twoscom(char x[]) // �� 2's complement
//////////////////////////////////////////////////
		{
	int k;
	if (x[MAX_DIGIT])
		x[MAX_DIGIT] = 0; // sign
	else
		x[MAX_DIGIT] = 1;
	for (k = 0; k < MAX_DIGIT; k++)
		x[k] = 9 - x[k]; //���� 1's complement
	x[0]++;
	for (k = 0; k < MAX_DIGIT; k++) {
		if (x[k] < 10)
			break; // �S�i��h����
		x[k] -= 10; // �d�U�Ӧ�, �� ..
		x[k + 1] += 1; // �i 1 ��U�@��, ���� overflow �����D
	}
}

istream& operator>>(istream&ii, BigInteger& y) {
	int k;
	char tmp[BigInteger::MAX_DIGIT + 38];
	ii.getline(tmp, BigInteger::MAX_DIGIT + 1); // read a line
	y.setData(tmp);
	return ii;
}

void BigInteger::setData(char tmp[]) {
	int k;
	int len = strlen(tmp); // strlen() in string.h
	for (k = 0; k <= MAX_DIGIT; k++)
		d[k] = 0; // assume positive 0
	char* p = tmp; //  �Y &tmp[0]
	if (tmp[0] == '+') {
		p++; // ���L����
		len--;
	}
	if (tmp[0] == '-') {
		d[MAX_DIGIT] = 1; // indicate it is a negative number
		p++;
		len--;
	}
	for (k = 0; k < len; k++) {
		d[k] = p[len - k - 1] - '0'; // ASCII ���Ʀr�ন 0..9
		if (d[k] < 0 || d[k] > 9)
			d[k] = 0; // �ݤ��������� 0
	}
	if (d[MAX_DIGIT]) {
		BigInteger::twoscom(d); // �t���� 2's complement �s
		d[MAX_DIGIT] = 1; // �T�O�O�t��, �] twoscom() �|�⥦�ܸ�
	}
}

struct BigNumber {
	int array[1000]; // �s 1000 ���
	bool sign; // ���t��
	int length; // ���
};

void print(int a[100]) {
	int i = 100 - 1;
	while (i >= 0 && a[i] == 0)
		i--;
	if (i < 0)
		cout << '0';
	else
		while (i >= 0)
			cout << a[i--];
}

bool largerthan(int a[100], int b[100]) {
	for (int i = 100 - 1; i >= 0; i--)
		if (a[i] != b[i])
			return a[i] > b[i];
	return false;
}

void add(int a[100], int b[100], int c[100]) {
	for (int i = 0; i < 100; i++) // ��������Ƭۥ[
		c[i] = a[i] + b[i];
	for (int i = 0; i < 100 - 1; i++) // �@�f��i��
			{
		c[i + 1] += c[i] / 10; // �i��
		c[i] %= 10; // �i���l�U����
	}
}

void sub(int a[100], int b[100], int c[100]) {
	for (int i = 0; i < 100; i++)
		c[i] = a[i] - b[i];
	for (int i = 0; i < 100 - 1; i++) // �@�f��ɦ�M�ɦ�
		if (c[i] < 0) {
			c[i + 1]--; // �ɦ�
			c[i] += 10; // �ɦ�
		}
}

void mul(int a[100], int b[100], int c[100]) {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (i + j < 100)
				c[i + j] = a[i] * b[j];
	for (int i = 0; i < 100 - 1; i++) // �@�f��i��
			{
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
}

void div(int a[100], int b[100], int c[100]) {
	int t[100];
	for (int i = 100 - 1; i >= 0; i--)
		for (int k = 9; k > 0; k--) // ���հӼ�
				{
			mul(b + i, k, t);
			if (largerthan(a + i, t)) {
				sub(a + i, t, c + i);
				break;
			}
		}
}

int main() {


	return 0;
}
