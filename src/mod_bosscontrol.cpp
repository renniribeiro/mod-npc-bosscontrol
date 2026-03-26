// =====================================
// Coordenadas fixas da arena
// =====================================
#define ARENA_X -3452.4685f
#define ARENA_Y -1463.7767f
#define ARENA_Z 233.0338f
#define ARENA_O 0.44351226f

bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
{
    // Bloqueia uso em combate
    if (!player->getAttackers().empty())
    {
        creature->Whisper("You are in combat. Leave combat first.", LANG_UNIVERSAL, player);
        ClearGossipMenuFor(player);
        CloseGossipMenuFor(player);
        return false;
    }

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

    ClearGossipMenuFor(player);
    CloseGossipMenuFor(player);
    return true;
}