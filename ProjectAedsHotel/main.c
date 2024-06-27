#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ano;
    int mes;
    int dia;
} datas;

typedef struct
{
    int codigo;
    char nome[50];
    char endereco[50];
    char telefone[20];
} cliente;

typedef struct
{
    int codigo;
    char nome[50];
    char telefone[20];
    char cargo[30];
    float salario;
} funcionario;

typedef struct
{
    int codigo;
    int qnt_diarias;
    int codigo_cliente;
    int num_quarto;
    datas data_entrada;
    datas data_saida;
} estadia;

typedef struct
{
    int num_quarto;
    int qnt_hospedes;
    float valor_diaria;
    int status;
} quarto;

int total_cliente = 0;
int total_funcionario = 0;
int total_estadia = 0;
int total_quarto = 0;

void cadastrar_cliente(cliente cli[])
{

    cli[total_cliente].codigo = total_cliente + 1;
    printf("\n\tCadastre um cliente !!\n\n");
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cli[total_cliente].nome);
    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]", cli[total_cliente].endereco);
    printf("Digite o telefone do cliente: ");
    scanf(" %[^\n]", cli[total_cliente].telefone);
    printf("Cliente cadastrado com sucesso !!\n\n");
    total_cliente++;
}

void cadastrar_funcionario(funcionario fun[])
{
    printf("\n\tCadastre um funcionario !!\n\n");

    fun[total_funcionario].codigo = total_funcionario + 1;

    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", fun[total_funcionario].nome);
    printf("Digite o telefone do funcionario: ");
    scanf(" %[^\n]", fun[total_funcionario].telefone);
    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]", fun[total_funcionario].cargo);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &fun[total_funcionario].salario);
    printf("Funcionario cadastrado com sucesso !!\n\n");
    total_funcionario++;
}

int validar_data(datas dat)
{
    if (dat.ano < 2023)
        return 0;

    if (dat.mes < 1 || dat.mes > 12)
        return 0;

    if (dat.dia < 1 || dat.dia > 30)
        return 0;

    return 1;
}

// Fnção que verifica se a segunda data é maior do que a primeira
int data_maior_que(datas dat1, datas dat2)
{
    if (dat2.ano > dat1.ano)
        return 1;
    if (dat2.ano == dat1.ano)
    {
        if (dat2.mes > dat1.mes)
            return 1;
        if (dat2.mes == dat1.mes)
        {
            if (dat2.dia > dat1.dia)
                return 1;
        }
    }
    return 0;
}

void cadastrar_estadia(estadia est[], cliente cli[], quarto qua[])
{
    int qnt_hospedes, cliente_valido = 0, quarto_encontrado = 0;
    datas data_entrada, data_saida;

    if (total_cliente > 0 && total_quarto > 0)
    {
        printf("\n\tCadastre sua Estadia !!\n\n");

        do
        {
            printf("Digite o codigo do cliente: ");
            scanf("%d", &est[total_estadia].codigo_cliente);
            for (int i = 0; i < total_cliente; i++)
            {
                if (est[total_estadia].codigo_cliente == cli[i].codigo)
                {
                    cliente_valido = 1;
                    break;
                }
            }
        }
        while (!cliente_valido);

        printf("Digite a quantidade de hospedes: ");
        scanf("%d", &qnt_hospedes);

        do
        {
            printf("Digite a data de entrada (dia/mes/ano): ");
            scanf("%d/%d/%d", &data_entrada.dia, &data_entrada.mes,
                  &data_entrada.ano);
        }
        while (!validar_data(data_entrada));

        do
        {
            printf("Digite a data de saida (dia/mes/ano): ");
            scanf("%d/%d/%d", &data_saida.dia, &data_saida.mes, &data_saida.ano);
        }
        while (!validar_data(data_saida) ||
                !data_maior_que(data_entrada, data_saida));

        est[total_estadia].data_entrada = data_entrada;
        est[total_estadia].data_saida = data_saida;

        est[total_estadia].qnt_diarias = ((est[total_estadia].data_saida.ano -
                                           est[total_estadia].data_entrada.ano) *
                                          365 +
                                          (est[total_estadia].data_saida.mes -
                                           est[total_estadia].data_entrada.mes) *
                                          30 +
                                          (est[total_estadia].data_saida.dia -
                                           est[total_estadia].data_entrada.dia));

        for (int i = 0; i < total_quarto; i++)
        {
            if (qnt_hospedes <= qua[i].qnt_hospedes && qua[i].status == 0)
            {
                qua[i].status = 1;
                est[total_estadia].num_quarto = qua[i].num_quarto;
                quarto_encontrado = 1;
                break;
            }
        }

        if (quarto_encontrado)
        {
            est[total_estadia].codigo = total_estadia + 1;
            total_estadia++;
            printf("Estadia cadastrada com sucesso!\n");
        }
        else
        {
            printf("Nao ha quartos disponíveis para a quantidade de hospedes.\n");
        }
    }
    else
    {
        printf("Nao ha clientes ou quartos cadastrados suficientes.\n\n");
    }
}

