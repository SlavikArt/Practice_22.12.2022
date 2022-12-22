#include <iostream>
using namespace std;

class Account
{
	char* name;
	char* surname;
	long long accountNumber;
	double percent;
	double sum;
public:
	Account();
	Account(const char* n, const char* sn, long long acN, double p, double s);
	~Account();

	void ChangeOwner(const char* n, const char* sn);
	void PutMoney(double s);
	void WithdrawMoney(double s);
	void PercentPay();

	void Print();
	void Init();

	double ConvertToUSD();
	double ConvertToEuro();

	char* GetName();
	char* GetSurname();
	long long GetAccountNumber();
	double GetSum();
	double GetPercent();

	void SetName(char* n);
	void SetSurname(char* sn);
	void SetAccountNumber(long long acN);
	void SetSum(double s);
	void SetPercent(double p);
};

Account::Account()
{
	name = nullptr;
	surname = nullptr;
	accountNumber = 0;
	percent = 0;
	sum = 0;
}

Account::Account(const char* n, const char* sn, long long acN, double p, double s)
{
	if (name != nullptr)
		delete[] name;
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);

	if (surname != nullptr)
		delete[] surname;
	this->surname = new char[strlen(sn) + 1];
	strcpy_s(this->surname, strlen(sn) + 1, sn);

	accountNumber = acN;
	percent = p;
	sum = s;
}

Account::~Account()
{
	delete[] name;
	delete[] surname;
}

void Account::ChangeOwner(const char* n, const char* sn)
{
	if (name != nullptr)
		delete[] name;
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);

	if (surname != nullptr)
		delete[] surname;
	this->surname = new char[strlen(sn) + 1];
	strcpy_s(this->surname, strlen(sn) + 1, sn);
}

void Account::PutMoney(double s)
{
	sum += s;
}

void Account::WithdrawMoney(double s)
{
	if (sum - s >= 0)
	{
		sum -= s;
	}
	else
	{
		sum -= sum;
	}	
}

void Account::PercentPay()
{
	sum += sum / 100 * percent;
}

void Account::Print()
{
	cout << name << " " << surname << "\n";
	cout << "Account number: " << accountNumber << "\n";
	cout << "Percent: " << percent << "\n";
	cout << "Money: " << sum << "\n";
}

void Account::Init()
{
	char buf[20];
	cout << "Enter name -> ";
	cin.getline(buf, 20);
	if (name != nullptr)
		delete[] name;
	this->name = new char[strlen(buf) + 1];
	strcpy_s(this->name, strlen(buf) + 1, buf);

	cout << "Enter surname -> ";
	cin.getline(buf, 20);
	if (surname != nullptr)
		delete[] surname;
	this->surname = new char[strlen(buf) + 1];
	strcpy_s(this->surname, strlen(buf) + 1, buf);

	cout << "Enter account number -> ";
	cin >> accountNumber;

	cout << "Enter percent -> ";
	cin >> percent;

	cout << "Enter amount of money -> ";
	cin >> sum;
}

double Account::ConvertToUSD()
{
	return sum / 36.92;
}

double Account::ConvertToEuro()
{
	return sum / 39.08;
}

char* Account::GetName()
{
	return name;
}

char* Account::GetSurname()
{
	return surname;
}

long long Account::GetAccountNumber()
{
	return accountNumber;
}

double Account::GetSum()
{
	return sum;
}

double Account::GetPercent()
{
	return percent;
}

void Account::SetName(char* n)
{
	if (name != nullptr)
		delete[] name;
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

void Account::SetSurname(char* sn)
{
	if (surname != nullptr)
		delete[] surname;
	this->surname = new char[strlen(sn) + 1];
	strcpy_s(this->surname, strlen(sn) + 1, sn);
}

void Account::SetAccountNumber(long long acN)
{
	accountNumber = acN;
}

void Account::SetSum(double s)
{
	sum = s;
}

void Account::SetPercent(double p)
{
	percent = p;
}

int main()
{
	Account obj1("Vlad", "Petrenko", 43243213LL, 2.5, 12500.0);
	obj1.Print();
	cout << "\n";

	obj1.ChangeOwner("Vasya", "Kovalenko");
	obj1.Print();
	cout << "\n";

	obj1.PutMoney(200.50);
	obj1.Print();
	cout << "\n";

	obj1.PercentPay();
	obj1.Print();
	cout << "\n";

	obj1.WithdrawMoney(523.3);
	obj1.Print();
	cout << "\n";

	cout << "In USD: " << obj1.ConvertToUSD() << "\n";
	cout << "In Euro: " << obj1.ConvertToEuro() << "\n";
}
