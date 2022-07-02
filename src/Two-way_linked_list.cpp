#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;//定义数据类型
typedef struct DNode{
    ElemType data;//数据域
    struct DNode *prior;//前驱指针
    struct DNode *next;//后驱指针
}DNode, *DLinkList;

//双向链表头插法创建链表
DLinkList head_insert(DLinkList &DL){
    DNode *s;
    int x;
    DL = (DLinkList)malloc(sizeof(DNode));//带头结点的链表
    DL->prior = NULL;//头结点的前驱指针指向空
    DL->next = NULL;//头结点的后驱指针指向空
    scanf("%d",&x);//从标准输入读入数据
    //3 4 5 6 7 9999
    while(x!=9999){
        s=(DNode*)malloc(sizeof(DNode));//申请一个新空间给s，强制类型转换
        s->data=x;//把读取到的数据存入s的data域
        s->next = DL->next;//把s的指针指向头结点的指针
        if (DL->next != NULL) {
            DL->next->prior = s;//把s的指针指向头结点的指针
        }
        s->prior = DL;//把s的指针指向头结点
        DL->next = s;//把头结点的指针指向s
        scanf("%d",&x);//从标准输入读入数据
    }
    return DL;
}

//双向链表尾插法创建链表
DLinkList tail_insert(DLinkList &DL){
    int x;
    DL=(DLinkList)malloc(sizeof(DNode));//带头结点的链表
    DNode *s;//指向新结点的指针
    DNode *r=DL;//r代表尾指针
    DL -> prior = NULL;//头结点的前驱指针指向空
    scanf ("%d",&x);//从标准输入读入数据
    //3 4 5 6 7 9999
    while(x!=9999){
        s=(DNode*)malloc(sizeof(DNode));//申请一个新空间给s，强制类型转换
        s->data=x;//把读取到的数据存入s的data域
        r->next=s;//把r的指针指向s
        s->prior=r;//把s的指针指向r
        r=s;//r指向新的表尾节点
        scanf("%d",&x);//从标准输入读入数据
    }
    r->next=NULL;//把r的指针指向空
    return DL;
}

//按值查找
DNode *search(DLinkList DL, ElemType x){
    DNode *p = DL->next;
    while(p!=NULL && p->data!=x){
        p = p->next;
    }
    return p;
}

//按位置查找
DNode *search_pos(DLinkList DL, int pos){
    DNode *p = DL->next;
    int i = 1;
    if(i==0){
        return DL;
    }
    if(i<1){
        return NULL;
    }
    while(p&&i<pos){
        p = p->next;
        i++;
    }
    return p;
}

//新节点插入到指定位置
DNode *insert_pos(DLinkList DL, int pos, ElemType x){
    DNode *p = search_pos(DL, pos);
    DNode *s = (DNode*)malloc(sizeof(DNode));
    s->data = x;
    s->prior = p->prior;
    s->next = p;
    p->prior->next = s;
    p->prior = s;
    return s;
}

//删除指定位置的节点
DNode *delete_pos(DLinkList DL, int pos){
    DNode *p = search_pos(DL, pos);
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return p;
}

//打印链表
void print_list(DLinkList DL){
    DL = DL->next;
    while(DL!=NULL){
        printf("%3d ",DL->data);
        DL = DL->next;
    }
    printf("\n");
}

int main(){
    DLinkList DL;
    //头插法创建链表
    head_insert(DL);
    printf("头插法创建链表:");
    print_list(DL);

    //尾插法创建链表
    tail_insert(DL);
    printf("尾插法创建链表:");
    print_list(DL);

    //按值查找
    DNode *p = search(DL, 6);
    if(p!=NULL){
        printf("按值查找成功：");
        printf("%d\n",p->data);
    }
    else{
        printf("not found\n");
    }

    //按位置查找
    p = search_pos(DL, 3);
    if(p!=NULL){
        printf("按位置查找成功：");
        printf("%d\n",p->data);
    }
    else{
        printf("not found\n");
    }

    //新节点插入到指定位置
    p = insert_pos(DL, 3, 8);
    printf("新节点插入到指定位置成功：");
    print_list(DL);
    
    //删除指定位置的节点
    p = delete_pos(DL, 4);
    printf("删除指定位置的节点成功：");
    print_list(DL);
    return 0;
}