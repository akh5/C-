#include <iostream>
using namespace std;

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

class Derived : public Base
{};

int main()
{
	// ������֤�������ཫ�����еĳ�Ա�����̳е�������
	cout << sizeof(Derived) << endl;

	// ��֤�������еĳ�Ա�����ͷű�����̳�
	Derived d;
	d.SetBase(10, 20, 30);
	d.PrintBase();
	return 0;
}
#endif

#if 0
// public�̳з�ʽ��

class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

// �̳�Ȩ��--public
// ������public/protected�ĳ�Ա��������Ȩ�޲���
// ������private�ĳ�Ա�������в��ɼ�(������---�ó�Ա����ȷʵ�Ѿ��̳е�������)
class Derived : public Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // ���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	}

	// ����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		_pro = 10;
	}
};

int main()
{
	Derived d;
	cout << sizeof(d) << endl;

	d._pub = 10;
	// d._pro = 10;
	return 0;
}
#endif


#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};


// �̳з�ʽ--protected
// ������public�ĳ�Ա�������з���Ȩ���Ѿ����protected
// ������protected�ĳ�Ա�������з���Ȩ�޲���
// ������private�ĳ�Ա�������в��ɼ�(������---�ó�Ա����ȷʵ�Ѿ��̳е�������)
class Derived : protected Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // ���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	}

	// ����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		_pub = 10;
		_pro = 20;
	}
};

int main()
{
	Derived d;
	// d._pub = 10;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};


// �̳з�ʽ--private
// ������public�ĳ�Ա�������з���Ȩ���Ѿ����private
// ������protected�ĳ�Ա�������з���Ȩ���Ѿ����private
// ������private�ĳ�Ա�������в��ɼ�(������---�ó�Ա����ȷʵ�Ѿ��̳е�������)
class Derived : private Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // ���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	}

	// ����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		// _pub = 10;
		//_pro = 20;
	}
};

int main()
{
	Derived d;
	 d._pub = 10;
	return 0;
}
#endif


#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

 
// class �� struct��Ĭ�ϼ̳�Ȩ��
// classĬ�ϼ̳�Ȩ��---priavet
// structĬ�ϼ̳�Ȩ��---public
struct Derived : Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // ���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	}

public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		_pub = 10;
	}
};

int main()
{
	D d;
	d._pub = 10;
	return 0;
}
#endif

#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}

protected:
	int _b;
};

class D : public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
		_d = d;
	}

//protected:
	int _d;
};

// ��ֵ���ݹ���ǰ��---->public
// �����public�̳з�ʽ����������������֮����--is-a�Ĺ�ϵ
// is-a: ��һ�������Խ�һ��������󿴳���һ���������
// �����õ���������λ�ö�����ʹ�����������д���
int main()
{
	B b;
	b.SetB(10);

	D d;
	//d.SetB(10);
	d.SetD(20, 30);

	// ��������������������������и�ֵ
	b = d;

	// һ������ָ�����ָ���������
	// һ�������ָ�벻��ֱ��ָ��һ������Ķ���
	B* pb = &d;

	D* pd = (D*)&b;
	pd->_d = 10;

	B& rb = d;
	//D& rd = b;

	// d = b;
	return 0;
}
#endif

#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}

	void Test(int a)
	{}

// protected:
	char _b;
};

// ͬ�����أ�������������о�����ͬ���Ƶĳ�Ա(��Ա���� || ��Ա����)
// ���ͨ�����������ֱ�ӷ���ͬ����Ա�����ȷ��ʵ������������Լ��ģ������
// ͬ����Ա����ֱ�ӷ��ʵ�(�����ཫ�����е�ͬ����Ա����)

// ��Ա����������������Ƿ���ͬ�޹�
// ��Ա���������Ա����ԭ���Ƿ���ͬ�޹�
class D : public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
	}

	void Test()
	{}

//protected:
	int _b;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b = '1';
	d.B::_b = '2';

	d.Test(10);
	d.B::Test(10);

	d.SetD(1, 2);
	return 0;
}
#endif

#if 0
// �������Ĺ��캯�����޲λ���ȫȱʡ�Ĺ��캯����
// �������๹�캯����ʼ���б��λ�õ��û򲻵��ö�����
// ����û�û�е��ã����������Ĭ�ϵ���
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}

protected:
	int _b;
};

class D : public B
{
public:
	D()
	{
		cout << "D()" << endl;
	}

protected:
	int _d;
};

