# BEST PRACTICES

## Deletar registros antigos (caso existam)

**Exemplo:**
```
DELETE FROM smart_scripts WHERE entryorguid IN (80001,80002,80003,90000) AND source_type = 0;
DELETE FROM creature_template WHERE entry = 90000;
DELETE FROM creature_template_model WHERE CreatureID = 90000;
DELETE FROM gossip_menu WHERE MenuID = 90000;
DELETE FROM gossip_menu_option WHERE MenuID = 90000;
```