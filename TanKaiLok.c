#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#pragma warning(disable:4996)
void logo();
void menu();
void answer();
void ordering();
void orderYes();
void orderNote();
void wrongDeposit();
void deliveryNote();
void deliveryAnswer();
void deliveryService();
void orderSummary();
void goodBye();
//variables declaration
//date
int day, month, year;

// user input to decide whether to start and continue ordering
int answerYes, nextOrder, orderno = 0, member;

// quantity of cookies purchased
int numLL, numNC, numAC,num;

// prices of cookies
const double PRICELL = 25.00, PRICENC = 20.00, PRICEAC = 15.00;

// dicount provided
const double DISCOUNT1 = 0.05, DISCOUNT2 = 0.10; //for non-member
const double DISCOUNT3 = 0.15, DISCOUNT4 = 0.20; //for member

// amount of purchases
double totalLL, totalNC, totalAC;
double orderTotal, amountToPay;
double discount, deposit, balance;
char  confirmOrder, deliveryYes;
int finalNumLL = 0, finalNumNC = 0, finalNumAC = 0;
double finalTotalLL, finalTotalNC, finalTotalAC, finalTotal, finalDiscount = 0, finalSales, finalDeposit = 0, finalBalance;

//delivery details
char addressLine1[30], addressLine2[30], addressLine3[30], customerName[20], customerTele[12], staffName[20] = "Tan Kai Lok", staffContact[13] = "017-3335118";
double deliveryCharge, totalDelivery = 0;


