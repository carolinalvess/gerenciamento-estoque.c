# gerenciamento-estoque.c

_______________________________________________________________________________
#gerenciamento-estoque.c

ADS-UNIPAC Uberlandia. 
Aluna: Carolina Alves de Souza.
_______________________________________________________________________________
Gerenciamento de estoque.

O projeto contém as seguintes funcionalidades:


    - Cadastrar produtos;
        - Um produto possui:
            * Descrição.
            * Quantidade disponível;
            * Preço Compra;
            * Preço Venda;


    - Listar Produtos;
    - Buscar um produto por código de barras e ou nome;
    - Alterar quantidade de produtos;   


    - Controle de Caixa:
        - Se comprou um produto reduz o caixa;
        - Se vendeu um produto aumenta o caixa;
        - Se não há dinheiro para a compra enviar mensagem;
        
 
   - O Software controla as seguintes opções:
        - Se existe o produto, vende e aumenta o dinheiro no caixa;
        - Se o produto não existe, envia mensagem: 'Produto não existe';
        - Se o produto existe mas a quantidade é insuficiente, envia a mensagem: 'Quantidade não suficiente';
        - Compra de produtos > aumenta a quantidade de produtos no estoque e reduz o dinheiro do caixa;


OBS: Este projeto funciona em tempo de execução, caso seja encerrado as informações serão perdidas. 

   
       *****A plataforma atende perfis comerciais, permitindo melhor visionamento de negócios.*****
