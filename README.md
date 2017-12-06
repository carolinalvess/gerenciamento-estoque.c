#gerenciamento-estoque.c


ADS-UNIPAC Uberlandia. 

Disciplina: Técnicas de programação.
Professor: Diego Alves da Silva.

Aluna: Carolina Alves de Souza.

_______________________________________________________________________________
Gerenciamento de estoque.

O projeto contém as seguintes funcionalidades:

    - Cadastro de produtos;
    - Alterar quantidade de produtos;
    - Listar produtos;
    - Buscar um produto por código de barras;
       - Os produtos possuem:
           -Descrição;
           -Código de barras;
           -Quantidade disponível;
           -Preço compra;
           -Preço de venda;
           
   - Controle de Caixa:
        -Se comprou um produto reduz o caixa;
        -Se vendeu um produto aumenta o caixa;
        -Se não há dinheiro para a compra enviar mensagem;
        
        
   - O Software controla as seguitnes opções:
        - Se existe o produto, vende e aumenta o dinheiro no caixa;
        - Se o produto não existe, envia mensagem: 'Produto não existe';
        - Se o produto existe mas a quantidade é insuficiente, envia a mensagem: 'Quantidade não suficiente';
        - Compra de produtos > aumenta a quantidade de produtos no estoque e reduz o dinheiro do caixa;


OBS: Este projeto funciona em tempo de execução, caso seja encerrado as informações serão perdidas. 
   
       *****A plataforma atende perfis comerciais, permitindo melhor visionamento de negócios.*****
       
       
       
       