void main()
{
	// first 0 = black background and second B = light aqua blue font
	system("color 0B"); 
	// to maximise the size of console window
	HWND hWnd = GetConsoleWindow();
	SendMessage(hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	logo();
	menu();
	answer();
	orderSummary();
	getch();
	system("cls");
	goodBye();
	system("cls");
}

//logo
void logo()
{
	printf("\n\t===============================================================================================================================================\n");
	printf("\t===============================================================================================================================================\n");
	printf("\t||\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     ||\n\t||\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     ||\n\t||          ``.::///:.``            ``.:///:-.`                   `..------.``            ....         `....`   `...      `.............`    ||\n");
	printf("\t||        `-oydmmmmmmmmdy+        `:ohmmmmmmmmmds/.             `-:////////////:-`         hmmh       `/hmmd/`   :mmm-     :mmmmmmmmmmmmm/   ||\n");
	printf("\t||       :ymmmhs+::::+sdmy      `odmmdyo/:::/+sdmmms.         `:///os///+/+yy+////-`       hmmh     `/hmmd+`     :mmm-     :mmmsooooooooo-   ||\n");
	printf("\t||     `smmmo-          -:     :dmmh/`         `:ymmm+       -///o//////o++sy+/shyo/.      hmmh   `:hmmd+`       :mmm-     :mmm-             ||\n");
	printf("\t||    `hmmd-                  /mmmo`              /mmms     -///+o///+yhy+///+/ydds//.     hmmh  :hmmd+`         :mmm-     :mmm-             ||\n");
	printf("\t||    ommm.                  .mmms                 /mmm:   `/////////ommms//+hs///++//     hmmh-ymmd+`           :mmm-     :mmm/---------    ||\n");
	printf("\t||    mmms                   +mmm.                  dmmy   -///yho/oo/+o+//+so////oo//`    hmmmmmmy`             :mmm-     :mmmmmmmmmmmmm.   ||\n");
	printf("\t||   `mmm+                   ommm`                  hmmh   -///++///yo////+mmmy//y+///`    hmmmdmmms`            :mmm-     :mmmo+++++++++    ||\n");
	printf("\t||    dmmh                   :mmm/                 .mmmo   ./+dmmo//////oo/oys+///////     hmmh`:dmmd/           :mmm-     :mmm-             ||\n");
	printf("\t||    :mmm+                   hmmd-               `ymmd`    :/sys+//o+//++/////oyyo//-     hmmh  `ommmh-         :mmm-     :mmm-             ||\n");
	printf("\t||     /mmms.            `    `hmmm+`            :dmmd.      ://++os+//+yh/oo//hmmy/-      hmmh    -hmmmo`       :mmm-     :mmm-             ||\n");
	printf("\t||      -hmmmy/.      ./yy      +mmmds:`     `-+hmmms`        -/++hds/.  `:-://////.       hmmh      /mmmd/      :mmm-     :mmm-`````````    ||\n");
	printf("\t||        :smmmmmdhhdmmmmy       `+hmmmmmdhddmmmmdo.            -://:`       ://:.         hmmh       .smmmy.    :mmm-     :mmmmmmmmmmmmm/   ||\n");
	printf("\t||          `-+syhhhhyo/-`          `:+syhhhyso/.                 `..        -.`           +ss+         :ssso.   -sss.     -sssssssssssss-   ||\n");
	printf("\t||\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t                                    `....`                     \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t`++++++++++o-   -o+o:        `-+o/+sssssss/`     `.://///-`    \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t`sssssssssss-  .sssss.    `/ossss+-` `-osss/   -+so+/+osssso-  \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t    .sss:     `ossssss`   `/ssss:     `-yss: `+s+.     -ss+:`  \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t    `ysy-     +sso`oss+`    +ssy- `:+++ss+-  osy`      `-`     \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t    `ysy-    :sss-`-sss/    +ssy.`osss/.`   `ssy-              \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t    `ysy-   -sssssssssss-   ossy. `+sss:    `ssss-`       ``   \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t    `ysy-  .sss+++++++sss.  osss`   -oss+`   -sssso/:---:++-   \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t    .sss- `oss+`      +sso` o+:.     `:oso-`  ./oossssoo/-`    \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t    `...` `...`       `...` `          `/ss+-`  ``....`        \t\t\t\t\t     ||\n");
	printf("\t||\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     ||\n");
	printf("\t===============================================================================================================================================\n");
	printf("\t===============================================================================================================================================\n");
	printf("\n\n\t\t\t\t\t\tWELCOME TO TARUC FESTIVE COOKIES SDN BHD !!! \n\n");
	printf("\t\t\t\t\t\tThis is our COOKIES ORDERING SYSTEM.\n\n");
	printf("\t\t\t\t\t\tLet's get started by entering today's date !! :\n");

	//user input to enter day, month, year
	printf("\n\t\t\t\t\t\tEnter a month :");
	num = 0;
	num=scanf("%d", &month);
	rewind(stdin);
	// validation of input
	if (month > 12 || month <= 0 ||num!=1) //if invalid input such as month 13 or alphabet is entered
	{
		do {
			printf("\t\t\t\t\t\tError, enter again.");
			printf("\n\n\t\t\t\t\t\tEnter a month :");
			num=scanf("%d", &month);
			rewind(stdin);
		} while (month > 12 || month <= 0 || num != 1);
	}
	printf("\n\t\t\t\t\t\tEnter a day of the month :");
	num = 0;
	num=scanf("%d", &day);
	rewind(stdin);
	if (month == 4 || month == 6 || month == 9 || month == 11) // if it is one if the months APRIL , JUNE, SEPTEMBER, NOVEMBER
	{
		if(day > 30 || day <= 0 ||num!=1)//when invalid input such as day 31 or alphabet is entered
		{
			do {
				printf("\t\t\t\t\t\tError, enter again.");
				printf("\n\n\t\t\t\t\t\tEnter a day of the month :");
				num=scanf("%d", &day);
				rewind(stdin);
			} while (day > 30 || day <= 0 || num != 1);
		}
	}
	else if (month == 2) // if it is February
	{
		if(day > 29 || day <= 0||num!=1)//when invalid input such as day 30 or alphabet is entered
		{
			do {
				printf("\t\t\t\t\t\tError, enter again.");
				printf("\n\n\t\t\t\t\t\tEnter a day of the month :");
				num=scanf("%d", &day);
				rewind(stdin);
			} while (day > 29 || day <= 0 || num != 1);
		}
	}
	else // if it is one of the months JANUARY, MARCH, MAY, JULY, AUGUST, OCTOBER, DECEMBER
	{
		if(day > 31 || day <= 0||num!=1) //when invalid input such as day 32 or alphabet is entered
		{
			do {
				printf("\t\t\t\t\t\tError, enter again.");
				printf("\n\n\t\t\t\t\t\tEnter a day of the month :");
				num=scanf("%d", &day);
				rewind(stdin);
			} while (day > 31 || day <= 0 || num != 1);
		}
	}//end if

	printf("\n\t\t\t\t\t\tEnter a year :");
	num = 0;
	num=scanf("%d", &year);
	rewind(stdin);
	if (year >= 10000 || year < 1000||num!=1)//when the year is invalid such as year 10000 or alphabet
	{
		do {
			printf("\t\t\t\t\t\tError, enter again.");
			printf("\n\n\t\t\t\t\t\tEnter a year :");
			num=scanf("%d", &year);
			rewind(stdin);
		} while (year >= 10000 || year < 1000 || num != 1);
	}
	printf("\n\t\t\t\t\t\tToday is (DD/MM/YYYY) :%d/%d/%d", day, month, year); // Show today's date
	printf("\n\tPress 'ENTER' key to show menu.");
	getch();
	system("cls");
}

void menu()
{
	//type and price of cookies
	printf("\n\tWe sell three different type of cookies and we can assure you that they taste equally good !!!");
	printf("\n\n\tPlease take a look at our menu below :\n\n");
	printf(" \t---------------------------------------------------------------------------------\n");
	printf(" \t|\t\t\t|\t\t\t|\t\t\t\t|\n \t|\tCategory\t|\tUnit\t\t|\tPrice(RM)per unit\t|\n \t|\t\t\t|\t\t\t|\t\t\t\t|\n");
	printf(" \t---------------------------------------------------------------------------------\n");
	printf(" \t|\tLove Letters\t|\t\t\t|\t\t\t\t|");
	printf(" \n \t|\t(Kuih Kapit)\t|\ttin\t\t|\t%10.2f\t\t|\n \t|\t\t\t|\t\t\t|\t\t\t\t|\n", PRICELL);
	printf(" \t---------------------------------------------------------------------------------\n");
	printf(" \t|\t\t\t|\t\t\t|\t\t\t\t|\n");
	printf(" \t|\tNut Cookies\t|\tjar\t\t|\t%10.2f\t\t|\n \t|\t\t\t|\t\t\t|\t\t\t\t|\n", PRICENC);
	printf(" \t---------------------------------------------------------------------------------\n");
	printf(" \t|\tAssorted\t|\t\t\t|\t\t\t\t|\n");
	printf(" \t|\tCookies\t\t|\tjar\t\t|\t%10.2f\t\t|\n \t|\t\t\t|\t\t\t|\t\t\t\t|\n", PRICEAC);
	printf(" \t---------------------------------------------------------------------------------\n");
	printf("\n \tWe are also having discounts when you meet the requirements as below:\n"); // discount provided
	printf(" \t-----------------------------------------------------------------------------------------------------");
	printf("\n \t|For non-member:\t\t\t\t\t\t\t\t\t\t    |\n \t|5%% for orders totaling between RM 500 and RM 1000 (inclusive)\t\t\t\t\t    |\n"); //non-member discount
	printf(" \t|10 % % for orders totaling more than RM1000                     \t\t\t\t\t    |");
	printf("\n \t-----------------------------------------------------------------------------------------------------\n");
	printf(" \t|For member:\t\t\t\t\t\t\t\t\t\t\t    |\n \t|15%% for orders totaling between RM 500 and RM 1000 (inclusive)\t\t\t\t\t    |\n");//member discount
	printf(" \t|20 % % for orders totaling more than RM1000                     \t\t\t\t\t    |\n \t|Even if your purchase doesn't exceed RM500, you can still enjoy a basic discount of 5%% as a member.|");
	printf("\n \t-----------------------------------------------------------------------------------------------------\n\n");
	printf("\n\tPlease note that if you are allergic to nut DO NOT ORDER nut cookies but do try out the two other type of cookies we have :))");
	printf("\n\n===============================================================================================================================================================\n===============================================================================================================================================================\n\n");
}

void answer() // user decides if to start ordering
{
	printf("\tStart ordering(Y=yes)? : ");
	rewind(stdin);
	scanf("%c", &answerYes);
	if (answerYes == 'y' || answerYes == 'Y') // when user starts ordering
		ordering();
	else if (answerYes == 'n' || answerYes == 'N') // when user doesn't start ordering
	{
		printf("\tOK thanks for visiting.\n");
		printf("\tPress 'ENTER' key to return to main page.");
		getch();
		system("cls");
		main();
	}
	else //when something else is entered
	{
		printf("\tError, please enter again.\n");
		answer();
	}
}

void ordering() //order process
{
	do {
		system("cls");
		printf("\n\n\tOrder No : %d\n", ++orderno); // increment order number by 1
		printf("\t==============================================================\n");
		printf("\n\tItem\t\t\t\t\tQuantity Required\n");
		printf("\t=========\n\n");
		printf("\t-LOVE LETTERS\t@RM %.2f per tin\t:\t", PRICELL); // get quantity of loveletters
		num = 0;
		num=scanf("%d", &numLL);
		rewind(stdin);
		if (numLL < 0 || num != 1) // when invalid digit or alphabet is entered
			{
			do {
				printf("\tPlease dont key in invalid number\n\n");
				printf("\t-LOVE LETTERS\t@RM %.2f per tin\t:\t", PRICELL);
				num = scanf("%d", &numLL);
				rewind(stdin);
			} while (numLL < 0 || num != 1);
		} 		
		totalLL = PRICELL * numLL;
		printf("\n\t\tLove Letters Order = \t\t\tRM %10.2f\n", totalLL);
		printf("\t\tOrder Subtotal\t   =\tRM%10.2f\n\n", totalLL);
		printf("\t-NUT COOKIES\t@RM %.2f per jar\t:\t", PRICENC); // get quantity of nut cookies
		num = 0;
		num = scanf("%d", &numNC);
		rewind(stdin);
		if (numNC < 0 || num != 1) // when invalid digit or alphabet is entered
		{
			do {
				printf("\tPlease dont key in invalid number\n\n");
				printf("\t-NUT COOKIES\t@RM %.2f per jar\t:\t", PRICENC);
				num=scanf("%d", &numNC);
				rewind(stdin);
			} while (numNC < 0 || num != 1);
		}
		totalNC = PRICENC * numNC;
		printf("\n\t\tNut Cookies Order  = \t\t\tRM %10.2f\n", totalNC);
		printf("\t\tOrder Subtotal\t   =\tRM%10.2f\n\n", totalLL + totalNC);
		printf("\t-ASST COOKIES\t@RM %.2f per jar\t:\t", PRICEAC); // get quantity of assorted cookies
		num = 0;
		num=scanf("%d", &numAC);
		rewind(stdin);
		if (numAC < 0 || num != 1) // when invalid digit or alphabet is entered
		{
			do {
				printf("\tPlease dont key in invalid number\n\n");
				printf("\t-LOVE LETTERS\t@RM %.2f per tin\t:\t", PRICEAC);
				num= scanf("%d", &numAC);
				rewind(stdin);
			} while (numAC < 0 || num != 1);
		}
		totalAC = PRICEAC * numAC;
		printf("\n\t\tAsst Cookies Order = \t\t\tRM %10.2f\n", totalAC);
		printf("\t\t\t\t\t\t\t-------------");
		orderTotal = totalLL + totalNC + totalAC;
		printf("\n\n\t\t\t\tORDER TOTAL\t:\tRM %10.2f\n", orderTotal);
		orderYes();
		printf("\n\n\tContinue to accept next order ? (y=yes)(n=no) :\t");
		scanf("%c", &nextOrder);
		rewind(stdin);
		if (nextOrder == 'n' || nextOrder == 'N')
		{
			printf("\n\tOrdering of today ends here, press'ENTER' to show order summary.");
			getch();
			system("cls");
		}
		else
		{
			printf("\n\tError, enter again.");
			printf("\n\n\tContinue to accept next order ? (y=yes)(n=no) :\t");
			scanf("%c", &nextOrder);
			rewind(stdin);
		}
	} while (nextOrder == 'y' || nextOrder == 'Y');	
}

void orderYes()
{
	// confirmation of order
	printf("\n\tConfirm / Cancel order (y = confirm)?\t");
	rewind(stdin);
	scanf("%c", &confirmOrder);
	if (confirmOrder == 'y' || confirmOrder == 'Y') //when the order is confirmed
	{
		printf("\n\tAre you a member ? (y = yes) >\t"); //ask if the customer is a member
		rewind(stdin);
		scanf("%c", &member);
		if (member == 'n' || member == 'N') //if customer is not a member
		{
			if (orderTotal >= 500 && orderTotal <= 1000) // test if the amount is within the range of 5% discount
			{
				printf("\n\t\t\tDISCOUNT (5%%)\t\t:\tRM %10.2f\n", discount = DISCOUNT1 * orderTotal);
				amountToPay = orderTotal - discount;
				printf("\n\t\t\tAMOUNT TO PAY \t\t:\tRM %10.2f\n", amountToPay);
				printf("\n\t\t\tDEPOSIT       \t\t:\tRM\t");
				num = 0;
				num=scanf("%lf", &deposit);
				rewind(stdin);
				wrongDeposit();
				balance = amountToPay - deposit;
				printf("\t\t\t\t\t\t\t-------------");
				printf("\n\t\t\tBALANCE       \t\t:\tRM %10.2f", balance);
				printf("\n\t\t\t\t\t\t\t-------------");
				printf("\n\n\t==============================================================\n");
				printf("\n\tPress 'ENTER' key to show order note.");
				getch();
				orderNote();
			}
			else if (orderTotal > 1000) //test if the amount is within the range for discount of 10%
			{
				printf("\n\t\t\tDISCOUNT (10%%)\t\t:\tRM %10.2f\n", discount = DISCOUNT2 * orderTotal);
				amountToPay = orderTotal - discount;
				printf("\n\t\t\tAMOUNT TO PAY \t\t:\tRM %10.2f\n", amountToPay);
				printf("\n\t\t\tDEPOSIT       \t\t:\tRM\t");
				num = 0;
				num = scanf("%lf", &deposit);				
				rewind(stdin);
				wrongDeposit();
				balance = amountToPay - deposit;
				printf("\t\t\t\t\t\t\t-------------");
				printf("\n\t\t\tBALANCE       \t\t:\tRM %10.2f", balance);
				printf("\n\t\t\t\t\t\t\t-------------");
				printf("\n\n\t==============================================================\n");
				printf("\n\tPress 'ENTER' key to show order note.");
				getch();
				orderNote();
			}
			else // no discount is given
			{
				printf("\n\t\t\tDISCOUNT (0%%)\t\t:\tRM %10.2f\n", discount = 0 * orderTotal);
				amountToPay = orderTotal;
				printf("\n\t\t\tAMOUNT TO PAY \t\t:\tRM %10.2f\n", amountToPay);
				printf("\n\t\t\tDEPOSIT       \t\t:\tRM\t");
				num = 0;
				num = scanf("%lf", &deposit);
				rewind(stdin);
				wrongDeposit();
				balance = orderTotal - deposit;
				printf("\t\t\t\t\t\t\t-------------");
				printf("\n\t\t\tBALANCE       \t\t:\tRM %10.2f", balance);
				printf("\n\t\t\t\t\t\t\t-------------");
				printf("\n\n\t==============================================================\n");
				printf("\n\tPress 'ENTER' key to show order note.");
				getch();
				orderNote();
			}
		}
		else if (member == 'y' || member == 'Y') //if customer is a member
		{
			if (orderTotal >= 500 && orderTotal <= 1000) // when the order totalling is between RM500 and RM1000, 15% of discount
			{
				printf("\n\t\t\tDISCOUNT (15%%)\t\t:\tRM %10.2f\n", discount = DISCOUNT3 * orderTotal);
				amountToPay = orderTotal - discount;
				printf("\n\t\t\tAMOUNT TO PAY \t\t:\tRM %10.2f\n", amountToPay);
				printf("\n\t\t\tDEPOSIT       \t\t:\tRM\t");
				num = 0;
				num = scanf("%lf", &deposit);
				rewind(stdin);
				wrongDeposit();
				balance = amountToPay - deposit;
				printf("\t\t\t\t\t\t\t-------------");
				printf("\n\t\t\tBALANCE       \t\t:\tRM %10.2f", balance);
				printf("\n\t\t\t\t\t\t\t-------------");
				printf("\n\n\t==============================================================\n");
				printf("\n\tPress 'ENTER' key to show order note.");
				getch();
				orderNote();
			}
			else if (orderTotal > 1000) //when the amount exceeds RM1000, 20% of discount
			{
				printf("\n\t\t\tDISCOUNT (10%%)\t\t:\tRM %10.2f\n", discount = DISCOUNT4 * orderTotal);
				amountToPay = orderTotal - discount;
				printf("\n\t\t\tAMOUNT TO PAY \t\t:\tRM %10.2f\n", amountToPay);
				printf("\n\t\t\tDEPOSIT       \t\t:\tRM\t");
				num = 0;
				num = scanf("%lf", &deposit);
				rewind(stdin);
				wrongDeposit();
				balance = amountToPay - deposit;
				printf("\t\t\t\t\t\t\t-------------");
				printf("\n\t\t\tBALANCE       \t\t:\tRM %10.2f", balance);
				printf("\n\t\t\t\t\t\t\t-------------");
				printf("\n\n\t==============================================================\n");
				printf("\n\tPress 'ENTER' key to show order note.");
				getch();
				orderNote();
			}
			else // 5% of discount is given
			{
				printf("\n\t\t\tDISCOUNT (5%%)\t\t:\tRM %10.2f\n", discount = DISCOUNT1 * orderTotal);
				amountToPay = orderTotal - discount;
				printf("\n\t\t\tAMOUNT TO PAY \t\t:\tRM %10.2f\n", amountToPay);
				printf("\n\t\t\tDEPOSIT       \t\t:\tRM\t");
				num = 0;
				num = scanf("%lf", &deposit);
				rewind(stdin);
				wrongDeposit();
				balance = amountToPay - deposit;
				printf("\t\t\t\t\t\t\t-------------");
				printf("\n\t\t\tBALANCE       \t\t:\tRM %10.2f", balance);
				printf("\n\t\t\t\t\t\t\t-------------");
				printf("\n\n\t==============================================================\n");
				printf("\n\tPress 'ENTER' key to show order note.");
				getch();
				orderNote();
			}
		}
		
		finalNumLL += numLL;
		finalNumNC += numNC;
		finalNumAC += numAC;
		finalDiscount += discount;
		finalDeposit += deposit;
	}
	else if (confirmOrder == 'n' || confirmOrder == 'N') // when the order is cancelled
	{
		orderno -= 1; // order number decreased by 1 due to cancelled order
		printf("\n\tOrder cancelled.\n\tPress 'ENTER' key to start again.");
		getch();
		system("cls");
		ordering();
	}
	else
	{
		printf("\tSomething went wrong, please enter again.");
		orderYes();
	}
}
void wrongDeposit()//when invalid deposit is entered
{
	while (deposit < 0 || deposit > amountToPay||num!=1)
	{
		printf("\t\t\tInvalid amount, please enter again.");
		printf("\n\t\t\tDEPOSIT       \t\t:\tRM\t");
		num = 0;
		num = scanf("%lf", &deposit);
		rewind(stdin);
	}
}
void orderNote() //display order note
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t==================================================================================");
	printf("\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n\t\t\t\t|| TARUC FESTIVE COOKIES SDN BHD\t\t\tPhone     : 0173325118  ||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||");
	printf("\n\t\t\t\t|| ORDER NOTE\t\t\t\t\t\tOrder Date: %d/%d/%d  ||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||", day, month, year);
	printf("\n\t\t\t\t|| Your Order No is :\t%d\t\t\t\tReady in 4 days.        ||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n\t\t\t\t||==============================================================================||", orderno);
	printf("\n\t\t\t\t|| \t%d LOVE LETTERS\t@RM %.2f per tin : RM\t%.lf\t\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||", numLL, PRICELL, totalLL);
	printf("\n\t\t\t\t|| \t%d NUT COOKIES \t@RM %.2f per tin : RM\t%.lf\t\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||", numNC, PRICENC, totalNC);
	printf("\n\t\t\t\t|| \t%d ASST COOKIES\t@RM %.2f per tin : RM\t%.lf\t\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||", numAC, PRICEAC, totalAC);
	if (member == 'n' || member == 'N') // order note when the customer is NON-MEMBER
	{
		if (orderTotal >= 500 && orderTotal <= 1000) // when order totalling between RM500 and RM1000
		{
			printf("\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n\t\t\t\t|| \t\t\tORDER TOTAL\t   :\tRM %10.2f\t\t\t\||\n", orderTotal);
			printf("\t\t\t\t|| \t\t\tDISCOUNT (5%%)\t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", discount = DISCOUNT1 * orderTotal); 
			printf("\t\t\t\t|| \t\t\tAMOUNT TO PAY \t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", amountToPay);
			printf("\t\t\t\t|| \t\t\tDEPOSIT       \t   :\tRM %10.2f\t\t\t||\n", deposit);
			printf("\t\t\t\t|| \t\t\tBALANCE       \t   :\tRM %10.2f\t\t\t||", balance);
		}
		else if (orderTotal > 1000) // when order totalling exceeds 1000
		{
			printf("\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n\t\t\t\t|| \t\t\tORDER TOTAL\t   :\tRM %10.2f\t\t\t\||\n", orderTotal);
			printf("\t\t\t\t|| \t\t\tDISCOUNT (10%%)\t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", discount = DISCOUNT2 * orderTotal);
			printf("\t\t\t\t|| \t\t\tAMOUNT TO PAY \t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", amountToPay);
			printf("\t\t\t\t|| \t\t\tDEPOSIT       \t   :\tRM %10.2f\t\t\t||\n", deposit);
			printf("\t\t\t\t|| \t\t\tBALANCE       \t   :\tRM %10.2f\t\t\t||", balance);
		}
		else // when order totalling is less than 500
		{
			printf("\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n\t\t\t\t|| \t\t\tORDER TOTAL\t   :\tRM %10.2f\t\t\t\||\n", orderTotal);
			printf("\t\t\t\t|| \t\t\tDISCOUNT (0%%)\t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", discount = 0 * orderTotal);
			printf("\t\t\t\t|| \t\t\tAMOUNT TO PAY \t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", amountToPay);
			printf("\t\t\t\t|| \t\t\tDEPOSIT       \t   :\tRM %10.2f\t\t\t||\n", deposit);
			printf("\t\t\t\t|| \t\t\tBALANCE       \t   :\tRM %10.2f\t\t\t||", balance);
		}
	}
	else if (member == 'y' || member == "Y") // order note when customer is a MEMBER
	{
		if (orderTotal >= 500 && orderTotal <= 1000)// when order totalling between RM500 and RM1000
		{
			printf("\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n\t\t\t\t|| \t\t\tORDER TOTAL\t   :\tRM %10.2f\t\t\t\||\n", orderTotal);
			printf("\t\t\t\t|| \t\t\tDISCOUNT (15%%)\t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", discount = DISCOUNT3 * orderTotal);
			printf("\t\t\t\t|| \t\t\tAMOUNT TO PAY \t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", amountToPay);
			printf("\t\t\t\t|| \t\t\tDEPOSIT       \t   :\tRM %10.2f\t\t\t||\n", deposit);
			printf("\t\t\t\t|| \t\t\tBALANCE       \t   :\tRM %10.2f\t\t\t||", balance);
		}
		else if (orderTotal > 1000)// when order totalling exceeds 1000
		{	printf("\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n\t\t\t\t|| \t\t\tORDER TOTAL\t   :\tRM %10.2f\t\t\t\||\n", orderTotal);
			printf("\t\t\t\t|| \t\t\tDISCOUNT (20%%)\t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", discount = DISCOUNT4 * orderTotal);
			printf("\t\t\t\t|| \t\t\tAMOUNT TO PAY \t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", amountToPay);
			printf("\t\t\t\t|| \t\t\tDEPOSIT       \t   :\tRM %10.2f\t\t\t||\n", deposit);
			printf("\t\t\t\t|| \t\t\tBALANCE       \t   :\tRM %10.2f\t\t\t||", balance);
		}
		else// when order totalling is less than 500
		{	printf("\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n\t\t\t\t|| \t\t\tORDER TOTAL\t   :\tRM %10.2f\t\t\t\||\n", orderTotal);
			printf("\t\t\t\t|| \t\t\tDISCOUNT (5%%)\t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", discount = DISCOUNT1 * orderTotal);
			printf("\t\t\t\t|| \t\t\tAMOUNT TO PAY \t   :\tRM %10.2f\t\t\t||\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n", amountToPay);
			printf("\t\t\t\t|| \t\t\tDEPOSIT       \t   :\tRM %10.2f\t\t\t||\n", deposit);
			printf("\t\t\t\t|| \t\t\tBALANCE       \t   :\tRM %10.2f\t\t\t||", balance);
		}
	}
	printf("\n\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||\n\t\t\t\t|| Thank You for purchasing from TARUC FESTIVE COOKIES SDN BHD .\t\t||\n");
	printf("\t\t\t\t|| Please bring along this Order Note when collecting your cookies. \t\t||\n");
	printf("\t\t\t\t|| Have a nice day and we hope to see you again :D\t\t\t\t||\n");
	printf("\t\t\t\t||\t\t\t\t\t\t\t\t\t\t||");
	printf("\n\t\t\t\t==================================================================================\n");
	deliveryNote(); // prompt and read user decision on delivery
}

