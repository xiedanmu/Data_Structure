#include <queue>
#include<iostream>
using namespace std;

template<typename T> class CStack
{
public:
	//CStack(void);
	//~CStack(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template <typename T> void CStack<T>::appendTail(const T& element)
{
	queue1.push(element);
}

template <typename T> T CStack<T>::deleteHead()
{	
	while (queue1.size() > 1)
	{
		T& data = queue1.front();
		queue1.pop();
		queue2.push(data);
	}

	if (queue1.size() == 1)
	{
		T head = queue1.front();
		queue1.pop();
		return head;
	}	

	while (queue2.size() > 1)
	{
		T& data = queue2.front();
		queue2.pop();
		queue1.push(data);
	}

	if (queue2.size() == 1)
	{
		T head = queue2.front();
		queue2.pop();
		return head;
	}
	
	throw new exception("this stack is empty");
}

void main()
{
	CStack<int> CStack1;
	CStack1.appendTail(1);
	CStack1.appendTail(2);
	std::cout << CStack1.deleteHead() << "   " << endl;
	CStack1.appendTail(3);
	CStack1.appendTail(4);
	std::cout<<CStack1.deleteHead()<<"   "<<endl;
	std::cout << CStack1.deleteHead() << "   " << endl;
	std::cout << CStack1.deleteHead() << "   " << endl;
	std::cout << CStack1.deleteHead() << "   " << endl;

	return;
}