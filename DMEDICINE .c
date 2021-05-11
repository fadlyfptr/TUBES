/* DESC 1 : judul 2 : D Medicine
Deskripsi : Program untuk pembelian obat secara online terdiri dari akun admin dan member. 
Akun member dapat melihat list obat berdasarkan jenis penyakitnya. 
Pembelian obat bisa dilakukan pada menu pembelian yang berisikan 
(Nama, Alamat, NO. HP, dan Metode pembayaran (COD/TF), Nama obat). 
Akun admin bisa menambah list obat, mengupdate data obat (nama, kategori/jenis penyakit, dosis, harga ),
menghapus data obat yg ada, mencari akun member untuk diupdate datanya(username,password,nama,alamat,no HP), dan dapat mengganti no rek bank. 

fitur : 
- Registrasi dan login.
- Member : ada 3 menu (beli obat bisa COD atau dari bank, logout).
- Admin : ada (tambah obat, update no rek bank, hapus obat, update obat, log out, update akun member).
*/

/*DESC 2 : Deskripsi : Program untuk pembelian obat secara online terdiri dari akun admin dan member. 
Sebelum dapat membeli obat, pembeli diharuskan untuk registrasi akun member yang terdiri dari username, password, nama, alamat, dan No HP. 
kemudian login menggunakan username dan password yang telah dibuat. Akun MEMBER hanya memiliki fitur unutk membeli obat. 
Alur pembelian obat dimulai dengan menampilkan list obat berdasarkan kategori penyakitnya (Contoh : DEMAM, PERNAPASAN, DLL) dengan batasan minimal 3 kategori penyakit.
Setelah memilih kategori penyakit, daftar obat yang tersedia akan ditampilkan secara terurut berdasarkan nama obat (ascending). 
Kemudian akun member dapat memilih obat yang tersedia untuk dibeli. 
Setelah memilih obat tertentu yang ingin dibeli, pembeli akan memilih metode pembayaran salah satu dari 2 metode pembayaran (COD/Transfer Bank). 
Pemilihan metode pembayaran secara COD hanya akan menampilkan pemberitahuan bahwa obat akan segera dikirim. 
Pemilihan metode pembayaran secara Transfer Bank akan menampilkan suatu NO Rekening virtual account dengan format KODE + NO HP PEMBELI 
(Contoh => Kode : 1337; NO HP : 0812111122223333; NO REKENING : 13370812111122223333).  
Akun ADMIN memiliki 7 fitur yaitu menambah data obat (NAMA OBAT, KATEGORI PENYAKIT, DOSIS (mg), HARGA), 
mengupdate informasi obat, menghapus data obat, mengupdate kode virtual account, mengupdate akun member, menghapus akun member, dan logout.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void title(){
	printf("                =======================================================================\n\
	        DDDDDD   MM    MM  EEEEEEE  DDDDDD   II  CCCCCC  II  NNN    NN  EEEEEEE      \n\
                DD   DD  MMM  MMM  EE       DD   DD  II  CC      II  NNNN   NN  EE       \n\
                DD   DD  MMMMMMMM  EEEEEE   DD   DD  II  CC      II  NN NN  NN  EEEEEE   \n\
                DD   DD  MM MM MM  EEEEEE   DD   DD  II  CC      II  NN  NN NN  EEEEEE   \n\
                DD   DD  MM    MM  EE       DD   DD  II  CC      II  NN   NNNN  EE       \n\
                DDDDDD   MM    MM  EEEEEEE  DDDDDD   II  CCCCCC  II  NN    NNN  EEEEEEE  \n\
		=======================================================================\n\n");
}
void login();
//Khusus Admin
void admin(); 
void menuAdmin();
		void loginAdmin(); //Udah
        void tambahObat();//Udah
        void hapusakun(); //udah
        void updatenorekbank(); //udah
        void hapusobat(); //udah
        void updateobat(); //udah
        void updateakunmember(); //Udah
//Khusus pembeli
void member();
    void loginMember(); //Aman
    void regist(); //Aman
    void menuPembeli(); //Aman
        void beliObat(); 
FILE *PEMBELI, *PEMBELI2,*OBAT, *OBAT2, *ADMIN;
struct{
    char uname[50],pass[50],obat[50],metodepembelian[50],nama[50],alamat[50],noHP[50];
}registPembeli,loginPembeli;
struct{
    char nama[50],jenisObat[50];
    int harga, dosis;
}listObat,sortObat[100],tempObat;
struct{
    char noRek[10];
}adm;
int login3x=3;
void main(){
    int pil;
    login3x=3;
    system("cls");
    title();
    printf("1. Admin\n2. Member\n3. Exit\nPilih : "); scanf("%d",&pil); getchar();
    switch(pil){
        case 1: system("cls"); admin();  break;
        case 2 : system("cls"); member();  break;
        case 3 : exit(0); break;
        default: printf("SALAH INPUT"); main();
    }
}
void admin(){
    int pil;
    system("cls");
    title();
    printf("1. Login\n2. Kembali\nPilih : "); scanf("%d",&pil); getchar();
    switch(pil){
        case 1: system("cls"); loginAdmin();  break;
        case 2 : main(); break;
        default: printf("SALAH INPUT"); main();
    }
}
void loginAdmin(){
    system("cls");
    title();
    char usr[99], pas[99];
    printf("LOGIN\n");
    printf("USERNAME : "); fgets(usr,sizeof(usr),stdin); usr[strcspn(usr,"\r\n")]=0;
    printf("PASSWORD : "); fgets(pas,sizeof(pas),stdin); pas[strcspn(pas,"\r\n")]=0;
    if(strcmp(usr,"ADMIN")==0 && strcmp(pas,"ADMIN")==0 && login3x>=1){
        system("cls");
        title();
        printf("LOGIN ADMIN SUKSES\n");
        system("pause"); 
        menuAdmin();
    }else if(login3x==0){
        printf("KESEMPATAN LOGIN HABIS\n");
        system("pause");
        main();
    } else{
        printf("LOGIN GAGAL\n");
        printf("KESEMPATAN LOGIN %d kali lagi\n",login3x);
        login3x--;
        system("pause");
        loginAdmin();
    }
}
void menuAdmin(){
    system("cls");
    title();
    login3x=3;
    int pil2;
    printf("==Menu Admin==\n");
    printf("1. Tambah obat\n2. Update No Rek Bank\n3. Hapus Obat\n4. Update Obat\n5. Update Akun Member\n6. Hapus akun member\n7. Logout\n");
    printf("Pilihan : "); scanf("%d",&pil2); getchar();
    switch(pil2){
        case 1 : system("cls"); tambahObat(); break;
        case 2 : system("cls"); updatenorekbank(); break;
        case 3 : system("cls"); hapusobat(); break;
        case 4 : system("cls"); updateobat(); break;
        case 5 : system("cls"); updateakunmember(); break;
        case 6 : system("cls"); hapusakun();break;
        case 7 : system("cls"); main(); break;
        default : printf("Pilihan tidak ada ..... \n");  menuAdmin();
    }
    
}
void tambahObat(){
    int n,i;
    system("cls");
    title();
    printf("\t\t\t\t\t==TAMBAH OBAT==\n");
    printf("Banyak obat yang ditambahkan : "); scanf("%d",&n); getchar();
    OBAT=fopen("obat.dat","ab");
    for(i=1;i<=n;i++){
    printf("%d. Nama obat : ",i);    fgets(listObat.nama,sizeof(listObat.nama),stdin); listObat.nama[strcspn(listObat.nama,"\r\n")]=0;
    printf("   Kategori  : ");    fgets(listObat.jenisObat,sizeof(listObat.jenisObat),stdin); listObat.jenisObat[strcspn(listObat.jenisObat,"\r\n")]=0;
    printf("   Dosis (mg): ");    scanf("%d",&listObat.dosis);
    printf("   Harga     : ");    scanf("%d",&listObat.harga); getchar();
        fwrite(&listObat,sizeof(listObat),1,OBAT); 
    }
    fclose(OBAT);
    system("pause");
    menuAdmin();
}

void updateobat(){
    int n,i=0;
    char cari[50];
    system("cls");
    title();
    printf("==Menu Update OBAT==\n");
    OBAT=fopen("obat.dat","rb");
    OBAT2=fopen("obat2.dat","wb");
    printf("LIST OBAT :\n");
    while(fread(&listObat,sizeof (listObat),1,OBAT)==1){
		printf("%d. Nama Obat : %s \n", i+1, listObat.nama);
        printf("   Kategori  : %s \n", listObat.jenisObat);
        printf("   Dosis     : %d mg \n", listObat.dosis);
        printf("   Harga     : %d \n\n", listObat.harga);
        i++;
		}
    rewind(OBAT);
    printf("Obat yang ingin diupdate : "); fgets(cari,sizeof(cari),stdin); cari[strcspn(cari,"\r\n")]=0;
    int obatditemukan=0;
    while (fread(&listObat,sizeof (listObat),1,OBAT)==1){
        if(strcmp(cari,listObat.nama)==0){
            obatditemukan=1;
            printf("Obat ditemukan!\n");
            printf("Nama Obat : %s \n", listObat.nama);
            printf("Kategori  : %s \n", listObat.jenisObat);
            printf("Dosis     : %d mg \n", listObat.dosis);
            printf("Harga     : %d \n\n", listObat.harga);
            break;
		}
	}
    if(obatditemukan==0){
        printf("Obat tidak ditemukan!\n");
        fclose(OBAT);
        fclose(OBAT2);
        getchar();
        system("cls");
        menuAdmin();
    }
    else {
        rewind(OBAT);
        while (fread(&listObat,sizeof (listObat),1,OBAT)==1){
            if(strcmp(cari,listObat.nama)==0){
                printf("Update Obat Menjadi :\n");
                printf("Nama obat : ");    fgets(listObat.nama,sizeof(listObat.nama),stdin); listObat.nama[strcspn(listObat.nama,"\r\n")]=0;
                printf("Kategori  : ");    fgets(listObat.jenisObat,sizeof(listObat.jenisObat),stdin); listObat.jenisObat[strcspn(listObat.jenisObat,"\r\n")]=0;
                printf("Dosis     : ");    scanf("%d",&listObat.dosis);
                printf("Harga     : ");    scanf("%d",&listObat.harga); getchar();
                fwrite(&listObat,sizeof(listObat),1,OBAT2); 
                printf("Obat berhasil diupdate!\n");
            } else {
                fwrite(&listObat,sizeof(listObat),1,OBAT2); 
            }
        }
	}
	fclose(OBAT);
    fclose(OBAT2);
    remove("obat.dat");
    rename("obat2.dat","obat.dat");
    system("pause");
    menuAdmin();
}

void hapusobat(){
    system("cls");
    title();
    char cari[50];
    int i=0,indikator=0;
    OBAT=fopen("obat.dat","rb");
    OBAT2=fopen("obat2.dat","wb");
    printf("DAFTAR OBAT : \n");
    while (fread(&listObat,sizeof (listObat),1,OBAT)==1){
		printf("%d. Nama Obat : %s \n", i+1,listObat.nama);
        printf("   Kategori  : %s \n", listObat.jenisObat);
        printf("   Dosis     : %d mg \n", listObat.dosis);
        printf("   Harga     : %d \n\n", listObat.harga);
        i++;
		}
    rewind(OBAT);
    printf("Obat yang ingin dihapus : "); fgets(cari,sizeof(cari),stdin); cari[strcspn(cari,"\r\n")]=0;
    while(fread(&listObat,sizeof(listObat),1,OBAT)==1){
        if(strcmp(listObat.nama,cari)!=0){
            fwrite(&listObat,sizeof(listObat),1,OBAT2);
        }
        if(strcmp(listObat.nama,cari)==0){
        	indikator=1;
		}
    }
    fclose(OBAT);
    fclose(OBAT2);
    remove("obat.dat");
    rename("obat2.dat","obat.dat");
    if(indikator==1) printf("Obat Berhasil Dihapus!\n");
    else printf("Obat tidak ditemukan\n");
    system("pause");
    menuAdmin();
}
    

void updatenorekbank(){
    char pil;
    system("cls");
    title();
    printf("==UPDATE NO REK===\n");
    ADMIN=fopen("admin.dat","rb");
    if(ADMIN!=NULL){
        rewind(ADMIN);
        while(fread(&adm, sizeof(adm), 1, ADMIN) == 1) {
            printf("Rekening Saat ini : %s \n", adm.noRek);
        }
        fclose(ADMIN);
        printf("Apakah ingin mengubah norek saat ini? (Y/n)"); scanf("%c",&pil); getchar();
        if(pil=='y' || pil=='Y') {
            printf("Input no rek baru: "); fgets(adm.noRek, sizeof(adm.noRek), stdin); adm.noRek[strcspn(adm.noRek, "\r\n")] = 0;
            ADMIN=fopen("admin.dat","wb");
            fwrite(&adm, sizeof(adm), 1, ADMIN);
            fclose(ADMIN);
            printf("No. Rekening berhasil diubah ... \n");
            system("pause");
            menuAdmin();
        }
        else {
            printf("PERUBAHAN NO REKENING DIBATALKAN\n");
            system("pause");
            menuAdmin();
        }
    }else {
        printf("Input no rek baru : "); 
        fgets(adm.noRek,sizeof(adm.noRek),stdin); adm.noRek[strcspn(adm.noRek, "\r\n")] = 0;
        ADMIN=fopen("admin.dat","wb");
        fwrite(&adm,sizeof(adm),1,ADMIN); 
        fclose(ADMIN);
        printf("No. Rekening berhasil diinput ... \n");
        system("pause");
        menuAdmin();
    }
    
}
void hapusakun(){
    system("cls");
    title();
    char cari[99];
    int i=1, indikator=0;
    PEMBELI=fopen("akunpembeli.dat","rb");
    PEMBELI2=fopen("akunpembeli2.dat","wb");
    printf("DAFTAR AKUN PEMBELI : \n");
    while(fread(&registPembeli,sizeof(registPembeli),1,PEMBELI)==1){
        printf("%d. USERNAME : %s\n",i,registPembeli.uname);
        printf("   PASSWORD : %s\n",registPembeli.pass);
        i++;
    }
    rewind(PEMBELI);
    printf("input USERNAME akun yang ingin dihapus : "); fgets(cari,sizeof(cari),stdin); cari[strcspn(cari,"\r\n")]=0;
	while(fread(&registPembeli,sizeof(registPembeli),1,PEMBELI)==1){
        if(strcmp(registPembeli.uname,cari)!=0){
            fwrite(&registPembeli,sizeof(registPembeli),1,PEMBELI2);
        }
        if(strcmp(registPembeli.uname,cari)==0){
        	indikator=1;
		}
    }
    fclose(PEMBELI);
    fclose(PEMBELI2);
    remove("akunpembeli.dat");
    rename("akunpembeli2.dat","akunpembeli.dat");
    if (indikator==1){
    	printf("Akun berhasil dihapus\n");
	}
	else printf("Akun tidak ditemukan\n");
    system("pause");
    menuAdmin();
}
void updateakunmember(){
    system("cls");
    title();
    char username[99],password[99],nama[99],alamat[99],noHP[99],cari[99];
    int i=1,found=0;
    printf("UPDATE AKUN MEMBER\n");
    PEMBELI=fopen("akunpembeli.dat","rb");
    PEMBELI2=fopen("akunpembeli2.dat","wb");
    while(fread(&registPembeli,sizeof(registPembeli),1,PEMBELI)==1){
            printf("%d. Username : %s\n",i,registPembeli.uname);
            printf("    Password : %s\n",registPembeli.pass);
            printf("    Nama : %s\n",registPembeli.nama);
            printf("    Alamat : %s\n",registPembeli.alamat);
            printf("    No HP : %s\n",registPembeli.noHP);
            i++;
    }
    rewind(PEMBELI);
    printf("username akun yang ingin diupdate : "); fgets(cari,sizeof(cari),stdin); cari[strcspn(cari,"\r\n")]=0;
    while(fread(&registPembeli,sizeof(registPembeli),1,PEMBELI)==1){
        if(strcmp(registPembeli.uname,cari)==0){
            found=1;
            printf("Username : %s\n",registPembeli.uname);
            printf("Password : %s\n",registPembeli.pass);
            printf("Nama : %s\n",registPembeli.nama);
            printf("Alamat : %s\n",registPembeli.alamat);
            printf("No HP : %s\n",registPembeli.noHP);
            break;
        }
    }
    rewind(PEMBELI);
    if(found=0){
        printf("DATA TIDAK DITEMUKAN\n");
        system("pause");
        fclose(PEMBELI);
        fclose(PEMBELI2);
        menuAdmin();
    } else{
        printf("DIGANTI DENGAN : \n");
        printf("Username : "); fgets(username,sizeof(username),stdin); username[strcspn(username,"\r\n")]=0;
        printf("Password : "); fgets(password,sizeof(password),stdin); password[strcspn(password,"\r\n")]=0;
        printf("Nama : "); fgets(nama,sizeof(nama),stdin); nama[strcspn(nama,"\r\n")]=0;
        printf("Alamat : "); fgets(alamat,sizeof(alamat),stdin); alamat[strcspn(alamat,"\r\n")]=0; 
        printf("No HP : "); fgets(noHP,sizeof(noHP),stdin); noHP[strcspn(noHP,"\r\n")]=0;
        while(fread(&registPembeli,sizeof(registPembeli),1,PEMBELI)==1){
            if(strcmp(registPembeli.uname,cari)==0){
                strcpy(registPembeli.uname,username);
                strcpy(registPembeli.pass,password);
                strcpy(registPembeli.nama,nama);
                strcpy(registPembeli.alamat,alamat);
                strcpy(registPembeli.noHP,noHP);
                fwrite(&registPembeli,sizeof(registPembeli),1,PEMBELI2);
                printf("UPDATED\n");
            } else{
                fwrite(&registPembeli,sizeof(registPembeli),1,PEMBELI2);
            }
        }
    }
    fclose(PEMBELI);
    fclose(PEMBELI2);
    remove("akunpembeli.dat");
    rename("akunpembeli2.dat","akunpembeli.dat");
    system("pause");
    menuAdmin();
}
//Atas bagian admin, Bawah bagian member
void member(){
    int pil;
    login3x=3;
    system("cls");
    title();
    printf("1. Registrasi\n2. Login\n3. kembali\nPilih : "); scanf("%d",&pil); getchar();
    switch(pil){
        case 1: system("cls"); regist();  break;
        case 2 : system("cls"); loginMember();  break;
        case 3 : main(); break;
        default: printf("SALAH INPUT"); main();
    }
}
void regist(){
    system("cls");
    title();
    printf("REGISTRASI PEMBELI\n");
    PEMBELI=fopen("akunpembeli.dat","ab");
    printf("USERNAME : "); fgets(registPembeli.uname,sizeof(registPembeli.uname),stdin); registPembeli.uname[strcspn(registPembeli.uname,"\r\n")]=0;
    printf("PASSWORD : "); fgets(registPembeli.pass,sizeof(registPembeli.pass),stdin); registPembeli.pass[strcspn(registPembeli.pass,"\r\n")]=0;
    printf("Nama\t: "); fgets(registPembeli.nama,sizeof(registPembeli.nama),stdin); registPembeli.nama[strcspn(registPembeli.nama,"\r\n")]=0;
    printf("Alamat\t: "); fgets(registPembeli.alamat,sizeof(registPembeli.alamat),stdin); registPembeli.alamat[strcspn(registPembeli.alamat,"\r\n")]=0;
    printf("No HP\t: "); fgets(registPembeli.noHP,sizeof(registPembeli.noHP),stdin); registPembeli.noHP[strcspn(registPembeli.noHP,"\r\n")]=0;
    strcpy(registPembeli.metodepembelian,"-");
    fwrite(&registPembeli,sizeof(registPembeli),1,PEMBELI); 
    printf("REGISTRASI BERHASIL\n"); 
    fclose(PEMBELI);
    system("pause");
    member(); 
}
void loginMember(){
    system("cls");
    title();
    printf("USERNAME : "); fgets(loginPembeli.uname,sizeof(loginPembeli.uname),stdin); loginPembeli.uname[strcspn(loginPembeli.uname,"\r\n")]=0;
    printf("PASSWORD : "); fgets(loginPembeli.pass,sizeof(loginPembeli.pass),stdin); loginPembeli.pass[strcspn(loginPembeli.pass,"\r\n")]=0;
    PEMBELI=fopen("akunpembeli.dat","rb");
    while(fread(&registPembeli,sizeof(registPembeli),1,PEMBELI)==1){
    if(strcmp(loginPembeli.uname,registPembeli.uname)==0 && strcmp(loginPembeli.pass,registPembeli.pass)==0){
        printf("LOGIN BERHASIL\n");
        system("pause");
        fclose(PEMBELI);
        menuPembeli();
        }
    }
        if(login3x==0){
            printf("KESEMPATAN LOGIN TELAH BERAKHIR\n");
            fclose(PEMBELI);
            system("pause");
            member();
        } else{
            printf("LOGIN GAGAL\nKESEMPATAN LOGIN %d KALI LAGI\n",login3x);
            login3x--;
            system("pause");
            loginMember();
        }
        fclose(PEMBELI); 
}
void menuPembeli(){
    login3x=3;
    system("cls");
    title();
    int pil2;
    printf("==Menu Pembeli==\n");
    printf("1. Beli Obat\n2. Log Out\n");
    printf("Pilihan : "); scanf("%d",&pil2); getchar();
    switch(pil2){
        case 1 : system("cls"); beliObat(); break;
        case 2 : system("cls"); main(); break;
        default : printf("Pilihan tidak ada ..... ");  menuPembeli();
    }    
}  
void beliObat(){
    char jPenyakit[99], pilObat[99], pilihan, hp[15];
    int pilihan2,hargaobat,found=0,found2=-1,i=0,n,j;
    OBAT=fopen("obat.dat","rb");
    system("cls");
    title();
    printf("==Jenis Penyakit==\n");
    printf("1. DEMAM\n2. SAKIT KEPALA\n3, BATUK\n4. PILEK\n5. LAMBUNG\n");
    printf("Pilih jenis penyakit (KAPITAL) : "); fgets(jPenyakit,sizeof(jPenyakit),stdin); jPenyakit[strcspn(jPenyakit,"\r\n")]=0;
    if(fread(&listObat,sizeof(listObat),1,OBAT)!=1){
        printf("Belum ada data.\n"); 
        fclose(OBAT); 
        system("pause");
    } else{
    	rewind(OBAT);
        while(fread(&listObat,sizeof(listObat),1,OBAT)==1){
            if(strcmp(jPenyakit,listObat.jenisObat)==0){
            	found=1;
                sortObat[i].dosis=listObat.dosis;
                strcpy(sortObat[i].jenisObat,listObat.jenisObat);
                strcpy(sortObat[i].nama,listObat.nama);
                sortObat[i].harga=listObat.harga;
                i++;
                n=i;
            }
        }
        if(found==0){
        	printf("Jenis penyakit tidak ditemukan\n");
        	fclose(OBAT);
        	system("pause");
        	menuPembeli();
		} else{
        	fclose(OBAT);
        	printf("Sorting berdasarkan : \n");
        	printf("1. Nama Obat Ascending\n2. Nama Obat Descending\n3. Dosis Obat Ascending\n4. Dosis Obat Descending\n5. Harga Obat Ascending\n6. Harga Obat Descending\n");
        	printf("Pilihan : "); scanf("%d",&pilihan2); getchar();
        	switch(pilihan2){
        		case 1 :
        			for(i=0;i<n-1;i++){
        				for(j=0;j<n-1-i;j++){
        					if(strcmp(sortObat[j].nama,sortObat[j+1].nama)>0){
							tempObat=sortObat[j];
        					sortObat[j]=sortObat[j+1];
        					sortObat[j+1]=tempObat;
        					}
						}
					}
					for(i=0;i<n;i++){
						printf("%d. Nama Obat \t: %s\n",i+1,sortObat[i].nama);
						printf("    Jenis Obat \t: %s\n",sortObat[i].jenisObat);
						printf("    Dosis Obat \t: %d mg\n",sortObat[i].dosis);
						printf("    Harga Obat \t: %d\n",sortObat[i].harga);
					}
					break;
				case 2 :
					for(i=0;i<n-1;i++){
        				for(j=0;j<n-1-i;j++){
        					if(strcmp(sortObat[j].nama,sortObat[j+1].nama)<0){
							tempObat=sortObat[j];
        					sortObat[j]=sortObat[j+1];
        					sortObat[j+1]=tempObat;
        					}
						}
					}
					for(i=0;i<n;i++){
						printf("%d. Nama Obat \t: %s\n",i+1,sortObat[i].nama);
						printf("    Jenis Obat \t: %s\n",sortObat[i].jenisObat);
						printf("    Dosis Obat \t: %d mg\n",sortObat[i].dosis);
						printf("    Harga Obat \t: %d\n",sortObat[i].harga);
					}
					break;
				case 3 :
					for(i=0;i<n-1;i++){
        				for(j=0;j<n-1-i;j++){
        					if(sortObat[j].dosis>sortObat[j+1].dosis){
							tempObat=sortObat[j];
        					sortObat[j]=sortObat[j+1];
        					sortObat[j+1]=tempObat;
        					}
						}
					}
					for(i=0;i<n;i++){
						printf("%d. Nama Obat \t: %s\n",i+1,sortObat[i].nama);
						printf("    Jenis Obat \t: %s\n",sortObat[i].jenisObat);
						printf("    Dosis Obat \t: %d mg\n",sortObat[i].dosis);
						printf("    Harga Obat \t: %d\n",sortObat[i].harga);
					}
					break;
				case 4 :
					for(i=0;i<n-1;i++){
        				for(j=0;j<n-1-i;j++){
        					if(sortObat[j].dosis<sortObat[j+1].dosis){
							tempObat=sortObat[j];
        					sortObat[j]=sortObat[j+1];
        					sortObat[j+1]=tempObat;
        					}
						}
					}
					for(i=0;i<n;i++){
						printf("%d. Nama Obat \t: %s\n",i+1,sortObat[i].nama);
						printf("    Jenis Obat \t: %s\n",sortObat[i].jenisObat);
						printf("    Dosis Obat \t: %d mg\n",sortObat[i].dosis);
						printf("    Harga Obat \t: %d\n",sortObat[i].harga);
					}
					break;
				case 5 :
					for(i=0;i<n-1;i++){
        				for(j=0;j<n-1-i;j++){
        					if(sortObat[j].harga>sortObat[j+1].harga){
							tempObat=sortObat[j];
        					sortObat[j]=sortObat[j+1];
        					sortObat[j+1]=tempObat;
        					}
						}
					}
					for(i=0;i<n;i++){
						printf("%d. Nama Obat \t: %s\n",i+1,sortObat[i].nama);
						printf("    Jenis Obat \t: %s\n",sortObat[i].jenisObat);
						printf("    Dosis Obat \t: %d mg\n",sortObat[i].dosis);
						printf("    Harga Obat \t: %d\n",sortObat[i].harga);
					}
					break;
				case 6 : 
					for(i=0;i<n-1;i++){
        				for(j=0;j<n-1-i;j++){
        					if(sortObat[j].harga<sortObat[j+1].harga){
							tempObat=sortObat[j];
        					sortObat[j]=sortObat[j+1];
        					sortObat[j+1]=tempObat;
        					}
						}
					}
					for(i=0;i<n;i++){
						printf("%d. Nama Obat \t: %s\n",i+1,sortObat[i].nama);
						printf("    Jenis Obat \t: %s\n",sortObat[i].jenisObat);
						printf("    Dosis Obat \t: %d mg\n",sortObat[i].dosis);
						printf("    Harga Obat \t: %d\n",sortObat[i].harga);
					}
					break;
				default : printf("SALAH INPUT\n"); system("pause"); fclose(OBAT); menuPembeli();		
			}
            rewind(OBAT);
        	printf("Pilih nama obat (KAPITAL) : "); fgets(pilObat,sizeof(pilObat),stdin); pilObat[strcspn(pilObat,"\r\n")]=0;
        	OBAT=fopen("obat.dat","rb");
        	if(fread(&listObat,sizeof(listObat),1,OBAT)!=1){
            	printf("Belum ada data.\n"); 
            	fclose(OBAT); 
            	system("pause");
        	} else{
                rewind(OBAT);
            	while(fread(&listObat,sizeof(listObat),1,OBAT)==1){
                	if(strcmp(pilObat,listObat.nama)==0){
                		found2=0;
                    	printf("Nama  Obat : %s\n",listObat.nama);
                    	printf("jenis Obat : %s\n",listObat.jenisObat);
                    	printf("Dosis Obat : %d mg\n",listObat.dosis);
                    	printf("Harga Obat : %d\n",listObat.harga); 
                    	hargaobat=listObat.harga;
                    	break;
                	}
            	}
            	if(found2==-1){
            		printf("Obat tidak ditemukan\n");
            		system("pause");
            		fclose(OBAT);
            		menuPembeli();
				}
            	fclose(OBAT);
            	printf("Apakah anda akan membeli obat ini ? (Y/N) : "); scanf("%c",&pilihan); getchar();
            	if(pilihan=='y' || pilihan=='Y'){
                	printf("Pilihan Metode Pembayaran :\n1. COD\n2. Transfer Bank \n3. Batal\nPilihan : ");
                	scanf("%d",&pilihan2); getchar();
                	switch(pilihan2){
                    	case 1 : printf("SELAMAT PEMEBELIAN ANDA SEDANG KAMI PROSES. DETAIL PEMBELIAN : \n");
                            	PEMBELI=fopen("akunpembeli.dat","rb"); 
                            	while(fread(&registPembeli,sizeof(registPembeli),1,PEMBELI)==1){
                                	if(strcmp(loginPembeli.uname, registPembeli.uname)==0){
                                	printf("Nama pembeli : %s\n", registPembeli.nama);
                                	printf("Alamat pembeli : %s\n", registPembeli.alamat);
                                	printf("No HP pembeli : %s\n", registPembeli.noHP);
                                	printf("Nama pembeli : %s\n", registPembeli.nama);
                                	break;
                                	}
                            	}
                            	fclose(PEMBELI);
                            	OBAT=fopen("obat.dat","rb");  
                            	while(fread(&listObat,sizeof(listObat),1,OBAT)==1){
                                    	if(strcmp(pilObat,listObat.nama)==0){
                                    	printf("Nama  Obat : %s\n",listObat.nama);
                                    	printf("jenis Obat : %s\n",listObat.jenisObat);
                                    	printf("Dosis Obat : %d mg\n",listObat.dosis);
                                    	printf("Harga Obat : %d\n",listObat.harga); 
                                    	break;
                                    	}
                            	}
                            	fclose(OBAT);
                            	printf("SILAHKAN MENUNGGU BARANG DATANG KE RUMAH ANDA. TERIMAKASIH TELAH BERBELANJA\nSEMOGA LEKAS SEMBUH\n");
                            	system("pause"); menuPembeli();
                            	break;
                    	case 2 : printf("SILAHKAN MELAKUKAN PEMBAYARAN MELALUI VIRTUAL ACCOUNT BERIKUT : "); 
                            	PEMBELI=fopen("akunpembeli.dat","rb"); 
                            	while(fread(&registPembeli,sizeof(registPembeli),1,PEMBELI)==1){
                                	if(strcmp(loginPembeli.uname, registPembeli.uname)==0){
                                	strcpy(hp,registPembeli.noHP);
                                	break;
                                	}
                            	}
                            	fclose(PEMBELI);
                            	ADMIN = fopen("admin.dat","rb");
                            	fread(&adm, sizeof(adm), 1, ADMIN);
                            	printf("%s + HP\n", adm.noRek);
                            	printf("NO REK\t: %s%s\n",adm.noRek,hp);
                            	printf("NOMINAL\t: %d\n",hargaobat); 
                            	printf("PENGIRIMAN AKAN DIPROSES SETELAH PROSES PEMBAYARAN KAMI TERIMA. TERIMAKASIH"); 
                            	system("pause"); menuPembeli(); break;
                    	case 3 : printf("Proses pembelian telah dibatalkan.\n"); system("pause"); menuPembeli(); break;
                    	default : printf("INPUTAN TIDAK SESUAI. SILAHKAN ULANGI PROSES PEMBELIAN"); menuPembeli();  break;
                	}
            	} else if(pilihan=='n'|| pilihan=='N'){
                    printf("PEMBELIAN DIBATALKAN\n");
                    system("pause");
                    menuPembeli();
                }else {
                    printf("Inputan Salah\n");
                    system("pause");
                    beliObat(); 
                }
        	}
        }
    } 
}

