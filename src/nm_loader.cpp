#include "ScriptMgr.h"

// Declaração do script
void AddSC_npc_bosscontrol();

/*
    Função chamada pelo core para registrar scripts do módulo
*/
void Addmod_bosscontrolScripts()
{
    AddSC_npc_bosscontrol();
}
