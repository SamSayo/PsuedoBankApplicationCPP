#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Card
{
private:
	ifstream costs;
	string cardName = "Отсутствует";
	string accountName;
	float balance = 0;
	int card[16];
	bool isDebit = false;
	bool accountExist = true;
	bool cardExist = false;

public:

	Card()
	{
		costs.open("account.pb", ios::out | ios::app | ios::binary);
		if (!costs)
		{
			cout << "Не удалось открыть файл" << endl;
			return;
		}
	}

	void createAccount()
	{
		system("cls");
		string accountName;
		int choice;

		cout << "Введите имя нового счёта: ";
		cin >> accountName;
		this->accountName = accountName;

		cout << "Выберите, каким будет счёт: "
			<< endl << "1. Кредитным\t\t2. Дебетовым" << endl;
		cin >> choice;

		if (choice == 2)
		{
			isDebit = true;
		}
		accountExist = true;

		cout << endl << "Отлично! Счёт был создан!"
			<< endl << "Хотите сорздать карту сейчас?" << endl;
		cout << "1. Да\t\t2. Нет" << endl;
		cin >> choice;

		if (choice == 1)
		{
			createCard();
		}
		else if (choice == 2)
		{
			system("cls");
			system("pause");
		}
	}

	void createCard()
	{
		system("cls");
		if (accountExist == false)
		{
			cout << "Счёт не был создан\nСначала создайте счёт, затем карту" << endl;
			system("pause");
			createAccount();
		}
		else if (cardExist == true)
		{
			cout << "Извините, создать новую карту не удалось\nПодождите версии 1.12.2" << endl;
			system("pause");
		}
		else
		{
			string cardName;
			int choice;

			cout << "Введите имя новой карты: ";
			cin >> cardName;
			this->cardName = cardName;

			cout << "Номер вашей карты: ";
			for (int i = 0; i < 16; i++)
			{
				card[i] = rand() % 10;
				cout << card[i];
				if (i == 3 || i == 7 || i == 11)
				{
					cout << " ";
				}
			}
			cout << endl;
			cardExist = true;
			system("pause");
		}
	}

	void refill()
	{
		system("cls");
		if (!accountExist)
		{
			cout << "Счёт не был создан\nСначала создайте счёт, затем можно будет его пополнить" << endl;
			system("pause");
			createAccount();
		}
		else
		{
			double sum;

			cout << "Введите сумму, на которую хотите пополнить баланс счёта: ";
			cin >> sum;

			if (sum <= 0)
			{
				cout << "Вы не можете положить эту сумму на карту, т.к. она меньше или равна нулю" << endl;
				system("pause");
			}
			else
			{
				balance += sum;
				cout << endl << "Баланс счёта теперь равен " << balance << " руб." << endl;
				system("pause");
			}
		}
	}

	void withdraw()
	{
		system("cls");
		if (!accountExist)
		{
			cout << "Счёт не был создан\nСначала создайте счёт" << endl;
			system("pause");
			createAccount();
		}
		else
		{
			double sum;

			cout << "Введите сумму, которую хотите снять со счёта: ";
			cin >> sum;
			if(sum > balance)
			{
				cout << "У вас на балансе меньше средств, чем вы хотите снять"
					<< endl << "А именно: " << balance << " руб." << endl;
				system("pause");
			}
			else
			{
				balance -= sum;
				cout << endl << "Баланс счёта теперь равен " << balance << " руб." << endl;
				system("pause");
			}
		}
	}

	void printAll()
	{
		system("cls");
		if (!accountExist)
		{
			cout << "Сначала нужно создать счёт" << endl;
			system("pause");
			createAccount();
		}
		else
		{
			cout << "Счёт: " << getAcc()
				<< endl << "Карта: " << getCard()
				<< endl << "Баланс счёта: " << getBalance() << endl << endl;
			system("pause");
		}
	}

	string getAcc() { return accountName; }
	string getCard() { return cardName; }
	float getBalance() { return balance; }

	~Card()
	{
		costs.close();
	}
};