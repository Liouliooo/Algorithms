/*********����������*********/
/****ʵ�ֶ����������Ĳ���****/
 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include"ercha_paixushu.h"



void Visit(Bitnode *v_T)                           /////�ѽڵ�v_T�е�data��layer���
{
	if(v_T!=NULL)                                              //Ҫ����Ľڵ���ڣ������ֵ
	{
		printf("%d(%d��)   ",v_T->data,v_T->layer);
	}
	else 
	{
		printf("�ڵ�û��ֵ!\n");
	}
}



Bitnode *CreatBitTree(void)				/////������n�����Ķ���������,����ָ��ͷ�ڵ��ָ��
{
	int number;
	Bitnode *c_head=NULL;
												//scanf�������سɹ��������Ŀ�ĸ������������������ַ��ͷ���ֵ0
	while(scanf("%d",&number))                //��������Ȼ��ѵ�һ����ֵ��Ϊ�����������ĸ��ڵ㣬�������ϵĽ��в��������
	{											//���գ����ղ������ݵ�˳�򣬴���һ�ö���������
 		c_head=InsertBitTreenode(c_head,number);
	}

	return c_head;                              //����ָ�����������ͷ����ָ��
}



Bitnode *RandomBitTree(void)					/////�������һ�ö���������
{
	int num;
	int i,end;

	Bitnode *r_head=NULL;                       //����ָ��ͷ����ָ��

	srand(time(NULL));                          //�Ե�ǰϵͳʱ����Ϊ�����������������
	end=rand()%100;                             //���ɵ�������ĸ�����100������
												//�����Ը�������ʱ�䣨GMT��Ϊ��׼����1970��1��1��00:00:00�����ڵĴ�ʱ�˿�������������

	for(i=0;i<end;i++)
	{
		num=rand()%1000;                       //ÿһ���������ֵ��1000����
		r_head=InsertBitTreenode(r_head,num);      //�Ѳ���ڵ�ķ�ʽ����һ�ö���������
	}
	
	return r_head;
}

 



float  AslBitTree(Bitnode *a_head)                  /////���������������ƽ�����ҳ��ȣ������ش���ֵ
{
	Bitnode *ap=a_head;
	float a_s=0;
	float length=AslLengthBitTree(ap);                //length��ʾ�ܹ��Ĳ��ҳ���
	float number=AslNumberBitTree(a_head);				//number��ʾ�ܹ��Ľڵ�ĸ���
	
	a_s=(length/number);

	printf("ƽ�����ҳ���ASL = %.0f/%.0f = ",length,number);

	return a_s;                                         //����ƽ�����ҳ���
}

float AslLengthBitTree(Bitnode *al_head)             /////����������������ܹ��Ĳ��ҳ��ȣ������ش���ֵ
{
	float s=0;
	if(al_head != NULL)                               //�������������������������ܲ��ҳ���
	{
		s+=AslLengthBitTree(al_head->lchild);             
		s+=al_head->layer;                             //layera��Ϊ��ÿһ���ڵ�Ĳ���
		s+=AslLengthBitTree(al_head->rchild);
	}
	return s;
}

float AslNumberBitTree(Bitnode *an_head)			/////��������������Ľڵ�ĸ����������ش���ֵ
{
	float k=0;
	if(an_head != NULL)								//�����������������������ڵ�ĸ�����
	{
		k+=AslNumberBitTree(an_head->lchild);		//���ڵ���ڣ��� K ֵ����1       
		k++;
		k+=AslNumberBitTree(an_head->rchild);
	}
	return k;
}



Bitnode *InsertBitTreenode(Bitnode *i_head,int &i_T)	/////�ѽڵ�i_T(���ں����д���)���������������,��ʹ����Ϊ����������������ͷ���ָ��
{
	int i_layer=1;
	Bitnode *s=NULL;							//sָ��Ҫ����Ľڵ�
	Bitnode *p=i_head;
	Bitnode *f=NULL;							//fָ��Ҫ����ڵ��˫�׽ڵ�

	while (p != NULL)
	{
		f=p;    ///fָ��Ҫ����ڵ��˫�׽ڵ�         
		
		if(p->data==i_T)
		{
			i_T=0;              //�����Ҫ����Ľڵ��Ѿ����ڣ�����û���Ҫ����Ľڵ�ֵ ��Ϊ 0,
			return i_head;		// ������ͷ���ָ��
		}
		else if(p->data < i_T)     //���Ҫ�����ֵ���ڸ��ڵ㣬���ڸ��ڵ���������в���
		{
			i_layer++;
			p=p->rchild;
		}
		else                       //���Ҫ�����ֵС�ڸ��ڵ㣬���ڸ��ڵ���������в���
		{
			i_layer++;
			p=p->lchild;
		}
	}

	s=(Bitnode*)malloc(sizeof(Bitnode));     //Ϊ�ڵ�����ڴ�ռ�
	s->data=i_T;							//�ڵ��ֵ��ΪҪ�����ֵ
	s->lchild=s->rchild=NULL;				//�ѽڵ������ָ������Ϊ��
	s->layer=i_layer;						//layerΪ�ڵ����ڵĲ������ڲ���Ĺ���֮���Ѿ��������ֵ

	if(i_head==NULL)                      //ͷ���Ϊ�գ�����s����ʱsָ��ͷ���
	{
		return s;
	}

	else if(f->data<i_T)			//˫�׽ڵ�f��ֵ��Ҫ����ڵ��ֵС����Ѹýڵ���뵽f��������
	{
		f->rchild=s;
	}
	else							//˫�׽ڵ�f��ֵ��Ҫ����ڵ��ֵ����Ѹýڵ���뵽f��������	
	{
		f->lchild=s;
	}
	return i_head;
}


