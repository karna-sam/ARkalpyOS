# ARkalpyOS
🌌 ARkalpyOS
ARkalpyOS é um sistema operacional desenvolvido do zero, projetado com uma arquitetura poliglota que abrange desde o controle direto do hardware até abstrações de alto nível para o ambiente de usuário.

🛠️ Stack Tecnológica
O desenvolvimento do ARkalpyOS utiliza um conjunto diversificado de linguagens, cada uma otimizada para uma camada específica do kernel e da userland:

<p align="left">
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" width="50" title="C" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width="50" title="C++" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/csharp/csharp-original.svg" width="50" title="C#" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/rust/rust-original.svg" width="50" title="Rust" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg" width="50" title="Python" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/perl/perl-original.svg" width="50" title="Perl" />
</p>

🏗️ Organização por Camadas
Low-Level & Kernel: Implementação em Assembly e C para bootloader, GDT, IDT e gerenciamento de memória.

System Services: Lógica de núcleo segura desenvolvida em Rust e C++.

Formal Design: Estruturação de módulos robustos via Modula-2.

Build System: Pipeline de automação e manipulação de binários com Python e Perl.

Application Layer: Ferramentas de suporte e interface de usuário utilizando C#.

🚀 Objetivo do Projeto
O ARkalpyOS busca o equilíbrio entre a segurança moderna (Rust) e o controle clássico (Assembly/C), criando um ecossistema onde diferentes paradigmas de programação coexistem no mesmo núcleo.
