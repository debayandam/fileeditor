#include <stdio.h>
#include <stdlib.h>
void create (FILE *p);
void delete (FILE *p);
void open (FILE *p);
void file_rename();
void close(void);
int main()
{
    FILE *f;
    int o;
    printf ("MAIN MENU \n\n");
    do
    {
        printf("Enter the option number : \n");
        printf("1.Create a new File.\n");
        printf("2.Open a File.\n");
        printf("3.Delete a File.\n");
        printf("4.Rename a File.\n");
        printf("5.Exit\n\n");
        scanf("%d",&o);
        switch(o)
        {
            case 1 : create(f);
            break;

            case 2 : open(f);
            break;

            case 3 : delete(f);
            break;

            case 4 : file_rename();
            break;

            case 5 :
                close();
                exit(2);
        }
    }while(1);

}
void create (FILE *f)
{
    char name[20],c;
    printf ("Enter the file name : \n");
    scanf("%s",name);

    printf ("Enter characters to input:\n");

    f=fopen(name,"w");
    while((c=getchar())!='.')
    {
        putc(c,f);
    }
    fclose(f);
    printf("\nFile created and closed successfully. \n");
}
void delete(FILE *f)
{
    char filename[20];
    int status;
    printf("Enter the file name:\n");
    scanf("%s",filename);
    f = fopen(filename, "r");
    if(f == NULL)
    {
        printf("Error:  file not found! check the directory!! \n");
        exit(0);
    }
    fclose(f);
    status = remove(filename);

    if( status == 0 )
    printf("%s file deleted successfully. \n",filename);
    else
    {
        printf("Unable to delete the file \n");
        perror("Error");
    }

}
void open(FILE *f)
{
    char name[20],c;
    int o;
    printf("\nEnter the option no : \n");
    printf("1.Open and Read.\n");
    printf("2.Open and add.\n");
    scanf("%d",&o);
    printf("Enter the file name : \n");
    scanf("%s",name);
    switch(o)
    {
        case 1 : f=fopen(name,"r");
                while((c=getc(f))!=EOF)
                {
                     printf("%c",c);
                }
                fclose(f);
                printf("\n");
                break;
        case 2 : f=fopen(name,"a");
                while((c=getchar())!='.')
                {
                    putc(c,f);
                }
                fclose(f);
                printf("Added Successfully ! \n");
                printf("\n");
                break;

    }
}
void file_rename()
{
    int ret;
    char new[20],old[20];
    printf("Enter the File name to be renamed : \n");
    scanf("%s",old);
    printf("Enter the new file name : \n");
    scanf("%s",new);
    ret = rename(old, new);
   if(ret == 0)
   {
      printf("File renamed successfully.\n");
   }
   else
   {
      printf("Error: unable to rename the file\n\n");
   }
}
void close(void)
{
     printf("This project has been created by DEBAYAN DAM.\n");
}
