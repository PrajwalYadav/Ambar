//Hash Table

# include <stdio.h>

struct pair{
  int key, value;
};

void display(struct pair arr[], int size);

int main(){
  int size, i, temp;
  printf("Enter the size of table: ");
  scanf("%d", &size);
  struct pair hash_table[size];
  printf("Enter the elements: ");
  for(int i = 0; i < size; i++){
    scanf("%d", &temp);
    hash_table[temp % size].value = temp;
    hash_table[temp % size].key = temp%size;
  }
  printf("\n");
  display(hash_table, size);
}

void display(struct pair arr[], int size){
  int i;
  printf("key\tvalue\n");
  for(i = 0; i < size; i++){
    printf("%d\t%d\n", arr[i].key, arr[i].value);
  }
}
