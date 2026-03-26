#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"

#define MSG_GOSSIP_TEXT_GETTING_STARTED "Bem-vindo(a) a Arena Nixcraft!"

#define MSG_ERR_INCOMBAT "Você está em combatee. Tente novamente mais tarde, bye-bye.."

#define MSG_GOSSIP_TEXT_MORTH_GNOME_MALE "[Sumonar] Monstrinho."
#define MSG_GOSSIP_TEXT_MORTH_GNOME_FEMALE "[Sumonar] Monstro."
#define MSG_GOSSIP_TEXT_MORTH_HUMAN_MALE "[Sumonar] Monstrengo."

class npc_bosscontrol : public CreatureScript
{
public: 
    npc_bosscontrol() : CreatureScript("npc_bosscontrol") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_GNOME_MALE, GOSSIP_SENDER_MAIN, 2);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_GNOME_FEMALE, GOSSIP_SENDER_MAIN, 3);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_HUMAN_MALE, GOSSIP_SENDER_MAIN, 4);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        if (!player->getAttackers().empty())
        {
            creature->Whisper(MSG_ERR_INCOMBAT, LANG_UNIVERSAL, player);
            ClearGossipMenuFor(player);
            return false;
        }

        switch (action)
        {
            case 2:
                .npc add 80001;
                ClearGossipMenuFor(player);
            break;
			case 3:
				.npc add 80002;
				ClearGossipMenuFor(player);
				break;
			case 4:
				.npc add 80003;
				ClearGossipMenuFor(player);
				break;
        }

        return true;
    }
};

void AddSC_npc_bosscontrol()
{
    new npc_bosscontrol();
}
