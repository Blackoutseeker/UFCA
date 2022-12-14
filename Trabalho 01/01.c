/*
  Autor: Felipe Pereira de Souza Silva

  Realizar o cadastro de contas bancárias com as seguintes informações: número da conta,
  nome do cliente e saldo. Não poderá haver mais que uma conta com o mesmo nome nesse
  banco. Crie o menu de opções a seguir:

  1.1) Cadastrar conta.
  1.2) Visualizar todas as contas de determinado cliente.
  1.3) Excluir a conta com menor saldo.
  1.4) Inserir/Remover valor da conta.
  1.5) Imprimir de forma ordenada as contas pelo saldo dos clientes, informando o saldo e
  número da conta.
  1.6) Imprimir a soma dos saldos de todas as contas.
  1.7) Sair.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE_NAME "log.txt"
#define CUSTOMERS_MAX_LENGTH 50
#define INITIAL_BALANCE_VALUE 0.0

typedef struct {
  int *array;
  size_t length;
  size_t size;
} Array;

typedef struct {
  int account_id;
  char name[128];
  char login[128];
  char password[128];
  float balance;
} Customer;

void init_array(Array *array);
void insert_into_array(Array *array, int element);
int check_array_duplicates(Array *array);

void create_file();
void write_into_file(char *text);

int increment_account_id(Array *account_ids);
int get_account_id(Customer *customer);
void create_new_account(Array *account_ids, Customer *customer);
void show_customer_info(Customer *customer);
void show_all_accounts(Customer *customers[CUSTOMERS_MAX_LENGTH]);
void delete_account(Customer *customer);
void delete_account_with_lowest_balance(Customer *customers[CUSTOMERS_MAX_LENGTH], int length);
void show_customers_sorted_by_account_balance(Customer *customers[CUSTOMERS_MAX_LENGTH]);
void show_accounts_balance_sum(Customer *customers[CUSTOMERS_MAX_LENGTH]);

int main() {
  Array account_ids;
  Customer *customers[CUSTOMERS_MAX_LENGTH];
  int main_operation = 1;

  init_array(&account_ids);
  create_file();

  while (main_operation != 7) {
    printf("\n\nEscolha uma operacao: ");
    printf("\n\n1) Cadastrar conta");
    printf("\n2) Visualizar todas as contas");
    printf("\n3) Excluir conta com menor saldo");
    printf("\n4) Inserir/Remover valor da conta");
    printf("\n5) Visualizar de forma ordenada as contas pelo saldo dos clientes");
    printf("\n6) Visualizar a soma dos saldos de todas as contas");
    printf("\n7) Sair\n");
    scanf("%d", &main_operation);

    switch (main_operation) {
    case 1:
      int customer_index = 0;
      if (account_ids.length > 0) customer_index = account_ids.length - 1;
      create_new_account(&account_ids, &customers[customer_index]);
      break;
    case 2:
      show_all_accounts(customers);
      break;
    case 3:
      delete_account_with_lowest_balance(customers, account_ids.length);
      break;
    case 4:
      int account_id = 1;
      printf("Digite o numero da conta: ");
      scanf("%d", &account_id);
      for (int index = 0; index < account_ids.length; index++) {
        int customer_account_id = get_account_id(&customers[index]);
        if (account_id == customer_account_id) {
          change_account_balance(&customers[index]);
        }
      }
      break;
    case 5:
      show_customers_sorted_by_account_balance(customers);
      break;
    case 6:
      show_accounts_balance_sum(customers);
      break;
    default:
      break;
    }
  }

  return 0;
}

void init_array(Array *array) {
  array->array = malloc(sizeof(int));
  array->length = 0;
  array->size = 1;
}

void insert_into_array(Array *array, int element) {
  if (array->length == array->size) {
    array->size *= 2;
    array->array = realloc(array->array, array->size * sizeof(int));
  }
  int array_top_index = array->length++;
  array->array[array_top_index] = element;
}

int check_array_duplicates(Array *array) {
  for (int i = 0; i < array->length; i++) {
    for (int j = i + 1; j < array->length; j++) {
      if (array->array[i] == array->array[j]) {
        return 1;
      }
    }
  }

  return 0;
}

void create_file() {
  FILE *file = fopen(LOG_FILE_NAME, "w");
  fclose(file);
}

void write_into_file(char *text) {
  FILE *file = fopen(LOG_FILE_NAME, "a");

  char *formatted_text = malloc(strlen(text) + 1);
  strcpy(formatted_text, text);
  strcat(formatted_text, "\n");

  fprintf(file, formatted_text);
  fclose(file);
}

int increment_account_id(Array *account_ids) {
  int latest_account_id = 0;
  if(account_ids->length != 0) {
    latest_account_id = account_ids->array[(account_ids->length - 1)];
  }
  insert_into_array(account_ids, latest_account_id + 1);
  return latest_account_id + 1;
}

int get_account_id(Customer *customer) {
  return customer->account_id;
}

void create_new_account(Array *account_ids, Customer *customer) {
  printf("\n\nDigite seu nome: ");
  scanf(" %[^\n]s", &customer->name);
  printf("Digite seu login: ");
  scanf(" %[^\n]s", &customer->login);
  printf("Crie uma senha: ");
  scanf(" %[^\n]s", &customer->password);

  int account_id = increment_account_id(account_ids);
  customer->account_id = account_id;
  customer->balance = INITIAL_BALANCE_VALUE;

  char *account_id_string = malloc(sizeof(int) + 1);
  char *balance_string = malloc(sizeof(float) + 1);
  snprintf(account_id_string, sizeof(int) + 1, "%d", account_id);
  snprintf(balance_string, sizeof(float) + 1, "%f", customer->balance);

  time_t raw_time;
  struct tm *time_info;
  time(&raw_time);
  time_info = localtime(&raw_time);
  char *time_string = asctime(time_info);

  write_into_file(time_string);
  write_into_file("=>NEW ACCOUNT CREATED\n");
  write_into_file(account_id_string);
  write_into_file(&customer->name);
  write_into_file(&customer->login);
  write_into_file(&customer->password);
  write_into_file(balance_string);
}

void show_customer_info(Customer *customer) {
  printf("\n\nNumero da conta: %d", customer->account_id);
  printf("\nNome: %s", customer->name);
  printf("\nLogin: %s", customer->login);
  printf("\nSenha: %s", customer->password);
  printf("\nSaldo: %.2f", customer->balance);
}

void show_all_accounts(Customer *customers[CUSTOMERS_MAX_LENGTH]) {
  for (int index = 0; index < CUSTOMERS_MAX_LENGTH; index++) {
    if (&customers[index]->account_id <= 0) break;
    show_customer_info(&customers[index]);
  }
}

void delete_account(Customer *customer) {
  customer->account_id = NULL;
  strcpy(customer->name, "");
  strcpy(customer->login, "");
  strcpy(customer->password, "");
  customer->balance = INITIAL_BALANCE_VALUE;

  time_t raw_time;
  struct tm * time_info;
  time(&raw_time);
  time_info = localtime(&raw_time);
  char *time_string = asctime(time_info);

  write_into_file(time_string);
  write_into_file("=>AN ACCOUNT HAS BEEN DELETED\n");
}

float get_customer_balance(Customer *customer) {
  return customer->balance;
}

void delete_account_with_lowest_balance(Customer *customers[CUSTOMERS_MAX_LENGTH], int length) {
  float lowest_balance = 0.0;
  int customer_index = 0;

  for (int index = 0; index < length; index++) {
    if (&customers[index]->account_id <= 0) break;

    float customer_balance = get_customer_balance(&customers[index]);
    if (index == 0) lowest_balance = customer_balance;

    if (customer_balance < lowest_balance) {
      lowest_balance = customer_balance;
      customer_index = index;
    }
  }

  delete_account(&customers[customer_index]);
}

void change_account_balance(Customer *customer) {
  float customer_balance = 0.0;
  printf("\nDigite o valor que deseja depositar (negativo, caso queira retirar): ");
  scanf("%f", &customer_balance);
  customer->balance = customer->balance + customer_balance;

  char *account_id_string = malloc(sizeof(int) + 1);
  char *balance_string = malloc(sizeof(float) + 1);
  snprintf(account_id_string, sizeof(int) + 1, "%d", customer->account_id);
  snprintf(balance_string, sizeof(float) + 1, "%f", customer->balance);

  time_t raw_time;
  struct tm *time_info;
  time(&raw_time);
  time_info = localtime(&raw_time);
  char *time_string = asctime(time_info);

  write_into_file(time_string);
  write_into_file("=>ACCOUNT BALANCE CHANGED\n");
  write_into_file(account_id_string);
  write_into_file(&customer->login);
  write_into_file(balance_string);
}

void sort(float balances[], int length) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (balances[j] > balances[j+1]) {
        int temp = balances[j];
        balances[j] = balances[j+1];
        balances[j+1] = temp;
      }
    }
  }
}

void show_customers_sorted_by_account_balance(Customer *customers[CUSTOMERS_MAX_LENGTH]) {
  float balances[CUSTOMERS_MAX_LENGTH];
  int length = 0;

  for (int index = 0; index < CUSTOMERS_MAX_LENGTH; index++) {
    if (&customers[index]->account_id <= 0) break;

    float customer_balance = get_customer_balance(&customers[index]);
    balances[index] = customer_balance;
    length++;
  }

  sort(balances, length);

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      float customer_balance = get_customer_balance(&customers[j]);
      if (balances[i] == customer_balance) show_customer_info(&customers[j]);
    }
  }
}

void show_accounts_balance_sum(Customer *customers[CUSTOMERS_MAX_LENGTH]) {
  float balance_sum = 0.0;
  for (int index = 0; index < CUSTOMERS_MAX_LENGTH; index++) {
    float customer_balance = get_customer_balance(&customers[index]);
    balance_sum += customer_balance;
  }

  printf("\n\nSoma total dos saldos: %.2f", balance_sum);

  char *balance_sum_string = malloc(sizeof(int) + 1);
  snprintf(balance_sum_string, sizeof(int) + 1, "%.2f", balance_sum);

  time_t raw_time;
  struct tm *time_info;
  time(&raw_time);
  time_info = localtime(&raw_time);
  char *time_string = asctime(time_info);

  write_into_file(time_string);
  write_into_file("=>ALL ACCOUNTS BALANCE SUM\n");
  write_into_file(balance_sum_string);
}
