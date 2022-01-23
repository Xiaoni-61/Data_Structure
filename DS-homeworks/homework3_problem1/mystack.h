#pragma once
#pragma once

template <typename T>
class Stack {

public:

	void clear();
	bool push(const T item);
	bool pop(T& item);
	bool top(T& item);
	bool isEmpty();
	bool isFull();
};

template< typename T >
class mystack :public Stack<T>
{

public:
	int m_size;
	int m_top;
	T *m_stack;

	mystack(int size) {
		this->m_size = size;
		this->m_top = -1;
		m_stack = new T[m_size];
	}


	mystack()
	{
		this->m_size = 0;
		this->m_top = -1;
		m_stack = new T[0];
	}


	~mystack()
	{
		delete[] m_stack;
	}


	void clear() {
		this->m_top = -1;
	}


	bool push(T item) {
		if (this->isFull()) {
			T *newMystack = new T[this->m_size * 2 + 1];
			for (int i = 0; i <= this->m_size; i++) {
				newMystack[i] = m_stack[i];
			}
			delete[]m_stack;
			m_stack = newMystack;

			this->m_size = this->m_size * 2 + 1;
		}

		this->m_top++;
		m_stack[m_top] = item;
		this->m_size++;

		return true;
	}




	bool pop(T &item) {

		if (m_top == -1) {
			//std::cout << "stack is empty, no item can be opped!" << std::endl;
			return false;
		}

		item = this->m_stack[this->m_top];
		this->m_top--;
		return true;
	}


	bool top(T &item) {

		/*
		*/
		if (m_top == -1) {
			//std::cout << "stack is empty, no item can be opped!" << std::endl;
			return false;
		}
		else
		{
			item = m_stack[this->m_top];
		}

	}


	bool isEmpty() {
		if (m_top == -1)
			return true;
		else
			return false;
	}




	bool isFull() {
		if (this->m_size == (this->m_top + 1))
			return 1;
		else
			return 0;
	}

	int pri(char s) {
		int a;
		switch (s)
		{
		case '(':a = 1; break;
		case '+':a = 2; break;
		case '-':a = 2; break;
		case '*':a = 3; break;
		case '/':a = 3; break;
		case ')':a = 4; break;
		default:
			a = 0;
			break;
		}
		return a;
	}
};