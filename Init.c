//
//  Init.c
//  Standard Student Information System (SIS)
//
//  Created by 丁嘉诚 on 2022/2/15.
//

#include "Init.h"

stu *head; //  初始化head

stu *Init(void) {
    FILE *fp;
    stu *p1, *p2;
    fp = fopen("/Users/dingjiacheng/Desktop/ding/C_Playground/SIS/FILE.DAT ", "r+");
    if(fp==NULL) {
        printf("\n 初始化失败!\n");
        fclose(fp);
        return NULL;
    } else {
        p1 = (stu*)malloc(LEN);
        head = p1;
        while(!feof(fp)) {
            fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n" , p2->No
                                                  , p2->name
                                                  , p2->age
                                                  , p2->sex
                                                  , p2->className
                                                  , p2->address
                                                  , p2->email
                                                  , p2->QQ
                                                  , p2->tel);
            p2 = p1;
            p1 = (stu*)malloc(LEN);
            p2 -> next = p1;
        } //  将文件中读到的学生信息存到链表head里
        p2 -> next = NULL;
        p2 = NULL;
        free(p1);
        p1 = NULL;
        p1 = head;
        while(p1 != NULL) {
            printf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n" , p2->No
                                                  , p2->name
                                                  , p2->age
                                                  , p2->sex
                                                  , p2->className
                                                  , p2->address
                                                  , p2->email
                                                  , p2->QQ
                                                  , p2->tel);
            p1 = p1 -> next;
        }
        fclose(fp);
        return head;
    }
} //  初始化, 从数据表中读取学生信息
