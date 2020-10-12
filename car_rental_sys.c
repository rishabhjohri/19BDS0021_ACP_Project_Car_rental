#include<stdio.h>
struct cust {
	char name[20];
	char mobile_no[10];
	char aadhar_no[20];
	int car_model;
	int days;
	char car_no[10];
	
};
void get_info(struct cust *c){
	printf("\n Enter name : ");
	scanf("%s",c->name);
	printf("\n Enter phone number : ");
	scanf("%s",c->mobile_no);
	printf("\n Enter Aadhar card number : ");
	scanf("%s",c->aadhar_no);
	printf("\n Enter car model : ");
	scanf("%d",&(c->car_model));
	printf("\n Enter number of days for which car is to be rented : ");
	scanf("%d",&(c->days));
	printf("\n Enter car number : ");
	scanf("%s",c->car_no);
	
}
int calc_rent(struct cust c){
	int rent;
	switch(c.car_model){
		case 1:
			rent = 1000*c.days;
			break;
		case 2:
			rent = 2000*c.days;
			break;
		case 3:
			rent = 3000*c.days;
			break;
	}
	return rent;
}
main(){
	struct cust c;
	printf("\n AVAILABLE MODELS : \n 1		price: 1000 Rs \n 2		price: 2000 Rs \n 3		price: 3000 Rs");
	printf("\n**NOTE : price refers to per day rate");
	get_info(&c);
	char path[300];
	printf( "\nEnter path where file is to be saved: eg: D://data.txt  ");
	scanf("%s",path);
	FILE *fp;
	fp  = fopen (path, "w+");
	fputs(c.name,fp);
	fputs("\n",fp);
	fputs(c.mobile_no,fp);
	fputs("\n",fp);
	fputs(c.aadhar_no,fp);
	fputs("\n",fp);
	fputc(c.car_model,fp);
	fputs("\n",fp);
	putw(c.days,fp);
	fputs("\n",fp);
	fputs(c.car_no,fp);
	fputs("\n",fp);
	fclose(fp);
	printf("\n SAVING . . .");
	printf("\n INFO SAVED SUCESSFULLY . . .");
	int r;
	r = calc_rent(c);
	printf("\n THE AMOUNT TO BE PAID IS %d",r);
}
