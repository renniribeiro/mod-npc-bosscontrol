DELETE FROM creature_template_model WHERE CreatureID IN (90000,80001,80002,80003);

-- Controller
INSERT INTO creature_template_model VALUES (90000, 0, 18047, 1.0, 1, 0);

-- Boss 1
INSERT INTO creature_template_model VALUES (80001, 0, 20522, 1.0, 1, 0);

-- Boss 2
INSERT INTO creature_template_model VALUES (80002, 0, 17028, 1.2, 1, 0);

-- Boss 3
INSERT INTO creature_template_model VALUES (80003, 0, 10193, 1.5, 1, 0);

-- mostra o que foi criado
SELECT * FROM creature_template_model WHERE CreatureID IN (80001,80002,80003,90000); 