/*********二叉排序树*********/
/****实现二叉排序树的操作****/
 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include"ercha_paixushu.h"



void Visit(Bitnode *v_T)                           /////把节点v_T中的data和layer输出
{
	if(v_T!=NULL)                                              //要输入的节点存在，则输出值
	{
		printf("%d(%d层)   ",v_T->data,v_T->layer);
	}
	else 
	{
		printf("节点没有值!\n");
	}
}



Bitnode *CreatBitTree(void)				/////创建有n个结点的二叉排序树,返回指向头节点的指针
{
	int number;
	Bitnode *c_head=NULL;
												//scanf函数返回成功读入的项目的个数，如果输入非数字字符就返回值0
	while(scanf("%d",&number))                //输入数据然后把第一个数值作为二叉排序树的根节点，进而不断的进行插入操作，
	{											//最终，按照插入数据的顺序，创建一棵二叉排序树
 		c_head=InsertBitTreenode(c_head,number);
	}

	return c_head;                              //返回指向二叉排序树头结点的指针
}



Bitnode *RandomBitTree(void)					/////随机创建一棵二叉排序树
{
	int num;
	int i,end;

	Bitnode *r_head=NULL;                       //定义指向头结点的指针

	srand(time(NULL));                          //以当前系统时间作为随机数生成器的种子
	end=rand()%100;                             //生成的随机数的个数在100个以内
												//即：以格林尼治时间（GMT）为标准，从1970年1月1日00:00:00到现在的此时此刻所经过的秒数

	for(i=0;i<end;i++)
	{
		num=rand()%1000;                       //每一个随机数的值在1000以内
		r_head=InsertBitTreenode(r_head,num);      //已插入节点的方式创建一棵二叉排序树
	}
	
	return r_head;
}

 



float  AslBitTree(Bitnode *a_head)                  /////计算二叉排序树的平均查找长度，并返回此数值
{
	Bitnode *ap=a_head;
	float a_s=0;
	float length=AslLengthBitTree(ap);                //length表示总共的查找长度
	float number=AslNumberBitTree(a_head);				//number表示总共的节点的个数
	
	a_s=(length/number);

	printf("平均查找长度ASL = %.0f/%.0f = ",length,number);

	return a_s;                                         //返回平均查找长度
}

float AslLengthBitTree(Bitnode *al_head)             /////计算二叉排序树的总共的查找长度，并返回此数值
{
	float s=0;
	if(al_head != NULL)                               //用中序遍历计算二叉排序树的总查找长度
	{
		s+=AslLengthBitTree(al_head->lchild);             
		s+=al_head->layer;                             //layera即为，每一个节点的层数
		s+=AslLengthBitTree(al_head->rchild);
	}
	return s;
}

float AslNumberBitTree(Bitnode *an_head)			/////计算二叉排序树的节点的个数，并返回此数值
{
	float k=0;
	if(an_head != NULL)								//用中序遍历计算二叉排序树节点的个数，
	{
		k+=AslNumberBitTree(an_head->lchild);		//若节点存在，则 K 值增加1       
		k++;
		k+=AslNumberBitTree(an_head->rchild);
	}
	return k;
}



Bitnode *InsertBitTreenode(Bitnode *i_head,int &i_T)	/////把节点i_T(需在函数中创建)插入二叉排序树中,并使新树为二叉排序树，返回头结点指针
{
	int i_layer=1;
	Bitnode *s=NULL;							//s指向要插入的节点
	Bitnode *p=i_head;
	Bitnode *f=NULL;							//f指向要插入节点的双亲节点

	while (p != NULL)
	{
		f=p;    ///f指向要插入节点的双亲节点         
		
		if(p->data==i_T)
		{
			i_T=0;              //如果想要插入的节点已经存在，则把用户想要插入的节点值 置为 0,
			return i_head;		// 并返回头结点指针
		}
		else if(p->data < i_T)     //如果要插入的值大于根节点，则在个节点的右子树中插入
		{
			i_layer++;
			p=p->rchild;
		}
		else                       //如果要插入的值小于根节点，则在个节点的左子树中插入
		{
			i_layer++;
			p=p->lchild;
		}
	}

	s=(Bitnode*)malloc(sizeof(Bitnode));     //为节点分配内存空间
	s->data=i_T;							//节点的值即为要插入的值
	s->lchild=s->rchild=NULL;				//把节点的左右指针设置为空
	s->layer=i_layer;						//layer为节点所在的层数，在插入的过程之中已经计算出此值

	if(i_head==NULL)                      //头结点为空，返回s，此时s指向头结点
	{
		return s;
	}

	else if(f->data<i_T)			//双亲节点f的值比要插入节点的值小，则把该节点插入到f的右子树
	{
		f->rchild=s;
	}
	else							//双亲节点f的值比要插入节点的值大，则把该节点插入到f的左子树	
	{
		f->lchild=s;
	}
	return i_head;
}


