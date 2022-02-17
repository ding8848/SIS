//
//  Init.c
//  Standard Student Information System (SIS)
//
//  Created by 丁嘉诚 on 2022/2/15.
//

#include "Init.h"

stu *Init(void) {
    FILE *fp;
    stu *head, *p, *r; //  r是尾节点
    head = NULL;
    r = NULL;
    fp = fopen("./FILE.DAT ", "r");
    if(fp==NULL) {
        printf("\n 初始化失败!\n");
        fclose(fp);
        return NULL;
    } else {
        p = (stu*)malloc(LEN);
        while(!feof(fp)) {
            fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n" , p->No
                                                  , p->name
                                                  , p->age
                                                  , p->sex
                                                  , p->className
                                                  , p->address
                                                  , p->email
                                                  , p->QQ
                                                  , p->tel);
            if(head==NULL) {
                head = p;
            } else {
                r -> next = p;
            }
            r = p;
        } //  将文件中读到的学生信息存到链表head里
        if(r!=NULL) {
            r -> next = NULL;
        } //  将尾节点的指针域置空
        fclose(fp);
        free(p);
        return head;
    }
} //  初始化, 从数据表中读取学生信息