void deliveryNote() // delivery service
{
	printf("\n\n\t\tWe are also providing delivery service with an extra charge of just RM 5.00.");
	printf("\n\t\tFor customers that spent over RM 350, delivery service will be free of charge !!");
	deliveryAnswer();
}
void deliveryService()
{
	printf("\n\n\t\tTO\t\t\t: MR / MRS %s\t\t\t\t\tOrder Number\t:%d\n", customerName, orderno);
	printf("\n\t\tAddress\t\t\t: %s\t\t\t\t\t\tStaff in charge\t:%s\n\t\t\t\t\t: %s\t\t\t\t\t\tStaff's contact\t:%s\n\t\t\t\t\t: %s", addressLine1, staffName, addressLine2, staffContact, addressLine3);
	printf("\n\n\t\tCustomer's Number\t: %s", customerTele);
	printf("\n\n\t\tDelivery charge\t\t: RM %.2f", deliveryCharge);
	printf("\n\n\t\tDelivery Items\n");
	printf("\t\t==========================================================================================================\n");
	printf("\n\t\t|| \t%d LOVE LETTERS\t\t\t\t\t\t\t\t\t\t\t||\n", numLL);
	printf("\n\t\t|| \t%d NUT COOKIES \t\t\t\t\t\t\t\t\t\t\t||\n", numNC);
	printf("\n\t\t|| \t%d ASST COOKIES\t\t\t\t\t\t\t\t\t\t\t||\n", numAC);
	printf("\n\t\t==========================================================================================================\n");
	printf("\n\n\n\t\tPRESS any key to continue.");
	getch();
	system("cls");
}

