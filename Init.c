//
//  Init.c
//  Standard Student Information System (SIS)
//
//  Created by 丁嘉诚 on 2022/2/15.
//

#include "Init.h"

int Init(void) {
    FILE *fp;
    stu *p2, *p3 = NULL;
    fp = fopen("DATASHEET.DAT", "r");
    if(fp==NULL) {
        printf("\n 初始化失败!\n");
        fclose(fp);
        return 0;
    } else {
        p2 = (stu*)malloc(LEN);
        head = p2;
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
            p3 = p2;
            p3 = (stu*)malloc(LEN);
            p3 -> next = p2;
        } //  将文件中读到的学生信息存到链表head里
        p3 -> next = NULL;
        p3 = NULL;
        free(p2);
        p2 = NULL;
        fclose(fp);
        return 1;
    }
} //  初始化, 从数据表中读取学生信息
