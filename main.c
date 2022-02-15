//
//  main.c
//  Standard Student Information System (SIS)
//
//  Created by 丁嘉诚 on 2022/2/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Find.h"
#include "Maintain.h"
#include "Init.h"

int main(int argc, char *argv[]) {
    char ch;
    int quitFlag, maintainFlag, findFlag;
    quitFlag = 1;
    stu *temp; //  指向初始化后的head
    temp = Init();
    if(temp!=NULL)
        while(quitFlag) {
            printf("\n\t\t********学生信息查询系统(SIS)********\n");
            printf("\t\t*             Q(Query).查询           *\n");
            printf("\t\t*             W(Write/Maintain).维护           *\n");
            printf("\t\t*             E(Exit).退出           *\n");
            printf("\t\t***************************************\n");
            printf("请选择(Q/W/E): ");
            ch = getchar();
            
            switch(tolower(ch)) {
                case 'q': findFlag = Find(temp); //  查询模式,实现在Find模块里
                          break;
                case 'w': maintainFlag = Maintain(temp);
                    //  维护模式,实现在Maintain模块里
                          break;
                case 'e': quitFlag = 0; //  退出
                          break;
                default:  printf("\n 输入错误，请重新输入\n\n\n");
                          break;
            }
        }
    else {
        printf("\n初始化学生信息失败！");
        return 1;
    }
    printf("\n 再见！请按任意键退出.");
    getchar();
    temp -> next = NULL;
    temp = NULL;
    free(temp);
    return 0;
}

