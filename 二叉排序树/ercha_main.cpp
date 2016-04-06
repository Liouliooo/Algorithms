/*********����������*********/
/****ʵ�ֶ����������Ĳ���****/
 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include"ercha_paixushu.h"


void print(void);
void select(void);

int main(void)
{
	float asl;				//asl��ʾƽ�����ҳ���
	char choose[3];			//switch��������
	int search;				//��ʾҪ���ҵ�����
	int insert;				//��ʾҪ���������
	int delet;				//��ʾҪɾ��������
	int isavl;				//�ж϶����������Ƿ���ƽ��������ı�־

	Bitnode *head=NULL;     //����������ͷ���ָ��
	
	print();
	
	printf("���ȴ���һ������������(�������������������ַ��˳�):\n");

	head=CreatBitTree();	//����һ�ö���������

	select();
	printf("��ѡ������ִ�еĲ���:\n");

	while(1)
	{
		getchar();  //�Ե�������������enter
		scanf("%s",choose);
		if(choose[1]!='\0')    //���˴���Ϊ�˴����û�����Ĵ����ѡ��
		{
			choose[0]='N';
		}

		switch(choose[0])
		{
		case '0': 
		{

			FILE *fp=NULL;
			time_t timep;              //ʱ�亯�� typedef long time_t
			time(&timep);				
			char *s=asctime(localtime(&timep));  //��ʱ��ת��Ϊ����ʱ�䣬��ת��Ϊ������ʾ���ַ�����Sat Jul 02 13:28:57 2011
			fp=fopen("BST.txt","a");				//���ַ������׵�ַ���ݸ� ָ��s

			fprintf(fp,"������������Ϊ:		");
			fprintf(fp,"TIME:  %s",s);
			fclose(fp);

			SaveBitTree(head);		

			fp=fopen("BST.txt","a");
			fprintf(fp,"\n\n\n");
			fclose(fp);
					
			head=FreeAllnode(head);

			printf("�����������˳�ǰ,�ѱ����浽���ļ�BST.txt��!\n");
			printf("���������������ڵ���ռ�ռ��Ѿ��ͷ�!\n\n");
		
			InOrderTraverse(head);

			printf("\n************************��ӭ������!************************\n\n");
			exit(0);
		}
		case '1':
		{
			if(head==NULL)
			{
				printf("�������������������!\n");
//					select();
				printf("�����ѡ������ִ�еĲ���:\n");
				break;
			}
			printf("�������������Ϊ:\n");
			InOrderTraverse(head);
//				select();
			printf("\n\n�����ѡ������ִ�еĲ���:\n");
			break;
		}
		case '2':
		{
			printf("��������õ���Ԫ��: ");
			scanf("%d",&search);

			head = SearchBitTree(head,search);
			InOrderTraverse(head); 

//				select();
			printf("\n\n�����ѡ������ִ�еĲ���:\n");
			break;
		}
		case '3':
		{
			printf("ѡ��������������: ");
			scanf("%d",&insert);

			head=InsertBitTreenode(head,insert);
			if(insert==0)
			{
				printf("�������Ľڵ��Ѿ�����!\n");
			}
			else 
			{
				printf("�ڵ��Ѿ�����!\n");
			}
			InOrderTraverse(head); 

//				select();
			printf("\n\n�����ѡ������ִ�еĲ���:\n");
			break;
		}
		case '4':
		{
			printf("ѡ������ɾ��������: ");
			scanf("%d",&delet);

			head=DeleteBitTree(head,delet);
				
			InOrderTraverse(head); 

//				select();
			printf("\n\n�����ѡ������ִ�еĲ���:\n");
			break;
		}
		case '5':
		{
			asl=AslBitTree(head);
			printf("%.3f\n",asl);

//				select();
			printf("\n�����ѡ������ִ�еĲ���:\n");
			break;
		}
		case '6':
		{
			isavl=IsAVLBitTree(head);
				
			if(isavl==1)
			{
				printf("�˶�����������һ��ƽ�������!\n");				
			}
			else 
			{
				printf("�˶�������������һ��ƽ�������!\n");
			}

			printf("\n�����ѡ������ִ�еĲ���:\n");
			break;
		}
		case '7':
		{
			head= FreeAllnode(head);
			printf("ԭ���������������ڵ�Ŀռ��Ѿ��ͷ�!\n");
			printf("���������������������ַ��Ƴ�:\n");

			head=CreatBitTree();

//				select();
			printf("\n��ѡ������ִ�еĲ���:\n");
			break;
		}
		case '8':
		{
			head= FreeAllnode(head);
			printf("ԭ���������������ڵ�Ŀռ��Ѿ��ͷ�!\n");

			printf("������ɵĶ���������Ϊ:\n");
				
			head=RandomBitTree();
			InOrderTraverse(head); 

//				select();
			printf("\n\n��ѡ������ִ�еĲ���:\n");
			break;
		}
		case '9':
		{
			FILE *ffp=NULL;
			time_t timep;              //ʱ�亯��
			time(&timep);
			char *s=asctime(localtime(&timep));
			ffp=fopen("BST.txt","a");
					
			fprintf(ffp,"�����������Ϊ:		");
			fprintf(ffp,"TIME:  %s",s);
			fclose(ffp);

			SaveBitTree(head);

			ffp=fopen("BST.txt","a");
			fprintf(ffp,"\n\n\n");
			fclose(ffp);

			printf("���������Ѿ����浽�ļ���,���ļ���ΪBST.txt,λ����Ӧ�ļ�����!\n");
//				select();
			printf("\n�����ѡ������ִ�еĲ���:\n");
			break;
		}
		default:
		{
			printf("�Բ���! û�д�ѡ��!\n\n");
//				select();
			printf("\n������ѡ������ִ�еĲ���:\n");
			break;
		}
		}
	}
	

	return 0;
}




void print(void)    //����ͷҪ��ʾ�Ľ��棬Ϊ�˸��кö�����
{	
	printf("\n		|******************************|\n");
	printf("		|                              |\n");	               
	printf("		|                              |\n");	                    
	printf("		|********* ���������� *********|\n");
	printf("		|                              |\n"); 
	printf("		|****** Binary Sort Tree ******|\n");
	printf("		|                              |\n"); 
	printf("		|                              |\n");	                 
	printf("		|******************************|\n\n\n\n");

}



void select(void)		//�������������������� ѡ��
{
	printf("\n");
	printf("\n\t*******************�˵�*******************\n");
	printf("\t******************************************\n");
	printf("\t	0:�˳�!                          \n");
	printf("\t	1:�������������!			     \n");      
	printf("\t	2:��������õ���Ԫ��!            \n");
	printf("\t	3:����һ��Ԫ��!				     \n");
	printf("\t	4:ɾ��һ��Ԫ��!			       	 \n");
	printf("\t	5:���������������ƽ�����ҳ���!  \n");
	printf("\t	6:�ж϶����������Ƿ���ƽ�������! \n");
	printf("\t	7:���´���һ�ö���������!       \n");
	printf("\t	8:�������һ�ö���������!       \n");
	printf("\t	9:�Ѷ��������������ݱ��浽�ļ���! \n");
	printf("\t******************************************\n\n");
}
