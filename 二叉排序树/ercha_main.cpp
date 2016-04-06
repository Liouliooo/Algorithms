/*********二叉排序树*********/
/****实现二叉排序树的操作****/
 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include"ercha_paixushu.h"


void print(void);
void select(void);

int main(void)
{
	float asl;				//asl表示平均查找长度
	char choose[3];			//switch语句的条件
	int search;				//表示要查找的数据
	int insert;				//表示要插入的数据
	int delet;				//表示要删除的数据
	int isavl;				//判断二叉排序树是否是平衡二叉树的标志

	Bitnode *head=NULL;     //二叉排序树头结点指针
	
	print();
	
	printf("请先创建一个二叉排序树(输入整数，输入任意字符退出):\n");

	head=CreatBitTree();	//创建一棵二叉排序树

	select();
	printf("请选择您想执行的操作:\n");

	while(1)
	{
		getchar();  //吃掉上面输入语句的enter
		scanf("%s",choose);
		if(choose[1]!='\0')    //做此处理：为了处理用户输入的错误的选项
		{
			choose[0]='N';
		}

		switch(choose[0])
		{
		case '0': 
		{

			FILE *fp=NULL;
			time_t timep;              //时间函数 typedef long time_t
			time(&timep);				
			char *s=asctime(localtime(&timep));  //把时间转化为本地时间，并转化为如有所示的字符串：Sat Jul 02 13:28:57 2011
			fp=fopen("BST.txt","a");				//把字符串的首地址传递给 指针s

			fprintf(fp,"最终所得数据为:		");
			fprintf(fp,"TIME:  %s",s);
			fclose(fp);

			SaveBitTree(head);		

			fp=fopen("BST.txt","a");
			fprintf(fp,"\n\n\n");
			fclose(fp);
					
			head=FreeAllnode(head);

			printf("您的数据在退出前,已被保存到了文件BST.txt中!\n");
			printf("二叉排序树各个节点所占空间已经释放!\n\n");
		
			InOrderTraverse(head);

			printf("\n************************欢迎您再来!************************\n\n");
			exit(0);
		}
		case '1':
		{
			if(head==NULL)
			{
				printf("这个二叉排序树不存在!\n");
//					select();
				printf("请继续选择您想执行的操作:\n");
				break;
			}
			printf("这个二叉排序树为:\n");
			InOrderTraverse(head);
//				select();
			printf("\n\n请继续选择您想执行的操作:\n");
			break;
		}
		case '2':
		{
			printf("查找您想得到的元素: ");
			scanf("%d",&search);

			head = SearchBitTree(head,search);
			InOrderTraverse(head); 

//				select();
			printf("\n\n请继续选择您想执行的操作:\n");
			break;
		}
		case '3':
		{
			printf("选择您想插入的数据: ");
			scanf("%d",&insert);

			head=InsertBitTreenode(head,insert);
			if(insert==0)
			{
				printf("您想插入的节点已经存在!\n");
			}
			else 
			{
				printf("节点已经插入!\n");
			}
			InOrderTraverse(head); 

//				select();
			printf("\n\n请继续选择您想执行的操作:\n");
			break;
		}
		case '4':
		{
			printf("选择您想删除的数据: ");
			scanf("%d",&delet);

			head=DeleteBitTree(head,delet);
				
			InOrderTraverse(head); 

//				select();
			printf("\n\n请继续选择您想执行的操作:\n");
			break;
		}
		case '5':
		{
			asl=AslBitTree(head);
			printf("%.3f\n",asl);

//				select();
			printf("\n请继续选择您想执行的操作:\n");
			break;
		}
		case '6':
		{
			isavl=IsAVLBitTree(head);
				
			if(isavl==1)
			{
				printf("此二叉排序树是一棵平衡二叉树!\n");				
			}
			else 
			{
				printf("此二叉排序树不是一棵平衡二叉树!\n");
			}

			printf("\n请继续选择您想执行的操作:\n");
			break;
		}
		case '7':
		{
			head= FreeAllnode(head);
			printf("原二叉排序树各个节点的空间已经释放!\n");
			printf("请输入整数，输入任意字符推出:\n");

			head=CreatBitTree();

//				select();
			printf("\n请选择您想执行的操作:\n");
			break;
		}
		case '8':
		{
			head= FreeAllnode(head);
			printf("原二叉排序树各个节点的空间已经释放!\n");

			printf("随机生成的二叉排序树为:\n");
				
			head=RandomBitTree();
			InOrderTraverse(head); 

//				select();
			printf("\n\n请选择您想执行的操作:\n");
			break;
		}
		case '9':
		{
			FILE *ffp=NULL;
			time_t timep;              //时间函数
			time(&timep);
			char *s=asctime(localtime(&timep));
			ffp=fopen("BST.txt","a");
					
			fprintf(ffp,"您保存的数据为:		");
			fprintf(ffp,"TIME:  %s",s);
			fclose(ffp);

			SaveBitTree(head);

			ffp=fopen("BST.txt","a");
			fprintf(ffp,"\n\n\n");
			fclose(ffp);

			printf("您的数据已经保存到文件中,此文件名为BST.txt,位于相应文件夹内!\n");
//				select();
			printf("\n请继续选择您想执行的操作:\n");
			break;
		}
		default:
		{
			printf("对不起! 没有此选项!\n\n");
//				select();
			printf("\n请重新选择您想执行的操作:\n");
			break;
		}
		}
	}
	

	return 0;
}




void print(void)    //程序开头要显示的界面，为了更有好而创建
{	
	printf("\n		|******************************|\n");
	printf("		|                              |\n");	               
	printf("		|                              |\n");	                    
	printf("		|********* 二叉排序树 *********|\n");
	printf("		|                              |\n"); 
	printf("		|****** Binary Sort Tree ******|\n");
	printf("		|                              |\n"); 
	printf("		|                              |\n");	                 
	printf("		|******************************|\n\n\n\n");

}



void select(void)		//操作二叉排序树的所有 选项
{
	printf("\n");
	printf("\n\t*******************菜单*******************\n");
	printf("\t******************************************\n");
	printf("\t	0:退出!                          \n");
	printf("\t	1:输出二叉排序树!			     \n");      
	printf("\t	2:查找您想得到的元素!            \n");
	printf("\t	3:插入一个元素!				     \n");
	printf("\t	4:删除一个元素!			       	 \n");
	printf("\t	5:计算二叉排序树的平均查找长度!  \n");
	printf("\t	6:判断二叉排序树是否是平衡二叉树! \n");
	printf("\t	7:重新创建一棵二叉排序树!       \n");
	printf("\t	8:随机生成一棵二叉排序树!       \n");
	printf("\t	9:把二叉排序树的数据保存到文件中! \n");
	printf("\t******************************************\n\n");
}