int main()
{
	D d;
	return 0;
}
#endif

#if 0
class B
{
public:
	B(int b)
	{
		cout << "B()" << endl;
	}

protected:
	int _b;
};

// �������Ĺ��캯�����в����Ĺ��캯�����û�������
// �����๹�캯����ʼ���б��λ����ʽ���ã�����ɻ���
// ���ֳ�Ա�ĳ�ʼ��
class D : public B
{
public:
	D()
		: B(1)
		, _d(2)
	{
		cout << "D()" << endl;
	}

protected:
	int _d;
};

int main()
{
	D d;
	return 0;
}
#endif

#if 0
class B
{
public:
	B(int b)
		: _b(b)
	{
		cout << "B()" << endl;
	}

	B(const B& b)
		: _b(b._b)
	{}

	B& operator=(const B& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}

		return *this;
	}

protected:
	int _b;
};

// �������Ĺ��캯�����в����Ĺ��캯�����û�������
// �����๹�캯����ʼ���б��λ����ʽ���ã�����ɻ���
// ���ֳ�Ա�ĳ�ʼ��
class D : public B
{
public:
	D(int b, int d)
		: B(b)
		, _d(d)
	{
		cout << "D()" << endl;
	}

	D(const D& d)
		: B(d)
		, _d(d._d)
	{}

	D& operator=(const D& d)
	{
		if (this != &d)
		{
			//*this = d;
			B::operator=(d);
			_d = d._d;
		}

		return *this;
	}
protected:
	int _d;
};

int main()
{
	D d1(1, 2);
	D d2(d1);

	D d3(3, 4);
	d2 = d3;
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b = 10)
		: _b(b)
	{}

	void SetBase(int b)
	{
		_b = b;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	void SetDerived(int b, int d)
	{
		_b = b;
		_d = d;
	}

protected:
	int _d;
};


int main()
{
	Base b;
	Derived d;
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{}

	void SetBase(int b)
	{
		_b = b;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	/*
	�������������Ĭ�ϵĹ��캯��������������ɵĹ��캯��һ�����޲ε�
	Derived()
	   : Base()
	{}
	
	������Ĭ�Ϲ��캯�������ʼ���б�λ�õ��û��๹�캯��ʱ��������û���
	�޲λ���ȫȱʡ�Ĺ��캯��
	*/

	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

	void SetDerived(int b, int d)
	{
		_b = b;
		_d = d;
	}

protected:
	int _d;
};


int main()
{
	Base b(10);
	Derived d(10, 20);
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{}

	Base(const Base& b)
		: _b(b._b)
	{}

	void SetBase(int b)
	{
		_b = b;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{}

	void SetDerived(int b, int d)
	{
		_b = b;
		_d = d;
	}

protected:
	int _d;
};


int main()
{
	Base b(10);
	Derived d1(10, 20);
	Derived d2(d1);

	Derived d3(30, 40);
	d2 = d3;
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{}

	Base(const Base& b)
		: _b(b._b)
	{}

	Base& operator=(const Base& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}

		return *this;
	}

	void SetBase(int b)
	{
		_b = b;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			// �����ಿ�ֳ�Ա��ֵ
			Base::operator=(d);

			// �������������ӳ�Ա��ֵ
			_d = d._d;
		}

		return *this;
	}

	void SetDerived(int b, int d)
	{
		_b = b;
		_d = d;
	}

protected:
	int _d;
};


int main()
{
	Base b(10);
	Derived d1(10, 20);
	Derived d2(d1);

	Derived d3(30, 40);
	d2 = d3;
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base::Base(int)" << endl;
	}

	~Base()
	{
		cout << "Base::~Base()" << endl;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{
		cout << "Derived::Derived(int,int)" << endl;
	}

	~Derived()
	{
		cout << "Derived::~Derived()" << endl;
		// call Base::~Base();
	}

protected:
	int _d;
};


// 1. ���н�����ӡ���
       /*
	      Base::Base(int)
		  Derived::Derived(int,int)
		  Derived::~Derived()
		  Base::~Base()
	   */
// 2. ����������ĵ��ô���
/*
         �������ִ�д����ȵ����๹��--->�����๹��--->����������--->��������
	  // ��Щ����£�ǧ���ܹ��������Լ����۾�
	  �������
	    �����๹�캯��()
		   : ���๹�캯������
		{}

		��������
		��������������()
		{
		   // �ͷ���������Դ

		   // �������������������������һ����Ч�������һ��������
		   call ������������;
		}
*/
void TestDerived()
{
	Derived d(10, 20);
}

