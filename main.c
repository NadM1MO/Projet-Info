#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct pixel{
int couleur[3];
int energie;
int predecesseur;
int distance;
};

typedef struct pixel pixel;

void nextline(FILE *f){                //fonction pour sauter une ligne dans un fichier//
int c=fgetc(f);
while(c!='\n'){c=fgetc(f);}
return; }


int largeur(FILE *f){            //récupérer la largeur du tableau de pixels à créer//
nextline(f);
int c=fgetc(f);  char s[6]; int i=0;
while(c!=' '){ s[i]=c; i++; c=fgetc(f);}
int r=atoi(s);
return r;}

int hauteur(FILE *f){          //récupérer la hauteur du tableau de pixels à créer//
int c=fgetc(f);  char s[6]; int i=0;
while(c!='\n'){  s[i]=c; i++; c=fgetc(f);}
int r=atoi(s);
return r;}

int conversion(FILE *f){
int c=fgetc(f); char s[10];  int i=0;
while(c==' ' || c=='\n'){c=fgetc(f);}
while(c!=' ' && c!='\n' && c!=EOF){ s[i]=c; i++; c=fgetc(f);}
int r=atoi(s);
s[0]='\0'; s[1]='\0'; s[2]='\0';
return r;}


pixel** remplissage(FILE *f){
int M=largeur(f);
int N=hauteur(f);
printf("La largeur est %d et la hauteur %d\n",M,N);
nextline(f);  int i,j;    pixel**p=malloc(M*sizeof(pixel)); int k; // OK car M colonnes
for(i=0;i<M;i++){p[i]=malloc(N*sizeof(pixel));} // ici pour chaque pixel de la 1ère ligne (il y en a M), on alloue de la mémoire pour un tableau de taille N (Nb de lignes)
for(i=0;i<N;i++){
   for(j=0;j<M;j++){
      for(k=0;k<3;k++){
         p[i][j].couleur[k]=conversion(f);
      }
    p[i][j].distance=-1;
    p[i][j].predecesseur=-1;
   }
}
i=0; j=0;
for(i=0;i<N;i++){   //calcule de l'energie pour chaque pixel qui ne sont pas au bord de l'image//
    for(j=1;j<M-1;j++){
       p[i][j].energie=(p[i][j-1].couleur[0]-p[i][j+1].couleur[0])*(p[i][j-1].couleur[0]-p[i][j+1].couleur[0])+(p[i][j-1].couleur[1]-p[i][j+1].couleur[1])*(p[i][j-1].couleur[1]-p[i][j+1].couleur[1])+(p[i][j-1].couleur[2]-p[i][j+1].couleur[2])*(p[i][j-1].couleur[2]-p[i][j+1].couleur[2]);
    }
}
return p;}

void image(FILE *f,pixel **p){
rewind(f);
int M=largeur(f);
int N=hauteur(f);  
FILE *fp=fopen("essai.txt","w+");
int i,j,k;
char s[4]; sprintf(s,"%d",M);
fputs("P3\n",fp); fputs(s,fp); fputc(' ',fp); sprintf(s,"%d",N); fputs(s,fp); fputc('\n',fp); fputs("255\n",fp);
for(i=0;i<N;i++){
   for(j=0;j<M;j++){
      for(k=0;k<3;k++){
           printf("%d ",p[i][j].couleur[k]);
            sprintf(s,"%d",p[i][j].couleur[k]);
           fputs(s,fp); fputc(' ',fp);
      }
   }
     fputc('\n',fp);
     printf("\n");
}

return;}

int main(){
FILE *f=fopen("test.o","r");
pixel **p=remplissage(f);
image(f,p);
fclose(f);
return 0;}
