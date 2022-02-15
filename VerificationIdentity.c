//
//  VerificationIdentity.c
//  Standard Student Information System (SIS)
//
//  Created by 丁嘉诚 on 2022/2/15.
//

#include "VerificationIdentity.h"

int VerificationIdentity(void) {
    char UID[20], pwd[20]; //  UID: 输入的用户名, pwd: 输入的用户口令
    char SID[20], key[20]; //  SID: 已注册用户名, key: 已注册口令
    int i, legalFlag = 0; //  用户名和密码匹配标识
    char ch;
    FILE *fp;
    fp = fopen("/Users/dingjiacheng/Desktop/ding/C_Playground/SIS/keygenSIS.txt", "r");
    if(fp==NULL) {
        printf("\n ID文件不存在! 按任意键继续...\n");
        getchar();
    } else {
        do {
            printf("\n 请输入用户名(不超过14个纯英文字符): ");
            
            i = 0;
            while (isalpha(ch=getchar())&&(i<15)) {
                UID[i] = ch;
                i++;
            } //  限定用户名只可以输入英文
            UID[i] = '\0';
            printf("\n 请输入密码(不超过10个数字): ");
            
            i = 0;
            while (isdigit(ch=getchar())&&(i<10)) {
                pwd[i] = ch;
                i++;
            } //  限定用户名只可以输入英文
            pwd[i] = '\0';
            rewind(fp); //  使文件位置指针重回文件开始的位置
            while(!feof(fp)) {
                fscanf(fp, "%s\t%s\t\n", SID, key);
                if((strcmp(UID, SID)==0)&&(strcmp(pwd, key)==0)) {
                    legalFlag = 1; //  匹配成功
                    break;
                }
            } //  当读文件结束时, 触发用户名与密码匹配
            if(legalFlag) {
                break;
            } else {
                printf("\n 用户名或密码不正确, 是否重新输入? [y/n]: ");
                ch = getchar();
            }
        } while(tolower(ch)=='y');
    }
    return legalFlag;
} //  鉴权