void dar_baixa_estadia(estadia est[], quarto qua[], cliente cli[])
{
    int codigo_estadia, indice_estadia = -1;
    float total_valor;

    // Solicita o código da estadia
    printf("\nInforme o codigo da estadia para dar baixa: ");
    scanf("%d", &codigo_estadia);

    // Procura a estadia correspondente ao código
    for (int i = 0; i < total_estadia; i++)
    {
        if (est[i].codigo == codigo_estadia)
        {
            indice_estadia = i;
            break;
        }
    }

    // Se a estadia não for encontrada
    if (indice_estadia == -1)
    {
        printf("\nNenhuma estadia encontrada com o codigo fornecido.\n");
        return;
    }

    // Calcula o valor total da estadia
    int quarto_codigo = est[indice_estadia].num_quarto;
    total_valor =
        est[indice_estadia].qnt_diarias * qua[quarto_codigo - 1].valor_diaria;

    // Exibe os detalhes da estadia
    printf("==========================");
    printf("\nDetalhes da estadia:\n");
    printf("Codigo da estadia: %d\n", est[indice_estadia].codigo);
    printf("Codigo do cliente: %d\n", est[indice_estadia].codigo_cliente);
    printf("Nome do cliente: %s\n",
           cli[est[indice_estadia].codigo_cliente - 1].nome);
    printf("Numero do quarto: %d\n", quarto_codigo);
    printf("Quantidade de diarias: %d\n", est[indice_estadia].qnt_diarias);
    printf("Valor total: R$ %.2f\n", total_valor);
    printf("Data de entrada: %d/%d/%d\n", est[indice_estadia].data_entrada.dia,
           est[indice_estadia].data_entrada.mes,
           est[indice_estadia].data_entrada.ano);
    printf("Data de saida: %d/%d/%d\n", est[indice_estadia].data_saida.dia,
           est[indice_estadia].data_saida.mes,
           est[indice_estadia].data_saida.ano);
    printf("==========================\n");

    // Atualiza o status do quarto para disponível
    for (int j = 0; j < total_quarto; j++)
    {
        if (qua[j].num_quarto == quarto_codigo)
        {
            qua[j].status = 0;
            break;
        }
    }
    // Remove a estadia do array deslocando os elementos
    for (int k = indice_estadia; k < total_estadia - 1; k++)
    {
        est[k] = est[k + 1];
    }
    total_estadia--;
    // Confirmação da operação
    printf("\nEstadia concluida com sucesso.\n");
}

