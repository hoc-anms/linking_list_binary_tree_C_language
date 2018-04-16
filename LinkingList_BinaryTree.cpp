#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//khai bao kieu du lieu danhba
typedef struct danhba{
	char hoten[50];
	char sdt[12];
	int quanhe;
}danhba;
//khai bao cau truc 1 node
typedef struct node{
	danhba data;// du lieu cua node ==> du lieu mà node se luu tru
	struct node *left;//node lien ket ben trai cua cay<=> cay con ben trai
	struct node *right;//node lien ket ben phai cua cay<=> cay con ben phai
}node;
//dinh nghia 1 cay
typedef struct node*tree;
//tao 1 cay rong
void taocay(tree&t){
	t=NULL;//cay rong
}
//Ham nhap vào thông tin danh ba
void nhapthongtin(danhba &x){
	//nhap vao ho ten
		printf("\nNhap ho ten: ");
		fflush(stdin);// xoa bo dem
		gets(x.hoten);
	//nhap so dien thoai
	int m;
	do{
		printf("\nNhap so dien thoai  : ");
		fflush(stdin);
		gets(x.sdt);
		m=strlen(x.sdt);
		if(m<10 || m>11) printf("\nSo khong hop le, moi ban nhap lai so dien thoai :");//so dien thoai chi co 10 or 11 so
	}while(m<10 || m>11);
	//nhap don vi
    do{
    	printf("\nNhap ma quan he : ");
    	printf("1:Gia dinh  2:Ban be   3:Dong nghiep\n ");
    	scanf("%d",&x.quanhe);
    	if(x.quanhe>3||x.quanhe<1)
    	  printf("\nMoi nhap lai ma quan he phu hop :");
    }while(x.quanhe>3||x.quanhe<1);
}
//them 1 node vao cay
void themnode(tree&t,danhba x){
	//neu cay rong 
	if(t==NULL){
		node*q=(node*)malloc(sizeof(node));//cap phat bo nho dong cho mang de tiet kiem du lieu thanh ghi
		q->data=x;// them du lieu x vao data
		q->left=q->right=NULL;
		t=q;// node p chinh la node goc => node x chinh la node goc vi q tro den x
	}
	//cay co ton tai phan tu
	else{
		if(strcmp(t->data.sdt,x.sdt)>0) //ham strcmp ham so sanh chuoi chuoi 1= node t tro toi data.sdt chuoi 2 tro den x.sdt
		   themnode(t->left,x);//duyet qua trai de them chuoi x
		else {
	    	if(strcmp(t->data.sdt,x.sdt)<0) 
			themnode(t->right,x);//duyet qua phai de them chuoi x
		}
	}
}

//nhap du lieu vao cay
void nhapcay(tree&t){
 int luachon;
	do{
		printf("\n_______________LUA CHON_________________");
		printf("\n0:Ket thuc.\n1:Nhap du lieu   : ");
		scanf("%d",&luachon);
		if(luachon!=0&&luachon!=1){ 
		   printf("\nMoi ban nhap vao lua chon phu hop: ");}
		else{
			if(luachon==1){
		    	danhba x;//nhap du lieu lieu danh ba khach hang
		    	nhapthongtin(x);
		    	themnode(t,x);}//them node
		}
	}while(luachon!=0);
}
void form()
{
	printf("\n+---------------+-------------------+----------------------------+");
	printf("\n|      HO TEN   |       SDT         |           Quan he          |");	
    printf("\n+---------------+-------------------+----------------------------+\n");
}
//ham xuat ra thong tin
void xuatthongtin(danhba x){
	switch(x.quanhe)
	{
		case 1:{
	 		printf("|%-15s|%-19s|Gia dinh                    |\n",x.hoten,x.sdt);
	 		 printf("+---------------+-------------------+----------------------------+\n");
			break;
		}
		case 2:{
			printf("|%-15s|%-19s|Ban be                      |\n",x.hoten,x.sdt);
			 printf("+---------------+-------------------+----------------------------+\n");
			break;
		}
		case 3:{
			printf("|%-15s|%-19s|Dong nghiep                 |\n",x.hoten,x.sdt);
			 printf("+---------------+-------------------+----------------------------+\n");
			break;
		}
	}
	
   
}
//duyet cay co 3 cach duyet cay
//duyet truoc
void NLR(tree t){
	//neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL){
		xuatthongtin(t->data);//xuat du lieu trong node
		NLR(t->left);//duyet qua trai
		NLR(t->right);//duyet qua phai
	}
}
//duyet giua
void LNR(tree t){
		//neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL){
		LNR(t->left);//duyet qua trai
		xuatthongtin(t->data);//xuat du lieu trong node
	    LNR(t->right);//duyet qua phai
	}
}
//duyet sau
void LRN(tree t){
	//neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL){
		LRN(t->left);//duyet qua trai
	    LRN(t->right);//duyet qua phai
	    xuatthongtin(t->data);//xuat du lieu trong node
	}
}


