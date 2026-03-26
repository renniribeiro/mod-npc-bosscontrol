// Inclui a classe Player (necessária para manipular o jogador)
#include "Player.h"

// Inclui funções prontas para criar menus de gossip (NPC interativo)
#include "ScriptedGossip.h"

// Sistema base de scripts do AzerothCore
#include "ScriptMgr.h"

// Mensagem inicial (não está sendo usada no código atual)
#define MSG_GOSSIP_TEXT_GETTING_STARTED "Welcome to AzerothCore morph service!"

// Mensagem de erro quando o player está em combate
#define MSG_ERR_INCOMBAT "You are in combat. To use my services, Leave it.."

// Textos exibidos no menu do NPC (gossip)
#define MSG_GOSSIP_TEXT_MORTH_GNOME_MALE "[Transform] Gnome, male."
#define MSG_GOSSIP_TEXT_MORTH_GNOME_FEMALE "[Transform] Gnome, female."
#define MSG_GOSSIP_TEXT_MORTH_HUMAN_MALE "[Transform] Human, male."
#define MSG_GOSSIP_TEXT_MORTH_HUMAN_FEMALE "[Transform] Human, female."
#define MSG_GOSSIP_TEXT_MORTH_BLOOD_ELF_MALE "[Transform] Blood Elf, male."
#define MSG_GOSSIP_TEXT_MORTH_BLOOD_ELF_FEMALE "[Transform] Blood Elf, female."
#define MSG_GOSSIP_TEXT_MORTH_TAUREN_MALE "[Transform] Tauren, male."
#define MSG_GOSSIP_TEXT_MORTH_TAUREN_FEMALE "[Transform] Tauren, female."

// Classe do NPC (script principal)
// Herdando de CreatureScript permite criar comportamento customizado
class npc_bosscontrol : public CreatureScript
{
public: 
    // Construtor: registra o nome do script ("npc_bosscontrol")
    npc_bosscontrol() : CreatureScript("npc_bosscontrol") { }

    // Função chamada quando o jogador interage com o NPC
    bool OnGossipHello(Player* player, Creature* creature) override
    {
        // Limpa qualquer menu anterior do jogador
        ClearGossipMenuFor(player);

        // Adiciona opções no menu (gossip)
        // Parâmetros:
        // - player: quem está interagindo
        // - ícone
        // - texto
        // - sender (geralmente MAIN)
        // - action (ID que será tratado no select)
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_GNOME_MALE, GOSSIP_SENDER_MAIN, 2);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_GNOME_FEMALE, GOSSIP_SENDER_MAIN, 3);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_HUMAN_MALE, GOSSIP_SENDER_MAIN, 4);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_HUMAN_FEMALE, GOSSIP_SENDER_MAIN, 5);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_BLOOD_ELF_MALE, GOSSIP_SENDER_MAIN, 6);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_BLOOD_ELF_FEMALE, GOSSIP_SENDER_MAIN, 7);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_TAUREN_MALE, GOSSIP_SENDER_MAIN, 8);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, MSG_GOSSIP_TEXT_MORTH_TAUREN_FEMALE, GOSSIP_SENDER_MAIN, 9);

        // Envia o menu para o jogador
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());

        return true;
    }

    // Função chamada quando o jogador seleciona uma opção do menu
    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        // Verifica se o jogador está em combate
        if (!player->getAttackers().empty())
        {
            // Envia mensagem privada (whisper)
            creature->Whisper(MSG_ERR_INCOMBAT, LANG_UNIVERSAL, player);

            // Limpa o menu
            ClearGossipMenuFor(player);

            // Cancela a ação
            return false;
        }

        // Trata a ação selecionada (cada número corresponde ao menu)
        switch (action)
        {
            case 2:
                // Muda o modelo visual do player (Gnome male)
                player->SetDisplayId(20580);
                ClearGossipMenuFor(player);
            break;

        case 3:
            player->SetDisplayId(20320);
            ClearGossipMenuFor(player);
            break;

        case 4:
            player->SetDisplayId(15833);
            ClearGossipMenuFor(player);
            break;

        case 5:
            player->SetDisplayId(25056);
            ClearGossipMenuFor(player);
            break;

        case 6:
            player->SetDisplayId(20368);
            ClearGossipMenuFor(player);
            break;

        case 7:
            player->SetDisplayId(20370);
            ClearGossipMenuFor(player);
            break;

        case 8:
            player->SetDisplayId(20319);
            ClearGossipMenuFor(player);
            break;

        case 9:
            player->SetDisplayId(20584);
            ClearGossipMenuFor(player);
            break;
        }

        return true;
    }
};

// Função obrigatória para registrar o script no AzerothCore
void AddSC_npc_bosscontrol()
{
    new npc_bosscontrol(); // instancia o script
}