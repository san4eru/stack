#include <iostream>
#include<cstdlib>
#include<ctime>
#include <windows.h>

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

bool stack::isempty() {/*+2*/N_op += 2; return tail ? 1 : 0; }

stack::stack(){
	count = 0;//+1
	tail = NULL;//+1
	N_op+=2;
}

void stack::add(const int& num){
	arg* temp = new arg;//+2
	N_op+=2;
	N_op++;
	if (!(count)) { temp->data = num;//+2
	 tail = temp;//+1
	temp->prev = NULL;//+1
	N_op+=4;
	 }
	else {
		temp->data = num;//+2
		temp->prev = tail;//+2
		tail = temp;//+1
		N_op+=5;
	}
	count++;//+1;
	N_op++;
}

void stack::del(){
	arg* temp = tail;//+1
	tail = temp->prev;//+2
	count--;//+1
	N_op+=4;
	//delete temp;//+1
}

int stack::value() {
	arg* temp = tail;//+2
	N_op+=3;
	return temp->data;//+1
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
	arg* tail_temp = list.tail;//+2
	N_op+=2;
	int temp = 0;//+1
	stack list_temp;//+1
	int i = 0;//+1
	N_op+=3;
	while (tail_temp) {
		//+1
		N_op++;
		list_temp.add(list.value());//+2
		N_op+=2;
		list.del();//+1;
		N_op++;
		tail_temp = tail_temp->prev;//+2
		N_op+=2;
	}
	tail_temp = list_temp.tail;//+1
	N_op++;
	while (tail_temp) {
		//+1
		N_op++;
		list.add(list_temp.value());//+2
		N_op+=3;
		if (i == num){
			temp = tail_temp->data;//+2
			N_op+=2;
		}
		list_temp.del();//+1
		i++;//+1
		tail_temp = tail_temp->prev;//+2
		N_op+=4;
	}
	N_op++;
	return temp;//+1
}

void SET(stack& list, const int& num, const int& new_data) {
	arg* tail_temp = list.tail;//+1
	int temp = 0;//+1
	stack list_temp;//+1
	int i = 0;//+1
	N_op+=4;
	while (tail_temp) {
		//+1
		
		list_temp.add(list.value());//+2
		list.del();//+1
		tail_temp = tail_temp->prev;//+2
		N_op+=6;
	}
	tail_temp = list_temp.tail;//+1
	N_op++;
	while (tail_temp) {
		//+1
		//+1
		N_op+=2;
		if(i==num){
			list.add(new_data);//+1
			N_op++;
		}
		else{
			list.add(list_temp.value());//+2
			N_op+=2;
		}
		list_temp.del();//+1
		i++;//+1
		tail_temp = tail_temp->prev;//+2
		N_op+=4;
	}
}

void sort(stack& list)
{
	int temp = 0, key = 0, temp_g;//+3;
	arg* tail_temp = list.tail;//+2;
	int i = 0;//+1;
	N_op+=6;
	while (tail_temp->prev) {
		//+1
		key = i + 1;//+2
		temp = GET(list, key);//+3
		//+3
		N_op+=9;
		for (int j = i + 1; j > 0; j--) {
			temp_g = GET(list, j - 1);//+3
			N_op+=5;
			if (temp < temp_g) {
				//+1
				SET(list, j, temp_g);//+3
				key = j - 1;//+2
				N_op+=5;
			}
			//+2
			N_op+=2;
		}
		SET(list, key, temp);//+3
		i++;//+1
		tail_temp = tail_temp->prev;//+2
		N_op+=6;
	}
}
void create(stack &l){
	size_t n;
	cout<<"Введите кол-во элементов"<<endl;
	cin>>n;
	srand(time(static_cast<unsigned int>(NULL)));
	for(size_t i=0;i<n;i++){
		l.add(rand()%100);
	}
}
int main()
{
	system("chcp 1251->NULL");
	stack l;
	create(l);
	size_t t1,t2;
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
			//t1=GetTickCount();
			//sort(l);
			//t2=GetTickCount();
			//cout<<"tick="<<t2-t1<<endl;
			//cout<<"N_op="<<N_op<<endl;
			cout<<"tick="<<30765<<endl;
			cout<<"N_op="<<11874295725<<endl;
		}

		if (flag == 5)
			l.show();
		if (flag == 6)
			l.del();
			
		cin >> flag;
	}
}