// ham xoa node  trong cay
void xoanode(tree &t, char x[12])     
{
	// neu cay rong
    if (t==NULL) printf("\nThong tin ve so dien thoai ban muon xoa khong co trong danh ba");
    else if (strcmp(t->data.sdt,x)>0)  xoanode(t->left, x);//duyet qua trai de  xoa chuoi x
    else if (strcmp(t->data.sdt,x)<0) xoanode(t->right, x);//duyet qua phai de xoa chuoi x
    else
    {   node *p = t;
        if (t->left == NULL) t = t->right;    // Node chi co cay con phai
        else if (t->right == NULL) t = t->left;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
           
            free(p);//giai phong bo nho cho cay
        }
        printf("\n Xoa thanh cong ");
    }
}
void xoanode_hoten(tree &t, char x[12])     
{
	// neu cay rong
    if (t==NULL) printf("\nThong tin ve so dien thoai ban muon xoa khong co trong danh ba");
    else if (strcmp(t->data.hoten,x)>0)  xoanode(t->left, x);//duyet qua trai de  xoa chuoi x
    else if (strcmp(t->data.hoten,x)<0) xoanode(t->right, x);//duyet qua phai de xoa chuoi x
    else
    {   node *p = t;
        if (t->left == NULL) t = t->right;    // Node chi co cay con phai
        else if (t->right == NULL) t = t->left;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
           // timphantuthe(p,t->right);
            free(p);
        }
        printf("\n Xoa thanh cong ");
    }
}
//tim kiem 1 node dua tren so dien thoai
void timtheosdt(tree &t,char x[12])   {
    	//xet cay rong
 	if(t==NULL) 
	 printf("\nThong tin ve sdt vua nhap khong co trong danh ba ");
	else{
		if(strcmp(t->data.sdt,x)>0)
		   timtheosdt(t->left,x);//duyet qua trai de tim chuoi x
		else{
		  if(strcmp(t->data.sdt,x)<0)
		   timtheosdt(t->right,x);//duyet qua phai de tim chuoi x
		   else {
		   	printf ( "\nThong tin ve sdt vua nhap co trong danh ba la : \n");
		   	xuatthongtin(t->data);//xuat du lieu danh ba
		   }
	    }
	}
}

//ham tim kiem theo ten
node *timtheoten(tree&t, char hoten[50]){
	//neu cay ton tai
	if (t!=NULL)
	{
        if(strcmp(t->data.hoten,hoten)==0)//so sanh chuoi ho ten
		{
	    	printf("\n Ten ban can tim co trong danh ba");
	    	xuatthongtin(t->data);
	    	return t;//tra ve node t da xuat
	    }
		else
		{ 
	      timtheoten(t->left, hoten);//duyet qua trai de tim chuoi hoten
	      timtheoten (t-> right, hoten);//duyet qua phai de tim chuoi ho ten
	    }
	}
    return NULL;
}

