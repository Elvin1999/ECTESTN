#pragma once
#include<iostream>
#include "Functions.h"
using namespace std;


void HomeMenu() {
	cout << "Admin [1]" << endl;
	cout << "Client [2]" << endl;
}

void AdminHomeMenu() {
	cout << "Show All Products        [1]" << endl;
	cout << "Add new Product          [2]" << endl;
	cout << "Add Product quantity     [3]" << endl;
	cout << "Delete Product           [4]" << endl;
	cout << "Orders                   [5]" << endl;
}

void ClientHomeMenu() {
	cout << "Show All Products [1]" << endl;
	cout << "Buy product       [2]" << endl;
	cout << "Order product     [3]" << endl;
}

void Start() {
	Init();
	while (true)
	{
		HomeMenu();
		int select = 0;
		cin >> select;
		cin.ignore();
		cin.clear();
		system("cls");
		if (select == 1) {
			cout << "Enter username : " << endl;
			char* username = new char[30]{};
			cin.getline(username, 30);
			cout << "Enter password : " << endl;
			char* pass = new char[30]{};
			cin.getline(pass, 30);

			auto admin = getAdmin(username, pass);
			system("cls");
			if (admin != nullptr) {
				AdminHomeMenu();
				cin >> select;
				system("cls");
				if (select == 1) {
					ShowAllProducts();
				}
				else if (select == 2) {
					cin.ignore();
					cin.clear();
					auto item = getObj();
					AddProductItem(database, &item);
				}
				else if (select == 3) {
					ShowAllProducts();
					int no = 0;
					cout << "Enter product no: " << endl;
					cin >> no;
					int quantity = 0;
					cout << "Enter quantity: " << endl;
					cin >> quantity;
					increseItemCount(no, quantity);

				}
				else if (select == 4) {
					ShowAllProducts();
					int no = 0;
					cout << "Enter product no: " << endl;
					cin >> no;
					deleteProductNo(no);
				}
				else if (select == 5) {
					ShowAllOrders();
					int no = 0;
					cout << "Enter product no: " << endl;
					cin >> no;
					ChangeOrderStatus(no);
				}
			}
			else {
				cout << "Your username or password is incorrect" << endl;
			}
		}
		else if (select == 2) {
			ClientHomeMenu();
			cin >> select;
			system("cls");
			if (select == 1) {
				ShowAllProducts();
			}
			else if (select == 2) {
				ShowAllProducts();
				cout << "Product NO to buy " << endl;
				int no = 0;
				cin >> no;
				int quantity = 0;
				cout << "Enter quantity : " << endl;
				cin >> quantity;
				Buy(no, quantity);
			}
			else if (select == 3) {
				ShowAllProducts();
				cout << "Product NO to order " << endl;
				int no = 0;
				cin >> no;
				int quantity = 0;
				cout << "Enter quantity : " << endl;
				cin >> quantity;
				OrderItem(no, quantity);
			}
		}
		else {
			cout << "Wrong Input" << endl;
		}
	}
}