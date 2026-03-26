-- deletar registros antigos
DELETE FROM creature_template_model WHERE CreatureID IN (90000,80001,80002,80003);

-- aparencioa do npc controlador
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES (90000, 0, 18471, 0.2, 1, 12340);
-- aparencioa do boss 1
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES (80001, 0, 20522, 0.2, 1, 12340);

-- aparencioa do boos 
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES (80002, 0, 17028, 1, 1, 12340);

-- aparencioa do boss 3
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES (80003, 0, 10193, 2, 1, 12340);
