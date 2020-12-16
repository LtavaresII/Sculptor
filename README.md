# Sculptor Drawer

O Sculptor desenha figuras geometricas em Voxels (3D Pixels) e importa os desenhos em .off, os quais podem ser lidos pelos programas Geomview e MeshLab.
Ele possui uma matriz central, conhecida como Canvas. Nela você pode desenhar varios tipos de estruturas, utlizando varios cubos para dar forma ao seu desenho.

Ele possui 8 funções Principais:

- Put Voxel: Desenha um cubo de tamanho 1x1 no Canvas.
- Cut Voxel: Apaga um cubo de tamanho 1x1 no Canvas.
- Put Box: Desenha uma Caixa de tamanho definido pelas barras de "Tamanho da Caixa".
- Cut Box: Apaga uma Caixa de tamanho definido pelas barras de "Tamanho da Caixa".
- Put Sphere: Desenha uma Esfera de tamanho definido pelas barras de "Raio da Esfera".
- Cut Sphere: Apaga uma Esfera de tamanho definido pelas barras de "Raio da Esfera".
- Put Ellipsoid: Desenha uma Elipse de tamanho definido pelas barras de "Raio da Elipse"
- Cut Ellipsoid: Apaga uma Elipse de tamanho definido pelas barras de "Raio da Elipse"

Essas funções podem ser acessadas pela barra de ferramentas acima da matriz central, disponível necessáriamente nessa ordem.

As Estruturas podem ter suas cores e o grau de transparencia definidas pelas barras de "Selecione a Cor" e definir o plano no qual está desenhando nos botões "Selecione o plano". Podemos também modificar a profundidade do plano, se movendo entre as camadas do Canvas na barra "Selecione a Profundidade".

Caso queria criar um novo Canvas, basta abrir a aba "Arquivo" e em "Novo Canvas", onde abrirá uma janela para configurar as dimensões do novo Canvas.
Para salvar os desenhos de suas estruturas, basta ir novamente em "Arquivo" e em "Exportar Arquivo .off" e irar criar um arquivo .off com suas estruturas, mas caso queira abrir o arquivo e visualizar sua estrutura, clique em "MeshLab" e irá abrir o Meshlab (caso o tenha instalado) no Windows.

Os programas utilizados para visualizar usas estruturas são MeshLab (Windows) e GeomView (Linux).

Autor: Luís Fernando Tavares