Bitnode * DeleteBitTree(Bitnode *d_head,int d_T)        /////把二叉排序树中,与d_T相同的节点删除,返回头节点指针
{

	Bitnode *f=NULL;
	Bitnode *k=NULL;

	if(d_head==NULL)
	{
		printf("您想删除的节点不存在!\n");
		return d_head;
	}

	else if(d_T==d_head->data)                        //所输入数据与节点cik值相同，删除节点的操作
	{
		if((d_head->lchild==NULL) && (d_head->rchild==NULL))               //情况1:节点cik左右节点为空,即:cik为叶子节点
		{
			free(d_head);													//把cik节点所占的内存空间释放
			d_head=NULL;
		}


		else if((d_head->lchild==NULL) && (d_head->rchild!=NULL))              //情况2：节点cik只有右节点，没有左节点
		{
			Bitnode *rd_head=d_head;
			d_head=d_head->rchild;
			DeleteAddLayer(d_head);			//cik的右子树的层数须增1 (以下情况i相同)
			free(rd_head);					//释放cik所占的内存空间
			rd_head=NULL;
		}

		else if((d_head->lchild!=NULL) && (d_head->rchild==NULL))          //情况3：节点cik只有左节点，没有右节点
		{
			Bitnode *ld_head=d_head;
			d_head=d_head->lchild;
			DeleteAddLayer(d_head);
			free(ld_head);
			ld_head=NULL;
		}

		else							//情况4：节点cik既有右节点，也有左节点								
		{												/////*******采用数据结构课本(严蔚敏)上的第二种方法	
			k=d_head;									//即：用节点cik的直接前驱iik替代cik，并删掉iik，再者iik的双亲节点fiik，fiik的右指针指向iik的左指针（如果iik的左指针存在）		

			f=k;	//f指向k的双亲节点
			k=k->lchild;	//k表示cik的直接前驱iik								
			while(k->rchild != NULL)
			{
				f=k;
				k=k->rchild;
			}

			d_head->data=k->data;			//用iik替代cik

			if(f==d_head)		//特殊情况，此情况为：cik的左指针，没有右子树
			{
				Bitnode *k_free=k;
				f->lchild=k->lchild;										
				DeleteAddLayer(k->lchild);
				free(k_free);
				k_free=NULL;

			}
			else
			{
				Bitnode *kk_free=k;
				f->rchild=k->lchild;			//fiik的右指针指向iik的左指针（左指针为空也没有错误，此时fiik的右指针依然为空）

				if(k->lchild != NULL)
				{	
					DeleteAddLayer(k->lchild);
				}
				free(kk_free);
				kk_free=NULL;
			}
		}


			return d_head;
	}

	else if(d_T<d_head->data)
	{
		d_head->lchild=DeleteBitTree(d_head->lchild,d_T);    //递归调用

		return d_head;
	}

	else
	{
		 d_head->rchild=DeleteBitTree(d_head->rchild,d_T);   //递归调用

		 return d_head;
	}
}
  


void DeleteAddLayer(Bitnode * l_head)	  	/////删除节点之后，相应节点的层数变化，此函数使节点的层数(layer-1)
{
	if(l_head != NULL)				//采用中序遍历
	{
		DeleteAddLayer(l_head->lchild);
		l_head->layer--;
		DeleteAddLayer(l_head->rchild);

	}
}





