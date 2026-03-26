// Declaração da função que registra o script do NPC
// Essa função foi definida no arquivo npc_morph.cpp
void AddSC_npc_morph();

// Função principal do módulo (loader)
// O nome normalmente segue padrão: Addmod_<nome>Scripts
void Addmod_npc_morphScripts()
{
    // Chama a função que registra o script no core
    AddSC_npc_morph();
}