void pesquisar(cliente cli[], funcionario fun[])
{
    int tipo_pesquisa, tipo_critica, codigo;
    char termo_pesquisa[50];
    int encontrados = 0;

    printf("\n\tFaca sua Pesquisa !!\n\n");

    // Selecionar tipo de pesquisa: Cliente ou Funcionário
    do
    {
        printf("Deseja pesquisar: \n\n");
        printf("1. Cliente\n2. Funcionario\n\nDigite a opcao desejada: ");
        scanf("%d", &tipo_pesquisa);
    }
    while (tipo_pesquisa < 1 || tipo_pesquisa > 2);

    // Selecionar tipo de critério: Nome ou Código
    do
    {
        printf("Deseja pesquisar por: \n\n");
        printf("1. Nome\n2. Codigo\n\nDigite a opcao desejada: ");
        scanf("%d", &tipo_critica);
    }
    while (tipo_critica < 1 || tipo_critica > 2);

    // Realizar a pesquisa de acordo com as escolhas
    if (tipo_pesquisa == 1)    // Pesquisar Cliente
    {
        if (tipo_critica == 1)   // Pesquisar por Nome
        {
            printf("Digite o nome do cliente: ");
            scanf(" %[^\n]", termo_pesquisa);
            for (int i = 0; i < total_cliente; i++)
            {
                if (strcmp(termo_pesquisa, cli[i].nome) == 0)
                {
                    encontrados++;
                    printf("\n========================");
                    printf("\nCodigo: %d\n", cli[i].codigo);
                    printf("Nome: %s\n", cli[i].nome);
                    printf("Endereco: %s\n", cli[i].endereco);
                    printf("Telefone: %s\n", cli[i].telefone);
                    printf("==========================\n");
                }
            }
        }
        else     // Pesquisar por Código
        {
            printf("Digite o codigo do cliente: ");
            scanf("%d", &codigo);
            for (int i = 0; i < total_cliente; i++)
            {
                if (codigo == cli[i].codigo)
                {
                    encontrados++;
                    printf("\n========================");
                    printf("\nCodigo: %d\n", cli[i].codigo);
                    printf("Nome: %s\n", cli[i].nome);
                    printf("Endereco: %s\n", cli[i].endereco);
                    printf("Telefone: %s\n", cli[i].telefone);
                    printf("==========================\n");
                    break; // Não é necessário continuar após encontrar o cliente
                }
            }
        }
    }
    else                       // Pesquisar Funcionário
    {
        if (tipo_critica == 1)   // Pesquisar por Nome
        {
            printf("Digite o nome do funcionario: ");
            scanf(" %[^\n]", termo_pesquisa);
            for (int i = 0; i < total_funcionario; i++)
            {
                if (strcmp(termo_pesquisa, fun[i].nome) == 0)
                {
                    encontrados++;
                    printf("\n==========================");
                    printf("\nCodigo: %d\n", fun[i].codigo);
                    printf("Nome: %s\n", fun[i].nome);
                    printf("Telefone: %s\n", fun[i].telefone);
                    printf("Cargo: %s\n", fun[i].cargo);
                    printf("Salario: %.2f\n", fun[i].salario);
                    printf("==========================\n");
                }
            }
        }
        else     // Pesquisar por Código
        {
            printf("Digite o codigo do funcionario: ");
            scanf("%d", &codigo);
            for (int i = 0; i < total_funcionario; i++)
            {
                if (codigo == fun[i].codigo)
                {
                    encontrados++;
                    printf("\n==========================");
                    printf("\nCodigo: %d\n", fun[i].codigo);
                    printf("Nome: %s\n", fun[i].nome);
                    printf("Telefone: %s\n", fun[i].telefone);
                    printf("Cargo: %s\n", fun[i].cargo);
                    printf("Salario: %.2f\n", fun[i].salario);
                    printf("==========================\n");
                    break; // Não é necessário continuar após encontrar o funcionário
                }
            }
        }
    }

    // Se não encontrou nenhum resultado
    if (encontrados == 0)
    {
        printf("Nenhuma informacao encontrada.\n\n");
    }
}

