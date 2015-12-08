#pragma once

#include <iostream>

using namespace std;

template <class Type>
class Tstack
{
private:
	int MaxSize;
	int Index;
	Type *mas;
public:
	Tstack(int len=10);
	~Tstack();
	Tstack(const Tstack &s);
	Tstack& operator = (const Tstack &s);
	bool IsEmpty();
	bool IsFull();
	Type Top(); //посмотреть, что наверху стека
	Type Pop(); //вытащить верхний элемент стека
	void Push(const Type a); //положить элемент а в стек;
	void clear();
};

template <class Type>
Tstack<Type>:: Tstack(int len = 10)
{
	if (len <= 0) throw len;
	MaxSize = len;
	Index = -1;
	mas = new Type[MaxSize];
}

template <class Type>
Tstack<Type>:: ~Tstack()
{
	delete[]mas;
}

template <class Type>
Tstack<Type>::Tstack(const Tstack &s)
{
	MaxSize = s.MaxSize;
	Index = s.Index;
	mas = new Type[MaxSize];
	for (int i = 0; i < Index + 1; i++)
		mas[i] = s.mas[i];
}

template <class Type>
Tstack<Type>& Tstack<Type>:: operator = (const Tstack &s)
{
	if (MaxSize != s.MaxSize)
	{
		delete[]mas;
		MaxSize = s.MaxSize;
		mas = new Type[MaxSize];
	}
	Index = s.Index;
	for (int i = 0; i < Index + 1; i++)
		mas[i] = s.mas[i];
	return (*this);
}

template <class Type>
bool Tstack<Type>::IsEmpty()
{
	bool flag = Index == -1;
	return flag;
}

template <class Type>
bool Tstack<Type>::IsFull()
{
	bool flag = Index == MaxSize - 1;
	return flag;
}

template <class Type>
Type Tstack<Type>::Top()
{
	if (Index < 0)
		throw Index;
	return mas[Index];
}

template <class Type>
Type Tstack<Type>::Pop()
{
	if (Index < 0)
	{
		cout<<"Index < 0";
		throw Index;
	}
	return mas[Index--];
}

template <class Type>
void Tstack<Type>::Push(const Type a)
{
	if (Index == MaxSize - 1)
		throw Index; //переполнение
	mas[++Index] = a;
}

template <class Type>
void Tstack<Type>:: clear()
{
	Index = -1;
}
