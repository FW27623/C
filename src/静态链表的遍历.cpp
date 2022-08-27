#include <stdio.h>
 
/* 静态链表 */
struct node
{
    int num;
    struct node *next;
};
 
int main()
{
    struct node stu[3];
    struct node *head, *p;
 
    stu[0].num = 10;		//对结点的num成员赋值
    stu[1].num = 20;
    stu[2].num = 30;
 
    head = &stu[0];		//头指针指向第1个结点stu[0]
    stu[0].next = &stu[1];	//将结点stu[1]的地址赋值给stu[0]结点的next成员
    stu[1].next = &stu[2];	//将结点stu[2]的地址赋值给stu[1]结点的next成员
    stu[2].next = NULL;		//stu[2]是最后一个结点，其next成员不存放任何结点的地址，置为NULL
 
    //遍历静态链表
    p = head;			//使p指针也指向第1个结点
    
    do{
        printf("%d\n", p->num);	//输出p所指向结点的数据
        p = p->next;		//然后让p指向下一个结点
    } while (p != NULL);	//直到p的next成员为NULL，即完成遍历
 
    return 0;
}