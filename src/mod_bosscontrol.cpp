#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

/*
    NPC Boss Controller

    Função:
    - Exibe menu com opções de bosses
    - Invoca bosses em uma posição fixa (arena)

    Observação:
    - Base para sistema estilo Ring of Blood
*/

// ================================
// Coordenadas fixas da arena
// ================================
#define ARENA_X -3452.4685f
#define ARENA_Y -1463.7767f
#define ARENA_Z 233.0338f
#define ARENA_O 0.44351226f

// ================================
// Textos
// ================================
#define MSG_ERR_INCOMBAT "You are in combat. Leave combat first."

#define MSG_SUMMON_1 "[Summon] Boss 1"
#define MSG_SUMMON_2 "[Summon] Boss 2"
#define MSG_SUMMON_3 "[Summon] Boss 3"

class npc_bosscontrol : public CreatureScript
{
public:
    npc_bosscontrol() : CreatureScript("npc_bosscontrol") { }

    /*
        Executado quando o player interage com o NPC
        Aqui criamos o menu
    */
    bool OnGossipHello(Player* player, Creature* creature) override
    {
        ClearGossipMenuFor(player);

        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_SUMMON_1, GOSSIP_SENDER_MAIN, 1);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_SUMMON_2, GOSSIP_SENDER_MAIN, 2);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_SUMMON_3, GOSSIP_SENDER_MAIN, 3);

        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    /*
        Executado quando o player escolhe uma opção do menu
    */
    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        // Bloqueia uso em combate
        if (!player->getAttackers().empty())
        {
            creature->Whisper(MSG_ERR_INCOMBAT, LANG_UNIVERSAL, player);
            ClearGossipMenuFor(player);
            CloseGossipMenuFor(player);
            return false;
        }

        /*
            Spawn dos bosses na posição fixa da arena
        */
        switch (action)
        {
            case 1: // Boss 1
                creature->SummonCreature(80001, ARENA_X, ARENA_Y, ARENA_Z, ARENA_O,
                    TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                break;

            case 2: // Boss 2
                creature->SummonCreature(80002, ARENA_X, ARENA_Y, ARENA_Z, ARENA_O,
                    TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                break;

            case 3: // Boss 3
                creature->SummonCreature(80003, ARENA_X, ARENA_Y, ARENA_Z, ARENA_O,
                    TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                break;
        }

        // Fecha o menu
        ClearGossipMenuFor(player);
        CloseGossipMenuFor(player);

        return true;
    }
};

/*
    Registro do script no core
*/
void AddSC_npc_bosscontrol()
{
    new npc_bosscontrol();
}