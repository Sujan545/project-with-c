#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
	{
		int id;
		char name[50],address[50];
		float percentage;
	};
	struct student s;

	int main()
	{
		
	char username[50],password[50],user[]="admin",pass[]="8855";
	int choice,i=0;
	char cont;

	FILE *fp,*fp_temp;
	top:
		system("cls");
	printf("enter username:");
	scanf("%s",&username);
	printf("enter password:");
	for(i=0; i<20; i++){
		password[i]=getch();
		if(password[i]==13)
		{
			break;
		}
		else{
			printf("*");
		}
	}
	password[i]='\0';
	if(strcmp(username,user)==0 && strcmp(password,pass)==0 )
	{
		mainmenu:
		printf("welcome to the system");
		system("cls");
		printf("**********welcome to the system************\n");
		printf("**********choose from the menu**********\n");
		printf("1.Add record\n");
		printf("2.View record\n");
		printf("3.Delete record\n");
		printf("4.Update record\n");
		printf("5.Search record\n");
		printf("6.Logout\n");
		printf("**********Enter the choice:**********\n");
		scanf("%d",&choice);
	switch(choice)
	{

	case 1:
		{  
		add:
		printf("Enter your id ");
		scanf("%d",&s.id);
		fflush(stdin);
		printf("Enter your name:\n");
		scanf("%s",&s.name);
		printf("Enter your address:\n");
		scanf("%s",&s.address);
		printf("Enter your percentage:\n");
		scanf("%f",&s.percentage);
		printf("Add record here\n");
		fp=fopen("student.txt","a");
		fwrite(&s, sizeof(s),1,fp);
		if(fwrite)
			{
			printf("success\n");
			}
			else
			{
			printf("failed\n");
			}
		fclose(fp);
		printf("do you want to continue?\n");
		printf("type Y for yes and N for No\n");
		
		cont=getche();
		system("cls");
			if(cont=='y')
			{
			goto add;
			}
			else
			{
			goto mainmenu;
			}
		
		break;
		}
		
	case 2:
		{
		fp=fopen("student.txt","r");
		printf("Id\tName\tAddress\t\tPercentage\n");
		while(fread(&s,sizeof(s),1,fp))
			{
			printf("%d",s.id);
			printf("\t%s",s.name);
			printf("\t%s",s.address);
			printf("\t\t%f\n",s.percentage);
			}
		getch();
		fclose(fp);
		goto mainmenu;
		   break;
		}
		   
	case 3:
		{
		int std_id,flag=0;
		printf("Enter the student id:");
		scanf("%d",&std_id);
		fp=fopen("student.txt","r");
		fp_temp=fopen("student_temp.txt","a");
		while(fread(&s,sizeof(s),1,fp))
			{
			if(std_id!=s.id)
			{	
			fwrite(&s,sizeof(s),1,fp_temp);
			}
			else
			flag=1;
			}
		fclose(fp);
		fclose(fp_temp);
		remove("student.txt");
		rename("student_temp.txt","student.txt");
			if(flag==1)
			{
			printf("record delete successful");
			}
			else
			printf("record couldnot delete");
		getch();
		goto mainmenu;
		break;
		}
	case 4:
		  {
		 	int std_id,flag=0;
			printf("Enter the student id to update:");
			scanf("%d",&std_id);
			fp=fopen("student.txt","r");
			fp_temp=fopen("student_temp.txt","a");
			while(fread(&s,sizeof(s),1,fp))
			{
				if(std_id==s.id)
				{
					printf("%d",s.id);
					printf("\t%s",s.name);
					printf("\t%s",s.address);
					printf("\t\t%f\n",s.percentage);
					fflush(stdin);
					printf("Enter the student Name:");
					gets(s.name);
					printf("\nEnter the student Address:");
					gets(s.address);
					printf("\nEnter the student percentage:");
					scanf("%f",&s.percentage);
					fwrite(&s,sizeof(s),1,fp_temp);
				}
				else{
				fwrite(&s,sizeof(s),1,fp_temp);
				flag=1;
			     }
			
	        	}
			fclose(fp);
			fclose(fp_temp);
			remove("student.txt");
			rename("student_temp.txt","student.txt");
				if(flag==1)
				{
				printf("record update successful");
				}
				else
				printf("record couldnot be updated");
			getch();
			goto mainmenu;
	   		break;
		}
		
	case 5:
		{
			int std_id,flag=0;
			printf("Enter the student id to search:");
			scanf("%d",&std_id);
			fp=fopen("student.txt","r");
			while(fread(&s,sizeof(s),1,fp))
			{
				if(std_id==s.id)
				{
					flag=1;
					printf("%d",s.id);
					printf("\t%s",s.name);
					printf("\t%s",s.address);
					printf("\t\t%f\n",s.percentage);
				}
			
			}
			if(flag!=1){
				printf("resuld could not be found:");
			}
			fclose(fp);
			getch();
			goto mainmenu;
			break;
		}
		
		case 6:
		{
			char ch=' ';
			system("cls");
			printf("Logout sucessfully press [y,Y] to login:");
			ch=getch();

			if(ch=='y'||ch=='Y')
			goto top;
			else
			exit(0);
			
			break;
   		}
	}
	}
	else
	{
	system("cls");
	printf("invalid username and passsword\n\n");
	goto top;

	}
return 0;
}	
