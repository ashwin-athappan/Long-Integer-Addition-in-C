#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
    int data;
    struct node *next,*prev;
};

struct node *I1 = NULL,*I2 = NULL,*Sum = NULL,*end = NULL;

void Add(struct node *L1,struct node *L2){
    int carry = 0,sum = 0;
    struct node *tmp1 = L1,*tmp2 = L2,*tmp3 = Sum,*new1 = NULL;
    while(tmp1 !=NULL || tmp2 != NULL) {

        if(tmp2 == NULL ){
            while(tmp1 != NULL) {
                new1 = (struct node *) malloc(sizeof(struct node));
                if(carry!=0){
                    new1->data = tmp1->data + carry;
                    carry = 0;
                } else{
                    new1->data = tmp1->data;
                }
                new1->next = new1->prev = NULL;
                tmp3 = Sum;
                while (tmp3->next != NULL) {
                    tmp3 = tmp3->next;
                }
                tmp3->next = new1;
                new1->prev = tmp3;
                end = new1;
                tmp1 = tmp1->next;
            }
        } else if(tmp1== NULL ){
            while(tmp2!=NULL) {
                new1 = (struct node *) malloc(sizeof(struct node));
                if (carry != 0) {
                    new1->data = tmp2->data + carry;
                    carry = 0;
                } else {
                    new1->data = tmp2->data;
                }
                new1->next = new1->prev = NULL;
                    tmp3 = Sum;
                    while (tmp3->next != NULL) {
                        tmp3 = tmp3->next;
                    }
                    tmp3->next = new1;
                    new1->prev = tmp3;
                    end = new1;
                    tmp2 = tmp2->next;

            }
        }else {

            new1 = (struct node *) malloc(sizeof(struct node));
            if (carry != 0) {
                sum = tmp1->data + tmp2->data + carry;
                carry = 0;
            } else {
                sum = tmp1->data + tmp2->data;
            }

            if (sum >= 10) {
                carry = sum % 10;
                sum = sum / 10;
                new1->data = carry;
                carry = sum;
            } else {
                new1->data = sum;
            }
            new1->next = new1->prev = NULL;

            if (Sum == NULL) {
                Sum = new1;
            } else {
                tmp3 = Sum;
                while (tmp3->next != NULL) {
                    tmp3 = tmp3->next;
                }
                tmp3->next = new1;
                new1->prev = tmp3;
                end = new1;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    if(carry != 0){
        new1 = (struct node *) malloc(sizeof(struct node));
        new1->data = carry;
        tmp3 = Sum;
        while(tmp3->next != NULL){
            tmp3 = tmp3->next;
        }
        tmp3->next = new1;
        new1->prev = tmp3;
        end = new1;
    }
}

void CreateList(char a[], int n){
    int i = 0;
    struct node *new1 = NULL,*tmp = I1;
    strrev(a);
    while(a[i] != '\0'){
        if(isdigit(a[i])){
            new1 = (struct node*)malloc(sizeof(struct node));
            new1->data = a[i] - 48;
            new1->next = new1->prev = NULL;
        }
        if(n == 1){
            if(I1 == NULL){
                I1 = new1;
            }else{
                tmp = I1;
                while(tmp->next != NULL){
                    tmp = tmp->next;
                }
                tmp->next = new1;
                new1->prev = tmp;
            }
        }else{
            if(I2== NULL){
                I2 = new1;
            }else{
                tmp = I2;
                while(tmp->next != NULL){
                    tmp = tmp->next;
                }
                tmp->next = new1;
                new1->prev = tmp;
            }
        }
        i++;
    }
}

void Display(struct node *t){
    struct node *tmp = end;
    while(tmp!=NULL){
        printf("%d",tmp->data);
        tmp = tmp->prev;
    }
}

int main() {
    char i1[30],i2[30];
    printf("Enter the first Long Integer:");
    scanf("%s",i1);
    CreateList(i1,1);
    printf("Enter the first Long Integer:");
    scanf("%s",i2);
    CreateList(i2,2);

    Add(I1,I2);
    Display(Sum);

    return 0;
}