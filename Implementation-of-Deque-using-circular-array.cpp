#include<iostream> 
using namespace std;
class abc
{
	int  arr[10]; int  front, rear, size;
public:
	abc(int size)
	{
		front = -1;
		rear = 0;
		this->size = size;
	}
	bool isFull()
	{
		return ((front == 0 && rear == size - 1) ||
			front == rear + 1);
	}
	bool isEmpty()
	{
		return (front == -1);
	}
	void insertfront(int key)
	{

		if (isFull())
		{
			cout << "Overflow\n" << endl;
			return;
		} 
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (front == 0) 
			front = size - 1;

		else  
			front = front - 1;  
		arr[front] = key;
	}
	void insertrear(int key)
	{
		if (isFull())
		{
			cout << " Overflow\n " << endl;
			return;
		}
		if (front == -1)
		{
			front = 0;
			rear = 0;
		} 
		else if (rear == size - 1)
			rear = 0; 
		else
			rear = rear + 1;
		arr[rear] = key;
	} 
	void deletefront()
	{ 
		if (isEmpty())
		{
			cout << "Queue Underflow\n" << endl;
			return;
		}
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else 
			if (front == size - 1)
				front = 0;

			else front = front + 1;
	}
	void deleterear()
	{
		if (isEmpty())
		{
			cout << " Underflow\n" << endl;
			return;
		} 
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if (rear == 0)
			rear = size - 1;
		else
			rear = rear - 1;
	}
	int getFront()
	{ 
		if (isEmpty())
		{
			cout << " Underflow\n" << endl;
			return -1;
		}
		return arr[front];
	} 
	int getRear()
	{ 
		if (isEmpty() || rear < 0)
		{
			cout << " Underflow\n" << endl;
			return -1;
		}
		return arr[rear];
	}
};
int main()
{
	abc deque(10);
	cout << "*********DEQUEU USING CIRCULAR ARRAY***************" << endl;
	cout << "Inserting at rear end, value =2";
	deque.insertrear(2);
	cout << "Printing rear " << " "
		<< deque.getRear() << endl;

	deque.deleterear();
	cout << "New rear" << deque.getRear() << endl;

	cout << "Inserting at front end";
	deque.insertfront(15);

	cout << "Printing front " << " "
		<< deque.getFront() << endl;
    deque.deletefront();
    cout << "New front"<< deque.getFront() << endl;
	system("pause");
}

