#include <iostream>
using namespace std;

class SortedArray {
	int size; // 현재 배열의 크기
	int* p; // 정수 배열에 대한 포인터
	void sort(); // 정수 배열을 오름차순으로 정렬
public:
	SortedArray() { p = NULL; size = 0; }; // p는 NULL로 size는 0으로 초기화
	SortedArray(const SortedArray& src); // 복사 생성자
	SortedArray(int p[], int size); // 생성자. 정수 배열과 크기를 전달받음
	~SortedArray() { delete []p; }
	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2); // 현재 배열에 op2 배열을 복사
	void show(); // 배열의 원소 출력
};

void SortedArray::sort()
{
	int tmp;
	for (int i = 0; i < this->size; i++){
		for (int j = 0; j < this->size - i - 1; j++) {
			if (p[j] > p[j + 1]) { 
				tmp = p[j]; 
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}

//복사 생성자
SortedArray::SortedArray(const SortedArray& src)
{
	this->size = src.size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) { this->p[i] = src.p[i]; }
	sort();
}

SortedArray::SortedArray(int p[], int size)
{
	this->size = size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) { this->p[i] = p[i]; }
	sort();
}

SortedArray SortedArray :: operator + (SortedArray& op2)
{
	SortedArray tmp;
	tmp.size = this->size + op2.size;
	tmp.p = new int[tmp.size];

	for (int i = 0; i < this->size; i++) {
		tmp.p[i] = this->p[i];
	}

	for (int i = 0; i < op2.size; i++) {
		tmp.p[i + (this->size)] = op2.p[i];
	}
	tmp.sort();
	return tmp;
}

SortedArray& SortedArray :: operator = (const SortedArray& op2)
{
	delete[]p;
	this->size = op2.size;
	this->p = new int[this->size];
	for (int i = 0; i < this->size; i++) { this->p[i] = op2.p[i]; }
	return *this;
}

void SortedArray::show()
{
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b; // +, = 연산자 작성 필요
	// + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요

	a.show();
	b.show();
	c.show();

	system("pause");
	return 0;

}