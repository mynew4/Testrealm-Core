DELETE FROM `quest_template` WHERE  `id` = 900101;
DELETE FROM `quest_template_addon` WHERE `id` = 900101;
DELETE FROM `creature_questender` WHERE `id` = 800096 AND `quest` = 900101;
DELETE FROM `creature_queststarter` WHERE `id` = 800096   AND `quest` = 900101;


REPLACE INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RequiredFactionId1`, `RequiredFactionId2`, `RequiredFactionValue1`, `RequiredFactionValue2`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardMoney`, `RewardBonusMoney`, `RewardDisplaySpell`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `Flags`, `RequiredPlayerKills`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardTalents`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `TimeAllowed`, `AllowableRaces`, `LogTitle`, `LogDescription`, `QuestDescription`, `QuestCompletionLog`, `RequiredNpcOrGo1`, `RequiredNpcOrGo2`, `RequiredNpcOrGo3`, `RequiredNpcOrGo4`, `RequiredNpcOrGoCount1`, `RequiredNpcOrGoCount2`, `RequiredNpcOrGoCount3`, `RequiredNpcOrGoCount4`, `RequiredItemId1`, `RequiredItemId2`, `RequiredItemId3`, `RequiredItemId4`, `RequiredItemId5`, `RequiredItemId6`, `RequiredItemCount1`, `RequiredItemCount2`, `RequiredItemCount3`, `RequiredItemCount4`, `RequiredItemCount5`, `RequiredItemCount6`, `Unknown0`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `VerifiedBuild`) VALUES
(
/* Id  */ '900101', 
/* TYPE  */ '2',
/* LEVEL  */ '80',
/* MINLevel  */ '80',
/* QuestSortID`  */'-22',
/* QuestInfoID`  */ '0',
/* SuggestedGroupNum`  */ '0',
/* RequiredFactionId1`  */'0',
/* RequiredFactionId2`  */'0',
/* RequiredFactionValue1`  */'0',
/* RequiredFactionValue2` */ '0',
/* RewardNextQuest` */'0',
/* RewardXPDifficulty` */ '0', 
/* RewardMoney`  */'0', 
/* RewardBonusMoney` */'0',
/* RewardDisplaySpell`  */'0',
/* RewardSpell`  */'0',
/* RewardHonor` */ '0',
/* RewardKillHonor` */ '0',
/* Startitem */ '0',
/* Flags` */ '0',
/* RequiredPlayerKills`  */'0',
/* RewardItem1` */ '0',
/* RewardAmount1` */ '0',
/* RewardItem2`  */'0',
/* RewardAmount2`  */'0',
/* RewardItem3`   */'0',
/* RewardAmount3  */ '0',
/* RewardItem4`  */ '0',
/* RewardAmount4   */'0',
/* ItemDrop1`  */'0',
/* ItemDropQuantity1` */'0',
/* Itemdrop2  */'0',
/* Quantity2 */ '0',
/* ItemDrop3` */ '0',
/* Quantity3 */ '0',
/* ItemDrop4`  */ '0', 
/* Itemdropquantity4   */'0',
/* RewardChoiceItemID1  */'0',
/* RewardChoiceItemQuantity1 */ '0',
/* RewardChoiceItemID2`  */'0',
/* RewardChoiceItemQuantity2` */ '0',
/* RewardChoiceItemID3`  */ '0',
/* RewardChoiceItemQuantity3`   */'0',
/* RewardChoiceItemID4`  */'0',
/* RewardChoiceItemQuantity4` */ '0',
/* RewardChoiceItemID5`  */'0',
/* RewardChoiceItemQuantity5`  */ '0',
/* RewardChoiceItemID6  */		'0',
/* RewardChoiceItemQuantity6`   */'0',
/* POIContinent   */'0',
/* POIx   */'0',
/* POIy*/ '0',
/* POIPriority */ '0',
/* RewardTitle */ '0',
/* RewardTalents  */ '0',
/* RewardArenaPoints  */ '0',
/* RewardFactionID1*/'0',
/* RewardFactionValue1   */ '0',
/* RewardFactionOverride1  */ '0',
/* RewardFactionID2   */ '0',
/* RewardFactionValue2`   */'0',
/* RewardFactionOverride2  */ '0',
/* RewardFactionID3`   */'0',
/* RewardFactionValue3`  */ '0',
/* RewardFactionOverride3*/ '0',
/* RewardFactionID4`   */ '0',
/* RewardFactionValue4*/ '0',
/* RewardFactionOverride4 */ '0',
/* RewardFactionID5`   */'0',
/* RewardFactionValue5*/ '0',
/* RewardFactionOverride5  */ '0',
/* TimeAllowed  */ '0',
/* AllowableRaces  */ '1791',
/* LogTitle   */'Frohes Neujahr',
/* LogDescription  */ 'Wir feiern gemeinsam Neujahr. Begebt Euch nun durch das Labyrinth.',
/* QuestDescription   */'Willkommen beim Neujahrsevent. Begebt Euch nun durch das Labyrinth. Ihr muesst nur euren Weg suchen, den benoetigten NPC werden ihr finden.',
/* QuestCompletionLog  */ 'Es ist eure Sache was ihr tut.',
/* RequiredNpcOrGo1   */'800098',
/* RequiredNpcOrGo2`  */ '0',
/* RequiredNpcOrGo3`   */'0',
/* RequiredNpcOrGo4`  */ '0',
/* RequiredNpcOrGoCount1  */ '1',
/* RequiredNpcOrGoCount2`  */ '0',
/* RequiredNpcOrGoCount3`  */ '0',
/* RequiredNpcOrGoCount4`   */'0',
/* RequiredItemId1  */ '0',
/* RequiredItemId2`  */ '0',
/* RequiredItemId3` */ '0',
/* RequiredItemId4`   */'0',
/* RequiredItemId5`  */ '0',
/* RequiredItemId6`  */ '0',
/* RequiredItemCount1   */'0',
/* RequiredItemCount2`  */ '0',
/* RequiredItemCount3`  */ '0',
/* RequiredItemCount4`   */'0',
/* RequiredItemCount5`   */'0',
/* RequiredItemCount6` */ '0',
/* Unknown0   */'0',
/* ObjectiveText1   */'0',
/* ObjectiveText2`   */'0',
/* ObjectiveText3`   */'0',
/* ObjectiveText4`    */'0',
/*  VerifiedBuild  */ '0');


REPLACE INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
( /*  ID  */900101,
  /*  MaxLevel  */80,
  /*  AllowableClasses  */2047,
  /*  SourceSpellID  */ 0,
  /*   PrevQuestID */ 900100,
  /*  NextQuestID  */900102,
  /*  ExclusiveGroup  */ 0,
  /*   RewardMailTemplateID */ 0,
  /*  RewardMailDelay  */ 0,
  /*  RequiredSkillID  */ 0,
  /*  RequiredSkillPoints  */ 0,
  /*  RequiredMinRepFaction  */ 0,
  /*  RequiredMaxRepFaction  */ 0,
  /*   RequiredMinRepValue */ 0,
  /*  RequiredMaxRepValue  */ 0,
  /*  ProvidedItemCount  */ 0,
  /*   SpecialFlags */ 0);

REPLACE INTO `creature_questender` (`id`, `quest`) VALUES
(800096, 900101);

REPLACE INTO `creature_queststarter` (`id`, `quest`) VALUES
(800096, 900101);