#include <iostream>
#include <string>

using namespace std;

class Base{
	public:
		Base(int a = 0): m_a(a){ }
		int get_a() const{ return m_a; }
		virtual void func() const { }
	protected:
		int m_a;
};
class Derived: public Base{
	public:
		Derived(int a = 0, int b = 0): Base(a), m_b(b){ }
		int get_b() const { return m_b; }
	private:
		int m_b;
};

class Error
{};

int main()
{
	Derived *pd1 = new Derived(35, 78);
	Base *pb1 = dynamic_cast<Derived*>(pd1);
	cout<<"pd1 = "<<pd1<<", pb1 = "<<pb1<<endl;
	cout<<pb1->get_a()<<endl;
	pb1->func();
	Base *base = new Derived(35, 78);
	cout << typeid(*base).name() << endl;

	Derived *der = dynamic_cast<Derived*>(base);
	/* 错误
	Error *pd2 = new Error();
	pb1 = dynamic_cast<Derived*>(pd2);
	pb1->func();
	*/
	return 0;
}