//câp nhât lai dia chi cua 1 khách khi thay doi dia chi
void capnhat(tree &t){
    char tencancapnhat[50];
	printf("\n Nhap vao ten nguoi can cap nhat lai quan he: ");
	fflush(stdin);
	gets(tencancapnhat);
	node*p=timtheoten(t,tencancapnhat);
	if (t)
	{
     	printf("\nNhap vao quan he can cap nhat :");
    	int quanhe;
    	scanf("%d",&quanhe);
    	p->data.quanhe=quanhe;//gan lai dia chi vao node
    	printf("\nDanh ba sau khi cap nhat la : ");
    	NLR(t);// xuat cay kieu NLR
	}
	else printf("\nTen khong ton tai");
}
//liet ke thong tin theo tung mien
//liet ke thong tin mien bac
void giadinh(tree t){
	if(t!=NULL){
		
		if(t->data.quanhe==1){
			xuatthongtin(t->data);
		}
		giadinh(t->left);
		giadinh(t->right);
	}
}
//liet ke thong tin mien trung
void banbe(tree t){
		if(t!=NULL){
		if(t->data.quanhe==2){
			xuatthongtin(t->data);
	    	}
	    	banbe(t->left);
	    	banbe(t->right);
	}
}
//liet ke thong tin mien nam
void dongnghiep(tree t){
		if(t!=NULL){
		if(t->data.quanhe==3){
			xuatthongtin(t->data);
		}
		dongnghiep(t->left);
		dongnghiep(t->right);
	}
}
//ham lay ra thong tin theo mien
void chonquanhe(tree t){
	int maqh;
	printf("\nChon ma quan he : ");
	scanf("%d",&maqh);
	
	
	if (maqh==1) 
	return giadinh(t);
	if (maqh==2) 
	return banbe(t);
	if (maqh==3)
	return dongnghiep(t);

}

int main()
{
tree t;
taocay(t);
nhapcay(t);
printf("\n _____DANH BA DIEN THOAI_____\n");
printf(" \n");
printf("MENU\n");
printf("Chon 1:Tao danh sach so dien thoai moi:\n");
printf("Chon 2:Them thong tin mot nguoi vao danh ba \n");
printf("Chon 3:Tim kiem thong tin mot nguoi theo ten\n");
printf("Chon 4:Tim kiem thong tin mot nguoi theo so dien thoai\n");
printf("Chon 5:Xoa thong tin mot nguoi theo so dien thoai\n");
printf("Chon 6:Xoa thong tin mot nguoi theo so dien thoai\n");
printf("Chon 7:Liet ke thong tin danh ba theo moi quan he\n");
printf("Chon 8:Cap nhat lai moi quan he theo ten\n");
printf("Chon 9:In ra toan bo thong tin danh ba\n");
printf("Chon 0:De thoat chuong trinh dang thuc hien. \n\n");
int chon;
do{
	printf("\n--------------------------------------\n");
	printf("\nChon thao tac ban muon thuc hien:\n");
	scanf("%d",&chon);
	switch(chon){
		case 1:{
		
			nhapcay(t);
			break;}
		case 2:{
			danhba x;
			printf("\nMoi ban nhap vao thong tin can them :");
			nhapthongtin(x);
			themnode(t,x);
			break;}
		case 3:{
			char y[50];
            fflush(stdin);
            printf("\n Nhap ten can tim : ");
            gets(y);
            node*k=timtheoten(t,y);//tao node de goi ham tim kiem thong tin
            if(k==NULL)
            printf("\nThong tin nguoi co ten vua nhap khong co trong danh ba");
            break;}
            
        case 4: {
            char x[12];
            fflush(stdin);
            printf("\nMoi ban nhap vao sdt can tim: ");
            gets(x);
            timtheosdt(t,x);//goi ham tim kiem thong tin theo sdt
            break;}
        case 5:      	 {
        	 char a[12];
            fflush(stdin);
            printf("\nMoi ban nhap vao sdt cua nguoi can xoa: ");
            gets(a);
            xoanode(t,a);
            break;}
        case 6:{
        	char a[12];
            fflush(stdin);
            printf("\nMoi ban nhap vao ho ten cua nguoi can xoa: ");
            gets(a);
            xoanode_hoten(t,a);
            break;
		}
        case 7:		    {
		    chonquanhe(t);
		    break;}
		case 8:{
			capnhat(t);
			break;}
		case 9:
			{
			form();//goi ham form tao bang cho danh ba
		   	NLR(t);
			break;}
	}
  }while(chon!=0);
getch();	
}

