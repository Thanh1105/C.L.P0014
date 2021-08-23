#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int random(int minN, int maxN){
	return minN + rand() % (maxN + 1 - minN);
}
void menu(){
	printf("\n1. Buy chips.");
	printf("\n2. Sell chips.");
	printf("\n3. Play Craps.");
	printf("\n4. Play Arup's Game of Dice.");
	printf("\n5. Status Report.");
	printf("\n6. Quit.\n");
}
void sellChip(int *money, int *chip){
	int n;
		printf("How many chips do you want sell?\n");
		scanf("%d",&n);
		if(*chip==0) printf("You do not have anychip.\n");
		else{
			*chip=*chip-n;
			int h=n*10;
			*money=(*money+(n*10));
			printf("Thank for player your money after you sell chip: %d$",h);
		}
	}
void buyChip(int *money, int *chip){
	int n,c;
		printf("How many chips do you want buy?\n");
		scanf("%d",&n);
		if(*money-(11*n)<0){
			printf("You do not have money for buy chip\n");}
		else {
			*money=(*money-(11*n));
			*chip= *chip + n;
			printf("Thank for player.You have %d chips", *chip);
		}
	}
void playCraps(int *money,int *chip){
	srand((int)time(0));
	int r,bet,c=0,k=13;
	char d,f;
	printf("How many chips would you like to bet?\n");
	scanf("%d",&bet);
	if((*chip-bet)<0) printf("Sorry!, you do not have that many chips to bet. No game played.");
	else{
		*chip=*chip-bet;
		printf("Press 'r' and hit Enter to first roll: ");
		fflush(stdin); 
		scanf("%d",&f);
		do{
			int i;
				for( i=0;i<1;i++)
				r=random(1,6)+random(1,6);
				printf("You roll: %d\n",r);
	
				if (c==r) {
					printf("You win!",r);
					*chip=(*chip + bet*2);
					break;}
					
				if  (r==7&&k!=13){
					printf("You lose!"); 
					break;
					}
				if (k==13) c=r;
				if(k==13){
					if (r==7|| r==11) {
						printf("You win!");
						*chip=(*chip + bet*2);
						break;}
					if(r==2||r==3||r==12){
						printf("You lose!");
						break;
					}
				k++;
				}
			printf("Press 'r'anh hit Enter next roll:");
			fflush(stdin);
			scanf("%c",&d);
		}while(d!=r);
	}
}

void playArup (int*money,int*chip){
	srand((int)time(0));
	int r,bet,c=0,k=13;
	char d,f;
	printf("How many chips would you like bet?\n");
	scanf("%d",&bet);
	if((*chip-bet)<0||bet==0) printf("Sorry,you do not have that many chips to bet. No game played!");
	else{
		*chip=*chip-bet;	
		printf("Presss 'r' hit Enter first roll: ");
	
		scanf("%d",&f);
		do{	
		int i;
			for( i=0;i<1;i++)
			r=random(1,12);
			printf("You roll: %d\n",r);
			if(k==13){
			if (r==11|| r==12) {
			printf("You win!");
			*chip=(*chip + bet*2);
			break;}
					}
			if	(k!=13){
			if (c<r) {
				printf("You win!");
				*chip=(*chip + bet*2);	
				break;
			}
			else{
				printf("You lose!");	
				break;}
			}
			if(k==13){
				c=r;
				k++;
				}
		
			printf("Press'r'hit Enter next roll:");
			fflush(stdin);
			scanf("%c",&d);
	}while(d!=r);
}
}
int main(){
	int money=1000;
	int chip =0;
	int choice;
	do{
	menu();
	printf("\nGet choice:");
	fflush(stdin);
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			buyChip(&money,&chip);
			break;
		}
		case 2:{
			sellChip(&money,&chip);
			break;
		}
		case 3:{
			playCraps(&money,&chip);
			break;
		}
		case 4:{
			playArup(&money,&chip);
			break;
		}
		case 5:{
			printf("Your money: %d$\n",money);
			printf("Your chips: %d\n",chip);
			break;
		}
		case 6:{
			break;
		}
	}
	}while(choice!=6);
}
