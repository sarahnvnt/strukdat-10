/*
Nama 	: Sarah Navianti 
NPM 	: 140810180021
Kelas 	: A
Tahun 	: 2019
Materi 	: Tree
*/

#include <iostream>

using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};

typedef Simpul* pointer;
typedef pointer Tree;

void createTree(Tree& Root){
    Root=NULL;
}

void CreateSimpul(pointer& pBaru) {
    pBaru = new Simpul;
    cout << "Masukkan satu angka : ";
    cin >> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void InsertBST (Tree& Root, pointer pBaru){
    if ( Root == NULL)
        Root = pBaru;
    else if (pBaru->info < Root->info)
        InsertBST(Root->left,pBaru);
    else if (pBaru->info > Root->info)
        InsertBST(Root->right,pBaru);
    else
        cout<<"sudah ada";
}

void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (Tree Root) {
     if (Root != NULL){
          inOrder(Root->left);
          cout<< Root->info <<endl;
          inOrder(Root->right);
     }
}

void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<endl;
    }
}

void notasiKurung(Tree Root){
    if(Root!=NULL){
        cout << "(";
        cout << Root->info;
        notasiKurung(Root->left);
        notasiKurung(Root->right);
        cout << ")";
    }
}

int main()
{
    Tree Root;
    pointer pBaru;
    int pilih;
    createTree(Root);
    int a;
    cout<<"Masukkan jumlah elemen : ";cin>>a;
    for(int i=0; i<a; i++)
    {
            CreateSimpul(pBaru);
            InsertBST(Root,pBaru);
    }
    notasiKurung(Root);
    system("pause");
     do{
      system("cls");
      cout << " Menu Program : "<<endl;
      cout << "1. Insert" << endl;
      cout << "2. Preorder" << endl;
      cout << "3. Inorder" << endl;
      cout << "4. Postorder "<< endl;
      cout << "5. Exit "<<endl;
      cout << "Masukkan pilihan anda : "; cin >> pilih;
      switch(pilih){
           case 1:
            CreateSimpul(pBaru);
            InsertBST(Root,pBaru);
            notasiKurung(Root);
            system("pause");
           break;
           case 2:
            preOrder(Root);
            system("pause");
           break;
           case 3:
            inOrder(Root);
            system("pause");
            break;
           case 4:
            postOrder(Root);
            system("pause");
           break;
           case 5:
            return 0;
           break;
          }
    }while(pilih!=5);

    return 0;
}
