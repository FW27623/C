#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;//定义数据类型
typedef struct LNode{
    ElemType data;//数据域
    struct LNode *next;//指向下一个节点
}LNode, *LinkList;

//头插法创建链表
LinkList CreatList1(LinkList &L){
    LNode *s;int x;
    L=(LinkList)malloc(sizeof(LNode));//带头结点的链表
    L->next=NULL;//头结点指向空
    scanf("%d",&x);//从标准输入读入数据
    //3 4 5 6 7 9999
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));//申请一个新空间给s，强制类型转换
        s->data=x;//把读取到的数据存入s的data域
        s->next=L->next;//把s的指针指向头结点的指针
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}

//尾插法创建链表
LinkList CreatList2(LinkList &L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));//带头结点的链表
    LNode *s, *r=L;//(LinkList s,r=L;)也可这样写，r代表链表表尾结点，指向链表尾部
    //3 4 5 6 7 9999
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;//r指向链表尾结点，指向新结点s
        r=s;//r指向最后一个节点
        scanf("%d",&x);
    }
    r->next=NULL;//尾结点的next指针指向NULL
    return L;
}

//按值查找
LNode *GetElem(LinkList L, ElemType e){
    while(L->next != NULL && L->data != e){
        L = L->next;
    }
    if(L->data == e){
        return L;
    }else{
        return NULL;
    }
}

//按序号查找节点值
LNode *GetElem1(LinkList L, int i){
    int j = 1;
    LNode *p = L->next;//让p指向第一个节点
    if(i==0){
        return L;//如果i=0，返回头结点
    }
    if (i < 1){
        return NULL;//如果i<1，返回NULL
    }
    while(p&&j<i){
        p = p->next;
        j++;
    }
    return p;
}

//新节点插入到第i个位置
bool ListInsert(LinkList &L, int i, ElemType e){
    int j = 1;
    LinkList p = L;//让p指向头结点
    while(p->next != NULL && j < i){
        p = p->next;//让p指向第i个节点
        j++;
    }
    if(j == i){
        LinkList q = (LinkList)malloc(sizeof(LNode));
        q->data = e;//把e存入q的data域
        q->next = p->next;//把q的指针指向p的指针
        p->next = q;//把p的指针指向q
        return true;
    }else{
        return false;
    }
}

//删除第i个节点
bool ListDelete(LinkList &L, int i){
    int j = 1;
    LinkList p = L;
    while(p->next != NULL && j < i){
        p = p->next;
        j++;
    }
    if(j == i){
        LinkList q = p->next;
        p->next = q->next;
        free(q);
        return true;
    }else{
        return false;
    }
}

//打印链表中每个节点的值
void PrintList(LinkList L){
    L=L->next;
    while(L != NULL){
        printf("%3d ",L->data);//打印当前节点的值
        L = L->next;//指针后移
    }
    printf("\n");
}

int main(){
    LinkList L;
    LinkList search;
    
    //头插法创建链表（头插法尾插法在本代码中同时只能存在一个）
    // CreatList1(L);
    
    //尾插法创建链表
    CreatList2(L);
    PrintList(L);
    
    //按值查询
    search = GetElem(L, 3);
    if(search != NULL){
        printf("按值查找成功，查找到的值为：");
        printf("%d\n", search->data);
    }else{
        printf("%s\n", "not found");
    }
    
    //按序号查询
    search = GetElem1(L, 2);
    if(search != NULL){
        printf("按序号查找成功，查找到的值为：");
        printf("%d\n", search->data);
    }else{
        printf("%s\n", "not found");
    }
    
    //新节点插入到第i个位置
    ListInsert(L, 3, 10);
    printf("插入后的链表为：");
    PrintList(L);
    
    //删除第i个节点
    ListDelete(L, 3);
    printf("删除后的链表为：");
    PrintList(L);
    return 0;
}