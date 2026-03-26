-- ########################################
-- BOSSES
-- ########################################

-- apaga npc, se existir
DELETE FROM creature_template WHERE entry IN (80001,80002,80003,90000);

-- Boss 1
INSERT INTO creature_template (entry, `name`, subname, minlevel, maxlevel, faction, npcflag, scale, `rank`, unit_class, unit_flags, type, mingold, maxgold, MovementType, ScriptName)
VALUES (80001, 'Monstrinho', 'Nixcraft Server', 60, 60, 16, 0, .5, 3, 1, 0, 7, 10000, 20000, 1, 'npc_arena_boss1');

-- Boss 2
INSERT INTO creature_template (entry, `name`, subname, minlevel, maxlevel, faction, npcflag, scale, `rank`, unit_class, unit_flags, type, mingold, maxgold, MovementType, ScriptName)
VALUES (80002, 'Monstro', 'Nixcraft Server', 70, 70, 16, 0, 1, 3, 1, 0, 7, 20000, 30000, 1, 'npc_arena_boss2');

-- Boss 3
INSERT INTO creature_template (entry, `name`, subname, minlevel, maxlevel, faction, npcflag, scale, `rank`, unit_class, unit_flags, type, mingold, maxgold, MovementType, ScriptName)
VALUES (80003, 'Monstrengo Boss', 'Nixcraft Server', 120, 120, 16, 0, 2, 3, 1, 0, 7, 50000, 100000, 1, 'npc_arena_boss3');

-- ########################################
-- CONTROLLER
-- ########################################

INSERT INTO creature_template (entry, `name`, subname, minlevel, maxlevel, faction, npcflag, ScriptName)
VALUES (90000, 'Jonildo', 'Nixcraft Server', 80, 80, 35, 1, 'npc_bosscontrol');

-- mostra o que foi criado
SELECT * FROM creature_template WHERE entry IN (80001,80002,80003,90000);