void exibir_estadia(estadia est[], cliente cli[])
{
    int codigo_cliente;
    int estadias_encontradas = 0;

    printf("\nDigite o codigo do cliente: ");
    scanf("%d", &codigo_cliente);

    printf("\nEstadias encontradas para o cliente %s:\n",
           cli[codigo_cliente - 1].nome);

    for (int i = 0; i < total_estadia; i++)
    {
        if (est[i].codigo_cliente == codigo_cliente)
        {
            estadias_encontradas++;
            printf("\n==========================");
            printf("\nCodigo da estadia: %d\n", est[i].codigo);
            printf("Numero do quarto: %d\n", est[i].num_quarto);
            printf("Quantidade de diarias: %d\n", est[i].qnt_diarias);
            printf("Data de entrada: %02d/%02d/%02d\n", est[i].data_entrada.dia,
                   est[i].data_entrada.mes, est[i].data_entrada.ano);
            printf("Data de saida: %02d/%02d/%02d\n", est[i].data_saida.dia,
                   est[i].data_saida.mes, est[i].data_saida.ano);
            printf("==========================\n");
        }
    }

    if (estadias_encontradas == 0)
    {
        printf("\nNenhuma estadia encontrada para o cliente %s com o codigo %d.\n",
               cli[codigo_cliente - 1].nome, codigo_cliente);
    }
}

void print_file(cliente cli[], funcionario fun[], estadia est[], quarto qua[])
{

    FILE *arquivo_cliente = fopen("clientes.txt", "w");
    FILE *arquivo_funcionarios = fopen("funcionarios.txt", "w");
    FILE *arquivo_estadias = fopen("estadias.txt", "w");
    FILE *arquivo_quartos = fopen("quartos.txt", "w");

    if (arquivo_cliente == NULL || arquivo_funcionarios == NULL ||
            arquivo_estadias == NULL || arquivo_quartos == NULL)
    {
        printf("Erro ao abrir os arquivos para escrita.\n");
        return;
    }

    // printa o total de clientes
    fprintf(arquivo_cliente, "%d\n", total_cliente);

    // printa todas as informações de um cliente
    for (int i = 0; i < total_cliente; i++)
    {
        fprintf(arquivo_cliente, "%d?%s?%s?%s\n", cli[i].codigo, cli[i].nome,
                cli[i].endereco, cli[i].telefone);
    }

    // printa o total de funcionarios
    fprintf(arquivo_funcionarios, "%d\n", total_funcionario);

    // printa todas as informações dos funcionarios
    for (int i = 0; i < total_funcionario; i++)
    {
        fprintf(arquivo_funcionarios, "%d?%s?%s?%s?%.2f\n", fun[i].codigo,
                fun[i].nome, fun[i].telefone, fun[i].cargo, fun[i].salario);
    }

    // printa o total de estadias
    fprintf(arquivo_estadias, "%d\n", total_estadia);

    // printa todas as informações das estadias
    for (int i = 0; i < total_estadia; i++)
    {
        fprintf(arquivo_estadias, "%d?%d?%d?%d?%02d/%02d/%02d?%02d/%02d/%02d\n",
                est[i].codigo, est[i].qnt_diarias, est[i].codigo_cliente,
                est[i].num_quarto, est[i].data_entrada.dia, est[i].data_entrada.mes,
                est[i].data_entrada.ano, est[i].data_saida.dia,
                est[i].data_saida.mes, est[i].data_saida.ano);
    }

    // printa o total de quartos
    fprintf(arquivo_quartos, "%d\n", total_quarto);

    // printa todas as informações dos quartos
    for (int i = 0; i < total_quarto; i++)
    {
        fprintf(arquivo_quartos, "%d?%d?%.2f?", qua[i].num_quarto,
                qua[i].qnt_hospedes, qua[i].valor_diaria);
        if (qua[i].status == 0)
        {
            fprintf(arquivo_quartos, "desocupado\n");
        }
        else
        {
            fprintf(arquivo_quartos, "ocupado\n");
        }
    }

    fclose(arquivo_cliente);
    fclose(arquivo_funcionarios);
    fclose(arquivo_estadias);
    fclose(arquivo_quartos);
}

