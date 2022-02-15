//
//  Find.c
//  Standard Student Information System (SIS)
//
//  Created by 丁嘉诚 on 2022/2/14.
//

#include "Find.h"

int Find(stu *head) {
    char ch;
    system("stty -icanon");
    int flag;
    flag = 4;
    while(flag) {
        printf("\n\t\t********** Query(查询) **********\n");
        printf("\t\t*          A(Adress).地址          *\n");
        printf("\t\t*          S(Student Number).学号        *\n");
        printf("\t\t*          D(Designation).姓名           *\n");
        printf("\t\t*          Q(Quit).退出          *\n");
        printf("请输入选择(A/S/D/Q): ");
        ch = getchar();
        switch(tolower(ch)) {
            case 'a': flag = FindAddrApart(head); //  查找地址,实现在FindStu模块里
                      break;
            case 's': flag = FindNumber(head); //  查找学号,实现在FindStu模块里
                      break;
            case 'd': flag = FindName(head); //  查找姓名,实现在FindStu模块里
                      break;
            case 'q': flag = 0; //  退出
                      break;
            default:  printf("\n 输入错误，请重新输入: ");
                      flag = 4;
                      break;
        }
        if(flag==5) {
            printf("你要查找的学生不存在！\n");
            printf("是否继续查找？[Y/N]");
            ch = getchar();
             if(tolower(ch)=='y')
                 continue;
             else
                 flag = 0;
        }
    }
    return flag;
}
