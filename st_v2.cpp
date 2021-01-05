#include <iostream> 

using namespace std;

class arg {
public:
	int data;
	arg* prev;
};

class stack {

	size_t count;
public:
	arg* tail;
	stack();

	void add(const int& num);
	void del();
	int value();
	bool isempty();
	void show_all();
	friend void sort(stack &list);
	friend int get(stack& list, const size_t& num);
	friend void set(stack& list, const size_t& num, const int& new_data);
};

bool stack::isempty() { return tail ? 1 : 0; }

stack::stack()
{
	count = 0;
	tail = NULL;
}

void stack::add(const int& num)
{
	arg* temp = new arg;
	if (!(count)) { temp->data = num; tail = temp; temp->prev = NULL; }
	else {
		temp->data = num;
		temp->prev = tail;
		tail = temp;
	}
	count++;
}

void stack::del()
{
	arg* temp = tail;
	tail = temp->prev;
	count--;
//	delete temp;
}

int stack::value() {
	arg* temp = tail;
	return temp->data;
}

void stack::show_all()
{
	arg* temp = tail;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

stack create(stack& list) {
	srand(static_cast<unsigned int>(NULL));
	for (int i = 0; i < 5; i++) {
		list.add(rand() % 10);
	}
	return list;
}

int main()
{
	short int sw;
	system("chcp 1251->NULL");
	stack l;
	int numb;
	l = create(l);
	l.show_all();
	int n, flag = -1;
	while (flag != 7) {
		cout << "1 - Добавить" << endl;
		cout << "2 - Извлечь" << endl;
		cout << "3 - ISEMPTY" << endl;
		cout << "4 - Сортировать" << endl;
		cout << "5 - Вывести" << endl;
		cout << "6 - Удалить" << endl;
		cout << "7 - Выйти" << endl;
		cout << "8-???????? ?? ????????????? ?????" << endl;
		cout << "9-???????? ? ???????????? ?????" << endl;
		cin >> flag;

		if (flag == 1) {
			cout << "??????? ???????: " << endl;  cin >> n;
			l.add(n);
		}
		if (flag == 2)
			cout << l.value() << endl;

		if (flag == 3)
			cout << l.isempty() << endl;

		if (flag == 4)
			sort(l);

		if (flag == 5)
			l.show_all();
		if (flag == 6)
			l.del();
		if (flag == 8) {
			cin >> flag;
			cout << get(l, flag) << endl;
		}
		if (flag == 9) {
			cout << "??????? ???? ????????" << endl;
			cin >> flag;
			cout << "??????? ????? ?????" << endl;
			cin >> numb;
			set(l, flag, numb);
		}
	}
}

int get(stack &list,const size_t &num){

	arg* tail_inner=list.tail;
	int temp = 0;
	stack list_inner;
	size_t i = 0;
	while(tail_inner){
		list_inner.add(list.value());
		list.del();
		tail_inner=tail_inner->prev;
	}
	tail_inner = list_inner.tail;
	while (tail_inner) {
		list.add(list_inner.value());
		if (i == num)
			temp = tail_inner->data;
		list_inner.del();
		i++;
		tail_inner = tail_inner->prev;
	}
	return temp;
}

void set(stack &list, const size_t& num, const int& new_data){
	arg* tail_inner = list.tail;
	int temp = 0;
	stack list_inner;
	size_t i = 0;
	while (tail_inner) {
		list_inner.add(list.value());
		list.del();
		tail_inner = tail_inner->prev;
	}
	tail_inner = list_inner.tail;
	while (tail_inner) {
		i == num ? list.add(new_data) : list.add(list_inner.value());;
		//list.show_all();
		list_inner.del();
		i++;
		tail_inner = tail_inner->prev;
	}
}

void sort(stack &list)
{
	int temp = 0, key = 0;
	arg* tail_inner = list.tail;
	int get_;
	size_t i = 0;
	while(tail_inner->prev) {
		key = i + 1;
		temp = get(list, key);
		for (int j = i + 1; j > 0; j--) {
			get_ = get(list,j - 1);
			if (temp < get_) {
				set(list,j, get_);
				key = j - 1;
			}
		}
		set(list, key, temp);
		//list.show_all();
		i++;
		tail_inner = tail_inner->prev;
	}
}
