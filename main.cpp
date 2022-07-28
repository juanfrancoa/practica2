#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>
using namespace std;

void aleatorio(char *b);
void punto2();
void punto3();
void punto4();
void punto5();
void punto6();
void punto8();
void punto10();
void punto11();
void cupunto11(char **a);
void punto12();
void cuadr14(int **asd);
void punto14();
void punto16();
void punto18();
int tamanio(char *a);
int tamanio(int a);
int cuadrado(int a,int b);
int conroma(char a);
bool bajar(int **a,int h,int k,int b,int n);
bool derecha(int **a,int h,int k,int b);

int main()
{

    //punto2();
    //punto3();
    //punto4();
    //punto5();
    //punto6();
    //punto8();
    //punto10();
    //punto11();
    //punto12();
    //punto14();
    //punto16();
    punto18();
    return 0;
}
int cuadrado(int a,int b){
    int y=a;
    for(int i=1;i<b;i++)
        y*=a;
    return y;
}
int tamanio(char* a){
    int i=0;
    while(a[i]!=0){
        i++;
    }
    return i;
}
int tamanio(int a){
    int p=1,n=-1,i=0;
    if(a>0){
        while(p<a){
            p*=10;
            i++;
        }
    }
    else if(a<0)
    {
        while(a<n){
            n*=10;
            i++;
        }
    }
    if(a==0)
        return 1;
    return i;
}
void aleatorio(char *b)
{
srand(time(NULL));
char ale;
for(int i=0;i<200;i++)
{ale = rand()%(90-65+1)+65;
b[i]=ale;
}
}
void punto2()
{
    char a[200];
    char *b = a;
    aleatorio(b);
    for(int l=0;l<200;l++)
    cout<<b[l];
    cout<<endl;
    for(char j=65;j<=90;j++)
    {
    int t=0;
    for(int k=0;k<200;k++)
        {
        if(j==b[k])
            t++;
        }
    cout<<j<<": "<<t<<endl;
    }
}
void punto3()
{
    char *a=nullptr,*b=nullptr;
    a=new char[50];b=new char[50];
    int gh=49;
    bool w=true;
    cout<<"Ingrese primera cadena de caracteres: "<<endl;
    cin.getline(a,gh);
    cout<<"Ingrese segunda cadena de caracteres: "<<endl;
    cin.getline(b,gh);
    if(tamanio(a)==tamanio(b)){
    for(int j=0;j<=tamanio(a);j++)
        {
            if(a[j]!=b[j])
                {
                w=false;
                break;
                }
         }
    }
    else{
        w=false;
    }
    if(w==true)
        cout<<"Verdadero"<<endl;
    else
        cout<<"Falso"<<endl;
    delete[] a;delete[] b;
}
void punto4()
{
    char *a=nullptr;a=new char [50];
    bool vr=true;
    cout<<"ingrese cadena de caracteres numericos :"<<endl;
    cin>>a;
    int i=tamanio(a);
    int *b=NULL;b=new int[i];
    for(int j=0;j<i;j++)
        {
        b[j]=a[j]-48;
        if(a[j]<48 or a[j]>57){
            cout<<"ERROR ENTRADA"<<endl;
            vr=false;
            break;
        }
        }
    if(vr==true){
        int n=i,h=0,yu=0;
        for(int k=0;k<i;k++)
            {
            yu = pow(10,n-1);
            h+=b[k]*(yu);
            n--;
            }
        cout<<h<<endl;
    }
    delete[] a;delete[] b;
}
void punto5(){
    int a=0;
    cout<<"Ingrese numero entero :";
    cin>>a;
    int y=0,b=0;
    y=tamanio(a);
    b=cuadrado(10,y-1);
    int hj=0;
    if(a>=0){
        char num[y];
        num[y]='\0';
        for(int i=y,g=0;i>0;i--,g++){
            hj=a/b;
            num[g]=hj+48;
            a-=b*hj;
            b/=10;
        }
    cout<<num<<endl;
    }
    else{
        char num[y+1];
        num[y+1]='\0';
        num[0]=45;
        a*=-1;
        for(int i=y,g=1;i>0;i--,g++){
            hj=a/b;
            num[g]=hj+48;
            a-=b*hj;
            b/=10;
        }
        cout<<num<<endl;
    }
}
void punto6()
{
    char *a=NULL;a=new char[100];
    int i=0;
    cout<<"Ingrese cadena de caractares a convertir : "<<endl;
    cin.getline(a,99);
    i=tamanio(a);
    char *b=NULL;
    b=new char[i];
    for(int j=0;j<i;j++)
        {
        if(a[j]>=97 and a[j]<=122)
            b[j]=a[j]-32;
        else
            b[j]=a[j];
        }
    for(int j=0;j<i;j++)
        cout<<b[j];
    cout<<endl;
    delete[] b;delete[] a;
}
void punto8(){
    char *a=NULL;
    a=new char[100];
    cout<<"Ingrese cadena de caracteres :";
    cin.getline(a,99);
    int tam=tamanio(a);
    int cnum=0;
    int ctex=0;
    char *num=NULL;num=new char[50];
    char *tex=NULL;tex=new char[50];
    for(int i=0;i<tam;i++){
        if(a[i]>=48 and a[i]<=57){
            num[cnum]=a[i];
            cnum++;
        }
        else{
           tex[ctex]=a[i];
           ctex++;
        }
    }
    num[cnum]='\0';
    tex[ctex]='\0';
    cout<<"Original: "<<a<<"."<<endl;
    cout<<"Texto: "<<tex<<". "<<"Numero: "<<num<<"."<<endl;
    delete []a;delete []num;delete []tex;
}
void punto10(){
    char *a=NULL;a=new char[100];
    cout<<"Ingrese numero romano en mayuscula: ";
    cin.getline(a,99);
    int tam=tamanio(a);
    int sum=0;
    for(int y=0;y<tam;y++){
        if(conroma(a[y])>=conroma(a[y+1])){
            sum+=conroma(a[y]);
        }
        else{
            sum-=conroma(a[y]);
        }
    }
    cout<<"El numero ingresado es: "<<a<<endl;
    cout<<"Que corresponde a: "<<sum<<endl;
    delete []a;
}
int conroma(char a){
    if(a=='M')
        return 1000;
    else if(a=='D')
        return 500;
    else if(a=='C')
        return 100;
    else if(a=='L')
        return 50;
    else if(a=='X')
        return 10;
    else if(a=='V')
        return 5;
    else if(a=='I')
        return 1;
}
void punto11()
{
    char f=NULL;
    int ds=NULL,hj=0;
    bool a=NULL;
    char **ag=NULL;ag=new char* [15];
    for(int i=0;i<15;i++)
        ag[i]=new char [20];
    for(int yu=0;yu<15;yu++)
    {
        for(int i=0;i<20;i++)
            ag[yu][i]=45;
    }
    cout<<"si desea hacer reserva ingrese 1,o cancelacion 0: ";
    cin>>a;
    cout<<"ingrese fila(a-o): ";
    cin>>f;
    cout<<"ingrese numero de silla(1-20): ";
    cin>>ds;
    for(char h=97;h<=111;h++)
    {
        hj++;
        if(h==f)
            break;
    }
    hj--;
    ds--;
    if(a==1)
        ag[hj][ds]=43;
    else
        ag[hj][ds]=45;
    cupunto11(ag);
    for(int i=0;i<15;i++)
            delete[] ag[i];
    delete[] ag;
}
void cupunto11(char **ag)
{
    char a=218,b=196,c=194,d=179,e=191,f=217,g=195,h=196,k=197,l=180,n=192,m=217,v=193;int df=0;
    cout<<a<<b<<b<<b;
    for(int i=0;i<19;i++)
        cout<<c<<b<<b<<b;
    cout<<e<<endl;
    for(df=0;df<14;df++)
    {
        for(int i=0;i<20;i++)
            cout<<d<<" "<<ag[df][i]<<" ";
        cout<<d<<endl;
        cout<<g<<b<<b<<b;
        for(int i=0;i<19;i++)
            cout<<k<<b<<b<<b;
        cout<<l<<endl;
    }
    for(int i=0;i<20;i++)
        cout<<d<<" "<<ag[df][i]<<" ";
    cout<<d<<endl;
    cout<<n<<b<<b<<b;
    for(int i=0;i<19;i++)
        cout<<v<<b<<b<<b;
    cout<<m<<endl;
}
void punto12()
{
    char a=218,b=196,c=194,d=179,e=191,f=217,g=195,h=196,k=197,l=180,n=192,m=217,v=193;
    int df=0,qw=0,**asd=NULL,dh=0;
    cout<<"Ingrese tamanio de la matriz: ";
    cin>>qw;
    asd=new int* [qw];
    for(int i=0;i<qw;i++)
        asd[i]=new int [qw];
    for(int yu=0;yu<qw;yu++)
    {
        cout<<"ingrese fila "<<yu+1<<": "<<endl;
        for(int i=0;i<qw;i++)
        {
            cout<<"ingrese termino "<<i+1<<": ";
            cin>>dh;
            asd[yu][i]=dh;
        }
    }
    cout<<a<<b<<b<<b;
    for(int i=0;i<qw-1;i++)
        cout<<c<<b<<b<<b;
    cout<<e<<endl;
    for(df=0;df<qw-1;df++)
    {
        for(int i=0;i<qw;i++)
            cout<<d<<" "<<asd[df][i]<<" ";
        cout<<d<<endl;
        cout<<g<<b<<b<<b;
        for(int i=0;i<qw-1;i++)
            cout<<k<<b<<b<<b;
        cout<<l<<endl;
    }
    for(int i=0;i<qw;i++)
        cout<<d<<" "<<asd[df][i]<<" ";
    cout<<d<<endl;
    cout<<n<<b<<b<<b;
    for(int i=0;i<qw-1;i++)
        cout<<v<<b<<b<<b;
    cout<<m<<endl;
    int jui=0,fgh=0;
    bool xc=1;
    for(int i=0;i<qw;i++)
    {
        fgh=jui;
        jui=0;
        for(int j=0;j<qw;j++)
            jui+=asd[i][j];
        if(fgh!=jui and fgh!=0)
        {
            xc=0;
            break;
        }
    }
    if(xc==1)
    {
        for(int i=0;i<qw;i++)
        {
            fgh=jui;
            jui=0;
            for(int j=0;j<qw;j++)
                jui+=asd[j][i];
            if(fgh!=jui and fgh!=0)
            {
                xc=0;
                break;
            }
        }
        if(xc==1)
        {
            jui=0;
            for(int i=0;i<qw;i++)
                jui+=asd[i][i];
            if(jui!=fgh)
                xc=0;
            if(xc==1)
            {
                jui=0;
                for(int i=0,k=qw;i<qw;i++,k--)
                    jui+=asd[k-1][i];
                if(jui!=fgh)
                    xc=0;
                if(xc==1)
                    cout<<"Verdadero"<<endl;
                else
                    cout<<"Falso"<<endl;
            }
            else
                cout<<"Falso"<<endl;
        }
        else
            cout<<"Falso"<<endl;
    }
    else
        cout<<"Falso"<<endl;
    for(int i=0;i<qw;i++)
        delete[] asd[i];
    delete[] asd;
}
void cuadr14(int **asd)
{
    char a=218,b=196,c=194,d=179,e=191,f=217,g=195,h=196,k=197,l=180,n=192,m=217,v=193;
    int df=0,qw=5;
    cout<<a<<b<<b<<b<<b;
    for(int i=0;i<qw-1;i++)
        cout<<c<<b<<b<<b<<b;
    cout<<e<<endl;
    for(df=0;df<qw-1;df++)
    {
        for(int i=0;i<qw;i++)
        {
            if(asd[df][i]<10)
                cout<<d<<" "<<asd[df][i]<<"  ";
            else
                cout<<d<<" "<<asd[df][i]<<" ";
        }
        cout<<d<<endl;
        cout<<g<<b<<b<<b<<b;
        for(int i=0;i<qw-1;i++)
            cout<<k<<b<<b<<b<<b;
        cout<<l<<endl;
    }
    for(int i=0;i<qw;i++)
    {
        if(asd[df][i]<10)
            cout<<d<<" "<<asd[df][i]<<"  ";
        else
            cout<<d<<" "<<asd[df][i]<<" ";
    }
    cout<<d<<endl;
    cout<<n<<b<<b<<b<<b;
    for(int i=0;i<qw-1;i++)
        cout<<v<<b<<b<<b<<b;
    cout<<m<<endl;
}
void punto14()
{
    char a=218,b=196,c=194,d=179,e=191,f=217,g=195,h=196,k=197,l=180,n=192,m=217,v=193;
    int qw=5,**asd=NULL,dh=1;
    asd=new int* [qw];
    for(int i=0;i<qw;i++)
        asd[i]=new int [qw];
    for(int yu=0;yu<qw;yu++)
    {
        for(int i=0;i<qw;i++)
        {
            asd[yu][i]=dh;
            dh++;
        }
    }
    cuadr14(asd);
    cout<<90<<endl;
    dh=1;
    for(int yu=qw-1;yu>=0;yu--)
    {
        for(int i=0;i<qw;i++)
        {
            asd[i][yu]=dh;
            dh++;
        }
    }
    cuadr14(asd);
    cout<<180<<endl;
    dh=1;
    for(int yu=qw-1;yu>=0;yu--)
    {
        for(int i=qw-1;i>=0;i--)
        {
            asd[yu][i]=dh;
            dh++;
        }
    }
    cuadr14(asd);
    cout<<270<<endl;
    dh=1;
    for(int yu=0;yu<qw;yu++)
    {
        for(int i=qw-1;i>=0;i--)
        {
            asd[i][yu]=dh;
            dh++;
        }
    }
    cuadr14(asd);
    for(int i=0;i<qw;i++)
        delete[] asd[i];
    delete[] asd;
}
void punto16()
{
    int n=0;
    cout<<"Ingrese numero entero: ";
    cin>>n;
    int b=n;
    b++;
    int cont=0;
    int **a=NULL;a=new int*[n];
    for(int i=0;i<n;i++)
        a[i]=new int [n];
    for(int i=0;i<n;i++){
        for(int y=0;y<n;y++)
            a[i][y]=1;
    }
    bool gh=false;
    int h=0,k=0;
    while(gh==false){
        if(bajar(a,h,k,b,n)==0){
            a[h+1][k]=2;
            cout<<2<<endl;
        }
        else{
            gh=true;
        }
    }
    b--;
    cout<<"Para una malla de "<<b<<"x"<<b<<" puntos hay "<<cont<<" caminos."<<endl;
    for(int i=0;i<n;i++)
        delete[] a[i];
    delete[] a;
}
bool bajar(int **a,int h,int k,int b,int n){
    if(h+1<=b-1){
        if(h+1<=n){
            if(a[h+1][k]==1){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

void punto18()
{
    int n=0,tam=10,*a=NULL;a=new int [tam];
    int*b=NULL;b=new int [10];int*c=NULL;c=new int [10];
    cout<<"Ingrese numero de permutacion: ";
    cin>>n;
    int j=n-1;
    for(int i=0;i<10;i++)
        b[i]=i;
    for(int i=1;i<=tam;i++)
    {
        a[tam-i]=j%i;
        j=j/i;
    }
    for(int i=0;i<tam;i++)
    {
        c[i]=b[a[i]];
        for(int j=a[i];j<tam;j++)
            b[j]=b[j+1];
    }
    cout<<"La permutacion numero "<<n<<" es: ";
    for(int i=0;i<tam;i++)
        cout<<c[i];
    cout<<endl;
    delete[] a;delete[] b;delete[] c;
}
