#include<iostream>
using namespace std;
#define n 10
template<class t>
class queue
{
	t* arr;
	int front;
	int back;
public:
	queue()
	{
		arr = new int[n];
		front = -1;
		back = -1;
	}
	void enqueue(t val)
	{
		if (front == -1)
		{
			front++;
			back++;
			arr[back] = val;
			return;
		}
		if (back < n)
		{
			back++;
			arr[back] = val;
			return;
		}
		else
			cout << "Queue Overflow" << endl;

	}
	void dequeue()
	{
		if (front == -1 || front > back)
		{
			cout << "No elements in the queue" << endl;
		}
		front++;
	}
	void print()
	{
		for (int i = front; i <= back; i++)
		{
			cout << arr[i]<<" ";
		}
	}
	int size()
	{
		if(back!=-1)
		return (back -front)+ 1;
	}
	bool isempty()
	{
		if (front == -1 || front > back)
			return true;
		return false;
	}
	bool Front(t& val)
	{
		if (front == -1 || front > back)
			return false;
		else
			val=arr[front];
	}
};
int main()
{
	queue<int> a,b;
	a.enqueue(5);
	a.enqueue(6);
	a.enqueue(7);
	a.dequeue();
	a.print();
	cout << a.size();
	if (b.isempty())
		cout << "empty";
	else
		cout << "not empty";
	int val;
	a.Front(val);
	cout << val;
}