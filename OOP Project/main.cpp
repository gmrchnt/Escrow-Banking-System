#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

#include<iostream>
#include<fstream>
#include <sstream>
#include<vector>
#include <stdlib.h>
#include <string>
#include <regex>
using namespace std;
class Account
{
private:
	string account_num;
	double balance;
public:
	Account()
	{
		account_num = "";
		balance = 0;
	}

	Account(string acc_nm, double bal)
	{
		account_num = acc_nm;
		balance = bal;
	}
	int deposite(string acc, double amount)
	{
		//			cout<<"acc"<<acc<<" ("<<account_num<<") "<<acc.compare(account_num)<<endl;
		if (!acc.compare(account_num))
		{
			if (amount > 0)
			{
				cout << "\n\t\t    AMOUNT DEPOSITE SUCCESSFULLY....." << endl;
				balance += amount;
				sleep(1);
				return 1;
			}
			else
			{
				cout << "\n\t\t    YOU CANNOT DEPOSIT NEGATIVE BALANCE.\n";
			}

		}
		else
		{
			cout << "\n\t\t    INCORRECT ACCOUNT NUMBER" << endl;
			sleep(1);
			return 0;
		}


	}
	double withdrawl(string acc, double amount)
	{
		//			cout<<acc<<account_num<<endl;
		if (!acc.compare(account_num))
		{
			if (balance >= amount && amount > 0)
			{
				//					cout<< "balance"<<balance;
				balance -= amount;
				//					cout<< "balance"<<balance;
				cout << "\n\t\t    AMOUNT WITHDRAWL SUCCESSFULLY..." << endl;
				sleep(1);
				return amount;
			}
			else
			{
				cout << "\n\t\t    INSUFFICENT BALANCE ." << endl;
				sleep(1);
				return 0;
			}
		}
		else
		{
			cout << "\n\t\t    INCORRECT ACCOUNT NUMBER...." << endl;
			sleep(1);
			return 0;
		}
		return 0;
	}
	double getBalance() const
	{
		return balance;
	}
	string getAccountNumber() const
	{
		return account_num;
	}
};
class User
{
private:
	string name;
	string gmail;
	string password;
	Account account;
public:
	User()
	{
		name = "";
		gmail = "";
		password = "";
		account = Account();
	}
	User(string n, string gm, string pass, Account Ac)
	{
		name = n;
		gmail = gm;
		password = pass;
		account = Ac;
	}
	int deposite(string acc, double amount) 
	{
		return account.deposite(acc, amount);
	}
	double withdrawl(string acc, double amount) 
	{
		return account.withdrawl(acc, amount);
	}
	int checkgmail(string gm) const
	{
		if (!gm.compare(gmail))
			return 1;
		else
			return 0;
	}
	int checkpasword(string pas) const
	{
		if (!pas.compare(password))
			return 1;
		else
			return 0;
	}
	int checkaccn(string accn)
	{
		if (!accn.compare(account.getAccountNumber()))
			return 1;
		else
			return 0;
	}
	string getName()
	{
		return name;
	}
	string getGmail()
	{
		return gmail;
	}
	Account getAccount()
	{
		return account;
	}
	int write_to_file(string filename)
	{
		fstream outfile(filename, std::ios::app);
		if (outfile.is_open())
		{
			outfile << name << endl;
			outfile << gmail << endl;
			outfile << password << endl;
			outfile << account.getAccountNumber() << endl;
			outfile << account.getBalance() << endl;
			outfile.close();
			//	            cout << "Attributes saved to user file: "  << endl;
		}
		else
		{
			//	            cout << "Error: Unable to open user file: " << filename << endl;
		}
		return 0;
	}
	void display()
	{
		cout << "      name        : " << name << endl;
		cout << "      Amount       : " << account.getBalance() << endl;
		cout << "      Gmail  : " << gmail << endl;
		cout << "      password : " << password << endl;
		cout << "      AccountNumber : " << account.getAccountNumber() << endl;

	}

};
class Transection
{
private:
	static int ID;
	int id;
	string title;
	double amount;
	string time;
	bool buyer_yes;
	bool seller_yes;
	bool approve;
	string status;
	string satisfaction;
	string buyergmail;
	string sellergmail;
	string buyerAccountNumber;
	string sellerAccountNumber;
	bool iscomplete;

public:
	Transection()
	{
		ID++;
		id = ID;
		title = "";
		amount = 0;
		time = "";
		buyer_yes = false;
		seller_yes = false;
		satisfaction = "Not Sure";
		status = "Pending";
		approve = false;
		buyergmail = "";
		sellergmail = "";
		buyerAccountNumber = "";
		sellerAccountNumber = "";
		iscomplete = false;
	}
	Transection(string tlt, double am, string tm, bool b_yes, bool s_yes, string buyer, string seller, string b_acc, string s_acc)
	{
		ID++;
		id = ID;
		title = tlt;
		amount = am;
		time = tm;
		buyer_yes = b_yes;
		seller_yes = s_yes;
		buyergmail = buyer;
		sellergmail = seller;
		satisfaction = "Not Sure";
		approve = false;
		status = "Pending";
		buyerAccountNumber = b_acc;
		sellerAccountNumber = s_acc;
		iscomplete = false;
	}
	Transection(string tlt, double am, string tm, bool b_yes, bool s_yes, string buyer, string seller, string b_acc, string s_acc, string sta, bool com)
	{
		ID++;
		id = ID;
		title = tlt;
		amount = am;
		time = tm;
		buyer_yes = b_yes;
		seller_yes = s_yes;
		buyergmail = buyer;
		sellergmail = seller;
		satisfaction = "Not Sure";
		approve = true;
		buyerAccountNumber = b_acc;
		sellerAccountNumber = s_acc;
		status = sta;
		iscomplete = com;

	}
	Transection(string tlt, double am, string tm, bool b_yes, bool s_yes, string buyer, string seller, string b_acc, string s_acc, bool app, string sta, string sat, bool com)
	{
		ID++;
		id = ID;
		title = tlt;
		amount = am;
		time = tm;
		buyer_yes = b_yes;
		seller_yes = s_yes;
		buyergmail = buyer;
		sellergmail = seller;
		satisfaction = sat;
		approve = app;
		buyerAccountNumber = b_acc;
		sellerAccountNumber = s_acc;
		status = sta;
		iscomplete = com;

	}
	double getAmount() const
	{
		return amount;
	}
	string getBuyergmail() const
	{
		return buyergmail;
	}
	string getSellergmail() const
	{
		return sellergmail;
	}
	string getBuyerAccountNumber() const
	{
		return buyerAccountNumber;
	}
	string getSellerAccountNumber() const
	{
		return sellerAccountNumber;
	}
	bool getBuyerYes() const
	{
		return buyer_yes;
	}
	bool getSellerYes() const
	{
		return seller_yes;
	}
	void setBuyerYes(bool b)
	{
		buyer_yes = b;
	}
	void setSellerYes(bool s)
	{
		seller_yes = s;
	}
	void setBuyerAccountNumber(string acc)
	{
		buyerAccountNumber = acc;
	}
	void setSellerAccountNumber(string acc)
	{
		sellerAccountNumber = acc;
	}
	int getID() const
	{
		return id;
	}
	void display() const
	{
		cout << "     __________________________________________" << endl;
		cout << "    |            (TRANSECTION NO " << id << ")            |" << endl;
		cout << "      Title        : " << title << endl;
		cout << "      Amount       : " << amount << endl;
		cout << "      Time         : " << time << endl;
		cout << "      Status       : " << status << endl;
		cout << "      Buyer Gmail  : " << buyergmail << endl;
		cout << "      Seller Gmail : " << sellergmail << endl;

		//cout<< " APPROVE "<<approve<<endl;
		if (approve)
			cout << "      APPROVED      " << endl;
		else
			cout << "      NOT APPROVED      " << endl;
		if (iscomplete)
			cout << "                     COMPLETED      " << endl;
		else
			cout << "                    INCOMPLETED      " << endl;
		cout << "    |__________________________________________|" << endl;
	}
	bool getApprove() const
	{
		return approve;
	}
	bool getComplete() const
	{
		return iscomplete;
	}
	string getStatus() const
	{
		return status;
	}
	string getSatisfaction()
	{
		return satisfaction;
	}
	void UpdateComplete()
	{
		iscomplete = true;
	}
	int UpdateApprove()
	{
		if (buyer_yes && seller_yes)
		{
			//				cout<<"buyer_yes"<<buyer_yes<<endl;
			//				cout<<"seller_yes"<<seller_yes<<endl;
			this->approve = true;
			return 1;
		}
		else
		{
			//				cout<<"else ma hai   ";
			//				cout<<"buyer_yes"<<buyer_yes<<endl;
			//				cout<<"seller_yes"<<seller_yes<<endl;
			return 0;
		}
	}
	int UpdateStatus()
	{
		if (approve)
		{
			status = "Delivered";
			return 1;
		}
		return 0;
	}
	int UpdateSatisfaction()
	{
		if (status == "Delivered" && !iscomplete)
		{
			int ch;
			cout << "ARE YOU SATISFAIED [1] FOR YES / [2] FOR NO ? \n ANSWER = ";
			cin >> ch;
			if (ch == 1)
			{
				//					cout<< " YEWESSSSSSSSSSS"<< endl;
				satisfaction = "Yes";
				return 1;
			}
			if (ch == 2)
			{
				//					cout<< " NOOOOOOOOOOO"<< endl;
				satisfaction = "No";
				return 2;
			}
			else
			{
				cout << "INCORRECT OPTION" << endl;
				return 0;
			}
		}
		return -1;
	}
	int write_to_file(string filename) const
	{
		fstream outfile(filename, std::ios::app);
		if (outfile.is_open())
		{
			outfile << title << endl;
			outfile << amount << endl;
			outfile << time << endl;
			outfile << buyer_yes << endl;
			outfile << seller_yes << endl;
			outfile << satisfaction << endl;
			outfile << status << endl;
			outfile << approve << endl;
			outfile << iscomplete << endl;
			outfile << buyergmail << endl;
			outfile << sellergmail << endl;
			outfile << buyerAccountNumber << endl;
			outfile << sellerAccountNumber << endl;
			outfile.close();
			//	            cout << "Attributes saved to file: "  << endl;
		}
		else
		{
			//	            cout << "Error: Unable to open file: " << filename << endl;
		}
		return 0;
	}
};
int Transection::ID = 0;
class Escrow
{
private:
	vector <User> users;
	Account escrow_account;
	vector <Transection> Trans;
	int x;
	string escrowAccountNumber;
public:
	Escrow()
	{

		readfromfile();
		readfromuserfile();

		//			Trans.push_back(Transection("RINGS",5000,"2-4-2023",false,true,"ghalibzaidi115@gmail.com","wali@gmail.com","1111-0220-0220-1111","1234-1234-1234-1234"));
		//			Trans.push_back(Transection("NECKLECE",7000,"7-2-2018",true,false,"wali@gmail.com","ghalibzaidi115@gmail.com","1234-1234-1234-1234","1111-0220-0220-1111"));
		//			Trans.push_back(Transection("CODE",3000,"15-8-2020",false,true,"ghalibzaidi115@gmail.com","wali@gmail.com","1111-0220-0220-1111","1234-1234-1234-1234"));
		//			Trans.push_back(Transection("DRESS",6000,"4-7-2013",true,false,"wali@gmail.com","ghalibzaidi115@gmail.com","1234-1234-1234-1234","1111-0220-0220-1111"));
		//			Trans.push_back(Transection("COMPUTER",3000,"25-12-2023",true,false,"wali@gmail.com","ghalibzaidi115@gmail.com","1234-1234-1234-1234","1111-0220-0220-1111"));
		//			Trans.push_back(Transection("LAPTOP",12000,"24-11-2014",true,true,"ghalibzaidi115@gmail.com","wali@gmail.com","1111-0220-0220-1111","1234-1234-1234-1234","Delivered",false));
		//			users.push_back(User("Ghalib","ghalibzaidi115@gmail.com","12345678",Account("1111-0220-0220-1111",1000000)));
		x = 0;
		escrow_account = { "0110-0110-0110-0110",100000 };
		escrowAccountNumber = "0110-0110-0110-0110";
	}
	void Khubsurti(string Name)
	{
		fflush(stdin);
		cout << "              Welcome to ESCROW PAYMENT METHOD  \n ";
		cout << "             +============================+          \n\n";
		cout << "                     $  " << Name << "  $ \n\n";
		if (Name.compare("HOME PAGE") && Name.compare("LOGIN PAGE") && Name.compare("SIGN UP PAGE"))
		{
			cout << " ________________________________________________________\n";
			cout << "   NAME :  " << users[x].getName() << "            AMOUNT :  " << users[x].getAccount().getBalance();
			cout << "\n ________________________________________________________\n\n";
		}
		if (Name.compare("LOGIN PAGE") && Name.compare("SIGN UP PAGE"))
		{
			cout << " || Please select the Option that you would like to do. || \n\n";
		}
	}
	int EscrowStart()
	{
		int op = 1;
		while (1)
		{
			system("cls");
			Khubsurti("HOME PAGE");
			cout << "\t\t      [1]  LOGIN \n";
			cout << "\t\t      [2]  SIGN UP \n";
			cout << "\t\t      [0]  EXIT\n\n";
			if (op > 2 || op < 0)
				cout << "\n\tPlease Choose Correctly\n\n";
			cout << "Enter your choice here : ";
			cin >> op;
			if (op == 0)
				break;
			else if (op == 1)
				Login();
			else if (op == 2)
				SignUp();
			else
				cout << "\n\tPlease Choose Correctly\n\n";
		}
		return 0;
	}
	int Login()
	{
		string gmail, pas;
		while (1)
		{
			system("cls");
			Khubsurti("LOGIN PAGE");
			cout << "\t\t    FOR EXIT PRESS [0] \n\n";
			cout << "\nEnter YOUR GMAIL : ";
			cin >> gmail;
			if (gmail[0] == '0')
				break;
			for (auto& c : gmail)
			{
				c = std::tolower(c);
			}
			cout << "\nEnter YOUR PASSWORD : ";
			cin >> pas;
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].checkgmail(gmail))
				{
					if (users[i].checkpasword(pas))
					{
						cout << "\n\t\t    LOGIN SUCCESSFUL\n";
						sleep(1);
						cout << "\n\t\t    WELLCOME MR. " << users[i].getName();
						sleep(1);
						x = i;
						UserFunction();
						return 0;
					}
					else
					{
						cout << "\n\t\tPLEASE ENTER CORRECT PASSWORD\n";
						sleep(1);
					}
				}

			}
			cout << "\n\t\tPLEASE ENTER CORRECT GMAIL FOR LOGIN \n";
			sleep(1);
		}
		return 0;
	}
	int SignUp()
	{
		string name;
		string gmail;
		string password;
		string account_num;
		double balance;
		system("cls");
		Khubsurti("SIGN UP PAGE");
		printf("\t\t    FOR EXIT PRESS [0] \n\n");
		cout << "ENTER YOUR NAME =  ";
		cin.ignore();
		getline(cin, name);
		if (name[0] == '0')
			return 0;
		fflush(stdin);
		cout << "ENTER YOUR GMAIL ID = ";
		cin >> gmail;
		if (gmail == "0")
			return 0;
		for (auto& c : gmail)
		{
			c = std::tolower(c);
		}
		gmail = checkgmail(gmail);
		cout << "ENTER YOUR PASSWORD = ";
		cin >> password;
		password = checkpassword(password, name);
		cout << "ENTER YOUR ACCOUNT NUMBER [0000-0000-0000-0000] = ";
		cin >> account_num;
		if (account_num == "0")
			return 0;
		regex pattern("^\\d{4}-\\d{4}-\\d{4}-\\d{4}$");
		while (!regex_match(account_num, pattern))
		{
			cout << "\t\t   INVALID ACCOUNT NUMBER" << endl;
			cout << "ENTER YOUR ACCOUNT NUMBER [0000-0000-0000-0000] = ";
			cin >> account_num;
			if (account_num == "0")
				return 0;
		}
		account_num = checkaccountnum(account_num);
		cout << "ENTER YOUR BALANCE = ";
		cin >> balance;
		balance = checkamount(balance);
		users.push_back(User(name, gmail, password, Account(account_num, balance)));
		cout << "\n\t\t    SIGNED UP SUCCESSULLY\n";
		sleep(1);
		return 0;
	}
	int UserFunction()
	{
		int ch = 0;
		while (1)
		{
			system("cls");
			fflush(stdin);
			Khubsurti("USER MENU");
			cout << "\t\t      [1] MY  ACCOUNT \n";
			cout << "\t\t      [2] MY TRANSECTION\n";
			cout << "\t\t      [3] MESSAGING\n";
			cout << "\t\t      [0] EXIT\n\n";
			if (ch > 3 || ch < 0)
				cout << "\n\tPlease Choose Correctly\n\n";
			fflush(stdin);
			cout << "Enter your choice here : ";
			scanf_s("%d", &ch);
			if (ch == 0)
				break;
			if (ch == 1)
				UserAccount();
			if (ch == 2)
				TransectionFunction();
			if (ch == 3)
				Messaging();
		}

		return 0;
	}
	int UserAccount()
	{
		int ch = 0;
		while (1)
		{
			system("cls");
			fflush(stdin);
			Khubsurti("ACCOUNT MENU");
			cout << "\t\t      [1] DEPOSITE \n";
			cout << "\t\t      [2] WITHDRAWL\n";
			cout << "\t\t      [0] EXIT\n\n";
			if (ch > 2 || ch < 0)
				cout << "\n\tPlease Choose Correctly\n\n";
			fflush(stdin);
			cout << "Enter your choice here : ";
			scanf_s("%d", &ch);
			if (ch == 0)
				break;
			if (ch == 1)
			{
				string acc;
				double amount;
				cout << "Enter Your Account Number : ";
				cin >> acc;
				acc = checkaccount_num(acc);
				cout << "Enter Amount You want to Deposite : ";
				cin >> amount;
				amount = checkamount(amount);
				users[x].deposite(acc, amount);
			}
			if (ch == 2)
			{
				string acc;
				double amount;
				cout << "Enter Your Account Number : ";
				cin >> acc;
				acc = checkaccount_num(acc);
				cout << "Enter Amount You want to Withdrawl : ";
				cin >> amount;
				amount = checkamount(amount);
				users[x].withdrawl(acc, amount);
			}
		}

		return 0;
		cout << "UserAccount();";
	}
	int TransectionFunction()
	{
		while (1)
		{
			system("cls");
			int ch = 0, flag = 0;
			fflush(stdin);
			Khubsurti("TRANSECTION MENU");
			cout << "\t\t      [1] ADD TRANSECTION \n";
			cout << "\t\t      [2] APPROVE TRANSECTION \n";
			cout << "\t\t      [3] UPDATE DELIVERY \n";
			cout << "\t\t      [4] CONFIRM PAYMENT \n";
			cout << "\t\t      [5] ALL TRANSECTION \n";
			cout << "\t\t      [6] ALL COMPLETED TRANSECTION \n";
			cout << "\t\t      [0] EXIT\n\n";
			if (ch > 3 || ch < 0)
				cout << "\n\tPlease Choose Correctly\n\n";
			fflush(stdin);
			cout << "Enter your choice here : ";
			scanf_s("%d", &ch);
			if (ch == 0)
				break;
			if (ch == 1)
				AddTransection();
			if (ch == 2)
				ApproveTransection();
			if (ch == 3)
				UpdateTransection();
			if (ch == 4)
				confirmPayment();
			if (ch == 5)
				allTransection();
			if (ch == 6)
				completedTransection();
		}

		return 0;
	}
	int AddTransection()
	{
		string title;
		double amount;
		string time;
		bool b_yes = false, s_yes = false;
		string buyergmail;
		string sellergmail;
		string buyerAccountNumber;
		string sellerAccountNumber;
		int ch = 1;
		cin.ignore();
		cout << "ENTER TITLE OF TRANSECTION [WITHOUT SPACE]= " << endl;
		getline(cin, title);
		fflush(stdin);
		cout << "ENTER AMOUNT OF TRANSECTION = " << endl;
		cin >> amount;
		amount = checkamount(amount);
		cout << "ENTER DATE OF INSPECTION (DD-MM-YYYY) = " << endl;
		cin >> time;
		time = isDateValid(time);

		cout << "ARE YOU = " << endl;
		cout << "[1] BUYER = " << endl;
		cout << "[2] SELLER = " << endl;
		while (1)
		{
			if (ch > 2 || ch < 0)
				cout << "\n\tPlease Choose Correctly\n\n";
			fflush(stdin);
			cout << "Enter your choice here : ";
			cin >> ch;
			if (ch == 0)
				break;
			if (ch == 1)
			{
				buyergmail = users[x].getGmail();
				//					cout<<"buyer gmail"<<users[x].getGmail();
				b_yes = true;
				cout << "ENTER YOUR ACCOUNT NUMBER = " << endl;
				cin >> buyerAccountNumber;
				buyerAccountNumber = checkaccount_num(buyerAccountNumber);
				cout << "ENTER SELLER GMAIL ID = ";
				cin >> sellergmail;
				while (buyergmail == sellergmail)
				{
					cout << "SELLER AND BUYER CANNOT BE THE SAME\n";
					cout << "ENTER SELLER GMAIL ID = ";
					cin >> sellergmail;
				}
				sellergmail = checkuservalidity(sellergmail);
				break;
			}
			if (ch == 2)
			{
				sellergmail = users[x].getGmail();
				s_yes = true;
				cout << "ENTER YOUR ACCOUNT NUMBER = " << endl;
				cin >> sellerAccountNumber;
				cout << "ENTER BUYER GMAIL ID = ";
				cin >> buyergmail;
				while (buyergmail == sellergmail)
				{
					cout << "SELLER AND BUYER CANNOT BE THE SAME\n";
					cout << "ENTER BUYER GMAIL ID = ";
					cin >> buyergmail;
				}
				buyergmail = checkuservalidity(buyergmail);
				break;
			}
		}
		Trans.push_back(Transection(title, amount, time, b_yes, s_yes, buyergmail, sellergmail, buyerAccountNumber, sellerAccountNumber));
		cout << "\n\t\t    TRANSECTION ADDED SUCCESSFULLY " << endl;
		sleep(1);
		return 1;
	}
	int ApproveTransection()
	{
		vector <int> id;
		int ch, flag_id = 1, flag_app = 1;
		while (1)
		{
			for (Transection T : Trans)
			{
				if (((users[x].checkgmail(T.getBuyergmail())) && (!T.getBuyerYes())) || ((users[x].checkgmail(T.getSellergmail())) && (!T.getSellerYes())))
				{
					//						cout<<"id "<<T.getID();
					id.push_back(T.getID());
					T.display();
				}
			}
			cout << "ENTER TRANSECTION ID YOU WANT TO APPROVE : ";
			cin >> ch;
			if (ch == 0)
			{
				return 0;
			}
			for (int i = 0; i < Trans.size(); i++)
			{
				//	cout<<"id ="<<id[i]<<"  Trans[i].getID()"<<Trans[i].getID()<<endl;
				if (Trans[i].getID() == ch)
				{
					flag_id = 0;
					//	cout<<"trans id match"<<endl;
					for (int j = 0; j < id.size(); j++)
					{
						//						cout<<"id ="<<id[j]<<"  Trans[i].getID()"<<Trans[i].getID()<<endl;
						if (Trans[i].getID() == id[j])
						{
							flag_app = 0;
							//								cout<<"match"<<Trans[i].getID()<<endl;
							string account_number;
							cout << "ENTER YOUR ACCOUNT NUMBER = ";
							cin >> account_number;
							account_number = checkaccount_num(account_number);
							if (users[x].checkgmail(Trans[i].getBuyergmail()))
							{
								//									cout<< " in buyer if"<<endl;
								Trans[i].setBuyerAccountNumber(account_number);
								Trans[i].setBuyerYes(true);
							}
							if (users[x].checkgmail(Trans[i].getSellergmail()))
							{
								//									cout<< " in seller if"<<endl;
								Trans[i].setSellerAccountNumber(account_number);
								Trans[i].setSellerYes(true);
							}
							if (DepositeToEscrow(Trans[i]))
							{
								if (Trans[i].UpdateApprove())
								{
									cout << "\n\t\t    APPROVED SUCCESSFULLY" << endl;
									sleep(1);
									break;
								}
								else
								{
									cout << "\n\t\t    APPROVED FAILD" << endl;
									sleep(1);
									break;
								}
							}
						}
						//approved or not your transection
					}
					if (flag_app)
					{
						flag_id = 0;
						cout << "\n\t\t    TRANSECTION ALREADY APPROVED OR IT IS NOT YOUR TRANSECTION. " << endl;
					}
				}
			}
			if (flag_id)
			{
				cout << "TRANSECTION ID NOT FOUND ...!" << endl;
			}
		}
	}
	int UpdateTransection()
	{
		vector <int> id;
		int ch;
		while (1)
		{
			for (Transection T : Trans)
			{
				if (users[x].checkgmail(T.getSellergmail()) && T.getApprove())
				{
					id.push_back(T.getID());
					T.display();
				}
			}
			cout << "ENTER TRANSECTION ID YOU WANT TO UPDATE : ";
			cin >> ch;
			if (ch == 0)
			{
				return 0;
			}
			for (int i = 0; i < Trans.size(); i++)
			{
				if (Trans[i].getID() == ch)
				{
					//cout<<"match"<<Trans[i].getID()<<endl;
					if (users[x].checkgmail(Trans[i].getSellergmail()))
					{
						if (Trans[i].UpdateStatus() == 1)
						{
							cout << "\n\t\t    UPDATED SUCCESSFULLY" << endl;
							sleep(1);
						}
						else
						{
							cout << "\n\t\t    UPDATE FAILD" << endl;
							sleep(1);
						}
					}
				}
			}
		}
	}
	int confirmPayment()
	{
		vector <int> id;
		int ch;
		int flag_app = 1, flag_id = 1;
		while (1)
		{
			for (Transection T : Trans)
			{
				if (users[x].checkgmail(T.getBuyergmail()) && !(T.getStatus().compare("Delivered")) && !T.getComplete())
				{
					id.push_back(T.getID());
					T.display();
				}
			}
			cout << "ENTER TRANSECTION ID FOR WHICH YOU WANT TO CONFIRM PAYMENT : ";
			cin >> ch;
			if (ch == 0)
			{
				return 0;
			}
			for (int i = 0; i < Trans.size(); i++)
			{
				//	cout<<"id ="<<id[i]<<"  Trans[i].getID()"<<Trans[i].getID()<<endl;
				if (Trans[i].getID() == ch)
				{
					flag_id = 0;
					//	cout<<"trans id match"<<endl;
					for (int j = 0; j < id.size(); j++)
					{
						//						cout<<"id ="<<id[j]<<"  Trans[i].getID()"<<Trans[i].getID()<<endl;
						if (Trans[i].getID() == id[j])
						{
							flag_app = 0;
							//										cout<<"match"<<Trans[i].getID()<<endl;
							if (users[x].checkgmail(Trans[i].getBuyergmail()))
							{
								if (Trans[i].UpdateSatisfaction())
								{
									if (WithdrawlFromEscrow(Trans[i]))
									{
										cout << "\n\t\t    TRANSECTION COMPLETED SUCCESSFULLY" << endl;
										Trans[i].UpdateComplete();
										sleep(1);
									}
									else
									{
										cout << "\n\t\t    TRANSECTION MONEY TRANSFER FAILED " << endl;
										sleep(1);
									}
								}
								else
								{
									cout << "\n\t\t    TRANSECTION CANCELED " << endl;
									sleep(1);
								}
							}

						}
						//approved or not your transection
					}
					if (flag_app)
					{
						flag_id = 0;
						cout << "\n\t\t    TRANSECTION ALREADY APPROVED OR IT IS NOT YOUR TRANSECTION. " << endl;
					}
				}
			}
			if (flag_id)
			{
				cout << "TRANSECTION ID NOT FOUND ...!" << endl;
			}
		}
	}
	int completedTransection()
	{
		while (1)
		{
			int ch = 0;
			for (Transection T : Trans)
			{
				if ((((users[x].checkgmail(T.getBuyergmail())) && (T.getBuyerYes())) || ((users[x].checkgmail(T.getSellergmail())) && (T.getSellerYes()))) && T.getApprove() && !(T.getStatus().compare("Delivered")) && T.getComplete())
				{
					T.display();
				}
			}
			cout << "ENTER ZERO TO EXIT : ";
			cin >> ch;
			if (ch == 0)
			{
				return 0;
			}
		}
	}
	int allTransection()
	{
		while (1)
		{
			int ch = 0;
			for (Transection T : Trans)
			{
				if ((users[x].checkgmail(T.getBuyergmail())) || (users[x].checkgmail(T.getSellergmail())))
				{
					T.display();
				}
			}
			cout << "ENTER ZERO TO EXIT : ";
			cin >> ch;
			if (ch == 0)
			{
				return 0;
			}
		}
	}

	//CHECKING GMAIL CORRECTNESS
	string checkgmail(const string email)
	{
		string gmail;
		gmail = email;
		int x = 0;
		do
		{
			x = 0;
			regex pattern("(\\w+)((\\.(\\w+))|(_(\\w+)))?@((yahoo)|(hotmail)|(gmail))\\.((com)|((co)\\.(\\w+)))");
			// If the email matches the pattern and is from Gmail, Yahoo, or Hotmail
			if (regex_match(gmail, pattern))
			{
				for (User U : users)
				{
					if (U.checkgmail(gmail))
					{
						cout << "\n\t\t   EMAIL ID ALREADY EXIST" << endl;
						x = 1;
						break;
					}
				}
			}
			else
			{
				cout << "\n\t\t   INCORRECT EMAIL FORMAT" << endl;
				x = 1;
			}

			if (x == 1)
			{
				cout << "\t\t   PLEASE ENTER AGAIN" << endl;
				cout << "\nENTER YOUR GMAIL ID  = ";
				cin >> gmail;
			}

			if (regex_match(gmail, pattern) && x == 0)
			{
				return gmail;
			}
		} while (1);
	}
	string checkuservalidity(string gmail)
	{
		do
		{
			for (User U : users)
			{
				if (U.checkgmail(gmail))
				{
					return gmail;
				}
			}
			cout << "\t\t   EMAIL ID DOESN'T EXIST " << endl;
			cout << "\t\t   PLEASE ENTER AGAIN" << endl;
			cout << "\nENTER YOUR GMAIL ID  = ";
			cin >> gmail;
		} while (1);
	}
	string checkpassword(string password, string username)
	{
		int x = 1;
		while (x)
		{
			bool has_upper = false, has_lower = false, has_digit = false, has_special = false;
			if (x != 1)
			{
				cout << "\n\t\t   CAN'T CONSIDER WEEK PASSWORD." << endl;
				sleep(1);
				cout << "ENTER YOUR PASSWORD AGAIN = ";
				cin >> password;
			}
			int password_len = static_cast<int>(password.length());

			// Check if password is the same as the username
			if (password.find(username) != string::npos)
			{
				cout << "\n\t\t   PASWORD SHOULD NOT CONTAIN USERNAME." << endl;
				sleep(1);
				x++;
				continue;
			}

			// Check if password is too common
			vector<string> common_passwords = { "password", "123456", "12345678", "1234", "qwerty", "abc123", "123123", "admin", "letmein", "monkey", "shadow", "sunshine", "12345", "password1", "trustno1" };
			int num_common_passwords = static_cast<int>(common_passwords.size());
			bool is_common = false;
			for (int i = 0; i < num_common_passwords; i++)
			{
				if (password == common_passwords[i])
				{
					cout << "\n\t\t   PASSWORD IS TOO COMMON." << endl;
					sleep(1);
					is_common = true;
					x++;
				}
			}
			if (is_common)
			{
				continue;
			}
			// Check if password contains uppercase, lowercase, digit, and special character
			for (int i = 0; i < password_len; i++)
			{
				char c = password[i];
				if (isupper(c))
				{
					has_upper = true;
				}
				else if (islower(c))
				{
					has_lower = true;
				}
				else if (isdigit(c))
				{
					has_digit = true;
				}
				else if (!isalnum(c))
				{
					has_special = true;
				}
			}

			if (!(has_upper && has_lower && has_digit && has_special))
			{
				fflush(stdin);
				cout << "\n\t\t   PASWORD SHOULD CONTAIN ATLEAST. \n\n\t\t   [1] ONE UPPERCASE LETTER. \n\t\t   [2] ONE LOWERCASE LETTER.\n\t\t   [3] ONE DIGIT.  \n\t\t   [4] ONE SPECIAL CHARACTER." << endl;
				sleep(1);
				x++;
				continue;
			}

			// Check password length
			if (password_len < 8 || password_len > 15)
			{
				cout << "\n\t\t   PASSWORD LENGTH SHOULD BE BETWEEN 8 TO 15 CHARACTERS." << endl;
				x++;
				sleep(1);
				continue;
			}
			// Password meets all requirements, return true
			x = 0;
			cout << "\n\t\t   PASWORD IS STRONG AND VALID." << endl;
			sleep(1);
			return password;
		}
		return "";
	}
	string checkaccountnum(string acc_num)
	{
		string account_number = acc_num;
		int x = 0;
		do
		{
			x = 0;
			for (User U : users)
			{
				if (U.checkaccn(account_number))
				{
					cout << "\n\t\t   ACCOUNT NUMBER ALREADY EXIST" << endl;
					x = 1;
					break;
				}
			}
			if (x == 0)
			{
				return account_number;
			}
			cout << "\t\t   INVALID ACCOUNT NUMBER" << endl;
			cout << "\t\t   PLEASE ENTER AGAIN" << endl;
			cout << "\nENTER YOUR ACCOUNT NUMBER  = ";
			cin >> account_number;
		} while (1);
	}
	string isDateValid(string dateStr)
	{
		while (true)
		{
			bool flag = true;
			if (dateStr.length() == 10)
			{
				//			        cout <<"lenght"<<endl;

									// Make sure the first and second characters are digits representing the day
				for (int i = 0; i < 2; i++) {
					if (!isdigit(dateStr[i])) {
						//				        cout <<"day"<<endl;
						flag = false;
					}
				}

				// Make sure the third character is a dash
				if (dateStr[2] != '-') {
					//				        cout <<"first daSH"<<endl;
					flag = false;
				}

				// Make sure the forth and fifth characters are digits representing the month
				for (int i = 3; i < 5; i++) {
					if (!isdigit(dateStr[i])) {
						//				        cout <<"mm"<<endl;
						flag = false;
					}
				}

				// Make sure the sixth character is a dash
				if (dateStr[5] != '-') {
					//				        cout <<"2 daSH"<<endl;
					flag = false;
				}

				// Make sure the last four characters are digits representing the year
				for (int i = 6; i < 10; i++) {
					if (!isdigit(dateStr[i])) {
						//				        cout <<"yy"<<endl;
						flag = false;
					}
				}

				// Convert the year, month, and day to integers
				int year, month, day;
				stringstream(dateStr.substr(0, 2)) >> day;
				stringstream(dateStr.substr(3, 2)) >> month;
				stringstream(dateStr.substr(6, 4)) >> year;

				// Make sure the month is between 1 and 12
				if (month < 1 || month > 12) {

					//				        cout <<"mm 12"<<endl;
					flag = false;
				}

				// Make sure the day is valid for the given month and year
				if (day < 1 || day > 31) {
					//				        cout <<"dd 31"<<endl;
					flag = false;
				}
				if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
					//				        cout <<"dd 31 and month 4 6 9 11"<<endl;
					flag = false;
				}
				if (month == 2 && (day == 30 || day == 31)) {

					//				        cout <<"mm2 dd 3031"<<endl;
					flag = false;
				}
				if (month == 2 && day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) {

					//				        cout <<"leep mm 2 d 29 year not %4 yes %100 not %400"<<endl;
					flag = false;
				}
			}
			else
			{
				flag = false;
			}

			if (flag)
			{
				return dateStr;
			}
			//		    	cout << "incorrect ";
			cout << "ENTER THE DATE AGAIN (DD-MM-YYYY) = ";
			cin >> dateStr;

		}
	}
	double checkamount(double amount)
	{
		do
		{
			if (amount <= 100000)
			{
				return amount;
			}
			cout << "\t\t   YOUR REQUESTED AMOUNT IS TOO MUCH..." << endl;
			cout << "\t\t   PLEASE ENTER AGAIN" << endl;
			cout << "\nENTER YOUR AMOUNT AGAIN  = ";
			cin >> amount;
		} while (1);
	}
	int DepositeToEscrow(Transection& T)
	{
		double amount=0.0;
		for (User& U : users)
		{
			if (U.checkgmail(T.getBuyergmail()))
			{
				amount = U.withdrawl(T.getBuyerAccountNumber(), T.getAmount());
				//					cout<< T.getBuyerAccountNumber()<<endl;
			}
		}
		if (amount != 0)
		{
			return escrow_account.deposite(escrowAccountNumber, amount);
		}
		return 0;
	}
	int WithdrawlFromEscrow(Transection& T)
	{
		double amount = escrow_account.withdrawl(escrowAccountNumber, T.getAmount());
		if (amount != 0)
		{
			for (User U : users)
			{
				//					cout<< " in loop "<< endl;
				//					cout<< "gmail" << U.checkgmail(T.getSellergmail())<< " approve "<< T.getApprove() << " status"<<T.getStatus()<< T.getStatus().compare("Delivered")<< endl; 
				if (U.checkgmail(T.getSellergmail()) && T.getApprove() && !T.getStatus().compare("Delivered"))
				{
					//						cout<< " checking gmail approved status "<< endl;
					if (!T.getSatisfaction().compare("Yes"))
					{
						int x = U.deposite(T.getSellerAccountNumber(), amount);
						//							cout<< " in if  returning "<<x<< endl;
						return x;
					}
					if (!T.getSatisfaction().compare("No"))
					{

						int v = (U.deposite(T.getSellerAccountNumber(), amount / 2)) + (users[x].deposite(T.getBuyerAccountNumber(), amount / 2));
						//							cout<< " in else  returning "<<v<< endl;
						return v / 2;
					}
				}
			}
		}
		return 0;
	}
	void readfromuserfile()
	{
		ifstream infile("Users.txt", ios::in);
		if (infile.is_open())
		{
			string name;
			string gmail;
			string password;
			string account_number;
			double amount;
			while (getline(infile, name))
			{
				cout << "Attributes read from user file: " << endl;

				stringstream s;
				string temp;
				getline(infile, gmail);
				getline(infile, password);
				getline(infile, account_number);
				getline(infile, temp);
				stringstream(temp) >> amount;

				//			            cout << "      name        : " << name << endl;
				//			            cout << "      Amount       : " << amount << endl;
				//			            cout << "      Gmail  : " << gmail << endl;
				//			            cout << "      password : " << password << endl;
				//			            cout << "      AccountNumber : " << account_number << endl;

				users.push_back(User(name, gmail, password, Account(account_number, amount)));

			}
			infile.close();
		}
		else
		{
			cout << "Error: Unable to open user file: " << endl;
		}

	}
	void readfromfile()
	{
		ifstream infile("Transection.txt", ios::in);
		if (infile.is_open())
		{
			string title;
			double amount;
			string time;
			bool buyer_yes;
			bool seller_yes;
			string buyergmail;
			string sellergmail;
			string buyerAccountNumber;
			string sellerAccountNumber;
			bool approve;
			string status;
			string satisfaction;
			bool iscomplete;
			while (getline(infile, title))
			{
				cout << "Attributes read from file: " << endl;

				stringstream ss;
				string temp;
				getline(infile, temp);
				stringstream(temp) >> amount;
				getline(infile, time);
				getline(infile, temp);
				stringstream(temp) >> buyer_yes;
				getline(infile, temp);
				stringstream(temp) >> seller_yes;
				getline(infile, satisfaction);
				getline(infile, status);
				getline(infile, temp);
				stringstream(temp) >> approve;
				getline(infile, temp);
				stringstream(temp) >> iscomplete;
				getline(infile, buyergmail);
				getline(infile, sellergmail);
				getline(infile, buyerAccountNumber);
				getline(infile, sellerAccountNumber);
				//			            cout << "      Title        : " << title << endl;
				//			            cout << "      Amount       : " << amount << endl;
				//			            cout << "      Time         : " << time << endl;
				//			            cout << "      Status       : " << status << endl;
				//			            cout << "      Buyer Gmail  : " << buyergmail << endl;
				//			            cout << "      Seller Gmail : " << sellergmail << endl;
				//			            cout << "      buyerAccountNumber : " << buyerAccountNumber << endl;
				//			            cout << "      sellerAccountNumber : " << sellerAccountNumber << endl;
				//			            cout << "      approve : " << approve << endl;
				//			            cout << "      satisfaction : " << satisfaction << endl;
				//			            cout << "      status : " << status<< endl;
				//			
				//			            if (approve)
				//			                cout << "      APPROVED      " << endl;
				//			            else
				//			                cout << "      NOT APPROVED  " << endl;
				Trans.push_back(Transection(title, amount, time, buyer_yes, seller_yes, buyergmail, sellergmail, buyerAccountNumber, sellerAccountNumber, approve, status, satisfaction, iscomplete));

			}
			infile.close();
		}
		else
		{
			cout << "Error: Unable to open file: " << endl;
		}

	}
	void readMessagesFromFile(string filename)
	{
		ifstream file(filename, ios::app);

		if (!file.is_open()) {
			cerr << "Failed to open " + filename << endl;
			exit(EXIT_FAILURE);  // If we can't open the file, terminate the program
		}

		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
	}
	void openFileForAppending(string& sfilename, string& rfilename, string msg)
	{
		ofstream sfile(sfilename, ios::app);
		ofstream rfile(rfilename, ios::app);

		if (!sfile.is_open() || !rfile.is_open()) {
			cerr << "Failed to open file for appending." << endl;
			exit(EXIT_FAILURE);  // If we can't open the file, terminate the program
		}

		sfile << users[x].getGmail() << ": " << msg << endl;
		rfile << users[x].getGmail() << ": " << msg << endl;
	}
	void Messaging()
	{
		string semail;
		string remail;
		string message;
		semail = users[x].getGmail();
		cout << "SENDER : " << semail << endl;
		cout << "ENTER RECIVER'S NAME [0 to EXIT] : ";
		cin >> remail;
		remail = checkuservalidity(remail);
		string sfilename = semail + remail + ".txt";
		string rfilename = remail + semail + ".txt";
		fflush(stdin);
		do
		{
			system("CLS");
			Khubsurti("MESSAGING");
			cout << "\n\t\t    MESSAGING  " << endl;
			cout << "\n\t[" << semail << "] AND [" << remail << "]\n" << endl;
			// Read previous messages from the file
			readMessagesFromFile(sfilename);

			// Get the new message from the sender
			cout << users[x].getGmail() << ": ";
			getline(cin, message);
			if (message == "0")
				break;
			// Write the new message to the file
			openFileForAppending(sfilename, rfilename, message);

		} while (message != "0");
	}
	string checkaccount_num(string acc_num)
	{
		do
		{
			if (acc_num.length() == 19)
			{
				int flag = 1;
				for (int i = 0; i < acc_num.length(); i++)
				{
					if (i == 4 || i == 9 || i == 14)
					{
						if (acc_num[i] != '-')
						{
							flag = 0;
							break;
						}
					}
					else
					{
						if (!(acc_num[i] >= '0' || acc_num[i] <= '1' || acc_num[i] <= '2' || acc_num[i] <= '3' || acc_num[i] <= '4' || acc_num[i] <= '5' || acc_num[i] <= '6' || acc_num[i] <= '7' || acc_num[i] <= '8' || acc_num[i] <= '9'))
						{
							flag = 0;
							break;
						}
					}
				}
				if (flag)
				{
					return acc_num;
				}
			}
			cout << "\t\t   INVALID ACCOUNT NUMBER" << endl;
			cout << "\t\t   PLEASE ENTER AGAIN" << endl;
			cout << "\nENTER YOUR ACCOUNT NUMBER  = ";
			cin >> acc_num;
		} while (1);
	}
	~Escrow()
	{
		string filename = "Transection.txt";
		ofstream file1(filename, std::ios::out);
		for (int i = 0; i < Trans.size(); i++)
		{
			Trans[i].write_to_file(filename);
		}
		filename = "Users.txt";
		ofstream file2(filename, std::ios::out);
		for (int i = 0; i < users.size(); i++)
		{
			users[i].write_to_file(filename);
		}
	}
};
int main()
{
	Escrow E;
	E.EscrowStart();
}