void deliveryAnswer() // delivery details
{
	printf("\n\n\t\tEnter (Y/y) for delivery service :\t");
	scanf("%c", &deliveryYes);
	rewind(stdin);
	if (deliveryYes == 'y' || deliveryYes == 'Y') //when delivery service is requested
	{
		system("cls");
		printf("\n\n\t\tDELIVERY NOTE\n");
		printf("\t\t============================================================================\n");
		printf("\n\t\tPlease enter your name\t\t\t:  ");
		gets(customerName); // get customer name
		rewind(stdin);
		printf("\n\t\tPlease enter your contact number\t:  ");
		gets(customerTele); // get customer contact number
		rewind(stdin);
		printf("\n\t\tPlease enter your address\t\t:  "); // address
		gets(addressLine1); // address line1
		rewind(stdin);
		printf("\t\t\t\t\t\t\t:  ");
		gets(addressLine2); //address line2
		rewind(stdin);
		printf("\t\t\t\t\t\t\t:  ");
		gets(addressLine3); //address line3
		rewind(stdin);
		printf("\n\t\t============================================================================\n");
		printf("\n\t\tPress 'ENTER' key to continue:");
		getch();
		system("cls");
		if (orderTotal > 350) // when order totalling exceeds RM350
		{
			deliveryCharge = 0.00; // no delivery charge
			deliveryService();		
		}
		else //when order totalling less than RM350
		{
			deliveryCharge = 5.00; //delivery charge of RM5
			deliveryService();
		}
		totalDelivery += deliveryCharge;
	}
	else if (deliveryYes == 'n' || deliveryYes == 'N') // when no delivery service is requested
	{
		printf("\n\t\tOKAY ");
		printf("\n\t\tPRESS any key to continue.");
		getch();
		system("cls");
	}
	else // when neither 'n' nor 'y' is entered
	{
		printf("\n\t\tInvalid command, enter again ");
		deliveryAnswer();
	}
}

