/*********二叉排序树*********/
/****实现二叉排序树的操作****/

#ifndef _TREE_B_
#define _TREE_B_


#include<stdio.h>
#include<time.h>
#include<malloc.h>


typedef struct BitTree                           //定义二叉排序树每一个节点
{												 
	int data; 										//data--节点数据                                  
	int layer;										//layer--节点所在的层数

	struct BitTree *lchild,*rchild;					//定义每一个节点的左右指针(指向左右子树)
}Bitnode;



void Visit(Bitnode *v_T);                            //把节点v_T中的data和layer输出


Bitnode *CreatBitTree(void);    //创建有n个结点的二叉排序树,返回指向头节点的指针


Bitnode *RandomBitTree(void);    //随机创建一棵二叉排序树


float  AslBitTree(Bitnode *a_head);                   //计算二叉排序树的平均查找长度，并返回此数值
float AslLengthBitTree(Bitnode *al_head);				  //计算二叉排序树的总共的查找长度，并返回此数值
float AslNumberBitTree(Bitnode *an_head);				  //计算二叉排序树的节点的个数，并返回此数值


Bitnode * InsertBitTreenode(Bitnode *i_head,int &i_T);        //把节点i_T(需在函数中创建)插入二叉排序树中,并使新树为二叉排序树，返回头结点指针


Bitnode * DeleteBitTree(Bitnode *d_head,int d_T);        //把二叉排序树中,与d_T相同的节点删除,返回头节点指针
void DeleteAddLayer(Bitnode * l_head);						//此函数为删除节点后，相应节点层数的变化，而定义的函数


Bitnode * SearchBitTree(Bitnode *s_head,int s_T);     //查找二叉排序树中与s_T相同的节点,返回头节点指针


int DepthBitTree(Bitnode * dp_head);              //计算二叉排序树的深度
int IsAVLBitTree(Bitnode *isa_head);				//判断二叉排序树是否是平衡二叉树


void InOrderTraverse(Bitnode *o_head);              //中序遍历二叉排序树("需用到Visit(BitTree v_T)")


void FreeBitTree(Bitnode *f_head);                  //释放二叉排序树每个节点所占的内存空间
Bitnode * FreeAllnode(Bitnode *fa_head);				//释放二叉排序树各个节点所占的内存空间,返回头结点指针


void SaveBitTree(Bitnode *st_head);					//把二叉排序树每个节点内容保存到文件中
void SaveBitnode(Bitnode *sa_head);                 //把二叉排序树，单个节点内容保存到文件中

#endif 