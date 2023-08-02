#include<stdio.h>
#include<malloc.h>
typedef struct LNode{
    int data;
    struct LNode*next;
}LNode,*LinkList;
bool InitList(LinkList &L);//��ʼ��
LNode*GetElem(LinkList L,int i);//��λ����
LNode*LocateElem(LinkList L,int i);//��ֵ����
int Length(LinkList L);//������ĳ���
bool InsertNextNode(LNode*p,int e);//���������ڽ��p�����Ԫ��e
bool InsertPriorNode(LNode*p,int e);//ǰ��������ڽ��pǰ����Ԫ��e
bool ListInsert(LinkList&L,int i,int e);//��ͷ���Ĳ���������ڵ�i��λ�ò���Ԫ��e
bool ListDelete(LinkList&L,int i,int e);//ɾ��λ��i�Ľ�㣬e��i����ֵ
bool DeleteNode(LNode*p) ;//ɾ��ָ�����P
LinkList List_TailInsert(LinkList&L,int a[],int n);//β�巨,��ͷ���
LinkList List_HeadInsert(LinkList&L,int a[],int n);//ͷ�巨����ͷ���

LinkList List_TailInsert(LinkList&L,int a[],int n){//β�巨����ͷ���
    L=(LinkList)malloc(sizeof(LNode));
    LNode*s,*r=L;//r��ʾ��βָ��
    for(int i=0;i<n;i++){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
LinkList List_HeadInsert(LinkList&L,int a[],int n) {//ͷ�巨����ͷ���
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    LNode*s;
    for(int i=0;i<n;i++){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}
bool InitList(LinkList&L){//��ʼ��
    L=(LNode*)malloc(sizeof(LNode));
    if(!L) return false;
    L->next=NULL;
    return true;
}
LNode* GetElem(LinkList L,int i){//����Ų��ҽ��
    if(i<1) return NULL;
    int j=1;
    LNode*p=L->next;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
LNode* LocateElem(LinkList L,int e){//��ֵ����
    LNode*p=L->next;
    while(p&&p->data!=e){
        p=p->next;
    }
    return p;
}
int Length(LinkList L){//ͳ�Ƶ�����ĳ���
    int len=0;
    LNode* p=L;
    while(p->next){
        len++;
        p=p->next;
    }
    return len;
}
bool InsertNextNode(LNode*p,int e){//���������ڽ��p�����Ԫ��e
    if(!p) return false;
    LNode*s=(LNode*)malloc(sizeof(LNode));
    if(!s) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
bool InsertPriorNode(LNode*p,int e){//ǰ��������ڽ��pǰ����Ԫ��e
    if(!p) return false;
    LNode*s=(LNode*)malloc(sizeof(LNode));
    if(!s) return false;
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}
bool ListInsert(LinkList&L,int i,int e){//��ͷ���Ĳ���������ڵ�i��λ�ò���Ԫ��e
    if(i<1)  return false;
    LNode*p=GetElem(L,i-1);
    if(!p) return false;
    return InsertNextNode(p,e);
    /*if(i<1) return false;
    int j=1;
    LNode*p=L->next;
    while(p&&j<i-1){
        p=p->next;
        j++;
    }
    if(!p) return false;
    LNode*s=(LNode*)malloc(sizeof(LNode));
    if(!s) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;*/
}
bool ListDelete(LinkList&L,int i,int e) {//ɾ��λ��i�Ľ�㣬e��i����ֵ
    if(i<1)return false;
    LNode*p=GetElem(L,i-1);
    if(!p||!(p->next)) return false;
    LNode*q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}
bool DeleteNode(LNode*p) {//ɾ��ָ�����P
    if (p->next == NULL) return false;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}
void print(LinkList L){
    LNode*s=L;
    while(s->next!=NULL){
        s=s->next;
        printf("%3d",s->data);
    }
    printf("\n");
}
int main(){
    LinkList L;
    int a[]={1,2,3,4,5,6,7};
    List_TailInsert(L,a,7);
    printf("β�巨�Ľ����");
    print(L);
}