//Simple Quiz Game
//Made by @asenaislive and @DarkDevil.
//Testing by @jyoshnavi2416 and Debugging by @snehapatnala1316
//Difficulty is chosen by age.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char anse[10];
char ansm[10];
char ansh[10];
int ii=0;
//ANSI codes for text colour
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"
//Used to clear input buffer to maintain input flow
void clsc()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//Converts lower case inputs to upper case 
void cln(char *name)
{
 int i=0, j=0;
 while (name[i])
 {
  if(isalpha(name[i]) || name[i] == ' ')
   name[j++]=name[i];
  i++;
 }
 name[j]='\0';
}
//checks if age has anything other than numbers
int isNum(const char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if(!isdigit(str[i]))
    return 0;
  }
  return 1;
}
//Exits if the user's age has any letters or special characters
int chkag(char ag[5])
{
  if (!isNum(ag))
  {
    printf("Invalid age. Only numbers are accepted.\n");
    exit(0);
  }
  ag = atoi(ag);
  return ag;
}
char con(char a)
{
  //This is to convert lowercase user answers to uppercase
  while(1)
  {
    if(a>='A' && a<='D')
      return a;
    else if(a>='a' && a<= 'd')
      return a-32;
    else if((a>='E' && a<='Z') || (a>='e' && a<='z'))//This checks if the user entered anything except A, B, C, D.
    {
      if(ii<2)
      {
        printf(RED"Invalid Input. Try again: "RESET);//The user gets 3 tries to answer. The quiz ends after 3 incorrect answers.
        scanf(" %c",&a);
        ii++;
      }
     else
      {
        printf(RED"\nToo many invalid attempts. Quiz ended. \n\t\tExiting.."RESET);
        exit(0);
      }
     clsc();
    }
    //This handles special characters like @,# and whitespaces
    else
    {
      if(ii<2)
      {
        printf(RED"Invalid Input. Try again: "RESET);
        scanf(" %c",&a);
        ii++;
      }
      else
      {
        printf(RED"\nToo many invalid attempts. Quiz ended.\n\t\tExiting.."RESET);
        exit(0);
      }
      
    }
  }
}
//Checks answers entered by the user with the actual answers.
//Returns score of the user based on the number of correct answers
int anscheck(char acheck[10], char level, char icans[10], int *wa)
{
    int i, score=0;
    char canse[10] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', 'A', 'C', 'B'}; // contains answers for Easy mode
    char cansm[10] = {'A', 'C', 'C', 'C', 'B', 'B', 'C', 'D', 'C', 'B'}; // Medium mode
    char cansh[10] = {'A', 'B', 'B', 'D', 'B', 'C', 'A', 'C', 'B', 'C'}; // Hard mode
    char *cor;
    if(level == 'E')
        cor=canse;
    else if(level == 'M')
        cor=cansm;
    else
        cor=cansh;    
    for(i=0; i<10; i++)
    {
        if(cor[i]==acheck[i])
            score++;
        else
            icans[(*wa)++]=i;
    }
    return score;
}

