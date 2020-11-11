#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct bo{
    int id ;
    char name[50] ;
    int quantity ;
}arr[50]/**the array of data*/, coarr[50] ;//make a copy of the array.


int i=0;//define an var to control the size of array
FILE *fptr ;//file pointer
int po;// var to control the while
del();searByid();searByname();bookSort();bookUnsort();//define functions

/**function to  insert a book*/

char insbook(){
     fptr = fopen("newword.txt","a+");//open the file to append and write

     printf("\a Please input your ID & Your FULLNAME & Your GRADE  with space and when you finsh put _ : \n");
     fflush(stdin);
     scanf(" %d %s %d ", &arr[i].id , arr[i].name , &arr[i].quantity);
     //print the book that insert in the the program and in file
     printf(" the book is: %d %s %d ",arr[i].id , arr[i].name , arr[i].quantity);
     fprintf(fptr,"\n %d %s %d \n",arr[i].id ,arr[i].name ,arr[i].quantity);
     i++;

     printf("\n  The book is insert Successfully in the file \n ");
     return 0;
 }

 /**function to delete a book using id given by the user to search */

int del(){
    fptr = fopen("newword.txt","w+");//open the file to read
    rewind(fptr);
    int idt;int k=0; int d; //define var

    printf("Enter an ID to delete:\t");//ask an id to delete from the user
    scanf("%d",&idt);//scan the id
    //print all books that not == to the id that want to delete
    for(k=0;k<i;k++){
        if(arr[k].id != idt){
            fprintf(fptr,"%d %s %d \n",arr[k].id,arr[k].name,arr[k].quantity);
                }//end if
    }//end for
    for(d=0;d<i;d++)
    {
        if(arr[d].id ==idt)
        {
            printf("the ID found successfully \n");
            printf("the delete is success\n");

            fclose(fptr);//close the file
            return;
        }
    }//end of for
printf("the ID not Found \n");
fclose(fptr);//close file

return 0;

}

/**function to search with id */

int searByid(){
    fptr = fopen("newword.txt","r+");//open the file to read
     int num; int y; int d;
    printf("\a enter id to search : \t");
    scanf("%d",&num);//make the user input the id to search
    for(y=0; y<i; y++)
    {
        while(arr[y].id == num){
                printf("\n position %d \t name: %s \t quantity: %d \n",y ,arr[y].name ,arr[y].quantity);//print into program
                fclose(fptr);//close the file
                return;


          }//end while

    }//end for
printf("not found \n");
fclose(fptr);//close the file
     return 0;
}



/** function to search by name given by the user*/

int searByname(){
    fptr = fopen("newword.txt","r");//open the file

    char namSer[50]; int e;
    printf("\a Enter a book name to search:\t");
    fflush(stdin);
    gets(namSer);//get name to search
    for(e=0; e<i; e++){
        if( strcmp(arr[e].name , namSer )==0 ){
            printf("\a The position of the book is in:%d \n and it's name is: %s  \n and it's ID is:%d \n and it's quantity is:%d \n",e,arr[e].name,arr[e].id,arr[e].quantity);
            fclose(fptr);//close the file
            return;

        }//end if
    }//end for
printf("not found \n");
fclose(fptr);//close the file
return 0;
}

/** function to sort all books and display it to the user*/
int bookSort(){
    fptr = fopen("newword.txt","r");//open the file to read
    int j=0;int r;  int n;int a;int g;
    struct bo temp;

    for(g=0;g<i;g++)
    {
        for(n=0; n<i-1 ;n++)//for to go into the array to search
        {
            if(strcmp(arr[n].name , arr[n+1].name)>0)//if statement to check between 2 strings
            {
                temp=arr[n];//swapping
                arr[n]=arr[n+1];
                arr[n+1]=temp;
            }//end if

        }//end for 2

    }//end for 1

    for(a=0; a<i ; a++)
    {
        printf("%d %s %d \n",arr[a].id,arr[a].name,arr[a].quantity);//print to the user all books sorted
    }//end for

    fclose(fptr);//close the file
return 0;

}//end function



/**print all books without sorting*/

int bookunSoort(){
    fptr = fopen("newword.txt","r");//open the file to read
    int p;

    for(p=0; p<i; p++){
        printf("ID name quantity \n");
        printf("%d %s %d \n",arr[p].id , arr[p].name , arr[p].quantity);//print all books to the user
    }
    fclose(fptr);//close the file


return 0;

}//end function


int main()
{
    printf("Hello world!\n");
    printf(" \t Welcome into the library \n");//intro
    fptr = fopen("newword.txt","r");      /** open the file  on mode read*/
    if(fptr==NULL){
        printf("not opened");
    }
    else {
        printf("The file is opening Now");
    }


    //reading from the file
    while((fscanf(fptr,"%d %s %d",&arr[i].id, arr[i].name, &arr[i].quantity)!=EOF))
          {
              coarr[i].id = arr[i].id;
              strcpy( coarr[i].name , arr[i].name); /**function copies the string*/
              coarr[i].quantity = arr[i].quantity;
              i++;
              if (i==5){
                    break;
               }


    }
    fclose(fptr); // closing the file after reading and scanning

    int op; /** the operation */
    int o;/**to choose another*/
    char rel;char ch;
    do{
         while((fscanf(fptr,"%d %s %d",&arr[i].id, arr[i].name, &arr[i].quantity)!=EOF))
          {
              coarr[i].id = arr[i].id;
              strcpy( coarr[i].name , arr[i].name); /**function copies the string*/
              coarr[i].quantity = arr[i].quantity;
              i++;
              if (i==5){
                    break;
               }


    }
    fclose(fptr); // closing the file after reading and scanning


        printf("\a THE MENU : \n");//the menu to the user
        printf("1.INSERT A BOOK \n ");
        printf("2.DELETE A BOOK BY ID \n");
        printf("3.SEARCH BY ID \n 4.SEARCH BY NAME \n");
        printf("5.DISPLAY ALL BOOKS SORTED \n 6.DISPLAY ALL BOOKS UNSORTED \n");
        printf("\a choose from the menu:\t");
        scanf("%d",&op);
        switch(op){
            case 1:
                {
                    insbook();//to insert a new book
                    break;
                }

            case 2:
                {
                    del();//to delete a book
                    break;
                }

            case 3:
                {
                    searByid();//to search a bout a book with id token from the user
                    break;
                }
            case 4:
                {
                    searByname();//to search a bout a book with name token from the user
                    break;
                }
            case 5:
                {
                    bookSort();//to print all books sorted by name into program
                    break;
                }
            case 6:
                {
                    bookunSoort();//to print all books without sort into program
                    break;

                }
        }//end switch



    printf("Please Input 1 to continue to Another Operation:\t");
    fflush(stdin);
    scanf("%d",&po);
    system("cls");
    }while(po==1); //end do while

return 0;
}//end the main function
