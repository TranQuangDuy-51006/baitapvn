#include<stdio.h>
#include<string.h>

int main(){
	struct Dish{
		int id;
		char name[100];
		double price;
	};
	int choice;
	
	struct Dish menu[100] = {
		{1, "bun cha", 35},
		{2, "banh canh", 20},
		{3, "bun dau mam tom", 50},
		{4, "banh cuon", 15},
		{5, "banh mi", 10}
	};
	int stt= 0;
	int size = 5;
	int viTri;
	
	do{
		printf("\n--------MENU--------\n");
		printf("1. In ra menu.\n");
		printf("2. Them mon an vao menu.\n");
		printf("3. Sua mon an trong menu.\n");
		printf("4. Xoa mon an khoi menu.\n");
		printf("5. Sap xep menu theo gia tien.\n");
		printf("6. Tim kiem mon an trong menu.\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);
		fflush(stdin);
		stt = size;
		switch(choice){
			case 1:
				printf("\n");
				for(int i = 0; i < size; i++){
					printf("%d. ", menu[i].id);
					printf("%s: ", menu[i].name);
					printf("%.2lf\n", menu[i].price);
					if(stt < size){
						stt = size;
					}
				}

				break;
			case 2:
				if(stt < 100){
					printf("\n");
					menu[stt].id = stt + 1;
					printf("Nhap ten mon an: ");
					fgets(menu[stt].name, sizeof(menu[stt].name), stdin);
					menu[stt].name[strcspn(menu[stt].name,"\n")] = '\0';
					printf("Nhap gia tien mon an: ");
					scanf("%lf", &menu[stt].price);
					size++;	
				}else{
					printf("mang day!\n");
				}
				break;
			case 3:
				printf("\n");
				printf("Nhap vi tri muon sua: ");
				scanf("%d", &viTri);
				fflush(stdin);
				if(viTri > 0){
					printf("Nhap ten mon an: ");
					fgets(menu[viTri-1].name, sizeof(menu[viTri-1].name), stdin);
					menu[viTri-1].name[strcspn(menu[viTri-1].name,"\n")] = '\0';
					printf("Nhap gia tien mon an: ");
					scanf("%lf", &menu[viTri-1].price);
				}else{
					printf("loi vi tri!\n");
				}
				break;
			case 4:
				if(stt > 0){
					size--;
					printf("Da xoa\n");
				}else{
					printf("mang day!\n");
				}
				break;
			case 5:
				for(int i = size; i > 0; i--){
					for(int j = 0; j < i; j++){
						if(menu[j].price < menu[j+1].price){
							int doiID = menu[j].id;
							menu[j].id = menu[j+1].id;
							menu[j+1].id = doiID;
							
							char doiStr[100];
							strcpy(doiStr, menu[j].name);
							strcpy(menu[j].name, menu[j+1].name);
							strcpy(menu[j+1].name, doiStr);
							
							double doiPrice = menu[j].price;
							menu[j].price = menu[j+1].price;
							menu[j+1].price = doiPrice;
						}
					}
				}
				break;
			case 6:
				char search[100];
				printf("Nhap ten mon an: ");
				fgets(search, sizeof(search), stdin);
				search[strcspn(search,"\n")] = '\0';
				for(int i = 0; i < size; i++){
					if(strcmp(search, menu[i].name) == 0){
						printf("%d. ", menu[i].id);
						printf("%s: ", menu[i].name);
						printf("%.2lf\n", menu[i].price);
					}	
				}
				break;
			case 7:
				printf("Thoat!");
				break;
			default:
				printf("\nsai cu phap!\n");
		}
	}while(choice != 7);
	

	
	return 0;
}