void orderSummary() // order summary of the day
{
	printf("\n\n\t\t\t\t\t\t\t\tORDER SUMMARY FOR TODAY (%d/%d/%d)\n", day, month, year);
	printf("\t\t\t\t\t==========================================================================\n");
	printf("\n\t\t\t\t\tTotal Number of Customer Orders : %d\n", orderno);
	printf("\n\t\t\t\t\t||\tTotal Orders\t||\tUnit Price\t||\tAmount\t\t||");
	printf("\n\t\t\t\t\t==========================================================================\n");
	finalTotalLL = finalNumLL * PRICELL; //total sales of love letters
	printf("\n\t\t\t\t\t%d LOVE LETTERS\t\t   @ RM %.2f per tin :\t\tRM %10.2f\n", finalNumLL, PRICELL, finalTotalLL);
	finalTotalNC = finalNumNC * PRICENC; //total sales of nut cookies
	printf("\n\t\t\t\t\t%d NUT COOKIES\t\t   @ RM %.2f per tin :\t\tRM %10.2f\n", finalNumNC, PRICENC, finalTotalNC);
	finalTotalAC = finalNumAC * PRICEAC; //total sales of assorted cookies
	printf("\n\t\t\t\t\t%d ASST COOKIES\t\t   @ RM %.2f per tin :\t\tRM %10.2f\n", finalNumAC, PRICEAC, finalTotalAC);
	finalTotal = finalTotalLL + finalTotalNC + finalTotalAC; //total sales of all 3 types of cookie
	printf("\n\n\t\t\t\t\t\t\t\tTOTAL SALES FOR TODAY:\t\tRM %10.2f\n", finalTotal);
	printf("\t\t\t\t\t\t\t\tTOTAL DISCOUNT ALLOWED:\t\tRM %10.2f\n", finalDiscount);
	printf("\t\t\t\t\t\t\t\tTOTAL DELIVERY FEES:\t\tRM %10.2f\n", totalDelivery);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t-------------\n");
	finalSales = finalTotal - finalDiscount + totalDelivery; //total net sales
	printf("\n\t\t\t\t\t\t\t\tTOTAL NET SALES\t\t  :\tRM %10.2f\n", finalSales);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t=============\n");
	printf("\n\t\t\t\t\t\t\t\tTOTAL DEPOSIT COLLECTED:\tRM %10.2f\n", finalDeposit);
	finalBalance = finalSales - finalDeposit;
	printf("\n\t\t\t\t\t\t\t\tTOTAL BALANCE\t\t:\tRM %10.2f\n", finalBalance);
	printf("\n\t\t\t\t\t==========================================================================\n");
}

