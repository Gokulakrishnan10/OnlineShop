#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct product
{
		int id;
		char name[20];
		int price;
		int qty;
};
void addproduct();
void viewproduct();
void modify();
//void editproduct(int id,int qty);

char fproduct[]={"product.dat"};

int main()
{
		FILE *fp;
		int ch;
		while(1)
		{
			printf("\nONLINE SHOPPING\n\n");
			printf("1.Add New Product\n\n");
			printf("2.View Product\n\n");
			printf("3.Modify Product\n\n");
			printf("0.Exit\n\n");
			printf("\nEnter Your Choice:\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:	addproduct();break;
				case 2: viewproduct();break;
				//case 3: modify();break;
				case 0: exit(0);
			}
			
			
		}
		return 0;
}

void addproduct()
{
	FILE *fp;
	struct product t1;
	system("cls");
	fp=fopen(fproduct,"a+");
	//printf("\nEnter Product Id:");
	//scanf("%d",t1.id);
	printf("\nEnter Product name:");
	scanf("%s",t1.name);
	printf("\nEnter Product price:");
	scanf("%d",&t1.price);
	printf("\nEnter Product Quantity:");
	scanf("%d",&t1.qty);
	fwrite(&t1,sizeof(t1),1,fp);
	fclose(fp);
	
}
void viewproduct()
{
	 FILE *fp;
	 struct product t;
	 system("cls");
	 fp=fopen(fproduct,"r+");
	 printf("\nPRODUCT DETAILS\n\n");
	 printf(" Name\t\t Qty.\t\t Price\n\n");
	 while(1)
	 { 
	 	fread(&t,sizeof(t),1,fp);
	 	if(feof(fp))
	 	{  
	 		break;
		}
		//printf("%d\t",t.id);
		printf("%s\t",t.name);
		printf("%d\t",t.qty);
		printf("%d\t\t\n",t.price);
		
		
	 }
	 fclose(fp);
}
/*void editproduct(int id,int qty)
{
	FILE *fp,*fp1;
	struct product t,t1;
	int found=0;
	fp=fopen(fproduct,"r+");
	fp1=fopen("temp.dat","w+");
	while(1)
	{
		fread(&t,sizeof(t),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(t.id==id)
		{
			 found=1;
			 t.qty=qty;
			 fwrite(&t,sizeof(t),1,fp1);
		}
		else
		{
			fwrite(&t,sizeof(t),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		printf("No records Found");
		
	}
	else
	{
		fp=fopen(fproduct,"w+");
		fp1=fopen("temp.dat","r+");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
		
	}
	fclose(fp);
	fclose(fp1);
}*/
/*void modify()
{
	FILE *fp,*fp1;
	struct product t,t1;
	int id,found=0,count=0;
	fp=fopen(fproduct,"r+");
	fp1=fopen("temp.dat","w+");
	printf("\nEnter the Product id u want to modify");
	scanf("%d",&id);
	while(1)
	{
		fread(&t,sizeof(t),1,fp);
		if(feof(fp))
		{
			break;
		
		}
		if(t.id==id)
		{
			found=1;
			printf("\nEnter Product id:");
			scanf("%d",&t.id);
		//	fflush(studin);
			printf("\nEnter Product Name;");
			scanf("%s",t.name);
			printf("\nEnter Quantity :");
			scanf("%d",&t.qty);
			printf("\nEnter Price:");
			scanf("%d",&t.price);
			fwrite(&t,sizeof(t),1,fp);
		}
		else
		{
			fwrite(&t,sizeof(t),1,fp1);
		}
		
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		printf("No records Found");
		
	}
	else
	{
		fp=fopen(fproduct,"w+");
		fp1=fopen("temp.dat","r+");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
		
	}
	fclose(fp);
	fclose(fp1);
	
}*/