// scanea todas as informações do arquivo
void read_file(cliente cli[], funcionario fun[], estadia est[], quarto qua[])
{
    FILE *arquivo_cliente = fopen("clientes.txt", "r");
    FILE *arquivo_funcionarios = fopen("funcionarios.txt", "r");
    FILE *arquivo_estadias = fopen("estadias.txt", "r");
    FILE *arquivo_quartos = fopen("quartos.txt", "r");

    if (arquivo_cliente == NULL || arquivo_funcionarios == NULL ||
            arquivo_estadias == NULL || arquivo_quartos == NULL)
    {
        printf("Erro ao abrir os arquivos para leitura.\n");
        return;
    }

    // leitura do total de clientes
    fscanf(arquivo_cliente, "%d\n", &total_cliente);

    // leitura de todas as informações dos clientes
    for (int i = 0; i < total_cliente; i++)
    {
        fscanf(arquivo_cliente, "%d?%[^?]?%[^?]?%[^\n]\n", &cli[i].codigo,
               cli[i].nome, cli[i].endereco, cli[i].telefone);
    }

    // leitura do total de funcionarios
    fscanf(arquivo_funcionarios, "%d\n", &total_funcionario);

    // leitura de todas as informações dos funcionarios
    for (int i = 0; i < total_funcionario; i++)
    {
        fscanf(arquivo_funcionarios, "%d?%[^?]?%[^?]?%[^?]?%f\n", &fun[i].codigo,
               fun[i].nome, fun[i].telefone, fun[i].cargo, &fun[i].salario);
    }

    // leitura do total de estadias
    fscanf(arquivo_estadias, "%d\n", &total_estadia);

    // leitura de todas as informações das estadias
    for (int i = 0; i < total_estadia; i++)
    {
        fscanf(arquivo_estadias, "%d?%d?%d?%d?%d/%d/%d?%d/%d/%d\n", &est[i].codigo,
               &est[i].qnt_diarias, &est[i].codigo_cliente, &est[i].num_quarto,
               &est[i].data_entrada.dia, &est[i].data_entrada.mes,
               &est[i].data_entrada.ano, &est[i].data_saida.dia,
               &est[i].data_saida.mes, &est[i].data_saida.ano);
    }

    // leitura do total de quartos
    fscanf(arquivo_quartos, "%d\n", &total_quarto);

    // leitura de todas as informações dos quartos
    for (int i = 0; i < total_quarto; i++)
    {
        char status_str[20];
        fscanf(arquivo_quartos, "%d?%d?%f?%s\n", &qua[i].num_quarto,
               &qua[i].qnt_hospedes, &qua[i].valor_diaria, status_str);
        if (strcmp(status_str, "desocupado") == 0)
        {
            qua[i].status = 0;
        }
        else
        {
            qua[i].status = 1;
        }
    }

    fclose(arquivo_cliente);
    fclose(arquivo_funcionarios);
    fclose(arquivo_estadias);
    fclose(arquivo_quartos);
}

int main()
{
    // Arrays para armazenar os dados
    cliente cli[100];
    funcionario fun[50];
    estadia est[100];
    quarto qua[50];

    read_file(cli, fun, est, qua);

    int opcao;

    // Loop principal do menu
    do
    {
        printf("\n========== Menu Principal ==========\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Funcionario\n");
        printf("3. Cadastrar Estadia\n");
        printf("4. Exibir Estadia de Cliente\n");
        printf("5. Dar Baixa em Estadia\n");
        printf("6. Pesquisar\n");
        printf("7. Sair\n");
        printf("====================================\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrar_cliente(cli);
            print_file(cli, fun, est, qua);
            break;
        case 2:
            cadastrar_funcionario(fun);
            print_file(cli, fun, est, qua);
            break;
        case 3:
            cadastrar_estadia(est, cli, qua);
            print_file(cli, fun, est, qua);
            break;
        case 4:
            exibir_estadia(est, cli);
            break;
        case 5:
            dar_baixa_estadia(est, qua, cli);
            print_file(cli, fun, est, qua);
            break;
        case 6:
            pesquisar(cli, fun);
            break;
        case 7:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
    while (opcao != 7);

    return 0;
}

