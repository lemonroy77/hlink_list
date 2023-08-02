#include<stdio.h>
#include<malloc.h>
typedef struct LNode{
    int data;
    struct LNode*next;
}LNode,*LinkList;
bool InitList(LinkList &L);//初始化
LNode*GetElem(LinkList L,int i);//按位查找
LNode*LocateElem(LinkList L,int e);//按值查找
int Length(LinkList L);//求单链表的长度
bool InsertNextNode(LNode*p,int e);//后插操作，在结点p后插入元素e
bool InsertPriorNode(LNode*p,int e);//前插操作，在结点p前插入元素e
bool ListInsert(LinkList&L,int i,int e);//带头结点的插入操作，在第i个位置插入元素e
bool ListDelete(LinkList&L,int i,int e);//删除位序i的结点，e是i结点的值
bool DeleteNode(LNode*p) ;//删除指定结点P
LinkList List_TailInsert(LinkList&L,int a[],int n);//尾插法,带头结点
LinkList List_HeadInsert(LinkList&L,int a[],int n);//头插法，带头结点

LinkList List_TailInsert(LinkList&L,int a[],int n){//尾插法，带头结点
    L=(LinkList)malloc(sizeof(LNode));
    LNode*s,*r=L;//r表示表尾指针
    for(int i=0;i<n;i++){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
LinkList List_HeadInsert(LinkList&L,int a[],int n) {//头插法，带头结点
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
bool InitList(LinkList&L){//初始化
    L=(LNode*)malloc(sizeof(LNode));
    if(!L) return false;
    L->next=NULL;
    return true;
}
LNode* GetElem(LinkList L,int i){//按序号查找结点
    if(i<1) return NULL;
    int j=1;
    LNode*p=L->next;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
LNode* LocateElem(LinkList L,int e){//按值查找
    LNode*p=L->next;
    while(p&&p->data!=e){
        p=p->next;
    }
    return p;
}
int Length(LinkList L){//统计单链表的长度
    int len=0;
    LNode* p=L;
    while(p->next){
        len++;
        p=p->next;
    }
    return len;
}
bool InsertNextNode(LNode*p,int e){//后插操作，在结点p后插入元素e
    if(!p) return false;
    LNode*s=(LNode*)malloc(sizeof(LNode));
    if(!s) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
bool InsertPriorNode(LNode*p,int e){//前插操作，在结点p前插入元素e
    if(!p) return false;
    LNode*s=(LNode*)malloc(sizeof(LNode));
    if(!s) return false;
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}
bool ListInsert(LinkList&L,int i,int e){//带头结点的插入操作，在第i个位置插入元素e
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
bool ListDelete(LinkList&L,int i,int e) {//删除位序i的结点，e是i结点的值
    if(i<1)return false;
    LNode*p=GetElem(L,i-1);
    if(!p||!(p->next)) return false;
    LNode*q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}
bool DeleteNode(LNode*p) {//删除指定结点P
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
    printf("尾插法的结果：");
    print(L);
}
