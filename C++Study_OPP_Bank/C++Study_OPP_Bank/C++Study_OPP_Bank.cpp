#include <iostream>

/* 통장의 계좌번호는 중복지 않는다는 가정.
   입금 및 출금금액은 무조건 0보다 크다는 가정
   고객의 계좌정보는 계좌번호(accountNum), 고객이름(name), 고객의 잔액(money), 이렇게 세가지만 저장 및 관리한다.
   둘 이상의 고객 정보 저장을 위해서 배열을 사용한다.(10개로 제한)
   계좌번호는 정수의 형태이다.
*/

void menu();
void printMenu();
void accountOpen();
void deposit();
void withdraw();
void allAccountInfo();

using namespace std;

int client_count = 0;

typedef struct _client
{
	char name[10];
	int accountNum;
	int money;
}client;

client clientNum[10];

int main(void)
{
	menu();
}

void menu()
{
	int choice;
	while(1)
	{
		system("cls");
		printMenu();
		cin>>choice;
		if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)//얘 switch defalt로 하는거랑 차이가 뭘까?
		{
			switch(choice)
			{
			case 1:
				accountOpen();
				break;
			case 2:
				deposit();
				break;
			case 3:
				withdraw();
				break;
			case 4:
				allAccountInfo();
				break;
			case 5:
				exit(1);
				break;
			}
		}

	}

}

void printMenu()
{
	cout<<"-------Menu--------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void accountOpen()
{
	if(client_count == 10)
	{
		cout<<"새로운 계좌를 만들 수 없습니다."<<endl;
	}
	else
	{
		printf("새로 만들 계좌의 번호를 입력하세요.\n");
		scanf("%d", &clientNum[client_count].accountNum);
		printf("이름을 입력하세요.\n");
		cin>>clientNum[client_count].name;
		printf("예금 금액을 입력하세요. (예금을 원하지 않으시면 0을 입력하세요.)\n");
		scanf("%d", &clientNum[client_count].money);
		printf("%s님이 개설하신 계좌의 번호는 %d이며, 현재 예치금은 %d원 입니다.", clientNum[client_count].name, clientNum[client_count].accountNum,
			clientNum[client_count].money);
		client_count++;
	}
	getchar();
	getchar();
}

void deposit()
{
	int accNum, i, deposit;
	printf("예금 할 계좌번호를 입력하세요\n");
	scanf("%d", &accNum);
	for(i = 0; i < 10; i++)
	{
		if(clientNum[i].accountNum == accNum)
		{
			printf("%s님의 계좌에 입금하실 금액을 입력하세요\n", clientNum[i].name);
			scanf("%d", &deposit);
			clientNum[i].money += deposit;
			printf("%s님의 계좌에 %d원이 입금되어 %d원이 있습니다.\n", clientNum[i].name, deposit, clientNum[i].money);
			break;
		}
		else
		{
			printf("%d의 계좌번호는 존재하지 않는 번호입니다.\n", accNum);
		}
	}
	fflush(stdin);
	getchar();
}


void withdraw()//잔액부족 추가할것
{
	int accNum, i, withdraw;
	printf("출금 할 계좌번호를 입력하세요\n");
	scanf("%d", &accNum);
	for(i = 0; i < 10; i++)
	{
		if(clientNum[i].accountNum == accNum)
		{
			printf("%s님의 계좌에 출금하실 금액을 입력하세요\n", clientNum[i].name);
			scanf("%d", &withdraw);
			clientNum[i].money -= withdraw;
			printf("%s님의 계좌에 %d원이 출금되어 %d원이 있습니다.\n", clientNum[i].name, withdraw, clientNum[i].money);
			break;
		}
		else
		{
			printf("%d의 계좌번호는 존재하지 않는 번호입니다.\n", accNum);
		}
	}
	getchar();
	getchar();
}

void allAccountInfo()
{
	int i;
	for(i = 0; i < client_count; i++)
	{
		printf("-----------모든 고객의 정보------------\n");
		printf("계좌번호 : %d\n", clientNum[i].accountNum);
		printf("고객이름 : %s\n", clientNum[i].name);
		printf("계좌잔액 : %d\n", clientNum[i].money);
	}
	getchar();
	getchar();
}
//fflush(stdin);