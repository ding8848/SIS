//
//  FindStu.h
//  Standard Student Information System (SIS)
//  
//  Created by 丁嘉诚 on 2022/2/14.
//

#ifndef FindStu_h
#define FindStu_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char No[11], name[10],sex[5], age[4];
    char className[10], address[30], email[20], QQ[15], tel[11];
    struct student *next;
}stu; //  自定义一个存储学生信息的结构体类型

#define LEN sizeof(stu) //  stu类型的大小

int FindNumber(stu *head);
int FindAddrApart(stu *head);
int FindName(stu *head);

#endif /* FindStu_h */