Bitnode *SearchBitTree(Bitnode *s_head,int s_T)       /////查找二叉排序树中与s_T相同的节点,返回头节点指针
{
	int i=1;		//用 i 计算查找的次数
	
	Bitnode *p=s_head;

	while(p!=NULL)
	{
		if(p->data == s_T)		//已找到要查找的节点
		{
			printf("您想要查找的节点值为 %d ,总共进行了 %d 次比较!\n",s_T,i);
			break;
		}

		else if(p->data > s_T)  //若此值比当前节点pt的值小，则在pt的左子树中查找
		{
			p=p->lchild;
			i++;
		}
		
		else					//若此值比当前节点pt的值大，则在pt的右子树中查找
		{
			p=p->rchild;
			i++;
		}
	}

	if(p==NULL)   //p==NULL则说明：查找到叶子节点后依然未找到要查找的元素，则此二叉排序树中没有要查找的元素
	{
		printf("您想查找的节点不存在!\n");
	}
	
	return s_head;
}



int DepthBitTree(Bitnode * dp_head)					/////计算二叉排序树的深度
{
	int lc=0;		//左子树的深度
	int rc=0;		//右子树的深度

	if(dp_head==NULL)
	{
		return 0;
	}

	lc=DepthBitTree(dp_head->lchild);
	rc=DepthBitTree(dp_head->rchild);

	return (lc>=rc?lc+1:rc+1);
}



int IsAVLBitTree(Bitnode *isa_head)				/////判断二叉排序树是否是平衡二叉树
{
	int alc=0;			//左子树深度
	int arc=0;			//右子树深度

	 int index_l=0;  
	 int index_r=0;

	if(isa_head==NULL)
	{
		return 1;				//空树是平衡二叉树
	}

	alc=DepthBitTree(isa_head->lchild);
	arc=DepthBitTree(isa_head->rchild);


	if((alc-arc>=2) || (alc-arc<=-2)) 
	{
		return 0;				//根节点的左右子树不是平衡二叉树
	}

	else				//根节点的左右子树满足平衡二叉树要求，再看左右子树是否满足要求
	{
		index_l=IsAVLBitTree(isa_head->lchild);
		index_r=IsAVLBitTree(isa_head->rchild);
	
		if(index_l==1 && index_r==1)		//根节点的左右子树都满足平衡二叉树的要求
		{
			return 1;
		}

		else							//根节点的左右子树不满足平衡二叉树的要求
		{
			return 0;
		}
	}
}




void InOrderTraverse(Bitnode *o_head)              /////中序遍历二叉排序树("需用到Visit(BitTree v_T)")
{
	if(o_head!=NULL)
	{
		InOrderTraverse(o_head->lchild);
		Visit(o_head);						//访问此节点的值(data 和 layer)
		InOrderTraverse(o_head->rchild);
	}
} 




void FreeBitTree(Bitnode *f_head)              /////释放二叉排序树每一个节点所占的空间
{
	if(f_head != NULL)
	{
		Bitnode *right=f_head->rchild;  //right指向f_head右子树的根节点

		FreeBitTree(f_head->lchild);
		free(f_head);      //释放f_head之后，用right表示他的右子树的根节点
		f_head=NULL;		//用此方法来释放这个二叉排序树每个节点所占的内存空间

		FreeBitTree(right);

	}
	
}   


Bitnode * FreeAllnode(Bitnode *fa_head)				/////释放二叉排序树各个节点所占的内存空间,返回头结点指针
{
	if(fa_head != NULL)
	{
		 FreeBitTree(fa_head);   //调用上面释放二叉排序树每个节点的空间
	}							

	fa_head=NULL;
	
	return fa_head;				//并把头结点指针的值置空，返回头结点指针

}





void SaveBitnode(Bitnode *sa_head)				/////把二叉排序树，单个节点内容保存到文件中
{
	FILE *s_fp=NULL;
	if((s_fp=fopen("BST.txt","a"))==NULL)				//为了没有错误的保存每个节点的值，定义此函数来
	{													//把每个节点的值保存到文件中
		printf("Can't open file BST.txt\n");
		exit(0);
	}

	fprintf(s_fp,"%d(%d层)   ",sa_head->data,sa_head->layer);

	fclose(s_fp);
}

void SaveBitTree(Bitnode *st_head)					/////把二叉排序树每个节点内容保存到文件BST.txt中
{
	if(st_head != NULL)							//用中序遍历把二叉排序树每个节点的值保存到文件BST.txt中
	{
		SaveBitTree(st_head->lchild);			
		SaveBitnode(st_head);
		SaveBitTree(st_head->rchild);
	}
}
