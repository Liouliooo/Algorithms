/*********����������*********/
/****ʵ�ֶ����������Ĳ���****/

#ifndef _TREE_B_
#define _TREE_B_


#include<stdio.h>
#include<time.h>
#include<malloc.h>


typedef struct BitTree                           //�������������ÿһ���ڵ�
{												 
	int data; 										//data--�ڵ�����                                  
	int layer;										//layer--�ڵ����ڵĲ���

	struct BitTree *lchild,*rchild;					//����ÿһ���ڵ������ָ��(ָ����������)
}Bitnode;



void Visit(Bitnode *v_T);                            //�ѽڵ�v_T�е�data��layer���


Bitnode *CreatBitTree(void);    //������n�����Ķ���������,����ָ��ͷ�ڵ��ָ��


Bitnode *RandomBitTree(void);    //�������һ�ö���������


float  AslBitTree(Bitnode *a_head);                   //���������������ƽ�����ҳ��ȣ������ش���ֵ
float AslLengthBitTree(Bitnode *al_head);				  //����������������ܹ��Ĳ��ҳ��ȣ������ش���ֵ
float AslNumberBitTree(Bitnode *an_head);				  //��������������Ľڵ�ĸ����������ش���ֵ


Bitnode * InsertBitTreenode(Bitnode *i_head,int &i_T);        //�ѽڵ�i_T(���ں����д���)���������������,��ʹ����Ϊ����������������ͷ���ָ��


Bitnode * DeleteBitTree(Bitnode *d_head,int d_T);        //�Ѷ�����������,��d_T��ͬ�Ľڵ�ɾ��,����ͷ�ڵ�ָ��
void DeleteAddLayer(Bitnode * l_head);						//�˺���Ϊɾ���ڵ����Ӧ�ڵ�����ı仯��������ĺ���


Bitnode * SearchBitTree(Bitnode *s_head,int s_T);     //���Ҷ�������������s_T��ͬ�Ľڵ�,����ͷ�ڵ�ָ��


int DepthBitTree(Bitnode * dp_head);              //������������������
int IsAVLBitTree(Bitnode *isa_head);				//�ж϶����������Ƿ���ƽ�������


void InOrderTraverse(Bitnode *o_head);              //�����������������("���õ�Visit(BitTree v_T)")


void FreeBitTree(Bitnode *f_head);                  //�ͷŶ���������ÿ���ڵ���ռ���ڴ�ռ�
Bitnode * FreeAllnode(Bitnode *fa_head);				//�ͷŶ��������������ڵ���ռ���ڴ�ռ�,����ͷ���ָ��


void SaveBitTree(Bitnode *st_head);					//�Ѷ���������ÿ���ڵ����ݱ��浽�ļ���
void SaveBitnode(Bitnode *sa_head);                 //�Ѷ����������������ڵ����ݱ��浽�ļ���

#endif 