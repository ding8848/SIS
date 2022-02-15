//
//  FindStu.c
//  Standard Student Information System (SIS)
//
//  Created by 丁嘉诚 on 2022/2/14.
//

#include "FindStu.h"

int FindNumber(void) {
    char input_nu[11]; //  输入的学生学号
    stu *p;
    int flag;
    flag = 5; //  查找失败标志, 5谐音"无"
    p = head;
    printf("\n 请输入您要查找学生的学号[00000000001~99999999999]: ");
    gets(input_nu);
    while(p!=NULL) {
        if(strcmp(input_nu, p->No)==0) {
            printf("\n 学号: %s\n", p->No);
            printf(" 姓名: %s\n", p->name);
            printf(" 年龄: %s\n", p->age);
            printf(" 性别: %s\n", p->sex);
            printf(" 班级: %s\n", p->className);
            printf(" 地址: %s\n", p->address);
            printf(" E-mail: %s\n", p->email);
            printf(" QQ: %s\n", p->QQ);
            printf(" 电话: %s\n", p->tel);
            flag = 1; //  查找成功
        }
        p = p -> next;
    }
    return flag;
}

int FindAddrApart(void) {
    char input_ad[20]; //  输入的学生地址
    stu *p;
    int flag;
    flag = 5;
    p = head;
    printf("\n 请输入您想要查找学生的住址: ");
    gets(input_ad);
    while(p!=NULL) {
        if(strcmp(input_ad, p->address)==0) {
            printf("\n 学号: %s\n", p->No);
            printf(" 姓名: %s\n", p->name);
            printf(" 年龄: %s\n", p->age);
            printf(" 性别: %s\n", p->sex);
            printf(" 班级: %s\n", p->className);
            printf(" 地址: %s\n", p->address);
            printf(" E-mail: %s\n", p->email);
            printf(" QQ: %s\n", p->QQ);
            printf(" 电话: %s\n", p->tel);
            flag = 1; //  查找成功
        }
        p = p -> next;
    }
    return flag;
}

int FindName(void) {
    char input_na[10]; //  输入的学生名字
    stu *p;
    int flag;
    flag = 5;
    p = head;
    printf("\n 请输入您想要查找学生的姓名: ");
    gets(input_na);
    while(p!=NULL) {
        if(strcmp(input_na, p->name)==0) {
            printf("\n 学号: %s\n", p->No);
            printf(" 姓名: %s\n", p->name);
            printf(" 年龄: %s\n", p->age);
            printf(" 性别: %s\n", p->sex);
            printf(" 班级: %s\n", p->className);
            printf(" 地址: %s\n", p->address);
            printf(" E-mail: %s\n", p->email);
            printf(" QQ: %s\n", p->QQ);
            printf(" 电话: %s\n", p->tel);
            flag = 1; //  查找成功
        }
        p = p -> next;
    }
    return flag;
}