//Easy Level Quiz Questions
int easy(char icans[10], int *wa)
{
    int i=-1;
    char ans;
    printf(GREEN"\n\n\tWelcome to the EASY LEVEL!\n");
    printf("\t\tGood luck!\n\n"RESET);
    printf(BLUE"\n==============================================="RESET);
    printf("\nPress Enter to continue.");//Waits for the user to press Enter to start the game.
    clsc();
    int ch = getchar();
    if(ch == '\n')
    {
        printf("\n1. What do you use to click and move to things on the screen?\nA) Mouse\nB) Remote\nC) Pencil\nD) Eraser\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);//con function is called for every input from the user
        anse[++i]=ans;
        
        printf("\n2. What helps you listen to sounds from the computer?\nA) printer\nB) Speaker\nC) Camera\nD) Microphone\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        anse[++i]=ans;
        
        printf("\n3. What do we call the big box that runs the computer?\nA) Monitor\nB) CPU\nC) Bag\n D) UPS\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        anse[++i]=ans;
        
        printf("\n4. What can you use to draw on the computer?\nA) Paint Program\nB) Calculator\nC) Clock \nD) Files\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        anse[++i]=ans;

        printf("\n5. What is a computer made of?\nA) Toys\nB) Books\nC) Parts like monitor and keyboard\nD) Blocks\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        anse[++i]=ans;
        
        printf("\n6. What shows pictures and videos on the computer?\nA) Monitor\nB) Keyboard\nC) Mouse\nD) Speaker\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        anse[++i]=ans;
        
        printf("\n7. Which device is used to print documents and pictures?\nA) Scanner\nB) Printer\nC) Speaker\nD) Mouse\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        anse[++i]=ans;
        
        printf("\n8. What do we use to type letters and numbers?\nA) Keyboard\nB) Monitor\nC) Mouse\nD) Camera\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        anse[++i]=ans;
        
        printf("\n9. What is used to take photos or videos on a computer?\nA) Speaker\nB) Microphone\nC) Camera\nD) Printer\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        anse[++i]=ans;
        
        printf("\n10. What connects a computer to the internet without wires?\nA) USB Cable\nB) Wi-Fi\nC) HDMI Cable\nD) Charger\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        anse[++i]=ans;
    }

    int score=anscheck(anse,'E', icans, wa);//Calls function to verify answers.
    return score;
}

//Medium Level Quiz Questions
int medium(char icans[10], int *wa)
{
    int i=-1;
    char ans;
    printf(YELLOW"\n\n\tWelcome to the MEDIUM LEVEL!\n");
    printf("\t\tGood luck!\n\n"RESET);
    printf(BLUE"==============================================="RESET);
    printf("\n\nPress Enter to continue.");
    clsc();
    int ch = getchar();
    if(ch == '\n')
    {
        printf("\n1. What does GUI stand for?\nA) Graphical User Interface\nB) General Utility Interface\nC) Graphic Usage Indicator\nD) Game User Interface\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
        
        printf("\n2. Which device is used to store data permanently?\nA) RAM\nB) ROM\nC) Hard Disk / SSD\nD) Cache\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
        
        printf("\n3. Which of the following is an input device?\nA) Printer\nB) Speaker\nC) Keyboard\nD) Monitor\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
        
        printf("\n4. What does HTTP stand for?\nA) Hyperlink Text Transfer Protocol\nB) High Text Transfer Program\nC) HyperText Transfer Protocol\nD) Home Terminal Transfer Process\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
        
        printf("\n5. What is the main circuit board inside a computer called?\nA) RAM\nB) Motherboard\nC) Hard Drive\nD) Processor\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
        
        printf("\n6. What does CPU stand for?\nA) Central Programming Unit\nB) Central Processing Unit\nC) Central Processing Utility\nD) Central Power Unit\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
        
        printf("\n7. What is the main funtof RAM?\nA) Stores data permanently \nB) Process graphics\nC) Stores data temporarily\nD) Connect to the Internet\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
        
        printf("\n8. Which part handles graphics and video rendering?\nA) CPU\nB) RAM\nC) SSD\nD) GPU\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
        
        printf("\n9. What connects your computer to a Wi-Fi network?\nA) Bluetooth\nB) USB Cable\nC) Network card/Wi-Fi adapter\nD) HDMI\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
        
        printf("\n10. Which software helps you browse the internet?\nA) Excel\nB) Chrome\nC) Paint\nD)Notepad\n---->>>>");
        scanf(" %c",&ans);
        ans=con(ans);
        ansm[++i]=ans;
    }
    
    int score=anscheck(ansm, 'M', icans, wa);
    return score;
}

//Hard Level Quiz Questions
int hard(char icans[10], int *wa)
{
    int i=-1;
    char ans;
    printf(RED"\n\n\tWelcome to the HARD LEVEL!\n");
    printf("\t\tGood luck!\n\n"RESET);
    printf(BLUE"\n==============================================="RESET);
    printf("\n\nPress Enter to continue.");
    clsc();
    int ch = getchar();
    if(ch == '\n')
    {
          printf("\n1. Which file extension is used for an executable program in Windows?\nA) .exe\nB) .txt\nC) .jpg\nD) .mp4\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
          
          printf("\n2. What does URL stand for?\nA) Universal Reference Location\nB) Uniform Resource Locator\nC) User Resource Link\nD) Unified Routing Language\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
        
          printf("\n3. What does SSD stand for?\nA) Standard Storage Drive\nB) Solid State Drive\nC) Secure Software Disk\nD) Speed Storage Device\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
         
          printf("\n4. Which of the following is an example of open-source software?\nA) Microsoft Office\nB) Windows 11\nC) Adobe Photoshop\nD) LibreOffice\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
        
          printf("\n5. Which of the following is a cloud storage service?\nA) Zoom\nB) OneDrive\nC) VLC\nD) PowerPoint\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
          
          printf("\n6. Which of the following is not an operating system?\nA) Linux\nB) Windows\nC) Oracle\nD) macOS\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
        
          printf("\n7. What does IP stand for in networking?\nA) Internet Protocol\nB) Internal Processing\nC) Input Protocol\nD) Integrated Pathway\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
        
          printf("\n8. What is the purpose of an operating system?\nA) Browse websites\nB) Run antivirus\nC) Manage hardware and software\nD) Write documents\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
        
          printf("\n9. What is the primary function of a firewall?\nA) Increase computer speed\nB) Protect against malware\nC) Filter network traffic\nD) Clean temporary files\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
        
          printf("\n10. Which command is used in Command Prompt to view files in a folder?\nA) open\nB) show\nC) dir\nD) list\n---->>>>");
          scanf(" %c",&ans);
          ans=con(ans);
          ansh[++i]=ans;
    }
    int score=anscheck(ansh, 'H', icans, wa);
    return score;
}

void main()
{
    int age, choice, score, i;
    char ag[5];
    char name[40];
    char icans[10];
    int wa=0;
    printf("Enter your name:");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")]='\0';
    cln(name);//Removes special characters and numbers
    printf("Enter your age:");
    if(scanf("%s",ag)==1)
    {
        age=chkag(ag);//calls the check age function
        if(age<3 || age>40)
        {
            printf("<<<<<<<<<<Not Eligible>>>>>>>>");
            exit(0);//Program exits if User not eligible
        }
        else if(age>=3 && age<=10)
            choice=1;  //game is set to easy mode
        else if(age>=11 && age<=21)
            choice=2;  //game is set to medium mode
        else if(age>=22 && age<=40)
            choice=3;  //game is set to hard made
    }
    else
    {
        printf("Invalid age.");
        exit(0);
    }
    printf(BLUE"\n==============================================="RESET);
    printf(GREEN"\n\n\t\tTech Trivia\n"RESET);
    switch(choice)
    {
        case 1: score=easy(icans, &wa);
                break;
        case 2: score=medium(icans, &wa);
                break;
        case 3: score=hard(icans, &wa);
                break;
    }
    //Final output
    printf("\n\n\n");
    printf(GREEN"\t\tYOU FINISHED THE TRIVIA!\n");
    printf(GREEN"\t\tNAME:%s\n",name);
    printf("\t\tAGE:%d \n",age);
    printf("\t\tYOUR SCORE:%d \n"RESET,score);
    if (wa != 0)
    {
       printf(RED"\tNumber of incorrect answers: %d\n",wa);
       printf("\tQuestions answered incorrectly: ");
       for(i=0; i<wa; i++)
        printf("%d ",icans[i]+1);
    }
    printf(RESET"\n\n\n");
    printf(BLUE"*************THANK YOU FOR PLAYING************"RESET);
}
