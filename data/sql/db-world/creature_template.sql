-- ########################################
-- BOSSES
-- ########################################

DELETE FROM creature_template WHERE entry IN (80001,80002,80003);

-- Boss 1
INSERT INTO creature_template (entry, name, subname, minlevel, maxlevel, faction, npcflag, rank, unit_class, unit_flags, type, ScriptName)
VALUES (80001, 'Monstrinho', 'Nixcraft Server', 60, 60, 16, 0, 3, 1, 0, 7, 'npc_arena_boss1');

-- Boss 2
INSERT INTO creature_template (entry, name, subname, minlevel, maxlevel, faction, npcflag, rank, unit_class, unit_flags, type, ScriptName)
VALUES (80002, 'Monstro', 'Nixcraft Server', 70, 70, 16, 0, 3, 1, 0, 7, 'npc_arena_boss2');

-- Boss 3
INSERT INTO creature_template (entry, name, subname, minlevel, maxlevel, faction, npcflag, rank, unit_class, unit_flags, type, ScriptName)
VALUES (80003, 'Monstrengo Boss', 'Nixcraft Server', 80, 80, 16, 0, 3, 1, 0, 7, 'npc_arena_boss3');

-- ########################################
-- CONTROLLER
-- ########################################

DELETE FROM creature_template WHERE entry = 90000;

INSERT INTO creature_template (entry, name, subname, minlevel, maxlevel, faction, npcflag, ScriptName)
VALUES (90000, 'Boss Controller', 'Arena System', 80, 80, 35, 1, 'npc_bosscontrol');