void goodBye() // ending message
{	printf("\n\n\n\t\t\t\t\t                                                               `+ss++s - \n");
	printf("\t\t\t\t\t                                `-:-                         -sm+`   -N                     \n");
	printf("\t\t\t\t\t                 ./shmmy`     `ym+-`                       .dNo      +d                     \n");
	printf("\t\t\t\t\t              :yNMMMdyosh     dm`                        .yMs`      -d.                     \n");
	printf("\t\t\t\t\t           `omMMho-   :m-     Mo                        /Nm-      `oy.                   `/`\n");
	printf("\t\t\t\t\t         `sNMd+`    -ys.      dy                      `sMs`     `oy:                     oMh\n");
	printf("\t\t\t\t\t        +NMy-     -o+`        .N/                    .dN/     -sy:-+o-                  +MMo\n");
	printf("\t\t\t\t\t      .hMh.      ``            .hs`                `/md.   :oyooyy+. o-                oMMm`\n");
	printf("\t\t\t\t\t     -NN/                        :ys:             `oNh.-+ss//yh/`  `+/                yMMd` \n");
	printf("\t\t\t\t\t    :Nh`                           `:oooo+/:::://odNdso:` /ho.   `+o`               `hMNd`  \n");
	printf("\t\t\t\t\t   -Nm`                .-------          `..---.oMNo    +h/    -oo.                `hNmh.   \n");
	printf("\t\t\t\t\t   hN-               .+.      `o`              `+:.   :h/   -oo:                  `hNdo     \n");
	printf("\t\t\t\t\t  -Mo    ./++ossoshy+y .yms    //     ...../syoyo   /hs-:+++/---        :-       .mMy-      \n");
	printf("\t\t\t\t\t  sM.     `.`` `+ms``ooMN/     y``/o/.  `omh/ohy`  /doo++---`:ms` /-  /msy.      dm:        \n");
	printf("\t\t\t\t\t  oM`        `+Nd-   +Mh:---:/y+:m+`/  /Nh--+od-  /d--:/d   +m-  oM: yd//:  /    h`         \n");
	printf("\t\t\t\t\t  .N/      .//Mh     Nh     /o` // .: -M+-/. sd`  d. `+s`  /d``/oMs /m`   -y-  -o-    `     \n");
	printf("\t\t\t\t\t   .h+.`-/+- +M`     ss  .//.    -.`  `+:.   dd   .-::`    ++::.mh  `s::/+:    yN+    //    \n");
	printf("\t\t\t\t\t     .:/-`    :.      .::.                   -do              .dm`             -`     ss    \n");
	printf("\t\t\t\t\t                                                `....----:-. :Nh`                   `sd`    \n");
	printf("\t\t\t\t\t                                                           :mNy//-.              ./yy/      \n");
	printf("\t\t\t\t\t                                                          .sNy`   .://+++++oooooos+-        \n");
	printf("\t\t\t\t\t                                                      `/hdo.                                \n");
	printf("\t\t\t\t\t                                           .      `-+yho-                                   \n");
	printf("\t\t\t\t\t                                           `-://+oo+:`                                      \n");
	printf("\n\n\t\t\tCLOSING IN\t3");
	Sleep(1000);
	printf("\n\n\t\t\t\t\t2");
	Sleep(1000);
	printf("\n\n\t\t\t\t\t1");
	Sleep(1000);
	system("cls");
}

