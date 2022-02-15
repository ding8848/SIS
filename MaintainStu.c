//
//  MaintainStu.c
//  Standard Student Information System (SIS)
//  
//  Created by 丁嘉诚 on 2022/2/15.
//

#include "MaintainStu.h"

int Add(stu *head) {
    stu *p2, *p3;
    char ch;
    int addFlag = 3; //  初始化为3, 防止影响到 Maintain 模块的循环逻辑
    p2 = head;
    while(p2->next!=NULL) {
        p2 = p2 -> next;
    }
    ch = 'y';
    while(tolower(ch)=='y') {
        p3 = (stu*)malloc(LEN);
        printf("\n 请根据提示依次输入: \n");
        printf("学号: ");
        gets(p3->No);
        printf("\n姓名: ");
        gets(p3->name);
        printf("\n年龄: ");
        gets(p3->age);
        printf("\n性别: ");
        gets(p3->sex);
        printf("\n班级: ");
        gets(p3->className);
        printf("\n地址: ");
        gets(p3->address);
        printf("\nE-mail: ");
        gets(p3->email);
        printf("\nQQ: ");
        gets(p3->QQ);
        printf("\n电话: ");
        gets(p3->tel);
        p3 -> next = NULL;
        printf("\n 请确认上述输入[y/Y], 或按其他键继续...");
        ch = getchar();
        if(tolower(ch)=='y') {
            p2 -> next = p3;
            p2 = p3;
            p3 = NULL;
            printf("\n 添加学生信息成功！！ ... 请按任意键继续 ...");
            getchar();
            putchar('\n');
            addFlag = 1; //  追加成功标识
        } else {
            printf("\n 添加学生信息失败!!! ... 按任意键继续 ...");
            getchar();
            putchar('\n');
            addFlag = 2;
        }
        printf("\n 是否继续添加学生信息？继续[y/Y]; 否[n/N]: ");
        ch = getchar();
    }
    p2 = NULL;
    return addFlag;
} //  添加新的学生信息

int Del(stu *head) {
    char ch, input_No[11];
    int deleteFlag = 2; //  初始化为2, 防止影响到 Maintain 模块的循环逻辑
    stu *p2, *p3;
    ch = 'y';
    while(tolower(ch)=='y') {
        printf("\n 请输入要删除学生的学号(回车确认): ");
        gets(input_No);
        p2 = head;
        p3 = NULL;
        while(p2!=NULL) {
            if(strcmp(p2->No, input_No)) {
                p3 = p2;
                p2 = p2 -> next;
            } else {
                printf("您将要删除的学生是: %s\n", p2->name);
                printf("请您再次确认[y/Y]: ");
                ch = getchar();
                if(tolower(ch)=='y') {
                    p3 -> next = p2 -> next;
                    deleteFlag = 3; //  删除成功标识
                    break;
                } else {
                    deleteFlag = 4; //  取消删除标识
                    break;
                }
            }
        }
        if(p2==NULL) {
            printf("\n 不存在您要删除的学生信息, 请按任意键继续...\n");
            deleteFlag = 5; //  删除失败标识
            getchar();
        }
        printf("\n 是否继续删除? [y/Y], 退出请按其他任意键...\n");
        ch = getchar();
    }
    return deleteFlag;
} //  删除指定学生信息

int Set(stu *head) {
    int SetFlag = 7; //  初始化为7, 防止影响到 Maintain 模块的循环逻辑
    char ch, input_No[11];
    stu *p2, *p3;
    do {
        printf("\n 请输入待修改学生的学号(回车键确认): ");
        gets(input_No);
        p2 = head;
        p3 = NULL;
        while(p2!=NULL) {
            if(strcmp(p2->No, input_No)) {
                p2 = p2 -> next;
            } else {
                break;
            }
        }
        while(1) {
            printf("\n 您要修改的学生原信息是: \n");
            printf("\n 学号: %s\n", p2->No);
            printf(" 姓名: %s\n", p2->name);
            printf(" 年龄: %s\n", p2->age);
            printf(" 性别: %s\n", p2->sex);
            printf(" 班级: %s\n", p2->className);
            printf(" 地址: %s\n", p2->address);
            printf(" E-mail: %s\n", p2->email);
            printf(" QQ: %s\n", p2->QQ);
            printf(" 电话: %s\n", p2->tel);
            printf("\n 请输入要修改的信息名称: \n");
            printf("1.学号 2.姓名 3.年龄 4.性别 5.班级 6.地址 7.E-mail 8.QQ 9.电话\n");
            printf("请选择(数字): ");
            ch = getchar();
            switch(ch) {
                case '1': printf("\n 请输入新的学号(回车结束): ");
                          gets(p2->No);
                          SetFlag = 6; //  修改成功标识
                          break;
                case '2': printf("\n 请输入新的姓名(回车结束): ");
                          gets(p2->name);
                          SetFlag = 6;
                          break;
                case '3': printf("\n 请输入新的年龄(回车结束): ");
                          gets(p2->age);
                          SetFlag = 6;
                          break;
                case '4': printf("\n 请输入新的性别(回车结束): ");
                          gets(p2->sex);
                          SetFlag = 6;
                          break;
                case '5': printf("\n 请输入新的班级(回车结束): ");
                          gets(p2->className);
                          SetFlag = 6;
                          break;
                case '6': printf("\n 请输入新的地址(回车结束): ");
                          gets(p2->address);
                          SetFlag = 6;
                          break;
                case '7': printf("\n 请输入新的邮箱(回车结束): ");
                          gets(p2->email);
                          SetFlag = 6;
                          break;
                case '8': printf("\n 请输入新的QQ(回车结束): ");
                          gets(p2->QQ);
                          SetFlag = 6;
                          break;
                case '9': printf("\n 请输入新的电话(回车结束): ");
                          gets(p2->tel);
                          SetFlag = 6;
                          break;
                default:  printf("\n 输入错误, 请重新输入: \n");
                          SetFlag = 5; //  修改失败标识
                          break;
            }
            printf("\n 是否还要继续修改学生信息? [y/n]: ");
            ch = getchar();
            if(tolower(ch)=='y') {
                continue;
            } else {
                break; //  跳出最内层循环
            }
        }
        printf("\n 是否还要继续修改学生信息? [y/n]: ");
        ch = getchar(); //  跳出外层循环
    } while(tolower(ch)=='y');
    return SetFlag;
} //  修改指定学生信息
