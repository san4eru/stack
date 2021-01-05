#include <iostream> 

using namespace std;

unsigned long long N_op;

class arg {
public:
	int data;
	arg* prev;
};

class stack {
	int count;
public:
	arg* tail;
	stack();

	void add(const int& num);
	void del();
	int value();
	bool isempty();
	void show();
	friend void sort(stack& list);
	friend int GET(stack& list, const int& num);
	friend void SET(stack& list, const int& num, const int& new_data);
};

bool stack::isempty() { 
	N_op+=1;
	if (tail){//+1
		N_op+=1;
		return 1;//+1
	}	
	else{
		N_op+=1;
		return 0;//+1
	}
}

stack::stack(){
	count = 0; //+1
	N_op+=1;
	tail = NULL; //+1
	N_op+=1;
}

void stack::add(const int& num){
	arg* temp = new arg; //+3
	N_op+=3;
	N_op+=2;
	if (!(count)) { //+2
		temp->data = num; //+2
		N_op+=2;
		tail = temp; //+1
		N_op+=1;
		temp->prev = NULL; //+2
		N_op+=2;
	}
	else {
		temp->data = num; //+2
		N_op+=2;
		temp->prev = tail; //+2
		N_op+=2;
		tail = temp; //+1
		N_op+=1;
	}
	count++; //+2
	N_op+=2;
}

void stack::del(){
	arg* temp = tail; //+2
	N_op+=2;
	tail = temp->prev; //+2
	N_op+=2;
	count--; //+2
	N_op+=2;
	N_op+=1;
	delete temp; //+1
}

int stack::value() {
	arg* temp = tail; //+2
	N_op+=2;
	N_op+=2;
	return temp->data; //+2
}

void stack::show(){
	arg* temp = tail;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

int GET(stack& list, const int& num) {
	arg* tail_temp = list.tail; //+3
	N_op+=3;
	int temp = 0; //+2
	N_op+=2;
	stack list_temp; //+1
	N_op+=1;
	int i = 0; //+2
	N_op+=2;
	N_op+=1;
	while (tail_temp) { //+1
		list_temp.add(list.value()); //+2
		N_op+=2;
		list.del(); //+1
		N_op+=1;
		tail_temp = tail_temp->prev; //+2
		N_op+=2;
		N_op+=1;
	}
	tail_temp = list_temp.tail; //+2
	N_op+=2;
	N_op+=1;
	while (tail_temp) { //+1
		list.add(list_temp.value()); //+2
		N_op+=2;
		N_op+=1;
		if (i == num) { //+1
			temp = tail_temp->data; //+2
			N_op+=2;
		}
		list_temp.del(); //+1
		N_op+=1;
		i++; //+2
		N_op+=2;
		tail_temp = tail_temp->prev; //+2
		N_op+=2;
		N_op+=1;
	}
	N_op+=1;
	return temp; //+1
}

void SET(stack& list, const int& num, const int& new_data) {
	arg* tail_temp = list.tail; //+3
	N_op+=3;
	int temp = 0; //+2
	N_op+=2;
	stack list_temp; //+1
	N_op+=1;
	int i = 0; //+2
	N_op+=2;
	N_op+=1;
	while (tail_temp) { //+1
		list_temp.add(list.value()); //+2
		N_op+=2;
		list.del(); //+1
		N_op+=1;
		tail_temp = tail_temp->prev; //+2
		N_op+=2;
		N_op+=1;
	}
	tail_temp = list_temp.tail; //+2
	N_op+=2;
	N_op+=1;
	while (tail_temp) { //+1
		N_op+=1;
		if (i == num){ //+1
			list.add(new_data); //+1
			N_op+=1;
		}
		else{
			list.add(list_temp.value()); //+2
			N_op+=2;
		}  
		list_temp.del(); //+1
		N_op+=1;
		i++; //+2
		N_op+=2;
		tail_temp = tail_temp->prev; //+2
		N_op+=2;
		N_op+=1;
	}
}

void sort(stack& list)
{
	int temp = 0, key = 0, temp_g; //+5
	N_op+=5;
	arg* tail_temp = list.tail; //+3
	N_op+=3;
	int i = 0; //+2
	N_op+=2;
	N_op+=2;
	while (tail_temp->prev) { //+2
		key = i + 1; //+2
		N_op+=2;
		temp = GET(list, key); //+3
		N_op+=3;
		N_op+=4;
		for (int j = i + 1; j > 0; j--) {
			temp_g = GET(list, j - 1); //+4
			N_op+=4;
			N_op+=1;
			if (temp < temp_g) { //+1
				SET(list, j, temp_g); //+3
				N_op+=3;
				key = j - 1; //+2
				N_op+=2;
			}
			N_op+=3;
		}
		SET(list, key, temp); //+3
		N_op+=3;
		i++; //+2
		N_op+=2;
		tail_temp = tail_temp->prev; //+2
		N_op+=2;
		N_op+=2;
	}
}

int main()
{
	system("chcp 1251->NULL");
	stack l;
	int n, flag = -1;
	while (flag != 7) {
		cout << "1 - Добавить" << endl;
		cout << "2 - Извлечь" << endl;
		cout << "3 - ISEMPTY" << endl;
		cout << "4 - Сортировать" << endl;
		cout << "5 - Вывести" << endl;
		cout << "6 - Удалить" << endl;
		cout << "7 - Выйти" << endl;
		cin >> flag;

		if (flag == 1) {
			cout << "Введите элемент: " << endl;  cin >> n;
			l.add(n);
		}
		if (flag == 2)
			cout << l.value() << endl;

		if (flag == 3)
			cout << l.isempty() << endl;

		if (flag == 4){
			N_op=0;
			sort(l);
			cout << "Шаги - " << N_op << endl;
		}

		if (flag == 5)
			l.show();
		if (flag == 6)
			l.del();
	}
}
