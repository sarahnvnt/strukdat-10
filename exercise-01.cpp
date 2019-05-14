/*
Nama 	: Sarah Navianti 
NPM 	: 140810180021
Kelas 	: A
Tahun 	: 2019
Materi 	: Queue 
*/

#include <iostream>

using namespace std;

const int maxElement = 255;
struct Queue{
    char isi[maxElement];
    int head; // depan
    int tail; // belakang
};

void createQueue (Queue& Q);
void createElement(char& elemen);
void insertQueue(Queue& Q, char elemen);
void deleteQueue(Queue& Q, char& elemenHapus);

int main()
{
    Queue Q;
    char ElementHapus,elemen;
    int a;
    createQueue(Q);
    cout << "Masukan Banyaknya Elemen : ";cin >> a;
    for(int i=0;i<a;i++){
        createElement(elemen);
        insertQueue(Q,elemen);
    }
    cout << endl;
    cout << "POP :"<<endl;
    for(int i=0;i<a;i++){
        deleteQueue(Q,ElementHapus);
        cout << endl;
    }
    return 0;
}
void createQueue (Queue& Q){
    Q.head = 0;
    Q.tail = -1;
}

void createElement(char& elemen){
    cout<<"Input: ";cin>>elemen;
}

void insertQueue(Queue& Q, char Element) {
    if (Q.tail==maxElement-1){
        cout<<"Antrian sudah penuh"<<endl;
    }
    else {
        Q.tail=Q.tail + 1;
        Q.isi[Q.tail] = Element;
    }
}

void deleteQueue(Queue& Q, char& elemenHapus){
    if (Q.head>Q.tail){ // atau Q.tail=-1
        cout<<"Antrian kosong"<<endl;
    }
    else {
        elemenHapus= Q.isi[Q.head];
        cout << elemenHapus; //Q.head=0
        for (int i=0;i<Q.tail;i++){ // Geser ke depan
            Q.isi[i]=Q.isi[i+1];
        }
        Q.tail=Q.tail-1;
    }
}

void displayReverse(Queue Q)
{
    int i;
   if (Q.head == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      for (int i = Q.tail; i >= Q.head; i--){
        cout<<Q.isi[i];
        if(i==Q.head)break;
        cout<<",";
        }
    }
}
void display(Queue Q){
    int i;
   if (Q.head == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      for (int i = Q.head; i <= Q.tail; i++){
        cout<<Q.isi[i];
        if(i==Q.tail)break;
        cout<<",";
        }
    }
}
