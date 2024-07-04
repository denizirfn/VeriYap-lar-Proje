#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct{
int takipNo;
char gonderici[100];
char alici[100];
char kargoDurum[100];
}Kargo;

Kargo * hash_tablo[10];

int hash1(int takipNo){
	return takipNo%10;
}

int hash2(int takipNo){
	return 7-(takipNo%7);
}
int hash3(int hash1,int deneme,int hash2){
	return (hash1+deneme*hash2)%10;
}


void ekle(Kargo*paket){
	int konum=hash1(paket->takipNo);
	
	
	if(hash_tablo[konum]==NULL){//tablo boþsa
		
		hash_tablo[konum]=paket;
		
	}
	else{//collision vardýr
		//int yeni_konum=hash2(paket-->takipNo);
		
		//while(1){
		  int deneme;
		  int son_konum;
			
			for(deneme=1;deneme<10;deneme++){
			  son_konum=hash3(hash1(paket->takipNo),deneme,hash2(paket->takipNo));
				
				if(hash_tablo[konum]==NULL){
	          hash_tablo[konum]=paket;
	          break;
		        }
		    else if(deneme==10){
		    	printf("tablo dolu");
		    	
				}
				    
				
			
			}
			
		//}
		
	}}

 
Kargo  * kargo_girisi(int takipNo, char * gonderici,char * alici,char * kargoDurum){
	Kargo*paket=(Kargo*)malloc(sizeof(Kargo));
	paket->takipNo=takipNo;
	strcpy(paket->gonderici, gonderici);
  strcpy(paket->alici, alici);
  strcpy(paket->kargoDurum, kargoDurum);
  return paket;
	
}
void kargo_takip(int TakipNo){
	
	for(int i=0;i<10;i++){
		if(hash_tablo[i]->takipNo==TakipNo){
			printf("%d adýmda bulundu.",i+1);
			printf("gonderici:%s ,alici:%s,kargo durumu:%s",hash_tablo[i]->gonderici,hash_tablo[i]->alici,hash_tablo[i]->kargoDurum);
		break;
		}
	}
	printf("kargo bulunamadý");
}	
	
	
	
	

void dosyaOku(){
	FILE*dosya=fopen("verim.txt","r");
	if(dosya==NULL){//dosya yoksa
		printf("dosya bulunamadi");
		
	}
	while(!feof(dosya)){//dosyanýn sonuna kadar
		Kargo*paket=(Kargo*)malloc(sizeof(Kargo));
		fscanf(dosya,"%d %s %s %s",&paket->takipNo,paket->gonderici,paket->alici,paket->kargoDurum);
		ekle(paket);
	}
  
  
	fclose(dosya);
	
}


void kargo_sil(int takipNo)
{
	
	for(int i=0;i<10;i++){
	
		if(hash_tablo[i]->takipNo==takipNo)	{
			free(hash_tablo[i]);
			hash_tablo[i]=NULL;
			printf("kargo teslim edildi\n");
		
			return;
		}
	}
	
		printf("kargo bulunamadi");
	
	
}





int main() {
	
	int secim,no;
	char gonderici[100],alici[100],kargoDurum[100];
	Kargo *yeniPaket;
	
	
	
	do {
		printf("\n0-Textten Veri Girisi Yap\n1-Tum Kargolari Listele\n2-Kargo Girisi\n3-Kargo Takip\n4-Kargoyu Teslim Et\n5-Cikis\n");
    printf("lutfen yapmak istediginiz islemi seciniz:\n");
		scanf("%d", &secim);
		
		switch(secim){
		case 0:
			dosyaOku();
			printf("dosyadan veri girisi yapildi\n");
			
		break;
		
		case 1:
			for (int i = 0; i < 10; i++) {
	        if (hash_tablo[i] != NULL) {
	          printf("Index %d - Takip No: %d,\tGonderici: %s,\tAlici: %s,\tDurum: %s\n", i, hash_tablo[i]->takipNo, hash_tablo[i]->gonderici, hash_tablo[i]->alici, hash_tablo[i]->kargoDurum);
	        }
    		}
		break;
		
	case 2:
			printf("Eklenecek kargonun takip numarasini girin: ");
      scanf("%d", &no);
      printf("Eklenecek kargonun gondericisini girin: ");
      scanf("%s", gonderici);
      printf("Eklenecek kargonun alicisini girin: ");
      scanf("%s", alici);
      printf("Eklenecek kargonun durum bilgisini girin: ");
      scanf("%s", kargoDurum);
            
      yeniPaket = kargo_girisi(no, gonderici, alici, kargoDurum);
   		ekle(yeniPaket);            
		break;
	case 3:
		  printf("lutfen kargo takibi yapilacak numarayi giriniz:");
		  scanf("%d",&no);
		  kargo_takip(no);
		
		
		
	case 4:
			printf("teslim edilecek kargo numarasini  giriniz:");
			scanf("%d",&no);
			kargo_sil(no);
		break;
		
	case 5:
      exit(0);
    break;        
        
	}
	}while(secim!=6);
	       
    return 0;
}
