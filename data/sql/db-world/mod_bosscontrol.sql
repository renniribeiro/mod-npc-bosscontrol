-- #########################################################
-- Boss Controller NPC (sem spawn fixo)
-- #########################################################

-- Remove caso já exista
DELETE FROM creature_template WHERE entry = 90000;

-- Cria o NPC
INSERT INTO creature_template (
    entry, name, subname, minlevel, maxlevel,
    faction, npcflag, speed_walk, speed_run,
    scale, rank, unit_class, unit_flags,
    type, type_flags, ScriptName
) VALUES (
    90000,
    'Boss Controller',
    'Arena System',
    80, 80,
    35,            -- friendly
    1,             -- gossip habilitado
    1, 1.14286,
    1,
    0,
    1,
    0,
    7,
    0,
    'npc_bosscontrol'
);

-- ########################################
-- APAR?NCIA DO NPC CONTROLLER
-- ########################################

DELETE FROM creature_template_model WHERE CreatureID = 90000;

INSERT INTO creature_template_model (
    CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability
) VALUES (
    90000,
    0,
    18471,   -- modelo (ex: NPC humano)
    1.0,
    1
);