int main()
{
	TestDerived();
	return 0;
}
#endif

#if 0
// C++98
// ���һ���಻�ܱ��̳�
class Base
{
public:
	static Base GetObject(int b)
	{
		return Base(b);
	}

private:
	Base(int b)
		: _b(b)
	{}

protected:
	int _b;
};

#if 0
class Derived : public Base
{
	/*
	public:
	   Derived()
	      : Base()
	   {}

	��Ϊ���๹�캯������Ȩ����private�����������оͲ���
	ֱ�ӱ����ã����������Ĺ��캯���޷�����
	*/
};
#endif


int main()
{
	// Derived d;
	Base b(Base::GetObject(10));
	return 0;
}
#endif

#if 0
// final�������һ���ࣺ��ʾ���಻�ܱ��̳�
class Base final
{
public:
	Base(int b)
		: _b(b)
	{}

protected:
	int _b;
};

class Derived : public Base
{};

int main()
{
	return 0;
}
#endif

#if 0
// ��Ԫ��ϵ�����ܱ��̳�
class Base
{
	friend void Print();
public:
	Base(int b)
		: _b(b)
	{}

	int GetB()
	{
		return _b;
	}
protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

protected:
	int _d;
};

void Print()
{
	Base b(10);
	cout << b.GetB() << endl;
	cout << b._b << endl;

	Derived d(10, 20);
	cout << d._d << endl;
}
#endif

#if 0
// ͳ��һ���ഴ���˶��ٸ�����
class Person
{
public:
	Person(const string& name, const string& gender, int age)
		: _name(name)
		, _gender(gender)
		, _age(age)
	{
		_count++;
	}

	Person(const Person& p)
		: _name(p._name)
		, _gender(p._gender)
		, _age(p._age)
	{
		++_count;
	}

	~Person()
	{
		--_count;
	}

protected:
	string _name;
	string _gender;
	int _age;

public:
	static size_t _count;
};

size_t Person::_count = 0;


class Student : public Person
{
public:
	Student(const string& name, const string& gender, int age, int stuId)
		: Person(name, gender, age)
		, _stuId(stuId)
	{}

	Student(const Student& s)
		: Person(s)
		, _stuId(s._stuId)
	{}


protected:
	int _stuId;
};

class Teacher : public Person
{
public:
	Teacher(const string& name, const string& gender, int age, int stuId)
		: Person(name, gender, age)
		, _stuId(stuId)
	{}

	Teacher(const Teacher& s)
		: Person(s)
		, _stuId(s._stuId)
	{}


protected:
	int _stuId;
};



void TestPerson()
{
	Person p("111", "��", 18);
	Student s("222", "Ů", 18, 20);

	cout << Person::_count << endl;
	cout << Student::_count << endl;

	cout << &Person::_count << endl;
	cout << &Student::_count << endl;
	cout << &Teacher::_count << endl;

	/*
	���ۣ�
	 1. �����о�̬��Ա�������Ա�����̳�
	 2. �������̳���ϵ�У���̬��Ա����ֻ��һ��
	*/
}

int main()
{
	TestPerson();
	return 0;
}
#endif

#if 0
class B1
{
public:
	int _b1;
};

class B2
{
public:
	int _b2;
};

// ע�⣺ÿ������ǰ��������̳�Ȩ�ޣ��������Ĭ�ϵļ̳�Ȩ��
class D : public B2,  public B1
{
public:
	int _d;
};


int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	return 0;
}
#endif

#if 0
class B
{
public:
	int _b;
};

class C1 : public B
{
public:
	int _c1;
};

class C2 : public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	//d._b = 1;  // ���μ̳�ȱ�ݣ�����ڶ���������
	
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
	return 0;
}
#endif

#if 1
// ��������̳�
class B
{
public:
	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

#if 0
	D d;
	d._b = 1;  // ���μ̳�ȱ�ݣ�����ڶ���������

	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
#endif

	// ��������̳�

	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;
	return 0;
}
#endif

#if 0
// ����̳�
class B
{
public:
	int _b;
};

class D : virtual public B
{
public:
	int _d;
};


int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b = 1;
	d._d = 2;

	return 0;
}
#endif