Bitnode * DeleteBitTree(Bitnode *d_head,int d_T)        /////�Ѷ�����������,��d_T��ͬ�Ľڵ�ɾ��,����ͷ�ڵ�ָ��
{

	Bitnode *f=NULL;
	Bitnode *k=NULL;

	if(d_head==NULL)
	{
		printf("����ɾ���Ľڵ㲻����!\n");
		return d_head;
	}

	else if(d_T==d_head->data)                        //������������ڵ�cikֵ��ͬ��ɾ���ڵ�Ĳ���
	{
		if((d_head->lchild==NULL) && (d_head->rchild==NULL))               //���1:�ڵ�cik���ҽڵ�Ϊ��,��:cikΪҶ�ӽڵ�
		{
			free(d_head);													//��cik�ڵ���ռ���ڴ�ռ��ͷ�
			d_head=NULL;
		}


		else if((d_head->lchild==NULL) && (d_head->rchild!=NULL))              //���2���ڵ�cikֻ���ҽڵ㣬û����ڵ�
		{
			Bitnode *rd_head=d_head;
			d_head=d_head->rchild;
			DeleteAddLayer(d_head);			//cik���������Ĳ�������1 (�������i��ͬ)
			free(rd_head);					//�ͷ�cik��ռ���ڴ�ռ�
			rd_head=NULL;
		}

		else if((d_head->lchild!=NULL) && (d_head->rchild==NULL))          //���3���ڵ�cikֻ����ڵ㣬û���ҽڵ�
		{
			Bitnode *ld_head=d_head;
			d_head=d_head->lchild;
			DeleteAddLayer(d_head);
			free(ld_head);
			ld_head=NULL;
		}

		else							//���4���ڵ�cik�����ҽڵ㣬Ҳ����ڵ�								
		{												/////*******�������ݽṹ�α�(��ε��)�ϵĵڶ��ַ���	
			k=d_head;									//�����ýڵ�cik��ֱ��ǰ��iik���cik����ɾ��iik������iik��˫�׽ڵ�fiik��fiik����ָ��ָ��iik����ָ�루���iik����ָ����ڣ�		

			f=k;	//fָ��k��˫�׽ڵ�
			k=k->lchild;	//k��ʾcik��ֱ��ǰ��iik								
			while(k->rchild != NULL)
			{
				f=k;
				k=k->rchild;
			}

			d_head->data=k->data;			//��iik���cik

			if(f==d_head)		//��������������Ϊ��cik����ָ�룬û��������
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
				f->rchild=k->lchild;			//fiik����ָ��ָ��iik����ָ�루��ָ��Ϊ��Ҳû�д��󣬴�ʱfiik����ָ����ȻΪ�գ�

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
		d_head->lchild=DeleteBitTree(d_head->lchild,d_T);    //�ݹ����

		return d_head;
	}

	else
	{
		 d_head->rchild=DeleteBitTree(d_head->rchild,d_T);   //�ݹ����

		 return d_head;
	}
}
  


void DeleteAddLayer(Bitnode * l_head)	  	/////ɾ���ڵ�֮����Ӧ�ڵ�Ĳ����仯���˺���ʹ�ڵ�Ĳ���(layer-1)
{
	if(l_head != NULL)				//�����������
	{
		DeleteAddLayer(l_head->lchild);
		l_head->layer--;
		DeleteAddLayer(l_head->rchild);

	}
}





Bitnode *SearchBitTree(Bitnode *s_head,int s_T)       /////���Ҷ�������������s_T��ͬ�Ľڵ�,����ͷ�ڵ�ָ��
{
	int i=1;		//�� i ������ҵĴ���
	
	Bitnode *p=s_head;

	while(p!=NULL)
	{
		if(p->data == s_T)		//���ҵ�Ҫ���ҵĽڵ�
		{
			printf("����Ҫ���ҵĽڵ�ֵΪ %d ,�ܹ������� %d �αȽ�!\n",s_T,i);
			break;
		}

		else if(p->data > s_T)  //����ֵ�ȵ�ǰ�ڵ�pt��ֵС������pt���������в���
		{
			p=p->lchild;
			i++;
		}
		
		else					//����ֵ�ȵ�ǰ�ڵ�pt��ֵ������pt���������в���
		{
			p=p->rchild;
			i++;
		}
	}

	if(p==NULL)   //p==NULL��˵�������ҵ�Ҷ�ӽڵ����Ȼδ�ҵ�Ҫ���ҵ�Ԫ�أ���˶�����������û��Ҫ���ҵ�Ԫ��
	{
		printf("������ҵĽڵ㲻����!\n");
	}
	
	return s_head;
}



int DepthBitTree(Bitnode * dp_head)					/////������������������
{
	int lc=0;		//�����������
	int rc=0;		//�����������

	if(dp_head==NULL)
	{
		return 0;
	}

	lc=DepthBitTree(dp_head->lchild);
	rc=DepthBitTree(dp_head->rchild);

	return (lc>=rc?lc+1:rc+1);
}



int IsAVLBitTree(Bitnode *isa_head)				/////�ж϶����������Ƿ���ƽ�������
{
	int alc=0;			//���������
	int arc=0;			//���������

	 int index_l=0;  
	 int index_r=0;

	if(isa_head==NULL)
	{
		return 1;				//������ƽ�������
	}

	alc=DepthBitTree(isa_head->lchild);
	arc=DepthBitTree(isa_head->rchild);


	if((alc-arc>=2) || (alc-arc<=-2)) 
	{
		return 0;				//���ڵ��������������ƽ�������
	}

	else				//���ڵ��������������ƽ�������Ҫ���ٿ����������Ƿ�����Ҫ��
	{
		index_l=IsAVLBitTree(isa_head->lchild);
		index_r=IsAVLBitTree(isa_head->rchild);
	
		if(index_l==1 && index_r==1)		//���ڵ����������������ƽ���������Ҫ��
		{
			return 1;
		}

		else							//���ڵ����������������ƽ���������Ҫ��
		{
			return 0;
		}
	}
}




void InOrderTraverse(Bitnode *o_head)              /////�����������������("���õ�Visit(BitTree v_T)")
{
	if(o_head!=NULL)
	{
		InOrderTraverse(o_head->lchild);
		Visit(o_head);						//���ʴ˽ڵ��ֵ(data �� layer)
		InOrderTraverse(o_head->rchild);
	}
} 




void FreeBitTree(Bitnode *f_head)              /////�ͷŶ���������ÿһ���ڵ���ռ�Ŀռ�
{
	if(f_head != NULL)
	{
		Bitnode *right=f_head->rchild;  //rightָ��f_head�������ĸ��ڵ�

		FreeBitTree(f_head->lchild);
		free(f_head);      //�ͷ�f_head֮����right��ʾ�����������ĸ��ڵ�
		f_head=NULL;		//�ô˷������ͷ��������������ÿ���ڵ���ռ���ڴ�ռ�

		FreeBitTree(right);

	}
	
}   


Bitnode * FreeAllnode(Bitnode *fa_head)				/////�ͷŶ��������������ڵ���ռ���ڴ�ռ�,����ͷ���ָ��
{
	if(fa_head != NULL)
	{
		 FreeBitTree(fa_head);   //���������ͷŶ���������ÿ���ڵ�Ŀռ�
	}							

	fa_head=NULL;
	
	return fa_head;				//����ͷ���ָ���ֵ�ÿգ�����ͷ���ָ��

}





void SaveBitnode(Bitnode *sa_head)				/////�Ѷ����������������ڵ����ݱ��浽�ļ���
{
	FILE *s_fp=NULL;
	if((s_fp=fopen("BST.txt","a"))==NULL)				//Ϊ��û�д���ı���ÿ���ڵ��ֵ������˺�����
	{													//��ÿ���ڵ��ֵ���浽�ļ���
		printf("Can't open file BST.txt\n");
		exit(0);
	}

	fprintf(s_fp,"%d(%d��)   ",sa_head->data,sa_head->layer);

	fclose(s_fp);
}

void SaveBitTree(Bitnode *st_head)					/////�Ѷ���������ÿ���ڵ����ݱ��浽�ļ�BST.txt��
{
	if(st_head != NULL)							//����������Ѷ���������ÿ���ڵ��ֵ���浽�ļ�BST.txt��
	{
		SaveBitTree(st_head->lchild);			
		SaveBitnode(st_head);
		SaveBitTree(st_head->rchild);
	}
}
