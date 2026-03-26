-- ########################################
-- BOSSES
-- ########################################

-- apaga npc, se existir
DELETE FROM creature_template WHERE entry IN (80001,80002,80003,90000);

-- Boss 1
INSERT INTO creature_template (entry, `name`, subname, minlevel, maxlevel, faction, npcflag, `rank`, BaseAttackTime, RangeAttackTime, unit_class, unit_flags, unit_flags2, type, lootid, skinloot, mingold, maxgold, MovementType, mechanic_immune_mask, flags_extra, ScriptName)
VALUES (80001, 'Monstrinho', 'Nixcraft Server', 60, 60, 16, 0, 3, 2000, 2000, 1, 0, 2048, 7, 80001, 70162, 10000, 20000, 1, 42016080, 1073741824, 'npc_arena_boss1');

-- Boss 2
INSERT INTO creature_template (entry, `name`, subname, minlevel, maxlevel, faction, npcflag, `rank`, BaseAttackTime, RangeAttackTime, unit_class, unit_flags, unit_flags2, type, lootid, skinloot, mingold, maxgold, MovementType, mechanic_immune_mask, flags_extra, ScriptName)
VALUES (80002, 'Monstro', 'Nixcraft Server', 70, 70, 16, 0, 3, 2000, 2000, 1, 0, 2048, 7, 80001, 70162, 20000, 30000, 1, 42016080, 1073741824, 'npc_arena_boss2');

-- Boss 3
INSERT INTO creature_template (entry, `name`, subname, minlevel, maxlevel, faction, npcflag, `rank`, BaseAttackTime, RangeAttackTime, unit_class, unit_flags, unit_flags2, type, lootid, skinloot, mingold, maxgold, MovementType, mechanic_immune_mask, flags_extra, ScriptName)
VALUES (80003, 'Monstrengo Boss', 'Nixcraft Server', 120, 120, 16, 0, 3, 2000, 2000, 1, 0, 2048, 7, 80001, 70162, 50000, 100000, 1, 42016080, 1073741824, 'npc_arena_boss3');

-- ########################################
-- CONTROLLER
-- ########################################

INSERT INTO creature_template (entry, `name`, subname, minlevel, maxlevel, faction, npcflag, ScriptName)
VALUES (90000, 'Jonildo', 'Nixcraft Server', 80, 80, 35, 1, 'npc_bosscontrol');

-- ########################################
-- Loot para o Boss 3
-- ########################################

-- apaga se existir
DELETE FROM creature_loot_template WHERE Entry = 80003;
-- cria loot
INSERT INTO creature_loot_template (Entry, Item, Chance, QuestRequired, LootMode,GroupId, MinCount, MaxCount ) VALUES
-- 💰 Gold extra (simulado via item ou já usa mingold/maxgold)
-- 🎁 Item raro (drop garantido)
(80003, 49426, 100, 0, 1, 0, 1, 1),  -- Emblem of Frost

-- 🟣 Equipamento (chance média)
(80003, 50709, 40, 0, 1, 1, 1, 1),
(80003, 50710, 40, 0, 1, 1, 1, 1),
-- 🔵 Itens secundários
(80003, 33470, 60, 0, 1, 0, 2, 5),  -- Frostweave Cloth
-- 💎 Drop raro
(80003, 36931, 15, 0, 1, 0, 1, 2);  -- Ametrine

-- mostra o que foi criado
SELECT * FROM creature_loot_template WHERE Entry = 80003;
SELECT * FROM creature_template WHERE entry IN (80001,80002,80003,90000);