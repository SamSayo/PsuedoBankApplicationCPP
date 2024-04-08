#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Card
{
private:
	fstream costs;
	string cardName = "�����������";
	string accountName;
	float balance = 0;
	int card[16];
	bool isDebit = false;
	bool accountExist = true;
	bool cardExist = false;

public:

	Card()
	{
		costs.open("account.lorembank", ios::in | ios::out | ios::app);
		if (!costs)
		{
			cout << "�� ������� ������� ����" << endl;
			return;
		}
	}

	void createAccount()
	{
		system("cls");
		string accountName;
		int choice;

		cout << "������� ��� ������ �����: ";
		cin >> accountName;
		this->accountName = accountName;

		cout << "��������, ����� ����� ����: "
			<< endl << "1. ���������\t\t2. ���������" << endl;
		cin >> choice;

		if (choice == 2)
		{
			isDebit = true;
		}
		accountExist = true;

		cout << endl << "�������! ���� ��� ������!"
			<< endl << "������ �������� ����� ������?" << endl;
		cout << "1. ��\t\t2. ���" << endl;
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
			cout << "���� �� ��� ������\n������� �������� ����, ����� �����" << endl;
			system("pause");
			createAccount();
		}
		else if (cardExist == true)
		{
			cout << "��������, ������� ����� ����� �� �������\n��������� ������ 1.12.2" << endl;
			system("pause");
		}
		else
		{
			string cardName;
			int choice;

			cout << "������� ��� ����� �����: ";
			cin >> cardName;
			this->cardName = cardName;

			cout << "����� ����� �����: ";
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
			cout << "���� �� ��� ������\n������� �������� ����, ����� ����� ����� ��� ���������" << endl;
			system("pause");
			createAccount();
		}
		else
		{
			double sum;

			cout << "������� �����, �� ������� ������ ��������� ������ �����: ";
			cin >> sum;

			if (sum <= 0)
			{
				cout << "�� �� ������ �������� ��� ����� �� �����, �.�. ��� ������ ��� ����� ����" << endl;
				system("pause");
			}
			else
			{
				balance += sum;
				cout << endl << "������ ����� ������ ����� " << balance << " ���." << endl;
				system("pause");
			}
		}
	}

	void withdraw()
	{
		system("cls");
		if (!accountExist)
		{
			cout << "���� �� ��� ������\n������� �������� ����" << endl;
			system("pause");
			createAccount();
		}
		else
		{
			double sum;

			cout << "������� �����, ������� ������ ����� �� �����: ";
			cin >> sum;
			if (sum > balance || sum == 0)
			{
				cout << "� ��� �� ������� ������ �������, ��� �� ������ �����"
					<< endl << "� ������: " << balance << " ���." << endl;
				system("pause");
			}
			else
			{
				int choice;
				cout << "��������, �� ��� �� ������� ������: "
					<< endl << "1. ������ �����\t2. ������� ������"
					<< endl << "3. ���������� ��������\t4. ������ ���";
				cout << endl << "�����: ";
				cin >> choice;

				switch (choice)
				{
				case 1:
					costs << "������ �����: " << sum << endl;
					break;

				case 2:
					costs << "�������: " << sum << endl;
					break;

				case 3:
					costs << "���������� ��������: " << sum << endl;
					break;

				case 4:
					costs << "������ ���: " << sum << endl;
					break;
				}

				balance -= sum;
				cout << endl << "������ ����� ������ ����� " << balance << " ���." << endl;
				system("pause");
			}
		}
	}

	void debugFoo()
	{
		system("cls");
		string word;
		while (getline(costs, word))
		{
			cout << word << endl;
		}
		system("pause");
	}

	void printAll()
	{
		system("cls");
		if (!accountExist)
		{
			cout << "������� ����� ������� ����" << endl;
			system("pause");
			createAccount();
		}
		else
		{
			cout << "����: " << getAcc()
				<< endl << "�����: " << getCard()
				<< endl << "������ �����: " << getBalance() << endl << endl;
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
